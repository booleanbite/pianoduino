/*
  booleanbite.com: este ejemplo permite crear un pequeo piano con algunas notas
  a traves de USB. Este ejemplo se basa en el tutorial:
 
 http://arduino.cc/en/Tutorial/Tone
  Fecha: 28/12/2014
  Autor: Booleanbite
 */
 #include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

void setup() {
  //Inicializacion del puerto serie
  Serial.begin(9600);
  //El siguiente fragmento de codigo simplemente inicializa una melodia para probar
  //que funciona correctamente.
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  //Si hay datos disponibles en el puerto serie
  if(Serial.available()){
     char note = Serial.read(); //Leemos el caracter
      switch(note){
       case 'a':
       case 'A':
          makeTone(NOTE_C4); //DO
         break;
       case 's':
       case 'S':
          makeTone(NOTE_D4); //RE
          break;
        case 'd':
       case 'D':
          makeTone(NOTE_E4); //MI
          break;
        case 'f':
       case 'F':
          makeTone(NOTE_F4); //FA
          break;
        case 'g':
       case 'G':
          makeTone(NOTE_G4); //SOL
          break;
        case 'h':
       case 'H':
          makeTone(NOTE_A4); //LA
          break;
         case 'j':
       case 'J':
          makeTone(NOTE_B4); //SI
          break;
         case 'k':
       case 'K':
          makeTone(NOTE_C5); //DO
          break;
      }
  }
  
}
//Crea una nota que dura 1/4 a traves del pin 8.
void makeTone(int melody){
  tone(8,melody,1000/4);
  delay((1000/4)*1.30);
  noTone(8);
}
