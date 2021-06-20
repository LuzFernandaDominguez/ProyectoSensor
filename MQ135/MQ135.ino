#include  <LiquidCrystal.h>
LiquidCrystal lcd(2,3,9,10,11,12);
int s_analogica_mq135=0;


void setup ()
{
  Serial.begin(9600);
  lcd.begin(16,2);

}

void loop ()
{
  s_analogica_mq135 = analogRead (0);
  Serial.print(s_analogica_mq135, DEC);
  Serial.println(" ppm");
  delay (1000);
  lcd.clear();
  lcd.print("Calidad de aire");
  s_analogica_mq135= analogRead(A0);
  lcd.setCursor(0,1);
  delay(1000);

  //aire
  if (s_analogica_mq135 <=55)
  {
    Serial.println("Calidad de aire normal");
    lcd.print("Aire normal");
    delay (1000);
  }
  
//aire con dioxido humano
 if (s_analogica_mq135>=56 && s_analogica_mq135<=65)
 {
  Serial.println("Aire con presencia de CO2");
  lcd.print("Presencia de CO2");
  delay (1000);
 }
//dioxido de carbono
 if (s_analogica_mq135>=66 && s_analogica_mq135<=320)
 {
   Serial.println("Aire con Carbono CO2");
   lcd.print("Aire con Carbono CO2");
  delay (1000);
 }
//Gas propano y butano
  if (s_analogica_mq135>=321)
  {
    Serial.println("Aire con Propano");
    lcd.print("Aire con Propano");
  delay (1000);
  }
  
}
