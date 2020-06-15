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
	ListaOrdInt clonL1 = clon(l1);
	ListaOrdInt clonL2 = clon(l2);
	ListaOrdInt nuevaLista = crearListaOrdInt();
	while (!esVacia(clonL1))
	{
		agregar(nuevaLista, minimo(clonL1));
		borrarMinimo(clonL1);
	}
	while (!esVacia(clonL2))
	{
		agregar(nuevaLista, minimo(clonL2));
		borrarMinimo(clonL2);
	}
	destruir(clonL1);
	destruir(clonL2);
	return nuevaLista;
}

bool buscarEnPila(PilaInt unaPila, int dato)
{
	bool seEncuentra = false;
	PilaInt nuevaPila = crearPilaInt();
	while (!esVacia(unaPila))
	{
		if (top(unaPila) == dato) {
			seEncuentra = true;
			pop(unaPila);
			break;
		}
		push(nuevaPila, top(unaPila));
		pop(unaPila);
	}

	while (!esVacia(nuevaPila))
	{
		push(unaPila, top(nuevaPila));
		pop(nuevaPila);
	}
	destruir(nuevaPila);
	return seEncuentra;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{	
	while (!(esVacia(p1)))
	{
		if (buscarEnPila(p2, top(p1))) {
			pop(p1);
		}
		else 
		{
			return false;
		}		
	}
	return true;
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

