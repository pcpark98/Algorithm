#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
vector<pair<int, int>> items;
vector<int> row;
int N, K, W, V;

int main() {
	cin >> N >> K;
	for (int i = 0; i <= K; i++) {
		row.push_back(0);
	}

	dp.push_back(row);
	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		items.push_back(make_pair(W, V));
		dp.push_back(row);
	}

	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[i].size(); j++) {
			int currentWeight = items[i-1].first, currentValue = items[i-1].second;
			if (currentWeight <= j) dp[i][j] = max(currentValue + dp[i - 1][j - currentWeight], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[dp.size() - 1][dp[dp.size() - 1].size() - 1];
}