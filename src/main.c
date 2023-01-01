#include <math.h>
#include <string.h>
#include "image.h"
#include "test.h"
#include "args.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
int main(int argc, char **argv)
{
    char* in = "data/dog.jpg";
    //char* out = "result";

    int option;
    scanf("%d", &option); getchar();
    // 1. get_pixel, set_pixel
    if (option == 1) {
        test_get_pixel(in);
        test_set_pixel(in);
    }
    // 2. copy image
    else if (option == 2) {
        test_copy(in);
    }
    // 3. gray scale
    else if (option == 3) {
        image im = load_image(in);
        image g = rgb_to_grayscale(im);
        save_image(g, "gray");
        free_image(im);
        free_image(g);

    }
    // 4. shifting image colors
    else if (option == 4) {
        /*image im = load_image(in);
        shift_image(im, 0, .4);
        shift_image(im, 1, .4);
        shift_image(im, 2, .4);
        save_image(im, "overflow");*/
        test_shift();
    }
    // 5. clamping image values
    else if (option == 5) {
        image im = load_image(in);
        shift_image(im, 0, .4);
        shift_image(im, 1, .4);
        shift_image(im, 2, .4);
        save_image(im, "before_clamping");

        clamp_image(im);
        save_image(im, "after_clamping");
    }
    // 6. RGB to HSV
    else if (option == 6) {
        test_rgb_to_hsv();
    }
    // 7. HSV to RGB
    else if (option == 7) {
        test_hsv_to_rgb();
    }
    else if (option == 8) {
        image im = load_image("data/dog.jpg");
        rgb_to_hsv(im);
        shift_image(im, 1, .2);
        clamp_image(im);
        hsv_to_rgb(im);
        save_image(im, "dog_saturated");
    }
    else if (option == 9) {
        test_nn_resize();
    }
    else if (option == 10) {

        test_bl_resize();

        test_multiple_resize();
    
    }
    else if (option == 11) {
        test_convolution();
    }
    else if (option == 12) {

        test_highpass_filter();
        test_emboss_filter();
        test_sharpen_filter();
    
    }
    else if (option == 13) {
       //test_gaussian_filter();
        test_gaussian_blur();
    }
    else if (option == 14) {

        test_hybrid_image();
        test_frequency_image();

    }
    else if (option == 15) {
        test_sobel();
    }
    else if (option == 16) {
        image im = load_image("data/dog.jpg");
        image new_image = colorize_sobel(im);
        save_image(new_image, "colorized");
    }
    return 0;
}
