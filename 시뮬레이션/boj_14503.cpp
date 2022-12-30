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
			// ��� ������ �� û���� �� ���� ���
			if (current[2] == 0) {
				// ���� ���� ����
				if (graph[current[0] + 1][current[1]] == 0) {
					//cout << "go back\n";
					// ���� �� �� �ִ� ���
					q.push({ current[0] + 1, current[1], current[2] });
					continue;
				}
				else {
					// ���� ���ϴ� ���
					return;
				}
			}

			if (current[2] == 1) {
				// ������ ���� ����
				if (graph[current[0]][current[1] - 1] == 0) {
					// ���� �� �� �ִ� ���
					//cout << "go back\n";
					q.push({ current[0], current[1] - 1, current[2] });
					continue;
				}
				else {
					// ���� ���ϴ� ���
					return;
				}
			}

			if (current[2] == 2) {
				// �Ʒ��� ���� ����
				if (graph[current[0] - 1][current[1]] == 0) {
					// ���� �� �� �ִ� ���
					//cout << "go back\n";
					q.push({ current[0] - 1, current[1], current[2] });
					continue;
				}
				else {
					// ���� ���ϴ� ���
					return;
				}
			}

			if (current[2] == 3) {
				// ���� ���� ����
				if (graph[current[0]][current[1] + 1] == 0) {
					// ���� �� �� �ִ� ���
					//cout << "go back\n";
					q.push({ current[0], current[1] + 1, current[2] });
					continue;
				}
				else {
					// ���� ���ϴ� ���
					return;
				}
			}
		}

		//cout << "can go\n";

		if (current[2] == 0) {
			// ���� û��
			if (current[1] > 0 && graph[current[0]][current[1] - 1] == 0 && !visited[current[0]][current[1] - 1]) {
				// û���� �� �ִ� ���.
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
			// �� û��
			if (current[0] > 0 && graph[current[0] - 1][current[1]] == 0 && !visited[current[0] - 1][current[1]]) {
				// û���� �� �ִ� ���.
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
			// ������ û��
			if (current[1] < M - 1 && graph[current[0]][current[1] + 1] == 0 && !visited[current[0]][current[1] + 1]) {
				// û���� �� �ִ� ���.
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
			// �Ʒ� û��
			if (current[0] < N - 1 && graph[current[0] + 1][current[1]] == 0 && !visited[current[0] + 1][current[1]]) {
				// û���� �� �ִ� ���.
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