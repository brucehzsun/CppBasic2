//
// Created by bruce sun on 2023/2/15.
//
#include "iostream"
#include "map"
#include "string"

class Person {
public:
    std::string name;
    int age;

    Person(std::string name, int age) {
        this->name = name;
        this->age = age;
    }
};

int main() {
    Person p1("dev_A", 22);
    Person p2("dev_B", 22);

    Person p3("sale_A", 22);
    Person p4("sale_B", 22);

    Person p5("hr_A", 22);

    std::multimap<std::string, Person> map;
    map.insert(std::make_pair("dev", p1));
    map.insert(std::make_pair("dev", p2));

    map.insert(std::make_pair("sale", p3));
    map.insert(std::make_pair("sale", p4));

    map.insert(std::make_pair("hr", p5));

    for (auto &it: map) {
        std::cout << it.first << " => " << it.second.name << std::endl;
    }

    std::cout << "研发部门人员：" << map.count("dev") << std::endl;
    int count = map.count("dev");
    int index = 0;
    auto it = map.find("dev");
    while (it != map.end() && index < count) {
        std::cout << it->first << " => " << it->second.name << std::endl;
        it++;
        index++;
    }

}