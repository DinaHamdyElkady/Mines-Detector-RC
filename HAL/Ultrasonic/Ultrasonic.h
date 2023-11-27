#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_


// Define HC-SR04 ultrasonic sensor pin connections
#define TRIG_PIN    0  // Trigger pin for the ultrasonic sensor
#define ECHO_PIN    3  // Echo pin for the ultrasonic sensor

void initUltrasonicSensor(void);
void ultrasonicTrigger(void);
int ultrasonicMeasure();


#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
