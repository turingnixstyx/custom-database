#include "database.hpp"

void Database::createTable(const std::string &tablename) {
    tables[tablename] = Table();
}

void Database::insertRecord(const std::string &tablename,
                            const Record &record) {
    tables[tablename].addRecord(record);
}
