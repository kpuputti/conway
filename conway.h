#ifndef _CONWAY_H_
#define _CONWAY_H_

#include <stdbool.h>

typedef struct Conway_s {
    unsigned int width;
    unsigned int height;
    unsigned int delay;
    bool **buffer;
} Conway;

// Create a new Conway with the given dimensions.
Conway *conway_create(unsigned int height,
                      unsigned int width);

// Free all memory allocated for the given Conway.
void conway_destroy(Conway *conway);

// Clear the buffer of the given Conway.
void conway_clear(Conway *conway);

// Add a point with the given coordinates to the buffer of the given
// Conway.
void conway_add_point(Conway *conway,
                      unsigned int x,
                      unsigned int y);

// Update the buffer. Return true/false depending if anything was
// changed.
bool conway_update(Conway *conway);

// Print out the Conway to stdout.
void conway_print(Conway *conway);

#endif /* _CONWAY_H_ */
