// Arbol binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// Arbol binario debusqueda

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
bool busqueda(Nodo*, int);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
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
	bool band = false;
	do
	{
		cout << "\n|------------------------|------------------|";
		cout << "\n|1. Insertar             | 4. PostOrden	   |";
		cout << "\n|2. Mostrar              | 5. InOrden       |";
		cout << "\n|3. Buscar               | 6. preOrden      |";
		cout << "\n|7. Salir                | 6. Orden         |";
		cout << "\n|------------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch (opcion_menu) {
		case 1:
			int dato;
			cout << "\n\n INSERTA NODO EN EL ARBOL \n\n";
			cout << "\n\n DATO:";
			cin >> dato;
			insertarNodo(arbol, dato);
			break;
		case 2:
			cout << "\n\n MOSTRAR ARBOL COMPLETO \n\n";
			mostrarArbol(arbol, contador);
			break;
		case 3:
			cout << "\n\n BUSQUEDA DE NODO EN EL ARBOL  \n\n";
			cout << "\n\n Digita el elemento a buscar:"; cin >> dato;
			
			band = busqueda(arbol, dato);
			if (band) {
				cout << "\n\n El elemento:" << dato << " ha sido encontrado\n\n";
			}
			else {
				cout << "\n\n El elemento:" << dato << " no ha sido encontrado\n\n";
			}
			break;
		case 4:
			cout << "\n\n SUMAR LOS NODOS  \n\n";
			break;
		case 7:
			cout << "\n\n Programa finalizado...";
			opcion_menu = 7;
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 7);
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

bool busqueda(Nodo* arbol, int n) {
	if (arbol == NULL)
	{
		return false;
	}
	else if (arbol->dato == n)
	{
		return true;
	}
	else if (n < arbol->dato)
	{
		return busqueda(arbol->izq, n);
	}
	else {
		return busqueda(arbol->der, n);
	}

}

void preOrden(Nodo* arbol)
{
	if (arbol == NULL) {
		return;
	}
	else {
		cout << arbol->dato << "-";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inorden(Nodo* arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		inorden(arbol->izq);
		cout << arbol->dato << " - ";
		inorden(arbol->der);
	}
}

void postOrden(Nodo* arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout << arbol->dato << " - ";
	}
}
