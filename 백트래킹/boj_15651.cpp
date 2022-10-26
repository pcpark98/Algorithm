#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> result;

int n, m;

void dfs(int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		result[idx] = arr[i];
		dfs(idx + 1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
		result.push_back(0);
	}
	dfs(0);
}