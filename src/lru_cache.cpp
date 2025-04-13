#include "lru_cache.h"

LRUCache1::LRUCache1(int capacity): _capacity(capacity) {
    // Empty
}

int LRUCache1::get(int key) {
    if (!this->_cache.count(key))
        return -1;
    this->_recentUsed.push(key);
    this->_waitForUpdate[key]++;
    return this->_cache[key];
}

void LRUCache1::put(int key, int value) {
    this->_cache[key] = value;
    this->_recentUsed.push(key);
    this->_waitForUpdate[key]++;

    while (this->_cache.size() > this->_capacity) {
        int leastUsed = this->_recentUsed.front();
        this->_recentUsed.pop();
        this->_waitForUpdate[leastUsed]--;
        if (this->_waitForUpdate[leastUsed] == 0)
            this->_cache.erase(leastUsed);
    }
}

// --------------------------------------------------------------

LRUCache2::LRUCache2(int capacity): _capacity(capacity) {
    this->_lruHead = new Node(-1, -1);
    this->_lruTail = new Node(-1, -1);
    this->_lruHead->next = this->_lruTail;
    this->_lruHead->prev = nullptr;
    this->_lruTail->next = nullptr;
    this->_lruTail->prev = this->_lruHead;
}

int LRUCache2::get(int key) {
    if (!this->_keyToNode.count(key))
        return -1;
    Node* node = this->_keyToNode[key];
    this->_remove(node);
    this->_add(node);
    return node->val;
}

void LRUCache2::put(int key, int value) {
    if (this->_keyToNode.count(key)) {
        Node* node = this->_keyToNode[key];
        this->_remove(node);
        delete node;
    }
    Node* newNode = new Node(key, value);
    this->_keyToNode[key] = newNode;
    this->_add(newNode);

    while (this->_keyToNode.size() > this->_capacity) {
        Node *delNode = this->_lruHead->next;
        this->_keyToNode.erase(delNode->key);
        this->_remove(delNode);
        delete delNode;
    }
}

void LRUCache2::_remove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void LRUCache2::_add(Node* node) {
    node->prev = this->_lruTail->prev;
    node->next = this->_lruTail;
    node->prev->next = node;
    node->next->prev = node;
}

// --------------------------------------------------------------

LRUCache3::LRUCache3(int capacity) : _capacity(capacity) {
    // Empty
}

int LRUCache3::get(int key) {
    unordered_map<int, list<pair<int, int>>::iterator>::iterator it = this->_keyToNode.find(key);
    if (it == this->_keyToNode.end())
        return -1;
    int value = it->second->second;
    this->_lru.erase(it->second);
    this->_lru.push_front({key, value});
    this->_keyToNode.erase(it);
    this->_keyToNode[key] = this->_lru.begin();
    return value;
}

void LRUCache3::put(int key, int value) {
    unordered_map<int, list<pair<int, int>>::iterator>::iterator it = this->_keyToNode.find(key);
    if (it != this->_keyToNode.end()) {
        this->_lru.erase(it->second);
        this->_keyToNode.erase(it);
    }
    this->_lru.push_front({key, value});
    this->_keyToNode[key] = this->_lru.begin();
    while (this->_keyToNode.size() > this->_capacity) {
        int key = this->_lru.back().first;
        this->_lru.pop_back();
        this->_keyToNode.erase(key);
    }
}
