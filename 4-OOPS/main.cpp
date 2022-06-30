#include <iostream>
#include <string>
using namespace std;

// Inheritance

class Human {
  public: 
    int height;
    int weight;
    int age;

    int getAge() {
      return this -> age;
    }

    void setWeight(int weight) {
      this -> weight = weight;
    }

    void talkHuman() {
      cout << "Human Talking" << endl;
    }

    void talk() {
      cout << "Human talk" << endl;
    }
};

class Male: public Human {
  public: 
    string color;

    void sleep() {
      cout << "Male Sleeping" << endl;
    }

    void talkMale() {
      cout << "Male Talking" << endl;
    }

    void talk() {
      cout << "Male talk" << endl;
    }
};

// Multilevel inheritance
class Boy: public Male {
  public: 
    int standard;

  void talk() {
    cout << "Boy talking" << endl;
  }
};

class Hero {
  // properties
  public:
    char * name;
    int health;
    char level;

    Hero() {
      name = new char[100];
    }

    Hero(char name[], int health, char level) {
      this -> name = name;
      this -> health = health;
      this -> level = level;
    }

    void print() {
      cout << this -> name << endl;
      cout << this -> health << endl;
      cout << this -> level << endl;
      cout << (*this).level << endl;
    }
};

// Multiple inheritence
class Multiple: public Human, public Hero {};

int main() {
  // Hero h1("Abhishek", 70, 'B');
  // // h1.name = "Abhishek";
  // // h1.health = 56;
  // // h1.level = 'A';
  // cout << "Size of hero object: " << sizeof(h1) << endl;
  // cout << "Name: " << h1.name << endl;
  // cout << "Health: " << h1.health << endl;
  // cout << "Level: " << h1.level << endl;
  // h1.print();

  // Male m1;
  // cout << m1.age << endl;
  // cout << m1.weight << endl;
  // cout << m1.height << endl;
  // cout << m1.color << endl;
  // m1.sleep();

  Boy b1;
  b1.talkHuman();
  b1.talkMale();
  b1.talk();

  return 0;
}