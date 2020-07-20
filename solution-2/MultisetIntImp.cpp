#include "MultisetInt.h"

#ifdef MULTISET_INT_IMP

struct _cabezalMultisetInt {
	int cantElementos;
	NodoListaInt* multiLista;
};

MultisetInt crearMultisetInt() {
	MultisetInt multiset = new _cabezalMultisetInt();
	multiset->multiLista = nullptr;
	return multiset;
}

void agregar(MultisetInt& s, int e, unsigned int ocurrencias) {
	while (ocurrencias != 0)
	{
		NodoListaInt* nuevo2 = new NodoListaInt(e);
		nuevo2->sig = s->multiLista;
		s->multiLista = nuevo2;
		s->cantElementos++;
		ocurrencias--;
	}
}

void borrar(MultisetInt& s, int e) {

	while (s->multiLista != nullptr && s->multiLista->dato == e)
	{
		NodoListaInt* aBorrar = s->multiLista;
		s->multiLista = s->multiLista->sig;
		delete aBorrar;
		s->cantElementos--;
		return;
	}
	NodoListaInt* aRecorrer = s->multiLista;

	while (aRecorrer != nullptr)
	{
		if (aRecorrer->sig != nullptr && aRecorrer->sig->dato == e) {
			NodoListaInt* aBorrar = aRecorrer->sig;
			aRecorrer->sig = aRecorrer->sig->sig;
			delete aBorrar;
			s->cantElementos--;
			break;
		}

		aRecorrer = aRecorrer->sig;
	}
}

bool pertenece(MultisetInt s, int e) {
	NodoListaInt* aRecorrer = s->multiLista;
	while (aRecorrer != nullptr) {
		if (aRecorrer->dato == e) {
			return true;
		}
		aRecorrer = aRecorrer->sig;
	}
	return false;
}

// PRE: -
// POS: Ordena la lista utilizando selection sort.
void listaOrdenadaSelectionSort(NodoListaInt*& l)
{
	if (l != nullptr) {
		NodoListaInt* menor = l;
		NodoListaInt* aux = l;

		while (aux != NULL) {
			if (aux->dato < menor->dato) {
				menor = aux;
			}
			aux = aux->sig;
		}

		int datoAux1 = l->dato;
		l->dato = menor->dato;
		menor->dato = datoAux1;

		listaOrdenadaSelectionSort(l->sig);
	}
}

// PRE: -
// POS: Retorna el menor de los dos numeros.
int obtenerMenor(int uno, int dos) {
	if (uno < dos) {
		return uno;
	}
	else {
		return dos;
	}
}

// PRE: -
// POS: Retorna el mayor de los dos numeros.
int obtenerMayor(int uno, int dos) {
	if (uno > dos) {
		return uno;
	}
	else {
		return dos;
	}
}

// PRE: -
// POS: Retorna las ocurrencias de e en el multiset.
int obtenerOcurrencias(MultisetInt s, int e) {
	NodoListaInt* aRecorrer = s->multiLista;
	int contador = 0;
	while (aRecorrer != nullptr) {
		if (aRecorrer->dato == e) {
			contador++;
		}
		aRecorrer = aRecorrer->sig;
	}
	return contador;
}

MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt recorrerS1 = clon(s1);
	listaOrdenadaSelectionSort(recorrerS1->multiLista);
	MultisetInt recorrerS2 = clon(s2);
	listaOrdenadaSelectionSort(recorrerS2->multiLista);
	MultisetInt aRetornar = crearMultisetInt();
	while (recorrerS1->multiLista != nullptr && recorrerS2->multiLista != nullptr)
	{
		if (recorrerS1->multiLista->dato == recorrerS2->multiLista->dato) {
			int dato = recorrerS1->multiLista->dato;
			MultisetInt nuevoRecorrer = recorrerS1;
			MultisetInt nuevoRecorrer2 = recorrerS2;
			int mayor = obtenerMayor(obtenerOcurrencias(nuevoRecorrer, dato), obtenerOcurrencias(nuevoRecorrer2, dato));
			
			while (mayor != 0)
			{
				agregar(aRetornar, recorrerS1->multiLista->dato, 1);
				mayor--;
			}
			while (recorrerS1->multiLista != nullptr && recorrerS1->multiLista->dato == dato)
			{
				recorrerS1->multiLista = recorrerS1->multiLista->sig;
			}
			while (recorrerS2->multiLista != nullptr && recorrerS2->multiLista->dato == dato)
			{
				recorrerS2->multiLista = recorrerS2->multiLista->sig;
			}
		}
		else if (recorrerS1->multiLista->dato < recorrerS2->multiLista->dato) {
			agregar(aRetornar, recorrerS1->multiLista->dato, 1);
			recorrerS1->multiLista = recorrerS1->multiLista->sig;
		}
		else {
			agregar(aRetornar, recorrerS2->multiLista->dato, 1);
			recorrerS2->multiLista = recorrerS2->multiLista->sig;
		}
	}
	destruir(recorrerS1);
	destruir(recorrerS2);
	return aRetornar;
}

MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt recorrerS1 = clon(s1);
	listaOrdenadaSelectionSort(recorrerS1->multiLista);
	MultisetInt recorrerS2 = clon(s2);
	listaOrdenadaSelectionSort(recorrerS2->multiLista);

	MultisetInt aRetornar = crearMultisetInt();
	while (recorrerS1->multiLista != nullptr && recorrerS2->multiLista != nullptr)
	{
		if (recorrerS1->multiLista->dato < recorrerS2->multiLista->dato) recorrerS1->multiLista = recorrerS1->multiLista->sig;
		else if (recorrerS1->multiLista->dato > recorrerS2->multiLista->dato) recorrerS2->multiLista = recorrerS2->multiLista->sig;
		else if (recorrerS1->multiLista->dato == recorrerS2->multiLista->dato) {
			int dato = recorrerS1->multiLista->dato;
			MultisetInt nuevoRecorrer = recorrerS1;
			MultisetInt nuevoRecorrer2 = recorrerS2;
			int menor = obtenerMenor(obtenerOcurrencias(nuevoRecorrer, dato), obtenerOcurrencias(nuevoRecorrer2, dato));

			while (menor != 0)
			{
				agregar(aRetornar, recorrerS1->multiLista->dato, 1);
				menor--;
			}
			while (recorrerS1->multiLista != nullptr && recorrerS1->multiLista->dato == dato)
			{
				recorrerS1->multiLista = recorrerS1->multiLista->sig;
			}
			while (recorrerS2->multiLista != nullptr && recorrerS2->multiLista->dato == dato)
			{
				recorrerS2->multiLista = recorrerS2->multiLista->sig;
			}
		}
	}
	destruir(recorrerS1);
	destruir(recorrerS2);
	return aRetornar;
}

MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {
	NodoListaInt* recorrerS1 = s1->multiLista;

	MultisetInt aRetornar = crearMultisetInt();
	while (recorrerS1 != nullptr)
	{
		MultisetInt recorrers1 = s1;
		MultisetInt recorrers2 = s2;
		int dato = recorrerS1->dato;
		int ocurrenciasEnS1 = obtenerOcurrencias(recorrers1, recorrerS1->dato);
		int ocurrenciasEnS2 = obtenerOcurrencias(recorrers2, recorrerS1->dato);
		int cantidad = ocurrenciasEnS1 - ocurrenciasEnS2;
		if (cantidad > 0) {
			agregar(aRetornar, recorrerS1->dato, 1);
		}
		while (recorrerS1 != nullptr && recorrerS1->dato == dato)
		{
			recorrerS1 = recorrerS1->sig;
		}
	}
	return aRetornar;
}

bool contenidoEn(MultisetInt s1, MultisetInt s2) {
	NodoListaInt* recorrerS1 = s1->multiLista;
	NodoListaInt* recorrerS2 = s2->multiLista;
	while (recorrerS1 != nullptr)
	{	
		MultisetInt recorrers1 = s1;
		MultisetInt recorrers2 = s2;
		int dato = recorrerS1->dato;
		int ocurrenciasEnS1 = obtenerOcurrencias(recorrers1, recorrerS1->dato);
		int ocurrenciasEnS2 = obtenerOcurrencias(recorrers2, recorrerS1->dato);
		if (ocurrenciasEnS1 > ocurrenciasEnS2) return false;
		if (pertenece(recorrers2, recorrerS1->dato)) {
			recorrerS1 = recorrerS1->sig;
		}
		else {
			return false;
		}
		
	}
	return true;
}

int elemento(MultisetInt s) {
	assert(!esVacio(s));
	return s->multiLista->dato;
}

bool esVacio(MultisetInt s) {
	return s->cantElementos == 0;
}

unsigned int cantidadElementos(MultisetInt s) {
	return s->cantElementos;
}

// PRE: -
// POS: Libera la memoria de la lista del multiset.
void vaciarMultiLista(NodoListaInt*& l) {
	if (l != NULL) {
		vaciarMultiLista(l->sig);
		delete l;
		l = NULL;
	}
}

void destruir(MultisetInt& s) {
	vaciarMultiLista(s->multiLista);
	delete s;
	s = nullptr;
}

// PRE: -
// POS: Retorna un clon de la lista que no comparte memoria.
NodoListaInt* clonarMultiLista(NodoListaInt* lista) {
	if (lista == nullptr) return nullptr;
	NodoListaInt* aux = new NodoListaInt();
	aux->dato = lista->dato;
	aux->sig = clonarMultiLista(lista->sig);
	return aux;
}

MultisetInt clon(MultisetInt s) {
	MultisetInt nuevoMultiset = crearMultisetInt();
	nuevoMultiset->multiLista = clonarMultiLista(s->multiLista);
	nuevoMultiset->cantElementos = s->cantElementos;
	return nuevoMultiset;
}

#endif