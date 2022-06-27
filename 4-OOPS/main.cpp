#include <iostream>
using namespace std;

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

int main() {
  Hero h1("Abhishek", 70, 'B');
  // h1.name = "Abhishek";
  // h1.health = 56;
  // h1.level = 'A';
  cout << "Size of hero object: " << sizeof(h1) << endl;
  cout << "Name: " << h1.name << endl;
  cout << "Health: " << h1.health << endl;
  cout << "Level: " << h1.level << endl;
  h1.print();
  return 0;
}