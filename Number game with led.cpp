// C++ code
//

#define PIN_LED_YELLOW 3
#define PIN_LED_RED 4
#define PIN_LED_GREEN 2

#define BUTTON_ENTER 8
#define BUTTON_PLUS 9
#define BUTTON_MINUS 10
#define BUTTON_RESET 11

#define RandomNumber

int randomNumber =0; 
int liczbaUzytkownika =0;
void setup()
{
 pinMode(PIN_LED_YELLOW, OUTPUT);
 pinMode(PIN_LED_RED, OUTPUT);
 pinMode(PIN_LED_GREEN, OUTPUT);
  
  
 pinMode(BUTTON_ENTER, INPUT_PULLUP);
 pinMode(BUTTON_RESET, INPUT_PULLUP);
 pinMode(BUTTON_PLUS, INPUT_PULLUP);
 pinMode(BUTTON_MINUS, INPUT_PULLUP);
  
 randomSeed(analogRead(0));
 randomNumber = random(1, 11);
 Serial.begin(9600);
}

void loop()
{
 digitalWrite(PIN_LED_YELLOW, LOW);
 digitalWrite(PIN_LED_RED, LOW);
 digitalWrite(PIN_LED_GREEN, LOW); 
 if(digitalRead(BUTTON_ENTER) == LOW)
 {
   delay(20);
    Serial.println("Wylosowana:");
    Serial.println(randomNumber);
    Serial.println("Podana:");
    Serial.println(liczbaUzytkownika);
    if(liczbaUzytkownika == randomNumber )
    {
      digitalWrite(PIN_LED_GREEN, HIGH); 
      delay(500);
      digitalWrite(PIN_LED_GREEN, LOW);
    }
    else if (liczbaUzytkownika > randomNumber)
    {
      digitalWrite(PIN_LED_YELLOW, HIGH);
      delay(500);
      digitalWrite(PIN_LED_YELLOW, LOW);
    }
    else if (liczbaUzytkownika < randomNumber)
    {
      digitalWrite(PIN_LED_RED, HIGH);
      delay(500);
      digitalWrite(PIN_LED_RED, LOW);
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

