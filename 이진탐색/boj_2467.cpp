#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> positive, negative;
vector<int> arr;
pair<int, int> ans;
int N, input, flag = 0, zero = 1000000001, negativeIdx = -1, positiveIdx = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);

		if (input < 0) {
			negativeIdx = i;
			if (positive.find(input) != positive.end()) {
				ans = make_pair(input, -1 * input);
				flag = 1;
				break;
			}
			negative[-1 * input] = 1;
		}
		else {
			positiveIdx = i;
			if (negative.find(input) != negative.end()) {
				ans = make_pair(-1 * input, input);
				flag = 1;
				break;
			}
			positive[input] = 1;
		}
	}

	if (flag == 1) {
		cout << ans.first << " " << ans.second;
		return 0;
	}

	/*
	if (N == 2) {
		cout << arr[0] << " " << arr[1];
		return 0;
	}
	*/

	int calculate;
	for (int i = 0; i < N; i++) {
		//cout << ans.first << " " << ans.second << endl;
		if (arr[i] < 0) {
			if (positive.empty()) {
				ans = make_pair(arr[N - 2], arr[N - 1]);
				break;
			}
			else {
				map<int, int>::iterator iter = positive.lower_bound(arr[i] * -1);
				if (iter != positive.end()) {
					calculate = arr[i] + iter->first;
					if (abs(calculate) < zero) {
						zero = abs(calculate);
						ans = make_pair(arr[i], iter->first);
					}
					if (iter != positive.begin()) {
						iter--;
						calculate = arr[i] + iter->first;
						if (abs(calculate) < zero) {
							zero = abs(calculate);
							ans = make_pair(arr[i], iter->first);
						}
					}
				}

				else {
					iter--;
					calculate = arr[i] + iter->first;
					if (abs(calculate) < zero) {
						zero = abs(calculate);
						ans = make_pair(arr[i], iter->first);
					}
				}

				if (negativeIdx != i) {
					calculate = arr[i] + arr[negativeIdx];
					if (abs(calculate) < zero) {
						zero = abs(calculate);
						ans = make_pair(arr[i], arr[negativeIdx]);
					}
				}
				else if (negativeIdx > 0) {
					calculate = arr[i] + arr[negativeIdx - 1];
					if (abs(calculate) < zero) {
						zero = abs(calculate);
						ans = make_pair(arr[negativeIdx], arr[i]);
					}
				}
			}
		}
		else {
			if (negative.empty()) {
				ans = make_pair(arr[0], arr[1]);
				break;
			}
			else {
				map<int, int>::iterator iter = negative.lower_bound(arr[i]);
				if (iter != negative.end()) {
					calculate = arr[i] + iter->first;
					if (abs(calculate) < zero) {
						zero = abs(calculate);
						ans = make_pair(iter->first, arr[i]);
					}
					if (iter != negative.begin()) {
						iter--;
						calculate = arr[i] + iter->first;
						if (abs(calculate) < zero) {
							zero = abs(calculate);
							ans = make_pair(iter->first, arr[i]);
						}
					}
				}

				else {
					iter--;
					calculate = arr[i] + iter->first;
					if (abs(calculate) < zero) {
						zero = abs(calculate);
						ans = make_pair(iter->first, arr[i]);
					}
				}

				if (negativeIdx + 1 != i) {
					calculate = arr[i] + arr[negativeIdx + 1];
					if (abs(calculate) < zero) {
						zero = abs(calculate);
						ans = make_pair(arr[negativeIdx + 1], arr[i]);
					}
				}
				else if (negativeIdx + 2 <= positiveIdx) {
					calculate = arr[i] + arr[negativeIdx + 2];
					if (abs(calculate) < zero) {	
						zero = abs(calculate);
						ans = make_pair(arr[i], arr[negativeIdx + 2]);
					}
				}
			}
		}
	}
	cout << ans.first << " " << ans.second;
}