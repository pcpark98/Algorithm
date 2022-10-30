#include <iostream>
using namespace std;

long long A, B, C;

long long mul(long long a, long long b, long long c) {
	if (b == 1) return a % c;
	else {
		if(b%2==0) return (mul(a, b/2, c) * mul(a, b/2, c)) % c;
		else return (mul(a, 1, c) * mul(a, b-1, c)) % c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;
	cout << mul(A, B, C);
}