#define LED 13 //the onboard LED of Arduino or Seeeduino
#define COLLISION_SENSOR 2//collision sensor is connected with D2 of Arduino
int count = 0;

void setup()
{
    Serial.begin(115200);
    pins_init();
    Serial.println(0);
}
 
void loop()
{
    if(isTriggered())
    {
        turnOnLED();
        delay(200);
        count +=1 ;
        Serial.println(count);        
    }
    else turnOffLED();
}
 
void pins_init()
{
    pinMode(LED,OUTPUT);
    turnOffLED();
    pinMode(COLLISION_SENSOR,INPUT);
}
 
boolean isTriggered()
{
    if(!digitalRead(COLLISION_SENSOR))
    {
        delay(150);
        if(!digitalRead(COLLISION_SENSOR))
        return true;//the collision sensor triggers
    }
    return false;
}

 
void turnOnLED()
{
    digitalWrite(LED,HIGH);//the LED is on
}
 
void turnOffLED()
{
    digitalWrite(LED,LOW);//the LED is off
}
