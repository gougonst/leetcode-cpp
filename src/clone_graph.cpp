#include <queue>
#include <unordered_set>
#include <unordered_map>
#include "clone_graph.h"
#include <iostream>
using namespace std;

Node* Solution::cloneGraphBFS(Node* node) {
    if (!node)
        return nullptr;

    // Start from root node, use BFS to traversal the graph.
    // Store the neighbors into a queue, how to deal with repeated node?
    // Use a unordered_set to store the visited node.
    queue<Node*> oldq, newq;
    unordered_map<Node*, Node*> visited;

    Node* newHead = new Node(node->val);
    Node** newRoot = &newHead;
    oldq.push(node);
    newq.push(newHead);
    visited[node] = newHead;
    while (!oldq.empty()) {
        Node* oldNode = oldq.front();
        Node* newNode = newq.front();
        oldq.pop();
        newq.pop();
        vector<Node*> newNeighbors;
        for (auto& neighbor: oldNode->neighbors) {
            if (!visited.count(neighbor)) {
                Node* newNeighbor = new Node(neighbor->val);
                newNeighbors.push_back(newNeighbor);
                // Visited neighbor should be added here instead of the entry of
                //  while loop, because we need to prevent visit duplicate neighbor
                visited[neighbor] = newNeighbor;
                oldq.push(neighbor);
                newq.push(newNeighbor);
            } else {
                newNeighbors.push_back(visited[neighbor]);
            }
        }
        newNode->neighbors = newNeighbors;
    }
    return *newRoot;
}

Node* Solution::cloneGraphDFS(Node* node) {
    if (!node)
        return nullptr;

    unordered_map<Node*, Node*> visited;
    return _dfs(node, visited);
}

Node* Solution::_dfs(Node* node, unordered_map<Node*, Node*> &visited) {
    Node* newNode = new Node(node->val);
    visited[node] = newNode;

    for (auto& neighbor: node->neighbors) {
        if (!visited.count(neighbor))
            newNode->neighbors.push_back(_dfs(neighbor, visited));
        else
            newNode->neighbors.push_back(visited[neighbor]);
    }

    return newNode;
}

void printGraph(Node* node) {
    queue<Node*> q;
    unordered_set<Node*> visited;

    q.push(node);
    while (!q.empty()) {
        if (visited.count(q.front())) {
            q.pop();
            continue;
        }

        Node* curNode = q.front();
        q.pop();
        visited.insert(curNode);

        cout << "Node: " << curNode->val << endl;
        cout << "Neighbors: ";
        for (auto& neighbor: curNode->neighbors) {
            cout << neighbor->val << " ";
            if (!visited.count(neighbor))
                q.push(neighbor);
        }
        cout << endl;
    }
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution sol;
    Node* newRootBFS = sol.cloneGraphBFS(node1);
    printGraph(newRootBFS);
    Node* newRootDFS = sol.cloneGraphDFS(node1);
    printGraph(newRootDFS);
    return 0;
}
