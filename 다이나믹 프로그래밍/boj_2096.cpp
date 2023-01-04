#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maximum, minimum;
int N, a, b, c, leftMax, rightMax, centerMax, leftMin, rightMin, centerMin;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (i == 0) {
			maximum = { a,b,c };
			minimum = { a,b,c };
			continue;
		}

		leftMax = max(maximum[0], maximum[1]), rightMax = max(maximum[1], maximum[2]);
		centerMax = max(leftMax, rightMax);
		maximum = { a + leftMax,b + centerMax,c + rightMax };

		leftMin = min(minimum[0], minimum[1]), rightMin = min(minimum[1], minimum[2]);
		centerMin = min(leftMin, rightMin);
		minimum = { a + leftMin, b + centerMin, c + rightMin };
	}
	sort(maximum.begin(), maximum.end());
	sort(minimum.begin(), minimum.end());

	cout << maximum[2] << " " << minimum[0];
}