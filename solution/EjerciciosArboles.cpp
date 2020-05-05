#include "EjerciciosArboles.h"
#include "EjerciciosListas.h"

//DONE
int altura(NodoAB* raiz){
	if (raiz == nullptr) return 0;
	if (1 + altura(raiz->der) > 1 + altura(raiz->izq)) {
		return 1 + altura(raiz->der);
	}
	else {
		return 1 + altura(raiz->izq);
	}
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
	if (raiz->der == nullptr && raiz->izq == nullptr) return raiz->dato == sum;
	if (raiz->der == nullptr) return existeCaminoConSuma(raiz->izq, sum - raiz->dato);
	if (raiz->izq == nullptr) return existeCaminoConSuma(raiz->der, sum - raiz->dato);
	if (raiz->izq != nullptr && raiz->der != nullptr) return existeCaminoConSuma(raiz->der, sum - raiz->dato) || existeCaminoConSuma(raiz->izq, sum - raiz->dato);
}

//Obligatorio -	TODO
bool esArbolBalanceado(NodoAB *raiz) {
	// IMPLEMENTAR SOLUCION
	return false;
}

NodoLista* enNivel(NodoAB *a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

//Obligatorio -	Done
NodoLista* camino(NodoAB *arbol, int x) {
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

//Obligatorio -	TODO
NodoAB* obtenerMinimo(NodoAB* A) {
	if (A->izq == nullptr) {
		return A;
	}
	else {
		return obtenerMinimo(A->izq);
	}
}

void borrarNodoRaiz(NodoAB * & A) {
	/*if (A->der == nullptr) {
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
		NodoAB* aux = obtenerMinimo(A->der);
		A->dato = aux->dato;
		borrarHojaO1Hijo(aux, aux->dato);

	}*/
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

//Obligatorio -	TODO
int sucesor(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}

//Obligatorio -	TODO
int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

void borrarPares(NodoAB* & a){
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}

//Obligatorio -	TODO
int sumaPorNiveles(NodoAG* raiz){
	// IMPLEMENTAR SOLUCION
	return 0;
}

//Obligatorio -	TODO
bool esPrefijo(NodoAG *a, NodoLista *l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

//Obligatorio -	TODO
NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

//Obligatorio -	TODO
int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	// IMPLEMENTAR SOLUCION
	return 0;
}
