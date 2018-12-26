////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
   IntercambiaComponentes
   EsPalíndromo
   Invierte
   EliminaOcurrencias
   Moda
*/

#include <iostream>
#include <cctype>
using namespace std;


struct FrecuenciaCaracter{
   char caracter;
   int  frecuencia;
};


class SecuenciaCaracteres{
private:
   static const int TAMANIO = 2e6;  // <- Para que compile con este tamaño debe consultar el guión de prácticas
   char vector_privado[TAMANIO];
   int total_utilizados;

   void IntercambiaComponentesDirectamente(int pos_izda, int pos_dcha){
      char intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
public:
   
   ///////////////////////////////////////////////////////////////////////
   // Métodos vistos en los apuntes:
   ///////////////////////////////////////////////////////////////////////

   SecuenciaCaracteres()
      :total_utilizados(0) {
   }

   int TotalUtilizados(){
      return total_utilizados;
   }

   int Capacidad(){
      return TAMANIO;
   }

   void EliminaTodos(){
      total_utilizados = 0;
   }

   void Aniade(char nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }

   void Modifica(int posicion, char nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }

   char Elemento(int indice){
      return vector_privado[indice];
   }

   string ToString(){
      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++)
         cadena.push_back(vector_privado[i]);

      return cadena;
   }
   
   void Elimina (int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
	}


   ///////////////////////////////////////////////////////////////////////
   // Métodos nuevos:
   ///////////////////////////////////////////////////////////////////////

   
   bool EsPalindromo(){
      // Observe cómo accedemos directamente a vector_privado dentro del método

      bool es_palindromo;
      int izda, dcha;

      es_palindromo = true;
      izda = 0;
      dcha = total_utilizados - 1;

      while (izda < dcha && es_palindromo){
         if (vector_privado[izda] != vector_privado[dcha])
            es_palindromo = false;
         else{
            izda++;
            dcha--;
         }
      }

      return es_palindromo;
   }
   
   /*
   Observe que tenemos dos métodos similares:
   
   IntercambiaComponentesDirectamente
      -> Privado. No comprueba el rango de los índices
      Lo llamaremos desde otros métodos de la clase
      
   IntercambiaComponentes
      -> Público. Sí comprueba el rango de los índices

   La idea es que todo lo que sea público debe ir "protegido"
   Lo que usemos dentro de la clase, podemos "desprotegerlo" para aumentar
   la rapidez en la llamada.
   */
   
	void IntercambiaComponentes (int izda, int dcha){
      if (izda >= 0  &&  izda < dcha  &&  dcha < total_utilizados)
         IntercambiaComponentesDirectamente(izda, dcha);
	}


   void Invierte(){
      // Llamamos al método privado IntercambiaComponentesDirectamente
		int izda, dcha;

		izda = 0;
		dcha = total_utilizados - 1;

		while (izda < dcha){
			IntercambiaComponentesDirectamente(izda, dcha);
			izda++;
			dcha--;
		}
	}

   void EliminaOcurrenciasIneficiente(char a_borrar){
         int i = 0;

      while (i < total_utilizados){                            // utilizados va cambiando
         if (vector_privado[i] == a_borrar){
            Elimina(i);
         }
         else
            i++;
      }
   }
	
   void EliminaOcurrencias(char a_borrar){
      // Observe cómo accedemos directamente a vector_privado dentro del método
      // No se nos ha de olvidar actualizar total_utilizados
      // pos_lectura y pos_escritura serán datos locales
      int pos_escritura, pos_lectura;

      pos_escritura = 0;

      for (pos_lectura = 0; pos_lectura < total_utilizados; pos_lectura++){
         if (vector_privado[pos_lectura] != a_borrar){
            vector_privado[pos_escritura] = vector_privado[pos_lectura];
            pos_escritura++;
         }
      }

      total_utilizados = pos_escritura;
   }

   FrecuenciaCaracter Moda(){
      /*
      Algoritmo (Moda de una secuencia de caracteres):

         Almacenaremos en un vector local los caracteres ya procesados

         Recorrer todos los caracteres de la secuencia original
            Buscar el carácter en el vector local de procesados
            Si no está (no ha sido procesado aún),
               lo añadimos y actualizamos, en su caso, la moda
      */

      const int NUMERO_CARACTERES_ASCII = 256;
      char procesados[NUMERO_CARACTERES_ASCII];
      FrecuenciaCaracter moda;
      char caracter_actual;
      int conteo_frecuencia;
      int utilizados_procesados;
      bool encontrado;


      utilizados_procesados = 0;
      moda.frecuencia = 0;

      for (int i = 0 ; i < total_utilizados ; i++){
         caracter_actual = vector_privado[i];
         encontrado = false;

         for (int j = 0; j < utilizados_procesados && !encontrado; j++){
            if (caracter_actual == procesados[j])
               encontrado = true;
         }

         if (! encontrado){
            procesados[utilizados_procesados] = caracter_actual;
            utilizados_procesados++;
            conteo_frecuencia = 1;

            for (int k = i + 1 ; k < total_utilizados ; k++)
               if (caracter_actual == vector_privado[k])
                  conteo_frecuencia++;

            if (conteo_frecuencia > moda.frecuencia) {
               moda.frecuencia = conteo_frecuencia;
               moda.caracter   = caracter_actual;
            }
         }
      }

      return moda;

      /*
      IMPORTANTE:
         Observe que el proceso de buscar un carácter dentro de procesados
         es análogo al proceso de buscar dentro de la clase SecuenciaCaracteres
         En el tema V veremos cómo no repetir este código y reutilizar
         esa funcionalidad ya definida dentro de la clase.
      */
   }
};

int main(){
   const char TERMINADOR = '#';
   SecuenciaCaracteres secuencia;
   int total_leidos;
   int capacidad_secuencia;
   char caracter, caracter_prueba = ' ', borrar;
   FrecuenciaCaracter moda_secuencia;
   SecuenciaCaracteres prueba;

   capacidad_secuencia = prueba.Capacidad();
   total_leidos = 0;
   //caracter = cin.get();

  /* while (caracter != TERMINADOR && total_leidos < capacidad_secuencia){
      secuencia.Aniade(caracter);
      total_leidos++;
      caracter = cin.get();
   }*/

   
   caracter_prueba = cin.get();

   while (caracter_prueba != TERMINADOR && total_leidos < capacidad_secuencia){
      prueba.Aniade(caracter_prueba);
      caracter_prueba = cin.get();
      total_leidos++;
   }

   cout << "\n\n" << prueba.ToString() << "\n\n";

   cin >> borrar;

   prueba.EliminaOcurrenciasIneficiente(borrar);

   cout << "\n\n" << prueba.ToString() << "\n\n";

  /* cout << "\n\n>" << secuencia.ToString() << "<\n\n";
   
   moda_secuencia = secuencia.Moda();
   
   cout << "Moda:       " << moda_secuencia.caracter << "\n"
        << "Frecuencia: " << moda_secuencia.frecuencia << "\n\n";


   if (secuencia.EsPalindromo())
      cout << "Es palíndromo";
   else{
      cout << "No Es palíndromo";
      cout << "\nComponentes del vector después de invertirlo: <";

      secuencia.Invierte();
      cout << secuencia.ToString();
      cout << ">";
   }

   cout << "\n\n";

   /*
   En vez de poner
      cout << secuencia.ToString();
   podríamos haber puesto:
      for (int i = 0; i < secuencia.TotalUtilizados(); i++)
         cout  << secuencia.Elemento(i) << " ";
   pero queda más elegante la primera forma.
   */

   // Ejemplo de entrada:
   // abcdba#
}
