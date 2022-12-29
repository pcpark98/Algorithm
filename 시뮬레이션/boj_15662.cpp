#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<deque<int>> dqs;
int T, status, K, nth, dir;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		deque<int> dq;
		cin >> status;
		for (int j = 0; j < 8; j++) {
			dq.push_front(status % 10);
			status /= 10;
		}
		dqs.push_back(dq);
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> nth >> dir;
		int currentLeft = dqs[nth - 1][6], currentRight = dqs[nth - 1][2];


		if (dir == 1) {
			dqs[nth - 1].push_front(dqs[nth - 1].back());
			dqs[nth - 1].pop_back();
		}
		else {
			dqs[nth - 1].push_back(dqs[nth - 1].front());
			dqs[nth - 1].pop_front();
		}

		int goLeft = nth - 2, currentDir = dir;
		while (goLeft >= 0) {
			// 왼쪽으로
			int prevLeft = dqs[goLeft][6], prevRight = dqs[goLeft][2];
			if (prevRight != currentLeft) {
				currentDir *= -1;
				if (currentDir == 1) {
					dqs[goLeft].push_front(dqs[goLeft].back());
					dqs[goLeft].pop_back();
				}
				else {
					dqs[goLeft].push_back(dqs[goLeft].front());
					dqs[goLeft].pop_front();
				}
			}
			else break;

			currentLeft = prevLeft;
			goLeft--;
		}

		int goRight = nth;
		currentDir = dir;
		while (goRight <= T - 1) {
			// 오른쪽으로
			int nextLeft = dqs[goRight][6], nextRight = dqs[goRight][2];
			if (nextLeft != currentRight) {
				currentDir *= -1;
				if (currentDir == 1) {
					dqs[goRight].push_front(dqs[goRight].back());
					dqs[goRight].pop_back();
				}
				else {
					dqs[goRight].push_back(dqs[goRight].front());
					dqs[goRight].pop_front();
				}
			}
			else break;

			currentRight = nextRight;
			goRight++;
		}
	}

	int ans = 0;
	for (int i = 0; i < T; i++) {
		if (dqs[i].front() == 1) ans++;
	}
	cout << ans;
}