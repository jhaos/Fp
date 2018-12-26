#include <iostream>
using namespace std;


   const char TERMINADOR = '#';
   const long MAX_NUM_CARACTERES = 50000000;

int main(){
   char v[MAX_NUM_CARACTERES];
   char a_borrar;
   char caracter;
   int i, utilizados, pos_lectura = 0, pos_escritura = 0;
 
   // Lectura
   cout << "entra";
   cin.get(caracter);
   i = 0;
   cout << "entra";
   while (caracter != TERMINADOR){
      v[i] = caracter;
      caracter = cin.get();
      i++;
   }
   
   utilizados = i;
   
   a_borrar = cin.get();
   char vector[utilizados];

   i = 0;
   pos_lectura = 0;
   pos_escritura = 0;
   while (pos_lectura < utilizados){
   	if(v[pos_lectura] != a_borrar){
   		vector[pos_escritura] = v[pos_lectura];
  			cout << vector[pos_escritura];
  			pos_escritura++;
   		i++;
   	}
   	pos_lectura++;
   	
	}


   for (int j = 0; j < i; j++)
   	cout << vector[j];
}