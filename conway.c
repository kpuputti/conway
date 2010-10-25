#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "conway.h"

Conway *conway_create(unsigned int height,
                      unsigned int width)
{
    Conway *conway = malloc(sizeof(Conway));
    assert(conway);
    conway->height = height;
    conway->width = width;
    conway->buffer = malloc(height * sizeof(bool *));
    assert(conway->buffer);
    for (unsigned int i = 0; i < height; ++i) {
        conway->buffer[i] = malloc(width * sizeof(bool));
        assert(conway->buffer[i]);
    }
    conway_clear(conway);
    return conway;
}

void conway_clear(Conway *conway)
{
    for (unsigned int i = 0; i < conway->height; ++i) {
        for (unsigned int j = 0; j < conway->width; ++j) {
            conway->buffer[i][j] = false;
        }
    }
}

void conway_destroy(Conway *conway)
{
    for (unsigned int i = 0; i < conway->height; ++i) {
        free(conway->buffer[i]);
    }
    free(conway->buffer);
    free(conway);
}

void conway_add_point(Conway *conway,
                      unsigned int x,
                      unsigned int y)
{
    assert(x < conway->width && y < conway->height);
    conway->buffer[y][x] = true;
}

bool conway_update(Conway *conway)
{
    for (unsigned int i = 0; i < conway->height; ++i) {
        for (unsigned int j = 0; j < conway->width; ++j) {
            // handle point
        }
    }
    return false;
}

void conway_print(Conway *conway)
{
    for (unsigned int i = 0; i < conway->height; ++i) {
        for (unsigned int j = 0; j < conway->width; ++j) {
            char *s = conway->buffer[i][j] ? "* " : "  ";
            printf("%s", s);
        }
        printf("\n");
    }
}
