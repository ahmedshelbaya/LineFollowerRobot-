/*
 *  This Code Written By A.Shelbaya Inc for
 *  line Follower Robot Nov/2018
 */
// Arduino Pin Connect to Motor Driver
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
// Memory location to store sensor Reading
int L; // Left Sensor
int C; // Middel Sensor
int R; // Right Sensor
void setup()
{
  // Define Motor Drive Pin as Output 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // Define Sensor Pin As Input 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}
void loop()
{
  R = digitalRead(A0); // Read and Store Right Sensor Reading  
  C = digitalRead(A1); // Read and Store Middel Sensor Reading 
  L = digitalRead(A2); // Read and Store Left Sensor Reading 
  // Serial for Debugging 
  Serial.print(R);
  Serial.println("R");
  Serial.print(L);
  Serial.println("L");
  Serial.print(C);
  Serial.println("C");
// Stop Condation all sensor see black or white 
  if ((L == LOW && C == LOW && R == LOW) || (L == HIGH && C == HIGH && R == HIGH))
  {
    STOP();
    Serial.println("STOP");
  }
  //Move Left Condation Left sensor see black line 
  else if ((L == LOW && C == HIGH && R == HIGH) || ( L == LOW && C == LOW && R == HIGH))
  {
    left();
    Serial.println("left");
  }
  //Move Right Condation right sensor see black line 
  else if ((L == HIGH && C == HIGH && R == LOW ) || ( L == LOW && C == LOW && R == LOW))
  {
    right();
    Serial.println("Right");
  }
  //Move Middel Condation Middel sensor see black line 
  else if (L == HIGH && C == LOW && R == HIGH)
  {
    forward();
    Serial.println("forward");
  }
  delay(500);
}

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void backword()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void STOP()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

