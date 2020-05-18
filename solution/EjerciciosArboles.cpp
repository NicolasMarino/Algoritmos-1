#include "EjerciciosArboles.h"
#include "EjerciciosListas.h"

int obtenerMaximo(int primerValor, int segundoValor) {
	if (primerValor >= segundoValor)
	{
		return primerValor;
	}
	else {
		return segundoValor;
	}
}

//DONE
int altura(NodoAB* raiz){
	if (raiz == nullptr) return 0;
	return obtenerMaximo(1 + altura(raiz->der), 1 + altura(raiz->izq));
}

//DONE
bool sonIguales(NodoAB* p, NodoAB* q) {
	if (p == nullptr && q == nullptr) return true;
	if (p == nullptr || q == nullptr) return false;
	return p->dato == q ->dato && sonIguales(p->der,q->der) && sonIguales(p->izq, q->izq);
}

//Obligatorio -	DONE
bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	if (raiz == nullptr && sum == 0) return true;
	if (raiz == nullptr && sum != 0) return false;
	if (raiz->der == nullptr) return existeCaminoConSuma(raiz->izq, sum - raiz->dato);
	if (raiz->izq == nullptr) return existeCaminoConSuma(raiz->der, sum - raiz->dato);
	if (raiz->der == nullptr && raiz->izq == nullptr) return raiz->dato == sum;
	if (raiz->izq != nullptr && raiz->der != nullptr) return existeCaminoConSuma(raiz->der, sum - raiz->dato) || existeCaminoConSuma(raiz->izq, sum - raiz->dato);
}

//Obligatorio -	DONE
bool esArbolBalanceado(NodoAB* raiz) {
	if (raiz == nullptr) return true;
	int cantidadIzq = altura(raiz->izq);
	int cantidadDer = altura(raiz->der);
	return (cantidadIzq == cantidadDer || (cantidadIzq - 1) == cantidadDer || cantidadIzq == (cantidadDer - 1)) && esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der);
}

NodoLista* enNivel(NodoAB *a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

//Obligatorio -	DONE
NodoLista* camino(NodoAB *arbol, int x) { //1,2,3 3
	NodoLista* listaRetorno = new NodoLista();
	listaRetorno->dato = arbol->dato;
	listaRetorno->sig = nullptr;
	if (arbol->dato > x) {
		listaRetorno->sig = camino(arbol->izq, x);
	}
	else if (arbol->dato < x) {
		listaRetorno->sig = camino(arbol->der, x);
	}
	return listaRetorno;
}

NodoAB* invertirHastak(NodoAB* a, int k){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

//Auxiliar
NodoAB*& obtenerMayorIzq(NodoAB*& A) {
	if (A->der == nullptr) {
		return A;
	}
	else {
		return obtenerMayorIzq(A->der);
	}
}

//Auxiliar
void borrarHojaO1Hijo(NodoAB*& raiz, int dato) {
	if (raiz->dato == dato)
	{
		NodoAB* borrar = raiz;
		raiz = raiz->der == nullptr ? raiz->izq : nullptr;
		delete borrar;
	}
	else {
		if (dato < raiz->dato) {
			borrarHojaO1Hijo(raiz->izq, dato);
		}
		else {
			borrarHojaO1Hijo(raiz->der, dato);
		}
	}
}

//Obligatorio -	DONE
void borrarNodoRaiz(NodoAB * & A) {
	if (A->der == nullptr) {
		NodoAB* aux = A;
		A = A->izq;
		delete aux;
	}
	else if (A->izq == nullptr)
	{
		NodoAB* aux = A;
		A = A->der;
		delete aux;
	}
	else
	{
		NodoAB*& aux = obtenerMayorIzq(A->izq);
		A->dato = aux->dato;
		borrarHojaO1Hijo(aux, aux->dato);
	}
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

//Obligatorio -	TODO
int sucesor(NodoAB* a, int n)
{
	return 0;
}

//Auxiliar
int obtenerNodosPorNivelArbolBinario(NodoAB* raiz, int nivel) {
	if (raiz == nullptr) return 0;
	if (nivel <= 1)
		return 1;
	return obtenerNodosPorNivelArbolBinario(raiz->izq, nivel - 1) + obtenerNodosPorNivelArbolBinario(raiz->der, nivel - 1);
}

//Auxiliar
int obtenerMayorArray(int* unArray, int largoArray) {
	int max = unArray[0];
	for (int x = 1; x <= largoArray; x++)
	{
		if (unArray[x] >= max) {
			max = unArray[x];
		}
	}
	return max;
}

//Auxiliar
int obtenerPrimeraOcurrenciaEnArray(int*& unArray, int largoArray, int dato) {
	for (int ia = 1; ia <= largoArray; ia++)
	{
		if (unArray[ia] == dato) {
			delete[] unArray;
			return ia;
		}
	}
}

//Obligatorio -	DONE
int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	if (raiz == nullptr) return 0;
	int* nodosPorNivel = new int[nivelHasta + 1]();
	int alturaArbol = altura(raiz);
	for (int i = 1; i < nivelHasta+1; i++)
	{
		nodosPorNivel[i] = obtenerNodosPorNivelArbolBinario(raiz, i);
	}
	int maximoArray = obtenerMayorArray(nodosPorNivel, nivelHasta + 1);
	return obtenerPrimeraOcurrenciaEnArray(nodosPorNivel, nivelHasta+1, maximoArray);
}

//DONE
void borrarPares(NodoAB* & a){
	if (a != NULL) {
		if (a->dato % 2 == 0) {
			borrarNodoRaiz(a);
			borrarPares(a);
		}
		else {
			borrarPares(a->izq);
			borrarPares(a->der);
		}
	}
}

//Opcional
int alturaAG(NodoAG* raiz)
{
	if(raiz == nullptr )return 0;
	return obtenerMaximo(alturaAG(raiz->sh), 1 + alturaAG(raiz->ph));
}

//Auxiliar
int sumaNivelParMenosImpar(NodoAG* raiz, int nivel) {
	if (raiz == nullptr) return 0;
	if (nivel % 2 == 0) {
		return + raiz->dato + sumaNivelParMenosImpar(raiz->ph, nivel + 1) + sumaNivelParMenosImpar(raiz->sh, nivel);
	}
	else {
		return - raiz->dato + sumaNivelParMenosImpar(raiz->ph, nivel + 1) + sumaNivelParMenosImpar(raiz->sh, nivel);
	}
}

//Obligatorio -	DONE
int sumaPorNiveles(NodoAG* raiz){
	return sumaNivelParMenosImpar(raiz, 1);
}

//Obligatorio -	DONE
bool esPrefijo(NodoAG *a, NodoLista *l)
{
	if (l == nullptr) return true;
	if (a == nullptr && l == nullptr) return true;
	if (a != nullptr && l != nullptr) {
		if (a->dato == l->dato) {
			return esPrefijo(a->ph, l->sig);
		}
		else {
			return esPrefijo(a->sh, l);
		}
	}
	return false;
}

//Obligatorio -	DONE
NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	if (arbolGeneral == nullptr) return nullptr;
	if (arbolGeneral->dato == dato) {
		NodoLista* ultimoLista = new NodoLista(dato);
		ultimoLista->sig = caminoAG(arbolGeneral->ph, dato);
		return ultimoLista;
	}
	else {
		NodoLista* aux  = caminoAG(arbolGeneral->ph, dato);
		if (aux != nullptr) {
			NodoLista* otroNodo = new NodoLista(arbolGeneral->dato);
			otroNodo->sig = aux;
			aux = otroNodo;
			return aux;
		}
		else {
			return caminoAG(arbolGeneral->sh, dato);
		}
	}
}

//Auxiliar
int obtenerNodosPorNivelAG(NodoAG* raiz, int nivel) {
	if (raiz == nullptr) return 0;
	if (nivel <= 1){
		return 1 + obtenerNodosPorNivelAG(raiz->sh, nivel);
	}
	return obtenerNodosPorNivelAG(raiz->ph, nivel-1) + obtenerNodosPorNivelAG(raiz->sh, nivel);
}

//Obligatorio -	DONE
int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	if (arbolGeneral == nullptr) return 0;
	int alturaArbol = alturaAG(arbolGeneral);
	int* cantidadNodosEnNivel = new int[alturaArbol+1];
	for (int i = 1; i < alturaArbol+1; i++)
	{
		cantidadNodosEnNivel[i] = obtenerNodosPorNivelAG(arbolGeneral, i);
	}
	int maximoArray = obtenerMayorArray(cantidadNodosEnNivel, alturaArbol);
	return obtenerPrimeraOcurrenciaEnArray(cantidadNodosEnNivel, alturaArbol, maximoArray);
}
