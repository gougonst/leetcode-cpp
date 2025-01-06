#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue();
    void push(int x);
    int pop();
    int peek();
    bool empty();
private:
    stack<int> _producer;
    stack<int> _consumer;
    void _transfer();
};
