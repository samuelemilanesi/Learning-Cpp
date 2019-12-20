#include <fstream>
#include <iostream>

#include <mpi.h>

#include "dense_matrix.hpp"

int main(int argc, char *argv[])
{
  MPI_Init(&argc, &argv);

  int rank(0), size(0);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  DenseMatrix full_A(0, 0);
  DenseMatrix full_B(0, 0);
  unsigned m(0), n(0), p(0);
  if (rank == 0)
  {
    std::ifstream first(argv[1]), second(argv[2]);
    full_A.read(first);
    full_B.read(second);
    m = full_A.rows();
    n = full_A.columns();
    p = full_B.columns();
  }

  // First rank 0 has to broadcast sizes of A and B
  MPI_Bcast(&m, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);
  MPI_Bcast(&n, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);
  MPI_Bcast(&p, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);

  DenseMatrix local_B(n, p);
  // Broadcast B
  if (rank == 0)
  {
    MPI_Bcast(full_B.data(), n * p, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    local_B = full_B;
  }
  else
  {
    MPI_Bcast(local_B.data(), n * p, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  }
  const unsigned stripe = m / size;
  DenseMatrix local_A(stripe, n);
  MPI_Scatter(full_A.data(), stripe * n, MPI_DOUBLE,
              local_A.data(), stripe * n, MPI_DOUBLE,
              0, MPI_COMM_WORLD);

  DenseMatrix local_C = local_A * local_B;

  DenseMatrix full_C(m, p);
  MPI_Allgather(local_C.data(), stripe * p, MPI_DOUBLE,
                full_C.data(), stripe * p, MPI_DOUBLE,
                MPI_COMM_WORLD);

  if (rank == 0)
  {
    std::cout << full_C.rows() << " " << full_C.columns() << "\n";

    for (std::size_t i = 0; i < full_C.rows(); ++i)
      for (std::size_t j = 0; j < full_C.columns(); ++j)
      {
        std::cout << full_C(i, j);
        std::cout << (full_C.columns() - j == 1 ? "\n" : " ");
      }
  }

  MPI_Finalize();
  return 0;
}
