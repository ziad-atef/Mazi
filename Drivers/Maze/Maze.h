#ifndef _Maze_H_
#define _Maze_H_
#include "../../Includes/Platform_Types.h"
#include "../Motors/Motors.h"

#define BLACK_THRESH 200


void follow_segment(int *sensor_readings);

uint8 select_turn(boolean left, boolean straight, boolean right);

void turn(uint8 direction);

void simplify_path(char *path, uint16* path_length);

boolean end_segment(int *sensor_readings);

void check_intersection_lines(int* sensor_readings, boolean* left, boolean* straight, boolean* right);

#endif