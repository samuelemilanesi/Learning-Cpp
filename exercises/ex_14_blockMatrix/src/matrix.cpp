#include "matrix.hpp"

Matrix::Matrix(size_t rows, size_t cols)
    : n_rows(rows), n_cols(cols) {}

size_t Matrix::get_n_cols() const
{
  return n_cols;
};

size_t Matrix::get_n_rows() const
{
  return n_rows;
};

void Matrix::set_n_cols(size_t c)
{
  n_cols=c;
};

void Matrix::set_n_rows(size_t r)
{
  n_rows=r;
};