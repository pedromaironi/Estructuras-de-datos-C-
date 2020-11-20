// ListasDoblementeEnlazadas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;


class nodo_doble
{
public:
	int id;
	nodo_doble* sig;
	nodo_doble* ant;
protected:

};


void agregar(int);
void presentar_i();
void presentar_f();

nodo_doble* I, * F, * T;

int main(int argc) {
	
	for (int i = 0; i < 10; i++)
	{
		agregar(i);
	}
	cout << endl << "Inicio" << endl;
	presentar_i();
	cout << endl << "Final" << endl;
	presentar_f();

	return 0;
}

void agregar(int x) {
	T = new nodo_doble();
	T->id = x;
	T->sig = NULL;
	T->ant = NULL;

	//Lista vacía
	if (I == NULL) {
		I = T;

	}
	else {
		F->sig = T;
		T->ant = F;

	}
	F = T;
}

void presentar_i() {
	T = I;
	while (T != NULL)
	{
		cout << "ID:" << T->id << endl;
		T = T->sig;
	}

}

void presentar_f() {
	T = F;
	while (T!=NULL)
	{
		cout << "ID:" << T->id << endl;
		T = T->ant;
	}
}
