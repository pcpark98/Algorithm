#include <iostream>
#include <vector>
using namespace std;

vector<int> board; // 1차원 벡터를 사용하자. (인덱스 : 행, 값 : 열)
vector<bool> visited; // 열이 중복되는지 검사하기 위함.
int n, ans = 0;

void dfs() {
	if (board.size() == n) {
		// n개의 퀸을 다 놓는데 성공한 경우.
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			// if 조건을 통해 열이 겹치는 경우 처리.

			// 대각선의 대한 처리.
			int flag = 0;
			for (int j = 0; j < board.size(); j++) {
				int row = board.size() - j, column = i - board[j];
				if (abs(row) == abs(column)) {
					flag = 1;
					break;
				}
			} 
			if (flag == 1) continue;
			// 여기까지 대각선의 대한 처리.

			visited[i] = true;
			board.push_back(i);
			dfs();
			board.pop_back();
			visited[i] = false;
			// 열 값들에 대한 순열 구성.
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		visited.push_back(false);
	}
	dfs();
	cout << ans;
}