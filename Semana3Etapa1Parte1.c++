#include <LiquidCrystal.h>

//Definindo o pino do sensor e do Led
const int pinSensor = A0;
const int pinLed = 13;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup(){
	Serial.begin(9600);
      
    lcd.begin(16,2);
  
  
  	pinMode(pinLed,OUTPUT);
      
  	/*define qual o estado do pino
    
    pinMode pode ser HIGH ou low, em questão de entrada ou saída
        
    Nesse caso, definimos o pinLed como saída
    */
  
  	digitalWrite(pinLed,HIGH);
}

void loop(){
	
 //Lendo a tensão no sensor
  float tension = analogRead(pinSensor)*(5.0/1024.0);
  //convertendo a para tem temperatura
  float temperature = (tension -0.5)*100;
	
  //Mostrando Temperatura no LED
  lcd.setCursor(0, 1);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("C");
  Serial.println();
  
  delay(5000);
}
