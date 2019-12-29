//5 leds positionnees Pin 2,4,6,8,10

int pinLed[5]={2, 4, 6, 8, 10}; //Tableau listant les pins

//tableau a double entrée : 25 séquences et l'etat des 5 leds. Premier chiffre les colonnes, 2eme chiffre les leds
boolean affichage[8][5]={
  1,0,0,0,0,
  0,1,0,0,0,
  0,0,1,0,0,
  0,0,0,1,0,
  0,0,0,0,1,
  0,0,0,1,0,
  0,0,1,0,0,
  0,1,0,0,0};


void setup() {
  //boucle pour indiquer le mode de fonctionnement des pins et éteindre les leds
  Serial.begin(9600); //Initialisation de la communication
  Serial.println(pinLed[0]);
  Serial.println(pinLed[1]);
  Serial.println(pinLed[2]);
  Serial.println(pinLed[3]);
  Serial.println(pinLed[4]);

  for (int i=0;i<5;i++)
  {
    pinMode(pinLed[i], OUTPUT);
    Serial.println (i);
    //delay(1000);
    Serial.println(pinLed[i]);
    //delay(1000);
    digitalWrite(pinLed[i],HIGH);
  }
}


void loop() {
  // boucle de séquences d'affichage, on parcours les 25 colonnes compteur i
  for (int i=0;i<8;i++)
  {
    for (int p=0;p<5;p++) // boucle d'etat des lignes de pins, compteur P
    
    {
      Serial.println(i);
      Serial.println(p);
      //delay(90);
      boolean etat=affichage[i][p]; // on récupére la valeur du tableau dans la variable etat
      digitalWrite(pinLed[p],etat); // on met chaque ligne de la led dans l'etat correspondant
    }
    delay(200); // 200 M seconde entre chaque séquence
  }
//  fin des séquences, on repart au début

}
