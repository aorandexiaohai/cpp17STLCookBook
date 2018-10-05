#include <stdio.h>

#define CALL_FUNCTION(f) \
    printf("call %s\n", #f);

int main()
{
    while (true)
    {
        switch (char c(getchar()); c)
        {
        case 'a':
            CALL_FUNCTION(move_left());
            break;
        case 's':
            CALL_FUNCTION(move_back());
            break;
        case 'w':
            CALL_FUNCTION(move_fwd());
            break;
        case 'd':
            CALL_FUNCTION(move_right());
            break;
        case 'q':
            CALL_FUNCTION(quit_game());
            break;
        default:
            break;
        }
    }
}