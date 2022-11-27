#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr;
int N, M, A, current = 0;
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		arr.push_back(0);
	}

	for (int i = 0; i < N; i++) {
		cin >> A;

		current += A % M;
		current %= M;


		ans += arr[current];
		if (current == 0) ans++;
		
		arr[current]++;
	}
	cout << ans;
}