#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <map>
#include <string>

#include "table.hpp"

class Database {
   public:
    std::map<std::string, Table> tables;

    void createTable(const std::string &tablename);
    void insertRecord(const std::string &tablename, const Record &record);
};

#endif  // DATABASE_HPP
