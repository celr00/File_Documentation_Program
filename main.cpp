#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){

    string name;
    cout << "Please enter the name of the program you want to document: "<<endl;
    cin >> name;

    ifstream entrada;
    entrada.open("programs/"+name+".cpp");
    ofstream salida;
    salida.open("txt_files/"+name+".txt");

    string linea;

    while(getline(entrada, linea)){
        salida << linea <<endl;
    }

    entrada.close();
    salida.close();

    ifstream ftexto;
    ftexto.open("txt_files/"+name+".txt");
    ofstream fhtml;
    fhtml.open("html/"+name+".html");

    fhtml << "<!DOCTYPE html>" <<endl;
    fhtml << "<html lang=\"en\">" <<endl;
    fhtml << "<head>" <<endl;
    fhtml << "<meta charset=\"UTF-8\">" <<endl;
    fhtml << "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">" <<endl;
    fhtml << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" <<endl;
    fhtml << "<title" << name+"'s Documentation"<< "</title>"<<endl;
    fhtml << "</head>" <<endl;
    fhtml << "<body>" <<endl;

    while(getline(ftexto, linea)){
        //salida << linea <<endl;
        int index;
        string info;

        if(linea.find("@progName")!= -1){

            index = linea.find("@progName");
            info = linea.substr(index+10);

            fhtml << "<h2>" <<endl;
            fhtml << "Program: " <<info <<endl;
            fhtml << "</h2>" <<endl;

        }else if(linea.find("@author")!= -1){

            index = linea.find("@author");
            info = linea.substr(index+8);

            fhtml << "<strong> Autor: </strong>" << info <<"<br>"<<endl;

        }else if(linea.find("@date")!= -1){

            index = linea.find("@date");
            info = linea.substr(index+6);

            fhtml << "<strong> Date: </strong>" << info <<"<br>"<<endl;

        }else if(linea.find("@funcName")!= -1){

            index = linea.find("@funcName");
            info = linea.substr(index+9);

            fhtml << "<h3>" <<endl;
            fhtml << "<hr><br> Function: " << info <<"<br>"<<endl;
            fhtml << "</h2>" <<endl;

        }else if(linea.find("@desc")!= -1){

            index = linea.find("@desc");
            info = linea.substr(index+6);

            fhtml << "<strong> Description: </strong>" << info <<"<br>"<<endl;

        }else if(linea.find("@param")!= -1){

            index = linea.find("@param");
            info = linea.substr(index+7);

            fhtml << "<strong> Parameters: </strong>" << info <<"<br>"<<endl;

        }else if(linea.find("@return")!= -1){

            index = linea.find("@return");
            info = linea.substr(index+8);

            fhtml << "<strong> Return: </strong>" << info <<"<br>"<<endl;
        }
    }

    fhtml << "</body>" <<endl;
    fhtml << "</html>" <<endl;

    ftexto.close();
    fhtml.close();

    return 0;
}
