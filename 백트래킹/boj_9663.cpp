#include <iostream>
#include <vector>
using namespace std;

vector<int> board; // 1���� ���͸� �������. (�ε��� : ��, �� : ��)
vector<bool> visited; // ���� �ߺ��Ǵ��� �˻��ϱ� ����.
int n, ans = 0;

void dfs() {
	if (board.size() == n) {
		// n���� ���� �� ���µ� ������ ���.
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			// if ������ ���� ���� ��ġ�� ��� ó��.

			// �밢���� ���� ó��.
			int flag = 0;
			for (int j = 0; j < board.size(); j++) {
				int row = board.size() - j, column = i - board[j];
				if (abs(row) == abs(column)) {
					flag = 1;
					break;
				}
			} 
			if (flag == 1) continue;
			// ������� �밢���� ���� ó��.

			visited[i] = true;
			board.push_back(i);
			dfs();
			board.pop_back();
			visited[i] = false;
			// �� ���鿡 ���� ���� ����.
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