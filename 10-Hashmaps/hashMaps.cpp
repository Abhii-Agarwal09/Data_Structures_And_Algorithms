#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {

  // In unorderd map, things are arranged in a random manner, but in map (ordered map) things are ordered

  // Creation
  unordered_map<string, int> m;

  // Insertion
  // 1
  pair<string, int> p = make_pair("Abhishek", 3);
  m.insert(p);
  // 2
  pair<string, int> q("Agarwal", 2);
  m.insert(q);
  // 3
  m["Hello"] = 1; // Makes new entry
  m["Hello"] = 2; // Replaces 1 by 2 as entry already exists (updation), no duplicate entries

  // Searching
  cout << m["Hello"] << endl;
  cout << m.at("Abhishek") << endl;

  cout << m["unknown"] << endl; // 0, as this method creates entry and defaults it to 0
  cout << m.at("unknown") << endl; // Error, (if present after above method, will also return 0)

  // Size
  cout << "Size: " << m.size() << endl;

  // To check presence
  cout << m.count("Agarwal") << endl; // returns 1 as key is present
  cout << m.count("random") << endl; // return 0 as key is not present

  // Erase
  m.erase("unknown");
  cout << "Size: " << m.size() << endl;

  // Iterators
  // for (auto i:m) {
  //   cout << i.first << " " << i.second << endl;
  // }

  unordered_map<string, int> :: iterator it = m.begin();

  while (it != m.end()) {
    cout << it->first << " " << it->second << endl;
    it++;
  }

  return 0;
}