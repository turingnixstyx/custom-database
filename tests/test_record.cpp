#include <gtest/gtest.h>

#include "record.hpp"

TEST(RecordTest, RecordInitialization) {
    Record record(1, "Alice", 30);
    EXPECT_EQ(record.id, 1);
    EXPECT_EQ(record.name, "Alice");
    EXPECT_EQ(record.age, 30);
}
