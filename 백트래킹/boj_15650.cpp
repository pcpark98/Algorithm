#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N개 중 M개를 고르는 조합 구하기.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> arr, combination;
	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
	}
	
	for (int j = 0; j < N; j++) {
		if (j < M) combination.push_back(1);
		else combination.push_back(0);
	}

	do {
		for (int i = 0; i < N; i++) {
			if (combination[i] == 1) cout << arr[i] << " ";
		}
		cout << "\n";
	} while (prev_permutation(combination.begin(), combination.end()));
}