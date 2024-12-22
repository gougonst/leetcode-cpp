#include <gtest/gtest.h>
#include "merge_two_sorted_list.h"

TEST(Solution, iterativeTest1) {
    Solution sol;

    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode* expectedList = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4))))));

    ListNode* newList = sol.mergeTwoListsIterative(list1, list2);

    EXPECT_TRUE(isListNodeEqual(newList, expectedList));
}

TEST(Solution, iterativeTest2) {
    Solution sol;

    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;

    ListNode* expectedList = nullptr;

    ListNode* newList = sol.mergeTwoListsIterative(list1, list2);

    EXPECT_TRUE(isListNodeEqual(newList, expectedList));
}

TEST(Solution, iterativeTest3) {
    Solution sol;

    ListNode* list1 = nullptr;
    ListNode* list2(0);

    ListNode* expectedList(0);

    ListNode* newList = sol.mergeTwoListsIterative(list1, list2);

    EXPECT_TRUE(isListNodeEqual(newList, expectedList));
}

TEST(Solution, recursiveTest1) {
    Solution sol;

    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode* expectedList = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4))))));

    ListNode* newList = sol.mergeTwoListsRecursive(list1, list2);

    EXPECT_TRUE(isListNodeEqual(newList, expectedList));
}

TEST(Solution, recursiveTest2) {
    Solution sol;

    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;

    ListNode* expectedList = nullptr;

    ListNode* newList = sol.mergeTwoListsRecursive(list1, list2);

    EXPECT_TRUE(isListNodeEqual(newList, expectedList));
}

TEST(Solution, recursiveTest3) {
    Solution sol;

    ListNode* list1 = nullptr;
    ListNode* list2(0);

    ListNode* expectedList(0);

    ListNode* newList = sol.mergeTwoListsRecursive(list1, list2);

    EXPECT_TRUE(isListNodeEqual(newList, expectedList));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
