#include <iostream>
#include "database.hpp"

int main()
{
	Database db;
	db.createTable("users");
	db.insertRecord("users", Record(1, "Alice", 30));
	db.insertRecord("users", Record(2, "Bob", 25));

	for (const auto &record : db.tables["users"].records)
	{
		std::cout << "ID: " << record.id << ", Name: " << record.name << ", Age: " << record.age << std::endl;
	}

	return 0;
}
