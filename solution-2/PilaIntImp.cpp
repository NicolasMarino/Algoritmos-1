#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct _cabezalPilaInt {
	int tamVector;
	int tope;
	int* vector;
};

PilaInt crearPilaInt() {
	PilaInt pilaInt = new _cabezalPilaInt();
	pilaInt->tamVector = 2;
	pilaInt->tope = -1;
	pilaInt->vector = new int[2];
	return pilaInt;
}

void expandirVector(PilaInt p) {
	int* nuevaMemoria = new int[p->tamVector * 2]();
	for (int i = 0; i < p->tamVector; i++)
	{
		nuevaMemoria[i] = p->vector[i];
	}
	delete[] p->vector;
	p->tamVector *= 2;
	p->vector = nuevaMemoria;
}

void push(PilaInt& p, int e) {
	if (p->tamVector == p->tope+1)
	{
		expandirVector(p);
	}
	p->tope++;
	p->vector[p->tope] = e;
}

int top(PilaInt p) {
	return p->vector[p->tope];
}

void pop(PilaInt& p) {
	p->tope--;
}

unsigned int cantidadElementos(PilaInt p) {
	return p->tope + 1;
}

bool esVacia(PilaInt p) {
	return p->tope == -1;
}

PilaInt clon(PilaInt p) {
	PilaInt nuevaPilaInt = new _cabezalPilaInt();
	nuevaPilaInt->vector = new int[p->tamVector]();
	for (int i = 0; i < p->tope + 1; i++)
	{
		nuevaPilaInt->vector[i] = p->vector[i];
	}
	nuevaPilaInt->tamVector = p->tamVector;
	nuevaPilaInt->tope = p->tope;
	return nuevaPilaInt;
}

void destruir(PilaInt& p) {
	delete[] p->vector;
	delete p;
}

#endif