#include <iostream>
using namespace std;

// 定义链表的节点结构
struct Node {
    int data;
    Node* next;      #两个变量

    Node(int data) {    #构造函数
        this->data = data;
        this->next = nullptr;
    }
};

// 定义栈类
class Stack {
    private:
        Node* top;

    public:
        // 构造函数
        Stack() {
            top = nullptr;
        }

        // 析构函数
        ~Stack() {
            while (!isEmpty()) {
                pop();
            }
        }

        // 入栈
        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
        }

        // 出栈
        int pop() {
            if (isEmpty()) {
                cout << "栈为空" << endl;
                return -1; // 或其他标志值
            }
            Node* temp = top;
            int poppedValue = top->data;
            top = top->next;
            delete temp;
            return poppedValue;
        }

        // 查看栈顶元素
        int peek() {
            if (isEmpty()) {
                cout << "栈为空" << endl;
                return -1; // 或其他标志值
            }
            return top->data;
        }

        // 检查栈是否为空
        bool isEmpty() {
            return top == nullptr;
        }
};

int main() {
    Stack myStack;

    // 测试栈操作
    myStack.push(5);
    myStack.push(10);
    cout << "栈顶元素: " << myStack.peek() << endl;
    cout << "出栈元素: " << myStack.pop() << endl;
    cout << "栈顶元素: " << myStack.peek() << endl;

    return 0;
}
