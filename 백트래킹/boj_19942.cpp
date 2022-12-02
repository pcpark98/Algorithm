#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, mp, mf, ms, mv, p, f, s, v, c;

class Food {
public:
	int p, f, s, v, c;

	Food(int p, int f, int s, int v, int c) {
		this->p = p;
		this->f = f;
		this->s = s;
		this->v = v;
		this->c = c;
	}
};

vector<Food*> foods;
vector<bool> visited;
vector<int> result;
vector<vector<string>> toPrint, tempPrint;

int m = 1, ans = 99999999, inResult = 0;
void dfs(int idx) {
	if (result.size() == m) {
		int currentP = 0, currentF = 0, currentS = 0, currentV = 0;
		for (int i = 0; i < m; i++) {
			currentP += foods[result[i]]->p;
			currentF += foods[result[i]]->f;
			currentS += foods[result[i]]->s;
			currentV += foods[result[i]]->v;
		}

		if (currentP < mp || currentF < mf || currentS < ms || currentV < mv) return;


		if (inResult < ans) {
			toPrint = tempPrint;
			ans = inResult;
		}
		toPrint.push_back({});
		for (int i = 0; i < m; i++) {
			toPrint[toPrint.size() - 1].push_back(to_string(result[i]+1));
		}

		return;
	}

	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			if (inResult + foods[i]->c > ans) continue;

			visited[i] = true;
			result.push_back(i);
			inResult += foods[i]->c;

			dfs(i + 1);

			inResult -= foods[i]->c;
			result.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; i++) {
		cin >> p >> f >> s >> v >> c;
		Food* newFood = new Food(p, f, s, v, c);
		foods.push_back(newFood);
		visited.push_back(false);
	}

	while (m <= N) {
		dfs(0);
		m++;
	}

	if (ans == 99999999) {
		cout << -1;
		return 0;
	}

	sort(toPrint.begin(), toPrint.end());

	cout << ans << "\n";
	for (int i = 0; i < toPrint[0].size(); i++) {
		cout << toPrint[0][i] << " ";
	}
}