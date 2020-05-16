#include "EjerciciosListas.h"

//Done
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

//Auxiliar
NodoLista* crearNodoLista(int dato, NodoLista* siguiente)
{
	NodoLista* nuevoNL = new NodoLista();
	nuevoNL->dato = dato;
	nuevoNL->sig = siguiente;
	return nuevoNL;
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

//Oligatorio - DONE
NodoLista* listaOrdenadaInsertionSort(NodoLista* l)
{
	if (l == nullptr) return nullptr;
	return insertionSort(l->dato, listaOrdenadaInsertionSort(l->sig));
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

//Auxiliar
void intercalarIterAux(NodoLista*& listaRetorno, NodoLista*& lista, NodoLista*& ultimo)
{
	if (listaRetorno == nullptr) {
		listaRetorno = new NodoLista();
		listaRetorno->dato = lista->dato;
		listaRetorno->sig = nullptr;
		ultimo = listaRetorno;
	}
	else
	{
		NodoLista* aux = new NodoLista();
		aux->dato = lista->dato;
		aux->sig = nullptr;
		ultimo->sig = aux;
		ultimo = aux;
	}
	lista = lista->sig;
}

//Obligatorio - DONE
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

//Obligatorio - DONE
NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	if (l1 == nullptr && l2 == nullptr) return nullptr;
	NodoLista* aux = new NodoLista();
	if (l1 != nullptr)
	{
		if (l2 == nullptr || l1->dato <= l2->dato)
		{
			aux->dato = l1->dato;
			aux->sig = intercalarRec(l1->sig, l2);
		}
	}
	if (l2 != nullptr)
	{
		if (l1 == nullptr || l1->dato >= l2->dato)
		{
			aux->dato = l2->dato;
			aux->sig = intercalarRec(l1, l2->sig);
		}
	}
	return aux;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

//Obligatorio - DONE
NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	if (l1 == nullptr && l2 == nullptr) return nullptr;
	NodoLista* listaRetorno = nullptr;
	NodoLista* ultimo = nullptr;
	while (l1 != nullptr && l2 != nullptr)
	{
		int datoUnoAux = l1->dato;
		while (l1->sig != nullptr && l1->sig->dato == datoUnoAux)
		{
			l1 = l1->sig;
		}
		int datoDosAux = l2->dato;
		while (l2->sig != nullptr && l2->sig->dato == datoDosAux)
		{
			l2 = l2->sig;
		}
		if (l1->dato == l2->dato) {
			l1 = l1->sig;
			l2 = l2->sig;
		}
		else if (l1->dato < l2->dato) {
			intercalarIterAux(listaRetorno, l1, ultimo);
		}
		else if (l1->dato > l2->dato) {
			intercalarIterAux(listaRetorno, l2, ultimo);
		}

	}

	if (l1 != nullptr)
	{
		while (l1 != nullptr)
		{
			int datoAuxUno = l1->dato;
			while (l1->sig != nullptr && l1->sig->dato == datoAuxUno)
			{
				l1 = l1->sig;
			}
			intercalarIterAux(listaRetorno, l1, ultimo);
		}
	}

	if (l2 != nullptr)
	{
		while (l2 != nullptr)
		{
			int datoAuxDos = l2->dato;
			while (l2->sig != nullptr && l2->sig->dato == datoAuxDos)
			{
				l2 = l2->sig;
			}
			intercalarIterAux(listaRetorno, l2, ultimo);
		}
	}

	return listaRetorno;
}

//Auxiliar
void eliminarCabeza(NodoLista*& nodo) {
	if (nodo != nullptr) {
		NodoLista* aux = nodo;
		nodo = nodo->sig;
		delete aux;
	}
}

//Obligatorio - DONE
void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l)
{
	if (l != nullptr) {
		if (l->sig != nullptr) {
			if (l->dato == l->sig->dato) {
				int datoAux = l->dato;
				while (l != nullptr && l->dato == datoAux)
				{
					eliminarCabeza(l);
				}
				eliminarDuplicadosListaOrdenadaDos(l);
			}
			else {
				eliminarDuplicadosListaOrdenadaDos(l->sig);
			}
		}
	}
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

//Auxiliar
bool secuenciaEmbebida(NodoLista* l, NodoLista* secuencia) {
	if (l == nullptr && secuencia == nullptr) return true;
	if (l == nullptr) return false;
	if (secuencia == nullptr) return true;
	if (l != nullptr && secuencia != nullptr)
		if (l->dato == secuencia->dato)
			secuenciaEmbebida(l->sig, secuencia->sig);
		else
			return false;
}

//Obligatorio - DONE
void eliminarSecuencia(NodoLista*& l, NodoLista* secuencia)
{
	if (l == nullptr || secuencia == nullptr) return;
	NodoLista* nodoListaAux = l;

	if (l != nullptr)
	{
		if (secuencia != nullptr && l->dato == secuencia->dato) {
			if (secuenciaEmbebida(l, secuencia)) {
				NodoLista* recorroSecuencia = secuencia;
				while (recorroSecuencia != nullptr)
				{
					eliminarCabeza(l);
					recorroSecuencia = recorroSecuencia->sig;
				}
			}
			else {
				eliminarSecuencia(l->sig, secuencia);
			}
		}
		else {
			eliminarSecuencia(l->sig, secuencia);
		}
	}
}

void moverNodo(NodoLista*& lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
