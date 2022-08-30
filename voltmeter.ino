#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

float input_voltage = 0.0;
float temp=0.0;
float r1=100000.0;
float r2=10000.0;
int signalPin = 2;

void setup(){   
Serial.begin(9600);    
lcd.begin(); 
lcd.backlight();   
pinMode(signalPin, OUTPUT);   
lcd.print("DIGITAL VOLTMETER");
}

void loop(){  
delay(100);
int analog_value = analogRead(A0);     
temp = (analog_value * 5.0) / 1024.0;   
input_voltage = temp / (r2/(r1 + r2));        
if (input_voltage < 0.9){     
  input_voltage=0.0;    
  }     
Serial.print("v= ");    
Serial.println(input_voltage);    
lcd.setCursor(0, 1);
lcd.print("Voltage= ");
lcd.print(input_voltage);
if (input_voltage < 11.40 and input_voltage > 3.3){
    digitalWrite(signalPin, HIGH); 
    delay(400);
    digitalWrite(signalPin, LOW);
    delay(300);
    }
}
