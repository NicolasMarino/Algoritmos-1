#include "DiccionarioInt.h"

#ifdef DICCIONARIO_INT_IMP

struct _cabezalDiccionarioInt {	
	NodoListaInt** vector;
	unsigned int tamVector;
	unsigned int cantElementos;
};

DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
	DiccionarioInt nuevoDiccionario = new _cabezalDiccionarioInt();
	nuevoDiccionario->cantElementos = 0;
	nuevoDiccionario->vector = new NodoListaInt * [esperados]();
	nuevoDiccionario->tamVector = esperados;
	return nuevoDiccionario;
}

int hashing(int dato, int tam) {
	int hashingData = dato % tam;
	hashingData = abs(hashingData);
	return hashingData;
}

bool factorCarga(int cantElementos, int tam) {
	return cantElementos / tam >= 1;
}

void agrandarHash(DiccionarioInt& d) {
	int dobleTam = d->tamVector * 2;
	d->tamVector = dobleTam;
	NodoListaInt** vectorNuevo = new NodoListaInt * [dobleTam]();
	for (int i = 0; i < d->tamVector / 2; i++)
	{
		while (d->vector[i] != nullptr)
		{
			int nuevoDatoHashed = d->vector[i]->dato;
			NodoListaInt * nuevo = new NodoListaInt(nuevoDatoHashed);
			nuevo->sig = vectorNuevo[hashing(nuevoDatoHashed, d->tamVector)];
			vectorNuevo[hashing(nuevoDatoHashed, d->tamVector)] = nuevo;
			d->vector[i] = d->vector[i]->sig;
		}
	}
	d->vector = vectorNuevo;
}

void agregar(DiccionarioInt& d, int e) {
	if (pertenece(d, e)) return;
	if (factorCarga(d->cantElementos, d->tamVector)) agrandarHash(d);
	NodoListaInt* nuevo = new NodoListaInt(e);
	nuevo->sig = d->vector[hashing(e, d->tamVector)];
	d->vector[hashing(e, d->tamVector)] = nuevo;
	d->cantElementos++;
}

void borrarLista(DiccionarioInt& d, NodoListaInt*& lista, int e) {
	bool borre = false;
	while (lista != nullptr && lista->dato == e && borre == false)
	{
		NodoListaInt* aBorrar = lista;
		lista = lista->sig;
		delete aBorrar;
		borre = true;
		d->cantElementos--;
	}
	NodoListaInt* aRecorrer = lista;

	while (aRecorrer != nullptr && borre == false)
	{
		if (aRecorrer->sig != nullptr && aRecorrer->sig->dato == e) {
			NodoListaInt* aBorrar = aRecorrer->sig;
			aRecorrer->sig = aRecorrer->sig->sig;
			delete aBorrar;
			borre = true;
			d->cantElementos--;
		}
		aRecorrer = aRecorrer->sig;
	}
}

void borrar(DiccionarioInt& d, int e) {
	int hashedE = hashing(e, d->tamVector);
	borrarLista(d, d->vector[hashedE], e);
}

bool pertenece(DiccionarioInt d, int e) {
	int hashedE = hashing(e, d->tamVector);
	NodoListaInt* lista = d->vector[hashedE];

	while (lista != nullptr) {
		if (lista->dato == e) {
			return true;
		}
		lista = lista->sig;
	}
	return false;
}

int elemento(DiccionarioInt d) {
	assert(!esVacio(d));
	for (int i = 0; i < d->tamVector; i++)
	{
		while (d->vector[i] != nullptr) {
			return d->vector[i]->dato;
		}
	}
}

bool esVacio(DiccionarioInt d) {
	return d->cantElementos == 0;
}

unsigned int cantidadElementos(DiccionarioInt d) {
	return d->cantElementos;
}

NodoListaInt* clonarDic(NodoListaInt* lista) {
	if (lista == nullptr) return nullptr;
	NodoListaInt* aux = new NodoListaInt();
	aux->dato = lista->dato;
	aux->sig = clonarDic(lista->sig);
	return aux;
}

DiccionarioInt clon(DiccionarioInt d) {
	DiccionarioInt aRetornar = crearDiccionarioInt(d->tamVector);

	for (int i = 0; i < d->tamVector; i++)
	{
		aRetornar->vector[i] = clonarDic(d->vector[i]);
	}
	aRetornar->cantElementos = d->cantElementos;
	return aRetornar;
}

void destruir(DiccionarioInt& d) {
	delete[] d->vector;
	delete d;
	d = nullptr;
}

#endif