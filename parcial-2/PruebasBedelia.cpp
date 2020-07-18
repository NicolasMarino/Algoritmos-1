#include "PruebasBedelia.h"

void pruebasBedeliaPriv(Prueba* pruebaConcreta);

void pruebasBedelia(Prueba* pruebaConcreta) {
	pruebaConcreta->mImpresion.iniciarSeccion("PRUEBAS Bedelia");
	pruebasBedeliaPriv(pruebaConcreta);
	pruebaConcreta->mImpresion.cerrarSeccion("PRUEBAS Bedelia");
}

void pruebasBedeliaPriv(Prueba* pruebaConcreta)
{
	Bedelia b = crearBedelia(10);

	actualizarEstudiante(b, "Juan A.", 100);
	actualizarEstudiante(b, "Jose B.", 200);
	actualizarEstudiante(b, "Ana C.", 300);
	actualizarEstudiante(b, "Lucia D.", 400);
	actualizarEstudiante(b, "Jose E.", 500); 
	actualizarEstudiante(b, "Juan F.", 600);
	actualizarEstudiante(b, "Pedro G.", 700); 
	actualizarEstudiante(b, "Diego H.", 800);

	actualizarMateria(b, "Base de datos", 12); 
	actualizarMateria(b, "Algebra lineal", 21);
	actualizarMateria(b, "Programacion 1", 52);
	actualizarMateria(b, "Programacion 2", 53);
	actualizarMateria(b, "Algoritmos 1", 73);
	actualizarMateria(b, "Algoritmos 2", 74); 
	actualizarMateria(b, "Probabilidad y estadistica", 95);
	actualizarMateria(b, "Matematica discreta", 200);
	actualizarMateria(b, "Logica", 1);

	pruebaConcreta->ver3("Cargo estudiantes y materias (sin salida)");

	escolaridadEstudiante(b, 100); 
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 100");

	estadisticaMateria(b, 12); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 12");

	//carga examenes 
	actualizarExamen(b, 100, 52, "20190210", 40);
	actualizarExamen(b, 100, 52, "20200529", 86);
	actualizarExamen(b, 100, 73, "20200223", 80);
	actualizarExamen(b, 100, 95, "20200510", 62);
	actualizarExamen(b, 100, 95, "20200630", 78);
	pruebaConcreta->ver3("Cargo examenes (sin salida)"); 
	cout << endl;

	escolaridadEstudiante(b, 100); 
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 100"); 
	cout << endl;

	estadisticaMateria(b, 95); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 95");
	cout << endl;

	actualizarExamen(b, 300, 95, "20190528", 78);
	actualizarExamen(b, 300, 21, "20200204", 40);
	actualizarExamen(b, 300, 21, "20200628", 86);
	actualizarExamen(b, 300, 52, "20200529", 80);

	actualizarExamen(b, 600, 95, "20190528", 78);
	actualizarExamen(b, 600, 21, "20190714", 45);
	actualizarExamen(b, 600, 21, "20200628", 84);
	actualizarExamen(b, 600, 52, "20200529", 80);
	actualizarExamen(b, 600, 53, "20190422", 80);

	actualizarExamen(b, 200, 95, "20200209", 58);
	actualizarExamen(b, 200, 95, "20200630", 95);
	actualizarExamen(b, 200, 73, "20190208", 84);
	actualizarExamen(b, 200, 52, "20200529", 81);

	actualizarExamen(b, 400, 95, "20200630", 76);
	actualizarExamen(b, 400, 21, "20190714", 75);
	actualizarExamen(b, 400, 52, "20190210", 70);
	actualizarExamen(b, 400, 53, "20200509", 80); 
	actualizarExamen(b, 400, 73, "20200223", 100);
	actualizarExamen(b, 400, 1, "20200512", 100);

	actualizarExamen(b, 800, 200,"20190719", 60);
	actualizarExamen(b, 800, 52, "20190210", 60);
	actualizarExamen(b, 800, 73, "20200223", 10);
	actualizarExamen(b, 800, 21, "20190714", 55);
	actualizarExamen(b, 800, 95, "20200630", 66);
	actualizarExamen(b, 800, 95, "20200510", 50);
	actualizarExamen(b, 800,  1, "20200512", 69);

	//escolaridad ESTUDIANTES
	escolaridadEstudiante(b, 100); 
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 100"); cout << endl;
	escolaridadEstudiante(b, 200); 
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 200"); cout << endl;
	escolaridadEstudiante(b, 300); 
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 300"); cout << endl;
	escolaridadEstudiante(b, 400); 
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 400"); cout << endl;
	escolaridadEstudiante(b, 500); 
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 500"); cout << endl;
	escolaridadEstudiante(b, 600); 
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 600"); cout << endl;
	escolaridadEstudiante(b, 700); 
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 700"); cout << endl;
	escolaridadEstudiante(b, 800); 
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 800"); cout << endl;

	//estadisticas MATERIAS
	estadisticaMateria(b, 1); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 1"); cout << endl;
	estadisticaMateria(b, 12); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 12"); cout << endl;
	estadisticaMateria(b, 21); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 21"); cout << endl;
	estadisticaMateria(b, 52); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 52"); cout << endl;
	estadisticaMateria(b, 53); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 53"); cout << endl;
	estadisticaMateria(b, 73); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 73"); cout << endl;
	estadisticaMateria(b, 74); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 74"); cout << endl;
	estadisticaMateria(b, 95); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 95"); cout << endl;
	estadisticaMateria(b, 200); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 200"); cout << endl;

	//modifica Examenes
	actualizarExamen(b, 400, 53, "20200509", 87);
	escolaridadEstudiante(b, 400);
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 400"); cout << endl;
	estadisticaMateria(b, 53); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 53"); cout << endl;
	
	actualizarExamen(b, 800, 73, "20200223", 60);
	actualizarExamen(b, 400, 73, "20200223", 81);
	escolaridadEstudiante(b, 400);
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 400"); cout << endl;
	escolaridadEstudiante(b, 800);
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 800"); cout << endl;
	estadisticaMateria(b, 73); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 73"); cout << endl;
	
	actualizarExamen(b, 800, 1, "20200512", 96); 
	escolaridadEstudiante(b, 800);
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 800"); cout << endl;
	estadisticaMateria(b, 1);
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 1"); cout << endl;
	
	actualizarExamen(b, 200, 95, "20200630", 59);
	actualizarExamen(b, 600, 95, "20190528", 68);
	escolaridadEstudiante(b, 200);
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 200"); cout << endl;
	escolaridadEstudiante(b, 600);
	pruebaConcreta->ver3("Imprimo la escolaridad del estudiante 600"); cout << endl;
	estadisticaMateria(b, 95); 
	pruebaConcreta->ver3("Imprimo la estadistica de la materia 95"); cout << endl;
	

	destruir(b);
	pruebaConcreta->ver3("Libero memoria");
}
