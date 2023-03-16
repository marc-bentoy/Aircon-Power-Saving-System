#include <IRremote.h>
#include <DHT.h>

/* PIN CONFIGURATION */
#define DHT_PIN 2
#define DHT_TYPE DHT11
#define IR_PIN 3

/* SYSTEM VARIABLES */
float temperature = 0;
float humidity = 0;
float heatIndex = 0;

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    // Initializes Serial for debugging
    Serial.begin(9600);

    // Starts up IR sensor
    IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

    // Starts up DHT sensor
    dht.begin();
}

void loop() {
    // read IRremote
    // read Temperature
    // read system settings
    // analyze temperature and system settings
    // perform necessary action best fit on the settings and temperature
    // read voltage
    // read current
    // calculate power
    // display temperature and power
}

void readTemperature() {
    // Wait a few seconds between measurements.
    delay(2000);

    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    humidity = dht.readHumidity();
    // Read temperature as Celsius (the default)
    temperature = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    // Compute heat index in Celsius (isFahreheit = false)
    heatIndex = dht.computeHeatIndex(temperature, humidity, false);

    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.print(F("%  Temperature: "));
    Serial.print(temperature);
    Serial.print(F("°C "));
    Serial.print(F(" Heat index: "));
    Serial.print(heatIndex);
    Serial.println(F("°C "));
}