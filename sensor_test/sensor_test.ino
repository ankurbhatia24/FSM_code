//---------------Libraries------------//


//-----------variable Declration---------------//
int left =A0,center=A1,right=A2; //line sensor 
int sen_pin[3]={A0,A1,A2};//line sensor input 
int reading_i[3]={0,0,0};//input of the sensor value
int reading_o[3]={0,0,0};//input of the sensor value
int r=3,g=4,b=5;  //RGB light connected to the bot
int line_sensor[3]={0,0,0};


//--------setup function -----------//

void setup()
{
  //initilize serial monitor 
  Serial.begin(9600);
  
  //input of line sensor
  pinMode(sen_pin[1],INPUT);
  pinMode(sen_pin[2],INPUT);
  pinMode(sen_pin[3],INPUT);
 /* 
  //input of line sensor
  pinMode(left,INPUT);
  pinMode(center,INPUT);
  pinMode(right,INPUT);
  */
  // output to the rgb light
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  
}

void loop()
{
  //input from the sensor
  reading_i[1]=analogRead(sen_pin[1]);//left sensor value
  reading_i[2]=analogRead(sen_pin[2]);//center sensor value
  reading_i[3]=analogRead(sen_pin[3]);//right sensor value
  // Mapping the input reading
  reading_o[1]=map(reading_i[1],0,1023,0,255);
  reading_o[2]=map(reading_i[2],0,1023,0,255);
  reading_o[3]=map(reading_i[3],0,1023,0,255);
  
  //reading onn the serial monitor
    Serial.print(reading_o[1]);   // print the left sensor value
    Serial.print("\t");    // prints a tab

    Serial.print(reading_o[2]);  // print the center sensor value
    Serial.print("\t");    // prints a tab

    Serial.print(reading_o[3]);  // print the right sensor value
    Serial.print("\t \n");    // prints a tab
    

    delay(50);            // delay 200 milliseconds
}

  
