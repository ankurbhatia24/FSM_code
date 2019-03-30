/*
* Function Name:fwd_node_2_node
* Input: Initial state 
* Output: None
* Logic:implementation for bot traversal from one node to other.
* Example call : fwd_node_2_node( state )
/*
/*###############################################################################################
 #################################################################################################
 ------------------       function for going from forward node to node    ---------------------*/




int fwd_node_2_node(int state  )
{
  fwd_go = 11;
  flag_fwd = 0 ;
  while(flag_fwd != 3)
  { 
    sensor_data();

    if (flag_fwd == 0)
    {

      if ((left >= 1 && center >= 1 && right == 0) || (left == 0 && center >= 1 && right >= 1) || (left >=1  && center >= 1 && right >= 1)  )
      { //current_time = millis();
        //while((millis()<current_time+15))
        {
        flag_fwd = 1;
        state = 11;
        cases(state); 
      }      
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
        else if(left >= 1 && center >= 1 && right >= 1)
        {
          state = 11;//fordward
          cases(state);        
        }
        else if((left >= 2 && center >= 3 && right == 0) || (left >= 3 && center == 0 && right == 0))
        {
          state = 10;//left
          cases(state);

        }
        else if((left == 0 && center >= 1 && right >= 1) || (left == 0 && center == 0 && right >= 1)) 
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
        if(left == 0 && center >= 1 && right == 0)
        {
          flag_fwd =2;
          state = 11;
          cases(state); 
        }      
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if((left == 0 && center >= 1 && right >= 1) || (left == 0 && center == 0 && right >= 1)) 
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
          flag_fwd =3; 
          state = 00;//stop
          cases(state);
                      
        }
       else if(left >= 1 && center >= 1 && right == 0)
        {
          flag_fwd =3;
          state = 00 ;
          cases(state);   
        }   
       else if(left == 0 && center >= 1 && right >= 1) 
        {
          flag_fwd=3;
          state = 00;//right
          cases(state);
        }        
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;//fordward
          cases(state);
        }


        else if(left >= 1 && center == 0 && right == 0)
        {
        //  while((state == 11) && (millis()<current_time+5))
          //{
            state = 10;//left  right
            cases(state);
         // }
        }   
        else if(left == 0 && center == 0 && right >= 1)
        {
          //while((state == 11) && (millis()<current_time+5))
        //  {
            state = 01;//left
            cases(state);
          //}
        }

        else 
        {
          state=11;//fordward
          cases(state);
        }
      }   

      else if (state == 01)
      {
        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 1 && right == 0) || (left >= 0 && center >= 1 && right >= 1))
        {
           flag_fwd =3;
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
          state = 10;//left
          cases(state);
        }  
      }   

      else  if (state == 10)
      {
        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 1 && right == 0) || (left >= 0 && center >= 1 && right >= 1))
        {
          flag_fwd =3;
          state = 00;//stop
          cases(state);            
        }             
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if (left == 0 && center == 0 && right >= 1)
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

