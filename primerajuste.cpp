#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Particion {
public:
    int id;
    int tamano;
    bool ocupada;
    string nombreProceso;
};

class Proceso {
public:
    string nombre;
    int tamano;
    int particionAsignada;
};

int main() {
    vector<Particion> particiones;
    vector<Proceso> procesos;
    int cantidadParticiones, cantidadProcesos;

    cin >> cantidadParticiones;

    for (int i = 0; i < cantidadParticiones; i++) {
        int tamanoParticion;
        cin >> tamanoParticion;
        Particion particion;
        particion.id = i + 1;
        particion.tamano = tamanoParticion;
        particion.ocupada = false;
        particion.nombreProceso = "";
        particiones.push_back(particion);
    }

    cin >> cantidadProcesos;
    cin.ignore();

    for (int i = 1; i <= cantidadProcesos; i++) {
        string nombreProceso;
        int tamanoProceso;

        getline(cin, nombreProceso);
        cin >> tamanoProceso;
        Proceso proceso;
        proceso.nombre = nombreProceso;
        proceso.tamano = tamanoProceso;
        proceso.particionAsignada = -1;
        procesos.push_back(proceso);
        cin.ignore();
    }

    for (int i = 0; i < procesos.size(); i++) {
        Proceso proceso = procesos[i];
        bool asignado = false;

        for (int j = 0; j < particiones.size(); j++) {
            Particion& particion = particiones[j];
            if (!particion.ocupada && particion.tamano >= proceso.tamano) {
                particion.ocupada = true;
                particion.nombreProceso = proceso.nombre;
                proceso.particionAsignada = particion.id;
                asignado = true;
                cout << proceso.nombre << " asignado a la partici�n " << particion.id << endl;
                break;
            }
        }

        if (!asignado) {
            cout << proceso.nombre << " no fue asignado a la memoria" << endl;
        }
    }

    for (int i = 0; i < procesos.size(); i++) {
        cout << procesos[i].nombre << " - Partici�n asignada: " << procesos[i].particionAsignada << endl;
    }

    return 0;
}

