/* Parallel computing program to evaluate the integral of a function using trapezoidal rule */
#include <iostream>
#include <mpi.h>

void get_input(double& a, double&v, unsigned& n);
void sum_and_print( double local_integral, std::streamo& out, double a, double b, unsigned n);

int main(int argc, char* argv[])
{
	double a(0);
	double b(1);
	int n(10);
	if(argc==3)
	{
		a=(double)argv[1];
		b=(double)argv[2];	
	}
}

void get_input(double& am double& v, unsigned& n)
{
	int rank;
	MPI_Comm_rank(MPI_COMM_WOLRD, &rank);
	if(rank==0)
		std::cin>> a >> b >> n; 
	MPI_Bcast(&a,1,MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(&b,1,MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(&n,1,MPI_DOUBLE, 0, MPI_COMM_WORLD);
}

void sum_and_print( double local_integral, std::streamo& out, double a, double b, unsigned n)
{
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double total(0.0);
MPI_Reduce(&local_integral, &total,1, MPI_DOUBLE,
}


