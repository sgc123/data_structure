#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Function to return precedence of operators
int precedence(char op) {
    if(op == '+'||op == '-') {
        return 1;
    }
    if(op == '*'||op == '/') {
        return 2;
    }
    return 0;
}

// Function to perform an operation and return output.
int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

//中缀表达式转换成后缀表达式
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operators;
    std::string postfix;

    for (char ch : infix) {
        if(std::isspace(ch)) {
            continue; // Skip whitespaces
        }
        else if (std::isdigit(ch)) {
            postfix += ch;
            postfix += ' ';
        }
        else if (ch == '(') {
            operators.push(ch);
        }
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.pop(); // Remove '(' from stack
        }
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }

    return postfix;
}

// 后缀表达式的运算
int evaluatePostfix(const std::string& postfix) {
    std::stack<int> values;

    for (char ch : postfix) {
        if (std::isspace(ch)) {
            continue; // Skip spaces
        }
        else if (std::isdigit(ch)) {
            int value = 0;
            while (std::isdigit(ch)) {
                value = (value * 10) + (ch - '0');
                ch = *(++&ch); // Move to next character
            }
            values.push(value);
        }
        else {
            int val2 = values.top(); values.pop();
            int val1 = values.top(); values.pop();
            int result = applyOp(val1, val2, ch);
            values.push(result);
        }
    }
    return values.top();
}

int main() {
    std::string infix;
    std::cout << "Enter infix expression: ";
    std::getline(std::cin, infix);
    
    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;
    
    int result = evaluatePostfix(postfix);
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}
