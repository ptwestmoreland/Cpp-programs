#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "Pixel.h"

class Image {
  Pixel** image;
  unsigned int width; // columns
  unsigned int height; // rows
  std::string filename;

public:
  Image();
  Image(std::string filename);
  ~Image(){ clear();};
  Image(unsigned int width, unsigned int height);

  Pixel*& operator[](unsigned int column);
  const Pixel* operator[](unsigned int column) const;
  Image& operator=(const Image& old);
  Image(const Image& old);
  unsigned int getWidth();
  unsigned int getHeight();

  void makeGreyscale();
  void makeSepia();
  void addColor(Pixel p);

  void output(std::string filename);

private:
  void load(std::string filename);
  void allocateImage(unsigned int width, unsigned int height);
  void clear();
};

#endif
