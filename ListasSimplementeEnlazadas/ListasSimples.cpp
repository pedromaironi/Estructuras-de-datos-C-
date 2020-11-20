#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;

};

void insertarNodo(Nodo *& , int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int);
void eliminarLista(Nodo *&, int);

int main()
{
    Nodo *lista = NULL;

    insertarNodo(lista, 30);
    insertarNodo(lista, 20);
	insertarNodo(lista, 500);
	
	mostrarLista(lista);
	cout << endl;
  	buscarLista(lista, 20);
  	cout << endl;
  	eliminarLista(lista,5);
  	cout << endl;
  	mostrarLista(lista);
    getch();
    return 0;
}

//10

void insertarNodo(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    lista = nuevo_nodo;
    nuevo_nodo->siguiente = aux1;

    while( (aux1!= NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

    cout << "Elemento\t" << n;
    cout << endl;
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual !=NULL){
		cout << actual->dato << "->";
		actual = actual->siguiente;
	}
}

void buscarLista(Nodo *lista, int n){
	Nodo *actual = new Nodo();
	actual = lista;
	bool band = false;
	
	while( (actual!=NULL) && (actual->dato<=n)){
		if(actual->dato==n){
			band = true;
		}
		actual = actual->siguiente;
	}
	
	if(band == true){
		cout << "El elemento "<<n<<"Fue encontrado";
	}else{
		cout << "El elemento "<<n<<"Fue no encontrado";
	}
}

void eliminarLista(Nodo *&Lista, int n){
	if(Lista!=NULL){
		Nodo *auxborrar;
		Nodo *anterior = NULL;
		auxborrar = Lista;
		
		while( (auxborrar!=NULL) && (auxborrar->dato!=n) ){
			anterior = auxborrar;
			auxborrar = auxborrar->siguiente;
		}
		
		if(auxborrar == NULL){
			cout << "Elementro inexistente";
		}else if(anterior == NULL){
			Lista = Lista->siguiente;
			delete auxborrar;
		}else{
			anterior->siguiente =auxborrar->siguiente;
			delete auxborrar;
		}
	}
}
