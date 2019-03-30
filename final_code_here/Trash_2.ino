/*
* Function Name:trash
* Input: 
* Output: None
* Logic:implementation for backward traversal.
* Example call : line_bck( state )
/
*/

void trash(int ah)
{

  switch(ah)
  {
  case 0:
    ah0_trash_service();
    break; 
  case 1:
    ah1_trash_service();
    break;
  case 2:
    ah2_trash_service();
    break;
  case 3:
    ah3_trash_service();
    break;
  }

}


void ah0_trash_service() 
{
  
  turn_full=180;
  left_turn(state);

  line_fwd(state);
  line_bck(state);

  turn_full=90;
  left_turn(state);

  line_fwd(state);
  line_bck(state);

  turn_full =90;
  left_turn(state);
  
  velocity(55, 50);
  
  line_fwd(state);
  line_bck(state);
  
  velocity(75, 70);


  if(trash_count == 0)
  {
    increase(core,90,110);

    trash_it_down();

    decrease(core,110, 90);

    trash_count = 1;
  }
  else if(trash_count == 1)
  {
    decrease(core,90,70);

    trash_it_down();

    increase(core,70, 90);

    trash_count = 2;
  }



}
void ah1_trash_service() 
{
  turn_full=180;
  left_turn(state);

  line_fwd(state);
  line_bck(state);

  turn_full=90;
  right_turn(state);

  line_fwd(state);
  line_bck(state);

  turn_full =90;
  right_turn(state);
  
  velocity(55, 50);

  line_fwd(state);
  line_bck(state);
  
  velocity(75, 70);

  if(trash_count == 0)
  {
    increase(core,90,110);

    trash_it_down();

    decrease(core,110, 90);

    trash_count = 1;
  }
  
  else if(trash_count == 1)
  {
    decrease(core,90,70);

    trash_it_down();

    increase(core,70, 90);

    trash_count = 2;
  }




}

void ah2_trash_service() 
{
  turn_full=180;
  left_turn(state);

  line_fwd(state);
  line_bck(state);


  turn_full=90;
  left_turn(state);

  line_fwd(state);
  line_bck(state);


  turn_full =90;
  right_turn(state);

  velocity(55, 50);

  line_fwd(state);
  line_bck(state);
  
  velocity(75, 70);


  if(trash_count == 0)
  {
    increase(core,90,110);

    trash_it_down();

    decrease(core,110, 90);

    trash_count = 1;
  }
  
  else if(trash_count == 1)
  {
    decrease(core,90,70);

    trash_it_down();

    increase(core,70, 90);

    trash_count = 2;
  }



}

void ah3_trash_service() 
{
  turn_full=180;
  left_turn(state);

  line_fwd(state);
  line_bck(state);

  turn_full=90;
  right_turn(state);

  line_fwd(state);
  line_bck(state);

  turn_full =90;
  left_turn(state);
  
  velocity(55, 50);

  line_fwd(state);
  line_bck(state);
  
  velocity(75, 70);

  if(trash_count == 0)
  {
    increase(core,90,110);

    trash_it_down();

    decrease(core,110, 90);

    trash_count = 1;
  }

  else if(trash_count == 1)
  {
    decrease(core,90,70);

    trash_it_down();

    increase(core,70, 90);

    trash_count = 2;
  }



}


