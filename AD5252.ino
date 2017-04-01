
#include<Wire.h>


#define Addr 0x2C
#define DataRegisterOne 0x01
#define DataRegisterThree 0x03

bool SendDateToI2C(byte , byte , byte );
unsigned int ReadDataFromI2C(byte,unsigned int );

void setup()
{

  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);

 SendDateToI2C(Addr, DataRegisterOne, 0x00);
 SendDateToI2C(Addr, DataRegisterThree, 0x00);
 delay(300);
  
}


void loop()
{
  unsigned int data;
  for(byte i = 0,j =255; i<=255; i++,j--)
  {
   
   SendDateToI2C(Addr, DataRegisterOne, j);

  
  data = ReadDataFromI2C(Addr, DataRegisterOne, 1);
 
   Serial.print("Pot One Value: ");
   Serial.print(data);

   SendDateToI2C(Addr, DataRegisterThree, i);
   data = ReadDataFromI2C(Addr, DataRegisterThree, 1);
 
   Serial.print("Pot Two Value: ");
   Serial.print(data);

  delay(100);
  }
}

unsigned int ReadDataFromI2C(byte bAddr,byte bRegAddress,unsigned int numberOfByte)
{
   // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select data register
  Wire.write(bRegAddress);
  // Stop I2C transmission
  Wire.endTransmission();
  
   // unsigned int data;
  // Request 1 byte of data
  Wire.requestFrom(Addr,  numberOfByte);

  // Read 1 byte of data
  if (Wire.available() == numberOfByte)
  {
   return  Wire.read();
  
  }
  
 }

bool SendDateToI2C(byte bAddr, byte bRegAddress, byte bValue)
{
     // Start I2C transmission
  Wire.beginTransmission(bAddr);
  // Send instruction for POT channel-1
  
  Wire.write( bRegAddress);
 
  
  Wire.write(bValue);
  // Stop I2C transmission
  Wire.endTransmission();

}
