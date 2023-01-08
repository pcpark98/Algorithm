#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, string> m;

int N, t, sec;
char c;
string operation, current = "";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> operation;
		if (operation == "type") {
			cin >> c >> sec;
			current += c;
			m[sec] = current;
		}
		else {
			cin >> t >> sec;
			map<int, string>::iterator iter = m.lower_bound(sec - t);
			if (iter == m.end()) continue;
			else if (iter == m.begin()) {
				current = "";
				m[sec] = "";
			}
			else {
				iter--;
				current = iter->second;
				m[sec] = current;
			}
		}
	}
	cout << current;
}