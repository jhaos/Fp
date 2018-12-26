#include <iostream>
#include <cmath>

using namespace std;

const int CENTENA = 100;

class Dinero{
	private:
		int euros;
		int centimos;

	public:
		Dinero(int euro, int cents){
			
			euros = euro;
			if (cents > CENTENA){
				int aumentar = cents / CENTENA;
				euros += aumentar;
				centimos = cents % CENTENA;
				
			}else{
				centimos = cents;
			}
		}

		Dinero(){
			euros = 0;
			centimos = 0;
		}

		int getEuros(){
			return euros;
		}

		int getCentimos(){
			return centimos;
		}

		Dinero Sumar(Dinero otro_dinero){
			int total_euros, total_centimos;

			total_euros = euros + otro_dinero.euros;
			total_centimos = centimos + otro_dinero.centimos;
			
			Dinero resultado(total_euros, total_centimos);

			return resultado;

		}

		void Sumale(Dinero otro_dinero){
			int total_euros, total_centimos;

			total_euros = euros + otro_dinero.euros;
			total_centimos = centimos + otro_dinero.centimos;

			if (total_centimos > CENTENA){
				int aumentar = total_centimos / CENTENA;
				euros = total_euros + aumentar;
				centimos = total_centimos % CENTENA;
				
			}else{
				centimos = total_centimos;
			}

			

		}

};

int main (){

	int euros_1, euros_2, centimos_1, centimos_2;
	int total_euros, total_centimos;
	

	cin >> euros_1 >> centimos_1;
	cin >> euros_2 >> centimos_2;

	Dinero dinero_1 (euros_1, centimos_1);
	Dinero dinero_2 (euros_2, centimos_2);
	Dinero dinero_suma, dinero_sumale;

	dinero_sumale = dinero_1;
	dinero_sumale.Sumale(dinero_2);
	dinero_suma = dinero_1.Sumar(dinero_2);


	cout << dinero_suma.getEuros() << " " << dinero_suma.getCentimos() << endl;
	cout << dinero_sumale.getEuros() << " " << dinero_sumale.getCentimos() << endl;

}