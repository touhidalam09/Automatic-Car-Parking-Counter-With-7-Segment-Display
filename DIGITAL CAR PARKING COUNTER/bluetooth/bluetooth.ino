char junk;
String inputString="";

void setup() {
pinMode(7, OUTPUT); //green
pinMode(6, OUTPUT); //red

Serial.begin(9600);
digitalWrite(6, HIGH);
} 

void loop()
{
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
             }
             else if(inputString == "b"){   //incase of 'b' turn the LED off
                  digitalWrite(7, LOW);
                  delay (2);
                  digitalWrite(6, HIGH); 
      }
    inputString = "";
  }
}

