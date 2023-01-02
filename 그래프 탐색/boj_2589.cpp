#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> graph;
vector<vector<bool>> visited, tempVisited;
vector<pair<int, int>> lands;

int x, y, ans = 0;
string input;

void bfs(pair<int, int> start) {
	queue<vector<int>> q;
	q.push({ start.first, start.second, 0 });
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		vector<int> current = q.front();
		q.pop();
		if (current[2] > ans) ans = current[2];

		if (current[0] > 0 && graph[current[0] - 1][current[1]] == 'L' && !visited[current[0] - 1][current[1]]) {
			// 위쪽
			q.push({ current[0] - 1, current[1], current[2] + 1 });
			visited[current[0] - 1][current[1]] = true;
		}

		if (current[1] < y - 1 && graph[current[0]][current[1] + 1] == 'L' && !visited[current[0]][current[1] + 1]) {
			// 오른쪽
			q.push({ current[0], current[1] + 1, current[2] + 1 });
			visited[current[0]][current[1] + 1] = true;
		}

		if (current[0] < x - 1 && graph[current[0] + 1][current[1]] == 'L' && !visited[current[0] + 1][current[1]]) {
			// 아래쪽
			q.push({ current[0] + 1, current[1], current[2] + 1 });
			visited[current[0] + 1][current[1]] = true;
		}

		if (current[1] > 0 && graph[current[0]][current[1] - 1] == 'L' && !visited[current[0]][current[1] - 1]) {
			// 왼쪽
			q.push({ current[0], current[1] - 1, current[2] + 1 });
			visited[current[0]][current[1] - 1] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		cin >> input;
		graph.push_back(input);

		visited.push_back({});
		tempVisited.push_back({});
		for (int j = 0; j < y; j++) {
			visited[i].push_back(false);
			tempVisited[i].push_back(false);

			if (graph[i][j] == 'L') lands.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < lands.size(); i++) {
		bfs(lands[i]);
		visited = tempVisited;
	}
	cout << ans;
}