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

//Obligatorio - DONE
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

//Obligatorio - DONE
int maximoNumero(unsigned int n) {
	
	int maxNumber = INT_MIN;
	
	
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num > maxNumber) {
			maxNumber = num;
		}
	};

    return maxNumber;
}

//Obligatorio - DONE
void ordenarVecInt(int *vec, int largoVec) {

	for (int i = 0; i < largoVec; i++)
	{
		for (int t = i+1; t < largoVec; t++)
		{
			int auxiliar = vec[i];
			if (vec[i] > vec[t]) {
				vec[i] = vec[t];
				vec[t] = auxiliar;
			}
		}
	}
}



/*
PRE: Recibe un string palabra.
POS: Retorna el largo de este string

Ejemplo 1
Entrada: "hola"
Retorno: 4

Ejemplo 2
Entrada: "ha"
Retorno: 2
*/
int largoPalabra(char* palabra)
{
	int largoP = 0;
	for (int i = 0; palabra[i] != '\0'; i++)
	{
		largoP += 1;
	}
	return largoP;
}


/**
PRE: Recibe un char unChar.
POS: Retorna si este char es String o no.

Ejemplo 1
Entrada: "h"
Retorno: true

Ejemplo 2
Entrada: "#"
Retorno: false
*/
bool esString(char unChar)
{
	bool esString = false;
	if (unChar >= 65 && unChar <= 122) {
		esString = true;
	}
	return esString;
}

//Obligatorio - DONE
char* invertirCase(char* palabra)
{	
	int largoPalabraInput = largoPalabra(palabra);
	char* palabraAux = new char[largoPalabraInput];
	
	for (int i = 0; palabra[i] != '\0'; i++)
	{
		if (esString(palabra[i]))
		{
			if (palabra[i] + 32 > 122)
			{
				palabraAux[i] = palabra[i] - 32;
			}
			else if (palabra[i] - 32 == 0)
			{
				palabraAux[i] = palabra[i];
			}
			else
			{
				palabraAux[i] = palabra[i] + 32;
			}
		}
		else
		{
			palabraAux[i] = palabra[i];
		}
		
	}
	
	palabraAux[largoPalabraInput] = '\0';
	return palabraAux;
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

/*
PRE: Recibe un string y el largo del mismo string.
POS: Retorna el mismo string en un nuevo espacio de memoria.
	  básicamente es una copia a una nueva memoria para poder modificar este sin modificar el original.

Ejemplo
Entrada : "hola"
Retorno : "hola" en nuevo espacio de memoria

*/
char* copiarStringCompleto(char* origen, int largoString)
{
	char* nuevoChar = new char[largoString];
	for (int i = 0; origen[i] != '\0'; i++)
	{
		nuevoChar[i] = origen[i];
	}
	nuevoChar[largoString - 1] = '\0';

	return nuevoChar;
}

/*
PRE: Recibe un vector y un largo de vector.
POS: Devuelve el mismo vector copiado en una memoria

Ejemplo
Entrada : ["paso,pasa,test"]
Retorno : ["paso,pasa,test"] en nuevo espacio de memoria
*/
char** copiaVectorCompleta(char** vector, int largoVector)
{
	char** nuevoVector = new char* [largoVector];

	for (int i = 0; i < largoVector; i++)
	{
		nuevoVector[i] = copiarStringCompleto(vector[i], largoPalabra(vector[i]) + 1);
	}

	return nuevoVector;
}

/*
PRE: Recibe dos strings.
POS: Retorna cual de los dos strings esta antes alfabeticamente

Ejemplo
Entrada : "paso,pasa"
Retorno : FALSE
*/
bool obtenerStringMayor(char* unChar, char* otroChar)
{
	int largoUnChar = largoPalabra(unChar);
	int largoOtroChar = largoPalabra(otroChar);
	int masLargo = (largoUnChar > largoOtroChar) ? masLargo = largoUnChar : masLargo = largoOtroChar;

	bool esMasLargo = true;
	for (int i = 0; i < masLargo; i++)
	{
		if (unChar[i] != otroChar[i])
		{
			return unChar[i] > otroChar[i];
		}
	}
	return esMasLargo;
}

//Obligatorio -	DONE
char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	char** nuevoVect = new char* [largoVecStr];
	for (int i = 0; i < largoVecStr; i++)
	{
		nuevoVect[i] = copiarStringCompleto(vecStr[i], largoPalabra(vecStr[i]) + 1);
	}

	for (int i = 0; i < largoVecStr; i++)
	{
		for (int t = i + 1; t < largoVecStr; t++)
		{
			char* auxiliar = nuevoVect[i];
			if (obtenerStringMayor(nuevoVect[i], nuevoVect[t]))
			{
				nuevoVect[i] = nuevoVect[t];
				nuevoVect[t] = auxiliar;
			}
		}
	}

	for (int i = 0; i < largoVecStr; i++)
	{
		char* test = nuevoVect[i];
	}

    return nuevoVect;
}

//Obligatorio - TODO
int* intercalarVector(int* v1, int* v2, int l1, int l2){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

//Obligatorio - DONE
bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	
	bool esSubConjunto = true;
	if (l1 != 0 && l2 != 0)
	{
		bool seEncuentra = true;
		for (int i = 0; i < l1; i++)
		{
			if (!perteneceAVector(v2, v1[i],l2)) 
			{
				seEncuentra = false;
			}
		}
		esSubConjunto = (seEncuentra) ? true : false;
	}
	else if (l1 != 0 && l2 == 0)
	{
		return false;
	}
	return esSubConjunto;
}

//Auxiliar
bool perteneceAVector(int* vector, int elemento, int largoVector) 
{
	bool aux = false;
	for (int i = 0; i < largoVector; i++)
	{
		if (vector[i] == elemento)
		{
			return true;
		}
	}
	return aux;
}

/*
PRE: Un string y un separador.
POS: Devuelve cantidad de strings que hay sin contar el separador

Entrada: " ", "@"
Salida: 1

Entrada: "A@B", "@"
Salda: 2
*/
int obtenerLargoSplit(char* palabra, char separador)
{
	bool auxSeparador = palabra[0] != separador;
	int contador = 0;
	for (int i = 0; palabra[i] != '\0'; i++)
	{
		if (palabra[i] == separador)
		{
			auxSeparador = true;
		}
		else
		{
			if (auxSeparador)
			{
				contador += 1;
				auxSeparador = false;
			}
		}
	}
	return contador;
}

//Obligatorio - DONE
char** splitStr(char* str, char separador, int& largoRet)
{
	int largoNuevoArray = obtenerLargoSplit(str, separador);
	largoRet = largoNuevoArray;
	if (largoNuevoArray == 0) return NULL;

	char* nuevoString = copiarStringCompleto(str, largoPalabra(str)+1);

	char** splittedArray = new char* [largoNuevoArray];

	char* separa = new char{ separador };
	char* pch = strtok(nuevoString, separa);

	int contadorAux2 = 0;
	while (pch != NULL)
	{
		splittedArray[contadorAux2] = pch;
		pch = strtok(NULL, separa);
		contadorAux2++;
	}

	return splittedArray;
}



void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}
