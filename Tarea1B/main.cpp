#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>


using namespace std; //Para ir mostrando datos.

void sumar_arreglo(int arreglo[][5]){
    for (int i = 0; i<5;i++){
        arreglo[2][i] = arreglo[1][i] + arreglo[0][i];
    }
}

int main(void){

    //Arreglo que nos piden
    int array[5][5], i = 0,j = 0; 

    //Variables para guardar datos del archivo
    char linea[100];
    char* particion;
	
	//Lectura de archivo
    ifstream archivo;
    archivo.open("archivo.txt", ios::out);
    if (archivo.is_open()){
        while (!archivo.eof()){
            archivo.getline(linea,100);
            
            //Guardado de datos en el arreglo.

            particion = strtok(linea, " ");
            int valor = atoi(particion);
            array[i][j] = valor;
            
            j=1;
            while (particion != NULL){
                if (j==5 && i ==1){
                    break;
                }
                if (j==5){
                	i=1;
                	j=0;
				}
                particion = strtok(NULL," ");
                valor = atoi(particion);
                array[i][j] = atoi(particion);
                j++;
                
                
            }

        }
        
    } else{
        cout<<"No se pudo abrir el archivo.";
    }

    sumar_arreglo(array); //Aqui termina parte de Juan...
    
    
    getch(); //Para que se detenga aqui.
}