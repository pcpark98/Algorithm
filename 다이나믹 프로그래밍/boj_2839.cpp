#include <iostream>
#include <vector>
using namespace std;

vector<int> dp = { 0, 5000,5000,1,5000,1 };
int N;

int main() {
	cin >> N;
	while (dp.size() <= N) {
		int newValue = min(dp[dp.size() - 3], dp[dp.size() - 5]);
		if (newValue == 5000) dp.push_back(5000);
		else dp.push_back(newValue + 1);
	}
	if (dp[N] == 5000) cout << -1;
	else cout << dp[N];
}