#ifndef list_h
#define list_h
#include <iostream>
#include "nodo.h"	
using std::cout;
using std:: cin;	
template<class T>	
class List
	{
	private:
		Nodo<T> *head;
		Nodo<T> *tail;
		int numelem;
		
	public:
		List();
		List(const List &a);
		bool isEmpty();
		void insert(T x);
		void print();
		void insertAt(T n, int pos);
		void deletee(int pos);
		T getElement(int pos);
		void invertir();
		void append(const List &x);
		void create(int num);
		void erase();
		~List();
		
	};


template<class T>
List<T>::List()
{
	head=NULL;
	numelem=0;
	
}

template<class T>
bool List<T>::isEmpty()
{
	return(head==NULL);
	
}
template<class T>
void List<T>::insert(T x)
{
	Nodo<T> *aux;
	aux=new Nodo<T>(x);
	
	if(isEmpty())
		head=tail=aux;
	else 
		{
			tail->modificarsig(aux);
			tail=aux;
			
			
		}
	numelem++;
	
}
template<class T>
void List<T>:: print()
{
	Nodo<T> *aux= head;
	int i ;
	
	i=1;
	if(isEmpty())
	{
		cout<<"la list esta isEmpty"<<std::endl;
		
	}else{
		while(aux!=NULL)
		{
			aux->print();
			
			aux=aux->consultarsig();	
			i++;	
		
		}
		cout<<"NULL"<<std::endl;
	}
	
}
template<class T>
void List<T>::insertAt(T n , int pos)
{
	Nodo<T> *actual,*anterior,*aux,*temp;
	temp=new Nodo<T> (n);
	int i=1;
	actual=head;
	
	if(pos==0 || pos==1 )
	{
		head=temp;
		head->modificarsig(actual);
		
	}else{
	
		while(i<pos)
			{
				anterior=actual;
				actual=actual->next;
				i++;
			}
	
		
		if(pos==numelem)
		{
			tail->sig=temp;
			tail=tail->sig;
		
		}else{
				aux=actual;
				anterior->sig=temp;
				temp->sig=aux;
			}
	}
	
numelem++ ;
}
template<class T>
T List<T>:: getElement(int pos)/*funciona*/
{
	Nodo<T> *aux;
	int i=1;
	if(pos<=numelem){
	
		aux=head;
		while(i<pos)
		{
			aux=aux->sig;
			i++;
		}
	}
	return(aux->consultare());
}
	
template<class T>	
List<T>::List(const List &a)
{
	Nodo<T> *aux,*creando;
	aux=a.head;
	head=new Nodo<T>(aux->consultare());
	aux=aux->consultarsig();
	creando=head;
	while(aux)
	{
		creando->sig=new Nodo<T>(aux->consultare());
		creando=creando->consultarsig();
		aux=aux->consultarsig();
	}
	
}
	

template<class T>
void List<T>::create(int n)/*funciona*/
{
	int i =1;
	int value;
	for (i=1 ; i<=n ;i++)
	{
		cout<<"inserte el valor a agregar al elemento "<<i<<std::endl;
		cin>>value;
		insert(value);
	}
	
	
}
template<class T>
List<T>::~List()/*no probado aun */
{
	erase();
}
template<class T>
void List<T>::erase()
{
	Nodo<T> *liberando;

	while(head!=NULL)
	{
		liberando=head;
		head=head->consultarsig();
		delete liberando;
	}
	head=NULL;
	numelem=0;
}

template<class T>
void List<T>::deletee( int pos)
{
	Nodo<T> *actual,*anterior;
	int i=1;
	actual=head;
	if (pos>numelem){
		cout<<"no hay tantos elementos en la list"<<std::endl;
	}
	else if(pos==1)
		{
		head=head->consultarsig();
		
		}
		else{
		
			while(i<pos)
			{
				anterior=actual;
				actual=actual->consultarsig();
				i++;
			}
			if(numelem==pos)
			{
				tail=anterior;
				tail->modificarsig(NULL);
		
			}
			else
				{
					anterior->modificarsig(actual->consultarsig());
				}
		
		}
		
		numelem --;
	
	
}

template<class T>
void List<T>::append(const List<T> &x)
{
	Nodo<T> *aux;
	aux=x.head;
	
		while (aux)
		{
			insert(aux->consultare());
			aux=aux->consultarsig();
		}
	
}


#endif
