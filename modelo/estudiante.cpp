#include "Estudiante.h"

void leerEstudiantes() {
    ifstream file("estudiantes.csv");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nombre;
        int edad;
        ss >> nombre >> edad;
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
    file.close();
}

void agregarEstudiante(const Estudiante& estudiante) {
    ofstream file("estudiantes.csv", ios::app);
    file << estudiante.nombre << " " << estudiante.edad << endl;
    file.close();
}

void actualizarEstudiante(const string& nombreViejo, const Estudiante& estudianteNuevo) {
    ifstream file("estudiantes.csv");
    ofstream temp("temp.csv");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nombre;
        int edad;
        ss >> nombre >> edad;
        if (nombre == nombreViejo) {
            temp << estudianteNuevo.nombre << " " << estudianteNuevo.edad << endl;
        } else {
            temp << nombre << " " << edad << endl;
        }
    }
    file.close();
    temp.close();
    remove("estudiantes.csv");
    rename("temp.csv", "estudiantes.csv");
}

void eliminarEstudiante(const string& nombre) {
    ifstream file("estudiantes.csv");
    ofstream temp("temp.csv");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nombreActual;
        int edad;
        ss >> nombreActual >> edad;
        if (nombreActual != nombre) {
            temp << nombreActual << " " << edad << endl;
        }
    }
    file.close();
    temp.close();
    remove("estudiantes.csv");
    rename("temp.csv", "estudiantes.csv");
}
