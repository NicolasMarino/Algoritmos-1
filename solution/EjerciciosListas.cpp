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
/*
 *	EJERCICIO OBLIGATORIO
PRE: Recibe dos listas simplemente encadenadas, ambas ordenadas en orden creciente
POS: Retorna una nueva lista con todos los elementos de l1 y l2,
	 incluyendo repetidos, ordenados en orden creciente.
	 La lista retornada no puede compartir memoria con las listas
	 recibidas, y estas no pueden ser modificadas.
	 La funcion no debe recorrer l1 o l2 mas de una vez,
	 y la lista resultado no debera recorrerse
	 El ejercicio se deberá resolver de forma iterativa.

Ejemplo
Entrada: (((1,3,5,7,9,9), (2,2,4,6,8))
Salida: (1,2,2,3,4,5,6,7,8,9,9)
*/
NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	if (l1 == nullptr && l2 == nullptr) return nullptr;
	NodoLista* listaRetorno = nullptr;
	NodoLista* ultimo = nullptr;
	NodoLista* aux = nullptr ;
	bool estaVacio = true;

	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->dato <= l2->dato)
		{
			if (estaVacio) {
				listaRetorno = new NodoLista();
				listaRetorno->dato = l1->dato;
				listaRetorno->sig = nullptr;
				ultimo = listaRetorno;
				estaVacio = false;
			}
			else
			{
				aux = new NodoLista();
				aux->dato = l1->dato;
				aux->sig = nullptr;
				ultimo->sig = aux;
				ultimo = aux;
			}
			l1 = l1->sig;
		}
		else
		{
			if (estaVacio) {
				listaRetorno = new NodoLista();
				listaRetorno->dato = l2->dato;
				listaRetorno->sig = nullptr;
				ultimo = listaRetorno;
				estaVacio = false;
			}
			else
			{

				aux = new NodoLista();
				aux->dato = l2->dato;
				aux->sig = nullptr;
				ultimo->sig = aux;
				ultimo = aux;
			}

			l2 = l2->sig;
		}
	}

	if (l1 == nullptr) 
	{
		if (listaRetorno != nullptr)
		{
			aux = new NodoLista();
			aux->dato = l2->dato;
			aux->sig = nullptr;
			ultimo->sig = aux;
			ultimo = aux;
		}
		else
		{
			listaRetorno = new NodoLista();
			listaRetorno->dato = l2->dato;
			listaRetorno->sig = nullptr;
			ultimo = listaRetorno;
		}
			
		l2 = l2->sig;
		while (l2 != nullptr)
		{
			if (listaRetorno != nullptr) {
				aux = new NodoLista();
				aux->dato = l2->dato;
				aux->sig = nullptr;
				ultimo->sig = aux;
				ultimo = aux;
			}
			l2 = l2->sig;
		}

		return listaRetorno;
	}
	if (l2 == nullptr) {
		if (listaRetorno != nullptr) {
			aux = new NodoLista();
			aux->dato = l1->dato;
			aux->sig = nullptr;
			ultimo->sig = aux;
			ultimo = aux;
		}
		else
		{
			listaRetorno = new NodoLista();
			listaRetorno->dato = l1->dato;
			listaRetorno->sig = nullptr;
			ultimo = listaRetorno;
		}
		
		l1 = l1->sig;
		while (l1 != nullptr)
		{
			if (listaRetorno != nullptr)
			{
				aux = new NodoLista();
				aux->dato = l1->dato;
				aux->sig = nullptr;
				ultimo->sig = aux;
				ultimo = aux;
			}
			l1 = l1->sig;
		}

		return listaRetorno;
	}
}

//Obligatorio - TODO
NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
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
