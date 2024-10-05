/* Author:Amir Philip Adam
   Email:amirphiladam@gmail.com
   WhatsApp:+919878036979
*/
//This is a code for receiving sensor data (temperature,pressure and light intensity) through LoRa
#include <LoRa.h>
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// LoRa Pin Definitions for ESP8266
#define LORA_SS 15  // GPIO 15 (D8)
#define LORA_RST 16  // GPIO 16 (D0)
#define LORA_DIO0 4  // GPIO 4 (D2)

void setup() {
  Serial.begin(9600);
  
  // Initialize OLED Display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED allocation failed");
    for (;;);
  }
  display.clearDisplay();
  
  // Initialize LoRa
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);  // Set LoRa pins
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed.");
    while (true);
  }
  Serial.println("LoRa init succeeded.");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String incoming = "";
    while (LoRa.available()) {
      incoming += (char)LoRa.read();
    }

    // Print received data to Serial Monitor
    Serial.println("Received packet: " + incoming);
    
    // Split incoming string by commas
    String temperature = getValue(incoming, ',', 0);
    String pressure = getValue(incoming, ',', 1);
    String lightIntensity = getValue(incoming, ',', 2);

    // Display received data on OLED
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Received Data:");
    display.println("Temp: " + temperature + " C");
    display.println("Pressure: \n" + pressure + " hPa");
    display.println("Light: \n" + lightIntensity + " lx");
    display.display();  // Update the display
  }
}

// Helper function to parse CSV data
String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
