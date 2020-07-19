#include "TablaIntString.h"

#ifdef TABLA_INT_STRING_IMP


struct TablaString {
	int clave;
	char* valor;
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

// PRE: 
// POS: Retorna el valor que le corresponde a la clave proporcionada en el hash, de tamaño tam proporcionado.
int hashingTabla(int clave, int tam) {
	int hashingTablaData = clave % tam;
	hashingTablaData = abs(hashingTablaData);
	return hashingTablaData;
}

// PRE: 
// POS: Retorna si la cantidad de elementos sobre el tamaño es mayor o igual a 1.
//		Le inidica al usuario si debe agrandar su vector de hash.
bool factorCargaTabla (int cantElementos, int tam) {
	return cantElementos / tam >= 1;
}

// PRE: 
// POS: Retorna el largo de este string
int largoPalabra(const char* palabra)
{
	int largoP = 0;
	for (int i = 0; palabra[i] != '\0'; i++)
	{
		largoP += 1;
	}
	return largoP + 1;
}

// PRE: Recibe un string y el largo del mismo string.
// POS: Retorna el mismo string en un nuevo espacio de memoria.
//	  básicamente es una copia a una nueva memoria para poder modificar este sin modificar el original.
char* copiarStringCompleto(const char* origen, int largoString)
{
	char* nuevoChar = new char[largoString];
	for (int i = 0; i < largoString - 1 ; i++)
	{
		nuevoChar[i] = origen[i];
	}
	nuevoChar[largoString - 1] = '\0';
	return nuevoChar;
}

// PRE: -
// POS: Libera la memoria del vector de la tabla.
void destruirVector(TablaIntString& t) {
	for (int i = 0; i < t->tamVector; i++)
	{
		while (t->vector[i] != nullptr)
		{
			TablaString* aBorrar = t->vector[i];
			char* charAborrar = t->vector[i]->valor;
			t->vector[i] = t->vector[i]->sig;
			delete[] charAborrar;
			delete aBorrar;
		}
	}
	delete[] t->vector;
}

// PRE: -
// POS: Agranda al doble las posiciones del vector de la TablaIntString que es pasada por parámetro.
//		Se vuelven a hashear todos los elementos y asignar al nuevo vector.
//		Se libera memoria del vector antiguo.
void agrandarHashTabla(TablaIntString& d) {
	int dobleTam = d->tamVector * 2;
	TablaString** vectorNuevo = new TablaString * [dobleTam]();
	for (int i = 0; i < d->tamVector; i++)
	{
		TablaString* aRecorrer = d->vector[i];
		while (aRecorrer != nullptr)
		{
			TablaString* nuevo = new TablaString();
			nuevo->clave = aRecorrer->clave;
			nuevo->valor = copiarStringCompleto(aRecorrer->valor, largoPalabra(aRecorrer->valor));
			nuevo->sig = vectorNuevo[hashingTabla(aRecorrer->clave, dobleTam)];
			vectorNuevo[hashingTabla(aRecorrer->clave, dobleTam)] = nuevo;
			aRecorrer = aRecorrer->sig;
		}
	}
	destruirVector(d);
	d->tamVector = dobleTam;
	d->vector = vectorNuevo;
}

// PRE: 
// POS: libera memoria del char proporcionado.
void borrarChar(char*& r) {
	char*& aBorrar = r;
	delete[] aBorrar;
}

// PRE: 
// POS: Como d esta definida en t, libera memoria y actualiza correspondencia con r.
void pisarValorTabla(TablaString*& lista, int d, const char* r) {
	if (lista != nullptr && lista->clave == d)
	{
		borrarChar(lista->valor);
		lista->valor = copiarStringCompleto(r, largoPalabra(r));
	}
	TablaString* aRecorrer = lista;

	while (aRecorrer != nullptr)
	{
		if (aRecorrer->sig != nullptr && aRecorrer->sig->clave == d) {
			borrarChar(lista->valor);
			aRecorrer->sig->valor = copiarStringCompleto(r, largoPalabra(r));
			break;
		}
		aRecorrer = aRecorrer->sig;
	}
}

void agregar(TablaIntString& t, int d, const char* r) {
	if (factorCargaTabla (t->cantElementos, t->tamVector)) agrandarHashTabla(t);

	if (estaDefinida(t, d)) {
		int hashedE = hashingTabla(d, t->tamVector);
		pisarValorTabla(t->vector[hashedE], d, r);
	} else {
		TablaString* nuevo = new TablaString();
		nuevo->clave = d;
		nuevo->valor = copiarStringCompleto(r, largoPalabra(r));
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

char* recuperar(TablaIntString t, int d) {
	int hashedE = hashingTabla(d, t->tamVector);	
	if (t->vector[hashedE] != nullptr && t->vector[hashedE]->clave == d)
	{
		int largoP = largoPalabra(t->vector[hashedE]->valor);
		return copiarStringCompleto(t->vector[hashedE]->valor, largoP);
	}
	TablaString* aRecorrer = t->vector[hashedE];

	while (aRecorrer != nullptr)
	{
		if (aRecorrer->sig != nullptr && aRecorrer->sig->clave == d) {
			int largoP = largoPalabra(aRecorrer->valor);
			return copiarStringCompleto(aRecorrer->valor, largoP);
		}
		aRecorrer = aRecorrer->sig;
	}
}

// PRE: -
// POS: Libera memoria de t(d) y baja la cantidad de elementos en la TablaIntString.
void borrarLista(TablaIntString& t, TablaString*& lista, int d) {
	if (lista != nullptr && lista->clave == d)
	{
		TablaString* aBorrar = lista;
		lista = lista->sig;
		borrarChar(aBorrar->valor);
		delete aBorrar;
		t->cantElementos--;
	}

	TablaString* aRecorrer = lista;
	bool borre = false;

	while (aRecorrer != nullptr && borre == false)
	{
		if (aRecorrer->sig != nullptr && aRecorrer->sig->clave == d) {
			TablaString* aBorrar = aRecorrer->sig;
			aRecorrer->sig = aRecorrer->sig->sig;
			borrarChar(aBorrar->valor);
			delete aBorrar;
			t->cantElementos--;
			break;
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

void destruir(TablaIntString& t) {
	destruirVector(t);
	delete t;
	t = nullptr;
}

// PRE: -
// POS: retorna una copia de una posición del vector de la tabla sin compartir memoria
TablaString* clonarTabla(TablaString* lista) {
	if (lista == nullptr) return nullptr;
	TablaString* aux = new TablaString();
	aux->clave = lista->clave;
	aux->valor = copiarStringCompleto(lista->valor,largoPalabra(lista->valor));
	aux->sig = clonarTabla(lista->sig);
	return aux;
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