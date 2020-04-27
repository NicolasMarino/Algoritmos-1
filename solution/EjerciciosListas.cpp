#include "EjerciciosListas.h"

//Auxiliar
NodoLista* copiarLista(NodoLista* unaLista)
{
	if (unaLista == nullptr) return nullptr;
	return crearNodoLista(unaLista->dato, copiarLista(unaLista->sig));
}

// DONE
NodoLista* invertirParcial(NodoLista* l)
{
	if (l != nullptr) {
		NodoLista* nuevaListaParcial = nullptr;

		while (l != nullptr) {

			if (l->sig == nullptr) return nuevaListaParcial;

			NodoLista* nuevoNodo = new NodoLista(l->dato);

			if (nuevaListaParcial == nullptr)
			{
				nuevoNodo->sig = nullptr;
			}
			else
			{
				nuevoNodo->sig = nuevaListaParcial;
			}

			nuevaListaParcial = nuevoNodo;
			l = l->sig;
		}

		return nuevaListaParcial;

	}
	else {
		return nullptr;
	}
}

//Obligatorio - DONE
void eliminarNesimoDesdeElFinal(NodoLista*& lista, int& n)
{
	if (lista != nullptr)
	{
		eliminarNesimoDesdeElFinal(lista->sig, n);
		n--;
		if (n == 0)
		{
			NodoLista* aux = lista;
			lista = lista->sig;
			delete aux;
		}
	}
}

//NodoLista* nuevaLista = copiarLista(l);
NodoLista* crearNodoLista(int dato, NodoLista* siguiente)
{
	NodoLista* nuevoNL = new NodoLista();
	nuevoNL->dato = dato;
	nuevoNL->sig = siguiente;
	return nuevoNL;
}

//Oligatorio - DONE
NodoLista* listaOrdenadaInsertionSort(NodoLista* l)
{
	if (l == nullptr) return nullptr;
	return insertionSort(l->dato, listaOrdenadaInsertionSort(l->sig));
}

//Auxiliar
NodoLista* insertionSort(int dato, NodoLista* siguienteNodo)
{
	if (siguienteNodo == nullptr || dato <= siguienteNodo->dato)
	{
		return crearNodoLista(dato, siguienteNodo);
	}
	else {
		siguienteNodo->sig = insertionSort(dato, siguienteNodo->sig);
		return siguienteNodo;
	}
}

//Obligatorio - DONE
void listaOrdenadaSelectionSort(NodoLista*& l)
{
	if (l != nullptr) {
		NodoLista* menor = l;
		NodoLista* aux = l;

		while (aux != NULL) {
			if (aux->dato < menor->dato) {
				menor = aux;
			}
			aux = aux->sig;
		}

		int datoAux = l->dato;
		l->dato = menor->dato;
		menor->dato = datoAux;

		listaOrdenadaSelectionSort(l->sig);
	}
}

//Obligatorio - TODO

void intercalarIterAux(NodoLista*& listaRetorno, NodoLista*& lista,NodoLista*& ultimo)
{
	NodoLista* aux = nullptr;
	if (listaRetorno == nullptr) {
		listaRetorno = new NodoLista();
		listaRetorno->dato = lista->dato;
		listaRetorno->sig = nullptr;
		ultimo = listaRetorno;
	}
	else
	{
		aux = new NodoLista();
		aux->dato = lista->dato;
		aux->sig = nullptr;
		ultimo->sig = aux;
		ultimo = aux;
	}
	lista = lista->sig;
}


NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	if (l1 == nullptr && l2 == nullptr) return nullptr;
	NodoLista* listaRetorno = nullptr;
	NodoLista* ultimo = nullptr;

	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->dato <= l2->dato)
		{
			intercalarIterAux(listaRetorno, l1, ultimo);
		}
		else
		{
			intercalarIterAux(listaRetorno, l2, ultimo);
		}
	}

	if (l1 == nullptr) 
	{
		intercalarIterAux(listaRetorno, l2, ultimo);
		while (l2 != nullptr)
		{
			intercalarIterAux(listaRetorno, l2, ultimo);
		}

		return listaRetorno;
	}
	if (l2 == nullptr) {
		intercalarIterAux(listaRetorno, l1, ultimo);
		while (l1 != nullptr)
		{
			intercalarIterAux(listaRetorno, l1, ultimo);
		}

		return listaRetorno;
	}
}

//Obligatorio - TODO
NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	//if (l1 == nullptr) return intercalarRec()
	return NULL;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

//Obligatorio - TODO
NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

//Obligatorio - TODO
void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l)
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

//Obligatorio - TODO
void eliminarSecuencia(NodoLista*& l, NodoLista* secuencia)
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista*& lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
