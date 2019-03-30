
/*###############################################################################################
 #################################################################################################


/*-----------------------     end here                     --------------------------------------*/
 




int bit_read(int num)
{
  if(bitRead(num, 6) == 0 && bitRead(num, 5) == 0)
  {
    if(bitRead(num, 7) == 1)
    { QAH = 0;
      Serial.print("\n Queen AH is 0");}
      
      
    SIM[0] = num;
  }
  else if(bitRead(num, 6) == 0 && bitRead(num, 5) == 1)
  {
    if(bitRead(num, 7) == 1)
      {QAH = 1;
      Serial.print("\n Queen AH is 1");}
    SIM[1] = num;
  }
  else if(bitRead(num, 6) == 1 && bitRead(num, 5) == 0)
  {
    if(bitRead(num, 7) == 1)
      {QAH = 2;
      Serial.print("\n Queen AH is 2");}
    SIM[2] = num;
  }
  else if(bitRead(num, 6) == 1 && bitRead(num, 5) == 1)
  {
    if(bitRead(num, 7) == 1)
      {QAH = 3;
      Serial.print("\n Queen AH is 3");}
      SIM[3] = num;
  }
}



int detect_aruco()
{ 

  // The code below rotates the the two servo with defined angle in corresponding upward and downward direction by calling the function in defined class 
  // attaches the servo on pin 9 to the servo object
  //################################DATA1################################
  data = -1;
  decrease(core,90,50);
  Wire.onRequest(sendData1);

  while(data == -1)
  {
    Wire.onReceive(receiveData);
  }
  //  //Serial.print("###########################DATA REUCEIVED#################### \n");
  //
  //  //Serial.print(data);
  bit_read(data);


  //################################DATA2################################  
  data=-1;
  increase(core,50, 130);

  Wire.onRequest(sendData2);

  while(data == -1)
  {
    Wire.onReceive(receiveData);
  }
  //  //Serial.print("###########################DATA REUCEIVED#################### \n");
  //
  //  //Serial.print(data);
  bit_read(data);
  //################################180TURN################################ 
  velocity(100,87);
  turn_full = 180;

  left_turn(state);
  line_bck1(state);


  //################################DATA3################################ 
  data = -1;

  Wire.onRequest(sendData4);

  while(data == -1)
  {
    Wire.onReceive(receiveData);
  }
  //  //Serial.print("###########################DATA REUCEIVED#################### \n");
  //
  //  //Serial.print(data);
  bit_read(data);
  //################################DATA4################################ 
  data = -1;
  decrease(core,130, 45);

  Wire.onRequest(sendData3);

  while(data == -1)
  {
    Wire.onReceive(receiveData);
  }
  //  //Serial.print("###########################DATA REUCEIVED#################### \n");
  //
  //  //Serial.print(data);
  bit_read(data);
  //#################MOVE SERVO BACK TO ITS POSITION#########

  increase(core,45, 90); // Servo back in 
  
  
  the_sequence_decider();
  services();
  
  
  for(int i = 0; i<4; i++)
  {
    Serial.print("\nSEQUENCE"); 
    Serial.print(sequence[i]); 
  }
  
  Serial.print("\nQAH"); 
  Serial.print(QAH);
    
    
  for(int i = 0; i<8; i++)
  {
    Serial.print("\n SERVICE REQUIRED"); 
    Serial.print(service_required[i]); 
  }
  
  cal_block_seq();
  
  for(int i = 0; i<7; i++)
  {
    Serial.print("\n BLOCK SEQUENCE"); 
    Serial.print(block_sequence[i]); 
    req_bl[i] = block_sequence[i];

  }
}  





/*###############################################################################################
 #################################################################################################
 ------------------ detect_color function start here        ----------------------------------*/
void detect_color()
{

  data = -1;
  Wire.onRequest(sendData5);

  while(data == -1)
  {
    Wire.onReceive(receiveData);
  }
  Serial.print("DAta");
  Serial.print(data);

}
/*-------------------- detect_color function of the end here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 ------------------      pick_it function start here          ----------------------------------*/
int pick_it()
{
   if(face_side == 1){
 int r = core.read();
 if(r > 4){
 decrease(core, r,4);}
 else if (r<4){
 increase(core, r ,4);}
 }
 else if (face_side == -1){
  int r = core.read();
 if(r < 178){
 increase(core, r,178);}
 else if (r>178){
 decrease(core, r ,178);}
 }
  //increase(picker,30,150);  

 //increase(stopper,0,180);

  increase(picker,30,175);

  increase(griper,100,180);

  decrease(picker,175,31,25);

  decrease(griper,180,100,10);

 // increase(stopper,10,180);

  increase(picker,30,165);

  decrease(stopper,180,0,25);

  decrease(picker,175,31);


}

/*--------------------  pick_it function of the end here --------------------------------------*/

/*###############################################################################################
 #################################################################################################
 ------------------      pick_it function start here          ----------------------------------*/
int pick_it_up()
{
  //increase(picker,30,150);  

 //increase(stopper,20,180);
  if(face_side == 1){
 int r = core.read();
 if(r > 4){
 decrease(core, r,4);}
 else if (r<4){
 increase(core, r ,4);}
 }
 else if (face_side == -1){
  int r = core.read();
 if(r < 178){
 increase(core, r,178);}
 else if (r>178){
 decrease(core, r ,178);}
 }

  increase(picker,31,173);

  increase(griper,100,180);

  decrease(picker,175,31,25);

  decrease(griper,180,155,50);
  
  decrease(griper,155,100,5);

  increase(stopper,0,180,6);

  increase(picker,31,160);

  decrease(stopper,180,0,20);

  decrease(picker,160,30);


}

/*--------------------  pick_it function of the end here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 ------------------      drop_it function start here          ---------------------------------*/

void drop_it()
{

  increase(griper,100,180);

  increase(picker,30,170);

  decrease(griper,180,100,15);

  decrease(picker,170,30);


}
/*--------------------  drop_it function of the end here --------------------------------------*/

/*###############################################################################################
 #################################################################################################
 ------------------     trash_it_up function start here          ---------------------------------*/
void trash_it_up()
{
  color_glow(4);
  
  
  increase(picker,31,175);

  increase(griper,100,180);

  decrease(picker,170,50,20);


}
/*--------------------  trash_it_up function of the end here --------------------------------------*/

/*###############################################################################################
 #################################################################################################
 ------------------     trash_it_down function start here          ---------------------------------*/
void trash_it_down()

{

  increase(picker,50,170,20);
  
  

  decrease(griper,180,140,15);



  decrease(picker,170,50);
  
  decrease(griper,140,100,3);
  
  decrease(picker,50,30);
  
  



}
/*--------------------  thrastrashh_it_down function of the end here --------------------------------------*/





/*###############################################################################################
 ################################################################################################# */



/*int service_at_ah(int ah)
{



  if ((bitRead(SIM[ah],0) == 0) && ((bitRead(SIM[ah],2) != 0) || (bitRead(SIM[ah],1) != 0)) && ((bitRead(SIM[ah],4) != 0) || (bitRead(SIM[ah],3) != 0)))
  {


    decrease(core,90,0);    //drop at service 1
    drop_it();
    increase(core,0,180);  //drop at service 2
    drop_it();
    decrease(core,180,90); //servo vapsi


  }

  if ((bitRead(SIM[ah],0) == 0) && ((bitRead(SIM[ah],2) == 0) && (bitRead(SIM[ah],1) == 0)) && ((bitRead(SIM[ah],4) != 0) || (bitRead(SIM[ah],3) != 0)))
  {
    increase(core,90,180);
    drop_it();
    decrease(core,180,90); //servo vapsi
  }
  if ((bitRead(SIM[ah],0) == 0) && ((bitRead(SIM[ah],2) != 0) || (bitRead(SIM[ah],1) != 0)) && ((bitRead(SIM[ah],4) == 0) && (bitRead(SIM[ah],3) == 0)))
  {

    decrease(core,90,0);
    drop_it();
    increase(core,0,90);
  }
  if ((bitRead(SIM[ah],0) == 1) && ((bitRead(SIM[ah],2) != 0) || (bitRead(SIM[ah],1) != 0)) && ((bitRead(SIM[ah],4) == 0) && (bitRead(SIM[ah],3) == 0)))
  {
    increase(core,90,180);
    trash_it_up();
    decrease(core,180,90);
    trash(ah);
    decrease(core,90,0);
    drop_it();
    increase(core,0,90);
  }
  if ((bitRead(SIM[ah],0) == 1) && ((bitRead(SIM[ah],2) == 0) && (bitRead(SIM[ah],1) == 0)) && ((bitRead(SIM[ah],4) != 0) || (bitRead(SIM[ah],3) != 0)))
  { 
    decrease(core,90,0);
    trash_it_up();
    increase(core,0,90);
    trash(ah);
    increase(core,90,180);
    drop_it();
    decrease(core,180,90);
  }
  if ((bitRead(SIM[ah],0) == 1) && ((bitRead(SIM[ah],2) == 0) && (bitRead(SIM[ah],1) == 0)) && ((bitRead(SIM[ah],4) == 0) && (bitRead(SIM[ah],3) == 0)))
  { 
    decrease(core,90,0);
    data = -1;

    Wire.onRequest(sendData7);

    while(data == -1)
    {
       Wire.onReceive(receiveData);
    }
    
    Wire.onRequest(sendData8);
    if (data == 4)
    { 
      trash_it_up();
      increase(core,0,90);
      trash(ah);
    }
    else
    {
    increase(core,90,180);
    trash_it_up();
    decrease(core,180,90);
    trash(ah);
    }
  }

} */



int service_at_ah(int ah)
{



  if ((bitRead(SIM[ah],0) == 0) && ((bitRead(SIM[ah],2) != 0) || (bitRead(SIM[ah],1) != 0)) && ((bitRead(SIM[ah],4) != 0) || (bitRead(SIM[ah],3) != 0)))
  {


    decrease(core,90,0);    //drop at service 1
    drop_it();
    increase(core,0,180);  //drop at service 2
    drop_it();
    decrease(core,180,90); //servo vapsi


  }

  if ((bitRead(SIM[ah],0) == 0) && ((bitRead(SIM[ah],2) == 0) && (bitRead(SIM[ah],1) == 0)) && ((bitRead(SIM[ah],4) != 0) || (bitRead(SIM[ah],3) != 0)))
  {
    increase(core,90,180);
    drop_it();
    decrease(core,180,90); //servo vapsi
  }
  if ((bitRead(SIM[ah],0) == 0) && ((bitRead(SIM[ah],2) != 0) || (bitRead(SIM[ah],1) != 0)) && ((bitRead(SIM[ah],4) == 0) && (bitRead(SIM[ah],3) == 0)))
  {

    decrease(core,90,0);
    drop_it();
    increase(core,0,90);
  }
  if ((bitRead(SIM[ah],0) == 1) && ((bitRead(SIM[ah],2) != 0) || (bitRead(SIM[ah],1) != 0)) && ((bitRead(SIM[ah],4) == 0) && (bitRead(SIM[ah],3) == 0)))
  {

    decrease(core,90,0);
    drop_it();
    increase(core,0,180);
    trash_it_up();
    decrease(core,180,90);
    trash(ah);
    trash_flag = 1;

  }
  if ((bitRead(SIM[ah],0) == 1) && ((bitRead(SIM[ah],2) == 0) && (bitRead(SIM[ah],1) == 0)) && ((bitRead(SIM[ah],4) != 0) || (bitRead(SIM[ah],3) != 0)))
  { 

    increase(core,90,180);
    drop_it();
    decrease(core,180,0);
    trash_it_up();
    increase(core,0,90);
    trash(ah);
    trash_flag = 1;

  }
  if ((bitRead(SIM[ah],0) == 1) && ((bitRead(SIM[ah],2) == 0) && (bitRead(SIM[ah],1) == 0)) && ((bitRead(SIM[ah],4) == 0) && (bitRead(SIM[ah],3) == 0)))
  { 
    decrease(core,90,0);
    data = -1;

    Wire.onRequest(sendData7);

    while(data == -1)
    {
       Wire.onReceive(receiveData);
    }
    
    Wire.onRequest(sendData8);
    data = 4;
    if (data == 4)
    { 
      trash_it_up();
      increase(core,0,90);
      trash(ah);
      trash_flag = 1;
    }
    else 
    {
      increase(core,90,180);
      trash_it_up();
      decrease(core,180,90);
      trash(ah);
      trash_flag = 1;
    }
  }

}


void the_sequence_decider()
{  Serial.print("In the SeQuhgfhdjhbvhdj");
  switch(QAH)
  { 
    
  case 0: 
        sequence[0] = 0;
        sequence[1] = 3;
        sequence[2] = 2;
        sequence[3] = 1;
        break;
  case 1:
        sequence[0] = 1;
        sequence[1] = 2;
        sequence[2] = 3;
        sequence[3] = 0;
        break;
  case 2:
        sequence[0] = 2;
        sequence[1] = 1;
        sequence[2] = 0;
        sequence[3] = 3;
        break;
  case 3:
        sequence[0] = 3;
        sequence[1] = 0;
        sequence[2] = 1;
        sequence[3] = 2;
        break;
      
  case -1: 
        sequence[0] = 0;
        sequence[1] = 3;
        sequence[2] = 2;
        sequence[3] = 1;
        break;
    } 
//  Serial.println(sequence[0]);
//  Serial.println(sequence[1]);
//  Serial.println(sequence[2]);
//  Serial.println(sequence[3]);
}

void services()
{
  Serial.print("\n In services");
/*  for(i = 1; i<4; i++)
  { //SERVICE 1
    Serial.print("i");
    Serial.println(sequence[i]);
   
    if(bitRead(SIM[sequence[i]], 2) == 0 && bitRead(SIM[sequence[i]],1) == 0)
    service_required[k-1] = -1; 
    if(bitRead(SIM[sequence[i]], 4) == 0 && bitRead(SIM[sequence[i]], 3) == 0)
    service_required[k] = -1;

    if(bitRead(SIM[sequence[i]], 2) == 0 && bitRead(SIM[sequence[i]],1) == 1)
    service_required[k-1] = 1; 
    if(bitRead(SIM[sequence[i]], 4) == 0 && bitRead(SIM[sequence[i]], 3) == 1)
    service_required[k] = 1;

   
    if(bitRead(SIM[sequence[i]], 2) == 1 && bitRead(SIM[sequence[i]], 1) == 0)
    service_required[k-1] = 2;
    if(bitRead(SIM[sequence[i]], 4) == 1 && bitRead(SIM[sequence[i]], 3) == 0)
    service_required[k] = 2;
    
    if(bitRead(SIM[sequence[i]], 2) == 1 && bitRead(SIM[sequence[i]], 1) == 1)
    service_required[k-1] = 3;
    if(bitRead(SIM[sequence[i]], 4) == 1 && bitRead(SIM[sequence[i]], 3) == 1)
    service_required[k] = 3;
    
    //SERVICE 2
//    if(bitRead(SIM[sequence[i]], 4) == 0 && bitRead(SIM[sequence[i]], 3) == 0)
//    service_required[k] = -1;
//    if(bitRead(SIM[sequence[i]], 4) == 0 && bitRead(SIM[sequence[i]], 3) == 1)
//    service_required[k] = 1;
//    if(bitRead(SIM[sequence[i]], 4) == 1 && bitRead(SIM[sequence[i]], 3) == 0)
//    service_required[k] = 2;
//    if(bitRead(SIM[sequence[i]], 4) == 1 && bitRead(SIM[sequence[i]], 3) == 1)
//    service_required[k] = 3;

    k-=2;    
  }*/
  
  
    //SERVICE 1
    if(bitRead(SIM[sequence[0]], 2) == 0 && bitRead(SIM[sequence[0]], 1) == 0)
    service_required[6] = -1;
    if(bitRead(SIM[sequence[0]], 2) == 0 && bitRead(SIM[sequence[0]], 1) == 1)
    service_required[6] = 1;
    if(bitRead(SIM[sequence[0]], 2) == 1 && bitRead(SIM[sequence[0]], 1) == 0)
    service_required[6] = 2;
    if(bitRead(SIM[sequence[0]], 2) == 1 && bitRead(SIM[sequence[0]], 1) == 1)
    service_required[6] = 3;
    //SERVICE 2
    if(bitRead(SIM[sequence[0]], 4) == 0 && bitRead(SIM[sequence[0]], 3) == 0)
    service_required[7] = -1;
    if(bitRead(SIM[sequence[0]], 4) == 0 && bitRead(SIM[sequence[0]], 3) == 1)
    service_required[7] = 1;
    if(bitRead(SIM[sequence[0]], 4) == 1 && bitRead(SIM[sequence[0]], 3) == 0)
    service_required[7] = 2;
    if(bitRead(SIM[sequence[0]], 4) == 1 && bitRead(SIM[sequence[0]], 3) == 1)
    service_required[7] = 3;
    //SERVICE 1
    if(bitRead(SIM[sequence[1]], 2) == 0 && bitRead(SIM[sequence[1]], 1) == 0)
    service_required[4] = -1;
    if(bitRead(SIM[sequence[1]], 2) == 0 && bitRead(SIM[sequence[1]], 1) == 1)
    service_required[4] = 1;
    if(bitRead(SIM[sequence[1]], 2) == 1 && bitRead(SIM[sequence[1]], 1) == 0)
    service_required[4] = 2;
    if(bitRead(SIM[sequence[1]], 2) == 1 && bitRead(SIM[sequence[1]], 1) == 1)
    service_required[4] = 3;
    //SERVICE 2
    if(bitRead(SIM[sequence[1]], 4) == 0 && bitRead(SIM[sequence[1]], 3) == 0)
    service_required[5] = -1;
    if(bitRead(SIM[sequence[1]], 4) == 0 && bitRead(SIM[sequence[1]], 3) == 1)
    service_required[5] = 1;
    if(bitRead(SIM[sequence[1]], 4) == 1 && bitRead(SIM[sequence[1]], 3) == 0)
    service_required[5] = 2;
    if(bitRead(SIM[sequence[1]], 4) == 1 && bitRead(SIM[sequence[1]], 3) == 1)
    service_required[5] = 3;
    //SERVICE 1
    if(bitRead(SIM[sequence[2]], 2) == 0 && bitRead(SIM[sequence[2]], 1) == 0)
    service_required[2] = -1;
    if(bitRead(SIM[sequence[2]], 2) == 0 && bitRead(SIM[sequence[2]], 1) == 1)
    service_required[2] = 1;
    if(bitRead(SIM[sequence[2]], 2) == 1 && bitRead(SIM[sequence[2]], 1) == 0)
    service_required[2] = 2;
    if(bitRead(SIM[sequence[2]], 2) == 1 && bitRead(SIM[sequence[2]], 1) == 1)
    service_required[2] = 3;
    //SERVICE 2
    if(bitRead(SIM[sequence[2]], 4) == 0 && bitRead(SIM[sequence[2]], 3) == 0)
    service_required[3] = -1;
    if(bitRead(SIM[sequence[2]], 4) == 0 && bitRead(SIM[sequence[2]], 3) == 1)
    service_required[3] = 1;
    if(bitRead(SIM[sequence[2]], 4) == 1 && bitRead(SIM[sequence[2]], 3) == 0)
    service_required[3] = 2;
    if(bitRead(SIM[sequence[2]], 4) == 1 && bitRead(SIM[sequence[2]], 3) == 1)
    service_required[3] = 3;
    //SERVICE 1
    if(bitRead(SIM[sequence[3]], 2) == 0 && bitRead(SIM[sequence[3]], 1) == 0)
    service_required[0] = -1;
    if(bitRead(SIM[sequence[3]], 2) == 0 && bitRead(SIM[sequence[3]], 1) == 1)
    service_required[0] = 1;
    if(bitRead(SIM[sequence[3]], 2) == 1 && bitRead(SIM[sequence[3]], 1) == 0)
    service_required[0] = 2;
    if(bitRead(SIM[sequence[3]], 2) == 1 && bitRead(SIM[sequence[3]], 1) == 1)
    service_required[0] = 3;
    //SERVICE 2
    if(bitRead(SIM[sequence[3]], 4) == 0 && bitRead(SIM[sequence[3]], 3) == 0)
    service_required[1] = -1;
    if(bitRead(SIM[sequence[3]], 4) == 0 && bitRead(SIM[sequence[3]], 3) == 1)
    service_required[1] = 1;
    if(bitRead(SIM[sequence[3]], 4) == 1 && bitRead(SIM[sequence[3]], 3) == 0)
    service_required[1] = 2;
    if(bitRead(SIM[sequence[3]], 4) == 1 && bitRead(SIM[sequence[3]], 3) == 1)
    service_required[1] = 3;

    



//   for(int i = 0; i<8; i++) 
//   {
//    if(service_required[i]!= -1)
//    {
//    Serial.print(service_required[i]);
//    Serial.print(",");}
//   }



}

void cal_block_seq()
{
      for(int i = 0, j = 0; i<8; i++)
    {
        if(service_required[i] != -1)
        {
            block_sequence[j] = service_required[i];
            j++;
        }
    
    }
}

