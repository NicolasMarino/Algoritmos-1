#include "ColaInt.h"

#ifdef COLA_INT_IMP

struct NodoColaInt {
	int dato;
	NodoColaInt* sig;
};

struct _cabezalColaInt {
	int cantidadPresentes;
	NodoColaInt* primero;
	NodoColaInt* ultimo;
};

ColaInt crearColaInt() {
	ColaInt nuevaC = new _cabezalColaInt();
	nuevaC->cantidadPresentes = -1;
	nuevaC->primero = nullptr;
	nuevaC->ultimo = nullptr;
	return nuevaC;
};

// PRE: -
// POS: Inserta al final de la lista, actualizo el ultimo nodo.
void insertarYQuedarmeUltimoNodo(NodoColaInt*& listaRetorno, NodoColaInt*& lista, NodoColaInt*& ultimo)
{
	if (listaRetorno == nullptr) {
		listaRetorno = new NodoColaInt();
		listaRetorno->dato = lista->dato;
		listaRetorno->sig = nullptr;
		ultimo = listaRetorno;
	}
	else
	{
		NodoColaInt* aux = new NodoColaInt();
		aux->dato = lista->dato;
		aux->sig = nullptr;
		ultimo->sig = aux;
		ultimo = aux;
	}
	lista = lista->sig;
}

void encolar(ColaInt& c, int e) {
	NodoColaInt* nuevoNodo = new NodoColaInt();
	nuevoNodo->dato = e;
	nuevoNodo->sig = nullptr;
	insertarYQuedarmeUltimoNodo(c->primero, nuevoNodo, c->ultimo);
	c->cantidadPresentes++;
}

int principio(ColaInt c) {
	assert(!esVacia(c));
	return c->primero->dato;
}

void desencolar(ColaInt& c) {
	NodoColaInt* aBorrar = c->primero;
	c->primero = c->primero->sig;
	delete aBorrar;
	c->cantidadPresentes--;
	if (c->cantidadPresentes == -1) c->ultimo = nullptr;
}

bool esVacia(ColaInt c) {
	return c->cantidadPresentes == -1;
}

unsigned int cantidadElementos(ColaInt c) {
	return c->cantidadPresentes + 1;
}

// PRE: -
// POS: Libera la memoria de la lista pasada por parámetro.
void vaciar(NodoColaInt*& l) {
	if (l != NULL) {
		vaciar(l->sig);
		delete l;
		l = NULL;
	}
}
 
ColaInt clon(ColaInt c) {
	ColaInt colaClon = new _cabezalColaInt();
	colaClon->cantidadPresentes = c->cantidadPresentes;

	NodoColaInt* listaRetorno = nullptr;
	NodoColaInt* ultimo = nullptr;
	NodoColaInt* aux = c->primero;
	while (aux != nullptr)
	{
		insertarYQuedarmeUltimoNodo(listaRetorno, aux, ultimo);
	}
	vaciar(aux);
	colaClon->primero = listaRetorno;
	colaClon->ultimo = ultimo;
	
	return colaClon;
}

void destruir(ColaInt& c) {
	vaciar(c->primero);
	c->ultimo = nullptr;
	delete c;
	c = nullptr;
}

#endif