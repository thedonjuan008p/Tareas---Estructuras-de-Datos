#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char **argv)
{

    string fll_entry;

    ifstream entrada;
    entrada.open(argv[1]);

    if(!entrada.is_open()) /* Verificar que el archivo fue abierto */
    {   
        cout << "Error al leer archivo " << argv[1] << endl;
        return 0;
    }

    string frst_delimeter = " ";
    string scnd_delimeter = ";";

    while (true)
    {
        getline(cin,fll_entry);
        cout << fll_entry << endl;

        int delim_pos = fll_entry.find(frst_delimeter);
        string prtial_entry = fll_entry.substr(0, delim_pos);
        cout << prtial_entry;
        fll_entry.erase(0, delim_pos + frst_delimeter.length());
        cout << fll_entry;

        if (prtial_entry == "info")
        {
            cout << "info" << endl;
        }
        else if (prtial_entry == "print")
        {
            cout << "print" << endl;
        }
        else if (prtial_entry == "add")
        {
            cout << "add" << endl;
        }
        else if (prtial_entry == "remove")
        {
            cout << "remove" << endl;
        }
        else if (prtial_entry == "exit")
        {
            cout << "exit" << endl;
            break;
        }
        else
        {
            cout << "Comando no valido" << endl;
        }
        
    } 
    

    return 0;

}