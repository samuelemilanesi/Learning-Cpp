#include <iostream>
#include <cstdio>
#include <mpi.h>
int main (int argc, char* argv[])
{
    MPI_Init (&argc, &argv);
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::cout<< "Hello world from process "<< rank <<" of " << size<< "\n";
    MPI_Finalize();

}

// to compile: mpicxx -o exe mail.cpp
// to run: mpiexec -np 5 exe // where 5 is the number of processes