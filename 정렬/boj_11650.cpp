#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> point;
int N, x, y;


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}
	sort(point.begin(), point.end());

	for (int i = 0; i < N; i++) {
		cout << point[i].first << " " << point[i].second << "\n";
	}
}