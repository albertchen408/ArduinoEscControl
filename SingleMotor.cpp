#include <Servo.h>

/** 
 * Initialize the ESC object (in this case servos use PPM signals as well) so the 
 * servo library can be used to drive the ESC. 
 **/
Servo esc1;


/** Define which digital pin will be used to drive the servo */
const int PIN_ESC1 = 2;

void setup() {
	/** Setup the digital pin to be output mode */
	pinMode(PIN_ESC1, OUTPUT);
	/** Initialize the ESC */
	esc1.begin(PIN_ESC1);
	/** Initialize serial so we can print out debug statements */
	Serial.begin(9600);
}

void loop() {
	/** Read the analog value. This uses a potentiometer which we'll read the wiper value */ 
	int analogValue = analogRead(0);
	Serial.print("Analog Value: ");
	Serial.println(analogValue);
	/** Servo library uses a range from 0 to 128 */
	int servoValue = analogValue / 128;
	/** Write the value to the ESC */ 
	esc1.write(servoValue);
	Serial.print("Servo value: ");
	Serial.println(servoValue);
}
