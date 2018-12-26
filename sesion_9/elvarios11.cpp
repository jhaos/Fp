#include <iostream>
using namespace std;


int main(){
   const int MAX_NUM_CARACTERES = 50;
   int v[MAX_NUM_CARACTERES];
   int num_v, num_a_borrar, nuevo_elemento;
   int i, utilizados, pos_lectura = 0, pos_escritura = 0;
 
   // Lectura
   
   cin >> num_v;
   i = 0;
   
   while (i < num_v){
      cin >> nuevo_elemento;
      v[i] = nuevo_elemento;
      i++;
   }



   utilizados = i;
   cin >> num_a_borrar;
   i = 0;
   int v_a_borrar[num_a_borrar];

   while (i < num_a_borrar){
      cin >> nuevo_elemento;
      v_a_borrar[i] = nuevo_elemento;
      
      if (i != 0 && v_a_borrar[i] < v_a_borrar[i-1]){
         int intercambio = v_a_borrar[i-1];
         v_a_borrar[i-1] = v_a_borrar[i];
         v_a_borrar[i] = intercambio;
      }
      i++;
   }
   i = 0;
   bool borrar_ok = false;
   while (pos_lectura < utilizados){
      
      if (pos_lectura == v_a_borrar[i]){

         pos_lectura++;
         borrar_ok = true;
      
      }else {
         
         v[pos_escritura] = v[pos_lectura];
         pos_escritura++;
         pos_lectura++;
         utilizados--;
      }
      if (borrar_ok){
         i++;
      }
   }
   for (int j = 0; j < utilizados; j++)
      cout << v[j] << " ";
}