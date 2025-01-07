#include <gtest/gtest.h>
#include "implement_queue_using_stacks.h"

TEST(MyQueue, test1) {
    MyQueue queue;
    queue.push(1);
    queue.push(2);

    EXPECT_EQ(queue.peek(), 1);
}

TEST(MyQueue, test2) {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.peek();

    EXPECT_EQ(queue.pop(), 1);
}

TEST(MyQueue, test3) {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.peek();
    queue.pop();

    EXPECT_FALSE(queue.empty());
}

TEST(MyQueue, test4) {
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
