#ifndef _CONWAY_H_
#define _CONWAY_H_

#include <stdbool.h>

typedef struct Conway_s {
    unsigned int width;
    unsigned int height;
    bool **buffer;
} Conway;

Conway *conway_create();
void conway_destroy(Conway *);
bool conway_update(Conway *);
void conway_print(Conway *);

#endif /* _CONWAY_H_ */
