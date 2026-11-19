// Builds a graph from the stations and connections lists.
// Each station gets a list of neighbours.
function buildGraph(stations, connections) {
  const graph = {};

  // 1. Make one empty entry for every station
  stations.forEach(function (station) {
    graph[station.id] = { name: station.name, neighbors: [] };
  });

  // 2. Add every connection in BOTH directions
  connections.forEach(function (c) {
    if (!graph[c.from] || !graph[c.to]) {
      console.warn("Unknown station in connection:", c);
      return;
    }
    graph[c.from].neighbors.push({ to: c.to, distance: c.distance_km, time: c.time_min });
    graph[c.to].neighbors.push({ to: c.from, distance: c.distance_km, time: c.time_min });
  });

  return graph;
}