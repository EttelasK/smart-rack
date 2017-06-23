#include <LiquidCrystal.h>
//#include "LiquidCrystal/LiquidCrystal.h"

LiquidCrystal lcd(D0, D1, D2, D3, D4, D5);

#include <HX711ADC.h>

SYSTEM_THREAD(ENABLED);

// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0
HX711ADC scale(A1, A0);    // parameter "gain" is ommited; the default value 128 is used by the library

int button1 = D6; //Where is the button?
int led = D7;
int scale_read = 0;
int scale_zero = 0;
int scale_one = 0;
double scale_unit = 0.0;
int units = 0;

String status;


void setup() {
    Serial.begin(9600);
    Particle.variable("ScaleRead", scale_read);
    Particle.variable("ScaleZero", scale_zero);
    Particle.variable("ScaleOne", scale_one);
    Particle.variable("ScaleUnit", scale_unit);
    Particle.variable("Units", units);
    
    //set and keep track of the button's status:
    status = "first";
    //set up the button to capture when pressed:
    pinMode(button1, INPUT);
    //set up the on board led to output blink:
    pinMode(led, OUTPUT);
    //start with LED turned off:
    digitalWrite(led, LOW);
    //set up the LCD's number of columns and rows: 
    lcd.begin(16,2);
    //welcome user
    lcd.print("WELCOME!");
}

void loop() {
    //Continuously read the weight from the load cell
    scale_read = scale.read();
    scale.power_down();
    delay(5000);
    scale.power_up();
    //Check to see if button has been pressed
    if (digitalRead(button1)==HIGH){
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(200);
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        if (status=="first"){
            lcd.clear();
            lcd.setCursor(3,0);
            lcd.print("REMOVE ALL");
            lcd.setCursor(3,1);
            lcd.print("TO ZERO OUT");
            status = "empty";
            Particle.publish("Status of calibration", status);
            delay(2000);
        }
        else if (status=="empty"){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("CALIBRATING FOR");
            lcd.setCursor(3,1);
            lcd.print("ZERO UNITS");
            scale_zero = scale_read;
            status = "zero_cal";
            Particle.publish("Status of calibration", status);
            delay(2000);
        }
        else if (status=="zero_cal"){
            lcd.clear();
            lcd.setCursor(1,0);
            lcd.print("PLACE ONE UNIT");
            lcd.setCursor(5,1);
            lcd.print("ON BIN");
            status = "one";
            Particle.publish("Status of calibration", status);
            delay(2000);
        }
        else if (status=="one"){
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("CALIBRATED!");
            scale_one = scale_read;
            status = "running";
            Particle.publish("Status of calibration", status);
            delay(2000);
        }
        else if (status=="running"){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("RESET INVENTORY?");
            lcd.setCursor(1,1);
            lcd.print("PRESS TO CONT");
            delay(4000);
            if (digitalRead(button1)==HIGH){
                status = "first";
                Particle.publish("Status of calibration", status);
            }
            else{
                lcd.clear();
                status = "running";
                Particle.publish("Status of calibration", status);
            }
        }
    }
    else{
        if (status=="running"){
            digitalWrite(led, HIGH);
            lcd.clear();
            scale_unit = (scale_read-scale_zero)/(scale_one-scale_zero) + 0.5;
            units = scale_unit;
            lcd.setCursor(5,0);
            lcd.print("UNIT(S):");
            lcd.setCursor(5,1);
            lcd.print(units);
            delay(100);
        }
        else if (status=="first"){
            digitalWrite(led, LOW);
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("PRESS BUTTON");
            lcd.setCursor(2,1);
            lcd.print("TO CALIBRATE");
            delay(100);
        }
    }
}