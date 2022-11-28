#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr, result;
int N, input, ans = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			result.push_back(arr[i]);
			continue;
		}

		if (result[result.size() - 1] < arr[i]) result.push_back(arr[i]);
		else {
			*lower_bound(result.begin(), result.end(), arr[i]) = arr[i];
			ans++;
		}
	}
	cout << ans;
}