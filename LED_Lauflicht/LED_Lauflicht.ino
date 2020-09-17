

/* LED Blinken im Sekundentakt
 * Sven Kloska
 * 11.09.2020
 * Arduino Uno (Chinakopie)
 * Grüne LED an Pin 3
 */


#define LED_GRN 4 //Variable für den Ausgangspin der LED Grün

unsigned long time = millis();  //Variable um die Zeit zu speichern für das Blinken

bool GRN_Status = false;  //Variable für den Status, den die LED haben soll

void setup() {

//Pin zuweisen für die grüne LED
  pinMode(LED_GRN, OUTPUT);

//Initialisiere die serielle Kommunikation
  Serial.begin(9600);

}


void loop() {


  if(millis()-time > 1000)     //Millis gibt die Laufzeit wieder, ist diese abzüglich time größer 1000 wird die Bedingung ausgeführt
  {
    GRN_Status = !GRN_Status;         //Invertiere den Status der LED
    digitalWrite(LED_GRN, GRN_Status);  //Schreibe den neuen Zustand
    time = millis();           //Schreibe die aktuelle Zeit in time, damit Laufzeit minus time 0 ergibt
  }


//Debugging Ausgabe:
Serial.print ("time: ");
Serial.print (time);
Serial.print (" Status Grüne: ");
Serial.println (GRN_Status);
//Serial.println (millis);

  
}
