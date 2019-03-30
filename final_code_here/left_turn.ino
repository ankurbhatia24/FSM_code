/*
* Function Name:left_turn
* Input: Initial state 
* Output: None
* Logic: implementation for left turn at node.
* Example call : left_turn( state )
/*
/*###############################################################################################
 #################################################################################################
 ------------------       program for taking left turn           ---------------------*/

int  left_turn(int state)
{ 
  fwd_go = 11;
  turn_go = 11;
  flag_lft = 0;
  while(flag_lft != 9)
  { 
    sensor_data();
    
//    i=10;
//    
//    if(flag_fwd == 3 || flag_fwd == 9 )
//    { 
//      if( left == 0 && center >= 1 && right >= 1) 
//      { current_time=millis();
//        while((millis()<current_time+15))
//        {
//          //sensor_data();
//          state = 10;//
//          cases(state);
////          if ( left == 0 && center >= 1 && right >= 0)
////          {
////            flag_bck = 0;//any arbitary flag to call backward line to node 
////            flag_fwd = 5;//any arbitary flag
////            //break;
////          }  
//        }
//      } 
//      if(left == 1 && center >= 1 && right == 0) 
//      {
//        current_time=millis();
//        while((millis()<current_time+15))
//        {
//          //sensor_data();
//          state = 10;//
//          cases(state);
////          if ( left == 0 && center >= 1 && right >= 0)
////          {
////            flag_bck = 0;//any arbitary flag to call backward line to node 
////            flag_fwd = 5;//any arbitary flag
////           // break;
////          }
//        }  
//      } 
//    }     

    if ((state == 00)  && flag_lft == 0 )
    { 
    
     if ((left >= 1 && center >= 2 && right >= 1) || (left >= 1 && center >= 2 && right >= 0) || (left >= 0 && center >= 2 && right >= 1))
      {
        flag_lft=5;
        turn=11;
        state =10;//right turn
        cases(state);
        
      }
    } 
    else if(state ==10   && flag_lft == 5 )
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

