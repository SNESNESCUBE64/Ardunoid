/*************************************************************/
/* Class: Ball                                               */
/* Version: 1.0                                              */
/* Programmer: Matthew Schalk / Michael Macdonald            */
/* Date Created: 05 September 2018                           */
/* Last Modified: 05 September 2018                          */
/*************************************************************/

/**************************************************************************/
/* Method: movePaddle                                                     */
/* Purpose: moves the paddle's position up or down                        */
/* Inputs: direction: uint8_t - the direction flag for going up and down  */
/* Returns: Nothing                                                       */
/**************************************************************************/
void movePaddle(uint8_t direction)//0 is up, 1 is down
{
  if((paddlePosition > 17) && (direction == 0))
    paddlePosition-=2;
  else if((paddlePosition < (display.height()-(PADDLE_SIZE + 2)) && (direction == 1)))
    paddlePosition+=2;

  updatePaddle();
}

/**************************************************************************/
/* Method: updatePaddle                                                   */
/* Purpose: redraws the paddle at the current position                    */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void updatePaddle()
{
  display.drawLine(0, 17, 0, display.height()-2, BLACK);//clear the current paddle
  display.drawLine(0, paddlePosition, 0, paddlePosition+PADDLE_SIZE, WHITE);//redraw the paddle
}
