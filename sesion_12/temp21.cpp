#include <iostream>

using namespace std;

struct ParFilaColumna{
	int fila;
	int columna;
};

class TablaTemperaturas{
	private:
		static const int FILAS = 10;
		static const int COLUMNAS  = 24;
		double matriz_ciudades[FILAS][COLUMNAS];
	public:
		/*TablaTemperaturas(){
			filas_utiles = 0;
			columnas_utiles = 0;
		}

		TablaTemperaturas(int fil, int col){
			filas_utiles = fil;
			columnas_utiles = col;
		}*/

		int MaxFilas(){
			return FILAS;
		}

		int MaxColumnas(){
			return COLUMNAS;
		}

		double Valor(int ciudad, int hora){
			if (ciudad < filas && hora < columnas)
				return matriz_ciudades[ciudad][hora];
		}

		void Modifica(int ciudad, int hora, double temperatura){
			if (ciudad < filas && hora < columnas)
				matriz_ciudades[ciudad][hora] = temperatura;
		}

		int Minimo(int ciudad){
			int minimo = matriz_ciudades[ciudad][0];

			if (ciudad < filas){
				for (int i = 0; i < COLUMNAS; i++)
					if (minimo > matriz_ciudades[ciudad][i])
						minimo = i;
			}
			return minimo;
		}

		ParFilaColumna MaxMinimos(){
			double minimos[filas];
			double max, indice_max;
			ParFilaColumna par;

			for (int i = 0; i < filas; i++){
				minimos[i] = Minimo(i);
			}	

			int i = 0;
			max = minimos[i];
			indice_max = i;

			for (i = 1; i < filas; i++){
				if (max < minimos[i])
					max = minimos[i];
					indice_max = i;
			}
			par.fila = indice_max;
			par.columna = max;

			return par;
		}
};

int main(){
	TablaTemperaturas tabla;
	ParFilaColumna par;
	int valor;

	for (int i = 0; i < tabla.MaxFilas(); ++i){
		for (int j = 0; j < tabla.MaxColumnas(); ++j){
			cin > tabla.Modifica[i][j];
		}
	}

	par = tabla.MaxMinimos();
	valor = tabla.Valor(par.filas, par.columnas);

	cout << "Ciudad: " << par.filas << endl;
	cout << "Hora: " << par.columnas << endl;
	cout << "temperatura: " << valor << endl;
}