#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> lcs;
string A, B, result = "";

int main() {
	cin >> A >> B;
	for (int i = 0; i <= A.length(); i++) {
		lcs.push_back({});
		for (int j = 0; j <= B.length(); j++) {
			lcs[i].push_back(0);
		}
	}

	for (int i = 0; i < A.length(); i++) {
		for (int j = 0; j < B.length(); j++) {
			if (A[i] == B[j]) lcs[i + 1][j + 1] = lcs[i][j] + 1;
			else lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
		}
	}

	int i = A.length(), j = B.length();
	while (lcs[i][j] != 0) {
		if (lcs[i][j] == lcs[i - 1][j]) i--;
		else if (lcs[i][j] == lcs[i][j - 1]) j --;
		else {
			result = A[i - 1] + result;
			i--;
			j--;
		}
	}

	cout << lcs[A.length()][B.length()] << "\n";
	cout << result;
}