#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited, tempVisited;
vector<pair<int, int>> candidates;
int N, a, b;

void bfs(int start) {
	queue<pair<int, int>> q; // Çö À§Ä¡, È½¼ö
	q.push(make_pair(start, 0));
	visited[start] = true;

	int score = 0;
	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();

		for (int i = 0; i < graph[current.first].size(); i++) {
			if (!visited[graph[current.first][i]]) {
				q.push(make_pair(graph[current.first][i], current.second + 1));
				visited[graph[current.first][i]] = true;
				if (current.second + 1 > score) score = current.second + 1;
			}
		}
	}
	candidates.push_back(make_pair(score, start));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i <= N; i++) {
		graph.push_back({});

		visited.push_back(false);
		tempVisited.push_back(false);
	}

	while (true) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		bfs(i);
		visited = tempVisited;
	}
	sort(candidates.begin(), candidates.end());

	int ansPoint = candidates[0].first, idx = 1;
	for (idx; idx < N; idx++) {
		if (candidates[idx].first > ansPoint) break;
	}

	cout << ansPoint << " " << idx << "\n";
	for (int i = 0; i < idx; i++) {
		cout << candidates[i].second << " ";
	}
}