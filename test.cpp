//
// Created by Bennett Gale on 5/8/18.
//

#include "graphing.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

#define I 100

int main(int argc, char **argv)
{
	// Test Dijkstra

	std::vector<std::vector<int> > graph(5);
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

	std::vector<int> solution = dijkstra(graph, 0);
	for (int &i : solution)
		std::cout << i << ", ";
	std::cout << std::endl;

	return 0;
}
