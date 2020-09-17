

/* Arduino Lauflicht
   Sven Kloska
   11.09.2020
   Arduino Uno (Chinakopie)
   Grüne LED an Pin 3
*/


#define LED_1 4 //Variablen für die Ausgangspins der LEDs
#define LED_2 5
#define LED_3 6
#define LED_4 7

#define Takt 1000  //Der Takt für die LEDs in Millisekunden

int counter = 0;

unsigned long time = millis();  //Variable um die Zeit zu speichern für das Blinken

bool GRN_Status = false;  //Variable für den Status, den die LED haben soll

void setup() {

  //Pins zuweisen für die LEDs
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

  //Initialisiere die serielle Kommunikation
  Serial.begin(9600);

}


void loop() {


  if (millis() - time > Takt)  //Millis gibt die Laufzeit wieder, ist diese abzüglich time größer 1000 wird die Bedingung ausgeführt
  {
    counter = counter + 1;  //Zähle die counter-Variable hoch um die nächste LED anzusteuern
    time = millis(); //Schreibe die aktuelle Zeit in time, damit Laufzeit minus time 0 ergibt
  }
  if (counter == 5) //wenn der counter außerhalb des Bereichs ist wird dieser auf 1 zurückgesetzt
  {
    counter = 1;
  }


LEDs:
  //Wenn die Variable i den Wert für die LED hat wird der Ausgang der LED eingeschaltet, sonst aus
  if (counter == 1)
  {
    digitalWrite(LED_1, HIGH);
  }
  else
  {
    digitalWrite(LED_1, LOW);
  }
  if (counter == 2)
  {
    digitalWrite(LED_2, HIGH);
  }
  else
  {
    digitalWrite(LED_2, LOW);
  }
  if (counter == 3)
  {
    digitalWrite(LED_3, HIGH);
  }
  else
  {
    digitalWrite(LED_3, LOW);
  }
  if (counter == 4)
  {
    digitalWrite(LED_4, HIGH);
  }
  else
  {
    digitalWrite(LED_4, LOW);
  }




  //Debugging Ausgabe:
  Serial.print ("Variable ");
  Serial.print (counter);
  Serial.print (" Time ");
  Serial.println (time);

  //Serial.println (millis);


}
