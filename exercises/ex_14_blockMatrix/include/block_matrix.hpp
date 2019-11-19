#ifndef BLOCKMATRIX_H_
#define BLOCKMATRIX_H_

#include <vector>

#include "block.hpp"

class BlockMatrix: public Matrix
{
private:
  std::vector<Block> blocks; 

  // given two indexes returns if the element (i,j) is in the block pointed by it
  bool is_in_block(size_t i, size_t j, std::vector<Block>::const_iterator it) const;

  public:
  BlockMatrix();

  double& operator () (std::size_t i, std::size_t j) override;

  double operator () (std::size_t i, std::size_t j) const override;


  void add_block(const Block&); 

};

#endif /* BLOCKMATRIX_H_ */
