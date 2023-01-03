#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> lines;
pair<int, int> currentLine;

int N, x, y, ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		lines.push_back(make_pair(x, y));
	}
	sort(lines.begin(), lines.end());

	currentLine = make_pair(lines[0].first, lines[0].second);
	for (int i = 1; i < N; i++) {
		if (lines[i].first <= currentLine.second) {
			// 이어 붙일 수 있는 경우
			if (lines[i].second > currentLine.second) currentLine.second = lines[i].second;
		}
		else {
			ans += currentLine.second - currentLine.first;
			currentLine = make_pair(lines[i].first, lines[i].second);
		}
	}
	ans += currentLine.second - currentLine.first;
	cout << ans;
}