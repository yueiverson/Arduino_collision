#define LED 13 //the onboard LED of Arduino or Seeeduino
#define COLLISION_SENSOR 3//collision sensor is connected with D3 of Arduino
int count = 0;
int val = 0;


void setup()
{
    Serial.begin(115200);
    pins_init();
    Serial.println(0);
}
 
void loop()
{
  int val = digitalRead(COLLISION_SENSOR);  // read input value
  if (val == HIGH) {                // check if the input is HIGH
    turnOffLED();      // turn LED OFF
  } else {
    turnOnLED();     // turn LED ON
    count +=1;
    Serial.println(count);
  }
  delay(100);


}
 
void pins_init()
{
    pinMode(LED,OUTPUT);
    turnOffLED();
   pinMode(COLLISION_SENSOR,INPUT);
}
 

 
void turnOnLED()
{
    digitalWrite(LED,HIGH);//the LED is on
}
 
void turnOffLED()
{
    digitalWrite(LED,LOW);//the LED is off
}
