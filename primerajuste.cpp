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

    Particion(int _id, int _tamano) : id(_id), tamano(_tamano), ocupada(false) {}
};

class Proceso {
public:
    string nombre;
    int tamano;

    Proceso(const string& _nombre, int _tamano) : nombre(_nombre), tamano(_tamano) {}
};

int main() {
    int Windows_2 = 2000;

    cout << "Ingrese la cantidad de particiones: ";
    int cantidadParticiones;
    cin >> cantidadParticiones;

    vector<Particion> particiones;
    for (int i = 0; i < cantidadParticiones; i++) {
        cout << "Ingrese el tamano de la particion " << (i + 1) << ": ";
        int tamanoParticion;
        cin >> tamanoParticion;
        particiones.push_back(Particion(i + 1, tamanoParticion));
    }

    cout << "\nIngresar procesos:\n";
    vector<Proceso> procesos;
    for (int i = 1; i <= 4; i++) {
      
        cout << "Ingrese el nombre del proceso " << i << ": ";
        string nombreProceso;
        getline(cin, nombreProceso);
        cout << "Ingrese el tamano del proceso " << i << ": ";
        int tamanoProceso;
        cin >> tamanoProceso;
        procesos.push_back(Proceso(nombreProceso, tamanoProceso));
    }

    cout << "\n";

    for (int i = 0; i < procesos.size(); i++) {
        Proceso proceso = procesos[i];
        bool asignado = false;

        for (int j = 0; j < particiones.size(); j++) {
            Particion& particion = particiones[j];
            if (!particion.ocupada && particion.tamano >= proceso.tamano) {
                particion.ocupada = true;
                particion.nombreProceso = proceso.nombre;
                asignado = true;
                cout << proceso.nombre << " asignado a la particion " << particion.id << endl;
                break;
            }
        }

        if (!asignado) {
            cout << proceso.nombre << " no fue asignado a ninguna particion" << endl;
        }
    }

    int espacioOcupado = 0;
    for (int i = 0; i < particiones.size(); i++) {
        if (particiones[i].ocupada) {
            for (int j = 0; j < procesos.size(); j++) {
                if (particiones[i].nombreProceso == procesos[j].nombre) {
                    espacioOcupado += procesos[j].tamano;
                    break;
                }
            }
        }
    }

    if (espacioOcupado > Windows_2) {
        cout << "\nNo hay suficiente memoria para asignar todos los procesos." << endl;
    } else {
        int espacioSobrante = Windows_2 - espacioOcupado;
        cout << "\nEspacio restante de Windows 2 es de: " << espacioSobrante << " de un total de " << Windows_2 << endl;
    }

    return 0;
}

