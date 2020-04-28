#include <iostream>
#include <fstream>
#include <string.h>


using namespace std; //Para ir mostrando datos.


void sumar_arreglo(int arreglo[][5]){
    for (int i = 0; i<5;i++){
        arreglo[2][i] = arreglo[1][i] + arreglo[0][i];
    }
}

void restar_arreglo(int arreglo[][5]){
    for (int i = 0; i<5;i++){
        arreglo[3][i] = arreglo[0][i] - arreglo[1][i];
    }
}

void multiplicar_arreglo(int arreglo[][5]){
    for (int i = 0; i<5;i++){
        arreglo[4][i] = arreglo[0][i] * arreglo[1][i];
    }
}

float promedio (int arr[][5])
{
    int sum = 0;

    for (int fil = 0; fil < 5; fil++)
    {
        for (int col = 0; col < 5; col++)
        {
            sum = sum + arr[fil][col];
        }
        
    }
    return (float) sum / 25;
    
}

void print_resultado(int arr[][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << promedio(arr)<< endl;
}

int main(int argc, char **argv){
    //Arreglo que nos piden
    int array[5][5], i = 0,j = 0; 

    //Variables para guardar datos del archivo
    char linea[100];
    char* particion;

    for (int i = 0; i < 5; i++) // Inicializar Array
    {
        for (int j = 0; j < 5; j++)
        {
            array[i][j] = 0;
        }
    }
    
	
	//Lectura de archivo
    ifstream archivo;
    archivo.open(argv[1]);
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
        cout<<"No se pudo abrir el archivo." << endl;
    }

    sumar_arreglo(array); //Aqui termina parte de Juan...
    restar_arreglo(array); 
    multiplicar_arreglo(array);
    print_resultado(array);
    
    
    return 0;
}