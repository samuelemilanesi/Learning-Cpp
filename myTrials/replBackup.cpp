#include <iostream>
#include <vector>
using namespace std;


/* DEFINIZIONE CLASSI */
/*=========================================================*/
class Test
{
  private:
    int id;
    int* ptr_ext_id;
  public:
    Test(int& ident, int& ext_id)
      :id(ident), ptr_ext_id(&ext_id){};
    void print() const
    {
      cout<<"--- TEST ---\n"<< "id: "<<id<<"\nid location: "<< &id<<"\nExternal Id: "<< *ptr_ext_id<<"\nExternal id location: "<< ptr_ext_id<<endl;
    }
    void increase_id(){id++;};
};



/*=========================================================*/



/* DEFINIZIONE FUNZIONI*/
/*=========================================================*/

void int_vector_print(vector<int>& v)
{
	for(auto el: v)
	{
		cout<< el <<endl;
	}
}

/*=========================================================*/




/* MAIN */
/*=========================================================*/

int main() 
{
// /* having fun with pointers

int x(190);
int* ptr(&x); // ptr punta alla variabile x

int* ptr2= new int(x); //qui creo una NUOVA variabile con dentro il valore pari al valore di x e faccio puntare ptr2 a questa nuova variabile

cout<<"---main--- "<< endl;

cout<<"x allocato in: "<< &x<<endl;
cout<<"ptr punta a: " << ptr<<endl;
cout<<"ptr2 punta a: " << ptr2<<endl;

Test prova(*ptr2,*ptr2);
prova.print();

prova.increase_id();
prova.print();

cout<<"---main--- "<<endl;

cout<<"x allocato in: "<< &x<< ";\t\t\tx= "<<x<<endl;
cout<<"ptr punta a: " << ptr<<";\t\t\t*ptr= "<<*ptr<<endl;
cout<<"ptr2 punta a: " << ptr2<<";\t\t\t *ptr2= "<<*ptr2<<endl;

// \end having fun with pointers */


};



