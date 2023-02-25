'''
IE-0624 Laboratorio de Microcontroladores
Alexa Carmona Buzo B91643
Raquel Corrales Marin B92378
Laboratorio 5
GPIO, Giroscopio, comunicaciones, TinyML
'''

#include <Arduino_LSM9DS1.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Inicio");

  if (!IMU.begin()) {
    Serial.println("No fue posible iniciar el IMU");
    while (1);
  }

  Serial.println("Aceleración en g's");
  Serial.println();
  Serial.print("Sample rate del acelerometro: ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");

  Serial.println("Giroscopio en grados/segundo");
  Serial.println();
  Serial.print("Sample rate del giroscopio: ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
 
  Serial.println("ac_X\tac_Y\tac_Z\tgc_X\tgc_Y\tgc_Z");
}

void loop() {
  float acX, acY, acZ, gcX, gcY, gcZ;

  if (IMU.gyroscopeAvailable() && IMU.accelerationAvailable()) {
    IMU.readAcceleration(acX, acY, acZ);
    IMU.readGyroscope(gcX, gcY, gcZ);

    Serial.print(acX);
    Serial.print('\t');
    Serial.print(acY);
    Serial.print('\t');
    Serial.print(acZ);
    Serial.print('\t');
    Serial.print(gcX);
    Serial.print('\t');
    Serial.print(gcY);
    Serial.print('\t');
    Serial.println(gcZ);
  }
}
