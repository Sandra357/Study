#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        	std::vector<std::vector<int>> dp(coins.size(), std::vector<int>(amount+1, INT_MAX));

	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[i].size(); j++) {
			if (j == 0) {
				dp[i][j] = 0;
			} else {
				if (i < 1) {
					if (j >= coins[i]) {
						if (j%coins[i] == 0)
							dp[i][j] = dp[i][j-coins[i]] + 1;
					}
				} else {
					int val = INT_MAX;
					if (j < coins[i]) {
						dp[i][j] = dp[i-1][j];
					} else {
						if (dp[i][j-coins[i]] != INT_MAX) {
							val = dp[i][j-coins[i]] + 1;
						}
						dp[i][j] = std::min(dp[i-1][j], val);
					}
				}
			}
		}
	}

	if (dp[dp.size()-1][amount] == INT_MAX) {
		return 0-1;
	}
	return dp[dp.size()-1][amount];
}

int main() {
	std::vector<int> coins = {186,419,83,408};
	int amount = 6249;

	std::cout << "res = " << coinChange(coins, amount) << std::endl;

	return 0;
}