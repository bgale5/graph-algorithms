#include "graphing.h"

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>

#define I 99 // Infinity

/*
 * Return the shortest paths to each vertex from the specified source.
 */
Result dijkstra(const Graph &graph, int source)
{
	unsigned long n = graph.size();
	std::vector<int> shortest(n, I);
	shortest[source] = 0;
	std::vector<int> visited;
	auto cmp = [&](int a, int b) -> bool {
		return shortest[a] > shortest[b];
	};
	std::vector<int> pq(n);
	for (int i = 0; i < n; i++)
		pq[i] = i;
	std::sort(pq.begin(), pq.end(), cmp);
	while(!pq.empty()) {
		int top = *pq.end();
		for (int i = 0; i < n; i++) {
			if (top == i)
				continue;
			if (shortest[top] + graph[top][i] < shortest[i]) {
				shortest[i] = shortest[top] + graph[top][i];
				std::sort(pq.begin(), pq.end(), cmp);
			}
		}
		visited.push_back(top);
		pq.pop_back();
	}
	Result res = {shortest, visited};
	return res;
}

Graph floyd_warshall(const Graph &graph)
{
	unsigned long n = graph.size();
	std::vector<std::vector<int> > dist(n); // Shortest path between nodes
	std::vector<std::vector<int> > path(n);
	// Initialise the distance table
	for (int i = 0; i < n; i++) {
		dist[i].resize(n);
		for (int j = 0; j < n; j++) {
			if (i == j) {
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = graph[i][j];
		}
	}
	// Initialise path
	for (auto &i : path) {
		i.resize(n, 0);
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	return dist;
}

Result bellmanford(const Graph &graph, int source)
{
	unsigned long n = graph.size();
	std::vector<int> dist(n, I);
	std::vector<int> predecessor(n, -1);
	dist[source] = 0;
	for (auto i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (dist[u] + graph[u][v] < dist[v]) {
					dist[v] = dist[u] + graph[u][v];
					predecessor[v] = u;
				}
			}
		}
	}
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			if (dist[u] + graph[u][v] < dist[v]) {
				std::cerr << "Negative loop cycle" << std::endl;
				exit(-1);
			}
		}
	}
	Result res = {dist, predecessor};
	return res;
}


