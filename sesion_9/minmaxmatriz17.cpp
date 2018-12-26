
#include <iostream>
using namespace std;

int main(){
   const int MAX_FIL = 10, MAX_COL = 10;
   double matriz[MAX_FIL][MAX_COL];
   double traspuesta[MAX_COL][MAX_FIL];
   int util_filas, util_columnas;


   // No etiquetamos las entradas porque suponemos que leemos de un fichero
   // Supondremos que util_filas y util_columnas son > 0

   cin >> util_filas;
   cin >> util_columnas;

   int menores[util_filas];
   int recorredor = 0;

   for (int i=0; i<util_filas; i++)
      for (int j=0; j<util_columnas; j++)
         cin >> matriz[i][j];

  for (int i=0; i<util_filas; i++){
      menores[recorredor] = matriz[i][j];
      for (int j=0; j<util_columnas; j++){
         if (menores[recorredor] )   
      }
  }
 

   cout << "\n\n";
   cout << "Matriz original:\n";

   for (int i=0; i<util_filas; i++){
      cout << "\n";

      for (int j=0; j<util_columnas; j++)
         cout << matriz[i][j] << '\t';
   }
   
   cout << "\n\n";
   cout << "Matriz traspuesta:\n";   
    
   for (int i=0; i<util_fil_traspuesta; i++){
      cout << "\n";
      
      for (int j=0; j<util_col_traspuesta; j++)
         cout << traspuesta[i][j] << '\t';
   }  
}