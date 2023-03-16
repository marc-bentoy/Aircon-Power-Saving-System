#include <IRremote.h>

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(3, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    String ir_code = String(IrReceiver.decodedIRData.command, HEX);
    Serial.println(ir_code);

    IrReceiver.resume();
  }
}