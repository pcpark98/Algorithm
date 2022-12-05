#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> graph; //(비용, 번호)
vector<long long> costs;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int N, M, src, dst, cost;
int toGo;

void bfs(int start) {
	costs[start] = 0;
	for (int i = 0; i < graph[start].size(); i++) {
		pq.push(graph[start][i]);
	}


	while (!pq.empty()) {
		int cost = pq.top().first, idx = pq.top().second;
		pq.pop();

		if (costs[toGo] != -1 && costs[toGo] < cost) continue;

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

	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		graph.push_back({});
		costs.push_back(-1);
	}

	for (int i = 0; i < M; i++) {
		cin >> src >> dst >> cost;
		graph[src].push_back(make_pair(cost, dst));
	}
	cin >> src >> toGo;
	
	bfs(src);
	cout << costs[toGo];
}