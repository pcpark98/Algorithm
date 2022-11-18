#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

priority_queue<int> total;
vector<int> arr, increase, decrease;
int N, input;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		int currentDpValue = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (currentDpValue < increase[j] + 1) currentDpValue = increase[j] + 1;
			}
		}
		increase.push_back(currentDpValue);
		decrease.push_back(1);
	}

	for (int i = N - 1; i >= 0; i--) {
		int currentDpValue = 1;
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				if (currentDpValue < decrease[j] + 1) {
					currentDpValue = decrease[j] + 1;
					decrease[i] = currentDpValue;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		total.push(increase[i] + decrease[i] - 1);
	}

	cout << total.top();
}