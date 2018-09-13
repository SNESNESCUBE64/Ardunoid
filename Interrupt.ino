/*************************************************************/
/* Class: Interrupt                                          */
/* Version: 1.0                                              */
/* Programmer: Matthew Schalk / Michael Macdonald            */
/* Date Created: 05 September 2018                           */
/* Last Modified: 05 September 2018                          */
/*************************************************************/

/**************************************************************************/
/* Method: setupInterrupt                                                 */
/* Purpose: sets the interupt trigger speed                               */
/* Inputs: framesPerSecond: int - how many times per second it interrupts */
/* Returns: Nothing                                                       */
/**************************************************************************/
void setupInterrupt(int framesPerSecond)
{
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize interrupt counter value to 0
  OCR1A = 8000000/(framesPerSecond*1024);//set the interupt frequency, 1024 prescaler
  TCCR1B |= (1 << WGM12);  // turn on CTC mode  
  TCCR1B |= (1 << CS12) | (1 << CS10);// Set CS10 and CS12 bits for 1024 prescaler
  //enableInterrupt();
}

/**************************************************************************/
/* Method: enableInterrupt                                                */
/* Purpose: makes the interrupt start triggering                          */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void enableInterrupt()
{
  TIMSK1 |= (1 << OCIE1A);
}

/**************************************************************************/
/* Method: disableInterrupt                                               */
/* Purpose: disables the interrupt so it doesn't trigger                  */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void disableInterrupt()
{
  TCNT1 = 0;
  TIMSK1 &= ~(1 << OCIE1A);
}

/**************************************************************************/
/* Method: ISR                                                            */
/* Purpose: Triggers during a specified time                              */
/* Interupt: Timer1                                                       */
/**************************************************************************/
ISR(TIMER1_COMPA_vect)//perform all the ball actions...
{
  if(!attract)
  {
    moveBall();//move the ball
    if(oneupCounter >= 0)
      oneupCounter--;
  }
  else
  {
    attractCounter++;
    if(attractCounter == 10)
    {
      credits();
    }
    else if(attractCounter == 15)
    {
      //load level and mark as demo...
      loadBoard(1);//load the default
      updatePaddle();
      updateScoreBoard(level, lives, score);
      drawBall();
      setupInterrupt(20);
    }
    else if(attractCounter < 450 && attractCounter > 15)
    {
      moveBall();
      if(attractCounter == 112)
        movePaddle(1);
      if(attractCounter == 117)
        movePaddle(1);
      if(attractCounter == 220)
        movePaddle(0);
      if(attractCounter == 225)
        movePaddle(0);
      if(attractCounter == 230)
        movePaddle(0);
      if(attractCounter == 235)
        movePaddle(0);
      if(attractCounter == 240)
        movePaddle(0);
      if(attractCounter == 245)
        movePaddle(0);
      if(attractCounter == 250)
        movePaddle(0);
      if(attractCounter == 255)
        movePaddle(0);
      if(attractCounter == 370)
      {
        display.setCursor(0,53);
        //make the user not be able to cheat by looking where everything is
        eraseBall();
        display.drawLine(0, 18, 0, display.height()-2, BLACK);//clear the current paddle
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.print(F("OOOMPH!"));
      }
    }
    else if(attractCounter == 450)
    {
      setupInterrupt(1);//make it slow again
      resetGame();//reset it
      display.clearDisplay();
      titleScreen();
      attractCounter = 0;
    }    
  }
  TCNT1 = 0; //reset the interupt
}
