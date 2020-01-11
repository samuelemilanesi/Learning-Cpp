# Functional C++
Molte funzioni sarebbe utile ricevessero in input altre funzioni. Un esempio sono funzioni di integrazione numerica, ottimizzazione, equation solvers, ... . Queste funzioni sono dette *funzioni di ordine superiore*. 
C++ non mette a disposizione *types* corrispondenti a funzioni: per utilizzare funzioni di ordine superiore si fa uso di **callable objects**.

## Callable objects
Gli oggetti invocabili sono oggetti che definiscono al loro interno l' `operator()` pubblico. In questo modo alle funzioni di grado superiore passata una funzione ma un callable object avente al suo interno il metodo richiesto.
 
```c++

class is_small
{
public:
	bool operator()(double x) const
	{
		return x<100;
	} 
}
unsigned count_if(const vector<double>& v, is_small op)
{	
	unsigned cnt(0);
	for(const auto& el: v)
		if(is_small.(el))
			cnt++;
	return cnt;
}
```
## Funzioni di ordine superiore
Noto l'uso dei callable objectes bisogna elaborare funzioni di ordine superiore ben progettate: nell'esempio della funzione `count_if`, per come \'e stata implementata nell'esempio, pu\'o ricevere in ingresso solo un oggetto invocabile di tipo `is_small`. Quello che vorremmo \'e che la funzione `count_it` possa prendere in input una grande classe di callable objcts per cui abbia senso il suo utilizzo. 

### L'header \<functional\>
Per il nostro scopo includeremo l'header `<functional>` che permette di fare overloading con functional objects come segue:
```c++
/#include<functional>
unsigned count_if(const std::vector<double>& v, const std::function<bool(double)>& fun) // overloading su tutti i callable objects i cui operatori () prendono in input double e resituiscono bool
{
	unsigned cnt(0);
	for(const auto& el: v)
		if(is_small.(el))
			cnt++;
	return cnt;
}
// adesso la funzione count_it pu\'o prendere in ingresso qualunque callable che riceva in ingresso un double e restituisca un bool
```


