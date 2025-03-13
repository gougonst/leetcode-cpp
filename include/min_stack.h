#include <vector>
using namespace std;

class MinStack1 {
public:
    MinStack1();
    void push(int val);
    void pop();
    int top();
    int getMin();
private:
    vector<int> _vals;
    int _min;
};

class MinStack2 {
public:
    MinStack2();
    void push(int val);
    void pop();
    int top();
    int getMin();
private:
    vector<pair<int, int>> _valMinPairs;
};
