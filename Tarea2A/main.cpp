#include <iostream>
#include <fstream>


using namespace std;

string split_info(string s) //Separar String de agregado de datos
{


}

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

        int delim_pos = fll_entry.find(frst_delimeter);
        string prtial_entry = fll_entry.substr(0, delim_pos); // Primera palabra ingresada
        fll_entry.erase(0, delim_pos + frst_delimeter.length()); //Resto de la palabra ingresada

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

            try
            {

            delim_pos = fll_entry.find(frst_delimeter);
            string temp = fll_entry.substr(0, delim_pos);
            int index = stoi(temp);
            fll_entry.erase(0, delim_pos + frst_delimeter.length());

            string cancion;
            delim_pos = fll_entry.find(scnd_delimeter);
            temp = fll_entry.substr(0, delim_pos);
            fll_entry.erase(0, delim_pos + scnd_delimeter.length());
            cancion = temp;

            string artista;
            delim_pos = fll_entry.find(scnd_delimeter);
            temp = fll_entry.substr(0, delim_pos);
            fll_entry.erase(0, delim_pos +  scnd_delimeter.length());
            artista = temp;

            int duracion = stoi(fll_entry);

            }
            catch (int e)
            {
                cout << "Ha ocurrido un error " << e;
            }



        }
        else if (prtial_entry == "remove")
        {
            int index = stoi(fll_entry.substr(0, delim_pos));
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