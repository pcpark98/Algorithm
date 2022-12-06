#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> inequalities;
vector<bool> visited;

string initial = "0123456789", result = "", maxVal = "0", minVal = "9999999999";
int k;
char inequality;

void dfs() {
	if (result.length() == k + 1) {

		int flag = 0;
		for (int i = 0; i < k; i++) {
			if (inequalities[i] == '<' && (int(result[i])>int(result[i+1]))) {
				flag = 1;
				break;
			}
			
			if (inequalities[i] == '>' && (int(result[i]) < int(result[i + 1]))) {
				flag = 1;
				break;
			}
		}


		if (flag == 0) {
			if (stoll(result) < stoll(minVal)) minVal = result;
			if (stoll(result) > stoll(maxVal)) maxVal = result;
		}
		return;
	}

	for (int i = 0; i < initial.length(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			result += initial[i];

			dfs();

			result.pop_back();
			visited[i] = false;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> inequality;
		inequalities.push_back(inequality);
	}

	for (int i = 0; i < 10; i++) {
		visited.push_back(false);
	}

	dfs();

	cout << maxVal << "\n" << minVal;
}