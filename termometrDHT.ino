
  
#include "DHT.h"
#include <Wire.h>   
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht;
 
void setup()
{
  Serial.begin(9600);
  dht.setup(3);
  lcd.begin(16,2);   
  lcd.backlight(); // zalaczenie podwietlenia 
}
 
void loop()
{
  int wartosc = 0;
  float napiecie = 0;
  wartosc = analogRead(A2);
  napiecie = wartosc * (5.0/1024.0);
  //zbieranie informacji o wilgotnosci
  int wilgotnosc = dht.getHumidity();
  //zbieranie informacji o temperaturze
  int temperatura = dht.getTemperature();
  

  lcd.setCursor(0,0); 
  lcd.print("Temp:"  );
    lcd.print(temperatura);
  delay(500);
  lcd.setCursor(9,0); 
  lcd.print("Wilg:");
  lcd.print(wilgotnosc);
  delay(500);
   lcd.setCursor(0,1); 
  lcd.print("Napiecie : ");
  lcd.print(napiecie);

  

  //serial
    Serial.print(wilgotnosc);
    Serial.print("%RH | ");
    Serial.print(temperatura);
    Serial.println("*C");
}
