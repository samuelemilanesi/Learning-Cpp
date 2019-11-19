#ifndef MATRIX_H_
#define MATRIX_H_
#include <vector>
using std::size_t;

class Matrix
{
protected:
  size_t n_rows;
  size_t n_cols;

public:
  Matrix(size_t rows, size_t cols);

  virtual double &operator()(std::size_t i, std::size_t j) = 0;
  virtual double operator()(std::size_t i, std::size_t j) const = 0;

  size_t get_n_cols() const;
  size_t get_n_rows() const;

  void set_n_cols(size_t);
  void set_n_rows(size_t);
  

};

#endif /* MATRIX_H_ */
