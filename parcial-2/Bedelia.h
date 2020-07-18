#pragma once

// Elegir la implementacion a usar (solo 1 a la vez):
#define BEDELIA_IMP
//#define BEDELIA_IMP_2

#if defined(BEDELIA_IMP)
#include "BedeliaImp.h"
#elif defined(BEDELIA_IMP_2)
#include "BedeliaImp2.h"
#endif

// VER PRE Y POS DE LAS FUNCIONES EN EL PDF DE LA LETRA

Bedelia crearBedelia(unsigned int cantEstudiantes);

void actualizarEstudiante(Bedelia& b, const char* nombreE, unsigned int id);

void actualizarMateria(Bedelia& b, const char* nombreA, unsigned int id);

void actualizarExamen(Bedelia &b, unsigned int nroE, unsigned int nroA, const char* fecha, int nota);

void escolaridadEstudiante(Bedelia b, unsigned int nroE);

void estadisticaMateria(Bedelia b, unsigned int nroA);

void destruir(Bedelia& b);

