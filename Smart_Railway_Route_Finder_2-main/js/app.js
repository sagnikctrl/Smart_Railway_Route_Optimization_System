let graph = null;

async function loadData() {
  const [stationsResponse, connectionsResponse] = await Promise.all([
    fetch("data/stations.json"),
    fetch("data/connections.json")
  ]);
  if (!stationsResponse.ok || !connectionsResponse.ok) {
    throw new Error("Could not load station and connection data.");
  }
  const stations = await stationsResponse.json();
  const connections = await connectionsResponse.json();
  return buildGraph(stations, connections);
}

function fillDropdown(selectId) {
  const select = document.getElementById(selectId);
  Object.keys(graph).forEach(id => {
    const option = document.createElement("option");
    option.value = id;
    option.textContent = graph[id].name;
    select.appendChild(option);
  });
}

function makeResultBox(title, summaryText, path, tag) {
  const box = document.createElement("article");
  box.className = "result-box";

  const heading = document.createElement("h3");
  heading.textContent = title;
  box.appendChild(heading);

  const summary = document.createElement("p");
  summary.className = "summary";
  summary.textContent = summaryText;
  box.appendChild(summary);

  const list = document.createElement("ol");
  path.forEach(id => {
    const item = document.createElement("li");
    item.textContent = graph[id].name;
    list.appendChild(item);
  });
  box.appendChild(list);

  const label = document.createElement("span");
  label.className = "result-tag";
  label.textContent = tag;
  box.appendChild(label);
  return box;
}

function showMessage(text) {
  const out = document.getElementById("routeOutput");
  out.innerHTML = "";
  const message = document.createElement("p");
  message.className = "message";
  message.textContent = text;
  out.appendChild(message);
}

function findRoute() {
  const start = document.getElementById("startSelect").value;
  const end = document.getElementById("endSelect").value;

  if (start === end) {
    showMessage("Please choose two different stations.");
    renderRailwayMap(graph);
    return;
  }

  const bfsPath = bfs(graph, start, end);
  const dijkstraResult = dijkstra(graph, start, end);

  if (!bfsPath || !dijkstraResult) {
    showMessage("No route was found between these stations.");
    renderRailwayMap(graph);
    return;
  }

  const out = document.getElementById("routeOutput");
  out.innerHTML = "";
  const grid = document.createElement("div");
  grid.className = "result-grid";
  grid.appendChild(makeResultBox(
    "BFS · Fewest stops",
    `${bfsPath.length - 1} stops between stations`,
    bfsPath,
    "Unweighted search"
  ));
  grid.appendChild(makeResultBox(
    "Dijkstra · Shortest distance",
    `${dijkstraResult.distance} km total distance`,
    dijkstraResult.path,
    "Distance-based search"
  ));
  out.appendChild(grid);

  const note = document.createElement("p");
  note.className = "note";
  note.textContent = "Distance values are from the supplied project dataset and are marked unverified.";
  out.appendChild(note);

  renderRailwayMap(graph, {
    bfs: bfsPath,
    dijkstra: dijkstraResult.path,
    start,
    end
  });
}

async function initialize() {
  try {
    graph = await loadData();
    fillDropdown("startSelect");
    fillDropdown("endSelect");

    // Keep the initial example similar to the supplied screenshot.
    document.getElementById("startSelect").value = "SDAH";
    document.getElementById("endSelect").value = "MMG";

    document.getElementById("findBtn").addEventListener("click", findRoute);

    let text = "";
    Object.keys(graph).forEach(id => {
      const neighbours = graph[id].neighbors.map(n =>
        `${graph[n.to].name} (${n.distance} km)`
      );
      text += `${graph[id].name}: ${neighbours.length ? neighbours.join(", ") : "no connections"}\n`;
    });
    document.getElementById("graphOutput").textContent = text;
    renderRailwayMap(graph);
    findRoute();
  } catch (error) {
    showMessage(`Unable to load the railway data. ${error.message}`);
    document.getElementById("graphOutput").textContent = String(error);
  }
}

initialize();
