/*

	En este programa se comprar si dos números tienen el mismo signo

*/

#include <iostream>

using namespace std;

int main(){
	int numero_1, numero_2;
	bool mismo_signo;
	cout << "Indica los números a comparar: ";
	cin >> numero_1 >> numero_2;
	
	mismo_signo = (numero_1 > 0 && numero_2 > 0) || (numero_1 < 0 && numero_2 < 0)
	
	if(mismo_signo){
		cout << "Tienen el mismo signo" << endl;
	}else{
		cout << "No tienen el mismo signo" << endl;
	}




}