#include "implement_queue_using_stacks.h"

MyQueue::MyQueue() {}

void MyQueue::push(int x) {
    _producer.push(x);
}

int MyQueue::pop() {
    _transfer();
    int ret = _consumer.top();
    _consumer.pop();
    return ret;
}

int MyQueue::peek() {
    _transfer();
    return _consumer.top();
}

void MyQueue::_transfer() {
    if (_consumer.empty()) {
        while (!_producer.empty()) {
            _consumer.push(_producer.top());
            _producer.pop();
        }
    }
}

bool MyQueue::empty() {
    return _consumer.empty() && _producer.empty();
}
