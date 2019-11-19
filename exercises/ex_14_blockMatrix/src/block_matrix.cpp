#include <limits>
#include <iostream>

#include "block_matrix.hpp"

BlockMatrix::BlockMatrix()
    : Matrix(0, 0) {}

void BlockMatrix::add_block(const Block &b)
{

  // increase the number of rows if necessary
  if (get_n_rows() < b.get_bottom_right_row() + 1)
    set_n_rows(b.get_bottom_right_row() + 1);
  // increase the number of cols if necessary
  if (get_n_cols() < b.get_bottom_right_col() + 1)
    set_n_cols(b.get_bottom_right_col() + 1);

  blocks.push_back(b);
}
double BlockMatrix::operator()(std::size_t i, std::size_t j) const
{
  if (i > n_rows - 1 || j > n_cols - 1)
    std::cerr << "ERROR: indexes exceed matrix dimensions" << std::endl;

  for (auto it = blocks.begin(); it != blocks.end(); ++it)
  {
    if (is_in_block(i, j, it))
    {
      return it->operator()(i - it->get_top_left_row(), j - it->get_top_left_col());
    }
  }
  return 0;
}

double &BlockMatrix::operator()(std::size_t i, std::size_t j)
{
  for (auto it = blocks.begin(); it != blocks.end(); ++it)
  {
    if (is_in_block(i, j, it))
    {
      return it->operator()(i - it->get_top_left_row(), j - it->get_top_left_col());
    }
  }

  add_block( Block(i, j, i, j, {0} ));
  return (blocks.end() - 1)->operator()(0, 0);
}

bool BlockMatrix::is_in_block(size_t i, size_t j, std::vector<Block>::const_iterator it) const
{
  bool flag((i >= it->get_top_left_row() && i <= it->get_bottom_right_row()) &&
         (j >= it->get_top_left_col() && j <= it->get_bottom_right_col()));

  return (i >= it->get_top_left_row() && i <= it->get_bottom_right_row()) &&
         (j >= it->get_top_left_col() && j <= it->get_bottom_right_col());
}