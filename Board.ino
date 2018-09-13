/*************************************************************/
/* Class: Board                                              */
/* Version: 1.0                                              */
/* Programmer: Matthew Schalk / Michael Macdonald            */
/* Date Created: 05 September 2018                           */
/* Last Modified: 05 September 2018                          */
/*************************************************************/

/**************************************************************************/
/* Method: levelSelect                                                    */
/* Purpose: makes the grid and then calls the level generation            */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void levelSelect()
{
  attract = false;
  disableInterrupt();
  int selection = 1;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  loadBoard(1);//start at 1
  while(digitalRead(aPin) != HIGH)
  {
    display.setCursor(0,0);
    display.println(F("Cheater... ;)"));
    display.print(F("Level: "));
    for(int i = 8; i < 16; i++)
      display.drawLine(36, i, 100,i, BLACK);//clear the selection
    display.print(selection);

    if(digitalRead(upPin) == HIGH)
    {
      selection--;
      if(selection < 1)
        selection = NUMBER_OF_LEVELS;

      loadBoard(selection);
      while(digitalRead(upPin) == HIGH){};
      delay(25);
    }
    else if(digitalRead(downPin) == HIGH)
    {
      selection++;
      if(selection > NUMBER_OF_LEVELS)
        selection = 1;

      loadBoard(selection);
      while(digitalRead(downPin) == HIGH){};
      delay(25);
    }  
    display.display();
  }

  level = selection;
}

void loadBoard(int inputLevel)
{
  //display.clearDisplay();
  for(int i = 16; i < 126; i++)//works better with the code...
      display.drawLine(0, i, display.width()-1,i, BLACK);//clear the board
  display.drawLine(0, WALL_TOP, display.width(), WALL_TOP, WHITE);
  display.drawLine(display.width()-1, WALL_TOP, display.width()-1, display.height()-1,WHITE);
  display.drawLine(0, display.height()-1, display.width()-1, display.height()-1,WHITE);

  if(level > NUMBER_OF_LEVELS)
  {
    //make it harder and reset back to one...
    level = 1;

    //increase dificulty
    if(score > 0)//just in case it is in attract mode
    {
      if(PADDLE_SIZE > 4)
        PADDLE_SIZE -= 2;
      setupInterrupt(30);//increase the speed
    }
  }
  
  numberOfBlocks = 0;//just to make sure we get the leftovers...

  //generate the grid
  switch(inputLevel)
  {
    case 2: makeGrid(level2);
      break;
    case 3: makeGrid(level3);
      break;
    case 4: makeGrid(level4);
      break;
    case 5: makeGrid(level5);
      break;
    case 6: makeGrid(level6);
      break;
    case 7: makeGrid(level7);
      break;
    case 8: makeGrid(level8);
      break;
    case 9: makeGrid(level9);
      break;
    case 10: makeGrid(level10);
      break;
    case 11: makeGrid(level11);
      break;
    case 12: makeGrid(level12);
      break;
    case 13: makeGrid(level13);
      break;
    case 14: makeGrid(level14);
      break;
    case 15: makeGrid(level15);
      break;
    case 16: makeGrid(level16);
      break;
    case 17: makeGrid(level17);
      break;
    case 18: makeGrid(level18);
      break;
    case 19: makeGrid(level19);
      break;
    case 20: makeGrid(level20);
      break;
    case 21: makeGrid(level21);
      break;
    case 22: makeGrid(level22);
      break;
    case 23: makeGrid(level23);
      break;
    case 24: makeGrid(level24);
      break;
    case 25: makeGrid(level25);
      break;
    case 26: makeGrid(level26);
      break;
    case 27: makeGrid(level27);
      break;
    case 28: makeGrid(level28);
      break;
    case 29: makeGrid(level29);
      break;
    case 30: makeGrid(level30);
      break;
    case 31: makeGrid(level31);
      break;
    case 32: makeGrid(level32);
      break;
    case 33: makeGrid(level33);
      break;
    case 34: makeGrid(level34);
      break;
    case 35: makeGrid(level35);
      break;
    case 36: makeGrid(level36);
      break;
    case 37: makeGrid(level37);
      break;
    case 38: makeGrid(level38);
      break;
    case 39: makeGrid(level39);
      break;
    case 40: makeGrid(level40);
      break;
    case 41: makeGrid(level41);
      break;
    case 42: makeGrid(level42);
      break;
    case 43: makeGrid(level43);
      break;
    case 44: makeGrid(level44);
      break;
    case 45: makeGrid(level45);
      break;
    case 46: makeGrid(level46);
      break;
    case 47: makeGrid(level47);
      break;
    case 48: makeGrid(level48);
      break;
    case 49: makeGrid(level49);
      break;
    case 50: makeGrid(level50);
      break;
    default: generateDefualtGrid();//in case of error
      break;
  }
    
  loadBlocks();//load all the blocks...
}

/**************************************************************************/
/* Method: generateDefualtGrid                                            */
/* Purpose: creates level 1. basically a test level                       */
/* Inputs: none                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void generateDefualtGrid()
{
    for(int i = 0; i < 9; i++)//each row
    {
      for(int j = 0; j < 21; j++)
      {
        if((j%2) == 0)
        {
          blockGrid [j][i] = 1;//assign all the values now, just in case...
          numberOfBlocks++;
        }
        else
          blockGrid [j][i] = 0;
      }
    }
}

/**************************************************************************/
/* Method: loadBlocks                                                     */
/* Purpose: generates the blocks on the screen based on the grid          */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void loadBlocks()
{
  int yCoord = 0;
  int xCoord = 0;
 
  for(int y = 18; y <62; y+=5)
  {
    xCoord = 20;
    for(int x = display.width()-4; x > LEVEL_GEN_START_X-3; x-=3)
    {     
      if(blockGrid[xCoord][yCoord] == 1)
      {
        display.drawLine(x,y,x,y+3 ,WHITE);
        display.drawLine(x+1,y,x+1,y+3 ,WHITE);
      }
      xCoord--;
    }
    yCoord++;
  }  
}

/*******************************************************************************/
/* Method: makeGrid                                                            */
/* Purpose: makes the 2d array grid that is used for block detection           */
/* Inputs: level: uint8_t [] - the array of 1s and 0s used to represent blocks */
/* Returns: Nothing                                                            */
/*******************************************************************************/
void makeGrid(uint8_t level[])
{
    int counter = 0;
    for(int i = 0; i < 9; i++)//each row
    {
      for(int j = 0; j < 21; j++)
      {
            if(pgm_read_byte_near(level + counter) ==1)
            {
              blockGrid [j][i] = 1;//assign all the values now, just in case...
              numberOfBlocks++;
            }
            else
              blockGrid [j][i] = 0;
          counter++;
      }
    }
}

/**************************************************************************/
/* Method: removeBlock                                                    */
/* Purpose: removes a block from the screen based on the grid             */
/* Inputs: x: int - the x coordinate of the one to be removed             */
/*         y: int - the y coordinate of the one to be removed             */
/* Returns: Nothing                                                       */
/**************************************************************************/
void removeBlock(int x, int y)
{
  int pixelX = 64 + (x*3);
  int pixelY = 18 + (y*5);
  display.drawLine(pixelX,pixelY,pixelX,pixelY+3 ,BLACK);
  display.drawLine(pixelX+1,pixelY,pixelX+1,pixelY+3,BLACK);
}

/**************************************************************************/
/* Method: updateScoreBoard                                               */
/* Purpose: Changes the numbers for the score                             */
/* Inputs: level: int - the level number                                  */
/*         lives: int - the number of lives                               */
/*         score: int - the users score                                   */
/* Returns: Nothing                                                       */
/**************************************************************************/
void updateScoreBoard(int level, int lives, int score)
{
  for(int i = 0; i < WALL_TOP; i++)//clear scoreboard
    display.drawLine(0, i, display.width()-1, i, BLACK);
  
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print(F("Level: "));
  display.print(level);
  display.print(F("    "));
  display.print(F("Lives: "));
  display.println(lives);
  display.print(F("Score: "));
  display.print(score);
  //do this if attract mode is enabled...
  if(attract)
    display.print(F("         DEMO"));
  //in case one up
  if(oneupCounter > 0)
  {
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(80,8);
      display.print(F("1-UP!"));
  }
  
}
