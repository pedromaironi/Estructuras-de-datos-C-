// ListaCircularDoblementeEnlazada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
	Nodo* anterior;


};


void insertarNodo(Nodo*&, Nodo*&);


void mostrarNodo(Nodo*, Nodo*&);
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
		cout << "\n|      ° LISTA CIRCULAR SIMPLE °      |";
		cout << "\n|------------------|------------------|";
		cout << "\n| 1. Insertar      | 4. Eliminar      |";
		cout << "\n| 2. Buscar        | 5. Desplegar     |";
		cout << "\n| 3. Modificar     | 6. Salir         |";
		cout << "\n|------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch (opcion_menu) {
		case 1:
			cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
			for (int i = 0; i < 5; i++) {
				insertarNodo(primero, ultimo);
			}
			break;
		case 2:
			cout << "\n\n BUSCAR UN NODO EN LA LISTA \n\n";
			int n;
			cout << "Digita el numero:";
			cin >> n;
			buscarNodo(primero, n);
			break;
		case 3:
			cout << "\n\n MODIFICAR UN NODO DE LA LISTA \n\n";
			cout << "\nDigita el nodo que reemplazaras:";
			cin >> n;
			modificarNodo(primero, n);
			break;
		case 4:
			cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
			cout << "\nDigita el nodo que eliminaras:";
			cin >> n;
			eliminarNodo(primero, ultimo, n);
			break;
		case 5:
			cout << "\n\n DESPLEGAR LISTA DE NODOS \n\n";
			mostrarNodo(primero, ultimo);
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

void insertarNodo(Nodo*& primero, Nodo*& ultimo) {
	Nodo *nuevo = new Nodo();

	cout << "Ingresa el dato que contendra el nuevo nodo";
	cin >> nuevo->dato;
	if (primero == NULL) {
		primero = nuevo;
		ultimo = nuevo;
		primero->siguiente = primero;
		primero->anterior = ultimo;
	}
	else {
		ultimo->siguiente = nuevo;
		nuevo->anterior = ultimo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
		primero->anterior = ultimo; 
	}
}

void mostrarNodo(Nodo* primero, Nodo*& ultimo) {
	Nodo* actual = new Nodo();
	actual = primero;

	if (actual != NULL) {
		cout << "\n\n Lista inicial \n\n";

		do {

			cout << "<-->" << actual->dato;
			actual = actual->siguiente;
		} while (actual != primero);
	}
	else {
		cout << "La lista circular se encuentra vacia";
	}

	actual = ultimo;
	if (actual != NULL) {
		cout << "\n\n Lista inicial \n\n";

		do {

			cout << "->" << actual->dato;
			actual = actual->anterior;
		} while (actual != ultimo);
	}
	else {
		cout << "La lista circular se encuentra vacia";
	}
}

void buscarNodo(Nodo* primero, int n) {
	Nodo* actual = new Nodo();
	actual = primero;
	bool bandera = false;

	if (primero != NULL) {

		do {
			if (actual->dato == n) {
				bandera = true;
				cout << "\nEl nodo " << n << " ha sido encontrado";
			}

			actual = actual->siguiente;
		} while (actual != primero && bandera != true);
		if (!bandera) {
			cout << "\nEl nodo " << n << " no ha sido encontrado";
		}
	}
}

void modificarNodo(Nodo*& primero, int n) {
	Nodo* actual = new Nodo();
	actual = primero;
	bool bandera = false;

	if (primero != NULL) {

		do {
			if (actual->dato == n) {
				bandera = true;
				cout << "\nEl nodo " << n << " ha sido encontrado";
				cout << "\nDigita el nuevo dato";
				cin >> actual->dato;
			}

			actual = actual->siguiente;
		} while (actual != primero && bandera != true);
		if (!bandera) {
			cout << "\nEl nodo " << n << " no ha sido encontrado";
		}
	}
}

void eliminarNodo(Nodo*& primero, Nodo* ultimo, int n) 
{
	Nodo* actual = new Nodo();
	actual = primero;
	bool bandera = false;
	Nodo* anterior = new Nodo();
	anterior = NULL;
	if (primero != NULL) {

		do {
			if (actual->dato == n) {
				bandera = true;
				cout << "\nEl nodo " << n << " ha sido encontrado";
				if (actual == primero)
				{
					primero = primero->siguiente;
					primero->anterior = ultimo;
					ultimo->siguiente = primero;
				}
				else if (actual == ultimo)
				{
					ultimo = anterior;
					ultimo->siguiente = primero;
					primero->anterior = ultimo;
				} // 1 - 2 - 3 -4 -5
				else {
					// Eliminar 3 este hace que el 2 apunte al siguiente que es 3 y esto sera igual a el siguiente de 3 que es 4
					anterior->siguiente = actual->siguiente;
					// Ahora 3 siguiente 4 atras 2 --- El 3 sigue apuntando a 4 por eso 4 atras es 2
					actual->siguiente->anterior = anterior;
				}
			}

			anterior = actual;
			actual = actual->siguiente;
		} while (actual != primero && bandera != true);
		if (!bandera) {
			cout << "\nEl nodo " << n << " no ha sido encontrado";
		}
	}
}