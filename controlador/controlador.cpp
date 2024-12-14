#include "Controlador.h"

void Controladorejecutar() {
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
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
             case 1:
                leerEstudiantes();
                break;
            case 2:
                cout << "Ingrese el nombre del estudiante: ";
                getline(cin, estudiante.nombre);
                cout << "Ingrese la edad del estudiante: ";
                cin >> estudiante.edad;
                cin.ignore(); // Limpiar el buffer de entrada
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
                cin.ignore(); // Limpiar el buffer de entrada
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

}
