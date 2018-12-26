// NO MODIFIQUE ESTA CLASE
class Instante{
private:
   static const int SEGUNDOS_POR_MINUTO = 60,
          MINUTOS_POR_HORA = 60,
          HORAS_EN_DIA = 24;
   int hora    = -1;
   int minuto  = -1;
   int segundo = -1;

   bool EsCorrecto (int hora, int minuto, int segundo){
      return  (0 <= hora    && hora < HORAS_EN_DIA  &&
               0 <= minuto  && minuto < MINUTOS_POR_HORA &&
               0 <= segundo && segundo < SEGUNDOS_POR_MINUTO);
   }

   // segundos_a_modificar puede ser positivo o negativo
   void AniadeQuitaSegundos(int segundos_a_modificar){
      int segundos_nuevos;

      segundos_nuevos =
         SegundosTotalesEnterosTranscurridos() + segundos_a_modificar;

      SetSegundosTotalesTranscurridos(segundos_nuevos);
   }

public:
   // Si vamos a crear vectores de VehiculoTunel y éstos contienen Instantes,
   // tenemos que proporcionar un constructor sin parámetros



   Instante(int hora_instante, int minuto_instante, int segundo_instante){
      SetHoraMinutoSegundo(hora_instante,  minuto_instante,  segundo_instante);
   }

   Instante(int segundos_transcurridos){
      SetSegundosTotalesTranscurridos(segundos_transcurridos);
   }

   int Hora(){
      return hora;
   }

   int Minuto(){
      return minuto;
   }

   int Segundo(){
      return segundo;
   }

   void SetHoraMinutoSegundo(int hora_instante,
                             int minuto_instante,
                             int segundo_instante){
      if (EsCorrecto(hora_instante, minuto_instante, segundo_instante)){
         hora = hora_instante;
         minuto = minuto_instante;
         segundo = segundo_instante;
      }
   }

   void SetSegundosTotalesTranscurridos(int segundos_totales){
      int minutos_enteros;
      const int SEGUNDOS_EN_1_DIA = SEGUNDOS_POR_MINUTO
                                    * MINUTOS_POR_HORA
                                    * HORAS_EN_DIA;

      if (segundos_totales < SEGUNDOS_EN_1_DIA){
         segundo = segundos_totales % SEGUNDOS_POR_MINUTO;
         minutos_enteros  = segundos_totales / SEGUNDOS_POR_MINUTO;
         minuto  = minutos_enteros % MINUTOS_POR_HORA;
         hora    = minutos_enteros / MINUTOS_POR_HORA;
      }
   }

   void SumaleSegundos(int segundos_a_aniadir){
      if (segundos_a_aniadir > 0)
         AniadeQuitaSegundos(segundos_a_aniadir);
   }

   void RestaleSegundos(int segundos_a_quitar){
      if (segundos_a_quitar > 0)
         AniadeQuitaSegundos( - segundos_a_quitar);
   }

   bool EsNulo(){
      return !EsCorrecto(hora, minuto, segundo);
   }

   int SegundosTotalesEnterosTranscurridos(){
      return SEGUNDOS_POR_MINUTO * (hora * MINUTOS_POR_HORA + minuto)
             + segundo;
   }

   int MinutosTotalesEnterosTranscurridos(){
      return trunc(MinutosTotalesDecimalTranscurridos());
   }

   double MinutosTotalesDecimalTranscurridos(){
      return 1.0 * SegundosTotalesEnterosTranscurridos() / SEGUNDOS_POR_MINUTO;
   }

   double HorasTotalesDecimalTranscurridas(){
      return 1.0 * MinutosTotalesDecimalTranscurridos() / MINUTOS_POR_HORA;
   }

   string ToString(){
      return to_string(hora) + "h, " +
             to_string(minuto) + "\', " +
             to_string(segundo) + "\'\'";
   }

   ///////////////////////////////////////////////////////////////////////
   // Métodos NUEVOS


   void Sumale(Instante otro_instante){
      SumaleSegundos(otro_instante.SegundosTotalesEnterosTranscurridos());
   }
   
   void Restale(Instante otro_instante){
      RestaleSegundos(otro_instante.SegundosTotalesEnterosTranscurridos());
   }

   Instante DiferenciaCon(Instante otro_instante){
      int segundos_iniciales, segundos_finales, segundos_diferencia;

      segundos_iniciales = SegundosTotalesEnterosTranscurridos();
      segundos_finales   = otro_instante.SegundosTotalesEnterosTranscurridos();
      segundos_diferencia = abs(segundos_finales - segundos_iniciales);

      Instante diferencia_con;

      diferencia_con.SetSegundosTotalesTranscurridos(segundos_diferencia);

      return diferencia_con;
   }

   bool EsMenorQue (Instante otro_instante){
      bool es_menor;

      if (hora < otro_instante.hora)
         es_menor = true;
      else if (otro_instante.hora > hora)
         es_menor = false;
      else if (minuto < otro_instante.minuto)
         es_menor = true;
      else if (minuto > otro_instante.minuto)
         es_menor = false;
      else if (segundo < otro_instante.segundo)
         es_menor = true;
      else
         es_menor = false;

      return es_menor;
   }
};
// NO MODIFIQUE ESTA CLASE
class VehiculoTunel{
private:
   string   matricula;
   Instante entrada;
   Instante salida;

   bool EsCorrectaMatricula(string matricula_vehiculo){
      return matricula_vehiculo.size() <= 8;
   }

public:
   // Si vamos a crear vectores de Vehiculos, tenemos que proporcionar
   // un constructor sin parámetros
   
   VehiculoTunel(){
   }

   VehiculoTunel(string matricula_vehiculo,
                Instante entrada_vehiculo,
                Instante salida_vehiculo
                )
   {
      SetMatricula(matricula_vehiculo);
      SetInstanteEntrada(entrada_vehiculo);
      SetInstanteSalida(salida_vehiculo);
   }

   string Matricula(){
      return matricula;
   }

   Instante InstanteEntrada(){
      return entrada;
   }

   Instante InstanteSalida(){
      return salida;
   }

   void SetMatricula(string matricula_vehiculo){
      if (EsCorrectaMatricula(matricula_vehiculo))
         matricula = matricula_vehiculo;
   }

   void SetInstanteEntrada(Instante entrada_vehiculo){
      entrada = entrada_vehiculo;
   }

   void SetInstanteSalida(Instante salida_vehiculo){
      salida = salida_vehiculo;
   }
};


// COMPLETE EL CÓDIGO DE ESTA CLASE
class Tunel{
private:
   double distancia_km;

   static const int MAX_NUM_VEHICULOS = 100;
   VehiculoTunel vehiculos[MAX_NUM_VEHICULOS];

   int total_entradas = 0;

   bool EsCorrectoIndice(int indice){
      return 0 <= indice && indice < total_entradas;
   }
public:
   Tunel(double distancia_km_tunel)
      :distancia_km(distancia_km_tunel)
   {
   }

   int TotalEntradas(){
      return total_entradas;
   }


   int Indice(string matricula){
      bool encontrado = false;
      int indice;

   	for (int i = 0; i < total_entradas && !encontrado; ++i){
   		if (vehiculos[i].Matricula() == matricula){
   			indice = i;
   			encontrado = true;
   		}

   		return indice;
   	}
      // Busque el vehículo con la matrícula pasada como parámetro
      // y devuelva el índice que le corresponde
   }

   VehiculoTunel Vehiculo(int indice){
   	VehiculoTunel vehiculo;
   	bool vehiculo_encontrado = false;

   		if (vehiculos[indice].Matricula() == matricula && !encontrado){
   			vehiculo = vehiculos[indice];
   			encontrado = true;
   		}   	
   		
   		if (encontrado)
   			return vehiculo;
   		else
   			return -1;
      // Devuelve el vehículo indicado según su índice
   }

   void Aniadir(VehiculoTunel vehiculo){

   	if (total_entradas < MAX_NUM_VEHICULOS){
   		vehiculos[total_entradas] == vehiculo;
   		total_entradas++;
   	}

   }

   void Entra(string matricula, Instante instante_entrada){
      VehiculoTunel nuevo_vehiculo;
      nuevo_vehiculo.SetMatricula(matricula);
      nuevo_vehiculo.SetInstanteEntrada(instante_entrada);

      Aniadir(nuevo_vehiculo);
	  // Construya un objeto de la clase VehiculoTunel
      // con los datos de los parámetros
      // Añádalo al vector vehiculos
   }


   void Sale(string matricula, Instante instante_salida){
      // Localice el vehículo con la matrícula indicada en el primer parámetro
      // y establezca el instante de salida indicado en el segundo parámetro
   	bool encontrado = false;

   	for (int i = 0; i < total_entradas && !encontrado; ++i){
   		if (vehiculos[i].Matricula() = matricula){
   			vehiculos[i].SetInstanteSalidaO(instante_salida);
   			encontrado = true;
   		} 
   	}
   }

   bool HaSalido(int indice){
      // Indique se el vehículo ha salido del túnel
   	bool ha_salido = false;

   	if (vehiculos[indice].InstanteSalida() != 0)
   		ha_salido = true;

   	return ha_salido;
   }
   
   double Velocidad(int indice){
      // Obtenga la velocidad del vehículo indicado
      // construyendo un objeto Instante como la diferencia
      // entre los instantes de salida y de entrada
      // Llame al método HorasTotalesDecimalTranscurridas()
      // de la clase Instante para calcular la velocidad.
      Instante resultado = vehiculos[i].InstanteEntrada().DiferenciaCon(vehiculos[i].InstanteEntrada());
      double horas;
		double velocidad;

      horas = resultado.HorasTotalesDecimalTranscurridas();
      velocidad = distancia_km / horas;

      return velocidad;
   }
};


// DEBE ENTENDER EL CÓDIGO DEL main
// PERO NO DEBE MODIFICAR NADA

int main(){
   setlocale(LC_ALL, "spanish");
   const char FIN_ENTRADA_FICHERO = '#';
   const char ENTRADA = 'E';
   const char SALIDA  = 'S';
   double long_tunel;
   char tipo_entrada_salida;

   string matricula;
   int hora, min, seg;
   
   FormateadorDoubles formateador_velocidad("", " km/h");
   formateador_velocidad.SetNumeroDecimales(1);

   cin >> long_tunel;

   Tunel tunel(long_tunel);

   cin >> tipo_entrada_salida;

   while (tipo_entrada_salida != FIN_ENTRADA_FICHERO){
      cin >> matricula;
      cin >> hora >> min >> seg;
      
      Instante instante(hora, min, seg);

      if (tipo_entrada_salida == ENTRADA)
         tunel.Entra(matricula, instante);
      else if (tipo_entrada_salida == SALIDA)
         tunel.Sale(matricula, instante);

      cin >> tipo_entrada_salida;
   }

   string cadena= "\n";

   for (int i = 0; i < tunel.TotalEntradas(); i++){
      cadena = cadena +
               "\n\nMatrícula:\t" + tunel.Vehiculo(i).Matricula() +
               "\nVelocidad:\t";

      string texto_salida;

      if (! tunel.HaSalido(i))
         texto_salida = "No ha salido";
      else
         texto_salida = formateador_velocidad.GetCadena(tunel.Velocidad(i));

      cadena = cadena + texto_salida;
   }

   cout << cadena;

   // longitud_túnel  <entrada_o_salida  Matrícula# Instante> ... #
   // 3.4    E 4467JHG 0    E 5678KGR 4    S 5678KGR 108    E 1234ABC 132 #
   // 3.4    E 4467JHG 0 1 2    E 5678KGR 0 1 6      S 5678KGR 0 2 50    E 1234ABC 0 3 14 #
}
