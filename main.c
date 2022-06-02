/*
 * Main Code for stm32 that's equivalent to .ino in arduino
 * An implementation to Left Hand Rule for solving a maze
 * Tha main steps are:
 *   - Initialize and configure left/right motors pins
 *   - Read sensors analog inputs
 *   - Drive until the sensors detect an intersection
 *   - Check the intersection type [Right, Left, T-intersection, Plus-intersection]
 *   - Apply left-hand rule to take the decision, which turn you should take.
 *
 * Left-hand Rule:
 *   - Check if there's a left turn, take it.
 *   - Else, check if there's a straight line, follow it.
 *   - Else, check if there's a right turn, take it
 *   - Else, make a U-turn and drive straight till the next intersection.
 * Notes:
 *   - Because the sensors are aligned on the same line, always the straight flag
 *    will be true, so we need to drive a little bit forward to check if
 *    the straight line continues or not.
 *    In case of a Left-hand rule, we only need to apply this if a right turn exists
 */

// Includes
#include "Drivers/ADC/ADC.h"
#include "Drivers/PWM/PWM.h"
#include "Drivers/Sensors/Sensors.h"
#include "Drivers/Maze/Maze.h"

// Defines
#define WHITE_THRESH 500
#define WHITE_LINE(sensor_reading) sensor_reading > WHITE_THRESH

// Variables
char path[100] = "";
uint16 path_length = 0; // the length of the path

int main(void)
{
  // start by configuring motor pins
  setup_motors();
  // apply initial speed to motors
  init_motors();
  // main loop logic
  while (1)
  {
    // variable to store sensor readings
    int sensors_readings[5];
    // read sensors analog input to the board and store them
    get_readings(sensors_readings);
    // calibrate_readings(sensors_readings);
    // drive until the sensors detect an intersection
    follow_segment(sensors_readings);

    // Flags to indicate what turn are available
    // used to determine the intersection type and the decision
    //  that should be taken
    boolean right = FALSE;
    boolean left = FALSE;
    boolean straight = FALSE;

    // Set flags based on sensor readings
    check_intersection_lines(sensors_readings, &left, &straight, &right);

    // If all sensors read Black, Check the END of the maze
    if (right == TRUE && left == TRUE && straight == TRUE)
    {
      // Drive a little bit forward
      forward();
      DelayMs(150); // REVISIT
      get_readings(sensors_readings);

      // flags to indicate turns type
      boolean tmp_right = FALSE;
      boolean tmp_left = FALSE;
      boolean tmp_straight = FALSE;

      // set flags based on sensor readings
      check_intersection_lines(sensors_readings, &tmp_left, &tmp_straight, &tmp_right);

      // If all sensors still read Black, this is the END point
      if (tmp_left == TRUE && tmp_right == TRUE && tmp_straight == TRUE)
        break;
    }
    // Because the sensors are aligned on the same line, always the straight flag
    // will be true, so we need to drive a little bit forward to check if
    // the straight line continues or not.
    // In case of a Left-hand rule, we only need to apply this if a right turn exists
    if (right == TRUE && straight == TRUE && left == FALSE)
      if (check_falsy_straight(sensors_readings))
        straight = FALSE;

    // The core of Left-hand Rule
    uint8 direction = select_turn(left, straight, right);
    // Move MOTORS to turn in the decided direction
    turn(direction);
    // Store path
    path[path_length++] = direction;
    path_length++;
    // replace redundant decisions with simplified equivalent ones.
    simplify_path(path, &path_length);
  }
  // STORE PATH IN FLASH MEMORY
  // int numofwords = (strlen(path)/4)+((strlen(path)%4)!=0);
  // Flash_Write_Data(0x080FF800 , (uint32_t*)path, numofwords);
  // Flash_Read_Data(0x080FF800 , Rx_Data, numofwords); // read in the next run(change mode)
}
