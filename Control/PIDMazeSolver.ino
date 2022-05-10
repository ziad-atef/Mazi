/*************************************
 * Line Follower Robot* 
 *  Code Written by MYBOTIC  *
 *************************************/

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define max_speed 80

int sensor1, sensor2, sensor3;

unsigned int last_proportional = 0;
long integral = 0;

void setup()
{
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  
  Serial.begin(9600);

  

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT); 

  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(5,max_speed);
  analogWrite(6,max_speed);
}

unsigned readLine(unsigned int *sensor_values)
{
  unsigned char i, on_line = 0;
  unsigned long avg; // this is for the weighted total, which is long
                     // before division
  unsigned int sum; // this is for the denominator which is <= 64000
  static int last_value=0; // assume initially that the line is left.
  const int _numSensors = 3;

  //readCalibrated(sensor_values, readMode);

  avg = 0;
  sum = 0;

  for(i=0;i<_numSensors;i++) {
    int value = sensor_values[i];

    // keep track of whether we see the line at all
    if(value > 200) {
      on_line = 1;
    }

    // only average in values that are above a noise threshold
    if(value > 50) {
      avg += (long)(value) * (i * 1000);
      sum += value;
    }
  }

  if(!on_line)
  {
    // If it last read to the left of center, return 0.
    if(last_value < (_numSensors-1)*1000/2)
      return 0;

    // If it last read to the right of center, return the max.
    else
      return (_numSensors-1)*1000;

  }

  last_value = avg/sum;

  return last_value;
}


void loop()
{
  sensor1 = 850 - analogRead(A0);
  sensor2 = 850 - analogRead(A1);
  sensor3 = 850 - analogRead(A2);
  
  int  arr[] = {sensor1, sensor2, sensor3};
  unsigned int position = readLine(arr);

  // The "proportional" term should be 0 when we are on the line.
  const int diff = 1000;
  int proportional = (int)position - diff;

  // Compute the derivative (change) and integral (sum) of the
  // position.
  int derivative = proportional - last_proportional;
  integral += proportional;

  // Remember the last position.
  last_proportional = proportional;

  // Compute the difference between the two motor power settings,
  // m1 - m2.  If this is a positive number the robot will turn
  // to the right.  If it is a negative number, the robot will
  // turn to the left, and the magnitude of the number determines
  // the sharpness of the turn.  You can adjust the constants by which
  // the proportional, integral, and derivative terms are multiplied to
  // improve performance.
  int power_difference = proportional/20 + integral/10000 + derivative*(3 / 2);

  // Compute the actual motor settings.  We never set either motor
  // to a negative value.
  const int maximum = max_speed;
  if (power_difference > maximum)
    power_difference = maximum;
  if (power_difference < -maximum)
    power_difference = -maximum;

  Serial.print("sensors: ");
  Serial.print(sensor1);
  Serial.print("  ");
  Serial.print(sensor2);
  Serial.print("  ");
  Serial.print(sensor3);
  Serial.print("  position: ");
  Serial.println(proportional);
  if (power_difference < 0)
  {
    analogWrite(5,maximum + power_difference);
  analogWrite(6,maximum);
   /*Serial.print("m1: ");
  Serial.print(maximum + power_difference);
   Serial.print(" m2:  ");
  Serial.println(maximum);*/
  }
  else
  {
    analogWrite(5,maximum);
  analogWrite(6,maximum - power_difference);
  /*Serial.print("m1: ");
  Serial.print(maximum);
   Serial.print(" m2:  ");
  Serial.println(maximum - power_difference);*/
  }
}
