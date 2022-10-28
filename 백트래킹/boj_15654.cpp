#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> result;
vector<bool> visited;

int n, m, input;

void dfs() {
	if (result.size() == m) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			result.push_back(arr[i]);
			dfs();
			result.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr.push_back(input);
		visited.push_back(false);
	}
	sort(arr.begin(), arr.end());
	dfs();
}