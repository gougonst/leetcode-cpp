#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;

struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) : key(key), val(val) , next(nullptr), prev(nullptr) {};
};

class LRUCache1 {
public:
    LRUCache1(int capacity);
    int get(int key);
    void put(int key, int value);
private:
    int _capacity;
    queue<int> _recentUsed;
    unordered_map<int, int> _waitForUpdate;
    unordered_map<int, int> _cache;
};

class LRUCache2 {
public:
    LRUCache2(int capacity);
    int get(int key);
    void put(int key, int value);
private:
    void _remove(Node* node);
    void _add(Node* node);

    int _capacity;
    Node* _lruHead;
    Node* _lruTail;
    unordered_map<int, Node*> _keyToNode;
};

class LRUCache3 {
public:
    LRUCache3(int capacity);
    int get(int key);
    void put(int key, int value);
private:
    int _capacity;
    list<pair<int, int>> _lru;
    unordered_map<int, list<pair<int, int>>::iterator> _keyToNode;
};
