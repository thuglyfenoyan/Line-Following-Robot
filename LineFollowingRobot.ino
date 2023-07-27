/**************************************************
Contributors:       Sabarisan Sabaratnam, Shreekavin Umasankar, 
                    Lemi Miyu, Muhammad Nomaan, Muhammad Sajid, 
                    Bilal Yasini, Supreet Pamma, 
                    Fawaaz Kamali Siddiqui
---------------------------------------------------
Last Update:        13-June-2023
===================================================
Description:        Contains program for the line following robot. 
                    IR sensors are used to read the line colour 
                    and 12V DC motors are used to control the 
                    robot. The L298N Driver is used to control
                    the DC motors, which are connected to an 
                    Arduino Uno. 
===================================================
Connections:        Right IR Sensor:     4
                    Left IR Sensor:      5
                    enA:                 9
                    enB:                 10
                    in1:                 7
                    in2:                 6
                    in3:                 11
                    in4:                 12
**************************************************/


// Instantiations - for devices with seperate libraries



// Variable Declarations 
int rightSensorPin = 4;
int leftSensorPin = 5;

int enA = 9;
int in1 = 7;
int in2 = 6;
int enB = 10;
int in3 = 11;
int in4 = 12;

int rightSensorVal = 0;
int leftSensorVal = 0;



void setup() {

    // Initialize connections 
    Serial.begin(9600);

    pinMode(rightSensorPin, INPUT);
    pinMode(leftSensorPin, INPUT);

    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    analogWrite(enA, 90);
    analogWrite(enB, 90);

}

void loop() {

    // Main program 
    rightSensorVal = readSensor(rightSensorPin);
    leftSensorVal = readSensor(leftSensorPin);

    if (rightSensorVal == 0 && leftSensorVal == 0) {        // both sensors over white surface
        moveForwards();
    } 
    else if (rightSensorVal == 0 && leftSensorVal == 1) {   // left sensor over black surface only
        rotateLeft();
    }
    else if (rightSensorVal == 1 && leftSensorVal == 0) {   // right sensor over black surface only
        rotateRight();
    }
    else if (rightSensorVal == 1 && leftSensorVal == 1) {   // both sensors over black surface
         stop();
    }

    // Serial.print("Right Sensor:");
    // Serial.print(rightSensorVal);
    // Serial.print("Left Sensor: ");
    // Serial.println(leftSensorVal);

}


// Motor methods

void rotateRight() {
    
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

}

void moveForwards() {

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

}

void rotateLeft() {

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);    

}

void stop() {
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

}


// Sensor Methods

int readSensor(int pin) {
    return digitalRead(pin);
}

