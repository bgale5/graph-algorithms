//
// Created by Bennett Gale on 5/8/18.
//

#include "graphing.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

#define I 99

int main(int argc, char **argv)
{
	// Test Dijkstra

	Graph graph(5);
	for (auto &i : graph)
		i.resize(5);
	std::vector<int> a = {I, 10, I, 5, I};
	std::vector<int> b = {I, I, 1, 2, I};
	std::vector<int> c = {I, I, I, I, 4};
	std::vector<int> d = {I, 3, 9, I, 2};
	std::vector<int> e = {7, 8, 6, I, I};
	graph[0] = a;
	graph[1] = b;
	graph[2] = c;
	graph[3] = d;
	graph[4] = e;

//	std::vector<std::vector<int> > path = floyd_warshall(graph);
//	for (std::vector<int> &i : path) {
//		for (int &j : i) {
//			std::cout << j << ", ";
//		}
//		std::cout << std::endl;
//	}

Result  res = dijkstra(graph, 0);
	for (auto &i : res.min_costs) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	return 0;
}
