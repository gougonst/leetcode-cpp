#include <gtest/gtest.h>
#include "reversed_linked_list.h"

TEST(Solution, test1) {
    Solution sol;
    ListNode* list = new ListNode(1,
                     new ListNode(2,
                     new ListNode(3,
                     new ListNode(4,
                     new ListNode(5)))));
    ListNode* reversedList = new ListNode(5,
                             new ListNode(4,
                             new ListNode(3,
                             new ListNode(2,
                             new ListNode(1)))));
    EXPECT_TRUE(isListNodeEqual(sol.reverseListRecursive(list), reversedList));
}

TEST(Solution, test2) {
    Solution sol;
    ListNode* list = new ListNode(1,
                     new ListNode(2));
    ListNode* reversedList = new ListNode(2,
                             new ListNode(1));
    EXPECT_TRUE(isListNodeEqual(sol.reverseListRecursive(list), reversedList));
}

TEST(Solution, test3) {
    Solution sol;
    EXPECT_TRUE(isListNodeEqual(sol.reverseListRecursive(nullptr), nullptr));
}

TEST(Solution, test4) {
    Solution sol;
    ListNode* list = new ListNode(1,
                     new ListNode(2,
                     new ListNode(3,
                     new ListNode(4,
                     new ListNode(5)))));
    ListNode* reversedList = new ListNode(5,
                             new ListNode(4,
                             new ListNode(3,
                             new ListNode(2,
                             new ListNode(1)))));
    EXPECT_TRUE(isListNodeEqual(sol.reverseListIterative(list), reversedList));
}

TEST(Solution, test5) {
    Solution sol;
    ListNode* list = new ListNode(1,
                     new ListNode(2));
    ListNode* reversedList = new ListNode(2,
                             new ListNode(1));
    EXPECT_TRUE(isListNodeEqual(sol.reverseListIterative(list), reversedList));
}

TEST(Solution, test6) {
    Solution sol;
    EXPECT_TRUE(isListNodeEqual(sol.reverseListIterative(nullptr), nullptr));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
