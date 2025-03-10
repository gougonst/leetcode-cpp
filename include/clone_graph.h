#include "node.h"

class Solution {
public:
    Node* cloneGraphBFS(Node* node);
    Node* cloneGraphDFS(Node* node);
private:
    Node* _dfs(Node* node, unordered_map<Node*, Node*> &visited);
};
