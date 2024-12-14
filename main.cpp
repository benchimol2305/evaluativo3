#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

struct Estudiante {
    string nombre;
    string edad;
};

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

int main() {
    int opcion;
    Estudiante estudiante;
    string nombreViejo;

    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Mostrar estudiantes" << endl;
        cout << "2. Agregar estudiante" << endl;
        cout << "3. Actualizar estudiante" << endl;
        cout << "4. Eliminar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                leerEstudiantes();
                break;
            case 2:
                cout << "Ingrese el nombre del estudiante: ";
                getline(cin, estudiante.nombre);
                cout << "Ingrese la edad del estudiante: ";
                cin >> estudiante.edad;
                cin.ignore(); 
                agregarEstudiante(estudiante);
                cout << "Estudiante agregado correctamente." << endl;
                break;
            case 3:
                cout << "Ingrese el nombre del estudiante a actualizar: ";
                getline(cin, nombreViejo);
                cout << "Ingrese el nuevo nombre del estudiante: ";
                getline(cin, estudiante.nombre);
                cout << "Ingrese la nueva edad del estudiante: ";
                cin >> estudiante.edad;
                cin.ignore();
                actualizarEstudiante(nombreViejo, estudiante);
                cout << "Estudiante actualizado correctamente." << endl;
                break;
            case 4:
                cout << "Ingrese el nombre del estudiante a eliminar: ";
                getline(cin, estudiante.nombre);
                eliminarEstudiante(estudiante.nombre);
                cout << "Estudiante eliminado correctamente." << endl;
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida, por favor intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}
