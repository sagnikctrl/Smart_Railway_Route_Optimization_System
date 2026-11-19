// Builds the route from the "came from" notes, walking back from the end.
function buildPath(cameFrom, end) {
  const path = [];
  let current = end;
  while (current !== null) {
    path.unshift(current);
    current = cameFrom[current];
  }
  return path;
}

// BFS: finds the route with the fewest stops.
function bfs(graph, start, end) {
  const queue = [start];
  const cameFrom = {};
  cameFrom[start] = null;

  while (queue.length > 0) {
    const current = queue.shift();
    if (current === end) break;
    graph[current].neighbors.forEach(function (n) {
      if (!(n.to in cameFrom)) {
        cameFrom[n.to] = current;
        queue.push(n.to);
      }
    });
  }

  if (!(end in cameFrom)) return null; // no route
  return buildPath(cameFrom, end);
}

// Dijkstra: finds the route with the shortest total distance.
function dijkstra(graph, start, end) {
  const dist = {};
  const cameFrom = {};
  const done = {};

  for (const id in graph) {
    dist[id] = Infinity;
  }
  dist[start] = 0;
  cameFrom[start] = null;

  while (true) {
    // pick the unfinished station with the smallest distance so far
    let current = null;
    for (const id in dist) {
      if (!done[id] && dist[id] < Infinity &&
          (current === null || dist[id] < dist[current])) {
        current = id;
      }
    }
    if (current === null || current === end) break;
    done[current] = true;

    graph[current].neighbors.forEach(function (n) {
      if (n.distance === null) return; // skip links with no distance
      const newDist = dist[current] + n.distance;
      if (newDist < dist[n.to]) {
        dist[n.to] = newDist;
        cameFrom[n.to] = current;
      }
    });
  }

  if (dist[end] === Infinity) return null; // no route
  return { path: buildPath(cameFrom, end), distance: dist[end] };
}