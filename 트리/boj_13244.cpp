#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph, tempGraph;
vector<bool> visited, tempVisited;
int T, N, M, A, B, visitedNode = 0;

void dfs(int start) {
	visitedNode++;
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		if (!visited[graph[start][i]]) {
			dfs(graph[start][i]);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		for (int j = 0; j <= N; j++) {
			graph.push_back({});
			visited.push_back(false);
		}

		for (int j = 0; j < M; j++) {
			cin >> A >> B;
			graph[A].push_back(B);
			graph[B].push_back(A);
		}

		if (M != N - 1) {
			cout << "graph\n";
			continue;
		}

		dfs(1);
		if (visitedNode != N) cout << "graph\n";
		else cout << "tree\n";


		graph = tempGraph;
		visited = tempVisited;
		visitedNode = 0;
	}
}