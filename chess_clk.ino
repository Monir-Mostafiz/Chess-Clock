#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

unsigned long previousMillis = 0;
int interval = 1000;

int i;
int whiteSec=60,whiteMin=14;
int blackSec=60,blackMin=14;

unsigned long whiteTime,blackTime;

int whiteButton,blackButton;

void setup() {

  pinMode(2,INPUT_PULLUP);//FOR WHITE BUTTON
  pinMode(3,INPUT_PULLUP);//FOR BLACK BUTTON

  lcd.init();
  lcd.clear();         
  lcd.backlight();

  lcd.setCursor(1, 0);
  lcd.print("White");
  lcd.setCursor(3, 1);
  lcd.print(":");
  lcd.setCursor(10, 0);
  lcd.print("Black");
  lcd.setCursor(12, 1);
  lcd.print(":");
}

void loop() {

  whiteButton=digitalRead(2);
  if(whiteButton == LOW)
  {
    whiteClock();
  }
  else
  {
    blackClock();
  }
  
}

void whiteClock(void)
{
  whiteTime=millis();
  
  if(whiteTime - previousMillis >= interval)
  {
    previousMillis = whiteTime;
    whiteSec=whiteSec-1;
    if(whiteSec<=0)
    {
      whiteSec=60;
      whiteMin=whiteMin-1;
    }
    if(whiteSec<10)
    {
      lcd.setCursor(4, 1);
      lcd.print("0");
      lcd.setCursor(5, 1);
      lcd.print(whiteSec);
    }
    else
    {
      lcd.setCursor(4, 1);
      lcd.print(whiteSec);
    }
    if(whiteMin<10)
    {
    lcd.setCursor(1, 1);
    lcd.print("0");
    lcd.setCursor(2, 1);
    lcd.print(whiteMin);
    }
    else
    {
      lcd.setCursor(1, 1);
      lcd.print(whiteMin);
    }
    

  }

}

void blackClock(void)
{
  blackTime=millis();
  
  if(blackTime - previousMillis >= interval)
  {
    previousMillis = blackTime;
    blackSec=blackSec-1;
    if(blackSec<=0)
    {
      blackSec=60;
      blackMin=blackMin-1;
    }
    if(blackSec<10)
    {
      lcd.setCursor(13, 1);
      lcd.print("0");
      lcd.setCursor(14, 1);
      lcd.print(blackSec);
    }
    else
    {
      lcd.setCursor(13, 1);
      lcd.print(blackSec);
    }
    if(blackMin<10)
    {
    lcd.setCursor(10, 1);
    lcd.print("0");
    lcd.setCursor(11, 1);
    lcd.print(blackMin);
    }
    else
    {
      lcd.setCursor(10, 1);
      lcd.print(blackMin);
    }
    

  }

}




