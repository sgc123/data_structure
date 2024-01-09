#include <iostream>
#include <stack>
#include <string>

bool areBracketsBalanced(std::string expr) {
    std::stack<char> s;
    char x;  #这个变量将用于在代码的其他部分保存从栈中弹出的括号字符

    // 遍历表达式检查括号
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            // 如果是开放括号，推入栈中
            s.push(expr[i]);
            continue;
        }

        // 如果当前字符不是括号，则跳过
        if (expr[i] != ')' && expr[i] != ']' && expr[i] != '}') {
            continue;
        }

        // 如果栈为空，则括号不匹配
        if (s.empty()) {
            return false;
        }

        switch (expr[i]) {
            case ')':
                // 栈顶元素必须是相匹配的开放括号
                x = s.top();
                s.pop();
                if (x != '(') {
                    return false;
                }
                break;
            case '}':
                x = s.top();
                s.pop();
                if (x != '{') {
                    return false;
                }
                break;
            case ']':
                x = s.top();
                s.pop();
                if (x != '[') {
                    return false;
                }
                break;
        }
    }

    // 检查栈是否为空
    return (s.empty());
}

int main() {
    std::string expr = "{()}[{}]";

    if (areBracketsBalanced(expr)) {
        std::cout << "Balanced";
    } else {
        std::cout << "Not Balanced";
    }

    return 0;
}
