
#include "PruebasEjemploDeUsoEntrega.h"

PruebasEjemploDeUsoEntrega::PruebasEjemploDeUsoEntrega(ConductorPrueba* conductor)
:Prueba(conductor)
{

}

PruebasEjemploDeUsoEntrega::~PruebasEjemploDeUsoEntrega()
{
	
}

const char* PruebasEjemploDeUsoEntrega::getNombre() const
{
	return "PruebasEjemploDeUsoEntrega";
}

void PruebasEjemploDeUsoEntrega::correrPruebaConcreta()
{
	pruebasBedelia(this);
}



