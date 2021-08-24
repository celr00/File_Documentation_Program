#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){

    string name;
    cout << "Please enter the name of the program you want to document: "<<endl;
    cin >> name;

    ifstream source;
    source.open(name+".cpp");
    ofstream fhtml;
    fhtml.open(name+".html");

    fhtml << "<!DOCTYPE html>" <<endl;
    fhtml << "<html lang=\"en\">" <<endl;
    fhtml << "<head>" <<endl;
    fhtml << "<meta charset=\"UTF-8\">" <<endl;
    fhtml << "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">" <<endl;
    fhtml << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" <<endl;
    fhtml << "<title" << name+"'s Documentation"<< "</title>"<<endl;
    fhtml << "</head>" <<endl;
    fhtml << "<body>" <<endl;

    string line;

    bool active = false;
    while(getline(source, line)){

        if(line.find("/**") != -1){
            active = true;
        }
        if(line.find("*/") != -1){
            active = false;
        }

        if(active){
            //salida << linea <<endl;
            int index;
            string info;

            if(line.find("@progName")!= -1){

                index = line.find("@progName");
                info = line.substr(index+10);

                fhtml << "<h2>" <<endl;
                fhtml << "Program: " <<info <<endl;
                fhtml << "</h2>" <<endl;

            }else if(line.find("@author")!= -1){

                index = line.find("@author");
                info = line.substr(index+8);

                fhtml << "<strong> Autor: </strong>" << info <<"<br>"<<endl;

            }else if(line.find("@date")!= -1){

                index = line.find("@date");
                info = line.substr(index+6);

                fhtml << "<strong> Date: </strong>" << info <<"<br>"<<endl;

            }else if(line.find("@funcName")!= -1){

                index = line.find("@funcName");
                info = line.substr(index+9);

                fhtml << "<h3>" <<endl;
                fhtml << "<hr><br> Function: " << info <<"<br>"<<endl;
                fhtml << "</h2>" <<endl;

            }else if(line.find("@desc")!= -1){

                index = line.find("@desc");
                info = line.substr(index+6);

                fhtml << "<strong> Description: </strong>" << info <<"<br>"<<endl;

            }else if(line.find("@param")!= -1){

                index = line.find("@param");
                info = line.substr(index+7);

                fhtml << "<strong> Parameters: </strong>" << info <<"<br>"<<endl;

            }else if(line.find("@return")!= -1){

                index = line.find("@return");
                info = line.substr(index+8);

                fhtml << "<strong> Return: </strong>" << info <<"<br>"<<endl;
            }
        }
    }

    fhtml << "</body>" <<endl;
    fhtml << "</html>" <<endl;

    source.close();
    fhtml.close();

    return 0;
}
