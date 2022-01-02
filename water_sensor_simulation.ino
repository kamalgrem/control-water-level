   //created by The Algerian Developer team
      
               

#include <LiquidCrystal.h>
//initialise the library with the numbers of the interface pins 
LiquidCrystal lcd(7,8,9,10,11,12,13);
 
int resval = 0;    // holds the value
int respin = A3;   // sensor pin used
  
void setup() { 
 
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2); 
  pinMode(0,OUTPUT);    //make the pin 0 as output
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  
  // Print a message to the LCD. 
  lcd.print("  WATER LEVEL : "); 
} 
  
void loop() { 
  // set the cursor to column 0, line 1 
  lcd.setCursor(0, 1); 
    
  resval = analogRead(respin); //Read data from analog pin and store it to resval variable
   
  if (resval<=100){ lcd.println("     Empty    ");digitalWrite(0,0);digitalWrite(1,0);digitalWrite(2,0);digitalWrite(3,1); } 
  
  else if (resval>100 && resval<=300){ lcd.println("       Low      ");digitalWrite(0,0);digitalWrite(1,0);digitalWrite(2,1);digitalWrite(3,0); }
  
  else if (resval>300 && resval<=330){ lcd.println("     Medium     "); digitalWrite(0,0);digitalWrite(1,1);digitalWrite(2,0);digitalWrite(3,0);} 
  
  else if (resval>330){ lcd.println("      High      ");digitalWrite(0,1);digitalWrite(1,0);digitalWrite(2,0);digitalWrite(3,0);}
  
  delay(1000); 
}
