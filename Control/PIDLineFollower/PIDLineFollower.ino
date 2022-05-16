#include "Motors.h"
#include "Sensors.h"

// PID parameters
const float kp = 0.06;
const float ki = 0;
const float kd = 0.5;
unsigned int last_proportional = 0;
long integral = 0;

void setup()
{

  Serial.begin(9600);

  setup_motors();
  init_motors();
}

void loop()
{
  int sensors_readings[_numSensors];

  get_readings(sensors_readings);
  calibrate_readings(sensors_readings);

  // The returned position from 0 to 2000
  unsigned int position = read_line(sensors_readings);

  // The "proportional" term should be 0 when we are on the line.
  const int diff = 1000;
  int proportional = (int)position - diff;

  // To ignore small errors
  if (abs(proportional) <= 50)
    proportional = 0;

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
  int power_difference = proportional * kp + integral * ki + derivative * kd;

  int maximum = MAX_SPEED;

  // To slow down for turns
  if (abs(proportional) > 500)
  {
    int d = map(abs(proportional), 500, 1000, 20, 50);
    maximum -= d;
  }

  // Compute the actual motor settings.  We never set either motor
  // to a negative value.
  if (power_difference > maximum)
    power_difference = maximum;
  if (power_difference < -maximum)
    power_difference = -maximum;

  if (power_difference < 0)
    change_speed(maximum, maximum + power_difference);
  else
    change_speed(maximum - power_difference, maximum);

  log_readings(sensors_readings, proportional);
}