#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, m, input;

vector<int> arr, result, visited;
unordered_map<int, int> check;

void dfs() {
	if (result.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (visited[i]<check[arr[i]]) {
			visited[i]++;
			result.push_back(arr[i]);
			dfs();
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
			check.insert({ input,1 });
			arr.push_back(input);
			visited.push_back(0);
		}
		else if (check[input] < m) check[input]++;
	}
	sort(arr.begin(), arr.end());

	dfs();
}
