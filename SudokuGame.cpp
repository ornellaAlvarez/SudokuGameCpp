#include <iostream>
#include <cstdlib>
#include <ctime>

#define topeFila 3
#define topeColumna 3

using namespace std;


//Declaracion de Funciones
void InicializarMatriz(int matriz[topeFila][topeColumna]);
void IngresarMatriz(int matriz[topeFila][topeColumna]);
bool ElementosFilas(int matriz[topeFila][topeColumna]);
bool ElementosColumnas(int matriz[topeFila][topeColumna]);
bool ElementosDiagonal(int matriz[topeFila][topeColumna]);
void MostrarMatriz(int matriz[topeFila][topeColumna]);
void diagonalAleatoria(int matriz[topeFila][topeColumna]);
bool verificaNumerosAleatorios(int matriz[topeFila][topeColumna], int numeroAleatorio);


int main()
{
	int matriz[topeFila][topeColumna];
	
	InicializarMatriz(matriz);
	cout<<"======== Sudoku "<<topeFila<<" x "<<topeColumna<<" ========"<<endl<<endl;
	IngresarMatriz(matriz);
	cout<<endl;
	MostrarMatriz(matriz);
	
	if (ElementosFilas(matriz) != false or ElementosColumnas(matriz) != false or ElementosDiagonal(matriz)){
		cout<<"Perdiste el juego";
	}
	else{
		cout<<"Ganaste el juego!";
	}
	return 0;
}


void InicializarMatriz(int matriz[topeFila][topeColumna])
{
	for(int i=0;i<topeFila;i++)
	{
		for (int j=0;j<topeColumna;j++)
		{
			matriz[i][j]=0; 
		}
	}
	diagonalAleatoria(matriz);
}


void diagonalAleatoria(int matriz[topeFila][topeColumna])
{
	int numerosAleatorios = 0;
	srand(time(0));
	
	for (int i=0; i < topeFila; i++)
	{
		numerosAleatorios = 1 + rand() % topeFila;
		while (verificaNumerosAleatorios(matriz, numerosAleatorios) == false)
		{
			numerosAleatorios = 1 + rand() % topeFila;
		}
		matriz[i][i] = numerosAleatorios;
	}
}


bool verificaNumerosAleatorios(int matriz[topeFila][topeColumna], int numerosAleatorios)
{
	bool verifica = true;
	
	for(int i=0;i<topeFila;i++)
	{
		if (numerosAleatorios == matriz[i][i])
		verifica = false;
	}
	return verifica;
}


void IngresarMatriz(int matriz[topeFila][topeColumna])
{
	for(int i=0;i<topeFila;i++)
	{
		cout<<endl;
		MostrarMatriz(matriz);
		cout<<"Fila nro."<<i+1<<endl;
		for (int j=0;j<topeColumna;j++)
		{
			cout<<"Ingresar elemento ["<<i<<"] ["<<j<<"]: ";
			cin>>matriz[i][j];
			while (matriz[i][j] < 1 or matriz[i][j] > topeFila)
			{
				cout<<"Reingrese el elemento ["<<i<<"] ["<<j<<"]: ";
				cin>>matriz[i][j];
			}
		}
	}
}


bool ElementosFilas(int matriz[topeFila][topeColumna])
{
	bool validacion=false;
	
	for (int i=0; i<topeFila; i++){
		for (int j=0; j<topeColumna; j++){
			for (int k=0; k<topeColumna; k++){
				if (matriz[i][j] == matriz[i][k] && k != j){
					validacion = true;
					
				}
			}
		}
	}
	return validacion;
}


bool ElementosColumnas(int matriz[topeFila][topeColumna])
{
	bool validacion=false;
	
	for (int i=0; i<topeColumna; i++){
		for (int j=0; j<topeFila; j++){
			for (int k=0; k<topeFila; k++){
				if (matriz[j][i] == matriz[k][i] && k != j){
					validacion = true;
					
				}
			}
		}
	}
	return validacion;
}


bool ElementosDiagonal(int matriz[topeFila][topeColumna])
{
	bool validacion=false;
	
	for (int i=0; i<topeFila and i<topeColumna; i++){
		for (int j=0; j<topeFila and j<topeColumna; j++){
			if (matriz[i][i] == matriz[j][j] and i != j){
				validacion = true;
			}
		}
	}
	return validacion;
}


void MostrarMatriz(int matriz[topeFila][topeColumna])
{
    for (int i=0; i<topeFila; i++){
        cout<< "   | ";
        for (int j=0; j<topeColumna; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }
	cout<<endl;
}
