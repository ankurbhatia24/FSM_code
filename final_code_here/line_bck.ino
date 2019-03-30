/*
* Function Name:line_bck
* Input: Initial state 
* Output: None
* Logic: implementation for backward traversal.
* Example call : line_bck( state )
/*

/*###############################################################################################
 #################################################################################################
 ------------------       program to follow backward line to node turn     ---------------------*/
int line_bck1( int state )
{
  fwd_go = 00 ; //backward
  flag_bck = 0;
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
 
          state = 10;//right
          cases(state);
        
      }  
      else if(left >= 1 && center >= 1 && right == 0)
      {
       
        state = 10 ;
        cases(state);   
      }
      else if(left == 0 && center == 0 && right >= 3)
      {

          state = 01;//right
          cases(state);
        
      }
      else if(left == 0 && center >= 1 && right >= 1) 
      {
        
        state = 01;//left
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
      else if( (left >= 1 && center == 0 && right == 0) || (left >= 1 && center >= 1 && right == 0)  )
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
      else if( (left == 0 && center == 0 && right >= 2) || (left == 0 && center >= 1 && right >= 1) )
      {
        state = 01;//left
        cases(state);
      }  
    }
  }

  return state; 
}
/*-------------------- backward line follow function of the end here --------------------------------------*/


