#include <sys/time.h>
struct timeval start = {};
struct timeval end = {};
make_treasure(tx, ty);
display_rule();
gettimeofday(&start, NULL);
system("clear");
game_control(tx, ty);
gettimeofday(&end, NULL);
pst = end.tv_sec + end.tv_usec / 1000000.0 - start.tv_sec - start.tv_usec / 1000000.0;