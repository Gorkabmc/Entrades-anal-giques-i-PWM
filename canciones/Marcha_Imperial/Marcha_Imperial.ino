/**********************************************************************************
**                                                                               **
**                        Piratas del caribe                                     **
**                                                                               **
** GORKA FERNÁNDEZ RAMOS                                       07/05/2017        **
**********************************************************************************/
#define DO4  262
#define RE4  294
#define MI4  330
#define FA4  349
#define FAS4  370
#define SOL4  392
#define LA4  440
#define LAS4  466
#define SI4  494
#define DO5  523
#define RE5  587

// Pins de I/O
#define SPKPIN        7
#define TRANSPOSEPIN  3
#define SHUFFLEPIN    4
#define SPEEDPIN      1
#define LED           13
#define LED1          22
#define LED2          26
#define LED3          30
#define LED4          34
#define LED5          38

// Estado de los LEDs
boolean ledState = LOW;
boolean led1State = HIGH;
boolean led2State = LOW;
boolean led3State = HIGH;
boolean led4State = LOW;
boolean led5State = HIGH;

// Duracion inicial de la nota
int noteDuration = 500;
// Delay para tocar la siguiente nota
int noteDelay = noteDuration + 50;

// Valores para shuffle de la duracion de notas
int staccato = 0;
int shuffle = 0;

// Variables para hacer transpose a las notas
int transposedNote;
int transpose = 0;

// Array de notas para We Wish You A Merry Christmas
int notes[54] = {
  DO4, FA4, FA4, SOL4, FA4, MI4, RE4, RE4, RE4, SOL4, SOL4, LA4, SOL4, FA4, MI4, DO4, DO4,
  LA4, LA4, LAS4, LA4, SOL4, FA4, RE4, DO4, DO4, RE4, SOL4, MI4, FA4, DO4, FA4, FA4, FA4,
  MI4, MI4, FA4, MI4, RE4, DO4, SOL4, LA4, SOL4, SOL4, FA4, FA4, DO5, DO4, DO4, DO4,
  RE4, SOL4, MI4, FA4
};

// Array de duracion de las notas
// Entre mas alto el valor mas corta la nota
int durations[54] = {
  2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2,
  2, 3, 3, 3, 3, 2, 2, 3, 3, 2, 2, 2, 1, 2, 2, 2, 2,
  1, 2, 2, 2, 2, 1, 2, 2, 3, 3, 3, 3, 2, 2, 3, 3,
  2, 2, 2, 1
};

void setup() {
  // Inicializar los pins como OUTPUT
  pinMode(SPKPIN, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  // Inicializar el puerto serial para imprimir el valor de la nota
  // en el monitor serial
  Serial.begin(9600);
}

void loop() {
  // hacemos un for loop de todas las notas en el array notes
  for (int i=0; i < sizeof(notes) / sizeof(int); i++) {
    // Para implementar el shuffle hay que poner un potenciometro en
    // el pin definido como SHUFFLEPIN (4)
    /*
    shuffle = analogRead(SHUFFLEPIN);
     staccato = random(10, map(shuffle, 0, 1023, 10, 200));
     */

    // Se lee el valor del potenciometro en TRANSPOSEPIN
    // que nos da un numero del 0 al 1023
    // con la funcion map() lo mapeamos de 1 a 5
    transpose = map(analogRead(TRANSPOSEPIN), 0, 1023, 1, 5);

    // Se guarda en la variable transposedNote
    // la frecuencia de la nota actual mas
    // la nota actual multiplicado por el valor de transpose
    transposedNote = notes[i] + (notes[i] * transpose);

    // Imprimimos en el monitor serial la frecuencia que se
    // esta tocando por el buzzer
    Serial.println(transposedNote);

    // leemos el valor del potenciometro en el SPEEDPIN
    // y lo mapeamos de 800 a 100
    noteDuration = map(analogRead(SPEEDPIN), 0, 1023, 800, 100);

    // Dividimos el valor de noteDuration entre la duracion de la nota actual
    // y le sumamos el staccato (shuffle)
    noteDelay = (noteDuration / durations[i]) + staccato;

    // Enviamos al buzzer conectado al SPKPIN, la frecuencia de la nota
    // por una duracion de noteDuration entre la duracion de la nota actual
    // menos el valor de staccato
    tone(SPKPIN, transposedNote, (noteDuration / durations[i]) - staccato);
    // detenemos el programa con la funcion delay() por la duracion
    // guardada en noteDelay (milisegundos: 1000 = 1 segundo)
    delay(noteDelay);
    // Le decimos al buzzer que deje de sonar
    // (esto no estoy seguro sea necesario cuando solo se este usando un buzzer)
    noTone(SPKPIN);

    // Enviamos los valores guardados en las variables
    // ledState a los LEDs conectados a los pins definidos en
    // LED, LED1..., LED5
    digitalWrite(LED, ledState);
    digitalWrite(LED1, led1State);
    digitalWrite(LED2, led2State);
    digitalWrite(LED3, led3State);
    digitalWrite(LED4, led4State);
    digitalWrite(LED5, led5State);
    // invertimos los valores de las variables guardadas en
    // cada una de estas variables
    // (si ledState era LOW, ahora es HIGH)
    // En Arduino LOW = false, HIGH = true 
    ledState = !ledState;
    led1State = !led1State;
    led2State = !led2State;
    led3State = !led3State;
    led4State = !led4State;
    led5State = !led5State;
  }
  // Terminamos el for loop!

  // Esperamos para repetir todo el programa
  // la cantidad de noteDelay * 1 (milisegundos)
  delay(noteDelay * 2);
}
