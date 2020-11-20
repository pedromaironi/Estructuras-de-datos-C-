// ListaCircularSimple.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

void insertarNodo(Nodo *&, Nodo *&);
void mostrarNodo(Nodo *);

int main()
{
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;
	insertarNodo(primero, ultimo);
	insertarNodo(primero, ultimo);
	insertarNodo(primero, ultimo);
	insertarNodo(primero, ultimo);
	insertarNodo(primero, ultimo);
	mostrarNodo(primero);
	return 0;
}

void insertarNodo(Nodo *&primero, Nodo *&ultimo) {
	Nodo* nuevo = new Nodo();
	
	cout << "Insertar dato:";
	cin >> nuevo->dato;
	if (primero == NULL) {
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;

	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}

	cout << "\nNodo ingresado" << endl << endl;
	
}

void mostrarNodo(Nodo *primero) {

	Nodo* actual = new Nodo();
	actual = primero;
	if (primero != NULL) {
		do {
			cout << "->" << actual->dato;
			actual = actual->siguiente;
		} while (actual != primero);
	}
	else {
		cout << "\nSe encuentra vacia\n\n";
	}
}