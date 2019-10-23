#include <iostream>
#include<vector>


using std::cout;
using std::endl;
using std::vector;

constexpr std::size_t SIZE =10;

int main(){
  int a[SIZE] = {1, 2, 3}; 
  vector<int> v ={1, 2, 3};
  //Q: What are a & v content?
  
  // A: a={1,2,3,0,0,0,0,0,0,0} (array); v={1,2,3} (vector)


  const int & second = a[1];  // const ref: we cannot change a[1] changing "second"
  int * const p = &a[1]; // const ptr to a[1] cannot point to any other object
  const int * const p2 = &a[1]; // const ptr const content to a[1] cannot change a[1] changing *p2
  int *p3 = &a[1]; //ptr to a[1]

  // in the following, fix errors (say why and comment out what is wrong)

  // second=3; --> // cannot work because second is const
  *p=3; // value of a[1]=3: a={1,3,3,0,0,...,0}
  // p++; --> // cannot work: the pointer is fixed to point to a[1]
  // p2++; --> // cannot work the pointer is fixed to point to a[1]
  // *p2 = 3; --> // cannot work: *p2 is const
  // p2 = end(a)-1; // I'VE JUST SAID THAT THIS CANNOT POIN ANYWHERE ELSE BUT a[1]!!!!

  *p3 = 4;  // the value of a[1]=4
  p3 = std::end(a)-1;  // end p3 now points to a[ 0 + SIZE - 1]=a[9] same as  p3=a+SIZE-1;
 
  int & r2 = *p3; // reference to a[9]

  r2 =7; // a[8]=7

  // what output we get here? 
  for (auto & elem : a )
    cout << elem << " ";
  cout << endl;

  //output: 1 4 3 0 0 0 0 0 7 0 

  // what output we get here? does it compile?
  
  for (auto it = v.cbegin(); it!= v.cend(); ++it){
    cout << *it << " ";
   // *it = *it + 1; -->// by default an iterator is const
  }
  cout << endl;

  //cannot compile because because of *it+=1, without that output: 1 2 3 

  // what output we get here?
  for (auto it = v.cbegin(); it!= v.cend(); ++it){
    cout << *it << " ";
  }
  cout << endl;
// output: 2 3 4 
  return 0;
}
