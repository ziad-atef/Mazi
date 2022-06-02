 /******************************************************************************
 *
 * Module: Maze
 *
 * File Name: Maze.h
 *
 * Description: Header file for Maze.
 *
 ******************************************************************************/


#ifndef _Maze_H_
#define _Maze_H_


/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "../../Includes/Platform_Types.h"
#include "../Motors/Motors.h"
#include "../../Includes/systick_time.h"


/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define BLACK_THRESH 500


/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/


/*
 *   Move the car to follow the current detect segment
 *
 *  This function drives the car forward with the help of the three sensors in the
 *  middle to center the car on the line.
 *  it breaks when an intersection is detected or the car reaches a dead-end
 *   
 *  @param sensor_readings: An array that stores sensors readings to continuously update
 *  and use to check intersections and dead-ends.
 */
void follow_segment(int *sensor_readings);

/*
 *   Select which turn the car should take at the current intersection
 *
 *  This function implements the core of the Left-hand rule, it decides which turn
 *  the car should take at a given intersection based on following rules:
 *      - if a left turn is detected, turn left 
 *      - else if a straight line is detected, drive straight
 *      - else if a right turn is detected, turn right.
 *      - else, it's a dead-end make a U-turn and drive forward.
 */
uint8 select_turn(boolean left, boolean straight, boolean right);

/*
 */
void turn(uint8 direction);

/*
 */
void simplify_path(char *path, uint16* path_length);

/*
 */
boolean end_segment(int *sensor_readings);

/*
 */
void check_intersection_lines(int* sensor_readings, boolean* left, boolean* straight, boolean* right);

/*
 */
boolean check_falsy_straight(int* sensor_readings);

#endif