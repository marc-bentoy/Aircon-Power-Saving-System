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

/* IR REMOTE VALUES */
const String IR_TEMP_DOWN = "b";        // ***
const String IR_TEMP_UP = "7";          // to be change depending on the 
const String IR_POWER = "2";            // specific remote signal values 
const String IR_POWER_SAVING = "68";    // *** 

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
    // analyze actual temperature and desired tempearture 
    // perform necessary action best fit on the desired and actual temperature
    // read voltage
    // read current
    // calculate power
    // display temperature and power
}

void readIRremote() {
    /* TODO */
    /* read IRremote signals */
    /* perform specific actions based on the signal read */
    // if ir_signal == b (volume down)
        // decrease the desired temperature by 1 degree celsius 
    // if ir_signal == 7 (volume up)
        // increase the temperature by 1 degree celsius 
    // if ir_signal == 2 (power)
        // to be added
    // if ir_signal == 68 (enter)
        // toggle power saving mode after a period of time
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

    // serial output for debugging
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.print(F("%  Temperature: "));
    Serial.print(temperature);
    Serial.print(F("°C "));
    Serial.print(F(" Heat index: "));
    Serial.print(heatIndex);
    Serial.println(F("°C "));
}

void analyzeTemperatures() {
    // 
}

void reachDesiredTemperature() {
    // if not in power saving mode, desired temperature can be anything
        // if actual temperature < desired temperature
            // turn on relay
        // if actual temperature > desired temperature
            // turn off relay
        // return
    // if in power saving mode, desired temperature can only be between 24-27 inclusive
        // if desired temperature is greater than MAX_POWER_SAVING_TEMP or desired temperature is lesser than MIN_POWER_SAVING_TEMP
            // return
        // if actual temperature < desired temperature
            // turn on relay
        // if actual temperature > desired temperature
            // turn off relay
}