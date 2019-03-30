/*
* Function Name:line_bck
* Input: Initial state 
* Output: None
* Logic:implementation for backward traversal.
* Example call : line_bck( state )
/
/*###############################################################################################
 #################################################################################################
 ------------------       program to follow backward line to node turn           ---------------------*/
int line_bck( int state )
{
  fwd_go = 00 ; //backward
  flag_bck =0;
  i=20;
  while (flag_bck != 9)
  {  

    sensor_data(); 

    if (state == 00)
    {
      if ((left >= 0 && center >= 1 && right >= 0) || (left >= 1 && center >= 1 && right >= 0) || (left >= 1 && center >= 0 && right >= 0) || (left >= 0 && center >= 0 && right >= 0) || (left >= 0 && center >= 0 && right >= 1) || (left >= 0 && center >= 1 && right >= 1) || (left >=1  && center >= 1 && right >= 1)  )
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
        if(left == 0 && center >= 1 && right == 0)
        {
          flag_bck =2;
          state = 11;//fordward
          cases(state);
           

        }     
        else if((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          state = 00;//fordward
          cases(state); 
          break;
            
             
        }
        else if( (left >= 3 && center == 0 && right == 0))
        {
          state = 01;//left
          cases(state);

        }
        else if(left >= 1 && center >= 1 && right >= 0) 
        {
          state = 00 ;
          cases(state);
          break;
        }
        else if( (left == 0 && center == 0 && right >= 3)) 
        {
          state = 10;//right
          cases(state);
        } 
       else if(left == 0 && center >= 1 && right >= 1) 
        {
          state = 00 ;
          cases(state);
          break;
        }
      }     

      else if (state == 01)
      {
        if(left == 0 && center >= 1 && right == 0)
        {
          flag_bck =2;  
          state = 11;
          cases(state);

        }     
        else if((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck =9;
          state = 00;
          cases(state);
          break;
        }
        else if((left >= 1 && center == 0 && right == 0))
        {

          state = 01;//left
          cases(state); 
        }  
        else if(left >=1 && center >= 1 && right >= 0) 
        {
          state = 00 ;
          cases(state);
          break;
        }
      }      
      else  if (state == 10)
      {
        if(left == 0 && center >= 1 && right == 0)
        {
          flag_bck =2;
          state = 11;
          cases(state); 
        }      
        else if((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck = 9;
          state = 00;
          cases(state);  
           break;
        }
        else if( (left == 0 && center == 0 && right >= 2)) 
        {
          state = 10;//right
          cases(state);
        }  
        else if(left == 0 && center >= 1 && right >= 1) 
        {
          state = 00 ;
          cases(state);
          break;
        }
      }
    }





    //follow straight line
    else if(flag_bck == 2)
    {      
      //state
      current_time = millis();
     if( state == 11)
      {   

        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck =9; 
          state = 00;//stop
          cases(state);
          break;
  
        }
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;//fordward
          cases(state);
        }


        else if(left >= 1 && center == 0 && right == 0)
        {
//          while((state == 11) && (millis()<current_time+10))
//          {
            state = 01;//left  right
            cases(state);
    //      }
        }  
        else if(left >= 0 && center >= 1 && right >= 1) 
        {
          flag_bck = 9 ;
          state = 00 ;
          cases(state);
       break;  
      
        }
        else if(left == 0 && center == 0 && right >= 1)
        {
//          while((state == 11) && (millis()<current_time+10))
//          {
            state = 10;//left
            cases(state);
        //  }
        }
        else if(left >= 1 && center >= 1 && right >= 0) 
        {
          flag_bck = 9;
          state = 00;//right
          cases(state);
          break;
           
        } 
//        else 
//        {
//          state=11;//fordward
//          cases(state);
//        }
      }   

      else if (state == 01)
      {
        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck =9;
          state = 00;//stop
          cases(state);
          break; 

        }
        else  if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if(left >= 1 && center == 0 && right == 0)
        {
          state = 01;//left
          cases(state);
        }  
                else if(left >= 1 && center >= 1 && right >= 0) 
        {
          flag_bck = 9;
          state = 00;//right
          cases(state);
          break;
           
        }
      }   

      else  if (state == 10)
      {
        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1)) 
        {
          flag_bck =9;
          state = 00;//stop
          cases(state);
          break;
         
        }             
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if (left == 0 && center == 0 && right >= 2)
        {
          state = 10;//right
          cases(state);
        }  
                else if(left >= 0 && center >= 1 && right >= 1) 
        {
          flag_bck = 9 ;
          state = 00 ;
          cases(state);
       break;  
      
        }
      }
    }
  }  
  //return state;
 
}
/*-------------------- backward line follow function of the end here --------------------------------------*/


