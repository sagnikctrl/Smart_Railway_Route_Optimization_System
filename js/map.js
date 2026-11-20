// Draws a schematic (not geographic) railway network from the project graph.
const stationPositions = {
  SDAH: [70, 180], BNXR: [175, 180], DDJ: [280, 180],
  BLH: [385, 180], AGP: [490, 180], SEP: [595, 180],
  KDH: [700, 180], TGH: [805, 180], BP: [910, 180],
  PTF: [1015, 180], IP: [1120, 180], SNR: [1225, 180],
  JGDL: [1330, 180], KNR: [1435, 180], NH: [1540, 180],
  DDC: [280, 285], DGNR: [385, 285], BBT: [490, 285],
  BRPK: [595, 285], NBE: [700, 285], MMG: [805, 285],
  HHR: [910, 285], BT: [1015, 285]
};

function renderRailwayMap(graph, activePaths = {}) {
  const target = document.getElementById("railwayMap");
  if (!target || !graph) return;

  const activeEdges = new Set();
  const bfsEdges = new Set();
  const dijkstraEdges = new Set();
  const addPathEdges = (path, set) => {
    if (!path) return;
    for (let i = 0; i < path.length - 1; i++) {
      set.add([path[i], path[i + 1]].sort().join("|"));
    }
  };
  addPathEdges(activePaths.bfs, bfsEdges);
  addPathEdges(activePaths.dijkstra, dijkstraEdges);
  bfsEdges.forEach(e => activeEdges.add(e));
  dijkstraEdges.forEach(e => activeEdges.add(e));

  const edges = [];
  const seen = new Set();
  Object.keys(graph).forEach(from => {
    graph[from].neighbors.forEach(n => {
      const key = [from, n.to].sort().join("|");
      if (!seen.has(key)) {
        seen.add(key);
        edges.push({
    from,
    to: n.to,
    key,
    distance: n.distance
});
      }
    });
  });

  const edgeMarkup = edges.map(edge => {
    const a = stationPositions[edge.from];
    const b = stationPositions[edge.to];

    if (!a || !b) return "";

    let className = "map-edge";

    if (bfsEdges.has(edge.key) && dijkstraEdges.has(edge.key)) {
        className += " route-bfs route-dijkstra";
    }
    else if (bfsEdges.has(edge.key)) {
        className += " route-bfs";
    }
    else if (dijkstraEdges.has(edge.key)) {
        className += " route-dijkstra";
    }

    const midX = (a[0] + b[0]) / 2;
    const midY = (a[1] + b[1]) / 2;

    // Position distance labels beside the railway line
    const isVertical = a[0] === b[0];

    const labelX = isVertical ? midX + 15 : midX;
    const labelY = midY + 4;

    const distanceLabel = edge.distance != null
        ? `<text class="distance-label"
                 x="${labelX}"
                 y="${labelY}"
                 text-anchor="${isVertical ? "start" : "middle"}">
              ${edge.distance} km
           </text>`
        : "";

    return `
        <line class="${className}"
            x1="${a[0]}" y1="${a[1]}"
            x2="${b[0]}" y2="${b[1]}" />

        ${distanceLabel}
    `;
}).join("");

  const pathStations = new Set();
  Object.values(activePaths).forEach(path => {
    if (Array.isArray(path)) {
      path.forEach(id => pathStations.add(id));
    }
  });
  const start = activePaths.start;
  const end = activePaths.end;

  const nodeMarkup = Object.keys(graph).map(id => {
    const pos = stationPositions[id];
    if (!pos) return "";
    const classes = ["station-node"];
    if (pathStations.has(id)) classes.push("active");
    if (id === start) classes.push("start");
    if (id === end) classes.push("end");
    const label = graph[id].name;
    const labelLines = wrapStationLabel(label, 12);
    // Find the station's position among stations in the same row
const rowIndex = Object.keys(stationPositions).filter(otherId => {
    const otherPos = stationPositions[otherId];

    return otherPos &&
           otherPos[1] === pos[1] &&
           otherPos[0] < pos[0];
}).length;

// Keep the main line's label order and reverse it for the Barasat branch.
const labelAbove = pos[1] === 285
    ? rowIndex % 2 !== 0
    : rowIndex % 2 === 0;

// Calculate label position
const labelY = labelAbove
    ? pos[1] - 17 - ((labelLines.length - 1) * 10)
    : pos[1] + 24;
    const labelMarkup = labelLines.map((line, index) =>
      `<tspan x="${pos[0]}" dy="${index === 0 ? 0 : 11}">${escapeMapText(line)}</tspan>`
    ).join("");
    return `<g class="${classes.join(" ")}">
      <circle cx="${pos[0]}" cy="${pos[1]}" r="7"></circle>
      <text x="${pos[0]}" y="${labelY}" text-anchor="middle">${labelMarkup}</text>
    </g>`;
  }).join("");

  target.innerHTML = `<svg viewBox="0 0 1620 370" role="img" aria-label="Schematic railway network showing station connections">
    <text x="70" y="45" fill="#55718b" font-size="13" font-weight="700">SEALDAH–NAIHATI ROUTE</text>
    <text x="280" y="345" fill="#55718b" font-size="13" font-weight="700">BARASAT BRANCH</text>
    ${edgeMarkup}
    ${nodeMarkup}
  </svg>`;
}

function escapeMapText(value) {
  return String(value).replace(/[&<>"']/g, char => ({
    "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;"
  })[char]);
}

// Split long station names into short centered lines so neighbouring labels do not collide.
function wrapStationLabel(value, maxChars = 12) {
  const words = String(value).trim().split(/\\s+/);
  const lines = [];
  let line = "";
  words.forEach(word => {
    const candidate = line ? `${line} ${word}` : word;
    if (candidate.length > maxChars && line) {
      lines.push(line);
      line = word;
    } else {
      line = candidate;
    }
  });
  if (line) lines.push(line);
  return lines;
}
