#include <iostream>
#include <cmath>

using namespace std;

const int MINUTOS = 60;
const int SEGUNDOS = MINUTOS * MINUTOS;

int tiempoTotal (int hora, int min, int seg){
	int tiempo_total;
	tiempo_total = hora*SEGUNDOS + min*MINUTOS + seg;

	return tiempo_total;
}

class Instante {
	private:
		int hora;
		int minutos;
		int segundos;
	
	public:

		Instante (int hor, int min, int seg){
			if (hor >= 0 && hor < 24)
				hora = hor;
			else
				hora = 0;

			if (min >= 0 && min < 60)
				minutos = min;
			else
				minutos = 0;

			if (seg >= 0 && seg < 60)
				segundos = seg;
			else
				segundos = 0;
		}

		Instante (){
			hora = 0;
			minutos = 0;
			segundos = 0;
		}

		int getHora(){
			return hora;
		}

		int getMinutos(){
			return minutos;
		}

		int getSegundos(){
			return segundos;
		}

		int segundosDesdeCero (){
			int total_segundos;

			total_segundos = hora*SEGUNDOS + minutos*MINUTOS + segundos;

			return total_segundos;

		}

		void segundosToInstante (int segs){

			hora = segs / SEGUNDOS;
			segs -= SEGUNDOS * hora;
			minutos = segs / MINUTOS;
			segs -= MINUTOS * minutos;
			segundos = segs;
		}



};

int main (){
	int segundos_instante_1, segundos_instante_2, segundos_diferencia, total_segundos;
	int hora_1, min_1, segundos_1, hora_2, min_2, segundos_2;
	int minutos_diferencia;

	cin >> hora_1 >> min_1 >> segundos_1 >> hora_2 >> min_2 >> segundos_2;

	Instante instante_inicial(hora_2, min_2, segundos_2);
	Instante instante_final(hora_1, min_1, segundos_1);

	segundos_instante_1 = tiempoTotal(instante_inicial.getHora(), instante_inicial.getMinutos(), instante_inicial.getSegundos());
	segundos_instante_2 = tiempoTotal(instante_final.getHora(), instante_final.getMinutos(), instante_final.getSegundos());

	segundos_diferencia = segundos_instante_1 - segundos_instante_2;
	minutos_diferencia = segundos_diferencia / MINUTOS;

	Instante instante_diferencia;

	instante_diferencia.segundosToInstante(segundos_diferencia);
	total_segundos = instante_diferencia.segundosDesdeCero();

	cout << "Diferencia: " << instante_diferencia.getHora() << "h " << instante_diferencia.getMinutos() << "m " << instante_diferencia.getSegundos() << "s " << endl;
	cout << minutos_diferencia << endl;
	cout << segundos_diferencia << endl;

}