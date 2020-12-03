// Arbol binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// Arbol binario de busqueda

#include <iostream>
using namespace std;


struct Nodo {
	int dato;
	Nodo* der;
	Nodo* izq;
};

Nodo* arbol = NULL;

//Prototipos
Nodo* crearNodo(int);
void insertarNodo(Nodo*&, int);
void Menu();
void mostrarArbol(Nodo*, int);

int main()
{
	Menu();

	return 0;
}

// Funcion crear nuevo nodo;

Nodo* crearNodo(int n) {
	Nodo* nuevo = new Nodo();
	nuevo->dato = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	return nuevo;
}

// Funcion para insertar Nodo al arbol
void insertarNodo(Nodo*& arbol, int n)
{
	if (arbol == NULL)
	{
		Nodo* nuevo = crearNodo(n);
		arbol = nuevo;
	}
	else {
		int valorRaiz = arbol->dato;
		if (n < valorRaiz)
		{
			insertarNodo(arbol->izq, n);
		}
		else {
			insertarNodo(arbol->der, n);
		}
	}
}

void Menu() {
	int opcion_menu = 0;
	int contador = 0;
	int array[] = { 14,15,4,9,7,18,3,5,16,4,20,17,9,14,5 };

	do
	{
		cout << "\n|------------------------|------------------|";
		cout << "\n|1. Insertar             | 4. Suma de nodos |";
		cout << "\n|2. Mostrar              | 5. SALIR         |";
		cout << "\n|3. Confirmar eliminacion|                  |";
		cout << "\n|------------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch (opcion_menu) {
		case 1:
			int dato;
			cout << "\n\n INSERTA NODOS {14,15,4,9,7,18,3,5,16,4,20,17,9,14,5 EN EL ARBOL \n\n";
			cout << "\n\n DATO:";
			for (int i = 0; i < 15; i++) {
				insertarNodo(arbol, array[i]);
			}
			break;
		case 2:
			cout << "\n\n MOSTRAR ARBOL COMPLETO \n\n";
			mostrarArbol(arbol, contador);
			break;
		case 3:
			cout << "\n\n CONTAR HOJAS  \n\n";
			break;
		case 4:
			cout << "\n\n SUMAR LOS NODOS  \n\n";
			break;
		case 5:
			cout << "\n\n Programa finalizado...";
			opcion_menu = 6;
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 6);
}

void mostrarArbol(Nodo* arbol, int contador)
{
	if (arbol == NULL)
	{

		return;
	}
	else {
		mostrarArbol(arbol->der, contador + 1);
		for (int i = 0; i < contador; i++)
		{
			cout << "     ";
		}
		cout << arbol->dato << endl;
		mostrarArbol(arbol->izq, contador + 1);
	}
}
