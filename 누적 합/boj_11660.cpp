#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> sum;
int N, M, X1, X2, Y1, Y2;
long long input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	sum.push_back({});
	for (int i = 0; i < N+1; i++) {
		sum[0].push_back(0);
	}

	for (int i = 1; i <= N; i++) {
		sum.push_back({0});
		for (int j = 1; j <= N; j++) {
			cin >> input;
			sum[i].push_back(input + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1]);
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> X1 >> Y1 >> X2 >> Y2;
		long long ans = sum[X2][Y2] - sum[X2][Y1 - 1] - sum[X1 - 1][Y2] + sum[X1 - 1][Y1 - 1];
		cout << ans << "\n";
	}
}