/******************************************************************************

Creare o aprire un file binario e scriverci finché 
non si inserisce la parola 'quit'.

Al termine della scrittura, stampare solamente i numeri inseriti nel file;

*******************************************************************************/
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    
    const string nomeFile = "file.dat";
    
    ifstream fileDaLeggere;
    ofstream fileDaScrivere;
    
    fileDaScrivere.open(nomeFile);
    string line;
    
    //Scrittura file
    if(fileDaScrivere.is_open()){
        do{
            cout<<"Digita cosa inserire nel file o 'quit' per uscire: ";
            cin>>line;    
            if(line == "quit"){
                cout<<"Arrivederci!"<<endl;
            }else{
                fileDaScrivere << line << endl;
            }
        }while(line != "quit");
        fileDaScrivere.close();
    }else{
        cout << "Errore di apertura file!"<<endl;
    }
    
    //Lettura File
    fileDaLeggere.open(nomeFile);
    if(fileDaLeggere.is_open()){
        char c = fileDaLeggere.get();
        //stampa carattere per carattere tutto il file
        cout<<"\nI numeri in questo file sono: ";
        while (fileDaLeggere.good()){
            if(isdigit(c)){
                cout << c << " ";
            }
            c = fileDaLeggere.get();
        }
        fileDaLeggere.close();
    }else{
        cout << "Errore di apertura file!"<<endl;
    }
    
    return 0;
}
