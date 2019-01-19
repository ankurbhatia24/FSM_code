int consecutive_sensors(int, int, int, int, int);
float cal_a(int x1, int x2, int x3, int y1, int y2, int y3);
float cal_b(int x1, int x2, int x3, int y1, int y2, int y3);
float cal_c(int x1, int x2, int x3, int y1, int y2, int y3);
float det(int n, float mat[3][3]);
int pin1 = A0, pin2 = A1, pin3 = A2;
int val_leftmost, val_left, val_center, val_right, val_rightmost, val, x1, x2, x3 ,v1 ,v2 ,v3 ,Tr;
float Turn, d = 0;
float a, b, c, y1, y2, y3, error, powerA, powerB;
#include<math.h>




//PID
int Kp = 10 ;
int Ki = 0 ;
int Kd = 0 ;
int offset = 45 ;
int Tp = 50 ;
float integral = 0 ;
float lastError = 0 ;
float derivative = 0 ;
float lastError2 = 0 ;

void setup() {

  Serial.begin(9600);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);

}

void loop() {
  v1 = analogRead(pin1);
  v2 = analogRead(pin2);
  v3= analogRead(pin3);
  float dt[3][3];
  val_left   = map(v1, 27 , 600, 0, 50);
  val_center = map(v2, 290, 600, 0, 50);
  val_right  = map(v3, 95, 600, 0, 50);
  //Finding Three consecutive sensors

  x1 = 1; x2 = 2; x3 = 3;
  y1 = val_left;
  y2 = val_center;
  y3 = val_right;

  dt[0][0] = x1 * x1; dt[0][1] = x1; dt[0][2] = 1;
  dt[1][0] = x2 * x2; dt[1][1] = x2; dt[1][2] = 1;
  dt[2][0] = x3 * x3; dt[2][1] = x3; dt[2][2] = 1;

  a = cal_a(x1, x2, x3, y1, y2, y3, dt);
  b = cal_b(x1, x2, x3, y1, y2, y3, dt);
  c = cal_c(x1, x2, x3, y1, y2, y3, dt);

  //error = -(b / (2 * a));
  error = -(y2 - y1 - (2*a*x1) - a) + 42 ;
  integral = (integral + error) / 2;
  derivative = error - 2 * lastError + lastError2;
  Turn = Kp * error + Ki * integral + Kd * derivative;
  //Tr = map(Turn, 
  powerA = Tp + Turn ;
  powerB = Tp - Turn ;
  //MOTOR A direction=forward power=PowerA
  //MOTOR B direction=forward power=PowerB
  lastError2 = lastError;
  lastError = error;
  Serial.print("error= ");
  Serial.print(error);
  Serial.print("\t");
  Serial.print("turn= ");
  Serial.print(Turn);
  Serial.print("\t");  
  Serial.print("left= ");
  Serial.print(val_left);
  Serial.print("\t");
  Serial.print("  center= ");
  Serial.print(val_center); 
  Serial.print("\t ");
  Serial.print("right= ");
  Serial.print(val_right);  
  Serial.print(" === left=  ");
  Serial.print(v1);
  Serial.print("\t");
  Serial.print("  center= ");
  Serial.print(v2); 
  Serial.print("\t");
  Serial.print("right= ");
  Serial.print(v3);  
  Serial.print("\t \n");

  delay(400);


}


float cal_a(int x1, int x2, int x3, int y1, int y2, int y3, float determinant[3][3])
{
  float a_upper, dt;
  float mat[3][3];
  mat[0][0] = y1; mat[0][1] = x1; mat[0][2] = 1;
  mat[1][0] = y2; mat[1][1] = x2; mat[1][2] = 1;
  mat[2][0] = y3; mat[2][1] = x3; mat[2][2] = 1;
  a_upper = det(3, mat);
  dt = det(3, determinant);
  return (a_upper / dt);

}

float cal_b(int x1, int x2, int x3, int y1, int y2, int y3, float determinant[3][3])
{
  float b_upper, dt;
  float mat[3][3];
  mat[0][0] = x1 * x1; mat[0][1] = y1; mat[0][2] = 1;
  mat[1][0] = x2 * x2; mat[1][1] = y2; mat[1][2] = 1;
  mat[2][0] = x3 * x3; mat[2][1] = y3; mat[2][2] = 1;
  b_upper = det(3, mat);
  dt = det(3, determinant);
  return (b_upper / dt);
}

float cal_c(int x1, int x2, int x3, int y1, int y2, int y3, float determinant[3][3])
{
  float c_upper, dt;
  float mat[3][3];
  mat[0][0] = x1 * x1; mat[0][1] = x1; mat[0][2] = y1;
  mat[1][0] = x2 * x2; mat[1][1] = x2; mat[1][2] = y2;
  mat[2][0] = x3 * x3; mat[2][1] = x3; mat[2][2] = y3;
  c_upper = det(3, mat);
  dt = det(3, determinant);
  return (c_upper / dt);
}


float det(int n, float mat[3][3])
{
  int c, subi, i, j, subj;
  float submat[3][3];
  if (n == 2)
  {
    return ( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
  }
  else
  {
    for (c = 0; c < n; c++)
    {
      subi = 0;
      for (i = 1; i < n; i++)
      {
        subj = 0;
        for (j = 0; j < n; j++)
        {
          if (j == c)
          {
            continue;
          }
          submat[subi][subj] = mat[i][j];
          subj++;
        }
        subi++;
      }
      d = d + (pow(-1 , c) * mat[0][c] * det(n - 1 , submat));
    }
  }
  return d;
}
