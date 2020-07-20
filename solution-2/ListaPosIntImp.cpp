#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct _cabezalListaPosInt {
	int tamVector;
	int tope;
	int* vector;
};

ListaPosInt crearListaPosInt()
{
	ListaPosInt lista = new _cabezalListaPosInt();
	lista->tamVector = 10;
	lista->tope = -1;
	lista->vector = new int [10];
	return lista;
}

// PRE: - 
// POS: Expande al doble el tamaño del vector dentro de p.
//		Copia todos los datos a nueva memoria.
void expandirVector(ListaPosInt p) {
	int* nuevaMemoria = new int [p->tamVector * 2]();
	for (int i = 0; i < p->tope + 1 ; i++)
	{
		nuevaMemoria[i] = p->vector[i];
	}
	delete[] p->vector;
	p->tamVector *= 2;
	p->vector = nuevaMemoria;
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	if (l->tope == l->tamVector) {
		expandirVector(l);
	}
	if (pos > l->tope)
	{
		l->tope++;
		l->vector[l->tope] = e;
	}
	else
	{
		for (int i = l->tope; i +1 > pos; i--) {
			l->vector[i + 1] = l->vector[i];
		}
		l->vector[pos] = e;
		l->tope++;
	}
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	if (pos >= l->tope+1) return;
	for (int i = pos; i < l->tope; i++) {
		l->vector[i] = l->vector[i + 1];
	}
	l->tope--;
}

int elemento(ListaPosInt l, unsigned int pos)
{
	return l->vector[pos];
}

bool esVacia(ListaPosInt l)
{
	return l->tope == -1;
}

unsigned int cantidadElementos(ListaPosInt l)
{
	return l->tope+1;
}

ListaPosInt clon(ListaPosInt l)
{
	ListaPosInt nuevaListaPosInt = new _cabezalListaPosInt();
	nuevaListaPosInt->vector = new int[l->tamVector]();
	for (int i = 0; i < l->tope + 1 ; i++)
	{
		nuevaListaPosInt->vector[i] = l->vector[i];
	}
	nuevaListaPosInt->tamVector = l->tamVector;
	nuevaListaPosInt->tope = l->tope;
	return nuevaListaPosInt;
}

void destruir(ListaPosInt& l)
{
	delete[] l->vector;
	delete l;
	l = nullptr;
}


#endif