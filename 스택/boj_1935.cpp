#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<double> s;
vector<double> alpha;
string input;
int N;
double num;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		alpha.push_back(0);
	}

	cin >> input;
	for (int i = 0; i < N; i++) {
		cin >> num;
		alpha[i] = num;
	}


	for (int i = 0; i < input.length(); i++) {
		char current = input[i];
		if (int(current) >= 65 && int(current) < 65 + N) {
			s.push(alpha[int(current) - 65]);
		}

		else {
			double right = s.top();
			s.pop();
			double left = s.top();
			s.pop();
			if (current == '+') s.push(left + right);
			else if (current == '-') s.push(left - right);
			else if (current == '*') s.push(left * right);
			else if (current == '/') s.push(left / right);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();
}