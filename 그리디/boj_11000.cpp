#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<>> pq;
vector<pair<int, int>> inputs;
int N, S, T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		inputs.push_back(make_pair(S, T));
	}
	sort(inputs.begin(), inputs.end());

	for (int i = 0; i < N; i++) {
		if (pq.empty()) {
			pq.push(inputs[i].second);
			continue;
		}

		if (pq.top() <= inputs[i].first) pq.pop();
		pq.push(inputs[i].second);
	}
	cout << pq.size();
}