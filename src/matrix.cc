#include "matrix.h"

RegularMatrix::RegularMatrix(size_t width, size_t height)
    : w(width), h(height) {
  data = new int*[height];
  for (size_t i = 0; i < height; ++i) {
    data[i] = new int[width];
  }
}

RegularMatrix::RegularMatrix(i_list<i_list<int>> l) {
  h = l.size();
  w = l.begin()->size();
  data = new int*[h];
  for (size_t i = 0; i < h; ++i) {
    auto ptr = l.begin() + i;
    data[i] = new int[w];

    for (size_t j = 0; j < w; ++j) {
      data[i][j] = *(ptr->begin() + j);
    }
  }
}

RegularMatrix::~RegularMatrix() {
  for (size_t i{0}; i < h; ++i) {
    delete[] data[i];
  }
  delete[] data;
}

SparseMatrix RegularMatrix::convert() {
  SparseMatrix res{};
  for (uint i{0}; i < h; ++i) {
    for (uint j{0}; j < w; ++j) {
      if (data[i][j] != 0) {
        res.push(i, j, data[i][j]);
      }
    }
  }
  return res;
}

void RegularMatrix::print() {
  using std::cout;
  using std::endl;
  using std::setw;
#define co cout << setw(SYM_W)
  co << endl << FR_TL;
  for (uint i{0}; i < w; ++i) {
    co << " ";
  }
  co << FR_TR << endl;
  for (uint i{0}; i < h; ++i) {
    co << FR_V;
    for (uint j{0}; j < w; ++j) {
      co << data[i][j];
    }
    co << FR_V << endl;
  }
  co << FR_BL;
  for (uint i{0}; i < w; ++i) {
    co << " ";
  }
  cout << setw(SYM_W) << FR_BR << endl;
}

SparseMatrix::SparseMatrix() {}

void SparseMatrix::push(size_t x, size_t y, int num) {
  data.push_back(Elem{x, y, num});
  if (++x > w) w = x;
  if (++y > h) h = y;
}

RegularMatrix SparseMatrix::convert() {
  RegularMatrix res{w, h};
  for (Elem e : data) {
    res[e.y][e.x] = e.data;
  }
  return res;
}
