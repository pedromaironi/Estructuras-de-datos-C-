// ListaDoblementeEnlazada2.0.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
	Nodo* atras;
};

void insertarNodo(Nodo *&, Nodo*&);
void mostrarNodo(Nodo*, Nodo*);
void mostrarNodoU(Nodo*, Nodo*);

int main()
{
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;

	insertarNodo(primero, ultimo);
	insertarNodo(primero, ultimo);
	insertarNodo(primero, ultimo);
	insertarNodo(primero, ultimo);
	insertarNodo(primero, ultimo);
	mostrarNodo(primero, ultimo);
	mostrarNodoU(primero, ultimo);


	return 0;
}


void insertarNodo(Nodo *&primero, Nodo *&ultimo){
	Nodo* nuevo = new Nodo();
	cout << "\tDatos\n";
	cout << "Ingrese el dato:";
	cin >> nuevo->dato;

	if (primero == NULL)
	{
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}
	else {
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;

	}

	cout << endl << "Nodo insertado" << endl;

}
void mostrarNodo(Nodo* primero, Nodo* ultimo) {
	Nodo* actual = new Nodo();
	actual = primero;

	if (primero != NULL) {

		while (actual != NULL)
		{
			cout << "->" << actual->dato;
			actual = actual->siguiente;
		}
	}
	else {
		cout << endl << "Lista vacia" << endl;

	}
}
void mostrarNodoU(Nodo* primero, Nodo* ultimo) {
	Nodo* actual = new Nodo();
	cout << endl;
	actual = ultimo;
	if (primero != NULL) {

		while (actual != NULL)
		{
			cout << "->" << actual->dato;
			actual = actual->atras;
		}
	}
	else {
		cout << endl << "Lista vacia" << endl;

	}
}