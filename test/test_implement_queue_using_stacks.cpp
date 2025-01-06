#include <gtest/gtest.h>
#include "implement_queue_using_stacks.h"

TEST(Solution, test1) {
    MyQueue queue;
    queue.push(1);
    queue.push(2);

    EXPECT_EQ(queue.peek(), 1);
}

TEST(Solution, test2) {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.peek();

    EXPECT_EQ(queue.pop(), 1);
}

TEST(Solution, test3) {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.peek();
    queue.pop();

    EXPECT_FALSE(queue.empty());
}

TEST(Solution, test4) {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.peek();
    queue.pop();
    queue.pop();

    EXPECT_TRUE(queue.empty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
