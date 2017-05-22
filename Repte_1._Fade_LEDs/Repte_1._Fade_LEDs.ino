
**                                                                               **
**                                Programa 1                                     **
**                                                                               **
**   NOM: Gorka Fernández Ramos                           DATA: 06 / 03 / 2017   **
**********************************************************************************/
//********** INCLUDE **************************************************************

//********** VARIABLES ************************************************************
int LED5 = 5;                         // LED5 es el pin digital 5
int LED6 = 6;                         // LED6 es el pin digital 6
int LED7 = 7;                         // LED7 es el pin digital 7
int LED8 = 8;                         // LED8 es el pin digital 8
int LED9 = 9;                         // LED9 es el pin digital 9
int LED10 = 10;                       // LED10 es el pin digital 10
int LED11 = 11;                       // LED11 es el pin digital 11
int LED12 = 12;                       // LED12 es el pin digital 12

//********** SETUP ****************************************************************
void setup() 
{                                     // S'executa un sol cop

  pinMode(LED5, OUTPUT);              // Configura el pin 5 com a sortida
  pinMode(LED6, OUTPUT);              // Configura el pin 6 com a sortida
  pinMode(LED7, OUTPUT);              // Configura el pin 7 com a sortida
  pinMode(LED8, OUTPUT);              // Configura el pin 8 com a sortida
  pinMode(LED9, OUTPUT);              // Configura el pin 9 com a sortida
  pinMode(LED10, OUTPUT);             // Configura el pin 10 com a sortida
  pinMode(LED11, OUTPUT);             // Configura el pin 11 com a sortida
  pinMode(LED12, OUTPUT);             // Configura el pin 12 com a sortida

}

//********** LOOP *****************************************************************
void loop() 
{                                     // S'executa repetidament 
  
  digitalWrite(LED5, HIGH);           // Activa el LED 5
  digitalWrite(LED6, HIGH);           // Activa el LED 6
  digitalWrite(LED7, HIGH);           // Activa el LED 7
  digitalWrite(LED8, HIGH);           // Activa el LED 8
  digitalWrite(LED9, HIGH);           // Activa el LED 9
  digitalWrite(LED10, HIGH);          // Activa el LED 10
  digitalWrite(LED11, HIGH);          // Activa el LED 11
  digitalWrite(LED12, HIGH);          // Activa el LED 12
  
  delay(1000);                        // Espera un segon
  
  digitalWrite(LED5, LOW);            // Desactiva el LED 5
  digitalWrite(LED6, LOW);            // Desactiva el LED 6
  digitalWrite(LED7, LOW);            // Desactiva el LED 7
  digitalWrite(LED8, LOW);            // Desactiva el LED 8
  digitalWrite(LED9, LOW);            // Desactiva el LED 9
  digitalWrite(LED10, LOW);           // Desactiva el LED 10
  digitalWrite(LED11, LOW);           // Desactiva el LED 11
  digitalWrite(LED12, LOW);           // Desactiva el LED 12
  
  delay(1000);                        // Espera un segon
  
}

//********** FUNCIONS *************************************************************

