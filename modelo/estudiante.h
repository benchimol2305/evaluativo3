#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Estudiante {
    string nombre;
    int edad;
};

void leerEstudiantes();
void agregarEstudiante(const Estudiante& estudiante);
void actualizarEstudiante(const string& nombreViejo, const Estudiante& estudianteNuevo);
void eliminarEstudiante(const string& nombre);

#endif // ESTUDIANTE_H
