 /*
* Function Name:return_case()
* Input: None
* Output: None
* Logic:       


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
               sf_lft();
                delay(1200);
                turn++;
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
                hr_lft();
                delay(1300);
                turn++;
          }
          else 
          {
            hr_lft();
          }
        } 
      }

      else 
      {
        sf_lft();  //move the motor forward 
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
          if (turn == 11)
          {
            sf_rgt();
            delay(1500);
            turn++;
          }
          else 
          {
            sf_rgt();
          }
        }
        else if( turn_full == 180 )
        {
          if (turn == 11)
          {
            hr_rgt();
            delay(1500);
            turn++;
          }
          else 
          {
            hr_rgt();
          }
        }   
      } 
      else 
      {
        sf_rgt();  //move the motor forward 
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

