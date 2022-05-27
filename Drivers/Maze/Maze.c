#include "Maze.h"

void follow_segment()
{
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

    if (path_length < 3 || path[path_length - 2] != 'B')
        return;
    // SBL => R
    if (path[path_length - 3] == 'S' && path[path_length - 1] == 'L')
        path[path_length - 3] = 'R';

    // LBL => S
    if (path[path_length - 3] == 'L' && path[path_length - 1] == 'L')
        path[path_length - 3] = 'S';

    // SBS => B
    if (path[path_length - 3] == 'S' && path[path_length - 1] == 'S')
        path[path_length - 3] = 'B';

    // RBL => B
    if (path[path_length - 3] == 'R' && path[path_length - 1] == 'L')
        path[path_length - 3] = 'B';

    // LBR => B
    if (path[path_length - 3] == 'L' && path[path_length - 1] == 'R')
        path[path_length - 3] = 'B';

    // LBS => R
    if (path[path_length - 3] == 'L' && path[path_length - 1] == 'S')
        path[path_length - 3] = 'R';

    *path_length -= 2;
}
void turn(uint8 direction)
{
    int speed1 = 0, speed2 = 0;
    switch (direction)
    {
    case 'L':
        change_speed(speed1, speed2);
        break;
    case 'B':
        change_speed(speed1, speed2);
        break;
    case 'R':
        change_speed(speed1, speed2);
        break;
    default:
        break;
    }
}