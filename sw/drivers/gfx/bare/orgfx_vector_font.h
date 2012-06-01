#ifndef ORGFX_VECTOR_FONT_H
#define ORGFX_VECTOR_FONT_H

#include "orgfx.h"
#include <wchar.h>

typedef struct Bezier_write
{
    orgfx_point2 start;
    orgfx_point2 control;
    orgfx_point2 end;
    int fillInside;
} Bezier_write;

typedef struct Triangle_write
{
    orgfx_point2 p0;
    orgfx_point2 p1;
    orgfx_point2 p2;
} Triangle_write;

typedef struct Glyph{
    int advance_x;
    int index;
    int bezier_n_writes;
    Bezier_write* bezier;
    int triangle_n_writes;
    Triangle_write* triangle;
} Glyph;

typedef struct orgfx_vector_font{
    int index_list_size;
    Glyph** index_list;
    int size;
    Glyph *glyph;
} orgfx_vector_font;

orgfx_vector_font orgfx_make_vector_font(Glyph *glyphlist, int size, Glyph **glyphindexlist, int glyphindexlistsize);
int  orgfx_init_vector_font(orgfx_vector_font font);


void orgfx_vf_write(orgfx_vector_font* font, const wchar_t *text, int xoffset, int yoffset, int color);
void orgfx_vf_write_char(orgfx_vector_font* font, wchar_t text, int xoffset, int yoffset, float scale);

#endif
