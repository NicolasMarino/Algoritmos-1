#pragma once

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "PruebasAuxEntrega.h"
#include "PruebasAuxDefensa.h"

#include "PruebasBedelia.h"

class PruebasEjemploDeUsoEntrega : public Prueba  
{

public:
	PruebasEjemploDeUsoEntrega(ConductorPrueba* conductor);
	virtual ~PruebasEjemploDeUsoEntrega();
	virtual void correrPruebaConcreta();

protected:
	virtual const char* getNombre() const;

private:
	ManejadorImpresionPrueba mImpresion;
};
