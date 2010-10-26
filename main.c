#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "conway.h"

// Initialize the buffer (pseudo)randomly.
void randomize_buffer(Conway *conway)
{
    conway_clear(conway);
    for (unsigned int i = 0; i < conway->height; ++i) {
        for (unsigned int j = 0; j < conway->width; ++j) {
            if (random() % 2 == 0) {
                conway->buffer[i][j] = true;
            }
        }
    }
}

void run(unsigned int count)
{
    Conway *conway = conway_create(40, 80);
    randomize_buffer(conway);
    bool has_changed = true;
    unsigned int i = 0;
    while (has_changed && count--) {
        printf("-- Conway iteration %3d --\n", i++);
        has_changed = conway_update(conway);
        conway_print(conway);
        usleep(500000);
    }
    conway_destroy(conway);
}

int main(void)
{
    unsigned int count = 5000;
    run(count);
    puts("Done.");
    return 0;
}
