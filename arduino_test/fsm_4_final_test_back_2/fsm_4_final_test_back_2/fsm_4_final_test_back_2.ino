
/*  
 * Team Id:2683
 * Author List: e-Yantra Team 
 * Filename: 
 * Theme:  Ant Bot
 * Functions: setup(),loop(),cases(value) ,right_turn(state) , left_turn(state), start_node(), sensor_value(),node_2_node(state)
 * Global Variables:enright ,righta ,rightb  ,enleft  ,lefta ,leftb ,max_left  ,min_left  ,max_center ,min_center  ,max_right  ,min_right ,normal_speed_right  ,normal_speed_left  
 */

/*###############################################################################################
 #################################################################################################
 ----------------------- header file calling of the start here --------------------------------------*/


#include <Wire.h>
#include <Servo.h> 

/*----------------------- header  of the end  here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 -----------------------constant function of the start here --------------------------------------*/
#define enright  11              //enabling pwm pin on right pin
#define righta   4               //enabling right motor on/off  
#define rightb   12              //enabling right motor on/off
#define enleft   3               //enabling pwm pin on left pin
#define lefta    7               //enabling left motor on/off
#define leftb    8               //enabling left motor on/off
#define max_left 490             //defining the max value encounter by the left sensor
#define min_left 20              //defining the min value encounter by the left sensor
#define max_center 410           //defining the max value encounter by the center sensor
#define min_center 20            //defining the min value encounter by the center sensor
#define max_right 500            //defining the max value encounter by the right sensor
#define min_right 20             //defining the min value encounter by the right sensor
#define speed_right 150    //giving the pwm value for the right sensor  
#define speed_left 148    //giving the pwm value for the left sensor  

/*-----------------------     end here                     --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 -----------------------class calling         here --------------------------------------*/
Servo myservo;
/*-----------------------     end here                     --------------------------------------*/

/*###############################################################################################
 #################################################################################################
 ----------------------- functions are define here --------------------------------------*/
int cases(int value);            //taking the different output from the state
int  right_turn(int state);      //function for taking right turn till the line detected
int  left_turn(int state);       //function for taking left turn till the line detected
int start_node();                //function for making a small forward turn till the middle line is detected    
//int sensor_value();
int node_2_node(int state);      //function for maoving the bot from one node to the another node

/*--------------------------    end here                   --------------------------------------*/

/*###############################################################################################
 #################################################################################################
 -----------------------different varialble initiallize here --------------------------------------*/

unsigned int s_lft = 151 ,s_rgt = 148;
unsigned int fwd_go = 22,turn_go = 22;                     //random values
unsigned int previous_millis = 0;                          //function for define the time period for the hardware timer                   
unsigned long interval = 1000;                             //interval of the millis function
unsigned int state =00 ,i=0 ,node=0,turn=0; 
unsigned int flag_rgt=0,flag_lft=0,flag_bck=0,flag_fwd=0,turn_full=0;
unsigned int right = 0 ;                                   //taking the sensor value using map function for left sensor  
unsigned int center = 0;                                   //taking the sensor value using map function for center sensor
unsigned int left = 0;                                     //taking the sensor value using map function for right sensor
unsigned long current_time = 0;
unsigned int sen_pin[]={
  A0,A1,A2};                         //line sensor input 
unsigned int reading_i[3];                                 //input of the sensor value
unsigned int reading_o[3];                                 //input of the sensor value
int node_count = 0;                                        //initialize node count

/*-----------------------setup  function of the end here --------------------------------------*/

//###############################################################



class bot_arm
{
  Servo servo;                                          // create servo object to control a servo

    int pos;                                              // initialising varialble 


public:  

  void Attach(int pin) 
  {
    servo.attach(pin);  
  }

  void Detach()
  {
    servo.detach();
  }

  void millis_servo(int interval)  //Function provides required hardware delays for servo
  {
    
    unsigned long  current_time = millis();
    while(millis()<current_time+interval)
    {
     
    }
   
  } 


  void increase(int angle1,int angle2)
  {
    for(pos = angle1; pos <= angle2; pos += 1) // goes from 0 degrees to 180 degrees
    {
      servo.write(pos);

      millis_servo(30);

    }
    millis_servo(0);

  }

  void decrease(int angle1,int angle2)
  {
    for(pos = angle1; pos>=angle2; pos-=1)
      // goes from 180 degrees to 0 degrees
    {
      servo.write(pos);
      // tell servo to go to position in variable 'pos'
      millis_servo(30);
      // waits 15ms for the servo to reach the position
    }
    millis_servo(50);
  }
};

bot_arm picker;//servo at picker
bot_arm griper;//servo at gripper
bot_arm core;//servo at base
/*--------------------  classes function of the end here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 ------------------      gripper function start here          ---------------------*/
int grip()
{
  // The code below rotates the the two servo with defined angle in corresponding upward and downward direction by calling the function in defined class 
  picker.Attach(9);             // attaches the servo on pin 9 to the servo object
  griper.Attach(5);
  picker.increase(40,175);
  griper.increase(120,180);
  picker.decrease(174,27);
  griper.decrease(180,105);
  griper.increase(105,180);
  picker.increase(26,170);
  griper.decrease(180,130);
  picker.decrease(174,40);
  griper.increase(130,180);
}  

/*-------------------- gripper function of the end here --------------------------------------*/

/*###############################################################################################
 #################################################################################################
 ------------------       function for going from forward node to node    ---------------------*/


int fwd_node_2_node(int state )
{
  fwd_go = 11;
  while(flag_fwd != 3)
  { 
    sensor_data();

    if (flag_fwd == 0)
    {

      if (left >=1  && center >= 3 && right >= 1)
      {
        flag_fwd = 1;
        state = 11;
        cases(state);       
      }   
    }
    else if (flag_fwd == 1)
    {
      if( state == 11)
      {
        if(left == 0 && center >= 3 && right == 0)
        {
          flag_fwd =2;
          state = 11;//fordward
          cases(state);

        }     
        else if(left >= 1 && center >= 3 && right >= 1)
        {
          state = 11;//fordward
          cases(state);        
        }
        else if((left >= 2 && center >= 3 && right == 0) || (left >= 3 && center == 0 && right == 0))
        {
          state = 10;//left
          cases(state);

        }
        else if((left == 0 && center >= 3 && right >= 2) || (left == 0 && center == 0 && right >= 3)) 
        {
          state = 01;//right
          cases(state);
        } 
      }     

      else if (state == 01)
      {
        if(left == 0 && center >= 2 && right == 0)
        {
          flag_fwd =2;
          state = 11;
          cases(state);

        }     
        else if(left == 1 && center >= 2 && right == 1)
        {
          state = 11;
          cases(state);
        }
        else if((left >= 2 && center >= 2 && right == 0) || (left >= 3 && center == 0 && right == 0))
        {
          state = 10;//left
          cases(state);
        }  
      }      
      else  if (state == 10)
      {
        if(left == 0 && center >= 2 && right == 0)
        {
          flag_fwd =2;
          state = 11;
          cases(state); 
        }      
        else if(left == 0 && center >= 2 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if((left == 0 && center >= 2 && right >= 2) || (left == 0 && center == 0 && right >= 2)) 
        {
          state = 01;//right
          cases(state);
        }  
      }
    }
    //follow straight line
    else if (flag_fwd == 2)
    {      
      //state
      current_time = millis();
      if (left >= 1 && center >= 2 && right >= 1) 
      {
        flag_fwd = 3;
        state = 00;//stop
        cases(state);      
      }


      else if( state == 11)
      {   

        if (left >= 1 && center >= 2 && right >= 1) 
        {
          state = 00;//stop
          cases(state);
          flag_fwd =3;             
        }
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;//fordward
          cases(state);
        }


        else if(left >= 1 && center == 0 && right == 0)
        {
          while((state == 11) && (millis()<current_time+10))
          {
            state = 10;//left  right
            cases(state);
          }
        }  
        else if(left >= 1 && center >= 1 && right == 0)
        {
          state = 00 ;
          cases(state);   
        }
        else if(left == 0 && center == 0 && right >= 3)
        {
          while((state == 11) && (millis()<current_time+10))
          {
            state = 01;//left
            cases(state);
          }
        }
        else if(left == 0 && center >= 1 && right >= 1) 
        {
          state = 00;//right
          cases(state);
        } 
        else 
        {
          state=11;//fordward
          cases(state);
        }
      }   
      
      else if (state == 01)
      {
        if (left >= 1 && center >= 1 && right >= 1) 
        {
          state = 00;//stop
          cases(state);
          flag_fwd =3;
        }
        else  if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if(left >= 1 && center == 0 && right == 0)
        {
          state = 10;//left
          cases(state);
        }  
      }   

      else  if (state == 10)
      {
        if (left >= 1 && center >= 1 && right >= 1) 
        {
          flag_fwd =3;
          state = 00;//stop
          cases(state);            
        }             
        else if(left == 0 && center >= 2 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if (left == 0 && center == 0 && right >= 2)
        {
          state = 01;//right
          cases(state);
        }  
      }
    }
  }  
  return state; 
}

/*-------------------- forward line follow function of the end here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 ------------------ function program for taking bacward from node to node            ---------------------*/

int back_node_2_node(int state)
{
  fwd_go = 00 ;
  while(flag_bck != 3)
  { 
    sensor_data();
    if (flag_bck == 0)
    {

      if (left >=1  && center >= 3 && right >= 1)
      {
        flag_bck = 1;
        state = 11;
        cases(state);       
      }   
    }
    else if (flag_bck == 1)
    {
      if( state == 11)
      {
        if(left == 0 && center >= 3 && right == 0)
        {
          flag_bck = 2;
          state = 11;//backward
          cases(state);
        }     
        else if(left >= 1 && center >= 3 && right >= 1)
        {
          state = 11;//backward
          cases(state);        
        }
        else if((left >= 2 && center >= 3 && right == 0) || (left >= 3 && center == 0 && right == 0))
        {
          state = 10;//right
          cases(state);
        }
        else if((left == 0 && center >= 3 && right >= 2) || (left == 0 && center == 0 && right >= 3)) 
        {
          state = 01;//left
          cases(state);
        } 
      }     

      else if (state == 01)
      {
        if(left == 0 && center >= 2 && right == 0)
        {
          flag_bck = 2;
          state = 11;
          cases(state);
        }     
        else if(left == 1 && center >= 2 && right == 1)
        {
          state = 11;
          cases(state);
        }
        else if((left >= 2 && center >= 2 && right == 0) || (left >= 3 && center == 0 && right == 0))
        {
          state = 10;//right
          cases(state);
        }  
      }      
      else  if (state == 10)
      {
        if(left == 0 && center >= 2 && right == 0)
        {
          flag_bck = 2;
          state = 11;
          cases(state); 
        }      
        else if(left == 0 && center >= 2 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if((left == 0 && center >= 2 && right >= 2) || (left == 0 && center == 0 && right >= 2)) 
        {
          state = 01;//left
          cases(state);
        }  
      }
    }
    //backward straight line
    else if (flag_bck == 2)
    {      
      //state
      current_time = millis();
      if (left >= 1 && center >= 2 && right >= 1) 
      {
        flag_bck = 3;
        state = 00;//stop
        cases(state);      
      }


      else if( state == 11)
      {   
        if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;//backward
          cases(state);
        }
        else if (left >= 1 && center >= 2 && right >= 1) 
        {
          flag_bck = 3;                    
          state = 00;//stop
          cases(state);
        }

        else if(left >= 1 && center == 0 && right == 0)
        {
          while((state == 11) && (millis()<current_time+10))
          {
            state = 10;//right
            cases(state);
          }
        }  
        else if(left >= 1 && center >= 1 && right == 0)
        {
          state = 00 ;
          cases(state);   
        }
        else if(left == 0 && center == 0 && right >= 3)
        {
          while((state == 11) && (millis()<current_time+30))
          {
            state = 01;//right
            cases(state);
          }
        }
        else if(left == 0 && center >= 1 && right >= 1) 
        {
          state = 00;//left
          cases(state);
        } 
        else 
        {
          state=11;//backward
          cases(state);
        }
      }   

      else if (state == 01)
      {
        if (left >= 1 && center >= 1 && right >= 1) 
        {
          state = 00;//stop
          cases(state);
          flag_bck = 3;

        }
        else  if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if(left >= 1 && center == 0 && right == 0)
        {
          state = 10;//right
          cases(state);
        }  
      }   

      else  if (state == 10)
      {
        if (left >= 1 && center >= 1 && right >= 1) 
        {
          flag_bck = 3;
          state = 00;//stop
          cases(state);            
        }             
        else if(left == 0 && center >= 2 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if (left == 0 && center == 0 && right >= 2)
        {
          state = 01;//left
          cases(state);
        }  
      }
    }
  }  
  return state; 
}
/*-------------------- backward function of the end here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 ------------------       program to follow backward line to node turn           ---------------------*/
int line_bck( int state )
{
  fwd_go = 00 ; //backward
  while (flag_bck != 9)
  {  
    sensor_data();    
    //state
    current_time = millis();
    if (left >= 1 && center >= 2 && right >= 1) 
    {
      flag_bck =9;
      state = 00;//stop
      cases(state);      
    }


    else if( fwd_go == 00 )
    {   
      if(left == 0 && center >= 1 && right == 0)
      {
        state = 11;//backward
        cases(state);
      }
      else if (left >= 1 && center >= 2 && right >= 1) 
      {
        flag_bck =9;
        state = 00;//stop
        cases(state);
      }

      else if(left >= 1 && center == 0 && right == 0)
      {
        while((state == 11) && (millis()<current_time+10))
        {
          state = 10;//right
          cases(state);
        }
      }  
      else if(left >= 1 && center >= 1 && right == 0)
      {
        //flag_bck =9;
        state = 00 ;
        cases(state);   
      }
      else if(left == 0 && center == 0 && right >= 3)
      {
        while((state == 11) && (millis()<current_time+30))
        {
          state = 01;//right
          cases(state);
        }
      }
      else if(left == 0 && center >= 1 && right >= 1) 
      {
        // flag_bck =9;
        state = 00;//left
        cases(state);
      } 
      else 
      {
        state=11;//backward
        cases(state);
      }
    }   

    else if (state == 01)
    {
      if (left >= 1 && center >= 1 && right >= 1) 
      {
        flag_bck =9;
        state = 00;//stop
        cases(state);
      }
      else  if(left == 0 && center >= 1 && right == 0)
      {
        state = 11;
        cases(state);
      }
      else if(left >= 1 && center == 0 && right == 0)
      {
        state = 10;//right
        cases(state);
      }  
    }   

    else  if (state == 10)
    {
      if (left >= 1 && center >= 1 && right >= 1) 
      {
        flag_bck = 9;
        state = 00;//stop
        cases(state);            
      }             
      else if(left == 0 && center >= 2 && right == 0)
      {
        state = 11;
        cases(state);
      }
      else if (left == 0 && center == 0 && right >= 2)
      {
        state = 01;//left
        cases(state);
      }  
    }
  }

  return state; 
}
/*-------------------- backward line follow function of the end here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 ------------------       program to follow forward line to node turn           ---------------------*/
int line_fwd(int state)
{
  fwd_go = 11;
  while (flag_fwd != 9)
  { 
    sensor_data();
    current_time = millis();
    if (left >= 1 && center >= 2 && right >= 1) 
    {
      flag_fwd = 9;
      state = 00;//stop
      cases(state);      
    }


    else if(fwd_go == 11)
    {   
      if(left == 0 && center >= 1 && right == 0)
      {
        state = 11;//backward
        cases(state);
      }
      else if (left >= 1 && center >= 2 && right >= 1) 
      {
        flag_fwd= 9;
        state = 00;//stop
        cases(state);
      }

      else if(left >= 1 && center == 0 && right == 0)
      {
        while((state == 11) && (millis()<current_time+10))
        {
          state = 10;//right
          cases(state);
        }
      }  
      else if(left >= 1 && center >= 1 && right == 0)
      {
        flag_fwd = 9;
        state = 00 ;
        cases(state);   
      }
      else if(left == 0 && center == 0 && right >= 3)
      {
        while((state == 11) && (millis()<current_time+30))
        {
          state = 01;//right
          cases(state);
        }
      }
      else if(left == 0 && center >= 1 && right >= 1) 
      {
        flag_fwd = 9 ;
        state = 00;//left
        cases(state);
      } 
      else 
      {
        state=11;//backward
        cases(state);
      }
    }   

    else if (state == 01)
    {
      if (left >= 1 && center >= 1 && right >= 1) 
      {
        flag_fwd = 9;
        state = 00;//stop
        cases(state);
      }
      else  if(left == 0 && center >= 1 && right == 0)
      {
        state = 11;
        cases(state);
      }
      else if(left >= 1 && center == 0 && right == 0)
      {
        state = 10;//right
        cases(state);
      }  
    }   

    else  if (state == 10)
    {
      if (left >= 1 && center >= 1 && right >= 1) 
      {
        flag_fwd = 9;
        state = 00;//stop
        cases(state);            
      }             
      else if(left == 0 && center >= 2 && right == 0)
      {
        state = 11;
        cases(state);
      }
      else if (left == 0 && center == 0 && right >= 2)
      {
        state = 01;//left
        cases(state);
      }  
    }
  }     
  return state;
}
/*-------------------- line follow function of the end here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 ------------------       program for taking left turn           ---------------------*/

int  left_turn(int state, int turn_full)
{ 
  fwd_go = 11;
  turn_go = 11;
  turn_full;
  while(flag_lft != 9)
  { 
    sensor_data();

    if (state == 00)
    { 

      if (left >= 1 && center >= 3 && right >= 1)
      {
        turn=11;
        state =10;//right turn
        cases(state);
      }
    } 
    else if(state ==10)
    {
      if(left == 0 && center >= 1 && right == 0)
      {
        flag_lft=9;
        state = 00;//stop
        cases(state); 
      }    

      else if ((left >= 1 && center >= 3 && right >= 1 )||(left >= 0 && center >= 3 && right >= 1 ))
      {
        state =10;//right motor
        cases(state);
      }

      else if((left >= 1 && center >= 3 && right >= 0) || (left >= 1 && center >= 0 && right >= 0) || (left >= 0 && center >= 0 && right >= 0) || (left >= 0 && center >= 0 && right >= 1) || (left >= 0 && center >= 3 && right >= 1))
      {
        state = 10;//right motor
        cases(state);
      } 

    }
  }
  return state;
} 
/*-------------------- left turn function of the end here --------------------------------------*/

/*###############################################################################################
 #################################################################################################
 ------------------       program for taking right turn           ---------------------*/


int  right_turn(int state ,int turn_full)
{
  fwd_go = 11;
  turn_go = 00;
  turn_full;
  while (flag_rgt !=6 )
  {
    sensor_data();
    if (state ==00)
    {
      if (left >= 1 && center >= 3 && right >= 1)
      {
        turn=00;
        state =01;//left motor
        cases(state);
      }
    }
    else if (state ==01)
    {
      if (left >= 0 && center >= 1 && right >= 0)
      {
        flag_rgt = 6;
        state =00;//left motor
        cases(state);
      }
      else if  ((left >= 1 && center >= 3 && right >= 1) ||(left >= 1 && center >= 3 && right >= 0) )
      {
        state =01;//right motor
        cases(state);
      }

      else if((left >= 0 && center >= 3 && right >= 1) || (left >= 0 && center >= 0 && right >= 1) || (left >= 0 && center >= 0 && right >= 0) || (left >= 1 && center >= 0 && right >= 0)   || (left >= 1 && center >= 3 && right >= 0))
      {
        state = 01;//left motor
        cases(state);
      } 

    }
  }   
  return state;  
}
/*-------------------- right turn function of the end here --------------------------------------*/



void millis_servo(int interval)  //Function provides required hardware delays
{
  current_time = millis();
  while(millis()<current_time+interval){
  }

} 




/*###############################################################################################
 #################################################################################################
 ------------------       cases for different states         ---------------------*/

int cases(int value)
{
  switch (value)
  {
  case 00 : 
    stp();   //stop the motor
    break; 
  case 11 : 
    if (fwd_go == 11)
    {
      fwd();
    }
    else if (fwd_go == 00 )
    {
      bck();
    } 
    break;

  case 01 : 
    if (fwd_go == 11)
    {
      if(turn_go == 00) 
      {
        if( turn_full == 90 )
        {
          if (turn == 00)
          {
            current_time = millis();
            while(millis()<current_time+1500)
            {
              sf_lft();   //move the left motor forward for 30 ms 
              if ( current_time+1400 == millis())
              {
                turn++;
              }
            } 
          }
          else 
          {
            sf_lft();
          }
        }
        else if( turn_full == 180 )
        {
          if (turn == 00)
          {
            current_time = millis();
            while(millis()<current_time+1500)
            {
              hr_lft();   //move the left motor forward for 30 ms 
              if ( current_time+1400 == millis())
              {
                turn++;
              }
            } 
          }
          else 
          {
            hr_lft();
          }
        } 

        else 
        {
          hr_lft();  //move the motor forward 
        }
      }
    }
    else if (fwd_go == 00 )
    {
      bck_lft();
    }                   
    break;            
  case 10 : 
    if (fwd_go == 11)
    {
      if(turn_go == 11) 
      {
        if( turn_full == 90 )
        {
          if (turn == 00)
          {
            current_time = millis();
            while(millis()<current_time+1500)
            {
              sf_rgt();   //move the left motor forward for 30 ms 
              if ( current_time+1400 == millis())
              {
                turn++;
              }
            } 
          }
          else 
          {
            sf_rgt();
          }
        }
        else if( turn_full == 180 )
        {
          if (turn == 00)
          {
            current_time = millis();
            while(millis()<current_time+1500)
            {
              hr_rgt();   //move the left motor forward for 30 ms 
              if ( current_time+1400 == millis())
              {
                turn++;
              }
            } 
          }
          else 
          {
            hr_rgt();
          }
        }    
        else 
        {
          hr_rgt();  //move the motor forward 
        }
      }
    }
    else if (fwd_go == 00 )
    {
      bck_rgt();
    }                    
    break;           

  default : 
    stp();  //stop the motor  
    break;           
  }
}
/*-------------------- cases function of the end here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 ------------------      function for speed calling          ---------------------*/

//forward function both motor on

void fwd()
{
  analogWrite(enleft,  s_lft);   //pwm value for the left motor 
  digitalWrite(lefta,  LOW );    //making left pin of motor low
  digitalWrite(leftb,  HIGH);    //making left pin of motor high
  digitalWrite(righta, LOW );    //making right pin of motor low
  digitalWrite(rightb, HIGH);    //making right pin of motor high
  analogWrite(enright, s_rgt);   //pwm value for the left motor 
}

// left motor on
void sf_lft()
{
  analogWrite(enleft, 72);    //pwm value for the left motor 
  digitalWrite(lefta,  LOW);  //making left pin of motor low
  digitalWrite(leftb,  HIGH); //making left pin of motor high  
  digitalWrite(righta, LOW);  //making right pin of motor low
  digitalWrite(rightb, HIGH); //making right pin of motor high
  analogWrite(enright, 0);    //pwm value for the left motor 
}

//right motor on 
void sf_rgt()
{
  analogWrite(enleft,  0);    //pwm value for the left motor 
  digitalWrite(lefta,  LOW);  //making left pin of motor low
  digitalWrite(leftb,  HIGH); //making left pin of motor high
  digitalWrite(righta, LOW);  //making right pin of motor low
  digitalWrite(rightb, HIGH); //making right pin of motor high
  analogWrite(enright, 68);   //pwm value for the left motor 
}

// left motor o
void hr_lft()
{
  analogWrite(enleft,  84);   //pwm value for the left motor 
  digitalWrite(lefta,  LOW);  //making left pin of motor low
  digitalWrite(leftb,  HIGH); //making left pin of motor high  
  digitalWrite(righta, HIGH); //making right pin of motor high
  digitalWrite(rightb, LOW);  //making right pin of motor low
  analogWrite(enright, 80);   //pwm value for the left motor 
}
//right motor on 
void hr_rgt()
{
  analogWrite(enleft,  84);    //pwm value for the left motor 
  digitalWrite(lefta,  HIGH);  //making left pin of motor high
  digitalWrite(leftb,  LOW);   //making left pin of motor low
  digitalWrite(righta, LOW);   //making right pin of motor low
  digitalWrite(rightb, HIGH);  //making right pin of motor high
  analogWrite(enright, 80);    //pwm value for the left motor 

}
//backward movement
void bck()
{
  analogWrite(enleft,  70 );    //pwm value for the left motor 
  digitalWrite(lefta,  HIGH);   //making left pin of motor high
  digitalWrite(leftb,  LOW);    //making left pin of motor low
  digitalWrite(righta, HIGH);   //making right pin of motor high
  digitalWrite(rightb, LOW);    //making right pin of motor low
  analogWrite(enright, 72);     //pwm value for the left motor 
}
//taking left turn in backward
void bck_lft()
{
  analogWrite(enleft,  70);     //pwm value for the left motor 
  digitalWrite(lefta,  HIGH);   //making left pin of motor high
  digitalWrite(leftb,  LOW);    //making left pin of motor low  
  digitalWrite(righta, HIGH);   //making right pin of motor high
  digitalWrite(rightb, LOW);    //making right pin of motor low
  analogWrite(enright, 0);      //pwm value for the left motor 
}
////taking right turn in backward 
void bck_rgt()
{
  analogWrite(enleft,  0);     //pwm value for the left motor 
  digitalWrite(lefta,  HIGH);  //making left pin of motor high
  digitalWrite(leftb,  LOW);   //making left pin of motor low
  digitalWrite(righta, HIGH);  //making right pin of motor high
  digitalWrite(rightb, LOW);   //making right pin of motor low
  analogWrite(enright, 72);    //pwm value for the left motor 
}
//both motor off position
void stp()
{
  digitalWrite(righta, LOW);  //making left pin of motor low
  digitalWrite(rightb, LOW);  //making left pin of motor low
  digitalWrite(lefta , LOW);  //making right pin of motor low
  digitalWrite(leftb , LOW);  //making right pin of motor low
}  
/*-------------------- speed calling function of the end here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 -----------------------function of the sensor data --------------------------------------*/

void sensor_data()
{
  reading_i[0]=analogRead(sen_pin[0]);                   // read the value from left input pin
  reading_i[1]=analogRead(sen_pin[1]);                   // read the value from center input pin
  reading_i[2]=analogRead(sen_pin[2]);                   // read the value from right input pin

  left   = map(reading_i[0], min_left, max_left, 0, 4);        //mapping the left function in fixed limit
  center = map(reading_i[1], min_center, max_center, 0, 4);//mapping the center function in fixed limit
  right  = map(reading_i[2], min_right, max_right, 0, 4);    //mapping the right function in fixed limit
}


/*###############################################################################################
 #################################################################################################
 ------------------      function for speed calling          ---------------------*/
void shrub_area()
{

}

/*-------------------- speed calling function of the end here --------------------------------------*/


/*###############################################################################################
 #################################################################################################
 -----------------------setup function of the start here --------------------------------------*/



void setup()
{ 
  Serial.begin(9600);                            //initializing the serial monitor for viewing    
  pinMode(sen_pin[0], INPUT);                    //initialing left sensor as input
  pinMode(sen_pin[1], INPUT);                    //initialing center sensor as input
  pinMode(sen_pin[2], INPUT);                    //initialing right sensor as input

  //initializing motor driver pins
  pinMode(enright, OUTPUT);                      //making the right pwm pin as enable 
  pinMode(righta, OUTPUT);                       //making the right pin as output 
  pinMode(rightb, OUTPUT);                       //making the right pin as output 
  pinMode(lefta, OUTPUT);                        //making the left  pin as output 
  pinMode(leftb, OUTPUT);                        //making the left  pin as output 
  pinMode(enleft, OUTPUT);                       //making the left pwm pin as enable 

  //state = right_turn(state);

  state = line_fwd(state);
}    
/*-----------------------setup  function of the end here --------------------------------------*/

/*###############################################################################################
 #################################################################################################
 -----------------------loop function of the start here --------------------------------------*/

void loop()
{
  // unsigned long currentMillis = millis();
  //sensor_data();

  Serial.print("left= ");
  Serial.print(left);
  Serial.print("\t");

  Serial.print("centre= ");
  Serial.print(center);
  Serial.print("\t");

  Serial.print("right= ");
  Serial.print(right);
  Serial.print("\t ");

  Serial.print(" i= ");
  Serial.print(i);
  Serial.print("\t ");  

  Serial.print("state= ");
  Serial.print(state);
  Serial.print("\t "); 

  Serial.print("flag= ");
  Serial.print(flag_bck);  
  Serial.print("\t \n");  

  //bck_lft();

  //state = right_turn(state);
  //    if(state == 00 && node_count == 2)
  //    {
  //   // flag  = i;
  //fwd_node_2_node(state);fwd_node_2_node(state);
  //  else if(flag != 3 )
  //   {
  //     
  //    state = start_node_2_node(state);
  //   // flag = i;
  //   }
  // grip();
  // }
}
/*-----------------------loop  function of the end here --------------------------------------*/





