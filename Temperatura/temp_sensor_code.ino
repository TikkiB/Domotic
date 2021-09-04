#include "DHT.h" // lib para mod temp
#define DHTPIN 6 // pin de comunicacion con el sensor de temperatura
#define DHTTYPE DHT11 // referencia del sensor

//int ventilador = 7;
DHT dht(DHTPIN,DHTTYPE); // instancia de objeto de clase DHT

void setup() {
  Serial.begin(9600);
  Serial.println("Probando conexion con sensor de temperatura");
  dht.begin(); // inicializamos el obj
  //pinMode(ventilador,OUTPUT);
}

void loop() {
  delay(2000);

  //temperatura
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();
  float hic = dht.computeHeatIndex(temperatura, humedad, false); // sensacion termica en C°

  if (isnan(humedad)|| isnan(temperatura)){
    Serial.println("Error al leer del sensor");
    return;
  }

  
  delay(350);
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print("%   ");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C  ");
  Serial.print("Sensación termica: ");
  Serial.print(hic);
  Serial.print("°C  ");
  Serial.println();
  //if(temperatura >27){
      //digitalWrite(ventilador,HIGH);
    //}    
}
