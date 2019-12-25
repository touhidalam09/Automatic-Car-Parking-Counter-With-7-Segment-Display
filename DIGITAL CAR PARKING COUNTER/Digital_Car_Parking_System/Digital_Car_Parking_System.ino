#include<LiquidCrystal.h>
#include <Wire.h>  // Comes with Arduino IDE
#include <Servo.h>

LiquidCrystal lcd(13,12,11,10,9,8);
//                (RS,E,DB4,DB5,DB6,DB7)  

char junk;
String inputString="";

#define echoPin 15 // Echo Pin
#define trigPin 14 // Trigger Pin

#define echoPin2 17 // Echo Pin
#define trigPin2 16 // Trigger Pin

int count=0;
long duration, duration2, inches2, inches, distance, distance2;

void IN()
{
    if(count > 10){
        //nothing do here

    }else{
    count++;
    lcd.clear();
    lcd.print(count);
    lcd.setCursor(0,1);
    lcd.print("SI# of CAR Entry");
    delay(1000);
    }
}

void OUT()
{
    if(count <= 0){
        //nothing do here
    }
    else{
    count--;
    lcd.clear();
    lcd.print(count);
    lcd.setCursor(0,1);
    lcd.print("SI# of CAR LEAVE");
    delay(1000);
    }
}

void setup()
{  
  //For LCD DISPLAY
 
  lcd.begin(16,2);   
  lcd.setCursor(0,0);
  lcd.print("Welcome To :)");
  delay (175);
  lcd.setCursor(0,1);
  lcd.print("CAR Parking");
  delay(3000);
  //for LED
  pinMode(7, OUTPUT); //green
  pinMode(6, OUTPUT); //red;
  Serial.begin(9600);
  digitalWrite(6, HIGH); // red LED always HIGH 
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop()
{
   // For  Bluetooth LED Light on / OFF
   if(Serial.available()){
       while(Serial.available())
       {
             char inChar = (char)Serial.read();
             inputString += inChar; 
       }
      Serial.println(inputString);
      while (Serial.available() > 0)  
      { 
             junk = Serial.read() ; }      
             if(inputString == "a")
             {
                  digitalWrite(6, LOW);        
                  delay (2);
                  digitalWrite(7, HIGH);
                  
                  lcd.clear();
                  lcd.setCursor(2,0);
                  lcd.print("PARKING ALLOW");
                  delay(1000);
             }
             else if(inputString == "b"){   //incase of 'b' turn the LED off
                  digitalWrite(7, LOW);
                  delay (2);
                  digitalWrite(6, HIGH);
                   
                  lcd.clear();
                  lcd.setCursor(4,1);
                  lcd.print("NOT ALLOW");
                  delay(1000);
      }
    inputString = "";
  }
   

 //FOR IN
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 pinMode(echoPin, INPUT); 

 duration = pulseIn(echoPin, HIGH);
 inches = (duration/2) / 74;
 /*Serial.print(inches);
 Serial.print("in, ");
 Serial.println();
 delay(250);
 */

 if(inches < 4  ){
    IN();
 }

 //FOR OUT
 digitalWrite(trigPin2, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin2, LOW);
 pinMode(echoPin2, INPUT); 
 duration2 = pulseIn(echoPin2, HIGH);//                                     
 inches2 = (duration2/2) / 74;
 /*
 Serial.print(inches2);
 Serial.print("in, ");
 Serial.println();
 delay(250);
 */

 if(inches2 < 4 ){
    OUT();
 }


 //rest of code
  if(count<=0)
  {
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("AVAILABLE");
    lcd.setCursor(0,1);
    lcd.print("For Car Parking");
    delay(1500);
  }
  
  else
   {
       if(count > 10){
       lcd.clear();
       lcd.setCursor(4,0);
       lcd.print("SORRY :(");
       delay(600);
       
       lcd.clear();
       lcd.setCursor(2,0);
       lcd.print("NOT AVAILABLE");
       lcd.setCursor(0,1);
       lcd.print("For Car Parking");
       delay(1500);
    }else{ 
          lcd.clear();
          lcd.setCursor(2,0);
          lcd.print("Parking Lots");
          lcd.setCursor(4,1);
          lcd.print("AVILABLE");
          delay(1500);
          
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("TOTAL CAR ENTRY");
          lcd.setCursor(0,1);
          lcd.print(count);
          delay(700);         
      

    }//iner else
         
   }//out else
   

}
