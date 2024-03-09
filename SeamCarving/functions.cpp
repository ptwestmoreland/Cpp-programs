#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

void initializeImage(Pixel image[][MAX_HEIGHT])
{
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++)
  {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++)
    {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

bool isValidColor(int colorVal) // test rgb pixel vals
{
  if (colorVal < 0 || colorVal > 255)
  {
    return false;
  }
  return true;
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height)
{
  /*
  Load image from PPM file. Store each entry in a 2D array(col,row) of pixels and
  validate input. Pixel is a structure with red, green, and blue integer
  values that represent a color. If not enough pixels or invalid pixel
  throw exception, if too many pixel values, throw Exception
  exceptions caught in main
  */
    ifstream ifs(filename); // input PPM file
    if (!ifs.is_open())
    {
      throw std::runtime_error("Failed to open " + filename);
    }
    // begin to process ppm file
    unsigned int counter = 0; // used to count input pixels and later report if not enough were in file
    string type = "";
    ifs >> type; // read type, must be P3 or p3
    // validate

    if(toupper(type.at(0)) != 'P' || type.at(1) != '3')
    {
      throw runtime_error("Invalid type " + type);

    }
    ifs >> width;
    ifs >> height; // col and row imput from file, updates var in main

    // validate

    if(width <= 0 || width > MAX_WIDTH)
    {
      throw runtime_error("Invalid dimensions");


    }
    if(height <= 0 || height > MAX_HEIGHT)
    {
      throw runtime_error("Invalid dimensions");

    }
    int colorMax = 0;
    ifs >> colorMax; // no validation or testing or use

    // read in pixels row by row into col major order 2D array
    // if not enough pixels throw excep, if too many throw excep,
    //if invalid integer pixel value throw excep
    for(unsigned int row = 0; row < height; row++)
    {
      for(unsigned int col = 0; col < width; col++) // col major ordering
      {
        ifs >> image[col][row].r;
        counter++;
        if(ifs.fail() || !isValidColor(image[col][row].r))
        {
          throw runtime_error("Invalid color value");

        }
        ifs >> image[col][row].g;
        counter++;
        if(ifs.fail() || !isValidColor(image[col][row].g))
        {
          throw runtime_error("Invalid color value");

        }
        ifs >> image[col][row].b;
        counter++;
        if(ifs.fail() || !(isValidColor(image[col][row].b))) // non int blue vals or < 0 || > 255 vals
        {
          throw runtime_error("Invalid color value");

        }


      } // end inner pixel array loading loop

    } // end outer pixel loading loop

   int excess = 0;
   ifs >> excess; // should fail if no excess pixel values
   if(!(ifs.fail()))
   {
     throw runtime_error("Too many values");

   }
   unsigned int product = width*height*3; // how many times we ideally would have iterated in pixel processing
   if(counter < product) // counter iterates once on every succesful rgb in file stream
   {
      throw runtime_error("Invalid color value"); // too few values

   }

   ifs.close();

} // end load image function

void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height)
{
  ofstream ofs(filename);
  // open file
  if (!ofs.is_open())
  {
    throw std::invalid_argument("Failed to open file " + filename);
  }
  ofs << "P3" << endl; // write to PPM file
  ofs << width << " " << height << endl;
  ofs << 255 << endl;

  for (unsigned int row = 0; row < height; ++row) // PPM is row major ordering, image is column
  {
    for (unsigned int col = 0; col < width; ++col)
    {

      ofs << image[col][row].r << " "; // row major ordering with row in outer loop
      ofs << image[col][row].g << " ";
      ofs << image[col][row].b << " ";
    }
   ofs << endl;

  }


 ofs.close();
}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
  /*
  computes energy of a pixel from any point, middle or corner of the array. The pixel coordinates are
  at (x,y) (col,row) col major ordering. Energy is computed via dual energy gradient function.
  E = delx^2 + dely^2
  where delx^2 = red_x_comp^2 + blue_x_comp^2 + green_x_comp^2. These compoennts, Rx,Gx..
  are calcualted as the difference between adjacent pixel. For normal case we compute based
  off pixels to left and right of pixel. For border cases, one of the pixels is the adjacent one and
  the other is the pixel that wraps around. For instance, in computing the red x component of
   the pixel at (0,y) we use the pixels (1,y) and (width - 1, y). If y = 0 and we have a square
   2x2 matrix this difference is 0 as both are the same pixel.
  */

  unsigned int energy = 0;

  unsigned int xInc = x + 1; // next column
  unsigned int xDeinc = x - 1; // prev column
  unsigned int yInc = y + 1; // row adjustment
  unsigned int yDeinc = y - 1;

// corner cases columns

 if(x == 0)
 {
   xDeinc = width - 1;
 }
if(x == width - 1)
{
  xInc = 0; // x comp pixel at {col,row} = 2,0 in a 3x2 matrix is computed from pixels (1,0) && (0,0)

}
// corner cases rows for y component
if(y == height - 1)
{
  yInc = 0;
}
if(y == 0)
{
  yDeinc = height - 1;

}

// now compute energy from adjacent or wrapped around pixels

int red_col_component = image[xInc][y].r - image[xDeinc][y].r; // access pixel struct at each adjacent col and row
int green_col_component = image[xInc][y].g - image[xDeinc][y].g; // dont need abs(x) because were squaring each one
int blue_col_component = image[xInc][y].b - image[xDeinc][y].b;
int red_row_comp = image[x][yInc].r - image[x][yDeinc].r;
int green_row_comp = image[x][yInc].g - image[x][yDeinc].g;
int blue_row_comp = image[x][yInc].b - image[x][yDeinc].b;

// square each color gradient component for columns

int red_comp_sq_col = red_col_component * red_col_component;
int blue_comp_sq_col = blue_col_component * blue_col_component;
int green_comp_sq_col = green_col_component * green_col_component;

// repeat for rows

 int red_comp_sq_row = red_row_comp * red_row_comp;
 int green_comp_sq_row = green_row_comp * green_row_comp;
 int blue_comp_sq_row = blue_row_comp * blue_row_comp;

 unsigned int delCol = red_comp_sq_col + blue_comp_sq_col + green_comp_sq_col; // each component will be positive
 unsigned int delRow = red_comp_sq_row + green_comp_sq_row + blue_comp_sq_row;

 energy = delCol + delRow;

 return energy;
}

 unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[])
 {

   /*
   Utilize a greedy algorithm to load a vertical seam and compute seam energy. We start at start_col parameter and row 0 and find adjacent pixels of lowest energy.
   Pixels can not wrap around. For instance, if we start at column width - 1 we can not go to column 0. We can go forward directly by
   incrementing row and leaving column the same or we can go right(tables perspective) by decreasing the column. If pixels have same
   energy, we prefer to go directly forward and left(increase column by 1) after that. We go through all row entries with a given
   starting column. We go row by row and find the column in that row, that is adjacent to previous pixel point, that locally has
   minimal energy and load that into the seam array. The seam array index is the row value and the value at that index is the column location.
   The energy of the seam is returned from this function.
   */

   unsigned int seamEnergy = 0; // total energy of seam, what we return
   unsigned int tempEnergy = 0; // energy we choose of a particular run (minimum)
   unsigned int row = 0; // where we start
   unsigned int newColumn = 0; // column after we make our decision based on energy

   // initilizae seam array with first entry, index is row value and value at index is column value of min pixel energy
   seam[row] = start_col; // seam[0] = start_col
   // compute energy of starting point and load seamEnergy with this pixels energy
   seamEnergy = energy(image, start_col, row, width, height); // start at row 0 and start_col paramter

   // now from starting column and row 0 we loop throw rows and update seam array and total energy

   for(row = 1; row < height; row++) // begins at next row to compute adjacent pixels energy and load seam
   {
     // handle corner case start col == width - 1
     if(start_col == width - 1)
     {
       unsigned int energy1 = energy(image, start_col, row, width, height); // directly forward path, same column next row
       unsigned int energy2 = energy(image, start_col - 1, row, width, height); // path to right
       // compare adjacent pixel energies
       if(energy1 <= energy2) // if eneryg1 == energy2 we take forward path as it is preferred
       {
         tempEnergy = energy1;
         newColumn = start_col;
       }
       if(energy2 < energy1)
       {
         tempEnergy = energy2;
         newColumn = start_col - 1;
       }

     }
    else if(start_col == 0) // other corner case
    {
      unsigned int energy1 = energy(image, start_col, row, width, height); // directly forward path, same column next row
      unsigned int energy2 = energy(image, start_col + 1, row, width, height); // path to left, right path isn't possible cant wrap
      // compare adjacent pixel energies
      if(energy1 <= energy2)
      {
        tempEnergy = energy1;
        newColumn = start_col;
      }
      if(energy2 < energy1)
      {
        tempEnergy = energy2;
        newColumn = start_col + 1;
      }
    }
    else // executes for middle pixels, we can compute pixels forward, left, and right of previous row and start col
    {
      unsigned int energy1 = energy(image, start_col, row, width, height); // directly forward path, same column next row
      unsigned int energy2 = energy(image, start_col + 1, row, width, height); // path to left from tables perspective (screen right)
      unsigned int energy3 = energy(image, start_col - 1, row, width, height);
      // compare energies, store minimum in energy sum variable,  and update column for next iteration
      if(energy1 < energy2 && energy1 < energy3)
      {
        tempEnergy = energy1;
        newColumn = start_col;
      }
      else if(energy2 < energy1 && energy2 < energy3)
      {
        tempEnergy = energy2;
        newColumn = start_col + 1; // left path

      }
      else if(energy3 < energy1 && energy3 < energy2)
      {
        tempEnergy = energy3;
        newColumn = start_col - 1;
      }
      else if(energy1 == energy2 && energy2 == energy3) // all three energies are the same, forward path is preferred {
      {
        tempEnergy = energy1;
        newColumn = start_col;
      }
      else if(energy1 == energy2) // E1 == E2 != E3, could mix with above block but for clarity  i am seperating them
      {
        tempEnergy = energy1; // forward path preserved once again, prev_row + 1 and newColumncol = start_col
        newColumn = start_col;
      }
      else if(energy1 == energy3)
      {
        tempEnergy = energy1; // forward path preserved once again, prev_row + 1 and newColumncol = start_col
        newColumn = start_col;
      }
      else // executes if energy2 == energy3 && energy1 != 2,3 // last case left path preferred over right when forward energy > others
      {
        tempEnergy = energy2;
        newColumn = start_col + 1; // prefer left, we only decrease column, go right, when it is lower than other pixel energies
      }
    } // end outer else statement

     seam[row] = newColumn; // load seam array
     start_col = newColumn; // reset start_col to correct column based on minimum adjacent pixel energy for next iteration
     /*
      note you could just use start_col above and get rid of newColumn variable however statements like start_col = start_col
     on instances where column doesn't change will produce warnings.
     */
     seamEnergy += tempEnergy;

   } // end loop through 2d array to load seam array and compute seam energy

   return seamEnergy;

 } // end load vertical seam function

unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_row, unsigned int width, unsigned int height, unsigned int seam[])
{
/*
Analogous to above case. Rows and columns switch places. We now iterate across all columns and find a path through the rows
of minimum energy at each step and update the seam array while computing the total energy of the horisontal seam to return
*/
unsigned int seamEnergy = 0;
unsigned int tempEnergy = 0;
unsigned int col = 0; // where we start
unsigned int newRow = 0;

seam[col] = start_row;

seamEnergy = energy(image, col, start_row, width, height); // start at col 0 and start_row = 0 initialize



for(col = 1; col < width; col++) // begins at next row to compute adjacent pixels energy and load seam
{

  if(start_row == height - 1)
  {
    unsigned int energy1 = energy(image, col, start_row, width, height);
    unsigned int energy2 = energy(image, col, start_row - 1, width, height); // path to right, matrix perspective screen left
    // compare adjacent pixel energies
    if(energy1 <= energy2) // if eneryg1 == energy2 we take forward path as it is preferred
    {
      tempEnergy = energy1;
      newRow = start_row;
    }
    if(energy2 < energy1)
    {
      tempEnergy = energy2;
      newRow = start_row - 1;
    }

  }
 else if(start_row == 0) // other corner case
 {
   unsigned int energy1 = energy(image, col, start_row, width, height);
   unsigned int energy2 = energy(image, col, start_row + 1, width, height); // path to left, right path isn't possible cant wrap
   // compare adjacent pixel energies
   if(energy1 <= energy2)
   {
     tempEnergy = energy1;
     newRow = start_row;
   }
   if(energy2 < energy1)
   {
     tempEnergy = energy2;
     newRow = start_row + 1;
   }
 }
 else
 {
   unsigned int energy1 = energy(image, col, start_row, width, height);
   unsigned int energy2 = energy(image, col, start_row + 1, width, height);
   unsigned int energy3 = energy(image, col, start_row - 1, width, height);
   // compare energies, store minimum in energy sum variable,  and update column for next iteration
   if(energy1 < energy2 && energy1 < energy3)
   {
     tempEnergy = energy1;
     newRow = start_row;
   }
   else if(energy2 < energy1 && energy2 < energy3)
   {
     tempEnergy = energy2;
     newRow = start_row + 1;

   }
   else if(energy3 < energy1 && energy3 < energy2)
   {
     tempEnergy = energy3;
     newRow = start_row - 1;
   }
   else if(energy1 == energy2 && energy2 == energy3)
   {
     tempEnergy = energy1;
     newRow = start_row;
   }
   else if(energy1 == energy2)
   {
     tempEnergy = energy1;
     newRow = start_row;
   }
   else if(energy1 == energy3)
   {
     tempEnergy = energy1;
     newRow = start_row;
   }
   else
   {
     tempEnergy = energy2;
     newRow = start_row - 1;
   }
 } // end outer else statement

  seam[col] = newRow;
  start_row = newRow;

  seamEnergy += tempEnergy;

} // end loop through 2d array to load seam array and compute seam energy

return seamEnergy;

} // end load horizontal seam function
void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[])
{
  unsigned int indxOfOccurence = 0;
  unsigned int minSeamEnergy = loadVerticalSeam(image, 0, width, height, seam); // set start_col = 0 to initialize for search
  unsigned int tempSeamEnergy = 0;

  // loop through different start columns, find which one leads to minimum veritcal seam
  for(unsigned int col = 1; col < width; col++)
  {
    tempSeamEnergy = loadVerticalSeam(image, col, width, height, seam); // try next column and compare
    if(tempSeamEnergy < minSeamEnergy)
    {
      minSeamEnergy = tempSeamEnergy; // reset minimum seam energy if another column starting point provides lower seam energy then previous
      indxOfOccurence = col; // record index at where it occurs then try next column
      continue; // readability

    }

  }

  // call again with mstart_col = indxOfOccurence that picks a minimum vertical seam out of all options
  loadVerticalSeam(image, indxOfOccurence, width, height, seam); // loads seam parameter with minimum energy vertical seam
} // end find min vertical seam function

void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[])
{
  unsigned int indxOfOccurence = 0;
  unsigned int minSeamEnergy = loadHorizontalSeam(image, 0, width, height, seam);
  unsigned int tempSeamEnergy = 0;

  for(unsigned int row = 1; row < height; row++)
  {
    tempSeamEnergy = loadHorizontalSeam(image, row, width, height, seam);
    if(tempSeamEnergy < minSeamEnergy)
    {
      minSeamEnergy = tempSeamEnergy;
      indxOfOccurence = row;
      continue;

    }

  } // end loop


  loadHorizontalSeam(image, indxOfOccurence, width, height, seam);

} // end find min horizontal seam function

void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int height, unsigned int verticalSeam[])
{

  /*
  Removes lower energy vertical seam without resizing the 2D pixel array/ image
  */
  width = width - 1; // update parameter as we remove seam
  unsigned int row = 0;
  while(row < height)
  {
    for(unsigned int i = verticalSeam[row]; i < width; ++i) // nested loop
    {

      image[i][row] = image[i+1][row];

    }


    row += 1;
  }
} // end remove vertical seam function

 void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int& height, unsigned int horizontalSeam[])
 {
   // works in same way as removeVerticalSeam()
   height = height - 1;
   unsigned int col = 0;
   while(col < width)
   {
     for(unsigned int i = horizontalSeam[col]; i < height; ++i) // nested loop
     {

       image[col][i] = image[col][i+1];

     }


     col += 1; // outer loop
}
} // end remove horizontal seam
