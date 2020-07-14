#include "TablaIntString.h"

#ifdef TABLA_INT_STRING_IMP


struct TablaString {
	int clave;
	const char* valor;
	TablaString* sig;
};

struct _cabezalTablaIntString {
	TablaString** vector;
	unsigned int tamVector;
	unsigned int cantElementos;
};

TablaIntString crearTablaIntString(unsigned int esperados) {
	TablaIntString nuevaTablaString = new _cabezalTablaIntString();
	nuevaTablaString->cantElementos = 0;
	nuevaTablaString->vector = new TablaString * [esperados]();
	nuevaTablaString->tamVector = esperados;
	return nuevaTablaString;
}

int hashingTabla(int dato, int tam) {
	int hashingTablaData = dato % tam;
	hashingTablaData = abs(hashingTablaData);
	return hashingTablaData;
}

bool factorCargaTabla (int cantElementos, int tam) {
	return cantElementos / tam >= 1;
}

void agrandarHashTabla(TablaIntString& d) {
	int dobleTam = d->tamVector * 2;
	d->tamVector = dobleTam;
	TablaString** vectorNuevo = new TablaString * [dobleTam]();
	for (int i = 0; i < d->tamVector / 2; i++)
	{
		while (d->vector[i] != nullptr)
		{
			TablaString* nuevo = new TablaString();
			nuevo->clave = d->vector[i]->clave;	
			nuevo->valor = d->vector[i]->valor;
			nuevo->sig = vectorNuevo[hashingTabla(d->vector[i]->clave, d->tamVector)];
			vectorNuevo[hashingTabla(d->vector[i]->clave, d->tamVector)] = nuevo;
			d->vector[i] = d->vector[i]->sig;
		}
	}
	d->vector = vectorNuevo;
}

void pisarTabla(TablaIntString& d, TablaString*& lista, int e, const char* r) {
	bool borre = false;
	while (lista != nullptr && lista->clave == e && borre == false)
	{
		lista->valor = r;
		borre = true;
	}
	TablaString* aRecorrer = lista;

	while (aRecorrer != nullptr && borre == false)
	{
		if (aRecorrer->sig != nullptr && aRecorrer->sig->clave == e) {
			aRecorrer->sig->valor = r;
			borre = true;
		}
		aRecorrer = aRecorrer->sig;
	}
}


void agregar(TablaIntString& t, int d, const char* r) {
	if (factorCargaTabla (t->cantElementos, t->tamVector)) agrandarHashTabla(t);

	if (estaDefinida(t, d)) {
		int hashedE = hashingTabla(d, t->tamVector);
		pisarTabla(t, t->vector[hashedE], d, r);
	} else {
		TablaString* nuevo = new TablaString();
		nuevo->clave = d;
		nuevo->valor = r;
		nuevo->sig = t->vector[hashingTabla(d, t->tamVector)];
		t->vector[hashingTabla(d, t->tamVector)] = nuevo;
		t->cantElementos++;
	}
	
}


bool estaDefinida(TablaIntString t, int d) {
	int hashedE = hashingTabla(d, t->tamVector);
	TablaString* lista = t->vector[hashedE];

	while (lista != nullptr) {
		if (lista->clave == d) {
			return true;
		}
		lista = lista->sig;
	}
	return false;
}

int largoPalabra(const char* palabra)
{
	int largoP = 0;
	for (int i = 0; palabra[i] != '\0'; i++)
	{
		largoP += 1;
	}
	return largoP + 1;
}

char* copiarStringCompleto(const char* origen, int largoString)
{
	char* nuevoChar = new char[largoString];
	for (int i = 0; i < largoString; i++)
	{
		nuevoChar[i] = origen[i];
	}

	return nuevoChar;
}

char* recuperar(TablaIntString t, int d) {
	int hashedE = hashingTabla(d, t->tamVector);	
	bool borre = false;
	while (t->vector[hashedE] != nullptr && t->vector[hashedE]->clave == d && borre == false)
	{
		int largoP = largoPalabra(t->vector[hashedE]->valor);
		return copiarStringCompleto(t->vector[hashedE]->valor, largoP);
		borre = true;
	}
	TablaString* aRecorrer = t->vector[hashedE];

	while (aRecorrer != nullptr && borre == false)
	{
		if (aRecorrer->sig != nullptr && aRecorrer->sig->clave == d) {
			int largoP = largoPalabra(t->vector[hashedE]->valor);
			return copiarStringCompleto(t->vector[hashedE]->valor, largoP);
			borre = true;
		}
		aRecorrer = aRecorrer->sig;
	}
}

void borrarLista(TablaIntString& d, TablaString*& lista, int e) {
	bool borre = false;
	while (lista != nullptr && lista->clave == e && borre == false)
	{
		TablaString* aBorrar = lista;
		lista = lista->sig;
		delete aBorrar;
		borre = true;
		d->cantElementos--;
	}
	TablaString* aRecorrer = lista;

	while (aRecorrer != nullptr && borre == false)
	{
		if (aRecorrer->sig != nullptr && aRecorrer->sig->clave == e) {
			TablaString* aBorrar = aRecorrer->sig;
			aRecorrer->sig = aRecorrer->sig->sig;
			delete aBorrar;
			borre = true;
			d->cantElementos--;
		}
		aRecorrer = aRecorrer->sig;
	}
}

void borrar(TablaIntString& t, int d) {
	int hashedE = hashingTabla(d, t->tamVector);
	borrarLista(t, t->vector[hashedE], d);
}

int elemento(TablaIntString t) {
	assert(!esVacia(t));
	for (int i = 0; i < t->tamVector; i++) {
		while (t->vector[i] != nullptr) {
			return t->vector[i]->clave;
		}
	}
}

bool esVacia(TablaIntString t) {
	return t->cantElementos == 0;
}

unsigned int cantidadElementos(TablaIntString t) {
	return t->cantElementos;
}

TablaString* clonarTabla(TablaString* lista) {
	if (lista == nullptr) return nullptr;
	TablaString* aux = new TablaString();
	aux->clave = lista->clave;
	aux->valor = lista->valor;
	aux->sig = clonarTabla(lista->sig);
	return aux;
}

void destruir(TablaIntString& t) {
	delete[] t->vector;
	delete t;
	t = nullptr;
}

TablaIntString clon(TablaIntString t) {
	TablaIntString aRetornar = crearTablaIntString(t->tamVector);

	for (int i = 0; i < t->tamVector; i++)
	{
		aRetornar->vector[i] = clonarTabla(t->vector[i]);
	}
	aRetornar->cantElementos = t->cantElementos;
	return aRetornar;
}

#endif