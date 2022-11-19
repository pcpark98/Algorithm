#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
int N, M, i, j, input;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int k = 0; k < N; k++) {
		cin >> input;
		if (dp.empty()) dp.push_back(input);
		else dp.push_back(dp[dp.size() - 1] + input);
	}

	for (int k = 0; k < M; k++) {
		cin >> i >> j;
		if (i == 1) cout << dp[j - 1] << "\n";
		else cout << dp[j - 1] - dp[i - 2] << "\n";
	}
}