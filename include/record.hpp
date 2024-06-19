#ifndef RECORD_HPP
#define RECORD_HPP

#include <string>

class Record
{
public:
    int id;
    std::string name;
    int age;

    Record(int id, const std::string &name, int age);
};

#endif // RECORD_HPP
