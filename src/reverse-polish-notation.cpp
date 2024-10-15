#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

using namespace std;

// Function to perform arithmetic operations
int calculate(int y, int x, char op) {
    switch (op) {
        case '+':
            return y + x;
        case '-':
            return y - x;
        case '*':
            return y * x;
        case '/':
            if (x != 0)
                return y / x;
            else
                throw runtime_error("Error: Division by zero");
        default:
            throw runtime_error("Invalid operator");
    }
}

// Function to parse and evaluate the reverse Polish notation expression
int parse() {
    stack<int> stk;
    string token;

    // Read input until '=' is encountered
    while (cin >> token && token != "=") {
        // Check if the token is an operator
        if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            // Ensure the stack has at least two elements for the operation
            if (stk.size() < 2) {
                throw runtime_error("Error: Invalid input format - not enough operands");
            }

            try {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                int result = calculate(y, x, token[0]);
                stk.push(result);
            } catch (const std::exception& e) {
                throw runtime_error("Invalid input token");
            }
        } else {
            // Attempt to convert the token to an integer
            try {
                stk.push(stoi(token));
            } catch (const invalid_argument& e) {
                throw runtime_error("Error: Invalid input token - not a number");
            }
        }
    }

    // The final result should be the only element left in the stack
    if (stk.size() != 1) {
        throw runtime_error("Error: Invalid input format - more than one element left in stack");
    }

    int res;
    try {
        res = stk.top();
    } catch (const std::exception& e) {
        throw runtime_error("Invalid input token");
    }
    return res;
}

int main() {
    try {
        int result = parse();
        cout << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1; // Return a non-zero exit code to indicate an error
    }

    return 0;
}