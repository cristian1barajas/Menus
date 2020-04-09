#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

WidgetTerminal terminal(V1);

char auth[] = "H9fCjQrQJOFJMgFkcafoi0eL124cYQCJ";
char ssid[] = "BotLAB";
char pass[] = "01010101";

int valor1, valor2, resultado, valorEntero;
String opcion;
int cont = 0;

void reset() {
  terminal.println("");
  terminal.print("             ");
  for (int i = 0; i < 4; i++) {
    terminal.print("*");
    terminal.flush();
    delay(500);
  }
  terminal.print("Thanks...!");
  terminal.flush();
  for (int i = 0; i < 4; i++) {
    terminal.print("*");
    terminal.flush();
    delay(500);
  }
}

void menu() {
  terminal.clear();
  terminal.println(F("       |****************************|"));
  terminal.println(F("       |**|      Bienvenidos     |**|"));
  terminal.println(F("       |**|         Menu         |**|"));
  terminal.println(F("       |****************************|"));
  terminal.println("");
  terminal.println("Seleccione una de las siguientes opciones:");
  terminal.println("1.- Suma de dos numeros");
  terminal.println("2.- Resta de dos numeros");
  terminal.println("3.- Divide dos numeros");
  terminal.println("4.- Multiplica dos numeros");
  terminal.println("5.- Salir");
  terminal.flush();
}

BLYNK_WRITE(V1) {
  String i = param.asStr();
  cont++;
  switch (cont)
  {
  case 1:
    opcion = i;
    valorEntero = opcion.toInt();
    switch (valorEntero)
    {
    case 1:
      terminal.println("Suma");
      terminal.println("Valor 1: ");
      break;
    case 2:
      terminal.println("Resta");
      terminal.println("Valor 1: ");
      break;
    case 3:
      terminal.println("Division");
      terminal.println("Valor 1: ");
      break;
    case 4:
      terminal.println("Multiplicacion");
      terminal.println("Valor 1: ");
      break;
    case 5:
      terminal.println("Salida inminente!");
      cont = 0;
      reset();
      menu();
      break;
    default:
      terminal.println("Opcion invalida");
      cont = 0;
      reset();
      menu();
      break;
    }
    terminal.flush();
    break;
  case 2:
    valor1 = i.toInt();
    terminal.println("Valor 2: ");
    terminal.flush();
    break;
  case 3:
    valor2 = i.toInt();
    switch (valorEntero)
    {
    case 1:
      resultado = valor1 + valor2;
      terminal.println("La suma es: " + String(resultado));
      reset();
      menu();
      break;
    case 2:
      resultado = valor1 - valor2;
      terminal.println("La resta es: " + String(resultado));
      reset();
      menu();
      break;
    case 3:
      resultado = valor1 / valor2;
      terminal.println("La division es: " + String(resultado));
      reset();
      menu();
      break;
    case 4:
      resultado = valor1 * valor2;
      terminal.println("La multiplicacion es: " + String(resultado));
      reset();
      menu();
      break;
    }
    cont = 0;
    terminal.flush();
    break;
  }
}

void setup() {
  Blynk.begin(auth, ssid, pass);
  terminal.clear();
  menu();
}

void loop() {
  Blynk.run();
}