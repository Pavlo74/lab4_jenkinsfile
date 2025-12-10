#include "pch.h"
#include "stringProcessor.h"

TEST(StringProcessorTests, ReversesString) {
    StringProcessor processor;
    EXPECT_EQ(processor.Process("abc"), "cba");
}

TEST(StringProcessorTests, HandlesEmpty) {
    StringProcessor processor;
    EXPECT_EQ(processor.Process(""), "");
}