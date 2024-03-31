#include <iostream>
#include "string"
#include "hostel.h"
#include <fstream>
#include <cstdlib> // Para usar la función rand()
#include <ctime> // Para usar la función time()

using namespace std;

vector<Habitacion_privada *> Hostel::get_habitaciones_privadas() {
    return habitaciones_privadas;
}
vector<Habitacion_compartida *> Hostel::get_habitaciones_compartidas() {
    return  habitaciones_compartidas;
}

vector<string> Hostel::separar_palabras(string texto) {
    string delimitador = " ";
    vector<string> palabras{};

    size_t pos = 0;
    while ((pos = texto.find(delimitador)) != string::npos) {

        if(texto[pos - 1] == ','){
            palabras.push_back(texto.substr(0, pos - 1));
            texto.erase(0, pos + delimitador.length());
        }else{
            palabras.push_back(texto.substr(0, pos));
            texto.erase(0, pos + delimitador.length());
        }
    }
    palabras.push_back(texto);

    return palabras;
}

void Hostel::cargar_habitaciones() {
    string entrada_string;
    ifstream entrada;
    vector<string> palabras;
    entrada.open("registro.txt");

    while(getline(entrada,entrada_string)){
        palabras = separar_palabras(entrada_string);//convertir el string a un vector para ir agregando los atributos a las habitaciones

        if(palabras[1] == "privada"){
            Cama *cama = new Cama(palabras[4],"", false,stoi(palabras[0]));
            camas_vector.push_back(cama);
            auto *h = new Habitacion_privada(
                    stoi(palabras[0]),stof(palabras[5]),palabras[1],stoi(palabras[2]),1,palabras[3],cama);
            habitaciones_privadas.push_back(h);
        }
        if(palabras[1] == "compartida"){
            Cama *cama = new Cama("Camarote",palabras[6], false,stoi(palabras[5]));
            camas_vector.push_back(cama);
            auto *h = new Habitacion_compartida(
                    stoi(palabras[0]),stof(palabras[7]),palabras[1],stoi(palabras[2]),stoi(palabras[3]),palabras[4],cama,stoi(palabras[3]) == 8);
            habitaciones_compartidas.push_back(h);
        }

    };
    entrada.close();

}

void Hostel::Menu() {
    string eleccion;
    do {
        cout << "\nBienvenido a El Mochilero" << endl;
        cout << "Seleccione una opcion" << endl;
        cout << "1) Hacer reserva" << endl;
        cout << "2) Imprimir camas disponibles" << endl;
        cout << "3) Imprimir camas ocupadas" << endl;
        cout << "4) Salir\n" << endl;
        cin >> eleccion;
        if(eleccion == "1"){
            reserva();}
        else if(eleccion == "2"){
            imprimir_camas_disponibles();
        }
        else if (eleccion == "3"){
            imprimir_camas_ocupadas();
        }
    } while(eleccion != "4");
}

void Hostel::reserva() {
    string nombre,tipo;char sexo;bool solo_mujeres_reserva = false;
    cout << "Ingrese su nombre: " << endl;
    cin >> nombre;
    cout << "Ingrese su sexo(M/F): " << endl;
    cin >> sexo;

    cout << "Ingrese el tipo de habitacion que desee" << endl;
    cout << "privada / compartida" << endl;
    cin >> tipo;

    if(sexo == 'F' && tipo == "compartida"){
        string respuesta;
        cout << "Desea que su habitacion sea solo de mujeres(si/no)?";
        cin >> respuesta;
        solo_mujeres_reserva = (respuesta == "si");
    }

    if (tipo == "privada"){
        string _tipo_bano,_tipo_cama;
        vector<int> numeros; //alamceno las ubicaciones de habitaciones que cumplan las condiciones para luego asignar una aleatoria al que reserve
        cout <<"Ingrese el tipo de bano que desee(privado o compartido)"<<endl;
        cin >> _tipo_bano;
        cout <<"Ingrese el tipo de cama que desee(normal o king)"<<endl;
        cin >> _tipo_cama;

        for(int i=0; i < habitaciones_privadas.size(); i++){
            if(_tipo_bano == "privado" && stoi(habitaciones_privadas[i]->get_tipo_bano()) == 0 ){
                if(_tipo_cama == "normal" && habitaciones_privadas[i]->get_cama()->get_tipo() == "normal"){
                    if(habitaciones_privadas[i]->get_capacidad() > 0){numeros.push_back(i);}
                }
                if(_tipo_cama == "king" && habitaciones_privadas[i]->get_cama()->get_tipo() == "king"){
                    if(habitaciones_privadas[i]->get_capacidad() > 0){numeros.push_back(i);}                }
            }
            if(_tipo_bano == "compartido" && stoi(habitaciones_privadas[i]->get_tipo_bano()) == 1 ){
                if(_tipo_cama == "normal" && habitaciones_privadas[i]->get_cama()->get_tipo() == "normal"){
                    if(habitaciones_privadas[i]->get_capacidad() > 0){numeros.push_back(i);}                }
                if(_tipo_cama == "king" && habitaciones_privadas[i]->get_cama()->get_tipo() == "king"){
                    if(habitaciones_privadas[i]->get_capacidad() > 0){numeros.push_back(i);}                }
            }
        }

        if(numeros.size() != 0){
            srand(time(NULL));
            int num = 0 + rand() % numeros.size();
            string siono;
            cout<<"La habitacion disponible para usted es la: " <<habitaciones_privadas[numeros[num]]->get_numero()<<endl;
            cout << "El monto a pagar por esta habitacion es: " <<habitaciones_privadas[numeros[num]]->get_tarifa();
            cout <<endl << "desea pagar?(si/no)";
            cin >> siono;
            if (siono == "si"){
            int _capacidad = habitaciones_privadas[numeros[num]]->get_capacidad();
            habitaciones_privadas[numeros[num]]->set_capacidad(_capacidad-1);
            habitaciones_privadas[numeros[num]]->get_cama()->set_ocupada(true);

            cout << "Reserva exitosa en la habitacion " << habitaciones_privadas[numeros[num]]->get_numero() << endl;
            }
        }
        else{cout<<"No se encuentran habitaciones acorde a tus datos :(\n";}
    }


    else if(tipo == "compartida"){
        int numero_camas;
        vector<int> numeros;
        cout <<"Ingrese si desea una habitacion con 4 o 8 camas?";
        cin >> numero_camas;
        for (int i = 0; i < habitaciones_compartidas.size(); ++i) {

            if(solo_mujeres_reserva && habitaciones_compartidas[i]->get_solomujeres() == "1"){
                if(numero_camas == 8 && habitaciones_compartidas[i]->get_num_cama_igual_8()){
                    if(habitaciones_compartidas[i]->get_capacidad() > 0){numeros.push_back(i);}
                }
                else if(numero_camas == 4 && !habitaciones_compartidas[i]->get_num_cama_igual_8()){
                    if(habitaciones_compartidas[i]->get_capacidad() > 0){numeros.push_back(i);}
                }
            }
            else if(!solo_mujeres_reserva && habitaciones_compartidas[i]->get_solomujeres() == "0"){
                if(numero_camas == 8 && habitaciones_compartidas[i]->get_num_cama_igual_8()){
                    if(habitaciones_compartidas[i]->get_capacidad() > 0){numeros.push_back(i);}
                }
                else if(numero_camas == 4 && !habitaciones_compartidas[i]->get_num_cama_igual_8()){
                    if(habitaciones_compartidas[i]->get_capacidad() > 0){numeros.push_back(i);}
                }
            }
        }

        if(numeros.size() != 0){
            srand(time(NULL));
            int num = 0 + rand() % numeros.size();
            string siono;
            cout<<"La habitacion disponible para usted es la: " <<habitaciones_compartidas[numeros[num]]->get_numero()<<endl;
            cout << "El monto a pagar por esta habitacion es: " <<habitaciones_compartidas[numeros[num]]->get_tarifa();
            cout <<endl << "desea pagar?(si/no)";
            cin >> siono;
            if (siono == "si"){
                int _capacidad = habitaciones_compartidas[numeros[num]]->get_capacidad();
                int numero_h = habitaciones_compartidas[numeros[num]]->get_numero();

                for (int i = 0; i < habitaciones_compartidas.size(); ++i) {
                    if (habitaciones_compartidas[i]->get_numero() == numero_h){
                        habitaciones_compartidas[i]->set_capacidad(_capacidad-1);
                    }
                }
                habitaciones_compartidas[numeros[num]]->get_cama()->set_ocupada(true);

                cout << "Reserva exitosa en la habitacion " << habitaciones_compartidas[numeros[num]]->get_numero() << endl;
                cout << "Su cama es la numero " << habitaciones_compartidas[numeros[num]]->get_cama()->get_numero() << endl;
            }
        }
        else{cout<<"No se encuentran habitaciones acorde a tus datos :(\n";}

    }
    else{
        cout << "No hay habitaciones." << endl;
    }

}

void Hostel::imprimir_camas_disponibles() {
    cout <<"\n Las camas disponibles son: \n";
    for(int i = 0; i < camas_vector.size();i++){
        if (!camas_vector[i]->get_ocupada()){
            cout << "Cama ";
            if (camas_vector[i]->get_tipo() == "Camarote"){
                cout <<camas_vector[i]->get_numero() << " " <<camas_vector[i]->get_ubicacion();
            }
            else{cout<< "de la habitacion numero " << camas_vector[i]->get_numero();}
            cout << endl;
        }
    }
    cout <<"\nSon en total " << camas_vector.size() <<"\n";
}
void Hostel::imprimir_camas_ocupadas() {
    cout <<"\n Las camas ocupadas son: \n";
    for(int i = 0; i < camas_vector.size();i++){
        if (camas_vector[i]->get_ocupada()){
            cout << "Cama ";
            if (camas_vector[i]->get_tipo() == "Camarote"){
                cout <<camas_vector[i]->get_numero() << " " <<camas_vector[i]->get_ubicacion();
            }
            else{cout<< "de la habitacion numero " << camas_vector[i]->get_numero();}
            cout << endl;
        }
    }
}

Hostel::~Hostel() {
    for (int i = 0; i < habitaciones_privadas.size(); ++i) {
        delete habitaciones_privadas[i];
    }
    for (int i = 0; i < habitaciones_compartidas.size(); ++i) {
        delete habitaciones_compartidas[i];
    }
    for (int i = 0; i < camas_vector.size(); ++i) {
        delete camas_vector[i];
    }
    habitaciones_privadas.clear();
    habitaciones_compartidas.clear();
    camas_vector.clear();
}


