#include "MultisetInt.h"

#ifdef MULTISET_INT_IMP

struct _cabezalMultisetInt {
	int cantElementos;
	NodoListaIntDobleDato* multiLista;
};

MultisetInt crearMultisetInt() {
	MultisetInt multiset = new _cabezalMultisetInt();
	multiset->multiLista = new NodoListaIntDobleDato();
	return multiset;
}

void agregarElem(NodoListaIntDobleDato* lista, int dato) {
	NodoListaIntDobleDato* nuevo = new NodoListaIntDobleDato(dato,1);
	lista->sig = nuevo;
}

void agregar(MultisetInt& s, int e, unsigned int ocurrencias){
	NodoListaIntDobleDato* aRecorrer = s->multiLista;
	bool agregue = false;
	NodoListaIntDobleDato* nuevo = new NodoListaIntDobleDato(e, ocurrencias);
	if (esVacio(s)) {
		s->multiLista = nuevo;
		s->cantElementos++; 
		agregue = true;
	}
	while (aRecorrer != nullptr && agregue == false)
	{
		if (aRecorrer->dato1 == e) {
			aRecorrer->dato2 += ocurrencias;
			agregue = true;
		}
		if (aRecorrer->sig == nullptr) {
			aRecorrer->sig = nuevo;
			s->cantElementos++;
			agregue = true;
		}
		aRecorrer = aRecorrer->sig;
	}
	
}

void borrar(MultisetInt& s, int e) {
	bool borre = false;
	while (s->multiLista != nullptr && s->multiLista->dato1 == e && borre==false)
	{
		NodoListaIntDobleDato* aBorrar = s->multiLista;
		s->multiLista = s->multiLista->sig;
		delete aBorrar;
		s->cantElementos--;
		borre = true;
	}
	NodoListaIntDobleDato* aRecorrer = s->multiLista;

	while (aRecorrer != nullptr && borre == false)
	{
		if (aRecorrer->sig != nullptr && aRecorrer->sig->dato1 == e) {
			NodoListaIntDobleDato* aBorrar = aRecorrer->sig;
			aRecorrer->sig = aRecorrer->sig->sig;
			delete aBorrar;
			s->cantElementos--;
			borre = true;
		}
		
		aRecorrer = aRecorrer->sig;
	}

}

bool pertenece(MultisetInt s, int e) {
	NodoListaIntDobleDato* aRecorrer = s->multiLista;
	while (aRecorrer != nullptr) {
		if (aRecorrer->dato1 == e) {
			return true;
		}
		aRecorrer = aRecorrer->sig;
	}
	return false;
}

void listaOrdenadaSelectionSort(NodoListaIntDobleDato*& l)
{
	if (l != nullptr) {
		NodoListaIntDobleDato* menor = l;
		NodoListaIntDobleDato* aux = l;

		while (aux != NULL) {
			if (aux->dato1 < menor->dato1) {
				menor = aux;
			}
			aux = aux->sig;
		}

		int datoAux1 = l->dato1;
		int datoAux2 = l->dato2;
		l->dato1 = menor->dato1;
		l->dato2 = menor->dato2;
		menor->dato1 = datoAux1;
		menor->dato2 = datoAux2;

		listaOrdenadaSelectionSort(l->sig);
	}
}
int obtenerMenor(int uno, int dos) {
	if (uno < dos) {
		return uno;
	}
	else {
		return dos;
	}
}

// PRE: -
// POS: Retorna un nuevo multiset que es la union de m1 y m2,
//   	 o sea, el conjunto que contiene los elementos de m1 y de m2
//   	 El conjunto retornado no debe compartir memoria con m1 ni m2.
MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt recorrerS1 = clon(s1);
	listaOrdenadaSelectionSort(recorrerS1->multiLista);
	MultisetInt recorrerS2 = clon(s2);
	listaOrdenadaSelectionSort(recorrerS2->multiLista);
	MultisetInt aRetornar = crearMultisetInt();
	while (recorrerS1->multiLista != nullptr && recorrerS2->multiLista != nullptr)
	{
		if (recorrerS1->multiLista->dato1 == recorrerS2->multiLista->dato1) {
			agregar(aRetornar, recorrerS1->multiLista->dato1, recorrerS1->multiLista->dato2);
			agregar(aRetornar, recorrerS2->multiLista->dato1, recorrerS2->multiLista->dato2);
			recorrerS1->multiLista = recorrerS1->multiLista->sig;
			recorrerS2->multiLista = recorrerS2->multiLista->sig;
		}
		else if (recorrerS1->multiLista->dato1 < recorrerS2->multiLista->dato1) {
			agregar(aRetornar, recorrerS1->multiLista->dato1, recorrerS1->multiLista->dato2);
			recorrerS1->multiLista = recorrerS1->multiLista->sig;
		}
		else {
			agregar(aRetornar, recorrerS2->multiLista->dato1, recorrerS2->multiLista->dato2);
			recorrerS2->multiLista = recorrerS2->multiLista->sig;
		}
	
	}
	/*while (recorrerS1->multiLista != nullptr)
	{
		agregar(aRetornar, recorrerS1->multiLista->dato1, recorrerS1->multiLista->dato2);
		recorrerS1->multiLista = recorrerS1->multiLista->sig;
	}
	while (recorrerS2->multiLista != nullptr)
	{
		agregar(aRetornar, recorrerS2->multiLista->dato1, recorrerS2->multiLista->dato2);
		recorrerS2->multiLista = recorrerS2->multiLista->sig;
	}*/
	return aRetornar;
}


MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {
	NodoListaIntDobleDato* recorrerS1 = clon(s1)->multiLista;
	listaOrdenadaSelectionSort(recorrerS1);
	NodoListaIntDobleDato* recorrerS2 = clon(s2)->multiLista;
	listaOrdenadaSelectionSort(recorrerS2);

	MultisetInt aRetornar = crearMultisetInt();
	while (recorrerS1 != nullptr && recorrerS2 != nullptr)
	{
		if (recorrerS1->dato1 < recorrerS2->dato1) recorrerS1 = recorrerS1->sig;
		else if (recorrerS1->dato1 > recorrerS2->dato1) recorrerS2 = recorrerS2->sig;
		else if (recorrerS1->dato1 == recorrerS2->dato1) {
			agregar(aRetornar, recorrerS1->dato1, obtenerMenor(recorrerS1->dato2, recorrerS2->dato2));
			recorrerS1 = recorrerS1->sig;
			recorrerS2 = recorrerS2->sig;
		}		
	}
	return aRetornar;
}

// PRE: -
// POS: Retorna un nuevo multiset que es la diferencia entre m1 y m2,
//   	 o sea, el conjunto que contiene solo los elementos que estan en m1 pero no en m2.
//   	 El conjunto retornado no debe compartir memoria con m1 ni m2.
MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {
	NodoListaIntDobleDato* recorrerS1 = s1->multiLista;
	MultisetInt aRetornar = crearMultisetInt();
	while (recorrerS1 != nullptr)
	{
		if (!pertenece(s2, recorrerS1->dato1)) {
			agregar(aRetornar, recorrerS1->dato1, recorrerS1->dato2);
		}
		recorrerS1 = recorrerS1->sig;
	}
	return aRetornar;
}

bool embebida(NodoListaIntDobleDato* l, NodoListaIntDobleDato* secuencia) {
	if (l == nullptr && secuencia == nullptr) return true;
	if (l == nullptr) return false;
	if (secuencia == nullptr) return true;
	if (l != nullptr && secuencia != nullptr)
		if (l->dato1 == secuencia->dato1)
			embebida(l->sig, secuencia->sig);
		else
			return false;
}
//PRE: -
//POS: Retorna true sii todos los elementos de m1 pertenecen a m2
bool contenidoEn(MultisetInt s1, MultisetInt s2) {
	NodoListaIntDobleDato* recorrerS1 = s1->multiLista;
	NodoListaIntDobleDato* recorrerS2 = s2->multiLista;
	return embebida(recorrerS1, recorrerS2);
}


int elemento(MultisetInt s) {
	assert(!esVacio(s));
	return s->multiLista->dato1;
}

bool esVacio(MultisetInt s) {
	return s->cantElementos == 0;
}

unsigned int cantidadElementos(MultisetInt s) {
	return s->cantElementos;
}

//void vaciar(NodoListaIntDobleDato*& l) {
//	if (l != NULL) {
//		vaciar(l->sig);
//		delete l;
//		l = NULL;
//	}
//}

void destruir(MultisetInt& s) {
	//vaciar(s->multiLista);

}

NodoListaIntDobleDato* clonare(NodoListaIntDobleDato* lista) {
	if (lista == nullptr) return nullptr;
	NodoListaIntDobleDato* aux = new NodoListaIntDobleDato();
	aux->dato1 = lista->dato1;
	aux->dato2 = lista->dato2;
	aux->sig = clonare(lista->sig);
	return aux;
}

MultisetInt clon(MultisetInt s) {
	MultisetInt nuevoMultiset = crearMultisetInt();
	nuevoMultiset->multiLista = clonare(s->multiLista);
	nuevoMultiset->cantElementos = s->cantElementos;
	return nuevoMultiset;
}

#endif