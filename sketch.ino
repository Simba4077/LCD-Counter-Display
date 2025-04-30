/*
  Counter Beginnings
*/

// Include Wire Library for I2C
#include <Wire.h>
// Include NewLiquidCrystal Library for I2C
#include <LiquidCrystal_I2C.h>
// Define I2C Address
LiquidCrystal_I2C lcd(0x27, 20, 4);

volatile long frameCount = 0;
long int temp = 0;
int dir = 0;
long int feet35 = 0;
long int feet16 = 0;

void updateIndexCount()
{
  if (dir == 0)
  {
    frameCount++;
    

  
  
  
  
  
  
  
  
  }
  else
  {
    frameCount--;
  }
  feet35 = (frameCount / 4);
  feet16 = (frameCount / 8);
}

void updateIndexCountD()
{
  if (digitalRead(2) == digitalRead(4))
  {
    dir = (1);
  }
  else
  {
    dir = (0);
  }
}

void setup()
{
  lcd.init();

  pinMode(3, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(6, INPUT);

  attachInterrupt(digitalPinToInterrupt(3), updateIndexCount, RISING);
  attachInterrupt(digitalPinToInterrupt(2), updateIndexCountD, CHANGE);

  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print("FRAMES");
  lcd.setCursor(0, 2);
  lcd.print("--------------------");
  lcd.setCursor(0, 3);
  lcd.print("FEET");
  lcd.setCursor(19, 1);
  lcd.print(frameCount);
  if (digitalRead(6) == (0))
  {
    lcd.setCursor(8, 0);
    lcd.print("35MM");
  }
  else
  {
    lcd.setCursor(8, 0);
    lcd.print("16MM");
  }
}

void loop()
{


if (digitalRead(6) == (0))
    {
      lcd.setCursor(8, 0);
      lcd.print("35MM");
  
  
    
    
    }
    else
    {
      lcd.setCursor(8, 0);
     lcd.print("16MM");
  
     
      
    } 













  if (frameCount != temp)
  {
    // Clear the display
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("FRAMES");
    lcd.setCursor(0, 2);
    lcd.print("--------------------");
    lcd.setCursor(0, 3);
    lcd.print("FEET");
    
    
    
    
    
    
    
    
    
    
    
    
    
    if (digitalRead(6) == (0))
    {
      lcd.setCursor(8, 0);
      lcd.print("35MM");
    
    
    
    
    if (feet35 > -1 && feet35 <= 9)
    {
      lcd.setCursor(19, 3);
      lcd.print(feet35);
    }

    if (feet35 > 9 && feet35 <= 99 || feet35 < 0 && feet35 > -9)
    {
      lcd.setCursor(18, 3);
      lcd.print(feet35);
    }

    if (feet35 > 99 && feet35 <= 999 || feet35 < -9 && feet35 > -99)
    {
      lcd.setCursor(17, 3);
      lcd.print(feet35);
    }

    if (feet35 > 999 && feet35 <= 9999 || feet35 < -99 && feet35 > -999)
    {
      lcd.setCursor(16, 3);
      lcd.print(feet35);
    }

    if (feet35 > 9999 && feet35 <= 99999 || feet35 < -999 && feet35 > -9999)
    {
      lcd.setCursor(15, 3);
      lcd.print(feet35);
    }

    if (feet35 > 99999 && feet35 <= 999999 || feet35 < -9999 && feet35 > -99999)
    {
      lcd.setCursor(14, 3);
      lcd.print(feet35);
    }

    if (feet35 > 999999 && feet35 <= 9999999 || feet35 < -99999 && feet35 > -999999)
    {
      lcd.setCursor(13, 3);
      lcd.print(feet35);
    }

    if (feet35 > 9999999 && feet35 <= 99999999 || feet35 < -999999 && feet35 > -9999999)
    {
      lcd.setCursor(12, 3);
      lcd.print(feet35);
    }

    if (feet35 < -9999999 && feet35 > -99999999)
    {
      lcd.setCursor(11, 3);
      lcd.print(feet35);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    }
    else
    {
      lcd.setCursor(8, 0);
      lcd.print("16MM");
    
    
    
    
    if (feet16 > -1 && feet16 <= 9)
    {
      lcd.setCursor(19, 3);
      lcd.print(feet16);
    }

    if (feet16 > 9 && feet16 <= 99 || feet16 < 0 && feet16 > -9)
    {
      lcd.setCursor(18, 3);
      lcd.print(feet16);
    }

    if (feet16 > 99 && feet16 <= 999 || feet16 < -9 && feet16 > -99)
    {
      lcd.setCursor(17, 3);
      lcd.print(feet16);
    }

    if (feet16 > 999 && feet16 <= 9999 || feet16 < -99 && feet16 > -999)
    {
      lcd.setCursor(16, 3);
      lcd.print(feet16);
    }

    if (feet16 > 9999 && feet16 <= 99999 || feet16 < -999 && feet16 > -9999)
    {
      lcd.setCursor(15, 3);
      lcd.print(feet16);
    }

    if (feet16 > 99999 && feet16 <= 999999 || feet16 < -9999 && feet16 > -99999)
    {
      lcd.setCursor(14, 3);
      lcd.print(feet16);
    }

    if (feet16 > 999999 && feet16 <= 9999999 || feet16 < -99999 && feet16 > -999999)
    {
      lcd.setCursor(13, 3);
      lcd.print(feet16);
    }

    if (feet16 > 9999999 && feet16 <= 99999999 || feet16 < -999999 && feet16 > -9999999)
    {
      lcd.setCursor(12, 3);
      lcd.print(feet16);
    }

    if (feet16 < -9999999 && feet16 > -99999999)
    {
      lcd.setCursor(11, 3);
      lcd.print(feet16);
    }
    
    
    
    
    
    
    
    
    
    
    
    }

   
    } // Print frame count
    if (frameCount > -1 && frameCount <= 9)
    {
      lcd.setCursor(19, 1);
      lcd.print(frameCount);
    }

    if (frameCount > 9 && frameCount <= 99 || frameCount < 0 && frameCount > -9)
    {
      lcd.setCursor(18, 1);
      lcd.print(frameCount);
    }

    if (frameCount > 99 && frameCount <= 999 || frameCount < -9 && frameCount > -99)
    {
      lcd.setCursor(17, 1);
      lcd.print(frameCount);
    }

    if (frameCount > 999 && frameCount <= 9999 || frameCount < -99 && frameCount > -999)
    {
      lcd.setCursor(16, 1);
      lcd.print(frameCount);
    }

    if (frameCount > 9999 && frameCount <= 99999 || frameCount < -999 && frameCount > -9999)
    {
      lcd.setCursor(15, 1);
      lcd.print(frameCount);
    }

    if (frameCount > 99999 && frameCount <= 999999 || frameCount < -9999 && frameCount > -99999)
    {
      lcd.setCursor(14, 1);
      lcd.print(frameCount);
    }

    if (frameCount > 999999 && frameCount <= 9999999 || frameCount < -99999 && frameCount > -999999)
    {
      lcd.setCursor(13, 1);
      lcd.print(frameCount);
    }

    if (frameCount > 9999999 && frameCount <= 99999999 || frameCount < -999999 && frameCount > -9999999)
    {
      lcd.setCursor(12, 1);
      lcd.print(frameCount);
    }

    if (frameCount < -9999999 && frameCount > -99999999)
    {
      lcd.setCursor(11, 1);
      lcd.print(frameCount);
    }
    temp = frameCount;
 
}