#include <LiquidCrystal_I2C.h>
#define BUTTON_ENTER 8
#define BUTTON_PLUS 9
#define BUTTON_MINUS 10
#define BUTTON_RESET 11



LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

#define RandomNumber

int randomNumber =0; 
int liczbaUzytkownika =0;
byte customChar[] = {
  B01010,
  B10101,
  B01010,
  B10101,
  B01010,
  B10101,
  B01010,
  B10101
};
void setup()
{
 pinMode(BUTTON_ENTER, INPUT_PULLUP);
 pinMode(BUTTON_RESET, INPUT_PULLUP);
 pinMode(BUTTON_PLUS, INPUT_PULLUP);
 pinMode(BUTTON_MINUS, INPUT_PULLUP);
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  lcd.createChar(0, customChar);
 randomSeed(analogRead(0));
 randomNumber = random(1, 11);
 Serial.begin(9600);

  lcd.clear();
  lcd.setCursor(0,0);
  for(int i=0; i<32; i++)
  {
    lcd.write(0);
  }
  lcd.setCursor(0,1);
    for(int i=0; i<32; i++)
  {
    lcd.write(0);
  }
  delay(1000);
   lcd.clear();
   lcd.print("Hello Game");
}

void loop()
{
 if(digitalRead(BUTTON_ENTER) == LOW)
 {
   delay(20);
    Serial.println("Wylosowana:");
    Serial.println(randomNumber);
    Serial.println("Podana:");
    Serial.println(liczbaUzytkownika);
    if(liczbaUzytkownika == randomNumber )
    {
      lcd.clear();
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("Zgadles");
  delay(1000);
  lcd.clear();
    }
    else if (liczbaUzytkownika > randomNumber)
    {
      lcd.clear();
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("Za duzo");
  delay(1000);
  lcd.clear();
    }
    else if (liczbaUzytkownika < randomNumber)
    {
      lcd.clear();
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("Za malo");
  delay(1000);
  lcd.clear();
    }
   while(digitalRead(BUTTON_ENTER) == LOW);
   delay(20);
 }
 if(digitalRead(BUTTON_PLUS) == LOW)
 {
   delay(20);
   Serial.println("dodaje");
   liczbaUzytkownika = liczbaUzytkownika + 1;
   while(digitalRead(BUTTON_PLUS) == LOW);
   delay(20);
  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.print("Dodaje");
  lcd.setCursor(0,1); 
  lcd.print("Twoja liczba: "+liczbaUzytkownika); 
  delay(500);
  lcd.clear();
 }
 if(digitalRead(BUTTON_MINUS) == LOW)
 {
   delay(20);
   Serial.println("Odejmuje");
   liczbaUzytkownika = liczbaUzytkownika -1 ;
   while(digitalRead(BUTTON_MINUS) == LOW);
   delay(20);
 }
 if(digitalRead(BUTTON_RESET) == LOW)
 {
  delay(20);
     Serial.println("resetuje");
   liczbaUzytkownika =0; 
   while(digitalRead(BUTTON_RESET) == LOW)
   delay(20);
 }
  

}

