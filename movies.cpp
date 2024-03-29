// movies.cpp
// Samuel Guo

#include <iostream>
#include <string>
#include "movies.h"

using namespace std;

MovieBST::MovieBST() {
  root = 0;
  }
MovieBST::MovieBST(Movie* m) {
  root = m;
  }

void MovieBST::empty(Movie *m) {
  if(m) {
    empty(m->left);
    empty(m->right);
    delete m;
  }
}

bool MovieBST::insert(string name, double rate) {
  N_visited = 0;
  if(!root) {
    root = new Movie(name, rate, 0);
    N = 1;
    return true;
  }
  return insert(name, rate, root, 0);
}

bool MovieBST::insert(string name, double rate, Movie* m, int deep) {
  Movie* temp = new Movie(name, rate, deep);
  if(name == m->movie_name) return false;
  if(name < m->movie_name) {
    if(m->left) return insert(name, rate, m->left, deep+1);
    else {
      m->left = new Movie(name, rate, deep+1);
      N++;
      N_visited = deep + 1;
      return true;
    }
  }
  else {
    if(m->right) return insert(name, rate, m->right, deep+1);
    else {
      m->right = new Movie(name, rate, deep+1);
      N++;
      N_visited = deep + 1;
      return true;
    }
  }
}

void MovieBST::printPreOrder(Movie* root) {
    if (root) {
	cout << root->movie_name << ", " << root->rating << ", " << root->depth << endl;
	printPreOrder(root->left);
	printPreOrder(root->right);
    }
}

Movie* MovieBST::find(string name, Movie* root) {
  while(root) {
    if(name == root->movie_name) return root;
    else if (root->movie_name < name) return find(name, root->right);
    else return find(name, root->left);
  }
  return 0;
}

Movie* MovieBST::findPrefix(string prefix, Movie* root) {
  MovieBST* fixed = new MovieBST;
    return findPrefixHelper(prefix, fixed, root);
}

Movie* MovieBST::findPrefixHelper(string prefix, MovieBST* fixed, Movie* root) {
     if (root) {
        if (root->movie_name.substr(0, prefix.size()) == prefix) fixed->insert(root->movie_name, root->rating);
	findPrefixHelper(prefix, fixed, root->left);
	findPrefixHelper(prefix, fixed, root->right);
    }
    return fixed->root;
}

Movie* MovieBST::findMax(Movie* root) {
    Movie* max = root;
    return findMaxHelper(root);
}

Movie* MovieBST::findMaxHelper(Movie* root) {
    Movie* max = root;
    if(root->left) {
        Movie* leftMax = findMaxHelper(root->left);
        if(max->rating < leftMax->rating)
            max = leftMax;
    }

    if(root->right) {
        Movie* rightMax = findMaxHelper(root->right);
        if(max->rating < rightMax->rating)
            max = rightMax;
    }
    return max;

}


MovieBST::~MovieBST(){
  empty(root);
}

Movie::~Movie(){
  movie_name = "";
  rating = 0;
  depth = 0;
  left = 0;
  right = 0;
  parent = 0;
}
