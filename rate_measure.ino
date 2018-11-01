#include <LiquidCrystal.h>

int Reset=7, Enable=6, Data4=5, Data5=4, Data6=3, Data7=2;

LiquidCrystal lcd(Reset,Enable,Data4,Data5,Data6,Data7);

double Temp, Threshold;
double time1, time2, Time;
float Rate;
int timer1=0, timer2=0;
#define ThermistorPin  8

boolean Breath=false;

void setup() 
{
  // put your setup code here, to run once:

  lcd.begin(16,2);
  lcd.clear();
  lcd.print("    Welcome    ");
  lcd.setCursor(0,1);
  lcd.print("Raspiratory Rate");
  delay(1000);

  pinMode(8,INPUT);
  pinMode(11,OUTPUT);
  

  Serial.begin(9600);


}

void loop() 
{
    
    Temp = digitalRead(ThermistorPin);
    if(Temp==0 && !Breath)
    {
      Breath=true;
      time2=millis();

      Time=time2-time1;
    
    Serial.println(time1);
    Serial.println(time2);
    Serial.println(Time);
    Serial.println();
    
    Rate = 60000/Time;

    lcd.clear();
    lcd.print("Raspration Rate:");
    lcd.setCursor(0,1);
    lcd.print(Rate);
    time1=time2;
    delay(600);
    
    if(Rate>24)
    {
      digitalWrite(11,HIGH);
      delay(1200);
      digitalWrite(11,LOW);
    }
    
      //break;
    }
    else if(Temp==1 && Breath)
    {
      Breath=false;
      delay(400);
      //continue;
    }
  //}


    //temperature();
    Thresh[i] =analogRead(Thermistorclear();
    lcd.print("Range
    lcd.setCursor(0,}

void getthreshold()
{
  float Thresh[10];
  for(int i=0;i<10;i++)
  {1);
    lcd.print(Temp);
    delay(1000);
  }

  Threshold=Thresh[0];
  Serial.println(Thresh[0]);
  
  for(int i=0;i<10;i++)
  {
    if(Threshold<Thresh[i])
    {
      Threshold = Thresh[i];
    }
  }

  lcd.clear();
  lcd.print("Threshold:");
  lcd.setCursor(0,1);
  lcd.print(Threshold);
  //lcd.print(" C");
  delay(1000);
}

