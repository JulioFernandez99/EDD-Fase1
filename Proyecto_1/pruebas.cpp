#include <iostream>
#include <windows.h>
#include <commdlg.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
int main() {
    OPENFILENAME ofn;
    char fileName[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.lpstrFilter = "Archivos de Texto (*.txt)\0*.txt\0Todos los archivos (*.*)\0*.*\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn) == TRUE) {
        //cout << "Archivo seleccionado: " << fileName << endl;

        /*---------------------------Abriendo archivo---------------------------*/
        ifstream inputFile(fileName); // Abre el archivo para lectura

        if (!inputFile.is_open()) {
            cout << "No se pudo abrir el archivo." << endl;

        }

        string line;
        while (getline(inputFile, line)) {
            //cout << line << endl;
            cout << "---------------------------" << endl;
            //--------------------------
            istringstream ss(line);
            string token;
            vector<std::string> tokens;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }


            cout << tokens[0]<< endl;
            cout << tokens[1]<< endl;
            cout << tokens[2]<< endl;
            //--------------------------
        }

        inputFile.close(); // Cierra el archivo

    } else {
        cout << "No se seleccionó ningún archivo." <<endl;
    }



    return 0;
}
