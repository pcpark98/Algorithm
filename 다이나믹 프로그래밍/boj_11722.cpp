#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr, dp = { 1 };
int N, input;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}

	for (int i = 1; i < N; i++) {
		int dpValue = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				if (dpValue < dp[j] + 1) dpValue = dp[j] + 1;
			}
		}
		dp.push_back(dpValue);
	}

	sort(dp.begin(), dp.end());
	cout << dp[dp.size() - 1];
}