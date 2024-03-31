//
// Created by jorge on 11/11/2023.
//
#include "cama.h"
#include <vector>
#include <string>
using namespace std;
#ifndef ELMOCHILERORESERVA_HABITACION_H
#define ELMOCHILERORESERVA_HABITACION_H
class Habitacion{
private:
    int numero;
    float tarifa;
    string tipo;
    int piso_ubicacion;
    int capacidad;
    Cama* cama;
public:
    Habitacion(int _numero, float _tarifa, string _tipo, int _piso_ubicaion,int _capacidad, Cama* _cama);
    int get_numero();
    float get_tarifa();
    string get_tipo();
    int get_piso_ubicacion();
    int get_capacidad();
    Cama* get_cama();

    void set_capacidad(int _capacidad);


};

class Habitacion_privada : public Habitacion{
private:
    string tipo_bano;
public:
    Habitacion_privada(int numero, float tarifa, string tipo, int pisoUbicaion, int capacidad,
                       string _tipo_bano,Cama* _cama);
    string get_tipo_bano();
};

class Habitacion_compartida : public Habitacion{
private:
    string solomujeres;
    bool num_cama_igual_8;
public:
    Habitacion_compartida(int numero, float tarifa, string tipo, int pisoUbicaion, int capacidad,
                       string _solomujeres, Cama* _cama, bool _num_cama_igual_8);
    string get_solomujeres();
    bool get_num_cama_igual_8();
};



#endif //ELMOCHILERORESERVA_HABITACION_H
