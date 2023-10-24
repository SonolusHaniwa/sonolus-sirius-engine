#ifndef MODULES_PNG_H
#define MODULES_PNG_H

#include<libpng/png.h>
using namespace std;

struct image {
	int width;
	int height;
	int channel;
	png_bytep* data;
};

image readImage(string path) {
	FILE *fp = fopen(path.c_str(), "rb");
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	png_infop info_ptr = png_create_info_struct(png_ptr);
	png_init_io(png_ptr, fp);
	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_EXPAND, 0);

	image img;
	img.width = png_get_image_width(png_ptr, info_ptr);
	img.height = png_get_image_height(png_ptr, info_ptr);
	img.data = png_get_rows(png_ptr, info_ptr);
	img.channel = png_get_channels(png_ptr, info_ptr);
	return img;
}

void writeImage(string path, image img) {
	FILE *fp = fopen(path.c_str(), "wb");
	png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	png_infop info_ptr = png_create_info_struct(png_ptr);
	png_init_io(png_ptr, fp);
	png_set_IHDR(png_ptr, info_ptr, img.width, img.height, 8, PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
	png_write_info(png_ptr, info_ptr);
	png_write_image(png_ptr, img.data);
	png_write_end(png_ptr, NULL);
}

#endif
