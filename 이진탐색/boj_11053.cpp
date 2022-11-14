#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr, lis;
int N, input, endPoint = 0, ans = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (i == 0) lis.push_back(input);
		else {
			if (input > lis[lis.size()-1]) lis.push_back(input);
			else {
				vector<int>::iterator iter = lower_bound(lis.begin(), lis.end(), input);
				*iter = input;
			}
		}

		if (lis.size() > ans) ans = lis.size();
	}
	cout << ans;
}