#ifndef GRAPHING_ALGORITHMS_LIBRARY_H
#define GRAPHING_ALGORITHMS_LIBRARY_H

#include <vector>

using Graph = std::vector<std::vector<int> >;

struct Result {
	std::vector<int> min_costs;
	std::vector<int> path;
};

Result dijkstra(const Graph &graph, int source);
std::vector<std::vector<int> > floyd_warshall(const Graph &graph);
Result bellmanford(const Graph &graph, int source);

#endif