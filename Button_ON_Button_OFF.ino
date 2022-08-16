#include <LiquidCrystal.h>
// załączona biblioteka LiquidCrystal
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//Ustawienie pinow pod  wyswietlacz 
int animationSpeed = 0;
boolean d1,d2;   
//

void setup() {
   lcd.begin(16, 2);
  pinMode(10, OUTPUT); //Dioda zielona
  pinMode(8, OUTPUT); //Dioda czerwona
  pinMode(7, INPUT_PULLUP); //Przycisk
 
  digitalWrite(10, LOW); //Wyłączenie diod
  digitalWrite(8, HIGH); //Wyłączenie diod
  d1=true;
  d2=false;
  lcd.setCursor(0,0);
 		lcd.print("   Przekaznik         ");
    	lcd.setCursor(0,1);
    	lcd.print("    Wylaczony      ");
}

void loop() {
  
    if (digitalRead(7) == LOW) //Obsluga przycisku
  { 	
      
    delay(200); //Opoznienie
      
	if (d1) {
        lcd.clear(); //Czyszczenie ekranu
		digitalWrite(10, LOW); 
		d1 = false;
		digitalWrite(8, HIGH);
		d2= true;
        lcd.setCursor(0,0);
 		lcd.print("   Przekaznik         ");
    	lcd.setCursor(0,1);
    	lcd.print("    Wylaczony      ");
	}
      
	else{
      lcd.clear();
		digitalWrite(10, HIGH); 
		d1 = true;
		digitalWrite(8, LOW);
		d2= false;
        lcd.setCursor(0,0);
 		lcd.print("   Przekaznik         ");
		lcd.setCursor(0,1);
    	lcd.print("    Wlaczony      ");

	}
}
}