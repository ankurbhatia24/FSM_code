

/*###############################################################################################
 #################################################################################################
 ------------------      function for speed calling          ---------------------*/

//forward function both motor on

void fwd()
{
  analogWrite(enleft,  speed_left);   //pwm value for the left motor 
  digitalWrite(lefta,  LOW );    //making left pin of motor low
  digitalWrite(leftb,  HIGH);    //making left pin of motor high
  digitalWrite(righta, LOW );    //making right pin of motor low
  digitalWrite(rightb, HIGH);    //making right pin of motor high
  analogWrite(enright, speed_right);   //pwm value for the left motor 
}

// left motor on
void sf_lft()
{
  analogWrite(enleft,  65);    //pwm value for the left motor 
  digitalWrite(lefta,  LOW);  //making left pin of motor low
  digitalWrite(leftb,  HIGH); //making left pin of motor high  
  digitalWrite(righta, LOW);  //making right pin of motor low
  digitalWrite(rightb, HIGH); //making right pin of motor high
  analogWrite(enright, 0);    //pwm value for the left motor 0
}

//right motor on 
void sf_rgt()
{
  analogWrite(enleft,  0);    //pwm value for the left motor 
  digitalWrite(lefta,  LOW);  //making left pin of motor low
  digitalWrite(leftb,  HIGH); //making left pin of motor high
  digitalWrite(righta, LOW);  //making right pin of motor low
  digitalWrite(rightb, HIGH); //making right pin of motor high
  analogWrite(enright, 60);   //pwm value for the left motor 0
}

// left motor o
void hr_lft()
{
  analogWrite(enleft,  60);   //pwm value for the left motor 95
  digitalWrite(lefta,  LOW);  //making left pin of motor low
  digitalWrite(leftb,  HIGH); //making left pin of motor high  
  digitalWrite(righta, HIGH); //making right pin of motor high
  digitalWrite(rightb, LOW);  //making right pin of motor low
  analogWrite(enright, 55);   //pwm value for the left motor 87
}
//right motor on 
void hr_rgt()
{
  analogWrite(enleft,  60);    //pwm value for the left motor 85
  digitalWrite(lefta,  HIGH);  //making left pin of motor high
  digitalWrite(leftb,  LOW);   //making left pin of motor low
  digitalWrite(righta, LOW);   //making right pin of motor low
  digitalWrite(rightb, HIGH);  //making right pin of motor high
  analogWrite(enright, 55);    //pwm value for the left motor 77

}
//backward movement
void bck()
{
  analogWrite(enleft,  55 );    //pwm value for the left motor  56 
  digitalWrite(lefta,  HIGH);   //making left pin of motor high
  digitalWrite(leftb,  LOW);    //making left pin of motor low
  digitalWrite(righta, HIGH);   //making right pin of motor high
  digitalWrite(rightb, LOW);    //making right pin of motor low
  analogWrite(enright, 49);     //pwm value for the left motor 51
}
//taking left turn in backward
void bck_lft()
{
  analogWrite(enleft,  50);     //pwm value for the left motor 
  digitalWrite(lefta,  HIGH);   //making left pin of motor high
  digitalWrite(leftb,  LOW);    //making left pin of motor low  
  digitalWrite(righta, LOW);   //making right pin of motor high
  digitalWrite(rightb, HIGH);    //making right pin of motor low
  analogWrite(enright, 0);      //pwm value for the left motor 
}
////taking right turn in backward 
void bck_rgt()
{
  analogWrite(enleft,  0);     //pwm value for the left motor 
  digitalWrite(lefta,  LOW);  //making left pin of motor high
  digitalWrite(leftb,  HIGH);   //making left pin of motor low
  digitalWrite(righta, HIGH);  //making right pin of motor high
  digitalWrite(rightb, LOW);   //making right pin of motor low
  analogWrite(enright, 45);   //pwm value for the left motor 
}
//both motor off position
void stp()
{
  digitalWrite(righta, LOW);  //making left pin of motor low
  digitalWrite(rightb, LOW);  //making left pin of motor low
  digitalWrite(lefta , LOW);  //making right pin of motor low
  digitalWrite(leftb , LOW);  //making right pin of motor low
}  
/*-------------------- speed calling function of the end here --------------------------------------*/




