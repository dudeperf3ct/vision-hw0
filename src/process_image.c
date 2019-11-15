#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // TODO Fill this in
    if (x >= 0 && x < im.w && y >= 0 && y < im.h && c >= 0 && c < im.c)
    {
        return im.data[x + (y * im.w) + (c * im.w * im.h)];
    }
    else{
        clamp_image(im);
        return im.data[x + (y * im.w) + (c * im.w * im.h)];
    }
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // TODO Fill this in
    if (x >= 0 && x < im.w && y >= 0 && y < im.h && c >= 0 && c < im.c)
    {
        im.data[x + (y * im.w) + (c * im.w * im.h)] = v;
    }
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    memcpy(copy.data, im.data, sizeof(im));
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    float c0=0., c1=0., c2=0.;
    for (int i=0; i<im.h; i++){
        for (int j=0; j<im.w; j++){
            c0 = get_pixel(im, j, i, 0);
            c1 = get_pixel(im, j, i, 1);
            c2 = get_pixel(im, j, i, 2);
            gray.data[i + j] = 0.299*c0 + 0.587*c1 + 0.114*c2;
        }
    }
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
    for (int i=0; i<im.h; i++){
        for (int j=0; j<im.w; j++){
            set_pixel(im, j, i, c, get_pixel(im, j, i, c) + v);
        }
    }
}

void clamp_image(image im)
{
    // TODO Fill this in
    for (int k=0; k<im.c; k++){
        for (int i=0; i<im.h; i++){
            for (int j=0; j<im.w; j++){
                if (get_pixel(im, j, i, k) < 0)
                {
                    set_pixel(im, j, i, k, 0);
                }
                if (get_pixel(im, j, i, k) > 1)
                {
                    set_pixel(im, j, i, k, 1);
                }                
            }
        }
    }
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
