#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int integerBreak(int n) {
	if (n == 0) return 0;

	std::vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < dp.size(); i++) {
		int max = 0;
		for (int j = 1, k = i-1; j<= k; j++, k--) {
			int val = std::max(j, dp[j]) * std::max(k, dp[k]);
			if (max < val) max = val;
		}
		dp[i] = max;
	}

	return dp[n];
}

int main() {
	std::cout << "res = " << integerBreak(10) << std::endl;

	return 0;
}