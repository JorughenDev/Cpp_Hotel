
#ifndef ELMOCHILERORESERVA_HOSTEL_H
#define ELMOCHILERORESERVA_HOSTEL_H

#include "habitacion.h"

class Hostel{
private:
    vector<Habitacion_privada*> habitaciones_privadas;
    vector<Habitacion_compartida*> habitaciones_compartidas;
    vector<Cama*> camas_vector;
public:


    vector<string> separar_palabras(string texto);
    void cargar_habitaciones();
    void Menu();
    void reserva();
    void imprimir_camas_disponibles();
    void imprimir_camas_ocupadas();

    //getters
    vector<Habitacion_privada*> get_habitaciones_privadas();
    vector<Habitacion_compartida*> get_habitaciones_compartidas();

    ~Hostel();
};


#endif //ELMOCHILERORESERVA_HOSTEL_H
