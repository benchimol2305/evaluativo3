#include "Vista.h"

void mostrarEstudiantes() {
    leerEstudiantes();
}

void agregarEstudianteVista() {
    Estudiante estudiante;
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, estudiante.nombre);
    cout << "Ingrese la edad del estudiante: ";
    cin >> estudiante.edad;
    cin.ignore(); // Limpiar el buffer de entrada
    agregarEstudiante(estudiante);
    cout << "Estudiante agregado correctamente." << endl;
}

void actualizarEstudianteVista() {
    string nombreViejo;
    Estudiante estudiante;
    cout << "Ingrese el nombre del estudiante a actualizar: ";
    getline(cin, nombreViejo);
    cout << "Ingrese el nuevo nombre del estudiante: ";
    getline(cin, estudiante.nombre);
    cout << "Ingrese la nueva edad del estudiante: ";
    cin >> estudiante.edad;
    cin.ignore(); // Limpiar el buffer de entrada
    actualizarEstudiante(nombreViejo, estudiante);
    cout << "Estudiante actualizado correctamente." << endl;
}

void eliminarEstudianteVista() {
    string nombre;
    cout << "Ingrese el nombre del estudiante a eliminar: ";
    getline(cin, nombre);
    eliminarEstudiante(nombre);
    cout << "Estudiante eliminado correctamente." << endl;
}
