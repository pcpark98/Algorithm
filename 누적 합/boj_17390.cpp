#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr = { 0 };
int N, Q, input, L, R;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());

	for (int i = 1; i <= N; i++) {
		arr[i] += arr[i - 1];
	}

	for (int i = 0; i < Q; i++) {
		cin >> L >> R;
		cout << arr[R] - arr[L - 1] << "\n";
	}
}