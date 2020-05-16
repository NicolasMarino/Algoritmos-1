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
	if (raiz->der == nullptr && raiz->izq == nullptr) return raiz->dato == sum;
	if (raiz->der == nullptr) return existeCaminoConSuma(raiz->izq, sum - raiz->dato);
	if (raiz->izq == nullptr) return existeCaminoConSuma(raiz->der, sum - raiz->dato);
	if (raiz->izq != nullptr && raiz->der != nullptr) return existeCaminoConSuma(raiz->der, sum - raiz->dato) || existeCaminoConSuma(raiz->izq, sum - raiz->dato);
}

//Obligatorio -	TODO
bool esArbolBalanceado(NodoAB* raiz) {
	if (raiz == nullptr) return true;
	int cantidadIzq = altura(raiz->izq);
	int cantidadDer = altura(raiz->der);
	int diferenciaIzq = cantidadIzq - cantidadDer;
	int diferenciaDer = cantidadDer - cantidadIzq;
	return esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der);
	if (diferenciaIzq == 0) {
		return true;
	}
	else if (diferenciaIzq > 1 || diferenciaDer > 1)
	{
		return false;
	}
	else
	{
		return true;
	}
	
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

//Obligatorio -	TODO
int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	
	return 0;
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
int sumaPorNivelesAux(NodoAG* raiz, int nivel) {
	return (raiz == nullptr) ? 0 : ((nivel % 2 == 0) ? + raiz->dato : -raiz->dato) + sumaPorNivelesAux(raiz->ph, nivel+1) + sumaPorNivelesAux(raiz->sh, nivel);
}

//Obligatorio -	DONE
int sumaPorNiveles(NodoAG* raiz){
	return sumaPorNivelesAux(raiz, 1);
}

//Obligatorio -	DONE
bool esPrefijo(NodoAG *a, NodoLista *l)
{
	if (l == nullptr) return true;
	if (a == nullptr && l == nullptr) return true;
	if (a == nullptr && l != nullptr) return false;
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
int obtenerNodosPorNivel(NodoAG* raiz, int nivel) {
	if (raiz == nullptr) return 0;
	if (nivel <= 1){
		return 1 + obtenerNodosPorNivel(raiz->sh, nivel);
	}
	return obtenerNodosPorNivel(raiz->ph, nivel-1) + obtenerNodosPorNivel(raiz->sh, nivel);
}

//Obligatorio -	DONE
int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	if (arbolGeneral == nullptr) return 0;
	int alturaArbol = alturaAG(arbolGeneral);
	int* arr = new int[alturaArbol+1];
	int cantidadNodos;
	for (int i = 1; i < alturaArbol+1; i++)
	{
		arr[i] = obtenerNodosPorNivel(arbolGeneral, i);
	}
	int max = arr[0];
	for (int x = 1; x <= alturaArbol; x++)
	{
		if (arr[x] > max) {
			max = arr[x];
		}
	}
	for (int ia = 1; ia <= alturaArbol; ia++)
	{
		if (arr[ia] == max) {
			return ia;
		}
	}
}
