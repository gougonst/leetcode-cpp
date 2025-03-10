#include <gtest/gtest.h>
#include "middle_of_the_linked_list.h"

TEST(Solution, test1) {
    Solution sol;
    ListNode* head = new ListNode(1,
                     new ListNode(2,
                     new ListNode(3,
                     new ListNode(4,
                     new ListNode(5)))));
    EXPECT_EQ(sol.middleNode(head), head->next->next);
}

TEST(Solution, test2) {
    Solution sol;
    ListNode* head = new ListNode(1,
                     new ListNode(2,
                     new ListNode(3,
                     new ListNode(4,
                     new ListNode(5,
                     new ListNode(6))))));
    EXPECT_EQ(sol.middleNode(head), head->next->next->next);
}

TEST(Solution, test3) {
    Solution sol;
    ListNode* head = new ListNode(1,
                     new ListNode(2));
    EXPECT_EQ(sol.middleNode(head), head->next);
}

TEST(Solution, test4) {
    Solution sol;
    ListNode* head = new ListNode(1);
    EXPECT_EQ(sol.middleNode(head), head);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
