/*************************************
 * Line Follower Robot* 
 *  Code Written by MYBOTIC  *
 *************************************/

#define SEN_1_PIN A2
#define SEN_2_PIN A3
#define SEN_3_PIN A4
#define SEN_4_PIN A5

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

short sensor1, sensor2;
void setup()
{
  pinMode(SEN_1_PIN, INPUT);
  pinMode(SEN_2_PIN, INPUT);
  pinMode(SEN_3_PIN, INPUT);
  pinMode(SEN_4_PIN, INPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 
  Serial.begin(9600);
  analogWrite(5,70);
  analogWrite(6,70);
}

void loop()
{
  sensor1 = analogRead(A0);
  sensor2 = analogRead(A1);
  
  Serial.print( sensor1 );
  Serial.print("\t");
  Serial.println( sensor2 );
  
  if( abs(sensor1 - sensor2) > 125 )
  {
    if( sensor1 < sensor2)
    {
      digitalWrite(IN1,0);
      digitalWrite(IN2,0);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0);
    }
    else
    {
      digitalWrite(IN1,1);
      digitalWrite(IN2,0);
      digitalWrite(IN3,0);
      digitalWrite(IN4,0);
    }
  }
  else
  {
    digitalWrite(IN1,1);
    digitalWrite(IN2,0);
    digitalWrite(IN3,1);
    digitalWrite(IN4,0);
  }
}
