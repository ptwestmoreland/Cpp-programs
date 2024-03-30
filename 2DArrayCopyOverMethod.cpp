#include <iostream>
using std::cout, std::endl, std::cin;

/* This is a simple program that copies over an old array into an enlarged new array. Enlargement 
is not done dynamically on the heap but it would be simple to implement. This has been tested 
for 2D arrays of multiple dimensions but it is hard set to work for a square matrix right now. To 
adjust this just change the array size and the old and new row/column parameters. A 2D array has 
its rows and columns incremented. It is then copied over with each entry of the old array being 
copied over as a 2x2 matrix in the new one. 

e.g the matrix 

1 3   becomes   1 1 3 3 
4 5             1 1 3 3 
                4 4 5 5
                4 4 5 5 

or 1 3 to 1 1 3 3 
          1 1 3 3

*/

int main() {
    
    
    int arr1[2][2]; // set parameters 
    int oldrow = 2;
    int oldCol = 2;
    int newRow = 4;
    int newCol = 4;
    int arr2[4][4];
    int rowPlace = 0; // used to index old array when copying over 
    int colPlace = 0; 
    
    for(int i = 0; i < oldrow;++i){ // fill array 1 with user input 
        for(int j = 0; j < oldCol; ++j){
            cin >> arr1[i][j];
        }
    }
    
    // loop through all rows 
    for(int row = 0; row < newRow; ++row)
    {
        colPlace = 0; // at every new row in the new array, reset column 
        if(row == oldrow ){ // when we turn 2x2 into 4x4, change row place holder to 1 when current row = 2
            rowPlace++; // increment 
        }
        for(int j = 0; j < newCol; ++j) // inner loop for columns, done on each row 
        {
            if(j % 2 == 0 && j != 0){ // increment column place holder for old array when j = 2,4,6....
                colPlace++;
            }
            arr2[row][j] = arr1[rowPlace][colPlace]; // copy over old array 
        } // end inner loop 
        // go back and start on next row in new array 
    } // end outer loop 
    
    
    // display results: 
    
        for(int i = 0; i < newRow;++i){
        for(int j = 0; j < newCol; ++j){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }


   return 0;
}