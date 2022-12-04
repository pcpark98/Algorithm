#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int,int>>> graph; // (비용, 번호)
vector<int> costs;

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq; // (비용, 번호)
int V, E, K, u, v, w;

void bfs(int start) {
	while (!pq.empty()) {
		int cost = pq.top().first, idx = pq.top().second;
		pq.pop();

		if (costs[idx] == -1 || cost < costs[idx]) {
			costs[idx] = cost;
			for (int i = 0; i < graph[idx].size(); i++) {
				pq.push(make_pair(cost + graph[idx][i].first, graph[idx][i].second));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;
	for (int i = 0; i <= V; i++) {
		graph.push_back({});
		costs.push_back(-1);
	}

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w,v));
		if (u == K) pq.push(make_pair(w, v));
	}
	bfs(K);
	costs[K] = 0;

	for (int i = 1; i <= V; i++) {
		if (costs[i] == -1) cout << "INF\n";
		else cout << costs[i] << "\n";
	}
}