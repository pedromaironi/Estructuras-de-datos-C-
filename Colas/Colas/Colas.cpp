// Colas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo* siguiente;

};

void insertarNodo(Nodo*&, Nodo*&,int);
void mostrarNodo(Nodo*);
void buscarNodo(Nodo*, int);
void modificarNodo(Nodo*&, int);
void eliminarNodo(Nodo*&, Nodo*, int);
int main()
{
	int opcion_menu = 0;
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;
	do
	{
		cout << "\n|-------------------------------------|";
		cout << "\n|			   °Colas°				 |";
		cout << "\n|------------------|------------------|";
		cout << "\n| 1. Insertar      | 4. Eliminar      |";
		cout << "\n| 2. Buscar        | 5. Desplegar     |";
		cout << "\n| 3. Modificar     | 6. Salir         |";
		cout << "\n|------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch (opcion_menu) {
		case 1:
			cout << "\n\n INSERTAR NODO EN LA PILA \n\n";
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
			modificarNodo(primero, n);
			break;
		case 4:
			cout << "\n\n ELIMINAR UN NODO DE LA PILA \n\n";
			cout << "Digita el numero:";
			cin >> n;
			eliminarNodo(primero, ultimo, n);
			break;
		case 5:
			cout << "\n\n DESPLEGAR PILA DE NODOS \n\n";
			mostrarNodo(primero);
			break;
		case 6:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 6);

	return 0;

}

void insertarNodo(Nodo*& primero,Nodo*& ultimo, int n) {
	Nodo* nuevo = new Nodo();
	nuevo->dato = n;


	if (primero == NULL)
	{
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = primero;

	}
	else {
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
}

void mostrarNodo(Nodo* primero) {
	Nodo* actual = new Nodo();
	actual = primero;

	if (actual != NULL) {
		while (actual != NULL){

			cout << " || " << actual->dato;
			actual = actual->siguiente;
		} 
	}
	else {
		cout << "\n\n Nodo vacio...";
	}
}

void buscarNodo(Nodo* primero, int n)
{
	Nodo* actual = new Nodo();
	actual = primero;
	bool bandera = false;

	if (actual != NULL) {

		while (actual != NULL && bandera != true){
			if (actual->dato == n) {
				cout << "La pila " << n << " ha sido encontrada";
				bandera = true;
			}
			actual = actual->siguiente;
		} 
		if (!bandera)
		{
			cout << "La pila " << n << " no existe";
		}
	}
	else {
		cout << "La PILA esa vacia";
	}
}

void modificarNodo(Nodo*& primero, int n)
{
	Nodo* actual = new Nodo();
	actual = primero;
	bool bandera = false;

	if (actual != NULL) {

		do {
			if (actual->dato == n) {
				cout << "La pila " << n << " ha sido encontrada";
				bandera = true;
				cout << "Inserte el dato que desea sustituir por " << n << " :";
				cin >> actual->dato;
			}
			actual = actual->siguiente;
		} while (actual != NULL && bandera != true);
		if (!bandera)
		{
			cout << "La cola " << n << " no existe";
		}
	}
	else {
		cout << "La COLA esa vacia";
	}
}

/*
0
-
1
-
2
-
3
-
4
*/

void eliminarNodo(Nodo*& primero, Nodo* ultimo, int n) {

	Nodo* actual = new Nodo();
	actual = primero;
	Nodo* anterior = new Nodo();
	anterior = NULL;
	bool bandera = false;

	if (actual != NULL) {

		do {
			if (actual->dato == n) {
				cout << "La pila " << n << " ha sido encontrada";
				bandera = true;
				if (actual == primero) {
					primero = primero->siguiente;
				}
				else if(actual == ultimo)
				{
					anterior->siguiente = NULL;
					ultimo = anterior;
				}
				else {

					anterior->siguiente = actual->siguiente;
				}
			}
			anterior = actual;
			actual = actual->siguiente;
		} while (actual != NULL && bandera != true);
		if (!bandera)
		{
			cout << "La COLA " << n << " no existe";
		}
	}
	else {
		cout << "La COLA esa vacia";
	}
}

