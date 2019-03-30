//int first_pick =0;
void color_glow(int c)
{
  if(c == 1)
  {
    
    digitalWrite(led_pin[0],HIGH);
    
    delay(1000);
    
    digitalWrite(led_pin[0], LOW);
    
  }
  else if(c == 2)
  {

    digitalWrite(led_pin[1],HIGH);

    delay(1000);

    digitalWrite(led_pin[1],LOW);

  }
  else if(c == 3){

    digitalWrite(led_pin[2],HIGH);
    
    delay(1000);
    
    digitalWrite(led_pin[2], LOW);
    
  }
  else if(c == 4){
    
    digitalWrite(led_pin[0],HIGH);
    digitalWrite(led_pin[1],HIGH);

    delay(1000);
    
    digitalWrite(led_pin[0],LOW);
    digitalWrite(led_pin[1], LOW);
    
  }
}

int color_detect1() 
{

  data = -1;


  Wire.onRequest(sendData5);

  while(data == -1)
  {
    Wire.onReceive(receiveData);
  }

  return data; 
}

int color_detect2() 
{

  data = -1;


  Wire.onRequest(sendData6);

  while(data == -1)
  {
    Wire.onReceive(receiveData);
  }

  return data; 
} 
int color_detect(){
return simu_supp[curr_node];
}
void pick(int c) {
  
  color_glow(c);
  if(count == 0){
  pick_it();
  Serial.println("pick_it()");}
  else{
  pick_it_up();
  Serial.println("pick_it_up()");}
  
  count++;
  simu_supp[curr_node] = 0;
  status_supply[curr_node] = 0;
  Serial.print("count = ");
  Serial.println(count);
  Serial.println("---");
  Serial.print(" Picked block = ");
  Serial.println(c);
}
void chk_c() {

  if (col == req_bl[count])
  {
    pick(col);

  }
  else {
    //Serial.println("chk_c in else");
    status_supply[curr_node] = col;
  }
}

void got_it() {
  if ( face_side == -1){
    if (subt < 0) {
      face_side = 1;
      Serial.println("in got it with diff<0 face side -1");
      turn_full = 180;
      //velocity(93, 85);
      left_turn(state);
      decrease(core,177,3);
      //velocity(72,68);
      line_fwd(state);
      line_bck(state);
      Serial.print("difference=");
      Serial.println(subt);
      Serial.print("curr_node = ");
      Serial.println(curr_node);
      curr_node = curr_node - 1;
      subt = subt + 1;
      Serial.print("differ = ");
      Serial.println(subt);
      Serial.print("curr_node =");
      Serial.println(curr_node);
      while (subt != 0 ) {
        Serial.println("hi");
        fwd_node_2_node(state);
        //if(curr_node != 0 || curr_node != 6)
        line_bck(state);
        curr_node = curr_node - 1;
        subt = subt + 1;
        Serial.print("diff");
        Serial.println(subt);
        Serial.print("curr_node");
        Serial.println(curr_node);
        //delay(100);
      }
    }
    else if (subt > 0) {
      Serial.println("in got it with diff > 0 with face side -1");
      while (subt != 0) {
        //velocity(72,68);
        fwd_node_2_node(state);
        //if(curr_node != 0 || curr_node != 6)
        line_bck(state);
        subt--;
        curr_node++;
        Serial.print("diff");
        Serial.println(subt);
        Serial.print("curr_node");
        Serial.println(curr_node);
        delay(100);
      }
    }
  }
  if ( face_side == 1){
    if (subt > 0) {
      face_side = -1;
      Serial.println("in got it with diff<0 wiht faceside 1");
      turn_full = 180;
      //velocity(93, 85);
      left_turn(state);
      increase(core,3,177);
      velocity(65,60);
      line_fwd(state);
      line_bck(state);
      Serial.print("diff");
      Serial.println(subt);
      Serial.print("curr_node");
      Serial.println(curr_node);
      curr_node = curr_node + 1;
      subt = subt - 1;
      Serial.print("diff");
      Serial.println(subt);
      Serial.print("curr_node");
      Serial.println(curr_node);
      while (subt != 0 ) {
        fwd_node_2_node(state);
        //if(curr_node != 0 || curr_node != 6)
        line_bck(state);
        curr_node = curr_node + 1;
        subt = subt - 1;
        Serial.print("diff");
        Serial.println(subt);
        Serial.print("curr_node");
        Serial.println(curr_node);
        //delay(100);
      }
    }
    else if (subt < 0) {
      Serial.println("in got it with diff > 0  faceside 1");
      while (subt != 0) {
        //velocity(72,68);
        ;
        fwd_node_2_node(state);
        //if(curr_node != 0 || curr_node != 6)
        line_bck(state);
        subt = subt + 1;
        curr_node = curr_node -1;
        Serial.print("diff");
        Serial.println(subt);
        Serial.print("curr_node");
        Serial.println(curr_node);
        delay(100);
      }
    }
  }


}

int supply() {

 

  if (!supply_taken) {
    if (curr_node == 3) {
      turn_full = 90;
      ////velocity(90, 0);
      right_turn(state);
      face_side = 1;
      velocity(72,68);

      line_fwd(state);
      delay(500);
      line_bck(state);
      delay(500);
      curr_node = 2;
      decrease(core,90,0);

      Serial.println(curr_node);
      delay(2000);
      col = color_detect();
      Serial.println("chk_c in");
      chk_c();
      Serial.println("chk_c out");
      if(req_bl[count] == 0){
        subt = 3 - curr_node;
        got_it();
        turn_full = 90;
        if(face_side == 1){
          increase(core,3,90);
          right_turn(state);
        }
        else if (face_side == -1){
          decrease(core,177,90);
          left_turn(state);
        }
        return 0;
      }

      fwd_node_2_node(state);
      delay(500);
      line_bck(state);
      delay(500);
      //increase(core,35,80);
      curr_node = 1;
      core.write(0);
      Serial.println(curr_node);
      delay(2000);
      col = color_detect();
      chk_c();
      if(req_bl[count] == 0){
        subt = 3 - curr_node;
        got_it();
        turn_full = 90;
        if(face_side == 1){
          increase(core,3,90);
          right_turn(state);
        }
        else if (face_side == -1){
          decrease(core,177,90);
          left_turn(state);
        }
        return 0;
      }
      //velocity(72,68);
      fwd_node_2_node(state);
      delay(500);
      line_bck(state);
      delay(500);
      //decrease(core,80,35);
      curr_node = 0;
      core.write(0);
      Serial.println(curr_node);
      delay(2000);
      col = color_detect();
      chk_c();
      if(req_bl[count] == 0){
        subt = 3 - curr_node;
        got_it();
        turn_full = 90;
        if(face_side == 1){
          increase(core,3,90);
          right_turn(state);
        }
        else if (face_side == -1){
          decrease(core,177,90);
          left_turn(state);
        }
        return 0;
      }

      turn_full = 180;
      //velocity(93,85 );
      right_turn(state);
      face_side = -1;
      increase(core,0,176);
      //line_bck(state);
      //velocity(72,68);
      line_fwd(state);
      delay(500);
      line_bck(state);
      delay(500);
      curr_node = 1;
      Serial.println(curr_node);
      ////velocity(73,68);
      int diff = supply_center - curr_node;
      while (diff != 0) {
        fwd_node_2_node(state);
        delay(500);
        line_bck(state);
        delay(500);
        curr_node++;
        Serial.println(curr_node);
        diff--;

      }
      diff = 0;
      //velocity(72,68);
      fwd_node_2_node(state);
      delay(500);
      line_bck(state);
      delay(500);
      curr_node = 4;
      Serial.println(curr_node);
      delay(2000);
      col = color_detect();
      chk_c();
      if(req_bl[count] == 0){
        subt = 3 - curr_node;
        got_it();
        turn_full = 90;
        if(face_side == 1){
          increase(core,3,90);
          right_turn(state);
        }
        else if (face_side == -1){
          decrease(core,177,90);
          left_turn(state);
        }
        return 0;
      }

      ////velocity(73,68);
      fwd_node_2_node(state);
      delay(500);
      line_bck(state);
      delay(500);
      curr_node = 5;
      core.write(177);
      Serial.println(curr_node);
      delay(2000);
      col = color_detect();
      chk_c();
      if(req_bl[count] == 0){
        subt = 3 - curr_node;
        got_it();
        turn_full = 90;
        if(face_side == 1){
          increase(core,3,90);
          right_turn(state);
        }
        else if (face_side == -1){
          decrease(core,177,90);
          left_turn(state);
        }
        return 0;
      }

      //velocity(72,68);
      fwd_node_2_node(state);
      delay(500);
      line_bck(state);
      delay(500);

      curr_node = 6;
      core.write(177);
      Serial.println(curr_node);
      delay(2000);
      col = color_detect();
      chk_c();
      if(req_bl[count] == 0){
        subt = 3 - curr_node;
        got_it();
        turn_full = 90;
        if(face_side == 1){
          increase(core,3,90);
          right_turn(state);
        }
        else if (face_side == -1){
          decrease(core,177,90);
          left_turn(state);
        }
        return 0;
      }

      //      //delay(1000);
      //turn_full = 180;
      //left_turn(state);
      Serial.print("count = ");
      Serial.println(count);
      //{2, 2, 3, 1, 0, 0}; 1,2,3,0,3,1,2    1,0,3,0,3,1,0    1,0,3,0,0,1,0
      Serial.print("Status Supply = ");
      for ( int v = 0; v < 7; v++) {
        Serial.print(status_supply[v]);
        Serial.print("  ");
      }
      Serial.println("Simu-supply = ");
      for ( int v = 0; v < 7; v++) {
        Serial.print(simu_supp[v]);
        Serial.print("  ");
      }
      Serial.println("");
      while ( req_bl[count] != 0 && count < 6 ) {
        for ( int k = curr_node - 1 ; k >= 0; k--) {
          if (status_supply[k] == req_bl[count]) {
            cpos1 = k;
            break;
          }
        }
        for (int  k = curr_node + 1; k < 7 ; k++) {
          if (status_supply[k] == req_bl[count]) {
            cpos2 = k;
            break;
          }
        }
        if ( cpos1 != -1 && cpos2 != -1)
        {
          Serial.print("cpos1 = ");
          Serial.print(cpos1);
          Serial.println("");
          Serial.print("cpos2 = ");
          Serial.print(cpos2);
          Serial.println("");
          if ( abs(cpos1 - curr_node) >= abs(cpos2 - curr_node))
          { 
            subt = cpos2 - curr_node;
            Serial.print("diff");
            Serial.println(subt);
            got_it();
            pick(req_bl[count]);
          }
          else if (abs(cpos1 - curr_node) < abs(cpos2 - curr_node)) {
            subt = cpos1 - curr_node;
            Serial.print("diff");
            Serial.println(subt);
            got_it();
            pick(req_bl[count]);
          }
        }
        else if ( cpos1 == -1) {
          Serial.print("cpos2 = ");
          Serial.print(cpos2);
          Serial.println("");
          subt = cpos2 - curr_node;
          Serial.print("diff");
          Serial.println(subt);
          got_it();
          pick(req_bl[count]);

        }
        else if (cpos2 == -1) {
          Serial.print("cpos1 = ");
          Serial.print(cpos1);
          Serial.println("");
          subt = cpos1 - curr_node;
          Serial.print("diff");
          Serial.println(subt);
          got_it();
          pick(req_bl[count]);
        }

        cpos1 = -1;
        cpos2 = -1;
        subt = 0;
      }
      for ( int v = 0; v < 7; v++) {
        Serial.print(status_supply[v]);
        Serial.print("  ");
      }
      Serial.println("Simu-supply = ");
      for ( int v = 0; v < 7; v++) {
        Serial.print(simu_supp[v]);
        Serial.print("  ");
      }
      subt = 3 - curr_node;
      got_it();
      turn_full = 90;
      if(face_side == 1){
        increase(core,3,90);
        right_turn(state);
      }
      else if (face_side == -1){
        decrease(core,177,90);
        left_turn(state);
      }

    }
  }
}
 


