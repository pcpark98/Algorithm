#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<map<char, int>> dictionary, puzzle;
vector<bool> visited, tempVisited;
string input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 26; i++) {
		visited.push_back(false);
		tempVisited.push_back(false);
	}

	while (true) {
		cin >> input;
		if (input == "-") break;

		map<char, int> temp;
		for (int i = 0; i < input.length(); i++) {
			temp[input[i]]++;
		}
		dictionary.push_back(temp);
	}

	while (true) {
		cin >> input;
		if (input == "#") break;

		map<char, int> current, ans;

		for (int i = 0; i < input.length(); i++) {
			current[input[i]]++;
			ans[input[i]] = 0;
		}

		for (int i = 0; i < dictionary.size(); i++) {
			int flag = 0;

			map<char, int>::iterator dicIter, puzIter;

			for (dicIter = dictionary[i].begin(); dicIter != dictionary[i].end(); dicIter++) {
				puzIter = current.find(dicIter->first);
				if (puzIter == current.end()) {
					flag = 1;
					break;
				}

				else if (dicIter->second > puzIter->second) {
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				for (dicIter = dictionary[i].begin(); dicIter != dictionary[i].end(); dicIter++) {
					if (!visited[int(dicIter->first) - 65]) {
						ans[dicIter->first]++;
						visited[int(dicIter->first) - 65] = true;
					}
				}
				visited = tempVisited;
			}

		}

		map<char, int>::iterator resultIter;
		vector<pair<int, char>> result;
		for (resultIter = ans.begin(); resultIter != ans.end(); resultIter++) {
			result.push_back(make_pair(resultIter->second, resultIter->first));
		}
		sort(result.begin(), result.end());

		string minStr="", maxStr="";
		int minVal = result[0].first, maxVal = result[result.size() - 1].first;
		for (int j = 0; j < result.size(); j++) {
			if (result[j].first == minVal) minStr += result[j].second;
			else break;
		}

		for (int j = result.size() - 1; j >= 0; j--) {
			if (result[j].first == maxVal) maxStr = result[j].second + maxStr;
			else break;
		}
		cout << minStr << " " << minVal << " " << maxStr << " " << maxVal << "\n";
	}
}