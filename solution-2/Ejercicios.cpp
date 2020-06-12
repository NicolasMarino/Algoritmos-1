#include "Ejercicios.h"

void agregarElemALista(ListaOrdInt& l, NodoABInt* a) {
	if (a != NULL) {
		agregarElemALista(l, a->izq);
		agregar(l, a->dato);
		agregarElemALista(l, a->der);
	}
}

ListaOrdInt Enlistar(NodoABInt* a)
{
	ListaOrdInt nl = crearListaOrdInt();
	agregarElemALista(nl, a);
	return nl;
}

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	ListaOrdInt nuevaLista = crearListaOrdInt();
	while (!esVacia(l1))
	{
		agregar(nuevaLista, minimo(l1));
		borrarMinimo(l1);
	}
	while (!esVacia(l2))
	{
		agregar(nuevaLista, minimo(l2));
		borrarMinimo(l2);
	}
		
	return nuevaLista;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{
	//IMPLEMENTAR SOLUCION
	return false;
}


ListaOrdInt ObtenerRepetidos(MultisetInt m) 
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
	//IMPLEMENTAR SOLUCION
	return NULL;
}

