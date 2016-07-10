#include <string>

#include "gtest/gtest.h"

TEST(SimpleTest, simple)
{
    EXPECT_EQ(1, 1);
}

class ExampleTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            // called before each test
        }

        virtual void TearDown() {
            // called prior to each test
        }

        // instance variables available to all tests in this case
        std::string name_;
};

TEST_F(ExampleTest, example) {
    name_ = "Hello";
    EXPECT_EQ(name_, "Hello");
}

