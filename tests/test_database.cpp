#include <gtest/gtest.h>

#include "database.hpp"

TEST(DatabaseTest, CreateTable) {
    Database db;
    db.createTable("users");
    EXPECT_TRUE(db.tables.find("users") != db.tables.end());
}

TEST(DatabaseTest, InsertRecord) {
    Database db;
    db.createTable("users");
    Record record(1, "Alice", 30);
    db.insertRecord("users", record);

    auto it = db.tables.find("users");
    ASSERT_TRUE(it != db.tables.end());
    const auto& records = it->second.records;
    ASSERT_EQ(records.size(), 1);
    EXPECT_EQ(records[0].id, 1);
    EXPECT_EQ(records[0].name, "Alice");
    EXPECT_EQ(records[0].age, 30);
}
