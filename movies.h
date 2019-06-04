// movies.h
// Samuel Guo

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <string>

using namespace std;

class Movie {

  public:
    string movie_name;
    double rating;
    int depth;
    Movie *left, *right, *parent;
    ~Movie();
    Movie(string name, double r, int d) : movie_name(name), rating(r), depth(d), left(0), right(0), parent(0) { }
    };


class MovieBST {

 public:
    MovieBST();                   // constructor
    MovieBST(Movie* m);
    ~MovieBST();                  // destructor
    Movie *root;
    void empty(Movie* m);
    bool insert(string name, double rate);
    bool insert(string name, double rate, Movie* m, int deep);
    void printPreOrder(Movie* root);
    Movie* find(string name, Movie* root);
    Movie* findPrefix(string prefix, Movie* root);
    Movie* findPrefixHelper(string prefix, MovieBST* fixed, Movie* root);
    Movie* findMax(Movie* root);
    Movie* findMaxHelper(Movie* root); 
    void analytics();

}; 

#endif
