#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> A;
vector<vector<int>> graph, tempGraph;
vector<vector<bool>> visited, tempVisited;
vector<pair<int, int>> connected, tempConnected;

int N, L, R, input;

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visited[i][j] = true;
	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		connected.push_back(current);

		if ((current.first > 0) && (abs(A[current.first - 1][current.second] - A[current.first][current.second]) >= L) && (abs(A[current.first - 1][current.second] - A[current.first][current.second]) <= R)) {
			// 위 : i > 0이어야 가능
			if (!visited[current.first - 1][current.second]) {
				q.push(make_pair(current.first - 1, current.second));
				visited[current.first - 1][current.second] = true;
			}
		}

		if ((current.second < N - 1) && (abs(A[current.first][current.second + 1] - A[current.first][current.second]) >= L) && (abs(A[current.first][current.second + 1] - A[current.first][current.second]) <= R)) {
			// 오른쪽 : j < N-1이어야 가능
			if (!visited[current.first][current.second + 1]) {
				q.push(make_pair(current.first, current.second + 1));
				visited[current.first][current.second + 1] = true;
			}
		}

		if ((current.first < N - 1) && (abs(A[current.first + 1][current.second] - A[current.first][current.second]) >= L) && (abs(A[current.first + 1][current.second] - A[current.first][current.second]) <= R)) {
			// 아래 : i < N-1이어야 가능
			if (!visited[current.first + 1][current.second]) {
				q.push(make_pair(current.first + 1, current.second));
				visited[current.first + 1][current.second] = true;
			}
		}

		if ((current.second > 0) && (abs(A[current.first][current.second - 1] - A[current.first][current.second]) >= L) && (abs(A[current.first][current.second - 1] - A[current.first][current.second]) <= R)) {
			// 왼쪽 : j > 0이어야 가능
			if (!visited[current.first][current.second - 1]) {
				q.push(make_pair(current.first, current.second - 1));
				visited[current.first][current.second - 1] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		A.push_back({});
		visited.push_back({});
		tempVisited.push_back({});
		for (int j = 0; j < N; j++) {
			cin >> input;
			A[i].push_back(input);
			visited[i].push_back(false);
			tempVisited[i].push_back(false);
		}
	}

	int flag = 0, ans = 0;
	while (flag != -1) {
		flag = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bfs(i, j);
					int size = connected.size();
					if (size >= 2) {
						int sum = 0;
						for (int k = 0; k < size; k++) {
							sum += A[connected[k].first][connected[k].second];
						}
						sum /= size;
						for (int k = 0; k < size; k++) {
							A[connected[k].first][connected[k].second] = sum;
						}
						flag = 0;
					}
					connected = tempConnected;
				}
			}
		}
		visited = tempVisited;
		if (flag != -1) ans++;
	}
	cout << ans;
}