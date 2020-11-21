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

void insertarNodo(Nodo *&, Nodo*&, int);
void mostrarNodo(Nodo*, Nodo*);
void mostrarNodoU(Nodo*, Nodo*);
void buscarNodo(Nodo*, int);
void eliminarNodo(Nodo*&, Nodo*&, int);

int main()
{
	int opcion_menu = 0;
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;
	do
	{
		cout << "\n|-------------------------------------|";
		cout << "\n|      ° Lista doble °                |";
		cout << "\n|------------------|------------------|";
		cout << "\n| 1. Insertar      | 4. Eliminar      |";
		cout << "\n| 2. Buscar        | 5. Desplegar     |";
		cout << "\n| 3. Modificar     | 6. Salir         |";
		cout << "\n|------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch (opcion_menu) {
		case 1:
			cout << "\n\n INSERTA NODO EN LA PILA \n\n";
			for (int i = 0; i < 5; i++) {
				insertarNodo(primero,ultimo, i);
			}
			cout << "\n\nNodos insertados\n\n";
			break;
		case 2:
			cout << "\n\n BUSCAR UN NODO EN LA PILA \n\n";
			int n;
			cout << "Digita el numero:";
			cin >> n;
			buscarNodo(primero, n);
			break;
		case 3:
			cout << "\n\n MODIFICAR UN NODO DE LA PILA \n\n";
			cout << "Digita el numero:";
			cin >> n;
			//modificarNodo(primero, n);
			break;
		case 4:
			cout << "\n\n ELIMINAR UN NODO DE LA PILA \n\n";
			cout << "Digita el numero:";
			cin >> n;
			eliminarNodo(primero, ultimo, n);
			break;
		case 5:
			cout << "\n\n DESPLEGAR PILA DE NODOS \n\n";
			mostrarNodo(primero,ultimo);
			mostrarNodoU(primero,ultimo);
			break;
		case 6:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 6);

	return 0;

	return 0;
}


void insertarNodo(Nodo *&primero, Nodo *&ultimo, int n){
	Nodo* nuevo = new Nodo();
	nuevo->dato = n;

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
			cout << "<->" << actual->dato;
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
			cout << "<->" << actual->dato;
			actual = actual->atras;
		}
	}
	else {
		cout << endl << "Lista vacia" << endl;

	}
}

void buscarNodo(Nodo* primero, int n)
{
	Nodo* actual = new Nodo();
	actual = primero;
	bool bandera = false;

	if (actual != NULL) {

		while (actual != NULL && bandera != true) {
			if (actual->dato == n) {
				cout << "El nodo " << n << " ha sido encontrada";
				bandera = true;
			}
			actual = actual->siguiente;
		}
		if (!bandera)
		{
			cout << "La lista" << n << " no existe";
		}
	}
	else {
		cout << "La lista esa vacia";
	}
}

void eliminarNodo(Nodo*& primero, Nodo*& ultimo, int n) {
	Nodo* actual = new Nodo();
	actual = primero;
	Nodo* anterior = new Nodo();
	anterior = NULL;

	bool bandera = false;

	if (actual != NULL) {

		while (actual != NULL && bandera != true) {
			if (actual->dato == n) {
				cout << "El nodo " << n << " ha sido encontrada";
				bandera = true;
				if (actual == primero)
				{
					primero = primero->siguiente;
					primero->atras = NULL;
				}
				else if (actual == ultimo)
				{
					anterior->siguiente = NULL;
					ultimo = anterior;
				}
				else {
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if (!bandera)
		{
			cout << "El nodo" << n << " no existe";
		}
	}
	else {
		cout << "La lista esa vacia";
	}
}