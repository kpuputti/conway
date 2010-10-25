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
    bool has_changed = false;
    bool tmpbuffer[conway->height][conway->width];

    unsigned int width = conway->width;
    unsigned int height = conway->height;

    for (unsigned int i = 0; i < conway->height; ++i) {
        for (unsigned int j = 0; j < conway->width; ++j) {

            bool is_alive = conway->buffer[i][j];
            tmpbuffer[i][j] = is_alive;

            // Make the buffer continuous from the edges.
            unsigned int prevrow = (i + height - 1) % height;
            unsigned int nextrow = (i + height + 1) % height;
            unsigned int prevcol = (j + width - 1) % width;
            unsigned int nextcol = (j + width + 1) % width;

            int up        = (int)conway->buffer[prevrow][j];
            int down      = (int)conway->buffer[nextrow][j];
            int left      = (int)conway->buffer[i][prevcol];
            int right     = (int)conway->buffer[i][nextcol];
            int upleft    = (int)conway->buffer[prevrow][prevcol];
            int upright   = (int)conway->buffer[prevrow][nextcol];
            int downleft  = (int)conway->buffer[nextrow][prevcol];
            int downright = (int)conway->buffer[nextrow][nextcol];

            int neighbours = up + down + left + right +
                upleft + upright + downleft + downright;

            if (is_alive && neighbours < 2) {
                // Die by under-population.
                tmpbuffer[i][j] = false;
                has_changed = true;
            } else if (is_alive && neighbours > 3) {
                // Die by overcrowding.
                tmpbuffer[i][j] = false;
                has_changed = true;
            } else if (!is_alive && neighbours == 3) {
                // Become alive by reproduction.
                tmpbuffer[i][j] = true;
                has_changed = true;
            }

        }
    }
    // Copy the new iteration to the Conway's buffer.
    for (unsigned int i = 0; i < conway->height; ++i) {
        for (unsigned int j = 0; j < conway->width; ++j) {
            conway->buffer[i][j] = tmpbuffer[i][j];
        }
    }
    return has_changed;
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
