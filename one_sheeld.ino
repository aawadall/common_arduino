
//#define CUSTOM_SETTINGS
//#define INCLUDE_LCD_SHIELD

/* Include 1Sheeld library. */ 
//#include <OneSheeld.h>

const float beta = 0.99;
int servopin = 4;
int pulse = 1000;
double dat;
/* A name for a button on pin 12. */
int buttonPin = 12;

void setup()
{
    /* Start communication. */
  //OneSheeld.begin();
  /* Set the button pin as input. */
  pinMode(buttonPin,INPUT); 
    Serial.begin(9600);//Set Baud Rate to 9600 bps
    pinMode(servopin, OUTPUT); 
    dat = 25;
   /* Stop blinking. */
   //LCD.noBlink();
   /* Clear the LCD. */
   //LCD.clear();
   //LCD.begin();
}

void loop()
{ 
    uint16_t val;

      /* Always check the button pin if pressed. */
   /* Begin the LCD cursor at the first row and first column. */
   
   //LCD.clear();
   /* Set the cursor to begin writing from the second row and first column. */
      /* Wait 10 seconds. */  
   //OneSheeld.delay(10);
   
    val=analogRead(A0);//Connect LM35 on Analog 0
    dat = beta * dat + (1-beta) * (double) val * (5/10.24); 
    //erial.print("Tep:"); //Display the temperature on Serial monitor
    Serial.println(dat);
    //Serial.println("C");
    
    digitalWrite(servopin, HIGH);
    delayMicroseconds((int)(500+pulse*(1-(dat-10)/40)));
    digitalWrite(servopin, LOW);
    delay(2);
       /* Print "Hello, World!" */
   //LCD.print(String(dat));

}

