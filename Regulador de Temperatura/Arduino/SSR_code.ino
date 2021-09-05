
// codigo para SSR (G3MB-202P)

int relayPin = 7; //Data Pin 
void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);

}

void loop() { 
   digitalWrite(relayPin, LOW) // Encendemos el relay 
   Serial.println("Relay encendido");
   delay(2000);

   digitalWrite(relayPin,HIGH) //Apagamos el relay
   Serial.println("Relay apagado");
   
}
