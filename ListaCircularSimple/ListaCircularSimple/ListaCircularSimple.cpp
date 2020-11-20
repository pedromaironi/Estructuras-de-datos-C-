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
void buscarNodo(Nodo*, int);
void modificarNodo(Nodo*&, int );

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
			cout << "Digita el numero:";
			cin >> n;
			modificarNodo(primero, n);
			break;
		case 4:
			cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
			break;
		case 5:
			cout << "\n\n DESPLEGAR LISTA DE NODOS \n\n";
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

void buscarNodo(Nodo* primero, int n) {
	Nodo* actual = new Nodo();
	actual = primero;
	bool bandera = false;
	if (primero != NULL) {


		do {
			if (actual->dato == n) {
				bandera = true;
			}
			else {
				bandera = false;
			}

			actual = actual->siguiente;
		} while (actual != primero && bandera != true);
		if (bandera == true) {
			cout << "\n El nodo con el dato " << n << " ha sido encontrado\n\n";
		}
		else {
			cout << "\n El nodo con el dato " << n << " no ha sido encontrado\n\n";
		}
	}
	else {
		cout << "\nSe encuentra vacia\n\n";
	}

}

void modificarNodo(Nodo*& primero, int n) {
	Nodo* actual = new Nodo();
	actual = primero;
	bool bandera = false;
	if (primero != NULL) {
		do {
			if (actual->dato == n) {
				cout << "\n El nodo con el dato " << n << " ha sido encontrado\n\n";
				cout << "\n Ingrese el dato que sustituira el nodo:";
				cin >> actual->dato;
				cout << "\n Nodo modificado";
				bandera = true;
			}
			else {
				bandera = false;
			}

			actual = actual->siguiente;
		} while (actual != primero && bandera != true);
		if (bandera != true) {
			cout << "\n El nodo con el dato " << n << " no ha sido encontrado\n\n";
		}
	}
	else {
		cout << "\nSe encuentra vacia\n\n";
	}
}