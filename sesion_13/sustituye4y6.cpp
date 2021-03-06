//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Secuencia de caracteres

#include <iostream>
using namespace std;

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 2e6;  // 2e6 es un real (dos millones) -> casting automático
                                    // Herramientas -> Opciones del Compilador ->
                                    // Compilador -> Añadir las siguientes opciones
                                    // -Wl,--stack,26000000
   char vector_privado[TAMANIO];
   int total_utilizados;
   
   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      char intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
public:
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
      // Si el número de caracteres en memoria es muy grande,
      // es mucho más eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++)
         cadena.push_back(vector_privado[i]);
         //cadena = cadena + vector_privado[i]  <- Evitarlo. Muy ineficiente para tamaños grandes;

      return cadena;
   }

   int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, char buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }
   
   int PrimeraOcurrencia (char buscado){
      return PrimeraOcurrenciaEntre (0, total_utilizados - 1, buscado);
   }
   

   /////////////////////////////////////////////////////////////
   // Búsquedas
   
   // Precond: 0 <= izda <= dcha < total_utilizados
   int PosicionMinimoEntre(int izda, int dcha){
      int posicion_minimo = -1;
      char minimo;

      minimo = vector_privado[izda];
      posicion_minimo = izda;

      for (int i = izda+1 ; i <= dcha ; i++)
         if (vector_privado[i] < minimo){
            minimo = vector_privado[i];
            posicion_minimo = i;
         }

      return posicion_minimo;
   }
   
   int PosicionMinimo(){
      return PosicionMinimoEntre(0, total_utilizados - 1);
   }
   
   int BusquedaBinaria (char buscado){
      int izda, dcha, centro;
      bool encontrado = false;

      izda = 0;
      dcha = total_utilizados - 1;
      centro = (izda + dcha) / 2;

      while (izda <= dcha  &&  !encontrado){
         if (vector_privado[centro] == buscado)
            encontrado = true;
         else if (buscado < vector_privado[centro])
            dcha = centro - 1;
         else
            izda = centro + 1;

         centro = (izda + dcha) / 2;
      }

      if (encontrado)
         return centro;
      else
         return -1;
   }
   
   
   /////////////////////////////////////////////////////////////
   // Recorridos que modifican las componentes
   
   // Inserta un valor en la posición especificada
   void Inserta(int pos_insercion, char valor_nuevo){
      if (total_utilizados < TAMANIO  &&  pos_insercion >= 0    
         &&  pos_insercion <= total_utilizados){

         for (int i = total_utilizados ; i > pos_insercion ; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[pos_insercion] = valor_nuevo;
         total_utilizados++;
      }
   }
   
   // Elimina una componente, dada por su posición
   void Elimina (int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
   }
   
   
   /////////////////////////////////////////////////////////////
   // Algoritmos de ordenación
   
   void Ordena_por_Seleccion(){
      int pos_min;

      for (int izda = 0 ; izda < total_utilizados ; izda++){
         pos_min = PosicionMinimoEntre(izda, total_utilizados - 1);
         IntercambiaComponentes_en_Posiciones(izda, pos_min);
      }
   }
   
   void Ordena_por_Insercion(){
      int izda, i;
      char a_desplazar;

      for (izda=1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i=izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }
   
   void InsertaOrdenadamente(char valor_nuevo){
        int i;

        if (total_utilizados > TAMANIO){
           for (i=total_utilizados; i>0 && valor_nuevo < vector_privado[i-1]; i--)
                vector_privado[i] = vector_privado[i-1];

           vector_privado[i] = valor_nuevo;
           total_utilizados++;
        }
   }

   void InsertaSecuencia(int pos_insercion, SecuenciaCaracteres a_insertar){
      int longitud_a_insertar = a_insertar.TotalUtilizados();

      if (longitud_a_insertar + total_utilizados < TAMANIO){
         for (int i = 0; i < longitud_a_insertar; i++){
            Inserta(pos_insercion, a_insertar.Elemento(i));    // Inserta aumenta automáticamente total_tulizados
            pos_insercion++;
         }
      }
   }

   void SustituirPorSecuencia(char a_sustituir, SecuenciaCaracteres a_insertar){
      int tamanio_total = total_utilizados + a_insertar.total_utilizados;

      for (int i = 0; i < total_utilizados; ++i){
         if (vector_privado[i] == a_sustituir){
            Elimina(i);
            InsertaSecuencia(i, a_insertar);
         }
      }

   }
   
   void SustituirPorSecuenciaAux(char a_sustituir, SecuenciaCaracteres a_insertar){
      int tamanio_total = total_utilizados + a_insertar.total_utilizados;
      SecuenciaCaracteres secuencia_auxiliar;

      for(int i = 0; i < total_utilizados; ++i){
         secuencia_auxiliar.vector_privado[i] = vector_privado[i];
      }


      for (int i = 0; i < secuencia_auxliar.total_utilizados; ++i){
         if (secuencia_axuliar.vector_privado[i] == a_sustituir){
            secuencia_auxiliar.Elimina(i);
            secuencia_auxiliar.InsertaSecuencia(i, a_insertar);
         }
      }


      for(int i = 0; i < secuencia_auxiliar.total_utilizados; ++i){
         vector_privado[i] = secuencia_auxiliar.vector_privado[i];
      }

   }

   
   void Ordena_por_Burbuja(){
      int izda, i;

      for (izda = 0; izda < total_utilizados; izda++)
        for (i = total_utilizados-1 ; i > izda ; i--)
          if (vector_privado[i] < vector_privado[i-1])
             IntercambiaComponentes_en_Posiciones(i, i-1);
   }
   
   void Ordena_por_BurbujaMejorado(){
      int izda, i;
      bool cambio;

      cambio= true;

      for (izda=0; izda < total_utilizados && cambio; izda++){
        cambio=false;

        for (i=total_utilizados-1 ; i>izda ; i--)
          if (vector_privado[i] < vector_privado[i-1]){
             IntercambiaComponentes_en_Posiciones(i, i-1);
             cambio=true;
          }
      }
   }
   
   void AniadeVarios(SecuenciaCaracteres nuevos){
      int totales_a_aniadir = nuevos.TotalUtilizados();
      
      for (int i = 0; i < totales_a_aniadir; i++)
         Aniade(nuevos.Elemento(i)); // Es importante entender
   }


   SecuenciaCaracteres ToUpper(){
      SecuenciaCaracteres en_mayuscula;
      
      for(int i = 0; i < total_utilizados; i++)
         en_mayuscula.Aniade(toupper(vector_privado[i]));

      return en_mayuscula;
   }


   // Busca una sub-secuencia
   // Las posiciones deben estar en orden y consecutivas
   int PosicionContiene (SecuenciaCaracteres a_buscar){
      int  inicio;
      int  ultima_componente;
      bool encontrado;
      int  posicion_contiene;
      bool va_coincidiendo;
      int  utilizados_a_buscar;

      /*
      Tenemos una secuencia "grande" de tamaño G y otra pequeña de tamaño P

      Recorrer la secuencia "grande" fijando una posición inicial inicio
      La última posición inicial a probar será G-P
         A partir de inicio recorrer en paralelo las
         dos secuencias "grande" y "pequeña"
         Si no coinciden todas las componentes, hay que
         empezar de nuevo a partir de inicio + 1.
      */

      utilizados_a_buscar = a_buscar.TotalUtilizados();

      if (utilizados_a_buscar > 0){
         ultima_componente = total_utilizados - utilizados_a_buscar;
         encontrado = false;

         for (inicio = 0; inicio <= ultima_componente && !encontrado; inicio++){
            va_coincidiendo = true;

            for (int i = 0; i < utilizados_a_buscar && va_coincidiendo; i++)
               va_coincidiendo = vector_privado[inicio + i] == a_buscar.Elemento(i);

            if (va_coincidiendo){
               posicion_contiene = inicio;
               encontrado = true;
            }
         }
      }
      else
         encontrado = false;

      if (encontrado)
         return posicion_contiene;
      else
         return -1;
   /*
   Batería de pruebas:
      Los dos vectores vacíos.
      Alguno de ellos vacío.
      Los dos vectores iguales.  atti / atti
      Que no se encuentre.   atti / tj
      Que se encuentre al principio.  atti / at
      Que se encuentre justo al final. atti / ti
      Que haya un emparejamiento parcial pero no total,
      aunque luego sí se encuentre.  atttij / ti
   */
   }
};



class LectorSecuenciaCaracteres{
private:
   char terminador;
public:
   LectorSecuenciaCaracteres(char caracter_terminador)
      :terminador(caracter_terminador)
   {
   }
   SecuenciaCaracteres Lee(){
      SecuenciaCaracteres a_leer;
      int total_introducidos;  // Esta variable es para contar los introducidos
                               // y que no nos pasemos de la capacidad de la secuencia.
      int capacidad_secuencia;
      char caracter;

      total_introducidos = 0;
      capacidad_secuencia = a_leer.Capacidad();
      caracter = cin.get();

      while (caracter == '\n')
         caracter = cin.get();

      while (caracter != terminador && total_introducidos < capacidad_secuencia){
         a_leer.Aniade(caracter);
         total_introducidos++;
         caracter = cin.get();
      }

      return a_leer;
   }
};



int main(){
   const char TERMINADOR = '#';
   LectorSecuenciaCaracteres lector_secuencias(TERMINADOR);
   LectorSecuenciaCaracteres lector_2(TERMINADOR);
   SecuenciaCaracteres secuencia;
   SecuenciaCaracteres sustituye, secuencia_2;

   secuencia = lector_secuencias.Lee();
   sustituye = lector_2.Lee();
   
   secuencia.SustituirPorSecuencia(sustituye);
   secuencia_2.SustituirPorSecuencia(sustituye);
   /////////////////////////////////////////////////////////
   // Búsqueda de una sub-secuencia:
   // abcccdefg#ccd#
   /*
   SecuenciaCaracteres pequenia;
   int pos_contiene;
   
   pequenia = lector_secuencias.Lee();
   pos_contiene = secuencia.PosicionContiene(pequenia);
   
   if (pos_contiene == -1)
      cout << "\nNo encontrada";
   else
      cout << "\nEncontrada en la posición " << pos_contiene;
   */
   
   // fedghcba#
   //secuencia.Ordena_por_Insercion_vs_directa();
   cout << secuencia.ToString();
   
   /////////////////////////////////////////////////////////
   // Recorrido para imprimir los elementos de la secuencia:

   /*
   int utilizados_en_secuencia;

   utilizados_en_secuencia = secuencia.TotalUtilizados();

   for (int i=0; i < utilizados_en_secuencia; i++)
      cout << secuencia.Elemento(i);

   // O bien:

   cout << "\n" << secuencia.ToString();
   */
   
   /////////////////////////////////////////////////////////
   // Búsquedas
   /////////////////////////////////////////////////////////
   
   /*
   
   int pos_encontrado;
   char letra_a_buscar;
   
   
   /////////////////////////////////////////////////////////
   // Primera Ocurrencia 
 
   cout << "\nIntroduzca una letra a buscar en la cadena ";
   cin >> letra_a_buscar;

   pos_encontrado = secuencia.PrimeraOcurrencia(letra_a_buscar);

   // Si estuviese ordenado:
   // pos_encontrado = secuencia.BusquedaBinaria(letra_a_buscar);

   if (pos_encontrado == -1)
      cout << "\nLa letra " << letra_a_buscar << " no se encuentra";
   else
      cout << "\nLa letra " << letra_a_buscar 
           << " se encuentra en la posición " << pos_encontrado;

   /////////////////////////////////////////////////////////
   // Mínimo

   int pos_minimo;

   pos_minimo = secuencia.PosicionMinimo();
   cout << "\nEl mínimo de la cadena se encuentra en la posición "
        << pos_minimo;
      
   */

   /////////////////////////////////////////////////////////
   // Recorridos que modifican las componentes
   /////////////////////////////////////////////////////////
   
    /////////////////////////////////////////////////////////
   // Eliminar
   
   /*
   int pos_a_eliminar;
   
   cout << "\nIntroduzca posición a eliminar ";
   cin >> pos_a_eliminar;
   
   secuencia.Elimina(pos_a_eliminar);
   

    /////////////////////////////////////////////////////////
   // Insertar 
      
   int pos_a_inserter;
   char caracter_a_insertar;
   
   cout << "\nIntroduzca posición a insertar ";
   cin >> pos_a_inserter;
   cout << "\nIntroduzca carácter a insertar ";
   cin >> caracter_a_insertar;   
   
   secuencia.Inserta(pos_a_inserter, caracter_a_insertar) ;
   */
   
   /////////////////////////////////////////////////////////
   // Algoritmos de ordenación
   /////////////////////////////////////////////////////////
   
   // secuencia.Ordena_por_Insercion();

   cout << "\n" << secuencia.ToString();
}