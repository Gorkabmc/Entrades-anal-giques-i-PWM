/**********************************************************************************
**                                                                               **
**                        Piratas del caribe                                     **
**                                                                               **
** GORKA FERNÁNDEZ RAMOS                                       07/05/2017        **
**********************************************************************************/

int ledPin = 13;
int speakerOut = 10;

/* 2 octavas :: semitones. 0 = do, 2 = re, etc. */
/* MIDI notes from 48 to 71. Indices here are from 0 to 23. */

int timeUpDown[] = {3822, 3606, 3404, 3214, 3032, 2862,
2702, 2550, 2406, 2272, 2144, 2024,
1911, 1803, 1702, 1607, 1516, 1431,
1351, 1275, 1203, 1136, 1072, 1012};
/* our song. Each number is a (MIDI note - 48) on a beat. */

//byte song[] = {12,12,12,14, 16,16,14,14, 12,16,14,14, 12,12,12,12,
//14,14,14,14, 9,9,9,9, 14,12,11,9, 7,7,7,7};
byte song[] = {7,7,7,12,12,12,16,16,7,7,7,12,12,12,16,16,16,16,16,16,16,12,12,11,11,9,9,7,7,7,7,7};
// do do do re mi re do mi re re do...

byte beat = 0;
int MAXCOUNT = 32;
float TEMPO_SECONDS = 0.2;
byte statePin = LOW;
byte period = 0;
int i, timeUp;

void setup() {
pinMode(ledPin, OUTPUT);
pinMode(speakerOut, OUTPUT);
}

void loop() {
digitalWrite(speakerOut, LOW);
for (beat = 0; beat < MAXCOUNT; beat++) {
statePin = !statePin;
digitalWrite(ledPin, statePin);

timeUp = timeUpDown[song[beat]];

period = ((1000000 / timeUp) / 2) * TEMPO_SECONDS;
for (i = 0; i < period; i++) {
digitalWrite(speakerOut, HIGH);
delayMicroseconds(timeUp);
digitalWrite(speakerOut, LOW);
delayMicroseconds(timeUp);
}
/* Uncomment this if you want notes to be discrete */
/* delay(50); */
}
digitalWrite(speakerOut, LOW);
delay(1000);
}
