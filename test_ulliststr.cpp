#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  // ULListStr dat;
  // dat.push_back("7");
  // dat.push_front("8");
  // dat.push_back("dog 9");
  // cout << "dat.get(0): " << dat.get(0) << endl;
  // cout << "dat.get(1): " << dat.get(1) << endl;
  // cout << "dat.get(2): " << dat.get(2) << endl;
  // // prints: 8 7 dog 9
  // cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
  // cout << dat.back() << endl; // prints dog 9
  // cout << dat.front() << endl; // prints 8
  // dat.pop_back();
  // dat.pop_front();
  // cout << dat.get(0) << endl; // prints 7

  ULListStr list;

	list.push_back("a");

	// ASSERT_EQ("a", list.get(0));

	list.pop_front();

	// ASSERT_EQ(0, list.size());


}
