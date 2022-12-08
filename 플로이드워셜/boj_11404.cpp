#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int n, m, a, b, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		dp.push_back({});
		for (int j = 0; j <= n; j++) {
			dp[i].push_back(0);
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (dp[a][b] == 0 || c < dp[a][b]) dp[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		vector<int> cols, rows;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] != 0) cols.push_back(j);
			if (dp[j][i] != 0) rows.push_back(j);
		}

		for (int j = 0; j < cols.size(); j++) {
			for (int k = 0; k < rows.size(); k++) {
				if (cols[j] == rows[k]) continue;

				if (dp[rows[k]][cols[j]] == 0 || dp[rows[k]][i] + dp[i][cols[j]] < dp[rows[k]][cols[j]]) dp[rows[k]][cols[j]] = dp[rows[k]][i] + dp[i][cols[j]];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}