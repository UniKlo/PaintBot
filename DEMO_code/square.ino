/*
 * Author:  Sanghyun Ko, Felipe Prevelato, Casey Singleton, David Gaitsgory, Vincent Zhao, Robert Papagna
 * Created: 11.12.2019
 *
 * (c) Copyright by 42 Robolab.
 */

/******************************** Draw Square *********************************
 *  Center piece movement to paint 3x3 sq ft based on our machinery setup.    *
 *                                                                            *
 *  Stop Spray <---------------- Move to the Left ------------------ Spray    *
 *    |                                                                       *
 *  Down                                                                      *
 *    |                                                                       *
 *    v                                                                       *
 *  Spray ---------------------- Move to the Right --------------> Stop Spray *
 *                                                                      |     *
 *                                                                     Down   *
 *                                                                      |     *
 *                                                                      v     *
 *  Stop Spray <---------------- Move to the Left ------------------- Spray   *
 *    |                                                                       *
 *  Down                                                                      *
 *    |                                                                       *
 *    v                                                                       *
 *  Spray ---------------------- Move to the Right --------------> Stop Spray *
 *                                                                      |     *
 *                                                                     Down   *
 *                                                                      |     *
 *                                                                      v     *
 *  Stop Spray <---------------- Move to the Left ------------------- Spray   *
 *  Then return to the start point                                            *
 *                                                                            *
 *  @param pos : Encoder reference while moving side way.                     *
 *  @param posH : Encoder reference while moving down way.                    *
 *****************************************************************************/

void square(long pos, long posH)
{
  while (1) {
  spray();

  moveLeft(190, 100, pos * 0.8);
  moveLeft(190, 100, pos * 0.35);
  moveLeft(190, 110, pos * 0.35);
  moveLeft(185, 130, pos * 0.6);
  stopSpraying();

  moveDown(185, 140, 0.55 * posH);
  
  spray();

  moveRight(120, 190, pos * 0.7);
  moveRight(110, 170, pos * 0.6);
  moveRight(140, 170, pos * 0.65);
  
  stopSpraying();

  moveDown(100, 180, 0.6 * posH);
  
  spray();

  moveLeft(175, 155, pos * 0.5);
  moveLeft(165, 150, pos * 0.7);
  moveLeft(155, 170, pos * 0.67);
  
  stopSpraying();

  moveDown(200, 150, 0.9 * posH);
  
  spray();

  moveRight(150, 170, pos * 0.7);
  moveRight(160, 160, pos * 0.5);
  moveRight(170, 145, pos * 0.4);
  
  stopSpraying();

  moveDown(125, 190, 0.75 * posH);
  
  spray();

  moveLeft(170, 165, pos * 0.5);
  moveLeft(155, 175, pos * 0.7);
  moveLeft(110, 190, pos * 0.3);
  
  stopSpraying();

  // Reset to origin.

  moveRight(170, 200, 1.645 * pos);
  moveUp(200, 200, 4.5 * posH);
  break;
  }
}
