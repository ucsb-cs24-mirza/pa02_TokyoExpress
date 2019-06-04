// tests.h
// Samuel Guo

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <string>
#include "movies.h"

using namespace std;

bool testAdd() {
  MovieBST test;
  test.insert("lol", 3.3);
  if(test.root->movie_name == "lol") return true;
  return false;
}

bool testAdd2() {
  MovieBST test;
  test.insert("lol", 3.3);
  test.insert("mol", 4.5);
  if (test.root->right->movie_name == "mol") return true;
  return false;
}

bool testFind() {
  MovieBST test;
  test.insert("lol", 3.3);
  test.insert("mol", 4.5);
  if (test.find("mol", test.root)) return true;
  return false;
}

void testPrefix() {
  MovieBST test;
  test.insert("lol", 3.3);
  test.insert("mol", 4.5);
  test.insert("fol", 4.5);
  test.insert("eee", 4.2);
  test.insert("lqw", 3.4);
  test.insert("lll", 6.7);
  Movie* lol = test.findPrefix("l", test.root);
  test.printPreOrder(lol);
}

void testPreOrder() {
  MovieBST test;
  test.insert("lol", 3.3);
  test.insert("mol", 4.5);
  test.printPreOrder(test.root);
}

void testMax() {
  MovieBST test;
  test.insert("lol", 3.3);
  test.insert("mol", 4.5);
  test.printPreOrder(test.root);
  cout << test.findMax(test.root)->rating << endl;
}

#endif
