#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct _nodoPilaInt {
	int dato;
	_nodoPilaInt* sig;
};

struct _cabezalPilaInt {
	_nodoPilaInt* tope;
	unsigned int cantidad;
};

PilaInt crearPilaInt(){
	PilaInt retorno = new _cabezalPilaInt();
	retorno->cantidad = 0;
	retorno->tope = nullptr;
	return retorno;
}

void push(PilaInt& p, int e) {
	_nodoPilaInt* nuevoNodo = new _nodoPilaInt();
	nuevoNodo->dato = e;
	nuevoNodo->sig = p->tope;
	p->tope = nuevoNodo;
	p->cantidad++;
}

int top(PilaInt p) {
	return p->tope->dato;
}

void pop(PilaInt& p) {
	_nodoPilaInt* borrar = p->tope;
	p->tope = p->tope->sig;
	delete borrar;
}

unsigned int cantidadElementos(PilaInt p) {
	return p->cantidad;
}

bool esVacia(PilaInt p) {
	return p->tope == nullptr;
}

PilaInt clon(PilaInt p) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(PilaInt& p) {
	// NO IMPLEMENTADO
}


#endif