#include "ListaOrdInt.h"

#ifdef LISTA_ORD_INT_IMP_2

struct _cabezalListaOrdInt {
	int cantidadElem;
	NodoABInt* arbol;
};

ListaOrdInt crearListaOrdInt() {
	ListaOrdInt nuevaLista = new _cabezalListaOrdInt();
	nuevaLista->arbol = nullptr;
	nuevaLista->cantidadElem = 0;
	return nuevaLista;
}

void agregar(ListaOrdInt& l, int e) {
	NodoABInt* aux = l->arbol;
	NodoABInt* insertar = new NodoABInt(e);
	if (l->arbol == nullptr)
	{
		l->arbol = insertar;
	}
	else
	{
		while (aux != nullptr) {
			if (aux->dato >= e) {
				if (aux->izq == nullptr) {
					aux->izq = insertar;
					aux = aux->izq;
				}
				aux = aux->izq;
			}
			else if (aux->dato < e) {
				if (aux->der == nullptr) {
					aux->der = insertar;
					aux = aux->der;
				}
				aux = aux->der;
			}
		}
	}
	l->cantidadElem++;
}

//PRE: recibe un arbol binario de búsqueda a, no vacío
//POS: Obtiene el nodo que tiene el dato mas grande del arbol
NodoABInt* obtenerMaximo(NodoABInt* A) {
	if (A->der == nullptr) {
		return A;
	}
	else {
		return obtenerMaximo(A->der);
	}
}

//PRE: recibe un arbol binario de búsqueda a, no vacío
//POS: Obtiene el nodo que tiene el dato mas chico del arbol
NodoABInt* obtenerMinimo(NodoABInt* A) {
	if (A->izq == nullptr) {
		return A;
	}
	else {
		return obtenerMinimo(A->izq);
	}
}

//PRE: recibe un arbol binario de búsqueda a, no vacío
//POS: elimina el dato que se encuentra en la raíz de a.
void borrarRaiz(NodoABInt*& A) {
	NodoABInt* borrar = A;
	if (A->der == nullptr) {
		A = A->izq;
	}
	else if (A->izq == nullptr)
	{
		A = A->der;
	}
	else
	{
		NodoABInt* aux = obtenerMaximo(A->izq);
		aux->der = A->der;
		A = A->izq;
	}
	delete borrar;
}

//PRE: -
//POS: Borra el nodo que tiene el valor e del arbol l pasado por parametro.
//	   Si no lo encuentra no tiene efecto.
void borrarAux(NodoABInt*& l, ListaOrdInt& la, int e) {
	if (l == NULL)return;
	if (l->dato == e) {
		borrarRaiz(l);
		la->cantidadElem--;
		return;
	}
	borrarAux(l->izq, la, e);
	borrarAux(l->der, la, e);
}

void borrarMinimo(ListaOrdInt& l) {
	if (l->arbol == nullptr) return;
	NodoABInt* aBorrar = obtenerMinimo(l->arbol);
	borrarAux(l->arbol, l, aBorrar->dato);
}

void borrarMaximo(ListaOrdInt& l) {
	if (l->arbol == nullptr) return;
	NodoABInt* aBorrar = obtenerMaximo(l->arbol);
	borrarAux(l->arbol , l, aBorrar->dato);
}

void borrar(ListaOrdInt& l, int e) {
	borrarAux(l->arbol,l, e);
}

int minimo(ListaOrdInt l) {
	return obtenerMinimo(l->arbol)->dato;
}

int maximo(ListaOrdInt l) {
	return obtenerMaximo(l->arbol)->dato;
}

bool existe(ListaOrdInt l, int e) {
	NodoABInt* arb = l->arbol;
	while (arb != nullptr)
	{
		if (arb->dato == e) return true;
		else if (arb->dato > e) arb = arb->izq;
		else if (arb->dato < e) arb = arb->der;
	}
	return false;
}

bool esVacia(ListaOrdInt l) {
	return l->cantidadElem == 0;
}

unsigned int cantidadElementos(ListaOrdInt l) {
	return l->cantidadElem;
}

// PRE: -
// POS: retorna una copia del arbol de ListaOrdInt sin compartir memoria
void clonarArbol(ListaOrdInt& abb, NodoABInt* raiz) {
	if (raiz == nullptr) return;
	agregar(abb, raiz->dato);
	clonarArbol(abb, raiz->izq);
	clonarArbol(abb, raiz->der);
}

ListaOrdInt clon(ListaOrdInt l) {
	ListaOrdInt nueva = new _cabezalListaOrdInt();
	clonarArbol(nueva, l->arbol);
	return nueva;
}

//TODO:
// PRE: -
// POS: libera memoria del arbol de la listaOrdInt.
void vaciarArbol(ListaOrdInt& l) {
	/*
	int aBorrar = obtenerMinimo(l->arbol)->dato;
	borrar(l, aBorrar);
	clonarArbol(l, l->arbol->izq);
	clonarArbol(l, l->arbol->der);
	*/
}

void destruir(ListaOrdInt& l) {
	//vaciarArbol(l);
	delete l->arbol;
	delete l;
}

#endif