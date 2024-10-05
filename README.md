# Wireless-Sensor-Network-With-LoRa
We transmit sensor data to the receiving station using LoRa

Introduction

In this project, I’ll show you how to build a wireless sensor network using ESP32 as a transmitter and ESP8266 as a receiver, communicating over LoRa. We’ll be using two sensors, BMP280 (for temperature and pressure) and BH1750 (for light intensity), to gather environmental data, which will be transmitted wirelessly using the LoRa SX1278 module. The data will then be displayed on an OLED screen connected to the ESP8266.

Why LoRa?

LoRa (Long Range) is a low-power, long-range communication technology perfect for IoT projects that need to send small amounts of data over long distances. It is ideal for remote monitoring, agriculture, environmental tracking, or any scenario where devices are spread over a wide area and need to conserve power.

Components and Tools

Here’s a list of all the components I used for this project:

Transmitter Circuit (ESP32)

- ESP32 microcontroller

- LoRa SX1278 transceiver module

- BMP280 (Temperature and Pressure sensor)

- BH1750 (Light intensity sensor)

- OLED Display (optional for monitoring on the transmitter side)

Receiver Circuit (ESP8266)

- ESP8266 microcontroller

- LoRa SX1278 transceiver module

- OLED Display for visualizing received data

Additional Items

- Breadboard and jumper wires (for prototyping)

- Soldered circuit for ESP8266 (receiver)

Software and Libraries

- Arduino IDE or PlatformIO (for programming the ESP32 and ESP8266)

- LoRa library

- Adafruit BMP280 and BH1750 libraries for sensor data

- Adafruit GFX and SSD1306 libraries for the OLED display

Transmitter Circuit Using ESP32

Wiring Diagram:



Below is the wiring for connecting the ESP32 to the LoRa SX1278, BMP280, and BH1750:

- LoRa SX1278 `VCC` → ESP32 `3.3V`

- LoRa SX1278 `GND` → ESP32`GND`

- LoRa SX1278 `MISO` → ESP32 `19` 

- LoRa SX1278`MOSI` → ESP32 `23`

- LoRa SX1278 `SCK` → ESP32 `18`

- LoRa SX1278 `NSS` → ESP32 `5`

- LoRa SX1278 `RST` → ESP32 `14`

- LoRa SX1278 `DIO0` → ESP32 `26`

BMP280 Sensor:

- BMP280 `VCC` → ESP32 `3.3V`

- BMP280`GND` → ESP32 `GND`

- BMP280 `SDA` → ESP32 `21`

- BMP280 `SCL` → ESP32 `22`

BH1750 Sensor:

- BH1750 `VCC` → ESP32 `3.3V`

- BH1750 `GND` → ESP32`GND`

- BH1750 `SDA` → ESP32 `21`

- BH1750 `SCL` → ESP32 `22`

Transmitter Code (ESP32):

Here’s the code for the ESP32 to read data from the BMP280 and BH1750 sensors, then send it over LoRa.

Receiver Circuit Using ESP8266

Wiring Diagram:



   

Here’s how to wire the ESP8266 with LoRa SX1278 and OLED:

- LoRa SX1278 `VCC` → ESP8266 `3.3V`

- LoRa SX1278`GND` → ESP8266 `GND`

- LoRa SX1278 `MISO` → ESP8266 `D6`

- LoRa SX1278 `MOSI` → ESP8266 `D7`

- LoRa SX1278 `SCK` → ESP8266 `D5`

- LoRa SX1278 `NSS` → ESP8266 `D8`

- LoRa SX1278 `RST` → ESP8266`D0`

- LoRa SX1278 `DIO0` → ESP8266 `D2`



Receiver Code (ESP8266):

The following code receives data over  LoRa, parses it, and displays it on the OLED.

Testing and Output

Once everything is wired and the code is uploaded, open the serial monitor on the receiver to check incoming data. You should see the sensor data (temperature, pressure, and light) being received every 5 seconds. The OLED will also display this data.

           Transmitter and receiver circuit.


                          The above figure shows transmitter and receiver circuit

           Display showing Data 



                                    The above figure shows Received Data on OLED

            Transmitter Serial Monitor readings



                      The above figure shows the transmitter serial monitor reading on PlatformIO.

           Receiver Serial Monitor readings




                   The above figure shows the receiver serial monitor reading on Arduino IDE.


Challenges and Debugging

- Pin Configuration: Ensure the correct SPI pin mappings for ESP32 and ESP8266 as they differ slightly.

- LoRa Frequency: Make sure both the transmitter and receiver are set to the same LoRa frequency (e.g., 433 MHz).

- Distance Testing: Test the range of communication in different environments (e.g., open field, indoors).

Conclusion

By using LoRa technology, I successfully built a simple wireless sensor network capable of sending and receiving environmental data over long distances with minimal power consumption. This setup is highly flexible and can be expanded with more sensors or even two-way communication.





