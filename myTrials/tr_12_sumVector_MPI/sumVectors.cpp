#include<iostream>
#include<mpi.h>
#include<cstddef>
#include<vector>
using std::vector;

int sum_vector_elements(vector<int>& local_vector);


int main(int argc, char* argv[])
{
	MPI_Init(&argc,&argv);
	int rank(0);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	vector<int> v1;

	// suppose data are available only at process 0
	if(rank==0)
	{
		constexpr std::size_t vector_size(100000);
		v1.assign(vector_size,3);
	}

	// parallel summation of the vectors
	
	// parallel summation of vector's elements
	int total_sum = sum_vector_elements(v1); 
	
	if(rank==0)
		std::cout<< "sumElements(v1) = " << total_sum<< std::endl;
}

int sum_vector_elements(vector<int>& vec)
{
	int rank(0), size(0);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	// perform block scatter of data 
	
	int local_size=vec.size()/size;
	MPI_Bcast(&local_size,1, MPI_INT,0,MPI_COMM_WORLD);
	vector<int> local_vec(local_size,0);
	MPI_Scatter(vec.data(),local_size,MPI_INT, local_vec.data(),local_size,MPI_INT,0,MPI_COMM_WORLD);
	int local_sum(0);
	for(const auto& el: local_vec)
		local_sum+=el;
	MPI_Allreduce(MPI_IN_PLACE, &local_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	return local_sum;
}
