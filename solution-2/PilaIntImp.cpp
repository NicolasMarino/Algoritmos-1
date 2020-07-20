#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct _cabezalPilaInt {
	unsigned int cantElementos;
	NodoListaInt* pila;
};

PilaInt crearPilaInt() {
	PilaInt pilaInt = new _cabezalPilaInt();
	pilaInt->pila = new NodoListaInt();
	return pilaInt;
}

void push(PilaInt& p, int e) {
	NodoListaInt* nuevoElem = new NodoListaInt(e);
	p->cantElementos++;
	nuevoElem->sig = p->pila;
	p->pila = nuevoElem;
}

int top(PilaInt p) {
	return p->pila->dato;
}

void pop(PilaInt& p) {
	NodoListaInt* aux = p->pila;
	p->pila = p->pila->sig;
	delete aux;
	p->cantElementos--;
}

unsigned int cantidadElementos(PilaInt p) {
	return p->cantElementos;
}

bool esVacia(PilaInt p) {
	return p->cantElementos == 0;
}

// PRE: -
// POS: retorna una copia de la pila sin compartir memoria.
NodoListaInt* clonar(NodoListaInt* pila) {
	if (pila == nullptr) return nullptr;
	NodoListaInt* aux = new NodoListaInt();
	aux->dato = pila->dato;
	aux->sig = clonar(pila->sig);
	return aux;
}

PilaInt clon(PilaInt p) {
	PilaInt nuevaPilaInt = new _cabezalPilaInt();
	nuevaPilaInt->pila = clonar(p->pila);
	nuevaPilaInt->cantElementos = p->cantElementos;
	return nuevaPilaInt;
}

// PRE: -
// POS: Libera la memoria de la lista pasada por parámetro.
void vaciar(NodoListaInt*& l) {
	if (l != NULL) {
		vaciar(l->sig);
		delete l;
		l = NULL;
	}
}

void destruir(PilaInt& p) {
	vaciar(p->pila);
	delete p->pila;
	delete p;
	p = nullptr;
}

#endif