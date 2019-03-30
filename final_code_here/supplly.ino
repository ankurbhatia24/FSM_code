void supply1()
{
  turn_full = 90;
  right_turn(state);

  decrease(core, 90, 5);
   
  velocity(65, 60); 
  
  line_fwd(state);
  delay(400);
  line_bck(state);
  delay(400);
  
  color_detect1();

  fwd_node_2_node(state);
  delay(300);
  line_bck(state);
  delay(300);
  

  color_detect2();
  color_glow(1);
  pick_it();

  fwd_node_2_node(state);
  delay(300);
  line_bck(state);
  delay(300);

  color_detect1();
 

  turn_full = 180;
  left_turn(state);
  
  increase(core, 0, 177);

  line_fwd(state);
  delay(300);
  line_bck(state);
  delay(300);

  fwd_node_2_node(state);
  delay(300);
  line_bck(state);
  delay(300);

  fwd_node_2_node(state);
  delay(300);
  line_bck(state);
  delay(300);
  


  fwd_node_2_node(state);
  delay(300);
  line_bck(state);
  delay(300);


  color_detect2();
  
  fwd_node_2_node(state);
  delay(300);
  line_bck(state);
  delay(300);
  
  color_detect1();
  
  fwd_node_2_node(state);
  delay(300);
  line_bck(state);
  delay(300);
  
  color_detect2();
  color_glow(3);
  pick_it_up();
  
  turn_full = 180;
  left_turn(state);
  
  decrease(core, 177, 0);
  
  line_fwd(state);
  delay(300);
  line_bck(state);
  delay(300);
  
  fwd_node_2_node(state);
  delay(300);
  line_bck(state);
  delay(300);
  
  color_glow(2);
  pick_it_up();
  
  fwd_node_2_node(state);
  delay(300);
  line_bck(state);
  delay(300);
  
  velocity(72,68);
  
  turn_full = 90;
  right_turn(state);
  
  line_fwd(state);
  delay(300);
  line_bck(state);
  delay(300);
  
  velocity(97, 81);
  
  

}

