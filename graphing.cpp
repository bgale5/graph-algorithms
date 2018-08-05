#include "graphing.h"

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>

#define I 100 // Infinity


/*
 * Return the shortest paths to each vertex from the specified source.
 */
std::vector<int> dijkstra(std::vector<std::vector<int> > weights, int source) {
	unsigned long n = weights.size();
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
			if (shortest[top] + weights[top][i] < shortest[i]) {
				shortest[i] = shortest[top] + weights[top][i];
				std::sort(pq.begin(), pq.end(), cmp);
			}
		}
		visited.push_back(top);
		pq.pop_back();
	}
	return shortest;
}

