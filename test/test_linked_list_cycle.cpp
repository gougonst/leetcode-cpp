#include <gtest/gtest.h>
#include "linked_list_cycle.h"

TEST(Solution, test1) {
    Solution sol;

    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    EXPECT_TRUE(sol.hasCycleBySet(node1));
    EXPECT_TRUE(sol.hasCycleByTwoPointer(node1));
}

TEST(Solution, test2) {
    Solution sol;

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    node2->next = node1;

    EXPECT_TRUE(sol.hasCycleBySet(node1));
    EXPECT_TRUE(sol.hasCycleByTwoPointer(node1));
}

TEST(Solution, test3) {
    Solution sol;

    ListNode* node1 = new ListNode(1);

    EXPECT_FALSE(sol.hasCycleBySet(node1));
    EXPECT_FALSE(sol.hasCycleByTwoPointer(node1));
}

TEST(Solution, test4) {
    Solution sol;

    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node3;

    EXPECT_TRUE(sol.hasCycleBySet(node1));
    EXPECT_TRUE(sol.hasCycleByTwoPointer(node1));
}

TEST(Solution, test5) {
    Solution sol;

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;

    EXPECT_FALSE(sol.hasCycleBySet(node1));
    EXPECT_FALSE(sol.hasCycleByTwoPointer(node1));
}

TEST(Solution, test6) {
    Solution sol;

    ListNode* node1 = new ListNode(1);
    node1->next = node1;

    EXPECT_TRUE(sol.hasCycleBySet(node1));
    EXPECT_TRUE(sol.hasCycleByTwoPointer(node1));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
