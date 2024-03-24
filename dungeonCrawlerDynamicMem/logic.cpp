#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player)
{
  char** map = nullptr; // map variable
  bool mapInvalid = false;
  // open file
  ifstream ifs;
  ifs.open(fileName);
  if(!ifs.is_open()) // return nullptr if any of dungeon level file is invalid
  {
    //cout << "KK" << endl;
    return nullptr;
  }
  // modifying to work for lines with spaces between characters and those that do not in the map portion of the file
  int doorCounter = 0;
  int dungeonExitCounter = 0;
  int totalTileCount = 0;
  // read data file as in file format

  ifs >> maxRow; // updates parameters, fails if type isnt integer
  //maxRow = maxRow - '\0';
 if(ifs.fail() )//|| isdigit(maxRow)) // if maxRow is an int, is digit returns false
  {
  //  cout << "MM" << endl;
    return nullptr;
  }

  ifs >> maxCol; // input stream
  if(ifs.fail() )//|| isdigit(maxCol)) // if maxRow is an int, is digit returns false
   {
     //cout << "MMM" << endl;
     return nullptr;

   }
  //cout << maxRow + maxCol << endl;
  // validate
  //cout << maxRow << "        " << maxCol << endl;
 if(maxRow <= 0 || maxRow > 999999)
  {
    return nullptr;

  }
  if(maxCol <= 0 || maxCol > 999999)
  {
    return nullptr;

  }
  if(maxCol > INT32_MAX/maxRow) // col*row (total tile spaces) isn't greater than max int
  {
    return nullptr; // if tile_space_total > INT32_MAX return nullptr to main

  }
  if(maxRow > INT32_MAX/maxCol){
    return nullptr;
  }
  // read in player position, update struct parameters
  ifs >> player.row; // player struct defined in logic.h
  if(ifs.fail() )//|| isdigit(player.row))
  {
  //  cout << "player.row" << endl;
    return nullptr;

  }
  ifs >> player.col;
  if(ifs.fail() )//|| isdigit(player.col))
  {
  //  cout << "player colmn" << endl;
    return nullptr;

  }
//cout << player.row + player.col << endl;
  if(player.row >= maxRow || player.row < 0)
  {
  //  cout << "a" << endl;
    return nullptr;
  }
  //cout << player.row + player.col << endl;
  //cout << "b" << endl;
  if(player.col >= maxCol || player.col < 0)
  {
    //cout << "b" << endl;
    return nullptr;
  }
  // create map, load it and validate map
  // if invalid, delete it and return nullptr
  map = createMap(maxRow, maxCol); // dynamic 2d array for dungeon level

  for(int i = 0; i < maxRow; ++i)
  {
    for(int j = 0; j < maxCol; ++j)
    {
      ifs >> map[i][j];
      if(ifs.fail()) // non char entry in file, deleteMap and return null
      {
        mapInvalid = true;

      }
      totalTileCount += 1; // count each tile should == maxrow*maxcol
      // check if entry is valid character, constants in logic.h. Using symbols here to save space
      if(map[i][j] != '-' && map[i][j] != '$' && map[i][j] != '@' && map[i][j] != 'M' && map[i][j] != '+' && map[i][j] != '?' && map[i][j] != '!')
      {
      //  cout << "d" << endl;
          mapInvalid = true;
      }
      if(map[i][j] == '!')
      {
        dungeonExitCounter += 1; // make sure theres at least 1 exit out of map or to next level

      }
      if(map[i][j] == '?') // exit to next level under levels for a category (ie easy1.txt to easy2.txt)
      {
        doorCounter += 1;

      }


    } // end inner loop to load map

  } // end outer loop
  //cout << doorCounter << endl;
  //cout << dungeonExitCounter << endl;
  //cout << map[maxRow - 1][maxCol - 1] << endl;
 if(totalTileCount < maxRow * maxCol) // not enough characters in map
  {
  //  cout << "e" << endl;
      mapInvalid = true;
  }
  /*if(totalTileCount == 0)
  {
    mapInvalid = true;
  } */

  if(doorCounter == 0 && dungeonExitCounter == 0) // no exit in map, invalid map file
  {
      mapInvalid = true;
  }
  char extraCharFlag = 'k';
  ifs >> extraCharFlag;
  if(!(ifs.fail())) // checks for extra characters in file map, greater than max
  {
      mapInvalid = true;
  }
  // verify that player tile is empty and update map with player symbol if it is
  if(map[player.row][player.col] != TILE_OPEN)
  {
      mapInvalid = true;
  }
  map[player.row][player.col] = TILE_PLAYER; // 'o' found in logic.h symbolizrs player on map


  ifs.close(); // close file
  if(!mapInvalid) // valid map
  {
    return map; // returns pointer to 2d char array if validly loaded.
  }
  deleteMap(map, maxRow); // executes if map is invalid 
  return nullptr;
}

/**
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol)
{

  if(input == MOVE_UP && nextRow != 0) // character input constants and player struct in logic.h
  {
    nextRow = nextRow - 1;
  }
  else if(input == MOVE_DOWN)
  {
    nextRow = nextRow + 1;
  }
  else if(input == MOVE_LEFT && nextCol != 0)
  {
    nextCol = nextCol - 1;
  }
  else if(input == MOVE_RIGHT)
  {
    nextCol = nextCol + 1;
  }
  // if none of above are true, nextRow and nextCOl are not updated as desired
  // all other inputs and seg faults are ignored
}
/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol)
{
  char** map = new char*[maxRow]; // make dynamic rows
  for(int i = 0; i < maxRow; ++i)
  {
    map[i] = new char[maxCol]; // make columns
  }
  for(int i = 0; i < maxRow; ++i)
  {
    for(int j = 0; j < maxCol; ++j)
    {
      map[i][j] = TILE_OPEN; // initiliaze 2D map array with open tiles before reading file for actual level

    }

  }
return map;
}
/**
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow, deallocate map and set to nullptr, set maxRow to 0
 */
void deleteMap(char**& map, int& maxRow)
{
  if(map != nullptr)
  {
  for(int i = 0; i < maxRow; i++){
    delete[] map[i];
  }
  delete[] map;
  map = nullptr;
 }
  maxRow = 0;
}

/**
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol)
{
  /* when player moves to amulet (@) symbol, map doubles in size and original map is copied into 4 subarrays
  . One goes in upper right quadrant(original) with the player, the other goes below that, another goes in the
  upper left quadrant and then another copy is made below that. Only the upper right quadrant contains the player.
  The amulet that caused the resize is destryoed by default as that tile becomes TILE_PLAYER */
  if(map == nullptr)
  {
    return nullptr;

  }
  if(maxRow <= 0)
  {
    return nullptr;

  }
  if(maxCol <= 0)
  {
    return nullptr;

  }
  // check if new dimensions overflow
  long long int temp1 = 0;
  long long int temp2 = 0;
  temp1 = maxRow;
  temp2 = maxCol;
  if(temp1 > INT32_MAX/2 || temp2 > INT32_MAX/2)
  {
    return nullptr;

  }
  int storage = maxRow; // used for making 4 copies of the map into subarray
  int storage2 = maxCol;
  maxRow *= 2;
  maxCol *= 2;
  char** map2 = createMap(maxRow, maxCol); // returns pointer dynamically allocated 2D array with 2x dimensions

  if(map2 == nullptr)
  {
    return nullptr;
  }

  // copy original map above, below and diagnollay

  for(int i = 0; i < storage; ++i)
  {
    for(int j = 0; j < storage2; ++j)
    {
      map2[i][j] = map[i][j]; // dont replace player

    } // end inner loop
 } // end loop outer
  //place holder variables iterate from 0 to originalMaxrow,Col - 1 on each copy
  // copy extra version of old map below first one (lower right quadrent) without copyinf player
  int placeHolderMap1 = 0; // used to copy over portions of first map that exist i,j wouldn't work in belo wloops as those indices dont exist
  int placeHolderMap2 = 0;
  for(int i = storage; i < maxRow; ++i){
    placeHolderMap2 = 0;
    for(int j = 0; j < storage2; ++j){

      if(map[placeHolderMap1][placeHolderMap2] == TILE_PLAYER )
      {
        map2[i][j] = TILE_OPEN; // dont copy over amulet or player
      }
      else
      {
        map2[i][j] = map[placeHolderMap1][placeHolderMap2];

      }
      placeHolderMap2++;
    }
    placeHolderMap1++;
  }
  // copy over original map in left quadrant
  // orig matrix doubled, divides into 4 submatrices of original size
  placeHolderMap1 = 0;
  placeHolderMap2 = 0;
  for(int i = 0; i < storage; ++i) // storage is original maxRow before it was doubled
  {
    placeHolderMap2 = 0;
    for(int j = storage2; j < maxCol; ++j) // maxCol has been doubled on the resize
    {
      if(map[placeHolderMap1][placeHolderMap2] == TILE_PLAYER)
      {
        map2[i][j] = TILE_OPEN; // dont copy over amulet or player
      }
      else
      {
        map2[i][j] = map[placeHolderMap1][placeHolderMap2];

      }
      placeHolderMap2++;

    }
    placeHolderMap1++;
  }

  // now copy over bottom right quadrant map
  placeHolderMap1 = 0;
  placeHolderMap2 = 0;
  for(int i = storage; i < maxRow; ++i)
  {
    placeHolderMap2 = 0;
    for(int j = storage2; j < maxCol; ++j)
    {
      if(map[placeHolderMap1][placeHolderMap2] == TILE_PLAYER)
      {
        map2[i][j] = TILE_OPEN; // dont copy over amulet or player
      }
      else
      {
        map2[i][j] = map[placeHolderMap1][placeHolderMap2];

      }
      placeHolderMap2++;

    }
    placeHolderMap1++;
  }

  deleteMap(map, storage); // deallocate original map
  map = nullptr;
  return map2;

}

/**
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure.
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol)
{
  // all constant symbols defined in logic.h
  int statusFlag = 0;
  if(map != nullptr) // verify that map is not null before accessing to avoid seg faults
  {
  //int treasureAmt = 0; // keep track of treasure
  if(nextRow < 0 || nextRow >= maxRow || nextCol < 0 || nextCol >= maxCol) // last valid index is maxCol/Row - 1
  {
    statusFlag = STATUS_STAY;
    nextRow = player.row;
    nextCol = player.col; // maintain current position if nextRow/Col is out of 2D array bounds
    return statusFlag;
  }
  else if(map[nextRow][nextCol] == TILE_PILLAR || map[nextRow][nextCol] == TILE_MONSTER)
  {
    statusFlag = STATUS_STAY; // impassible objects on next up/down/left/right position
    nextRow = player.row; // maintain row column position
    nextCol = player.col;
  }

  else if(map[nextRow][nextCol] == TILE_TREASURE)
  {
    statusFlag = STATUS_TREASURE; // impassible objects on next up/down/left/right position
    player.treasure += 1; // increment , need atleast 1 treasure piee to exit dungeon
  }
  else if(map[nextRow][nextCol] == TILE_AMULET) // resize map array amulet
  {
    statusFlag = STATUS_AMULET; // call resize in main dungeoncrawler file
  }
   else if(map[nextRow][nextCol] == TILE_DOOR) // exit to next level
  {
    statusFlag = STATUS_LEAVE;

  }
  else if(map[nextRow][nextCol] == TILE_EXIT) // exit on last dungeon level
  {
    if(player.treasure >= 1)
    {
      statusFlag = STATUS_ESCAPE;

    }
    else
    { // treat as pillar if no treasure
      statusFlag = STATUS_STAY; // impassible objects on next up/down/left/right position
      nextRow = player.row; // maintain row column position
      nextCol = player.col;

     }
  }
  else
  {
    statusFlag = STATUS_MOVE;

  }
  // update old player tile position, make it open
  map[player.row][player.col] = TILE_OPEN;
  map[nextRow][nextCol] = TILE_PLAYER;
  player.row = nextRow; // update player object
  player.col = nextCol;

}
  return statusFlag;
}

/**
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player)
{

  // check up first, we only move monsters in vertical or horizontal line of site of player 1 step closer to player
if(map != nullptr)
{
 if(player.row > 0 && player.row <= maxRow - 1 ) // verify bounds cant go up if row == 0
 {
   int begin = player.row - 1;
   for(int i = begin; i >= 0; --i) // check until top, move all monsters found 1 tile closer
   {
     if(map[i][player.col] == TILE_PILLAR) // if next tile is pillar dont move monster
     {
       break;
     }
     if(map[i][player.col] == TILE_MONSTER)
     {

       map[i + 1][player.col] = TILE_MONSTER; // move monster 1 step closer to player
       map[i][player.col] = TILE_OPEN; // reset where monster was since it moved
     }

  } // end loop
}
// repeat for vertical trip down
  if(player.row < maxRow - 1 && player.row >= 0) // valid 2d array bounds to iterate downwards through rows
  {
   for(int i = player.row + 1; i < maxRow; ++i)
   {
     if(map[i][player.col] == TILE_PILLAR) // if next tile is pillar dont move monster
     {
       break;
     }
    if(map[i][player.col] == TILE_MONSTER)
    {
      map[i - 1][player.col] = TILE_MONSTER;
      map[i][player.col] = TILE_OPEN;

     }

   } // end loop
  }

// now do left to right column searches within valid bounds
// left search first
if(player.col > 0 && player.col <= maxCol - 1)
{
  for(int i = player.col - 1; i >= 0; --i)
  {
    if(map[player.row][i] == TILE_PILLAR) // if next tile is pillar dont move monster
    {
      break; // leave loop, impassible object
    }
    if(map[player.row][i] == TILE_MONSTER)
    {
      map[player.row][i + 1] = TILE_MONSTER;
      map[player.row][i] = TILE_OPEN;
    }

  }
}
// now go screen right through columns along player row
 if(player.col < maxCol - 1 && player.col >= 0)
 {
   // begin right search in adjacent column and same row
   for(int i = player.col + 1; i < maxCol; ++i)
   {
     if(map[player.row][i] == TILE_PILLAR) // if next tile is pillar dont move monster
     {
       break;
     }
     if(map[player.row][i] == TILE_MONSTER)
     {
       map[player.row][i - 1] = TILE_MONSTER;
       map[player.row][i] = TILE_OPEN;
     }

   }
}
// check if monster got player
  if(map[player.row][player.col] == TILE_MONSTER)
 {
    return true;
 }
}
 return false;
}
