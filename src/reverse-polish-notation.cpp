#include <iostream>
#include <sstream>
#include <stack>
#include <stdlib.h>
using namespace std;

string parse() {
	string str;
	stack<string> stk;
	char c;
	int x, y, z;
	while (cin >> c, c != '=') {
		switch (c) {
		case '(':
			stk.push(parse());
			break;
		case ')':
			if (!stk.empty()) {
				return stk.top();
			}
			break;
		case '+':
		case '*':
		case '-':
		case '/':
			x = atoi(stk.top().c_str());
			stk.pop();
			y = atoi(stk.top().c_str());
			stk.pop();
			if (c == '+')
				z = x + y;
			else if (c == '-')
				z = y - x;
			else if (c == '*')
				z = x * y;
			else if (c == '/') {
				if (x != 0)
					z = y / x;
				else {
					cout << "Error: Division by zero" << endl;
					throw 0;
				}
			}
			stk.push(
					static_cast<ostringstream*>(&(ostringstream() << z))->str());
			break;
		default:
			cin.putback(c);
			cin >> str;
			stk.push(str);
			break;
		}
	}

	if (!stk.empty()) {
		return stk.top();
	}
	throw 0;
}

int main() {
	try {
		cout << parse();
	} catch (int e) {
		cout << "Parse error" << endl;
	}

	return 0;
}
