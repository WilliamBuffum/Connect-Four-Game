/**************************************************************
 * Name: main.cpp
 * Author: William Buffum
 * Date: 4/12/15
 * Input: argc and argv
 * output: connect_any game
 ************************************************************/
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "./connect_four.h"//library containing all prototypes used

using namespace std;


/******************************************************************
 * Name: main
 * Description: runs the program
 * Input: argc and argv commandline
 * Output: connect_any game
 ****************************************************************/
int main(int argc, char* argv[]){
   game g_info;
   char answer; 

   if(argc != 7){//ensures correct number of arguments were entered
      cout << "Error: Invalid number of arguments." << endl;
      exit(0);
   }
   if(is_valid_arguments(argv)){//validates arguments before starting things
      do{
	 set_game_info(&g_info, argv);//sets the board up
	 do{
	    play_game(&g_info);//plays the game
	 }while(!check_winner(g_info));//announces the winner

	 cout << "Would you like to play again? (y/n): ";
	 cin >> answer;

	 delete_table(&g_info);
      }while(answer == 'y');
   }

   return 0;
}
