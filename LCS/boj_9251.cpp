#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> lcs;
string A, B;

int main() {
	cin >> A >> B;
	for (int i = 0; i <= A.length(); i++) {
		lcs.push_back({});
		for (int j = 0; j <= B.length(); j++) {
			lcs[i].push_back(0);
		}
	}

	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			if (A[i - 1] == B[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	cout << lcs[A.length()][B.length()];
}
