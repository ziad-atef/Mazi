#include "Drivers/ADC/ADC.h"
#include "Drivers/PWM/PWM.h"

#include "Drivers/Sensors/Sensors.h"
#include "Drivers/Maze/Maze.h"

#define WHITE_THRESH 500
#define WHITE_LINE(sensor_reading) sensor_reading > WHITE_THRESH

char path[100] = "";
uint16 path_length = 0; // the length of the path

int main(void)
{

  setup_motors();
  init_motors();

  while (1)
  {
    int sensors_readings[5];
    get_readings(sensors_readings);
    calibrate_readings(sensors_readings);
    follow_segment(sensors_readings);

    boolean right = FALSE;
    boolean left = FALSE;
    boolean straight = FALSE;

    check_intersection_lines(sensors_readings, &left, &straight, &right);

    // CHECK END
    if (right == TRUE && left == TRUE && straight == TRUE)
    {
      change_speed(0, 0); // REVISIT
      DelayMs(150);       // REVISIT
      get_readings(sensors_readings);

      boolean tmp_right = FALSE;
      boolean tmp_left = FALSE;
      boolean tmp_straight = FALSE;

      check_intersection_lines(sensors_readings, &tmp_left, &tmp_straight, &tmp_right);

      // End MAZE
      if (tmp_left == TRUE && tmp_right == TRUE && tmp_straight == TRUE)
        break;
    }
    // Yahia's Suggestion
    // if (left == TRUE && right == TRUE)
    // {
    // change_speed(0, 0); // REVISIT
    // DelayMs(200);       // REVISIT
    // check_intersection_lines(sensors_readings, &left, &straight, &right);
    // left = TRUE;
    // right = TRUE;
    // }
    if(right == TRUE && straight == TRUE && left == FALSE)
      if(check_falsy_straight(sensors_readings))
      {
        straight= FALSE;
      }
    uint8 direction = select_turn(left, straight, right);
    // Move MOTORS
    turn(direction);
    // Store path
    path[path_length++] = direction;
    path_length++;

    simplify_path(path, &path_length);
  }
  // STORE PATH IN FLASH MEMORY
  //int numofwords = (strlen(path)/4)+((strlen(path)%4)!=0);
  // Flash_Write_Data(0x080FF800 , (uint32_t*)path, numofwords);
  // Flash_Read_Data(0x080FF800 , Rx_Data, numofwords); // read in the next run(change mode)
}

