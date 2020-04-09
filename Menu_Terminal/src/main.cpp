#include <Arduino.h>

int valor1, valor2, resultado;

void Menu(){
  Serial.println("");
  Serial.println("|****************************|");
  Serial.println("|**|      Bienvenidos     |**|");
  Serial.println("|**|         Menu         |**|");
  Serial.println("|****************************|");
  Serial.println("");
  Serial.println("Seleccione una de las siguientes opciones:");
  Serial.println("1.- Suma de dos números");
  Serial.println("2.- Resta de dos números");
  Serial.println("3.- Divide dos números");
  Serial.println("4.- Multiplica dos números");
  Serial.println("5.- Salir");

  while(!Serial.available()){}
  int i = Serial.parseInt();
  Serial.println("Opción: " + String(i));

  switch(i) {
  case 1:
    Serial.print("Valor 1: ");
    while(!Serial.available()){}
    valor1 = Serial.parseInt();
    Serial.println(String(valor1));
    Serial.print("Valor 2: ");
    while(!Serial.available()){}
    valor2 = Serial.parseInt();
    Serial.println(String(valor2));
    resultado = valor1 + valor2;
    Serial.println("La suma es: " + String(resultado));
    break;
  case 2:
    Serial.println("Resta");
    break;
  case 3:
    Serial.println("División"); 
    break;
  case 4:
    Serial.println("Multiplicación"); 
    break;
  case 5:
    Serial.println("Salida inminente...!"); 
    while (true);  
    break;
  default:
    Serial.println("Opción invalida");
    break;
    } 
 }

void setup() {
  Serial.begin(115200);
}

void loop() {
  Menu();
}