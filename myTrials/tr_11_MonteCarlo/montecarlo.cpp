//Parallel Monte Carlo
#include<iostream>
#include<random> 
#include<functional>
#include<mpi.h>
#include<math.h>


double MonteCarlo(std::function<double(double)> ICDF,
 std::function<double(double)> f, unsigned long n_iter);


class ExpICDF
{
private:
	double lambda=1;
public:
	InverseExponential(double _l): lambda(_l){};

	double operator()(double y) const
	{
		return (1/lambda * log(1-y));
	}
}

class Squared
{
public:
	double operator()(double x) const
	{
		return x*x;
	}
}

int main(int argc, char const *argv[])
{
	MPI_Init(&argc, &argv);
	double y = MonteCarlo(ExpICDF(2), Squared(), 1e6);

	if(rank==0)
		std::cout << "f(X) is in avarage equal to " << y << std::cout;

	// result should be 0.25
	MPI_Finalize();

	return 0;
}


double MonteCarlo(std::function<double(double)> ICDF,
std::function<double(double)> f, unsigned long iter)
{
	unsigned rank(0), size(0);
	MPI_Comm_rank(MPI_COMM_WOLRD, &rank);
	MPI_Comm_size(MPI_COMM_WOLRD, &size);
	
	unsigned long local_iter(iter/size);
	std::vector<double> local_results;

	std::uniform_real_distribution<double> udist(0,1);
	std::standard_random_engine gen(rank);
	for(unsigned long k=0; k<local_iter; ++k)
	{	
		double campioned_x = ICDF(udist(gen));
		local_results.push_back(f(campioned_x));
	}
	double res(0);
	MPI_Allreduce(local_results.data(), &res, local_iter, MPI_DOUBLE, MPI_SUM, MPI_COMM_WOLRD);

	return res/n_iter;
}