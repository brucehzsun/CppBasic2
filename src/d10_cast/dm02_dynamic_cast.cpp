//
// Created by bruce on 2019-11-09.
//
#include <iostream>

using namespace std;


class Animal {
public:
    virtual void cry() = 0;
};

class Dog : public Animal {
public:
    void cry() {
        cout << "旺旺" << endl;
    }

    void doHome() {
        cout << "看家" << endl;
    }
};

class Cat : public Animal {
public:
    void cry() {
        cout << "旺旺" << endl;
    }

    void doThing() {
        cout << "抓老鼠" << endl;
    }
};


class Tree {
public:
    Tree(){
        cout <<"Tree 构造函数" << endl;
        a = 100;
    }
    void flow() {
        cout << "树开花了"<< a << endl;
    }
    int a = 200;
};

void animalCall(Animal *animal) {
    animal->cry();
    Dog *dog = dynamic_cast<Dog *>(animal);
    if (dog != nullptr) {
        dog->doHome();
    }

    //向下转型使用dynamic_cast；
    Cat *cat = dynamic_cast<Cat *>(animal);
    if (cat != nullptr) {
        cat->doThing();
    }
}

int main() {

    {
        Dog dog;
        Cat cat;
        animalCall(&dog);
        animalCall(&cat);
    }
    {
        Dog dog;
        Animal *animal = nullptr;
        //向上转型使用static_cast
        animal = static_cast<Animal *>(&dog);
        animal->cry();
    }
    {
        Tree *t = nullptr;
        Dog dog;
        t = reinterpret_cast<Tree *>(&dog);
        t->flow();
        dog.cry();
    }
}
