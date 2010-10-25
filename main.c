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
            int rand = random() % 100;
            if (rand < 50) {
                conway->buffer[i][j] = true;
            }
        }
    }
}

void run()
{
    Conway *conway = conway_create(20, 40);
    randomize_buffer(conway);
    bool has_changed = true;
    unsigned int i = 0;
    while (has_changed) {
        printf("-- Conway iteration %3d --\n", i++);
        has_changed = conway_update(conway);
        conway_print(conway);
        usleep(500000);
    }
    conway_destroy(conway);
}

int main(void)
{
    run();
    puts("Done.");
    return 0;
}
