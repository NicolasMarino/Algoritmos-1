#include "Bedelia.h"

#ifdef BEDELIA_IMP

struct Materia {
	char* nombre;
};

struct Examen {
	char* fecha;
	Materia* materia;
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
};

struct _cabezalBedelia {
	Materia** materias;
	Estudiante** estudiantes;
	Examen* examenes;
	unsigned int cantidadEstudiantes;
};

Bedelia crearBedelia(unsigned int cantEstudiantes) {
	Bedelia nuevaBedelia = new _cabezalBedelia();
	nuevaBedelia->estudiantes = new Estudiante * [cantEstudiantes]();
	nuevaBedelia->examenes = nullptr;
	nuevaBedelia->cantidadEstudiantes = cantEstudiantes;
	return nuevaBedelia;
}

// ---------------------- ORDEN(1) promedio / HASH SI O SI-----------------------------------
//PRE: -
//POS: asocia el nombre de estudiante nombreE al identificador dado, independientemente de si
//éste existía ya o no, en el sistema de bedelía b 
void actualizarEstudiante(Bedelia& b, const char* nombreE, unsigned int id) {
	
}

// ---------------------- ORDEN(1) peor caso, si o si un array de 200.-----------------------------------
//PRE: el parámetro id es válido
//POS: asocia el nombre de la materia nombreA al identificador dado, independientemente de
//si ésta existía ya o no, en el sistema de bedelía b 
void actualizarMateria(Bedelia& b, const char* nombreA, unsigned int id) {
	// NO IMPLEMENTADA
}

// ---------------------- ORDEN(1) peor caso-----------------------------------
//PRE: todos los parámetros son válidos:
// - nroE y nroA existen, corresponden a estudiante y materia registrados en el sistema,
// - 0 >= nota >= 100,
// - fecha tiene el formato “aaaammdd” y o bien no existe en el sistema (y se asignará a la
// materia nroA), o si ya existe, corresponde a un examen de la materia nroA
//POS: agrega el registro del examen realizado por el estudiante nroE de la materia nroA, en la
//fecha dada, con la nota obtenida. Si ya existe un registro para ese estudiante en esa materia y
//fecha, se actualiza la nota resultado del examen 
void actualizarExamen(Bedelia& b, unsigned int nroE, unsigned int nroA, const char* fecha, int nota) {
	// NO IMPLEMENTADA
}

// ---------------------- ORDEN(1) peor caso-----------------------------------
//PRE: el parámetro nroE es válido
//POS: muestra por pantalla la escolaridad del estudiante nroE, listando todas las materias en
//las que registró examen, con fecha y nota en cada caso, ordenados por fecha desde la más
//antigua a la más reciente 
void escolaridadEstudiante(Bedelia b, unsigned int nroE) {
	// NO IMPLEMENTADA
}

// ---------ORDEN(n) peor caso, n cantidad de instancias de examen de la materia dada------------------
//PRE: el parámetro nroA es válido
//POS: muestra por pantalla la cantidad de aprobados y no aprobados en cada fecha de examen de la
//materia, ordenados por fecha desde la más antigua hasta la más reciente 
void estadisticaMateria(Bedelia b, unsigned int nroA) {
	// NO IMPLEMENTADA
}

//PRE: -
//POS: destruye el registro de bedelía b, liberando la memoria utilizada 
void destruir(Bedelia& b) {
	// NO IMPLEMENTADA
}

#endif

