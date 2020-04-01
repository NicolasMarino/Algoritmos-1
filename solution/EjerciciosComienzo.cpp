#include "EjerciciosComienzo.h"

int suma(int a, int b) {
    return a+b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
	for (int i = desde; i <= hasta; i++)
	{
		cout << i << '*' << tablaDel << '=' << i * tablaDel;

		if (i < hasta)
		{
			cout << ';';
		}
	}
	return;
}

void simplificar(int n, int d) {
	
	return;
}

//Obligatorio
int ocurrencias123Repetidos(int* vector, int largo) {

	bool aux = false;
	int contador = 0;

	for (int i = 0; i < largo; i++)
	{
		if (vector[i] == 1) {
			aux = true;
		}
		if (aux && vector[i] == 2) {
			aux = true;
			if (vector[i + 1] != 3 && vector[i + 1] != 2) {
				aux = false;
			}
		}
		if (aux && vector[i+1] == 2) {
			aux = true;
			if (vector[i + 2] == 3) {
				contador += 1;
			}
		}
		else {
			aux = false;
		}
		if (aux && vector[i] != 1 && vector[i] == 3) {
			contador += 1;
		}
	}
	return contador;
}

//Obligatorio
int maximoNumero(unsigned int n) {
	// IMPLEMENTAR SOLUCION
    return 0;
}

//Obligatorio
void ordenarVecInt(int *vec, int largoVec) {
	// IMPLEMENTAR SOLUCION
}

//Obligatorio
char* invertirCase(char* palabra)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

//Obligatorio
char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	// IMPLEMENTAR SOLUCION
    return NULL;
}

//Obligatorio
int* intercalarVector(int* v1, int* v2, int l1, int l2){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

//Obligatorio
bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

//Obligatorio
char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}
