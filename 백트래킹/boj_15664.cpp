#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> arr, result, visited;
unordered_map<int, int> check;
int n, m, input;

void dfs(int idx) {
	if (result.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (!result.empty() && result[result.size() - 1] > arr[i]) continue;
		if (visited[i] < check[arr[i]]) {
			visited[i]++;
			result.push_back(arr[i]);
			dfs(i + 1);
			result.pop_back();
			visited[i]--;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (check.find(input) == check.end()) {
			arr.push_back(input);
			visited.push_back(0);
			check.insert({ input, 1 });
		}
		else if (check[input] < m) check[input]++;
	}
	sort(arr.begin(), arr.end());
	dfs(0);
}