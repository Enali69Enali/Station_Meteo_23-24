#define GIROUETTE 36


// Version pour le réseau R2R
// DUEE-MOREAU Arwen & PELLETIER Ilane

// Fev 2024

void girouette() {
  // on va prendre un résolution de 12 bits, cela donnera des valeur comprises entre 0 et 4096

  int sensorValue = analogRead(GIROUETTE);
  Serial.print(sensorValue);
  int directionVent;
  Serial.print("Girouette : ");

  if (sensorValue >4080){
    directionVent = 0; // Nord
    Serial.print("Nord \n");
  }
  else if (sensorValue > 3700 && sensorValue <= 4080){
    directionVent = 15; // Nord++ - Ouest
    Serial.print("Nord++ - Ouest \n");
  }

  else if (sensorValue > 3444 && sensorValue <= 3700){
    directionVent = 5; // Sud - Est++
    Serial.print("Sud - Est++ \n");
  }

  else if (sensorValue > 3072 && sensorValue <= 3328){
    directionVent = 10; // Sud - Ouest
    Serial.print("Sud - Ouest \n");
  }

  else if (sensorValue > 2816 && sensorValue <= 3072){
    directionVent = 7; // Sud++ - Est
    Serial.print("Sud++ - Est \n");
  }

  else if (sensorValue > 2560 && sensorValue <= 2816){
    directionVent = 8; // Sud
    Serial.print("Sud \n");
  }

  else if (sensorValue > 2304 && sensorValue <= 2560){
    directionVent = 6; // Sud - Est
    Serial.print("Sud - Est  \n");
  }

  else if (sensorValue > 2048 && sensorValue <= 2304){
    directionVent = 9; // Sud++ - Ouest
    Serial.print("Sud++ - Ouest \n");
  }

  else if (sensorValue > 1792 && sensorValue <= 2048){
    directionVent = 1; // Nord++ - Est
    Serial.print("Nord++ - Est \n");
  }

  else if (sensorValue > 1536 && sensorValue <= 1792){
    directionVent = 14; // Nord - Ouest
    Serial.print("Nord - Ouest \n");
  }

  else if (sensorValue > 1280 && sensorValue <= 1536){
    directionVent = 4; // Est
    Serial.print("Est \n");
  }

  else if (sensorValue > 1024 && sensorValue <= 1280){
    directionVent = 11; // Sud - Ouest++
    Serial.print("Sud - Ouest++ \n");
  }

  else if (sensorValue > 768 && sensorValue <= 1024){
    directionVent = 2; // Nord - Est
    Serial.print("Nord - Est \n");
  }

  else if (sensorValue > 384 && sensorValue <= 768){
    directionVent = 13; // Nord - Ouest++
    Serial.print("Nord - Ouest++ \n");
  }

  else if (sensorValue > 50 && sensorValue <= 384){
    directionVent = 3; // Nord - Est++
    Serial.print("Nord - Est++ \n");
  }

  else {
    directionVent = 12; // Ouest
    Serial.print("Ouest \n");
  }
  Serial.println(directionVent);
  //ds.donnees_girouette = static_cast<double>(directionVent);

}



/*
//PROJET STATION METEO
//AMBRE ALLOUIS - SOLENE GUILLAUME
//ANNEE 2022-2023

// Méthode permettant l'affichage de la direction du vent ************************ //
void Girouette() {
  int sensorValue = analogRead(GIROUETTE);
  int directionVent;
  if (sensorValue > 3216 && sensorValue <= 3600 )
  {
    directionVent = 12; // Ouest
  }
  if (sensorValue > 2869 && sensorValue <= 3216)
  {
    directionVent = 14; // Nord Ouest
  }
  if (sensorValue > 2646 && sensorValue <= 2869)
  {
    directionVent = 13; // Nord Ouest Ouest
  }
  if (sensorValue > 2417 && sensorValue <= 2646)
  {
    directionVent = 0; // Nord
  }
  if (sensorValue > 2121 && sensorValue <= 2417)
  {
    directionVent = 15; // Nord Nord Ouest
  }
  if (sensorValue > 1934 && sensorValue <= 2121)
  {
    directionVent = 10; // Sud Ouest
  }
  if (sensorValue > 1645 && sensorValue <= 1934)
  {
    directionVent = 11; // Sud Ouest Ouest
  }
  if (sensorValue > 1312 && sensorValue <= 1645)
  {
    directionVent = 2; // Nord Est
  }
  if (sensorValue > 1008 && sensorValue <= 1312)
  {
    directionVent = 1; // Nord Nord Est
  }
  if (sensorValue > 725 && sensorValue <= 1008)
  {
    directionVent = 8; // Sud
  }
  if (sensorValue > 543 && sensorValue <= 725)
  {
    directionVent = 9; // Sud Sud Ouest
  }
  if (sensorValue > 338 && sensorValue <= 543)
  {
    directionVent = 6; // Sud Est
  }
  if (sensorValue > 184 && sensorValue <= 338)
  {
    directionVent = 7; // Sud Sud Est
  }
  if (sensorValue > 111 && sensorValue <= 184)
  {
    directionVent = 4; // Est
  }
  if (sensorValue > 64 && sensorValue <= 111)
  {
    directionVent = 3; // Nord Est Est
  }
  if (sensorValue > 1 && sensorValue <= 64)
  {
    directionVent = 5; // Sud Est Est
  }
  Serial.print("Girouette : ");
  Serial.println(directionVent);
  ds.donnees_girouette = static_cast<double>(directionVent);
}
*/
