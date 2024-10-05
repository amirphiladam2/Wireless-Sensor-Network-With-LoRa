/* Author:Amir Philip Adam
   Email:amirphiladam@gmail.com
   WhatsApp:+919878036979
*/
//This is a code for Transmitting sensor data (temperature,pressure and light intensity) through LoRa
#include <Wire.h>
#include <Adafruit_BMP280.h>   
#include <BH1750.h>            
#include <LoRa.h>              

// Create sensor objects
Adafruit_BMP280 bmp;           
BH1750 lightMeter;

#define LORA_SCK 18
#define LORA_MISO 19
#define LORA_MOSI 23
#define LORA_SS 5
#define LORA_RST 14
#define LORA_DIO0 26

void setup() {
  
  Serial.begin(9600);

  
  Wire.begin();
  
  
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
  if (!lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("Error initializing BH1750"));
    while (1);
  }
  
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0); 

  if (!LoRa.begin(433E6)) {  
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  Serial.println("LoRa Initialized");
}

void loop() {
  
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F;  
  float lightLevel = lightMeter.readLightLevel(); 
  
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" hPa");
  
  Serial.print("Light Intensity = ");
  Serial.print(lightLevel);
  Serial.println(" lux");
  
  String dataToSend = String(temperature) + "," + String(pressure) + "," + String(lightLevel);
  
  Serial.print("Sending data: ");
  Serial.println(dataToSend);

  LoRa.beginPacket();
  LoRa.print(dataToSend);  
  LoRa.endPacket();        

  delay(5000);  
}
