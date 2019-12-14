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


vector<int>& vectorize_triplete(int a, int b, int c)
{
// NON E` UNA BUONA IDEA CREARE CON NEW E RESITUTIRE LA REFERENCE
	vector<int>* result = new vector<int>({a,b,c});
	cout<< "triplete address: " << result<<endl;
	return *result;
}

/*=========================================================*/




/* MAIN */
/*=========================================================*/

int main() 
{
/* having fun with pointers

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

// end having fun with pointers */


/* having fun with return references dynamically allocated

int a=1; int b=2; int c=3;

vector<int>& v(vectorize_triplete(a, b, c));

cout<< "vector v address: " << &v <<endl;
int_vector_print(v);
delete &v;

// end having fun with return reference dynamically allcated */



};






