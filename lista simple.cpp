#include <iostream>

using namespace std;
/*
Una lista enlazada contiene los siguientes números: 4,3,5,7. 
Desarrollar un Programa  en C++ que devuelva la la suma de de los nodos y permita eliminar el seguno nodo. 
El programa debe tener un menú que indique las operaciones a realizar.

Posible salida:

Lista de elementos:  4,3,5,7

Suma de los nodos: 19

Lista con nodo eliminado : 4,5,7

*/

struct nodo{
	int dato;
	nodo* siguiente;
} *primero, *ultimo;

void insertarNodo(int);
void SumarNodos();
void EliminacionNodo();

void desplegarLista();

int main(){
	
	int opcion_menu = 0;
	
	do
	{
		cout << "\n|------------------------|------------------|";
		cout << "\n|1. Insertar             | 4. Suma de nodos |";
		cout << "\n|2. Mostrar              | 5. SALIR         |";
		cout << "\n|3.Confirmar eliminacion |                  |";
		cout << "\n|------------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu){
		case 1:
			int dato;
			cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
			cout << "\n\n INSERTANDO LOS NUMEROS 4 - 3 - 5 - 7\n\n";
					
			insertarNodo(4);
			insertarNodo(3);
			insertarNodo(5);
			insertarNodo(7);
		break;
		case 2:
			cout << "\n\n MOSTRAR LISTA \n\n";
			desplegarLista();
			
			break;
		case 3:
			cout << "\n\n ELIMINACION DE NODO  \n\n";
			EliminacionNodo();
			break;
		case 4:
			cout << "\n\n SUMAR LOS NODOS  \n\n";
			SumarNodos();
			break;
		case 5:
			cout << "\n\n Programa finalizado...";
			opcion_menu = 6;
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 6);
	
	
	return 0;
}

void insertarNodo(int dato){
	nodo* nuevo = new nodo();
	nuevo->dato = dato;
	
		
	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	cout << "\n Nodo Ingresado\n\n";
}      

void SumarNodos(){
	nodo* actual = new nodo();
	actual = primero;
	int suma = 0;
	
	if(primero != NULL){
		while(actual != NULL){
			suma += actual->dato;	
			actual = actual->siguiente;
		}
		cout << "\n La suma de los nodos es:" << suma << endl << endl;
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

void EliminacionNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a Buscar para Eliminar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		
		while(actual != NULL && encontrado != true){
			
			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado\n\n";
				
				if(actual == primero){
					primero = primero->siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				
				cout << "\n Nodo ELiminado con exito\n\n";
				
				encontrado = true;
			}
			
			anterior = actual;
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

void desplegarLista(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero != NULL){
		
		while(actual != NULL){
			cout << " " << actual->dato  << endl;
			actual = actual->siguiente;
		}
		
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}
