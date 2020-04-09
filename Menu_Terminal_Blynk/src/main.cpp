#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

WidgetTerminal terminal(V1);

char auth[] = "H9fCjQrQJOFJMgFkcafoi0eL124cYQCJ";
char ssid[] = "BotLAB";
char pass[] = "01010101";

int valor1, valor2, resultado;
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
  if (cont == 1) {
    opcion = i;
    if (opcion == "1") {
      terminal.println("Suma");
      terminal.println("Valor 1: ");
    } else if (opcion == "2") {
        terminal.println("Resta");
        terminal.println("Valor 1: ");
      } else if (opcion == "3") {
          terminal.println("Division");
          terminal.println("Valor 1: ");
        } else if (opcion == "4") {
            terminal.println("Multiplicacion");
            terminal.println("Valor 1: ");
          } else if (opcion == "5") {
              terminal.println("Salida inminente!");
              cont = 0;
              reset();
              menu();
            } else {
                terminal.println("Opcion invalida");
                cont = 0;
                reset();
                menu();
              }
    terminal.flush();
  } else if (cont == 2) {
      valor1 = i.toInt();
      terminal.println("Valor 2: ");
      terminal.flush();
    } else if (cont == 3) {
      valor2 = i.toInt();
      if (opcion == "1") {
        resultado = valor1 + valor2;
        terminal.println("La suma es: " + String(resultado));
        reset();
        menu();
      } else if (opcion == "2") {
          resultado = valor1 - valor2;
          terminal.println("La resta es: " + String(resultado));
          reset();
          menu();
        } else if (opcion == "3") {
            resultado = valor1 / valor2;
            terminal.println("La division es: " + String(resultado));
            reset();
            menu();
          } else if (opcion == "4") {
              resultado = valor1 * valor2;
              terminal.println("La multiplicacion es: " + String(resultado));
              reset();
              menu();
            }
      cont = 0;
      terminal.flush();
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