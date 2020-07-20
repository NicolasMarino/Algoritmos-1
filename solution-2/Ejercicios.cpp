#include "Ejercicios.h"

// PRE: -
// POS: Recorre y agrega todos los elementos del arbol a pasado como parametro en la listaOrdInt l.
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
	MultisetInt clonM1 = clon(m);
	ListaOrdInt aRetornar = crearListaOrdInt();
	while (!esVacio(clonM1)) {
		int dato = elemento(clonM1);
		borrar(clonM1, dato);
		if (!existe(aRetornar, dato) && pertenece(clonM1, dato)) {
			agregar(aRetornar, dato);
		}
	}

	return aRetornar;
}

MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
	MultisetInt clonM1 = clon(m1);
	MultisetInt clonM2 = clon(m2);
	MultisetInt aRetornar = crearMultisetInt();
	MultisetInt aBorrar = crearMultisetInt();
	aBorrar = interseccionConjuntos(clonM1, clonM2);
	while (!esVacio(aBorrar)) {
		int dato = elemento(aBorrar);
		borrar(clonM1, dato);
		borrar(clonM2, dato);
		borrar(aBorrar, dato);
	}
	while (!esVacio(clonM1))
	{
		int dato = elemento(clonM1);
		agregar(aRetornar, dato, 1);
		borrar(clonM1, dato);
	}
	while (!esVacio(clonM2))
	{
		int dato = elemento(clonM2);
		agregar(aRetornar, dato, 1);
		borrar(clonM2, dato);
	}
	destruir(clonM1);
	destruir(clonM2);
	destruir(aBorrar);
	return aRetornar;
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
	ColaPrioridadInt colaRetorno = crearColaPrioridadInt();
	if (esVacia(c)) return colaRetorno;

	ColaPrioridadInt clonCola = clon(c);
	ColaPrioridadInt clonCola2 = clon(c);
	
	int menorPrioridad = principioPrioridad(clonCola);
	while (!esVacia(clonCola))
	{
		int prioridad = principioPrioridad(clonCola); 
		if (prioridad < menorPrioridad) menorPrioridad = prioridad;
		desencolar(clonCola);
	}
	while (!esVacia(clonCola2))
	{
		int princI = principioPrioridad(clonCola2);
		if (princI == menorPrioridad) {
			encolar(colaRetorno, principio(clonCola2), menorPrioridad);
		}
		desencolar(clonCola2);
	}
	destruir(clonCola);
	destruir(clonCola2);
	return colaRetorno;
}

