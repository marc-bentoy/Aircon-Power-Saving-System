#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte binFull[] = {
	0x00,
	0x11,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
	0x0E
};

byte binEmpty[] = {
	0x00,
	0x11,
	0x11,
	0x11,
	0x11,
	0x11,
	0x11,
	0x0E
};

byte lightning2[] = {
	0x00,
	0x02,
	0x04,
	0x0C,
	0x1F,
	0x06,
	0x04,
	0x08
};

byte degreeCelsius[] = {
	0x00,
	0x10,
	0x06,
	0x09,
	0x08,
	0x08,
	0x09,
	0x06
};

byte lock[] = {
	0x00,
	0x0E,
	0x11,
	0x11,
	0x1F,
	0x1B,
	0x1B,
	0x1F
};

byte arrowUp[] = {
	0x1F,
	0x1B,
	0x11,
	0x0A,
	0x1B,
	0x1B,
	0x1B,
	0x1F
};

byte arrowDown[] = {
	0x1F,
	0x1B,
	0x1B,
	0x1B,
	0x0A,
	0x11,
	0x1B,
	0x1F
};

byte check[] = {
	0x00,
	0x01,
	0x03,
	0x16,
	0x1C,
	0x08,
	0x00,
	0x00
};

void setup()
{
	// initialize the LCD
	lcd.init();

	// Turn on the blacklight and print a message.
	lcd.backlight();

	// creates custom characters 
	lcd.createChar(0, binFull);
    lcd.createChar(1, binEmpty);
    lcd.createChar(6, degreeCelsius);
    lcd.createChar(7, lightning2);
    lcd.createChar(8, lock);
    lcd.createChar(9, arrowUp);
    lcd.createChar(10, arrowDown);
    lcd.createChar(11, check);
}

void loop()
{
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.write(7); 			// lightning
    lcd.setCursor(2, 0);
    lcd.print("800 W");		// power consumption

	lcd.setCursor(9, 0);
	lcd.write(9);			// arrowUp

	lcd.setCursor(12, 0);
	lcd.print("18");		// temperature

	lcd.setCursor(15, 0); 	
	lcd.write(6);			// degree celsius

	lcd.setCursor(2, 1);
    lcd.print("NORMAL MODE");	// operation mode
	delay(2500);

	lcd.clear();
	lcd.setCursor(0,0);
	lcd.write(7);
    lcd.setCursor(2, 0);
    lcd.print("500 W");

	lcd.setCursor(9, 0);
	lcd.write(11);			// arrowUp

	lcd.setCursor(12, 0);
	lcd.print("24");		// temperature

	lcd.setCursor(15, 0); 	
	lcd.write(6);			// degree celsius

	lcd.setCursor(1, 1);
    lcd.print("POWER SAVING");
	lcd.setCursor(14, 1);
	lcd.write(8);
	delay(2500);
}