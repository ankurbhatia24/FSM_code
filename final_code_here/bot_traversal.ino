




int return_case(int two_bits[])
{


  if (bitRead(SIM[two_bits[0]], 0) == 0 && bitRead(SIM[two_bits[0]], 1) == 0 && bitRead(SIM[two_bits[0]], 2) == 0 && bitRead(SIM[two_bits[0]], 3) == 0 && bitRead(SIM[two_bits[0]], 4) == 0)
  {
    supply_check[0] = 0;
  }
  else
  {
    supply_check[0] = 1;
  }

  if (bitRead(SIM[two_bits[1]], 0) == 0 && bitRead(SIM[two_bits[1]], 1) == 0 && bitRead(SIM[two_bits[1]], 2) == 0 && bitRead(SIM[two_bits[1]], 3) == 0 && bitRead(SIM[two_bits[1]], 4) == 0)
  {
    supply_check[1] = 0;
  }
  else
  {
    supply_check[1] = 1;
  }

}


void zero_three_ka_kaam()
  {

  if(supply_check[0] == 0 && supply_check[1] == 1)
  {
    turn_full = 90;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    //servo ka kaam pick place trash

    turn_full = 180;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    turn_full = 90;
    right_turn(state);

    line_fwd(state);
    line_bck(state);
  }

  if(supply_check[0] == 1 && supply_check[1] == 0)
  {
    turn_full = 90;
    right_turn(state);

    line_fwd(state);
    line_bck(state);

    //servo ka kaam pick place trash

    turn_full = 180;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    turn_full = 90;
    left_turn(state);

    line_fwd(state);
    line_bck(state);
  }

  if(supply_check[0] == 1 && supply_check[1] == 1)
  {
    turn_full = 90;
    right_turn(state);

    line_fwd(state);
    line_bck(state);

    //servo ka kaam pick place trash

    turn_full = 180;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    fwd_node_2_node(state);
    line_bck(state);

    //servo ka kaam pick place trash

    turn_full = 180;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    turn_full = 90;
    right_turn(state);

    line_fwd(state);
    line_bck(state);
  }
  }


void one_two_ka_kaam()
  {

  if(supply_check[0] == 0 && supply_check[1] == 1)
  {
    turn_full = 90;
    right_turn(state);

    line_fwd(state);
    line_bck(state);

    //servo ka kaam pick place trash

    turn_full = 180;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    turn_full = 90;
    left_turn(state);

    line_fwd(state);
    line_bck(state);
  }

  if(supply_check[0] == 1 && supply_check[1] == 0)
  {
    turn_full = 90;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    //servo ka kaam pick place trash

    turn_full = 180;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    turn_full = 90;
    right_turn(state);

    line_fwd(state);
    line_bck(state);
  }

  if(supply_check[0] == 1 && supply_check[1] == 1)
  {
    turn_full = 90;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    //servo ka kaam pick place trash

    turn_full = 180;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    fwd_node_2_node(state);
    line_bck(state);

    //servo ka kaam pick place trash

    turn_full = 180;
    left_turn(state);

    line_fwd(state);
    line_bck(state);

    turn_full = 90;
    left_turn(state);

    line_fwd(state);
    line_bck(state);
  }
  } 


void CN_2_CN(int sequence[]) // {0,3,2,1} || {1,2,3,0} || {2,1,0,3} || {3,0,1,2}
{
  int first_two_bit_array[2] = {sequence[0], sequence[1]};  //First two {0,3} , {3,0}, {1,2}, {2,1}
  int second_two_bit_array[2] = {sequence[2], sequence[3]};  //Second two {2,1} , {1,2}, {3,0}, {0,3}ce
  

  
  
  
  return_case(first_two_bit_array); // it maked the supply_check[0] and supply_check[1] {0,0}, {0,1}, {1,0}, {1,1} for First two AH 0 and 3
//  Serial.print(sequence[0]);
//  Serial.print("\n");
//  Serial.print(sequence[1]);
//  Serial.print("\n");
//  Serial.print(supply_check[0]);
//  Serial.print("\n");
//  Serial.print(supply_check[1]);
 
  if ((sequence[0] == 0 && sequence[1] == 3 ) || (sequence[0] == 3 && sequence[1] == 0 ))
  {      
            if (supply_check[0] != 0 || supply_check[1] != 0)

             // It make the bot turn left from the CN if {0,3} || {3,0} have some work 
            {
                 turn_full = 90;
                 left_turn(state);

                 line_fwd(state);
                 line_bck(state);

                 //delay
                 if(sequence[0] == 0 && sequence[1] == 3)
                 {    zero_three_ka_kaam();
                      AH_count = 2;
                 }
                 
                 else if(sequence[0] == 3 && sequence[1] == 0)
                 { 
                      one_two_ka_kaam();
                      AH_count = 2;
                 }

                 
                 //Yahan tak bot   -------> khada hai
                 //Yahan tak bot   -------> khada hai
                 //Yahan tak bot   -------> khada hai
            

                 return_case(second_two_bit_array); // it maked the supply_check[0] and supply_check[1] {0,0}, {0,1}, {1,0}, {1,1} for last two AH, 1 and 2
                 if (supply_check[0] != 0 || supply_check[1] != 0)
                 {
                      fwd_node_2_node(state);
                      line_bck(state);

                      //delay

                          if(sequence[0] == 2 && sequence[1] == 1)
                          {    zero_three_ka_kaam();
                               AH_count = 4;
                          }
                          else if(sequence[0] == 1 && sequence[1] == 2)
                          { 
                               one_two_ka_kaam();
                               AH_count = 4;
                          }

                     
                          //bot <------ ese khada hai
                          //bot <------ ese khada hai
                          //bot <------ ese khada hai

                          //Yahan se bot ko start pe le jao and kaam khatam
                          turn_full = 90;
                          left_turn(state);
                 } 
                 else
                 {
                     AH_count = 4;
                     //Yahan tak bot   -------> khada hai
                     //Yahan tak bot   -------> khada hai
                     //Yahan tak bot   -------> khada hai

                     //Yahan se bot ko start pe le jao and kaam khatam
                     turn_full = 90;
                     right_turn(state);

                     line_bck(state);
                     //Yahan tak bot   v  khada hai
                     //Yahan tak bot   v  khada hai
                     //Yahan tak bot   v  khada hai
                     
                 }



             }
             else
             {
                 AH_count = 2;
                 
                 //Yahan tak bot  ^  khada hai
                 //Yahan tak bot  ^  khada hai
                 //Yahan tak bot  ^  khada hai

                 return_case(second_two_bit_array);
                 if (supply_check[0] != 0 || supply_check[1] != 0)
                 {
                          turn_full = 90;
                          right_turn(state);
                          
                          line_fwd(state);
                          line_bck(state);

                          //delay

                          if(sequence[0] == 2 && sequence[1] == 1)
                          {    zero_three_ka_kaam();
                               AH_count = 4;
                          }
                          else if(sequence[0] == 1 && sequence[1] == 2)
                          { 
                               one_two_ka_kaam();
                               AH_count = 4;
                          }

                     
                          //bot <------ ese khada hai
                          //bot <------ ese khada hai
                          //bot <------ ese khada hai

                          //Yahan se bot ko start pe le jao and kaam khatam
                          turn_full = 90;
                          left_turn(state);

                          line_bck(state);
                          //Yahan tak bot   v  khada hai
                          //Yahan tak bot   v  khada hai
                          //Yahan tak bot   v  khada hai
                 } 
                 else
                 {
                          AH_count = 4;

                          //Yahan se bot ko start pe le jao and kaam khatam
                          turn_full = 180;
                          left_turn(state);

                          line_bck(state);
                          //Yahan tak bot   v  khada hai
                          //Yahan tak bot   v  khada hai
                          //Yahan tak bot   v  khada hai


                 }
                 
             
             }
  
  }

  else if ((sequence[0] == 1 && sequence[1] == 2 ) || (sequence[0] == 2 && sequence[1] == 1 ))
  { 

               if (supply_check[0] != 0 || supply_check[1] != 0)

             // It make the bot turn left from the CN if {0,3} || {3,0} have some work 
              {
                 //Yahan tak bot ^ khada hai
                 //Yahan tak bot ^ khada hai
                 //Yahan tak bot ^ khada hai
                 turn_full = 90;
                 right_turn(state);

                 line_fwd(state);
                 line_bck(state);

                 //delay
                 if(sequence[0] == 1 && sequence[1] == 2)
                 {    one_two_ka_kaam();
                      AH_count = 2;
                 }
                 
                 else if(sequence[0] == 2 && sequence[1] == 1)
                 { 
                      zero_three_ka_kaam();
                      AH_count = 2;
                 }

                 
                 //Yahan tak bot   <------- khada hai
                 //Yahan tak bot   <------- khada hai
                 //Yahan tak bot   <------- khada hai
            

                 return_case(second_two_bit_array); // it maked the supply_check[0] and supply_check[1] {0,0}, {0,1}, {1,0}, {1,1} for last two AH, 1 and 2
                 
                 if (supply_check[0] != 0 || supply_check[1] != 0)
                 {
                      fwd_node_2_node(state);
                      line_bck(state);

                      //delay

                          if(sequence[0] == 0 && sequence[1] == 3)
                          {    zero_three_ka_kaam();
                               AH_count = 4;
                          }
                          else if(sequence[0] == 3 && sequence[1] == 0)
                          { 
                               one_two_ka_kaam();
                               AH_count = 4;
                          }

                     
                          //bot ------> ese khada hai
                          //bot ------> ese khada hai
                          //bot ------> ese khada hai

                          //Yahan se bot ko start pe le jao and kaam khatam
                          turn_full = 90;
                          right_turn(state);
                 } 
                 else
                 {
                     AH_count = 4;
                     //Yahan tak bot   <------- khada hai
                     //Yahan tak bot   <------- khada hai
                     //Yahan tak bot   <------- khada hai

                     //Yahan se bot ko start pe le jao and kaam khatam
                     turn_full = 90;
                     left_turn(state);

                     line_bck(state);
                     //Yahan tak bot   v  khada hai
                     //Yahan tak bot   v  khada hai
                     //Yahan tak bot   v  khada hai
                     
                 }



             }
             else
             {
                 AH_count = 2;
                 
                 //Yahan tak bot  ^  khada hai
                 //Yahan tak bot  ^  khada hai
                 //Yahan tak bot  ^  khada hai

                 return_case(second_two_bit_array);
                 
                 if (supply_check[0] != 0 || supply_check[1] != 0)
                 {
                          turn_full = 90;
                          left_turn(state);
                          
                          line_fwd(state);
                          line_bck(state);

                          //delay

                          if(sequence[0] == 0 && sequence[1] == 3)
                          {    zero_three_ka_kaam();
                               AH_count = 4;
                          }
                          else if(sequence[0] == 3 && sequence[1] == 0)
                          { 
                               one_two_ka_kaam();
                               AH_count = 4;
                          }

                     
                          //bot ------> ese khada hai
                          //bot ------> ese khada hai
                          //bot ------> ese khada hai

                          //Yahan se bot ko start pe le jao and kaam khatam
                          turn_full = 90;
                          right_turn(state);

                          line_bck(state);
                          //Yahan tak bot   v  khada hai
                          //Yahan tak bot   v  khada hai
                          //Yahan tak bot   v  khada hai
                 } 
                 else
                 {
                          AH_count = 4;

                          //Yahan se bot ko start pe le jao and kaam khatam
                          turn_full = 180;
                          left_turn(state);

                          line_bck(state);
                          //Yahan tak bot   v  khada hai
                          //Yahan tak bot   v  khada hai
                          //Yahan tak bot   v  khada hai


                 }
                 
             
             }

  }
  

}







