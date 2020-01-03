#include <iostream>
#include "mpi.h"
#include <random>
#include <string>

double square(double x);

double approximate_pi(unsigned long, unsigned);

int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	int rank;
	if(argc!=3)
	{
		std::cerr << "Must insert 2 args"<< std::endl;
	}
	else
	{
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		
		unsigned long iterations(std::stoul(argv[1]));
		unsigned darts(std::stoi(argv[2]));
		
		double pi=approximate_pi(iterations, darts);
		
		if(rank==0)
			std::cout<<"pi approximation = " << pi << std::endl; 
	}

	MPI_Finalize();

	return 0;

}

double square(double x){ return x*x; } 

double approximate_pi(unsigned long iterations, unsigned darts)
{
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	std::cout << "OK FINO A QUI"<< " rank= "<< rank << "size= " << size  <<std::endl;	
	
	// local variables
	unsigned long local_iterations(iterations/(unsigned)size);
	double local_pi(0), local_x(0), local_y(0);
	unsigned local_score(0);

	std::uniform_real_distribution<double> udist(-1.0,1.0);
	std::random_device rd;

	for(unsigned long k=0; k<local_iterations; ++k)
	{
		local_score=0;
		for(unsigned j=0; j<darts;++j)
		{
			std::default_random_engine genx(rd()), geny(rd());

			local_x=udist(genx);
			local_y=udist(geny);

			if( square(local_x)+square(local_y) < 1)
				local_score++;
		}
		local_pi += (double)local_score; 
	}
	local_pi= 4.0*local_pi/( (double)(darts*local_iterations));

	double pi(0);

	MPI_Allreduce(&local_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
	return pi/(double)size;
}


