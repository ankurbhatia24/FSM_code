
/*###############################################################################################
 #################################################################################################
 ------------------       program to follow backward line to node turn           ---------------------
 int line_bck1( int state )
 {
 fwd_go = 00 ; //backward
 flag_bck =4;
 i=20;
 while (flag_bck != 9)
 {  i=8;
 sensor_data(); 
 
 //   i=45;
 //    if(flag_fwd == 3 || flag_fwd == 9)
 //    { 
 //      if(( left == 0 && center >= 1 && right >= 1) || ( left == 0 && center == 0 && right == 0) || ( left == 0 && center == 0 && right >= 1) ||( left == 0 && center == 0 && right >= 0))
 //      { flag_bck=0;
 //      current_time = millis();
 //        while((millis()<current_time+10))
 //        { i=50;
 //          state = 01;//
 //          cases(state);
 //          sensor_data(); 
 //          if ( left == 0 && center >= 1 && right >= 0)
 //          {i=56;
 //            flag_bck = 5;//any arbitary flag to call backward line to node 
 //            flag_fwd = 5;//any arbitary flag
 //            //break;
 //          }  
 //        }
 //      } 
 //      if((left == 1 && center >= 1 && right == 0) || ( left == 0 && center == 0 && right == 0) ||  (left == 1 && center >= 0 && right == 0) ||( left == 0 && center == 0 && right >= 0)) 
 //      { current_time = millis();
 //        while((millis()<current_time+15))
 //        { i=59;
 //          state = 10;//
 //          cases(state);
 //          sensor_data(); 
 //          if ( left == 0 && center >= 1 && right >= 0)
 //          {i=60;
 //            flag_bck = 5;//any arbitary flag to call backward line to node 
 //            flag_fwd = 5;//any arbitary flag
 //            //break;
 //          }
 //        }  
 //      } 
 //    } 
 
 if ((left >= 1 && center >= 2 && right >= 1) || (left >=1 && center>=1 && right >=0) || (left >=0 && center>=1 && right >=1)  ) 
 { 
 flag_bck =9;
 state = 00;//stop
 cases(state);      
 }
 
 
 
 else if( flag_bck == 5 || flag_bck == 4 )
 {   
 if(left == 0 && center >= 1 && right == 0)
 {
 state = 11;//backward
 cases(state);
 }
 else if (left >= 1 && center >= 2 && right >= 1) 
 {
 flag_bck = 9;
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
 flag_bck =9;
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
 flag_bck =9;
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
 state = 10;//stop
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
 state = 10;//stop
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
 ------------------       program to follow backward line to node turn           ---------------------*/
int line_bck2( int state )
{
  fwd_go = 00 ; //backward
  flag_bck =0;
  i=20;
  while (flag_bck != 3)
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
        if(left == 0 && center >= 3 && right == 0)
        {
          flag_bck =2;
          state = 11;//fordward
          cases(state);


        }     
        else if((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck =3;
          state = 00;//fordward
          cases(state); 
          break;


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
          flag_bck =1;  
          state = 11;
          cases(state);

        }     
        else if((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck =3;
          state = 00;
          cases(state);
          break;
        }
        else if((left >= 2 && center >= 2 && right >= 0) || (left >= 3 && center == 0 && right == 0))
        {

          state = 10;//left
          cases(state); 
        }  
      }      
      else  if (state == 10)
      {
        if(left == 0 && center >= 2 && right == 0)
        {
          flag_bck =1;
          state = 11;
          cases(state); 
        }      
        else if((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck = 3;
          state = 00;
          cases(state);  
          break;
        }
        else if((left == 0 && center >= 2 && right >= 2) || (left == 0 && center == 0 && right >= 2)) 
        {
          state = 01;//right
          cases(state);
        }  
      }
    }




  }
  return state;
}


