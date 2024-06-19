#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>
#include "record.hpp"

class Table
{
public:
    std::vector<Record> records;
    void addRecord(const Record &record);
};

#endif // TABLE_HPP
