/*************************************************************/
/* Class: Ball                                               */
/* Version: 1.0                                              */
/* Programmer: Matthew Schalk / Michael Macdonald            */
/* Date Created: 05 September 2018                           */
/* Last Modified: 05 September 2018                          */
/*************************************************************/

/**************************************************************************/
/* Method: resetGame                                                      */
/* Purpose: resets everything, lives, score, and board                    */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void resetGame()
{
  lives = 2;
  level = 1;
  score = 0;
  lifeScore = 0;
  died = 0;
  PADDLE_SIZE = 8;
  resetBoard();//might as well reset these
}

/**************************************************************************/
/* Method: resetBoard                                                     */
/* Purpose: resets the board after user loses a life                      */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void resetBoard()
{
  ballDirection = 0;
  eraseBall();//erase the ball
  paddlePosition = 35;//the current position on the top of the paddle
  ballPositionX = 1;//the X pos of the ball
  ballPositionY = 38;//The Y pos of the ball
  ballFrontMiddleX = 4;
  ballFrontMiddleY = 39;
  updatePaddle();//draw the paddle
  drawBall();//redraw the ball
}
