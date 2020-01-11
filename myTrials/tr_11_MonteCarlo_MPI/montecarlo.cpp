//Parallel Monte Carlo
#include<iostream>
#include<random> 
#include<functional>
#include<mpi.h>
#include<math.h>


/* Given a r.v. X characterized by its ICDF, a function h, the numer of iterations simulates the distribution via Smirnov Transform and returns ExpectedValue[h(X)] with Monte Carlo paralellizing the computation */
 
double MonteCarlo(std::function<double(double)> ICDF,
 std::function<double(double)> h, unsigned long n_iter);


/* callable object of the inverse cumulative distribution function of an exponential distribution*/
class ExpICDF
{
private:
	double lambda=1;
public:
	ExpICDF(double _l): lambda(_l){};

	double operator()(double y) const
	{
		return (-1/lambdai * log(1-y));
	}
};

/*callable obj of the function h(x)=x^2 */
class Squared
{
public:
	double operator()(double x) const
	{
		return x*x;
	}
};

int main(int argc, char *argv[])
{
	MPI_Init(&argc, &argv);
	int rank(0);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double y = MonteCarlo(ExpICDF(0.5), Squared(), 1e8);

	if(rank==0)
		std::cout << "f(X) is in avarage equal to " << y << std::endl;

	MPI_Finalize();

	return 0;
};


double MonteCarlo(std::function<double(double)> ICDF,
std::function<double(double)> f, unsigned long iter)
{
	int rank(0), size(0);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	unsigned long local_iter(iter/size);
	double  local_sum(0);

	std::uniform_real_distribution<double> udist(0,1);
	std::default_random_engine gen(rank);
	for(unsigned long k=0; k<local_iter; ++k)
	{	
		double campioned_x = ICDF(udist(gen));
		local_sum+=f(campioned_x);
	}
	double res(0);
	MPI_Allreduce(&local_sum, &res, 1,MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

	return  res/iter;
};
