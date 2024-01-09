#include <iostream>
using namespace std;

class Stack {
    private:
        int top;
        int maxSize;
        int* stackArray;

    public:
        // 构造函数
        Stack(int size) {
            maxSize = size;
            stackArray = new int[maxSize];
            top = -1;
        }

        // 析构函数
        ~Stack() {
            delete[] stackArray;
        }

        // 入栈
        void push(int value) {
            if (top >= maxSize - 1) {
                cout << "栈已满，无法添加新元素" << endl;
                return;
            }
            stackArray[++top] = value;
        }

        // 出栈
        int pop() {
            if (isEmpty()) {
                cout << "栈为空" << endl;
                return -1; // 或其他标志值
            }
            return stackArray[top--];
        }

        // 查看栈顶元素
        int peek() {
            if (isEmpty()) {
                cout << "栈为空" << endl;
                return -1; // 或其他标志值
            }
            return stackArray[top];
        }

        // 检查栈是否为空
        bool isEmpty() {
            return top == -1;
        }
};

int main() {
    Stack myStack(10); // 创建一个最大容量为10的栈

    // 测试栈操作
    myStack.push(5);
    myStack.push(10);
    cout << "栈顶元素: " << myStack.peek() << endl;
    cout << "出栈元素: " << myStack.pop() << endl;
    cout << "栈顶元素: " << myStack.peek() << endl;

    return 0;
}
