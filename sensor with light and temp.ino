#include<wire.h> //temperature
int temp_adress=72;
int light;//to store analog values of intensity

void setup()
{
  Serial.begin(9600);//begin interaction with serial
  Wire.begin();
  
    
}

void loop()
{light=analogRead(A0);//raead the intensity
  //start talking
  Wire.beginTransmission(temp_adress);
  //first value
  Wire.send(0);
  Wire.endTransmission();
  Wire.requestFrom(temp_adress,1);
  while(Wire.available()==0);
  int c=Wire.receive();
  Serial.print(c);//temperature in celcius
  Serial.print("C,");
 Serial.print("LI");
 Serial.print(light);//light intensity
}
