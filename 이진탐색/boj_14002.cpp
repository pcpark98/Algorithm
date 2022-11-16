#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<pair<int,int>>> table;
vector<int> arr;
int N, input;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (arr.size() == 0) {
			arr.push_back(input);
			table.push_back({ make_pair(input,i) });
			continue;
		}

		if (input > arr[arr.size()-1]) {
			arr.push_back(input);
			table.push_back({ make_pair(input,i) });
		}
		else {
			vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), input);
			*iter = input;
			table[iter - arr.begin()].push_back(make_pair(input, i));
		}
	}

	cout << arr.size() << "\n";

	stack<int> result;
	long long currentIdx = 1001;
	for (int i = table.size()-1; i >= 0; i--) {
		for (int j = table[i].size()-1; j >= 0; j--) {
			if (currentIdx > table[i][j].second) {
				result.push(table[i][j].first);
				currentIdx = table[i][j].second;
				break;
			}
		}
	}

	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
}