/*************************************************************/
/* Class: Ball                                               */
/* Version: 1.0                                              */
/* Programmer: Matthew Schalk / Michael Macdonald            */
/* Date Created: 05 September 2018                           */
/* Last Modified: 12 September 2018                          */
/*************************************************************/

/**************************************************************************/
/* Method: titleScreen                                                    */
/* Purpose: prints the title screen to the screen                         */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void titleScreen()
{
  display.setCursor(0,0);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(F(" ARDUNOID!"));
  display.setTextSize(1);
  display.print(F("\nHigh Score:\n"));
  display.print(F("    "));
  display.print((char)EEPROM.read(2));
  display.print((char)EEPROM.read(4));
  display.print((char)EEPROM.read(6));
  display.print(F("   "));
  display.print(EEPROM.read(8));
  display.print(EEPROM.read(9));
  display.print(EEPROM.read(10));
  display.print(EEPROM.read(11));
  display.print(EEPROM.read(12));
  display.print(EEPROM.read(13));
  display.print(F("\n\n  Press 'A' to Start"));
}

/**************************************************************************/
/* Method: credits                                                        */
/* Purpose: shows the people who had a hand in the game                   */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void credits()
{
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println(F("Programmed by:\n  Matthew Schalk\n  Michael Macdonald"));
    display.println(F("Levels by:\n  Matthew Schalk\n  Michael Macdonald\n  ReGrove23\n  Antoine Fantys"));
}

/**************************************************************************/
/* Method: readyGo                                                        */
/* Purpose: prints the ready? GO! message on the bottom left corner       */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void readyGo()
{  
  display.setCursor(0,53);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print(F("Ready?"));
  display.display();
  delay(1000);
  for(int i = 53; i < 62; i++)//clear the text
    display.drawLine(0, i, 36, i, BLACK);
  display.setCursor(0,53);
  display.print(F("Go!"));
  display.display();
  delay(500);
  for(int i = 53; i < 62; i++)//clear the text
    display.drawLine(0, i, 36, i, BLACK);
}

/**************************************************************************/
/* Method: pause                                                          */
/* Purpose: stops the interupt to pause the game, prints that it is paused*/
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void pause()
{
    disableInterrupt();
    display.setCursor(0,53);
    //make the user not be able to cheat by looking where everything is
    eraseBall();
    display.drawLine(0, 18, 0, display.height()-2, BLACK);//clear the current paddle
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print(F("Paused"));
    display.display();
    while(digitalRead(aPin) == HIGH){};
    delay(25);//account for the debounce
    while(digitalRead(aPin) != HIGH){};//wait for another button press
    while(digitalRead(aPin) == HIGH){};
    delay(25);//account for the debounce
    for(int i = 53; i < 62; i++)//clear the text
      display.drawLine(0, i, 36, i, BLACK);
    drawBall();
    updatePaddle();
    display.display();
    enableInterrupt();
}

/**************************************************************************/
/* Method: ouch                                                           */
/* Purpose: just lets the user know that they died                        */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void ouch()
{
    display.setCursor(0,53);
    //make the user not be able to cheat by looking where everything is
    eraseBall();
    display.drawLine(0, 18, 0, display.height()-2, BLACK);//clear the current paddle
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print(F("OOOMPH!"));
    display.display();
    delay(2000);//account for the debounce
    for(int i = 53; i < 62; i++)//clear the text
      display.drawLine(0, i, 44, i, BLACK);
    drawBall();
    updatePaddle();
    display.display();
}

/**************************************************************************/
/* Method: gameOver                                                       */
/* Purpose: prints the game over screen after you run out of lives        */
/* Inputs: None                                                           */
/* Returns: Nothing                                                       */
/**************************************************************************/
void gameOver()
{
    //make the user not be able to cheat by looking where everything is
    eraseBall();
    lives = 0;//bring it back to 0
    updateScoreBoard(level, lives, score);
    for(int i = 16; i < 126; i++)
      display.drawLine(0, i, display.width()-1,i, BLACK);//clear the board
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(32,24);
    display.println(F("Game Over..."));
    display.setCursor(1,40);
    display.println(F("Press 'A' to Continue"));
    display.display();
    while(digitalRead(aPin) != HIGH){};
    while(digitalRead(aPin) == HIGH){};//wait until the user releases
    delay(25);//debounce
    highScore();//check for the high score and work accordingly
    display.clearDisplay();
}
