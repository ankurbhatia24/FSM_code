
/*###############################################################################################
 #################################################################################################
 ----------------------- header file calling of the start here --------------------------------------*/





/*----------------------- header  of the end  here --------------------------------------*/




void sendData0()
{
  Wire.write(0);
}
void sendData1()
{   
  Wire.write(1);
}
void sendData2()
{
  Wire.write(2);
}
void sendData3()
{
  Wire.write(3);
}
void sendData4()
{
  Wire.write(4);
}
void sendData5()
{
  Wire.write(5);
}
void sendData6()
{
  Wire.write(6);
}
void sendData7()
{
  Wire.write(7);
}
void sendData8()
{
  Wire.write(8);
}

void receiveData(int byteCount)
{

  data = Wire.read();
 
}

