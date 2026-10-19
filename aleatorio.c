#include <iostream>
#include <format>
using namespace std;

/*
 * ./ejecutable [num_repeticiones] [1=Generar IP, OTRO=Generar MAC]
 */

struct IP{
    int octeto1;
    int octeto2;
    int octeto3;
    int octeto4;
};

struct MAC{
    int pareja1;
    int pareja2;
    int pareja3;
    int pareja4;
    int pareja5;
    int pareja6;
};


void aleatoriaIP(const int longi, IP ip, const bool puerto){
    int min = 0, max = 255;
    for(int i=0; i<longi;i++){
        ip.octeto1 = rand()%(max-min)+min;
        ip.octeto2 = rand()%(max-min)+min;
        ip.octeto3 = rand()%(max-min)+min;
        ip.octeto4 = rand()%(max-min)+min;

        cout << ip.octeto1 << "." << ip.octeto2 << "." << ip.octeto3 << "." << ip.octeto4;
        if(puerto){
            cout << ":" << rand()%(20000-1)+1;
        }
        cout << "\n";
    }
}

void aleatoriaMAC(const int longi, MAC mac){
    int min = 0, max = 255;
    for(int i=0; i<longi;i++){
        mac.pareja1 = rand()%(max-min)+min;
        mac.pareja2 = rand()%(max-min)+min;
        mac.pareja3 = rand()%(max-min)+min;
        mac.pareja4 = rand()%(max-min)+min;
        mac.pareja5 = rand()%(max-min)+min;
        mac.pareja6 = rand()%(max-min)+min;

        cout << hex << mac.pareja1 << ":"<< hex  << mac.pareja2 << ":"<< hex  << mac.pareja3 << ":"<< hex  << mac.pareja4<< ":"<< hex  << mac.pareja5 << ":"<< hex  << mac.pareja6 << endl;
    }
}

int main(int argc, char* argv[]) {
    //random = rand()%(max-min + 1) + min;
    srand(time(nullptr));

    if(atoi(argv[2]) == 1){
        IP ip;
        string imprimir_puerto;
        cout << "Imprimir puerto aleatorio? SI|NO" << endl;
        cin >> imprimir_puerto;
        bool puerto = false;
        if(imprimir_puerto == "SI"){
            bool puerto = true;
        }
        aleatoriaIP(atoi(argv[1]), ip, puerto);
    }else{
        MAC mac;
        aleatoriaMAC(atoi(argv[1]), mac);
    }
}
