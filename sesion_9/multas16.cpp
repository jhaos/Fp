#include <iostream>

using namespace std;

int main () {
	int cantidad_inicial = 21, cantidad;	
	int matriz[5][10];
	for (int i = 0; i < 5; i++){
		cantidad = cantidad_inicial;
		matriz[i][0] = cantidad;
		if (i == 1){
			cantidad_inicial = cantidad_inicial + 20;
			matriz[i][0] = cantidad_inicial;
		}
		else if (i > 1){
			cantidad_inicial = cantidad_inicial +10;
			matriz[i][0] = cantidad_inicial;
		}
			cantidad = cantidad_inicial;
	   for (int j = 0; j < 10; j++){
	      if (i == 1 && j == 3){
	      	cantidad += 20;
	      	matriz[i][j] = cantidad;
	      }else if (i > 1 && j == 3){
	      	cantidad += 30;
	      	matriz[i][j] = cantidad;
	      }else {

	      	cantidad += 10;
	    		matriz[i][j] = cantidad;
	      }
	  
	   }
	  
	}
		for (int i = 0; i < 5; i++){
		for (int j = 0; j < 10; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

