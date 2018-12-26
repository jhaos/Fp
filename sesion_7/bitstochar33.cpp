#include <iostream>
#include <cmath>

using namespace std;

const int TERMINADOR = -1;
const double PORCENTAJE = 100.0;

int main (){
	int bit, contador = 7;	
	char resultado;
	int letra = 0, otros = 0, total = 0;
	bool minuscula = resultado <= 'z' && resultado >= 'a';
	bool mayuscula = resultado <= 'Z' && resultado >= 'A'; 
	double porcentaje_letras = 0.0, porcentaje_otros = 0.0;	

	cin >> bit; 
	while(bit != TERMINADOR){

	   contador--;
	   while ((bit == 0 || bit == 1) && contador >= 0 || bit != TERMINADOR){
	      resultado += pow(bit,contador);
	      do{
	      cin >> bit;
	      }while(bit != 0 || bit != 1);    	 
	      contador--;
	   } 

	   if (contador > 0){
	      resultado = '0';
	   }else {
	   		
	      if ((minuscula) || (mayuscula)){
	         cout << "El resultado es " << resultado << endl;
	         letra++;
	      }else {
	         otros++;
	      }  
      }
	   contador = 7;
	
		
	   cin >> bit;

	}
	
	if(letra == 0 && otros == 0){
		total = 1;
	}
	total = letra + otros;
	porcentaje_letras = letra*PORCENTAJE / total;
	porcentaje_otros = otros*PORCENTAJE / total;
	
	cout << "Porcentaje de letras: " << porcentaje_letras << "\n" << endl;
	cout << "Porcentaje de otros: " << porcentaje_otros << "\n" << endl;
}
