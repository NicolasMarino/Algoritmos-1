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

// PRE: 
// POS: Retorna el valor que le corresponde a la clave proporcionada en el hash, de tamaño tam proporcionado.
int hashing(int dato, int tam) {
	int hashingData = dato % tam;
	hashingData = abs(hashingData);
	return hashingData;
}

// PRE: 
// POS: Retorna si la cantidad de elementos sobre el tamaño es mayor o igual a 1.
//		Le inidica al usuario si debe agrandar su vector de hash.
bool factorCarga(int cantElementos, int tam) {
	return cantElementos / tam >= 1;
}

// PRE: -
// POS: Libera la memoria del vector del diccionario.
void destruirVector(DiccionarioInt& d) {
	for (int i = 0; i < d->tamVector; i++)
	{
		while (d->vector[i] != nullptr)
		{
			NodoListaInt* aBorrar = d->vector[i];
			d->vector[i] = d->vector[i]->sig;
			delete aBorrar;
		}
	}
	delete[] d->vector;
}

// PRE: -
// POS: Agranda al doble las posiciones del vector del diccionario que es pasada por parámetro.
//		Se vuelven a hashear todos los elementos y asignar al nuevo vector.
//		Se libera memoria del vector antiguo.
void agrandarHash(DiccionarioInt& d) {
	int dobleTam = d->tamVector * 2;
	NodoListaInt** vectorNuevo = new NodoListaInt * [dobleTam]();
	for (int i = 0; i < d->tamVector; i++)
	{
		while (d->vector[i] != nullptr)
		{
			int nuevoDatoHashed = d->vector[i]->dato;
			NodoListaInt * nuevo = new NodoListaInt(nuevoDatoHashed);
			nuevo->sig = vectorNuevo[hashing(nuevoDatoHashed, dobleTam)];
			vectorNuevo[hashing(nuevoDatoHashed, dobleTam)] = nuevo;
			d->vector[i] = d->vector[i]->sig;
		}
	}
	destruirVector(d);
	d->tamVector = dobleTam;
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

// PRE: -
// POS: Borra un elemento del diccionario, si no se encuentra no tiene efecto.
void borrarLista(DiccionarioInt& d, NodoListaInt*& lista, int e) {
	if (lista != nullptr && lista->dato == e)
	{
		NodoListaInt* aBorrar = lista;
		lista = lista->sig;
		delete aBorrar;
		d->cantElementos--;
	}
	NodoListaInt* aRecorrer = lista;

	while (aRecorrer != nullptr)
	{
		if (aRecorrer->sig != nullptr && aRecorrer->sig->dato == e) {
			NodoListaInt* aBorrar = aRecorrer->sig;
			aRecorrer->sig = aRecorrer->sig->sig;
			delete aBorrar;
			d->cantElementos--;
			break;
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

// PRE: -
// POS: retorna una copia de una posición del vector del diccionario sin compartir memoria
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
	destruirVector(d);
	delete d;
	d = nullptr;
}
#endif