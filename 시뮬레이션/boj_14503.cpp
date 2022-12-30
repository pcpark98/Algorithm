#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;
int N, M, r, c, d, input, ans = 1;

void bfs(vector<int> start) {
	queue<vector<int>> q;
	q.push(start);
	visited[start[0]][start[1]] = true;
	while (!q.empty()) {
		vector<int> current = q.front();
		q.pop();
		//cout << "current : " << current[0] << ", " << current[1] << endl;

		if (!(current[1] > 0 && graph[current[0]][current[1] - 1] == 0 && !visited[current[0]][current[1] - 1]) && !(current[0] > 0 && graph[current[0] - 1][current[1]] == 0 && !visited[current[0] - 1][current[1]]) && !(current[1] < M - 1 && graph[current[0]][current[1] + 1] == 0 && !visited[current[0]][current[1] + 1]) && !(current[0] < N - 1 && graph[current[0] + 1][current[1]] == 0 && !visited[current[0] + 1][current[1]])) {
			// 모든 방향을 다 청소할 수 없는 경우
			if (current[2] == 0) {
				// 위쪽 보고 있음
				if (graph[current[0] + 1][current[1]] == 0) {
					//cout << "go back\n";
					// 후진 할 수 있는 경우
					q.push({ current[0] + 1, current[1], current[2] });
					continue;
				}
				else {
					// 후진 못하는 경우
					return;
				}
			}

			if (current[2] == 1) {
				// 오른쪽 보고 있음
				if (graph[current[0]][current[1] - 1] == 0) {
					// 후진 할 수 있는 경우
					//cout << "go back\n";
					q.push({ current[0], current[1] - 1, current[2] });
					continue;
				}
				else {
					// 후진 못하는 경우
					return;
				}
			}

			if (current[2] == 2) {
				// 아래쪽 보고 있음
				if (graph[current[0] - 1][current[1]] == 0) {
					// 후진 할 수 있는 경우
					//cout << "go back\n";
					q.push({ current[0] - 1, current[1], current[2] });
					continue;
				}
				else {
					// 후진 못하는 경우
					return;
				}
			}

			if (current[2] == 3) {
				// 왼쪽 보고 있음
				if (graph[current[0]][current[1] + 1] == 0) {
					// 후진 할 수 있는 경우
					//cout << "go back\n";
					q.push({ current[0], current[1] + 1, current[2] });
					continue;
				}
				else {
					// 후진 못하는 경우
					return;
				}
			}
		}

		//cout << "can go\n";

		if (current[2] == 0) {
			// 왼쪽 청소
			if (current[1] > 0 && graph[current[0]][current[1] - 1] == 0 && !visited[current[0]][current[1] - 1]) {
				// 청소할 수 있는 경우.
				//cout << "clean left\n";
				visited[current[0]][current[1] - 1] = true;
				ans++;
				q.push({ current[0], current[1] - 1, 3 });
			}
			else {
				//cout << "turn left\n";
				q.push({ current[0], current[1], 3 });
			}
		}
		else if (current[2] == 1) {
			// 위 청소
			if (current[0] > 0 && graph[current[0] - 1][current[1]] == 0 && !visited[current[0] - 1][current[1]]) {
				// 청소할 수 있는 경우.
				//cout << "clean up\n";
				visited[current[0] - 1][current[1]] = true;
				ans++;
				q.push({ current[0] - 1, current[1], 0 });
			}
			else {
				//cout << "turn up\n";
				q.push({ current[0], current[1], 0 });
			}
		}
		else if (current[2] == 2) {
			// 오른쪽 청소
			if (current[1] < M - 1 && graph[current[0]][current[1] + 1] == 0 && !visited[current[0]][current[1] + 1]) {
				// 청소할 수 있는 경우.
				//cout << "clean right\n";
				visited[current[0]][current[1] + 1] = true;
				ans++;
				q.push({ current[0], current[1] + 1, 1 });
			}
			else {
				//cout << "turn right\n";
				q.push({ current[0], current[1], 1 });
			}
		}
		else {
			// 아래 청소
			if (current[0] < N - 1 && graph[current[0] + 1][current[1]] == 0 && !visited[current[0] + 1][current[1]]) {
				// 청소할 수 있는 경우.
				//cout << "clean bottom\n";
				visited[current[0] + 1][current[1]] = true;
				ans++;
				q.push({ current[0] + 1, current[1], 2 });
			}
			else {
				//cout << "turn bottom\n";
				q.push({ current[0], current[1], 2 });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		graph.push_back({});
		visited.push_back({});
		for (int j = 0; j < M; j++) {
			cin >> input;
			graph[i].push_back(input);
			visited[i].push_back(false);
		}
	}

	bfs({ r,c,d });
	cout << ans;
}