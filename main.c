#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "conway.h"

void randomize_buffer(Conway *conway)
{
    conway_clear(conway);
    for (unsigned int i = 0; i < conway->height; ++i) {
        for (unsigned int j = 0; j < conway->width; ++j) {
            int rand = random() % 100;
            if (rand < 50) {
                conway->buffer[i][j] = true;
            }
        }
    }
}

void run(unsigned int count)
{
    Conway *conway = conway_create(20, 40);
    while (count--) {
        puts("-- Conway --");
        //conway_update(conway);
        randomize_buffer(conway);
        conway_print(conway);
        usleep(500000);
    }
    conway_destroy(conway);
}

int main(void)
{
    unsigned int count = 10;
    run(count);
    puts("Done.");
    return 0;
}
