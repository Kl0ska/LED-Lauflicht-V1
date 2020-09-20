

/* Arduino Lauflicht
   Sven Kloska
   17.09.2020
   Arduino Uno (Chinakopie)
   LEDs an Pins 4, 5, 6, 7
*/


byte led[4] = {4, 5, 6, 7};

#define Takt 10000  //Der Takt für die LEDs in Millisekunden

int counter = 0;  //Zählvariable für die LED

unsigned long time = millis();  //Variable um die Zeit zu speichern für das Blinken




void setup() {

  //Pins zuweisen für die LEDs

  for (byte i = 0; i < 4; i++)
  {
    pinMode(led[i], OUTPUT);
  }

  //Initialisiere die serielle Kommunikation
  Serial.begin(9600);

}


void loop() {

  /*
    if (millis() - time > Takt)  //Millis gibt die Laufzeit wieder, ist diese abzüglich time größer 1000 wird die Bedingung ausgeführt
    {
      counter = counter + 1;  //Zähle die counter-Variable hoch um die nächste LED anzusteuern
      time = millis(); //Schreibe die aktuelle Zeit in time, damit Laufzeit minus time 0 ergibt
    }
    if (counter == 5) //wenn der counter außerhalb des Bereichs ist wird dieser auf 1 zurückgesetzt
    {
      counter = 1;
    }
  */
  int i = 0;


  for (i = 0; i < 4; i++)
  {
    digitalWrite(led[i], HIGH);
    delay(500);
  }
  for (i = 4; i >= 0; i--)
  {
    digitalWrite(led[i], LOW);
    delay(500);
  }



  /*
    LEDs:
    //Wenn die Variable counter den Wert für die LED hat wird der Ausgang der LED eingeschaltet, sonst aus
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


  */

  //Debugging Ausgabe:
  Serial.print ("Variable ");
  Serial.print (counter);
  Serial.print (" Time ");
  Serial.println (time);

  //Serial.println (millis);


}
