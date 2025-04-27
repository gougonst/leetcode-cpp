#include "remove_nth_node_from_end_of_list.h"
#include <vector>
using namespace std;

ListNode* Solution::removeNthFromEnd1(ListNode* head, int n) {
    ListNode root = ListNode();
    root.next = head;

    ListNode* curNode = head;
    int length = 0;
    while (curNode) {
        curNode = curNode->next;
        length++;
    }

    // n must smaller than length
    // 0, 1, 2, 3, 4 -> length = 5
    // n = 2
    // remove 3, index = 3
    int removeIdx = length - n;
    ListNode* prevNode = &root;
    ListNode* removeNode = head;
    for (int i = 0; i < removeIdx; i++) {
        removeNode = removeNode->next;
        prevNode = prevNode->next;
    }
    prevNode->next = removeNode->next;
    delete removeNode;

    return root.next;
}


// one-pass
ListNode* Solution::removeNthFromEnd2(ListNode* head, int n) {
    ListNode root = ListNode();
    root.next = head;

    vector<ListNode*> nodes;
    nodes.push_back(&root);
    ListNode* curNode = head;
    while (curNode) {
        nodes.push_back(curNode);
        curNode = curNode->next;
    }

    // n must smaller than length
    // r, 0, 1, 2, 3, 4 -> length = 6
    // n = 2
    // remove 3, index = 4
    int removeIdx = nodes.size() - n;
    nodes[removeIdx - 1]->next = nodes[removeIdx]->next;
    delete nodes[removeIdx];

    return root.next;
}

// one-pass O(1) space complexity
ListNode* Solution::removeNthFromEnd2(ListNode* head, int n) {
    ListNode root = ListNode();
    root.next = head;

    ListNode* node1 = &root;
    ListNode* node2 = &root;
    for (int i = 0; i <= n; i++) {
        node1 = node1->next;
    }

    // 0, 1, 2, 3, 4 -> length = 5
    // n = 2
    // remove 3, index = 3
    while (node1) {
        node1 = node1->next;
        node2 = node2->next;
    }
    ListNode* removeNode = node2->next;
    node2->next = node2->next->next;
    delete removeNode;

    return root.next;
}
