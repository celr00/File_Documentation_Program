#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){

    string nombre;
    cout << "Escribe el nombre del archivo que quieres documentar: "<<endl;
    cin >> nombre;

    ifstream entrada;
    entrada.open("entradas/"+nombre+".cpp");
    ofstream salida;
    salida.open("texto/"+nombre+".txt");

    string linea;

    while(getline(entrada, linea)){
        salida << linea <<endl;
    }

    entrada.close();
    salida.close();

    ifstream ftexto;
    ftexto.open("texto/"+nombre+".txt");
    ofstream fhtml;
    fhtml.open("html/"+nombre+".html");

    fhtml << "<!DOCTYPE html>" <<endl;
    fhtml << '<html lang="en">' <<endl;
    fhtml << "<head>" <<endl;
    fhtml << '<meta charset="UTF-8">' <<endl;
    fhtml << '<meta http-equiv="X-UA-Compatible" content="IE=edge">' <<endl;
    fhtml << '<meta name="viewport" content="width=device-width, initial-scale=1.0">' <<endl;
    fhtml << '<title>' << nombre+"'s Documentation"<< '</title>'<<endl;
    fhtml << "</head>" <<endl;
    fhtml << "<body>" <<endl;

    while(getline(ftexto, linea)){
        salida << linea <<endl;
    }

    fhtml << "</body>" <<endl;
    fhtml << "</html>" <<endl;

    ftexto.close();
    fhtml.close();

    return 0;
}