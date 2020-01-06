#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
	int cost = 0;
	std::queue<std::pair<int, int>> last7;
	std::queue<std::pair<int, int>> last30;

	for (const auto &d : days) {
		while (!last7.empty() && last7.front().first + 7 <= d) {
			last7.pop();
		}

		while (!last30.empty() && last30.front().first + 30 <= d) {
			last30.pop();
		}

		last7.push({d, cost + costs[1]});
		last30.push({d, cost + costs[2]});
		cost = std::min({cost + costs[0], last7.front().second, last30.front().second});
	}

	return cost;
}

int main() {
	std::vector<int> days = {1,4,6,7,8,20};
	std::vector<int> costs = {2, 7, 15};

	std::cout << "res = " << mincostTickets(days, costs) << std::endl;

	return 0;
}