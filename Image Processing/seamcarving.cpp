#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout, std::endl, std::cin, std::string, std::stringstream;

int main() {
  // 2D array of pixels
  static Pixel image[MAX_WIDTH][MAX_HEIGHT]; // define pixel array

  // initialize 2D array
  initializeImage(image); // initializes each element with {r,g,b} = {0,0,0}

  // declare variables
  string filename;
  unsigned int width = 0;
  unsigned int height = 0;
  unsigned int targetWidth = 0;
  unsigned int targetHeight = 0;

  // accept filename
  cout << "Input filename: ";
  cin >> filename;

  try
  {
    // attempt to load image
    loadImage(filename, image, width, height); // width height updated within function from file
    cout << "Detected image width: " << width << endl;
    cout << "Detected image height: " << height << endl;
  }
  catch (std::exception &ex)
  {
    cout << "Exception thrown: " << ex.what() << endl;
    return 1; // exit with error
  }

  // accept target dimensions
  cout << "Input target width: "; // seam carve PPM image to target dimension
  cin >> targetWidth;
  cout << "Input target height: ";
  cin >> targetHeight;


  // TODO: add code to validate input

  // float point checking isn't necessary cin converts 3.2 to int 3 with targetWidth/Height type being int

  // image resizing in this program can only make image smaller
  // so targetwidth must be less than input file width
  // comparison with targetWidth/Height < 0 isn't needed because it is unsigned
  if( targetWidth > width || targetHeight > height)
  {
    cout << "Invalid target dimensions" << endl;
    return 1; // exit error
  }

  // Exit program with error if there are problems with
  //   targetWidth or targetHeight

  cout << "Start carving..." << endl;


   while ((width - targetWidth > 0) || (height - targetHeight > 0)) {
  //   // find and remove a vertical seam
     if (width - targetWidth > 0) {
       unsigned int verticalSeam[MAX_HEIGHT];
       findMinVerticalSeam(image, width, height, verticalSeam);
       removeVerticalSeam(image, width, height, verticalSeam);
     }

  //   // find and remove a horizontal seam
      if (height - targetHeight > 0) {
       unsigned int horizontalSeam[MAX_WIDTH];
       findMinHorizontalSeam(image, width, height, horizontalSeam);
       removeHorizontalSeam(image, width, height, horizontalSeam);
     }
   }

  try {
    // attempt to output image
    stringstream ss;
    ss << "carved" << width << "X" << height << ".ppm";
    outputImage(ss.str().c_str(), image, width, height);
  } catch (std::exception &ex) {
    cout << "Exception thrown: " << ex.what() << endl;
    return 1; // exit with an error
  }

  cout << "Image output" << endl;

  return 0; // exit without errors
}
