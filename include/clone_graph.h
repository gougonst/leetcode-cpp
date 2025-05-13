#include "node.h"

class Solution {
public:
    Node* cloneGraphBFS(Node* node);
    Node* cloneGraphDFS1(Node* node);
    Node* cloneGraphDFS2(Node* node);
private:
    Node* _dfs1(Node* node, unordered_map<Node*, Node*> &visited);
    void _dfs2(Node* cur, unordered_map<Node*, Node*>& visited);
};
