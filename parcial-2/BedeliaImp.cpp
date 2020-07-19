#include "Bedelia.h"

#ifdef BEDELIA_IMP

struct Materia {
	int id;
	char* nombre;
};

struct Examen {
	char* fecha;
	int idMateria;
	unsigned int nota;
	Examen* sig;
};

struct Estudiante {
	char* nombre;
	int idEstudiante;
	Examen* examenes;
	unsigned int cantExamenes;
	unsigned int cantexamenesAprobados;
	unsigned int cantexamenesReprobados;
	Estudiante* sig;
};

struct _cabezalBedelia {
	Estudiante** estudiantes;
	Materia** materias;
	Examen* examenes;
	unsigned int cantidadEstudiantes;
};

Bedelia crearBedelia(unsigned int cantEstudiantes) {
	Bedelia nuevaBedelia = new _cabezalBedelia();
	nuevaBedelia->materias = new Materia * [200]();
	nuevaBedelia->estudiantes = new Estudiante * [cantEstudiantes]();
	//nuevaBedelia->examenes = nullptr;
	nuevaBedelia->cantidadEstudiantes = cantEstudiantes;
	return nuevaBedelia;
}

int hashing(int clave, int tam) {
	int hashingData = clave % tam;
	hashingData = abs(hashingData);
	return hashingData;
}

// PRE: 
// POS: Retorna el largo de este string
//
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
//
char* copiarStringCompleto(const char* origen, int largoString)
{
	char* nuevoChar = new char[largoString];
	for (int i = 0; i < largoString - 1; i++)
	{
		nuevoChar[i] = origen[i];
	}
	nuevoChar[largoString - 1] = '\0';
	return nuevoChar;
}

// PRE: 
// POS: libera memoria del char proporcionado.
//
void borrarChar(char*& r) {
	char*& aBorrar = r;
	delete[] aBorrar;
}

void agregarEstudiante(Bedelia& d, int id, const char* nombre) {
	int hashedEstudiante = hashing(id, d->cantidadEstudiantes);
	Estudiante* lista = d->estudiantes[hashedEstudiante];
	bool modifique = false;
	while (lista != nullptr) {
		if (lista->idEstudiante == id) {
			borrarChar(lista->nombre);
			lista->nombre = copiarStringCompleto(nombre, largoPalabra(nombre));
			modifique = true;
		}
		lista = lista->sig;
	}
	if (modifique == false) {
		Estudiante* nuevo = new Estudiante();
		nuevo->idEstudiante = id;
		nuevo->nombre = copiarStringCompleto(nombre, largoPalabra(nombre));
		nuevo->sig = d->estudiantes[hashedEstudiante];
		d->estudiantes[hashedEstudiante] = nuevo;
	}
}

// ---------------------- ORDEN(1) promedio / HASH SI O SI-----------------------------------
//PRE: -
//POS: asocia el nombre de estudiante nombreE al identificador dado, independientemente de si
//éste existía ya o no, en el sistema de bedelía b 
void actualizarEstudiante(Bedelia& b, const char* nombreE, unsigned int id) {
	agregarEstudiante(b, id, nombreE);
}

// ---------------------- ORDEN(1) peor caso, si o si un array de 200.-----------------------------------
//PRE: el parámetro id es válido
//POS: asocia el nombre de la materia nombreA al identificador dado, independientemente de
//si ésta existía ya o no, en el sistema de bedelía b 
void actualizarMateria(Bedelia& b, const char* nombreA, unsigned int id) {
	//if (b->materias[id] != nullptr) borrarChar(b->materias[id]->nombre);
	Materia* nuevaMateria = new Materia;
	nuevaMateria->id = id;
	nuevaMateria->nombre = copiarStringCompleto(nombreA, largoPalabra(nombreA));
	b->materias[id] = nuevaMateria;
	//b->materias[id]->nombre = 
}

/*
PRE: Recibe dos strings.
POS: Retorna cual de los dos strings esta antes alfabeticamente

Ejemplo
Entrada : "paso,pasa"
Retorno : FALSE
*/
bool esIgual(char* unChar, const char* otroChar)
{
	int largoUnChar = largoPalabra(unChar);
	int largoOtroChar = largoPalabra(otroChar);
	int masLargo = (largoUnChar > largoOtroChar) ? masLargo = largoUnChar : masLargo = largoOtroChar;
	//char* unCharRecorrer = unChar;
	//const char* otroCharRecorrer = otroChar;
	bool esMasLargo = true;
	for (int i = 0; i < masLargo; i++)
	{
		if (unChar[i] != otroChar[i])
		{
			return false;
		}
	}
	return true;
}

//PRE: todos los parámetros son válidos:
// - nroE y nroA existen, corresponden a estudiante y materia registrados en el sistema,
// - 0 >= nota >= 100,
// - fecha tiene el formato “aaaammdd” y o bien no existe en el sistema (y se asignará a la
// materia nroA), o si ya existe, corresponde a un examen de la materia nroA
//POS: agrega el registro del examen realizado por el estudiante nroE de la materia nroA, en la
//fecha dada, con la nota obtenida. Si ya existe un registro para ese estudiante en esa materia y
//fecha, se actualiza la nota resultado del examen 
void actualizarExamen(Bedelia& b, unsigned int nroE, unsigned int nroA, const char* fecha, int nota) {
	int hashedEstudiante = hashing(nroE, b->cantidadEstudiantes);
	Estudiante* lista = b->estudiantes[hashedEstudiante];
	bool modifique = false;
	while (lista != nullptr && modifique == false) {
		if (lista->idEstudiante == nroE) {
			if(lista->examenes != nullptr) {
				Examen* listaRecorrer = lista->examenes;
				while (listaRecorrer != nullptr)
				{
					if (esIgual(listaRecorrer->fecha, fecha) && listaRecorrer->idMateria == nroA) {
						listaRecorrer->nota = nota;
						modifique = true;
						break;
					}
					listaRecorrer = listaRecorrer->sig;
				}
			}
			if (!modifique) {
				Examen* nuevoExamen = new Examen();
				nuevoExamen->fecha = copiarStringCompleto(fecha, largoPalabra(fecha));
				nuevoExamen->idMateria = nroA;
				nuevoExamen->nota = nota;
				nuevoExamen->sig = lista->examenes;
				lista->examenes = nuevoExamen;
				lista->cantExamenes++;
				if (nota >= 70) {
					lista->cantexamenesAprobados++;
				}
				else {
					lista->cantexamenesReprobados++;
				}
			}
			
		}
		lista = lista->sig;
	}
	/*lista = b->estudiantes[hashedEstudiante];
	if (!modifique) {
		while (lista)
		{

		}
		if (lista->idEstudiante == nroE) {
			
		}
		lista = lista->sig;
	}*/
}

bool obtenerStringMenor(char* unChar, const char* otroChar)
{
	int largoUnChar = largoPalabra(unChar);
	int largoOtroChar = largoPalabra(otroChar);
	int masLargo = (largoUnChar > largoOtroChar) ? masLargo = largoUnChar : masLargo = largoOtroChar;
	//char* unCharRecorrer = unChar;
	//const char* otroCharRecorrer = otroChar;
	bool esMasLargo = true;
	for (int i = 0; i < masLargo; i++)
	{
		if (unChar[i] != otroChar[i])
		{
			return unChar[i] < otroChar[i];
		}
	}
	return esMasLargo;
}


void listaOrdenadaSelectionSort(Examen* l)
{
	if (l != nullptr) {
		Examen* menor = l;
		Examen* aux = l;

		while (aux != NULL) {
			if (obtenerStringMenor(aux->fecha,menor->fecha)) {
				menor = aux;
			}
			aux = aux->sig;
		}
		char* fechaAux = l->fecha;
		int materiaAux = l->idMateria;
		int notaAux = l->nota;
		l->fecha = menor->fecha;
		l->idMateria = menor->idMateria;
		l->nota = menor->nota;
		menor->fecha = fechaAux;
		menor->idMateria = materiaAux;
		menor->nota = notaAux;

		//menor = l->sig;

		listaOrdenadaSelectionSort(l->sig);
	}
}

// ---------------------- ORDEN(1) peor caso-----------------------------------
//PRE: el parámetro nroE es válido
//POS: muestra por pantalla la escolaridad del estudiante nroE, listando todas las materias en
//las que registró examen, con fecha y nota en cada caso, ordenados por fecha desde la más
//antigua a la más reciente 
void escolaridadEstudiante(Bedelia b, unsigned int nroE) {
	int hashedEstudiante = hashing(nroE, b->cantidadEstudiantes);
	Estudiante* lista = b->estudiantes[hashedEstudiante];

	while (lista != nullptr)
	{
		if (lista->idEstudiante == nroE) {
			cout << "Escolaridad del estudiante " << nroE << ": " << lista->nombre << endl;
			if (lista->examenes == nullptr) {
				cout << "El estudiante no rindio examenes.";
			}
			else {
				Examen* aOrdenar = lista->examenes;
				listaOrdenadaSelectionSort(aOrdenar);
				while (aOrdenar != nullptr)
				{
					//Fecha: 20190210 - Materia 52: Programacion 1 - Nota: 40
					cout << "Fecha: " << aOrdenar->fecha << " - Materia " << aOrdenar->idMateria << ": " << b->materias[aOrdenar->idMateria]->nombre << " - Nota: " << aOrdenar->nota << endl;
					aOrdenar = aOrdenar->sig;
				}
			}
		}
		lista = lista->sig;
	}

	//Escolaridad del estudiante NROESTUDIANTE: NOMBREESTUDIANTE 


}

// ---------ORDEN(n) peor caso, n cantidad de instancias de examen de la materia dada------------------
//PRE: el parámetro nroA es válido
//POS: muestra por pantalla la cantidad de aprobados y no aprobados en cada fecha de examen de la
//materia, ordenados por fecha desde la más antigua hasta la más reciente 
void estadisticaMateria(Bedelia b, unsigned int nroA) {
	//examenes por fecha
}

//PRE: -
//POS: destruye el registro de bedelía b, liberando la memoria utilizada 
void destruir(Bedelia& b) {
	// NO IMPLEMENTADA
}

#endif

