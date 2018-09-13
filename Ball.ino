/*************************************************************/
/* Class: Ball                                               */
/* Version: 1.0                                              */
/* Programmer: Matthew Schalk / Michael Macdonald            */
/* Date Created: 05 September 2018                           */
/* Last Modified: 05 September 2018                          */
/*************************************************************/

/**************************************************************************/
/* Method: drawBall                                                       */
/* Purpose: draws the ball to the screen based on the positions           */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void drawBall()
{
  display.drawLine(ballPositionX+1, ballPositionY, ballPositionX+2,ballPositionY, WHITE);
  display.drawLine(ballPositionX, ballPositionY+1, ballPositionX+3,ballPositionY+1, WHITE);
  display.drawLine(ballPositionX, ballPositionY+2, ballPositionX+3,ballPositionY+2, WHITE);
  display.drawLine(ballPositionX+1, ballPositionY+3, ballPositionX+2,ballPositionY+3, WHITE);
  loadBlocks();//load the blocks again, sometimes the ball makes edges disappear
}

/**************************************************************************/
/* Method: eraseBall                                                      */
/* Purpose: removes the ball based on the positions, needed for movement  */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void eraseBall()
{
  display.drawLine(ballPositionX+1, ballPositionY, ballPositionX+2,ballPositionY, BLACK);
  display.drawLine(ballPositionX, ballPositionY+1, ballPositionX+3,ballPositionY+1, BLACK);
  display.drawLine(ballPositionX, ballPositionY+2, ballPositionX+3,ballPositionY+2, BLACK);
  display.drawLine(ballPositionX+1, ballPositionY+3, ballPositionX+2,ballPositionY+3, BLACK);
}

/**************************************************************************/
/* Method: moveBall                                                       */
/* Purpose: moves the ball to a new position based on generated positions */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void moveBall()//detects collision with the walls, changes direction, and moves the ball
{
  int newXPos = getNewXPos();
  int newYPos = getNewYPos();
  int collision = checkCollision(newXPos, newYPos);//checks and handles the collision with walls
  if(collision != -1)//there was a collision
  {
    if(collision != -2)
    {
      ballDirection = changeDirection(collision);//change the direction based on the collision
      moveBall();//the direction has changed, lets try again...
    }
    else
      died = 1;
  }
  else//no collision, move normally
  {
    eraseBall();
    ballPositionX = newXPos;
    ballFrontMiddleX = newXPos + 3;
    ballPositionY = newYPos;
    ballFrontMiddleY = newYPos + 1;
    drawBall();
  }
}

/**************************************************************************/
/* Method: getNewXPos                                                     */
/* Purpose: gets the next position of the ball                            */
/* Inputs: None                                                           */
/* Returns: newPosX: int - the new x position                             */
/**************************************************************************/
int getNewXPos()
{
  if((ballDirection == 0) || (ballDirection == 1))
    return ballPositionX + 1;//move right
  else
    return ballPositionX - 1;//move left
}

/**************************************************************************/
/* Method: getNewYPos                                                     */
/* Purpose: gets the next position of the ball                            */
/* Inputs: None                                                           */
/* Returns: newPosY: int - the new y position                             */
/**************************************************************************/
int getNewYPos()
{
  if((ballDirection == 0) || (ballDirection == 2))
    return ballPositionY + 1;//move down
  else
    return ballPositionY - 1;//move up
}

/**************************************************************************/
/* Method: checkCollision                                                 */
/* Purpose: checks for a collision with a block, wall, or the paddle      */
/* Inputs: newPosX: uint8_t - the new x position                          */
/*         newPosY: uint8_t - the new y position                          */
/* Returns: collisionFlag: uint8_t - if there was a collision             */
/**************************************************************************/
int checkCollision(uint8_t newPosX, uint8_t newPosY)
{
  if(newPosX == 0)//hit left limit (check for paddle)
  {
    //old paddle detection
    /*if(newPosY >= (paddlePosition-1) && newPosY < (paddlePosition + PADDLE_SIZE))
      return 0;*/
      
    for(int i = 0; i < 4; i++)//check to see if any part of the paddle hits the ball
    {
      if((/*newPosY*/ballPositionY + i) >= (paddlePosition-1) && (/*newPosY*/ballPositionY+i) < (paddlePosition + PADDLE_SIZE))
        return 0;//return if it detected it
    }
        
    return -2;//the player died, lose a life
  }
  else if(newPosX == display.width()-4)//hit right wall
    return 1;
  else if(newPosY == WALL_TOP)//hit top wall
    return 2;
  else if(newPosY == display.height()-4)//hit bottom wall
    return 3;
  else if(newPosX > 60)//account for the 
  {
    int arrayY = (ballFrontMiddleY-17)/5;//find out the array locations based on pixel locations
    int arrayX = (ballFrontMiddleX - 64)/3;

    if(blockGrid[arrayX][arrayY])//if there is a block there...
    {
      blockGrid[arrayX][arrayY] = 0;
      removeBlock(arrayX,arrayY);
      score += 5;
      lifeScore += 5;
      numberOfBlocks--;
      //loadBlocks();
      return 4;//it hit a block
    }

    return -1;
  }
  else
    return -1;//no collision 
}

/**************************************************************************/
/* Method: changeDirection                                                */
/* Purpose: changes the direction based on the collision flag             */
/* Inputs: collision: int - the collision flag, unique per collision      */
/* Returns: newDirection: int - the new direction based on collision      */
/**************************************************************************/
int changeDirection(int collision)
{
  //0 is down & right
  //1 is up & right
  //2 is down & left
  //3 is up & left
  if(ballDirection == 0 && collision == 3)
    return 1;
  else if(ballDirection == 2 && collision == 3)
    return 3;
  else if(ballDirection == 1 && collision == 2)
    return 0;
  else if(ballDirection == 3 && collision == 2)
    return 2;
  else if(ballDirection == 1 && collision == 1)
    return 3;
  else if(ballDirection == 0 && collision == 1)
    return 2;
  else if(ballDirection == 3 && collision == 0)
    return 1;
  else if(ballDirection == 2 && collision == 0)
    return 0;
  else if(ballDirection == 0 && collision == 4)
    return 2;
  else if(ballDirection == 1 && collision == 4)
    return 3;
  else if(ballDirection == 2 && collision == 4)
    return 0;
  else if(ballDirection == 3 && collision == 4)
    return 1;
  else
    return -1;//lock up the game, but should never happen
}
