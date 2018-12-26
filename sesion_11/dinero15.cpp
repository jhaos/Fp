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

};

int main (){

	int euros_1, euros_2, centimos_1, centimos_2;
	int total_euros, total_centimos;

	cin >> euros_1 >> centimos_1;
	cin >> euros_2 >> centimos_2;

	Dinero dinero_1 (euros_1, centimos_1);
	Dinero dinero_2 (euros_2, centimos_2);

	total_euros = dinero_1.getEuros() + dinero_2.getEuros();
	total_centimos = dinero_1.getCentimos() + dinero_2.getCentimos();

	Dinero dinero_total (total_euros, total_centimos);

	cout << dinero_total.getEuros() << " " << dinero_total.getCentimos() << endl;

}