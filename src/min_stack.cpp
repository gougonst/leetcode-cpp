#include "min_stack.h"

MinStack1::MinStack() {
    _min = __INT32_MAX__;
}

void MinStack1::push(int val) {
    _vals.push_back(val);
    _min = val < _min ? val : _min;
}

void MinStack1::pop() {
    int last = top();
    _vals.pop_back();

    if (_min != last)
        return;

    _min = __INT32_MAX__;
    for (int& val: _vals)
        _min = val < _min ? val : _min;
}

int MinStack1::top() {
    return _vals[_vals.size() - 1];
}

// After I pop the minimum value, how to get next minimum value?
int MinStack1::getMin() {
    return _min;
}

// -2 -> 0 -> -3
// -2 -> 0 -> x


MinStack2::MinStack() {
    // Not implement
}

void MinStack2::push(int val) {
    int min_val = getMin();
    if (_valMinPairs.empty() || val < min_val)
        min_val = val;
    _valMinPairs.push_back({val, min_val});
}

void MinStack2::pop() {
    _valMinPairs.pop_back();
}

int MinStack2::top() {
    return _valMinPairs.back().first;
}

int MinStack2::getMin() {
    return _valMinPairs.empty() ? -1 : _valMinPairs.back().second;
}
