#include <iostream>
#include <string>
using std::string; 
using namespace std;

class Counter {
	private:
		string *name;
	protected:
		int* count;
	public:
		Counter(const string _name, const int _count)
			: name(new string(_name)), count(new int(_count))
		{
			cout<< "I1" << endl;
		}
		Counter(const string _name)
			:Counter(_name,0)
		{
			cout<<"I2"<<endl;
		}
		virtual ~Counter()
		{
			cout<<"D1"<<endl;
		}
	  virtual void incr()
		{
			*count += 1;
		}
		void print()
		{
			cout<< *name << " = " << *count << endl;		
		}
};

class StepCounter: public Counter{
	protected:
		int* step;
	public:
		StepCounter(const string _name, const int _step, const int _count)
			:Counter(_name, _count), step(new int(_step))
		{
			cout<< "I3" << endl;
		}
		StepCounter(const string _name, const int _step)
			:StepCounter(_name,_step,0)
		{
			cout<< "I4" << endl;
		}
		~StepCounter() override
		{
			delete step;
			cout << "D2" << endl;
		}
		void incr() override
		{
			*count += *step;
		}
};




int main()
{
	Counter *c1 = new Counter("c1"); // viene chiamato il costruttore Counter(string) 
                                   // viene letta la initializing list di Counter(string)
                                   // viene eseguito Counter("c1",0)
                                   // (esecuzione body di Counter("c1",0)) -> stampa I1 
                                   // (esecuzione body di Counter(string)) -> stampa I2
 	c1->incr(); // si incrementa il coutner di 1
	c1->incr(); // si incrementa il counter di 1
	c1->print(); // stampa c1=2

	delete c1;  // viene chiamato il distruttore ~Counter()
              // viene eseguito il corpo di ~Counter() -> stampa D1
  cout<<endl;

	StepCounter *c2 = new StepCounter("c2",3,-5); // viene chiamato il costruttore StepCounter(string,int,int)
                                                // viene letta la initializing list di StepCoutner(string,int,int)
                                                // viene eseguito Counter(_name, _count)
                                                // (esecuzione body di 	:Counter(_name, _count)) -> stampa I1
                                                // (esecuizione body di StepCounter(string,int,int)) -> stampa I3
	c2->incr(); // viene incrementato il counter di 3
	c2->incr(); // viene incrementato il coutner di 3
	c2->print(); // stampa c2=1
	
	delete c2; // viene chiamato il distruttore ~StepCounter()
             // viene distrutto il figlio eseguendo il corpo di ~StepCounter() -> stampa D2 
             // viene distrutta la madre eseguendo il corpo di ~Counter() -> stampa D1
  cout<<endl;


// occhio al polimorfismo
	Counter *c3 = new StepCounter("c3", -2); // viene chiamato il costruttore StepCounter(string, int) 
                                           // viene letta la initializing list di StepCounter(string,int)
                                           // viene chiamato StepCounter("c3",-2,0)
                                           // viene letta la initializing list di StepCounter("c3",-2,0)
                                           // viene eseguito Counter(_name, _count)
                                           // (esecuzione body di 	:Counter(_name, _count)) -> stampa I1
                                           // viene eseguito il body di StepCounter(string,int,int) -> stampa I3
                                           // viene eseguito il body di StepCounter(string,int) -> stampa I4
	c3->incr(); // la funzione incr() è virtuale: c3 viene considerato come polimorfismo e si utilizza la dichiarazione della funzione che per ultima overridda incr() -> count += -2
	c3->incr(); // come sopra -> count = -4
	c3->print(); // stampa c3 = -4
	
	delete c3; // il distruttore è virtuale: c3 è un polimorfismo e si utilizza la dichiarazione del distruttore che per ultima overridda il distruttore -> viene chiamato ~StepCounter() 
            // prima viene uccisa la parte figlia eseguendo il body di ~StepCounter() -> stampa D2
            // poi viene uccisa la parte madre eseguendo il body di ~Counter() -> stampa D1
  cout<<endl;


  // Output: I1 I2 c1=2 D1 \n I1 I3 c2=1  D2 D1 \n I1 I3 I4 c3=-4 D2 D1 \n
	


/*
Togliendo gli i `virtual` e gli `override` avremmo che tutti i polimorfismi sono risolti chiamando le funzioni del type con cui sono stati dichiarati (quindi le funzioni della classe madre). Questo comporta che:
  - c3 chiama la funzione incr() della classe madre due volte stampando quindi c3=2
  - c3 chiama il distruttore della classe madre non stampando D2 e causando un memory leak per la variabile step allocata sulla heap e non più raggiungibile
*/
	return 0;
}
