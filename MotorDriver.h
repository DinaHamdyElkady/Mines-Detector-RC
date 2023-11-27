#ifndef HAL_METALDETECT_MOTORDRIVER_H_
#define HAL_METALDETECT_MOTORDRIVER_H_


 // Define L298N motor driver pin connections
#define MOTOR1_EN   3  // Enable pin for motor 1 (OC0)
#define MOTOR1A     0  // Motor 1 input A
#define MOTOR1B     1  // Motor 1 input B

#define MOTOR2_EN   5  // Enable pin for motor 2 (OC1A)
#define MOTOR2A     4  // Motor 2 input A
#define MOTOR2B     5  // Motor 2 input B

void initPWM(void);
void moveForward(void);
void stop(void);
void turnRight(void);


#endif /* HAL_METALDETECT_MOTORDRIVER_H_ */
