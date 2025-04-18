#define BLYNK_TEMPLATE_ID "TMPL3KuhoP-ys"
#define BLYNK_TEMPLATE_NAME "cable fault"
#define BLYNK_AUTH_TOKEN "-kq05JOSnjxwyB3aAFjcM4s9Vd53C2jb"
char auth[] = BLYNK_AUTH_TOKEN;
//#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include <Ethernet.h>
BlynkTimer timer;
// Your WiFi credentials.
char ssid[] = "ABCDE";
char pass[] = "123456789";
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define Switch1 D7
#define Switch2 D4
#define Switch3 D5
#define Buzzer D6
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();
  Blynk.begin(auth, ssid, pass);
  pinMode(Switch1,INPUT_PULLUP);
  pinMode(Switch2,INPUT_PULLUP);
  pinMode(Switch3,INPUT_PULLUP);
  pinMode(Buzzer,OUTPUT);
  digitalWrite(Buzzer,LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" IOT BASED ");
  lcd.setCursor(0,1);
  lcd.print("FAULT DETECTION");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OF UNDERGROUNG");
  lcd.setCursor(0,1);
  lcd.print("CABLES THROUGH");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NODEMCU");
  delay(2000);
}
void loop()
{
  int Switch_state1 = digitalRead(Switch1);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Switch_state1:");
  lcd.setCursor(0,1);
  lcd.print(Switch_state1);
  Blynk.virtualWrite(V0, Switch_state1);
  delay(1000);
  int Switch_state2 = digitalRead(Switch2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Switch_state2:");
  lcd.setCursor(0,1);
  lcd.print(Switch_state2);
  Blynk.virtualWrite(V1, Switch_state2);
  delay(1000);
  int Switch_state3 = digitalRead(Switch3);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Switch_state3:");
  lcd.setCursor(0,1);
  lcd.print(Switch_state3);
  Blynk.virtualWrite(V2, Switch_state3);
  delay(1000);
  
  if(Switch_state1 ==0)
  {
    digitalWrite(Buzzer,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("CABLE FAULT");
    lcd.setCursor(0,1);
    lcd.print("DETECTED");
    delay(1000);
  }
  else
  {
    digitalWrite(Buzzer,LOW);
  }
 if(Switch_state2 ==0)
  {
    digitalWrite(Buzzer,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("CABLE FAULT");
    lcd.setCursor(0,1);
    lcd.print("DETECTED");
    delay(1000);
  }
  else
  {
   digitalWrite(Buzzer,LOW);
  }
  if(Switch_state3 ==0)
  {
    digitalWrite(Buzzer,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("CABLE FAULT");
    lcd.setCursor(0,1);
    lcd.print("DETECTED");
    delay(1000);
  }
  else
  {
   digitalWrite(Buzzer,LOW);
  }
  Blynk.run();
  timer.run();
}
