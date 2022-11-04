#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> dp;
string A, B;

int main() {
	cin >> A >> B;
	for (int i = 0; i < B.length() + 1; i++) {
		dp.push_back({});
		for (int j = 0; j < A.length() + 1; j++) {
			dp[i].push_back(i + j);
		}
	}

	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[i].size(); j++) {
			if (A[j - 1] == B[i - 1]) dp[i][j] = dp[i - 1][j - 1];
			else {
				int minimum = min(dp[i][j - 1], dp[i - 1][j - 1]);
				minimum = min(minimum, dp[i - 1][j]);
				dp[i][j] = minimum + 1;
			}
		}
	}
	cout << dp[dp.size() - 1][dp[dp.size() - 1].size() - 1];
}