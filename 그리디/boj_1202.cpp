#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> weightValue;
priority_queue<pair<int, int>> valueWeight;
vector<int> backpacks;
int N, K, M, V, C;
long long ans = 0;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> M >> V;
		weightValue.push(make_pair(M, V));
	}

	for (int i = 0; i < K; i++) {
		cin >> C;
		backpacks.push_back(C);
	}
	sort(backpacks.begin(), backpacks.end());

	for (int i = 0; i < K; i++) {
		while (!weightValue.empty() && weightValue.top().first <= backpacks[i]) {
			valueWeight.push(make_pair(weightValue.top().second, weightValue.top().first));
			weightValue.pop();
			if (weightValue.empty()) break;
		}

		if (!valueWeight.empty()) {
			ans += valueWeight.top().first;
			valueWeight.pop();
		}
	}

	cout << ans;
}