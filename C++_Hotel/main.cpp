#include <iostream>
#include <string>
#include <vector>
#include "hostel.h"

using namespace std;

int main() {
    string n;
    Hostel hostel;
    hostel.cargar_habitaciones();
    hostel.Menu();
    return 0;
}
