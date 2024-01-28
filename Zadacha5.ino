#include <Arduino.h>
const int THERMISTOR_PIN = A0;
const float R0 = 10000; // номинальное сопротивление (Ом)
const float T0 = 298.15; // номинальная температура (Кельвины)
const float B = 3650; // бета-коэффициент

float getTemperature() {
  int raw = analogRead(THERMISTOR_PIN);
  float resistance = 10000.0 / ((1023.0 / raw) - 1); // рассчитываем сопротивление термистора
  float temperature = 1.0 / ((1.0 / T0) + (1.0 / B) * log(resistance / R0)); // рассчитываем температуру
  temperature -= 273.15; // переводим в градусы Цельсия
  return temperature;
}

void heat() {
  float temperature = getTemperature();
  if (temperature < 8) {
    Serial.println("Нагрев");
    // здесь должна быть логика управления нагревательным элементом
  }
}

void setup() {
  Serial.begin(9600); // инициализация монитора порта
}

void loop() {
  heat(); // проверяем температуру и работаем с нагревательным элементом
  delay(1000); // задержка 1 секунда
}
