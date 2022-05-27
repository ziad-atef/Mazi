#ifndef _Maze_H_
#define _Maze_H_
#include "../../Includes/Platform_Types.h"
#include "../Motors/Motors.h"

void follow_segment();

uint8 select_turn(boolean left, boolean straight, boolean right);

void turn(uint8 direction);

void simplify_path(char *path);

#endif