#include "ColaPrioridadInt.h"

#ifdef COLAPRIORIDAD_INT_IMP

struct _cabezalColaPrioridadInt {
	int cantElementos;
	NodoListaIntDobleDato* principio;
	NodoListaIntDobleDato* ultimo;
};

ColaPrioridadInt crearColaPrioridadInt() {
	ColaPrioridadInt nueva = new _cabezalColaPrioridadInt();
	nueva->cantElementos = 0;
	nueva->principio = nullptr;
	nueva->ultimo = nullptr;
	return nueva;
}

// PRE: -
// POS: Inserta al final de la lista.
void insertarFinal(NodoListaIntDobleDato*& listaRetorno, NodoListaIntDobleDato*& lista, NodoListaIntDobleDato*& ultimo)
{
	ultimo->sig = lista;
	ultimo = lista;
	lista = lista->sig;
}

void encolar(ColaPrioridadInt& c, int e, int p) {
	bool inserte = false;
	NodoListaIntDobleDato* insertar = new NodoListaIntDobleDato(e,p);

	if (c->principio == nullptr) {
		c->principio = insertar;
		c->ultimo = insertar;
		inserte = true;
	}
	if ( p > c->principio->dato2) {
		insertar->sig = c->principio;
		c->principio = insertar;
		inserte = true;
	}
	if (p <= c->ultimo->dato2 && inserte == false) {
		insertarFinal(c->principio, insertar, c->ultimo);
		inserte = true;
	}
	NodoListaIntDobleDato* aux = c->principio;
	while (aux != nullptr && inserte == false)
	{
		if (aux->sig != nullptr && ((p < aux->dato2 &&  p > aux->sig->dato2) || (aux->dato2 == p && aux->sig->dato2 != p))) {
			insertar->sig = aux->sig;
			aux->sig = insertar;
			inserte = true;
		}
		aux = aux->sig;
	}
	if(inserte) c->cantElementos++;
}

int principio(ColaPrioridadInt c) {
	assert(!esVacia(c));
	return c->principio->dato1;
}

int principioPrioridad(ColaPrioridadInt c) {
	assert(!esVacia(c));
	return c->principio->dato2;
}

// PRE: No es nula la lista
// POS: Borro un elemento.
void eliminarCabeza(NodoListaIntDobleDato*& lista) {
	assert(lista != nullptr);
	NodoListaIntDobleDato* aBorrar = lista;
	lista = lista->sig;
	delete aBorrar;
	aBorrar = nullptr;
}

void desencolar(ColaPrioridadInt& c) {
	assert(!esVacia(c));
	if (c->cantElementos == 1) {
		eliminarCabeza(c->principio);
		c->ultimo = nullptr;
	}
	else {
		eliminarCabeza(c->principio);
	}

	c->cantElementos--;
}

bool esVacia(ColaPrioridadInt c) {
	return c->cantElementos == 0;
}

unsigned int cantidadElementos(ColaPrioridadInt c) {
	return c->cantElementos;
}

// PRE: -
// POS: retorna una copia de la cola de prioridad sin compartir memoria
NodoListaIntDobleDato* clonar(NodoListaIntDobleDato* lista) {
	if (lista == nullptr) return nullptr;
	NodoListaIntDobleDato* aux = new NodoListaIntDobleDato();
	aux->dato1 = lista->dato1;
	aux->dato2 = lista->dato2;
	aux->sig = clonar(lista->sig);
	return aux;
}

ColaPrioridadInt clon(ColaPrioridadInt c) {
	ColaPrioridadInt nuevaPilaInt = new _cabezalColaPrioridadInt();
	nuevaPilaInt->principio = clonar(c->principio);
	nuevaPilaInt->ultimo = clonar(c->ultimo);
	nuevaPilaInt->cantElementos = c->cantElementos;
	return nuevaPilaInt;
}

// PRE: -
// POS: Libera la memoria de la lista de la cola de prioridad.
void vaciar(NodoListaIntDobleDato*& l) {
	if (l != NULL) {
		vaciar(l->sig);
		delete l;
		l = NULL;
	}
}

void destruir(ColaPrioridadInt& c) {
	vaciar(c->principio);
	delete c->principio;
	delete c;
	c = nullptr;
}

#endif