//
///*
// * Team Id:2683
//
// * Author List: Ankur,Charvi
//         
// * Filename:bot_traversal.ino
// * Theme: Ant Bot
// * Functions:return_case, left_traversal, right_traversal, CN_2_end
// * Global Variables: None
// */
//
//
///*###############################################################################################
// ################################################################################################# */
//
///*
//* Function Name:return_case()
//* Input: None
//* Output: None
//* Logic: It takes the first two AH from the sequence of AH to be followed and then 
//*        it makes the supply_check[2] array to be {0, 0}, {0, 1}, {1,0}, {1, 1} 
//*        {0, 0} => No service at both the AH of the first two || second two AH in sequence
//*        {0, 1} => Service only at the 2nd AH of the first two || second two AH in sequence
//*        {1, 0} => Service at the 1st AH of the first two || second two AH in sequence
//*        {1, 1} => Service at both AH of the first two || second two AH in sequence
//*Example Call: return_case();
//*/
//
//
//void millis_delay(int interval)  //Function provides required hardware delays
//{
//  current_time = millis();
//  while(millis()<current_time+interval){
//  }
//
//} 
//
//int return_case()
//{
//
//
//  if (bitRead(SIM[two_bits[0]], 0) == 0 && bitRead(SIM[two_bits[0]], 1) == 0 && bitRead(SIM[two_bits[0]], 2) == 0 && bitRead(SIM[two_bits[0]], 3) == 0 && bitRead(SIM[two_bits[0]], 4) == 0)
//  {
//    supply_check[0] = 0;
//  }
//  else
//  {
//    supply_check[0] = 1;
//  }
//
//  if (bitRead(SIM[two_bits[1]], 0) == 0 && bitRead(SIM[two_bits[1]], 1) == 0 && bitRead(SIM[two_bits[1]], 2) == 0 && bitRead(SIM[two_bits[1]], 3) == 0 && bitRead(SIM[two_bits[1]], 4) == 0)
//  {
//    supply_check[1] = 0;
//  }
//  else
//  {
//    supply_check[1] = 1;
//  }
//
//}
//
///*###############################################################################################
// ################################################################################################# */
// 
///*
//* Function Name:left_traversal()
//* Input: None
//* Output: None
//* Logic: Traverse on the AH depending on the Service requirements on AH
//*Example Call: left_traversal();
//*/
//
//void left_traversal()
//{
//
//  if(supply_check[0] == 0 && supply_check[1] == 1)
//  {
//    turn_full = 90;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    //servo ka kaam 
//    service_at_ah(two_bits[1]); 
//
//    turn_full = 180;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    turn_full = 90;
//    right_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//  }
//
//  if(supply_check[0] == 1 && supply_check[1] == 0)
//  {
//    turn_full = 90;
//    right_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    //servo ka kaam pick place trash
//    service_at_ah(two_bits[0]);
//
//    turn_full = 180;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    turn_full = 90;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//  }
//
//  if(supply_check[0] == 1 && supply_check[1] == 1)
//  {
//    turn_full = 90;
//    right_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    //servo ka kaam pick place trash
//    service_at_ah(two_bits[0]); 
//
//    turn_full = 180;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    fwd_node_2_node(state);
//    line_bck(state);
//
//    //servo ka kaam pick place trash
//    service_at_ah(two_bits[1]);
//
//    turn_full = 180;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    turn_full = 90;
//    right_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//  }
//}
//
///*###############################################################################################
// ################################################################################################# */
//
///*
//* Function Name:right_traversal()
//* Input: None
//* Output: None
//* Logic: Traverse on the AH depending on the Service requirements on AH
//*Example Call: right_traversal();
//*/
//
//void right_traversal()
//{
//
//  if(supply_check[0] == 0 && supply_check[1] == 1)
//  {
//    turn_full = 90;
//    right_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    //servo ka kaam pick place trash
//    service_at_ah(two_bits[1]);
//
//    turn_full = 180;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    turn_full = 90;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//  }
//
//  if(supply_check[0] == 1 && supply_check[1] == 0)
//  {
//    turn_full = 90;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    //servo ka kaam pick place trash
//    service_at_ah(two_bits[0]);
//
//    turn_full = 180;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    turn_full = 90;
//    right_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//  }
//
//  if(supply_check[0] == 1 && supply_check[1] == 1)
//  {
//    turn_full = 90;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    //servo ka kaam pick place trash
//    service_at_ah(two_bits[0]);
//
//    turn_full = 180;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    fwd_node_2_node(state);
//    line_bck(state);
//
//    //servo ka kaam pick place trash
//    service_at_ah(two_bits[1]);
//
//    turn_full = 180;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//
//    turn_full = 90;
//    left_turn(state);
//
//    line_fwd(state);
//    line_bck(state);
//  }
//} 
//
///*###############################################################################################
// ################################################################################################# */
//
///*
//* Function Name:CN_2_end()
//* Input: sequence[] => An array which stores the sequence of AH to be serviced
//* Output: None
//* Logic: Servicing all the Ant Hills in the priority order
//*Example Call: CN_2_end(sequence);
//*/
//
//void CN_2_end(int sequence[]) // {0,3,2,1} || {1,2,3,0} || {2,1,0,3} || {3,0,1,2}
//{
////  int first_two_bit_array[2] = {
////    sequence[0], sequence[1]  };  //First two {0,3} , {3,0}, {1,2}, {2,1}
////  int second_two_bit_array[2] = {
////    sequence[2], sequence[3]  };  //Second two {2,1} , {1,2}, {3,0}, {0,3}
//
//
//
//
//
//  two_bits[0] = sequence[0];   //First two {0,3} , {3,0}, {1,2}, {2,1}
//  two_bits[1] = sequence[1];
//  return_case(); // it maked the supply_check[0] and supply_check[1] {0,0}, {0,1}, {1,0}, {1,1} for First two AH 0 and 3
//
//  if ((sequence[0] == 0 && sequence[1] == 3 ) || (sequence[0] == 3 && sequence[1] == 0 ))
//  {      
//    if (supply_check[0] != 0 || supply_check[1] != 0)
//
//      // It make the bot turn left from the CN if {0,3} || {3,0} have some work 
//    {
//      turn_full = 90;
//
//      left_turn(state);
//
//      line_fwd(state);
//      line_bck(state);
//
//
//      if(sequence[0] == 0 && sequence[1] == 3)
//      {    
//        left_traversal();
//        AH_count = 2;
//      }
//
//      else if(sequence[0] == 3 && sequence[1] == 0)
//      { 
//        right_traversal();
//        AH_count = 2;
//      }
//
//
//      //Presently bot   -------> stands like this
//      //Presently bot   -------> stands like this
//      //Presently bot   -------> stands like this
//
//
//      two_bits[0] = sequence[2];    //Second two {2,1} , {1,2}, {3,0}, {0,3}
//      two_bits[1] = sequence[3];
//      return_case(); // it maked the supply_check[0] and supply_check[1] {0,0}, {0,1}, {1,0}, {1,1} for last two AH, 1 and 2
//
//      if (supply_check[0] != 0 || supply_check[1] != 0)
//      {
//        fwd_node_2_node(state);
//        line_bck(state);
//
//        //delay
//
//        if(sequence[2] == 2 && sequence[3] == 1)
//        {    
//          left_traversal();
//          AH_count = 4;
//        }
//        else if(sequence[2] == 1 && sequence[3] == 2)
//        { 
//          right_traversal();
//          AH_count = 4;
//        }
//
//
//        //Presently bot <------ stands like this
//        //Presently bot <------ stands like this
//        //Presently bot <------ stands like this
//
//        //Move bot to CN
//        turn_full = 90;
//        left_turn(state);
//
//
//      } 
//      else
//      {
//        AH_count = 4;
//        
//        //Presently bot   -------> stands like this
//        //Presently bot   -------> stands like this
//        //Presently bot   -------> stands like this
//
//        //Move bot to CN
//        turn_full = 90;
//        right_turn(state);
//
//
//        //Presently bot   ^   stands like this
//        //Presently bot   ^   stands like this
//        //Presently bot   ^   stands like this
//
//      }
//
//
//
//    }
//    else
//    {
//      AH_count = 2;
//
//        //Presently bot   ^   stands like this
//        //Presently bot   ^   stands like this
//        //Presently bot   ^   stands like this
//
//      two_bits[0] = sequence[2];    //Second two {2,1} , {1,2}, {3,0}, {0,3}
//      two_bits[1] = sequence[3];
//      return_case();
//      if (supply_check[0] != 0 || supply_check[1] != 0)
//      {
//        turn_full = 90;
//        right_turn(state);
//
//        line_fwd(state);
//        line_bck(state);
//
//
//
//        if(sequence[2] == 2 && sequence[3] == 1)
//        {    
//          left_traversal();
//          AH_count = 4;
//        }
//        else if(sequence[2] == 1 && sequence[3] == 2)
//        { 
//          right_traversal();
//          AH_count = 4;
//        }
//
//
//        //bot <------ stands like this
//        //bot <------ stands like this
//        //bot <------ stands like this
//
//        //Yahan se bot ko start pe le jao and kaam khatam
//        turn_full = 90;
//        left_turn(state);
//
//
//
//        //Presently bot   v   stands like this
//        //Presently bot   v   stands like this
//        //Presently bot   v   stands like this
//      } 
//      else
//      {
//        AH_count = 4;
//
//        //ROtate bot on CN
//        turn_full = 180;
//        left_turn(state);
//
//
//        //Presently bot   v   stands like this
//        //Presently bot   v   stands like this
//        //Presently bot   v   stands like this
//
//
//      }
//
//
//    }
//
//  }
//
//  else if ((sequence[0] == 1 && sequence[1] == 2 ) || (sequence[0] == 2 && sequence[1] == 1 ))
//  { 
//
//    if (supply_check[0] != 0 || supply_check[1] != 0)
//
//      // It make the bot turn left from the CN if {0,3} || {3,0} have some work 
//    {
//
//      //Presently bot   ^   stands like this
//      //Presently bot   ^   stands like this
//      //Presently bot   ^   stands like this
//      
//      turn_full = 90;
//      right_turn(state);
//
//      line_fwd(state);
//      line_bck(state);
//
//      //delay
//      if(sequence[0] == 1 && sequence[1] == 2)
//      {    
//        right_traversal();
//        AH_count = 2;
//      }
//
//      else if(sequence[0] == 2 && sequence[1] == 1)
//      { 
//        left_traversal();
//        AH_count = 2;
//      }
//
//
//        //bot <------ stands like this
//        //bot <------ stands like this
//        //bot <------ stands like this
//
//
//     two_bits[0] = sequence[2];   //Second two {2,1} , {1,2}, {3,0}, {0,3}
//     two_bits[1] = sequence[3];  
//     return_case(); // it maked the supply_check[0] and supply_check[1] {0,0}, {0,1}, {1,0}, {1,1} for last two AH, 1 and 2
//
//      if (supply_check[0] != 0 || supply_check[1] != 0)
//      {
//        fwd_node_2_node(state);
//        line_bck(state);
//
//        //delay
//
//        if(sequence[2] == 0 && sequence[3] == 3)
//        {    
//          left_traversal();
//          AH_count = 4;
//        }
//        else if(sequence[2] == 3 && sequence[3] == 0)
//        { 
//          right_traversal();
//          AH_count = 4;
//        }
//
//
//        //Presently bot   -------> stands like this
//        //Presently bot   -------> stands like this
//        //Presently bot   -------> stands like this
//
//        //Rotate bot on CN
//        turn_full = 90;
//        right_turn(state);
//      } 
//      else
//      {
//        AH_count = 4;
//        //bot <------ stands like this
//        //bot <------ stands like this
//        //bot <------ stands like this
//
//        //Rotate bot on CN
//        turn_full = 90;
//        left_turn(state);
//
//
//        //Presently bot   v   stands like this
//        //Presently bot   v   stands like this
//        //Presently bot   v   stands like this
//
//      }
//
//
//
//    }
//    else
//    {
//      AH_count = 2;
//
//      //Presently bot   ^   stands like this
//      //Presently bot   ^   stands like this
//      //Presently bot   ^   stands like this
//
//      two_bits[0] = sequence[2];   //Second two {2,1} , {1,2}, {3,0}, {0,3}
//      two_bits[1] = sequence[3];
//      return_case();
//
//      if (supply_check[0] != 0 || supply_check[1] != 0)
//      {
//        turn_full = 90;
//        left_turn(state);
//
//        line_fwd(state);
//        line_bck(state);
//
//        //delay
//
//        if(sequence[2] == 0 && sequence[3] == 3)
//        {    
//          left_traversal();
//          AH_count = 4;
//        }
//        else if(sequence[2] == 3 && sequence[3] == 0)
//        { 
//          right_traversal();
//          AH_count = 4;
//        }
//
//        //Presently bot   -------> stands like this
//        //Presently bot   -------> stands like this
//        //Presently bot   -------> stands like this
//
//        //Rotate bot on CN
//        turn_full = 90;
//        right_turn(state);
//
//
//        //Presently bot   v   stands like this
//        //Presently bot   v   stands like this
//        //Presently bot   v   stands like this
//      } 
//      else
//      {
//        AH_count = 4;
//
//        //Rotate on CN 
//        turn_full = 180;
//        left_turn(state);
//
//
//        //Presently bot   v   stands like this
//        //Presently bot   v   stands like this
//        //Presently bot   v   stands like this
//
//
//      }
//
//
//    }
//
//  }
//
//
//}
//
//
///*###############################################################################################
// ################################################################################################# */
//
//
//

