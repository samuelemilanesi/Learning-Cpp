#include <iostream>
#include <random> 
#include <string>

int main(int argc, char *argv[])
{

    // receive as input the range 
    double range_from(0);
    double range_to(1);
    if(argc==3)
    {
        range_from=(double)*argv[2];
        range_to=(double)*argv[3];
    };

    // randomness source
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_real_distribution<double>  distr(range_from, range_to);

    
     std::cout << distr(generator) << '\n';

    std::string file_name("coors.txt");
    //std::ofstream ostr {file_name};
    


}