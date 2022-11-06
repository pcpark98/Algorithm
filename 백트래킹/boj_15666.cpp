#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, int> check;
vector<int> arr, result;

int n, m, input;

void dfs(int idx, int start) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < arr.size(); i++) {
		result[idx] = arr[i];
		dfs(idx + 1, i);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (check.find(input) == check.end()) {
			arr.push_back(input);
			check.insert({ input,1 });
		}
		result.push_back(0);
	}
	sort(arr.begin(), arr.end());
	dfs(0, 0);
}