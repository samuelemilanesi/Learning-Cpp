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
		~StepCounter()
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
	Counter *c1 = new Counter("c1");
	c1->incr();
	c1->incr();
	c1->print();

	delete c1;


	StepCounter *c2 = new StepCounter("c2",3,-5);
	c2->incr();
	c2->incr();
	c2->print();
	
	delete c2;


	Counter *c3 = new Counter("c3", -2);
	c3->incr();
	c3->incr();
	c3->print();
	
	delete c3;
	
	return 0;
}
