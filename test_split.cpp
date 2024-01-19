/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include<iostream>
using namespace std;


int main(int argc, char* argv[])
{
  cout << "CASE1: 1 3 7 15" << endl;
  
  Node *n15 = new Node(15, nullptr);
  Node *n7 = new Node(7, n15);
  Node *n5 = new Node(5, n7);
  Node *n1 = new Node(1, n5);

  Node *ptr = n1;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

  Node *odds = nullptr;
  Node *evens = nullptr;
  split(n1, odds, evens);

  cout << "odds: " << endl;
  ptr = odds;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

  cout << "evens: " << endl;
  ptr = evens;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

  cout << "CASE2: 2 9" << endl;
  odds = nullptr;
  evens = nullptr;
  
  Node *n9 = new Node(9, nullptr);
  Node *n2 = new Node(2, n9);

  // print before
  ptr = n2;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

  odds = nullptr;
  evens = nullptr;
  split(n2, odds, evens);

  // print after
  cout << "odds: " << endl;
  ptr = odds;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

  cout << "evens: " << endl;
  ptr = evens;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;


  cout << "CASE2: 4" << endl;
  
  Node *n4 = new Node(4, nullptr);

  ptr = n4;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

  odds = nullptr;
  evens = nullptr;
  split(n4, odds, evens);

  cout << "odds: " << endl;
  ptr = odds;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

  cout << "evens: " << endl;
  ptr = evens;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

  cout << "CASE4: 1 2 4 7 9 10 11" << endl;
  
  Node *n11 = new Node(11, nullptr);
  Node *n10 = new Node(10, n11);
  n9->next = n10;
  n7->next = n9;
  n4->next = n7;
  n2->next = n4;
  n1->next = n2;

  ptr = n1;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

  odds = nullptr;
  evens = nullptr;
  split(n1, odds, evens);

  cout << "odds: " << endl;
  ptr = odds;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

  cout << "evens: " << endl;
  ptr = evens;
  while(ptr!=nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << endl;

}
