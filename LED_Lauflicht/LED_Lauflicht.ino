

/* Arduino Lauflicht
   Sven Kloska
   17.09.2020
   Arduino Uno (Chinakopie)
   LEDs an Pins 4, 5, 6, 7
*/


byte led[8] = {2, 3, 4, 5, 6, 7, 8, 9};

byte ledZustand[10][8] = {
  {1, 0, 0, 0, 0, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
};

int takt = 0;  //Der Takt für die LEDs in Millisekunden

int counter = 0;  //Zählvariable für die LED

unsigned long time = millis();  //Variable um die Zeit zu speichern für das Blinken

#define buttonPin 10
bool button = false;


void setup() {

  //Pins zuweisen für die LEDs
  for (byte i = 0; i < 8; i++)
  {
    pinMode(led[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT);

  //Initialisiere die serielle Kommunikation
  Serial.begin(9600);

}


void loop() {



  /*  for (byte i = 0; i < 10; i++)  //Zeilen
    {
      for (byte j = 0; j < 8; j++)  //Spalten
      {
        digitalWrite(led[j], ledZustand[i][j]);

      }
      delay(takt);
    }
  */

  button = digitalRead(buttonPin);


  digitalWrite(led[0], button);

  if (button == true)
  {
    Serial.println("LED ist an");
  }
  else
  {
    Serial.println("LED ist aus");
  }

}
