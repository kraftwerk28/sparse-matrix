#ifndef __MATRIX_H_
#define __MATRIX_H_
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <list>
#include <tuple>

#define FR_TL "┏"
#define FR_TR "┓"
#define FR_BL "┗"
#define FR_BR "┛"
#define FR_V "┃"
#define FR_H "━"
#define SYM_W 10
#define i_list std::initializer_list

class SparseMatrix;
class RegularMatrix;
// Звичайна матриця
class RegularMatrix {
 public:
  RegularMatrix(size_t width, size_t height);
  RegularMatrix(i_list<i_list<int>> l);
  SparseMatrix convert();
  ~RegularMatrix();
  void print();
  size_t w, h;

  int* operator[](size_t i) { return data[i]; }

 private:
  int** data;
};

// Розріджена матриця
class SparseMatrix {
 public:
  SparseMatrix();
  RegularMatrix convert();
  void push(size_t x, size_t y, int num);
  int& get(size_t x, size_t y);
  size_t w{0}, h{0};

 private:
  struct Elem {
    Elem(size_t _x, size_t _y, int _data) : x(_x), y(_y), data(_data){};
    uint x, y;
    int data;
  };
  std::list<Elem> data;
};

#endif
