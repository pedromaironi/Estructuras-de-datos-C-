#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;

};

void insertarNodo(Nodo *& , int);

int main()
{
    Nodo *lista = NULL;

    insertarNodo(lista, 10);
    insertarNodo(lista, 20);


    while(lista != NULL){
        cout << lista->dato;
    }
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
}
