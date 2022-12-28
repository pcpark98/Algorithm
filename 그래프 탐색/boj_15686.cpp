#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph, tempGraph, visited, tempVisited;
vector<pair<int, int>> house, chicken;
vector<int> combination;
int N, M, input;

void bfs(vector<pair<int, int>> start) {
	queue<vector<int>> q;
	for (int i = 0; i < start.size(); i++) {
		q.push({ start[i].first, start[i].second, 0 });
		graph[start[i].first][start[i].second] = 0;
	}

	int houseCnt = house.size();
	while (!q.empty()) {
		if (houseCnt == 0) return;

		vector<int> current = q.front();
		q.pop();

		if (current[0] > 0 && !visited[current[0] - 1][current[1]]) {
			// 위
			q.push({ current[0] - 1, current[1], current[2] + 1 });
			visited[current[0] - 1][current[1]] = true;
			if (graph[current[0] - 1][current[1]] == -1 || graph[current[0] - 1][current[1]] > current[2] + 1) {
				graph[current[0] - 1][current[1]] = current[2] + 1;
				if (tempGraph[current[0] - 1][current[1]] == -1) {
					houseCnt--;
					if (houseCnt == 0) return;
				}
			}
		}

		if (current[1] < N - 1 && !visited[current[0]][current[1] + 1]) {
			// 오른쪽
			q.push({ current[0], current[1] + 1, current[2] + 1 });
			visited[current[0]][current[1] + 1] = true;
			if (graph[current[0]][current[1] + 1] == -1 || graph[current[0]][current[1] + 1] > current[2] + 1) {
				graph[current[0]][current[1] + 1] = current[2] + 1;
				if (tempGraph[current[0]][current[1] + 1] == -1) {
					houseCnt--;
					if (houseCnt == 0) return;
				}
			}
		}

		if (current[0] < N - 1 && !visited[current[0] + 1][current[1]]) {
			// 아래
			q.push({ current[0] + 1, current[1], current[2] + 1 });
			visited[current[0] + 1][current[1]] = true;
			if (graph[current[0] + 1][current[1]] == -1 || graph[current[0] + 1][current[1]] > current[2] + 1) {
				graph[current[0] + 1][current[1]] = current[2] + 1;
				if (tempGraph[current[0] + 1][current[1]] == -1) {
					houseCnt--;
					if (houseCnt == 0) return;
				}
			}
		}

		if (current[1] > 0 && !visited[current[0]][current[1] - 1]) {
			// 왼쪽
			q.push({ current[0], current[1] - 1, current[2] + 1 });
			visited[current[0]][current[1] - 1] = true;
			if (graph[current[0]][current[1] - 1] == -1 || graph[current[0]][current[1] - 1] > current[2] + 1) {
				graph[current[0]][current[1] - 1] = current[2] + 1;
				if (tempGraph[current[0]][current[1] - 1] == -1) {
					houseCnt--;
					if (houseCnt == 0) return;
				}
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		graph.push_back({});
		tempGraph.push_back({});
		visited.push_back({});
		tempVisited.push_back({});
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input > 0) input *= -1;

			graph[i].push_back(input);
			tempGraph[i].push_back(input);
			visited[i].push_back(0);
			tempVisited[i].push_back(0);

			if (input == -1) house.push_back(make_pair(i, j));
			else if (input == -2) chicken.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < chicken.size() - M; i++) {
		combination.push_back(0);
	}
	for (int i = 0; i < M; i++) {
		combination.push_back(1);
	}

	int ans = 99999999;
	do {
		vector<pair<int, int>> chickens;
		for (int i = 0; i < chicken.size(); i++) {
			if (combination[i] == 1) {
				chickens.push_back(chicken[i]);
			}
		}
		bfs(chickens);
		int temp = 0;
		for (int i = 0; i < house.size(); i++) {
			temp += graph[house[i].first][house[i].second];
			if (temp > ans) break;
		}
		if (temp < ans) ans = temp;
		graph = tempGraph;
		visited = tempVisited;
	} while (next_permutation(combination.begin(), combination.end()));
	cout << ans;
}