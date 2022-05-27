#ifndef MAZE_SRC_PWM_C_
#define MAZE_SRC_PWM_C_

#include "Maze.h"

void follow_segment(int *sensor_readings)
{
    while (1)
    {
        /* Implement ME */
        if (sensor_readings[1] <= BLACK_THRESH && sensor_readings[3] > BLACK_THRESH)
            turn_left();
        if (sensor_readings[1] > BLACK_THRESH && sensor_readings[3] <= BLACK_THRESH)
            turn_right();
        if (sensor_readings[1] > BLACK_THRESH && sensor_readings[3] > BLACK_THRESH)
            forward();
        if (end_segment(sensor_readings) == TRUE)
            return;
    }
}
boolean end_segment(int *sensor_readings)
{
    /* Implement ME */
    if (sensor_readings[0] <= BLACK_THRESH || sensor_readings[4] <= BLACK_THRESH)
        return TRUE;
    forward();
    DelayMs(100); // REVISIT
    get_readings(sensor_readings);
    if (sensor_readings[0] > BLACK_THRESH && sensor_readings[1] > BLACK_THRESH &&
        sensor_readings[2] > BLACK_THRESH && sensor_readings[3] > BLACK_THRESH &&
        sensor_readings[4] > BLACK_THRESH)
        return TRUE;
    return FALSE;
}

void check_intersection_lines(int *sensor_readings, boolean *left, boolean *straight, boolean *right)
{
    if (sensor_readings[0] <= BLACK_THRESH && sensor_readings[4] > BLACK_THRESH)
        *left = TRUE;

    if (sensor_readings[0] > BLACK_THRESH && sensor_readings[4] <= BLACK_THRESH)
        *right = TRUE;

    if (sensor_readings[2] <= BLACK_THRESH)
        *straight = TRUE;
}
boolean check_falsy_straight(int* sensor_readings){
    forward();
    DelayMs(100);
    stop();
    get_readings(sensor_readings);

    if(sensor_readings[2] <= BLACK_THRESH)
        return FALSE;
    return TRUE;
}
uint8 select_turn(boolean left, boolean straight, boolean right)
{
    if (left == TRUE)
        return 'L';
    if (straight == TRUE)
        return 'S';
    if (right == TRUE)
        return 'R';
    return 'B';
}
void simplify_path(char *path, uint16 *path_length)
{

    if (*path_length < 3 || path[*path_length - 2] != 'B')
        return;
    // SBL => R
    if (path[*path_length - 3] == 'S' && path[*path_length - 1] == 'L')
        path[*path_length - 3] = 'R';

    // LBL => S
    if (path[*path_length - 3] == 'L' && path[*path_length - 1] == 'L')
        path[*path_length - 3] = 'S';

    // SBS => B
    if (path[*path_length - 3] == 'S' && path[*path_length - 1] == 'S')
        path[*path_length - 3] = 'B';

    // RBL => B
    if (path[*path_length - 3] == 'R' && path[*path_length - 1] == 'L')
        path[*path_length - 3] = 'B';

    // LBR => B
    if (path[*path_length - 3] == 'L' && path[*path_length - 1] == 'R')
        path[*path_length - 3] = 'B';

    // LBS => R
    if (path[*path_length - 3] == 'L' && path[*path_length - 1] == 'S')
        path[*path_length - 3] = 'R';

    *path_length -= 2;
}
void turn(uint8 direction)
{
    switch (direction)
    {
    case 'L':
        turn_left();
        break;
    case 'B':
        backward();
        break;
    case 'R':
        turn_right();
        break;
    default:
        break;
    }
}
#endif
