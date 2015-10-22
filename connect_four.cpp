/*********************************************************************
 * Program Name: connect_four.cpp
 * Author: William Buffum
 * Date: 4/12/15
 * input: commandline argvs and user input
 * output: connect_any board game
 ********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "./connect_four.h"//library containing all prototypes used

using namespace std;

/**************************************************************
 *Name: clear_screen
 *Description: clears screen and sets cursor back to top left
 *Input: None
 *Output: cleared screen
 * ***********************************************************/
void clear_screen(){
   cout << "\e[2J" << "\e[K" << "\e[;H";
}

/***************************************************************
 *Name: delete_table
 *Description: function to free memory space after game is played
 *Input: info struct
 *Output: free'd memory space
 * *************************************************************/
void delete_table(struct game* g_info){// 5
   for(int i = 0; i < g_info->r; i++){
      delete [] g_info->board[i];// frees second D of array
   }
   delete [] g_info->board;// frees array 1D
}

/***************************************************************
 *Name: horizontal_check
 *Description: checks horizontally for connections
 *Input: info strcut, players' color, opponents' color, name of winner
 *Output: name of winner if won, otherwise nothing
 * *************************************************************/
int horizontal_check(const game &g_info, char color, char other, string winner){// 10
   int counter = 0; 
   for(int i = 0; i < (g_info.r); i++){//this selects starting row
      for(int j = 0; j < (g_info.c); j++){//this selects starting column
	 if(g_info.board[i][j] == ' '){ counter = 0; }//checks for element fill
	 if(g_info.board[i][j] == other){ counter = 0; }
	 if(g_info.board[i][j] == color){ counter += 1; }//counts color in row
	 if(counter == g_info.p){
	    cout << winner << ", you won!" << endl;
	    return 1;
	 }
      }
   }
   return 0;
}

// done
/***************************************************************
 *Name: vertical_check
 *Description: checks vertically for connections
 *Input: info struct, players' color, opponents color, name of winner
 *Output: name of winner if won, nothing if lost
 * *************************************************************/
int vertical_check(const game &g_info, char color, char other, string winner){// 10
   int counter = 0; 
   for(int i = 0; i < (g_info.c); i++){//this selects starting row
      for(int j = 0; j < (g_info.r); j++){//this selects starting column
	 if(g_info.board[j][i] == ' '){ counter = 0; }//checks for element fill
	 if(g_info.board[j][i] == other){ counter = 0; }
	 if(g_info.board[j][i] == color){ counter += 1; }//counts color in row
	 if(counter == g_info.p){
	    cout << winner << ", you won!" << endl;
	    return 1;
	 }
      }
   }
   return 0;
}

// done
/***************************************************************
 *Name: dia_dr_check
 *Description: checks upper-left diagonals for connections
 *Input: info struct, players' color, opponents color, name of winner
 *Output: name of winner if won, nothing is lost
 * *************************************************************/
int dia_dr_check(const game &g_info, char color, char other, string winner){// 11
   int counter = 0; 
   for(int i = 0; i+(g_info.p-1) < g_info.r; i++){//this selects starting row
      for(int j = 0; j+(g_info.p-1) < (g_info.c); j++){//starting column
	 for(int e = 0; e < g_info.p; e++){//loop necessary for diagonal
	    //             the e allows to go in certain directions
	    if(g_info.board[i+e][j+e] == ' '){ counter = 0; }
	    if(g_info.board[i+e][j+e] == other){ counter = 0; }
	    if(g_info.board[i+e][j+e] == color){ counter += 1; }
	    if(counter == g_info.p){
	       cout << winner << ", you won!" << endl;
	       return 1;
	    }
	 }
      }
   }
   return 0;
}

// done
/***************************************************************
 *Name: dia_ur_check
 *Description: checks upper-right diagonals for connections
 *Input: info struct, players' color, opponents color, name of winner
 *Output: name of winner if won, nothing if lost
 * *************************************************************/
int dia_ur_check(const game &g_info, char color, char other, string winner){// 11
   int counter = 0; 
   for(int i = g_info.r-1; i-(g_info.p-1) >= 0; i--){//this selects starting row
      for(int j = 0; j+(g_info.p-1) < (g_info.c); j++){//starting column
	 for(int e = 0; e < g_info.p; e++){//loop necessary for diagonal  
	    if(g_info.board[i-e][j+e] == ' '){ counter = 0; }
	    if(g_info.board[i-e][j+e] == other){ counter = 0; }
	    if(g_info.board[i-e][j+e] == color){ counter += 1; }
	    if(counter == g_info.p){
	       cout << winner << ", you won!" << endl;
	       return 1;
	    }
	 }
      }
   }
   return 0;
}

// done
/***************************************************************
 *Name: check_p1
 *Description: checks to see if player1 has the connect_any
 *Input: info struct and win variable
 *Output: win -> yes/no
 * *************************************************************/
void check_p1(const game &g_info, int &win){// 8
   /*calls to various connect_any checkers. Makes sure that a person knows
    * if they win.*/
   win = 0;
   win = horizontal_check(g_info, g_info.p1, g_info.p2, "Player1");
   if(win == 0)
      win = vertical_check(g_info, g_info.p1, g_info.p2, "Player1");
   if(win == 0)
      win = dia_dr_check(g_info, g_info.p1, g_info.p2, "Player1");
   if(win == 0)
      win = dia_ur_check(g_info, g_info.p1, g_info.p2, "Player1");
}

// done
/***************************************************************
 *Name: check_p2
 *Description: checks to see if player2 has the connect_any
 *Input: info struct and win variable
 *Output: win -> yes/no
 * *************************************************************/
void check_p2(const game &g_info, int &win){// 8
   /*calls to various connect_any checkers. Makes sure that a person knows
    * if they win.*/
   win = 0;
   win = horizontal_check(g_info, g_info.p2, g_info.p1, "Player2");
   if(win == 0)
      win = vertical_check(g_info, g_info.p2, g_info.p1, "Player2");
   if(win == 0)
      win = dia_dr_check(g_info, g_info.p2, g_info.p1, "Player2");
   if(win == 0)
      win = dia_ur_check(g_info, g_info.p2, g_info.p1, "Player2");
}

// done
/***************************************************************
 *Name: check_winner
 *Description: checks to see if either player has won
 *Input: info struct
 *Output: yes/no on person winning
 * *************************************************************/
bool check_winner(game g_info){// 5
   int winner = 0;

   check_p1(g_info, winner);
   if(winner == 0)//checks to make sure winner is overwritten
      check_p2(g_info, winner);

   return winner;
}

// done
/***************************************************************
 *Name: print_table
 *Description: prints the table after each turn
 *Input: info struct
 *Output: new table showing players' moves
 * *************************************************************/
void print_table(struct game* g_info){// 7
   clear_screen();

   for(int j = 0; j < g_info->r; j++){
      for(int k = 0; k < g_info->c; k++){
	 //turns pipes blue on the board to make them stand out
	 cout << "\033[34m" << "|" << "\033[0m" << g_info->board[j][k];
      }
      cout << "\033[34m" << "|" << "\033[0m" << endl;
      for(int i = 0; i < g_info->c; i++) {
	 cout <<  "--";
      }
      cout << "-" << endl;
   }
}

// done
/***************************************************************
 *Name: check_input
 *Description: varifies that the users move choice is okay
 *Input: info struct and users choice
 *Output: gives go-ahead to set move
 * *************************************************************/
int check_input(game* &g_info, char choice[]){// 10
   for(int i = 0; i < strlen(choice); i++){ 
      while((atoi(choice) > g_info->c)){//error check for column selection
	 cout << "Error: column doesn't exist: ";
	 cin >> choice;
	 i=0;
      }
      while(!isdigit(choice[i])){//error check to make sure col choice == int
	 cout << "Error: integers only. ";
	 cin >> choice;
	 i=0;
      }
   }
   return atoi(choice);
}


// done
/***************************************************************
 *Name: input_choice
 *Description: inputs the users choice for their move
 *Input: info struct, c-string, and players color
 *Output: varifies the move is within the table and sets it
 * *************************************************************/
void input_choice(struct game* g_info, char temp[], char color){// 8

   int choice = check_input(g_info, temp);//error checks

   /*for loop takes column selection and inputs the players color in the
    * board space if nothing is there. If there is something in the spot, 
    * then the loop bumps the piece up a slot similar to the connect_four
    * game. If the entire column is filled, then the error message
    * announces that the column is full and prompts the user for a new
    * input. The input is then taken into the loop and the process is repeated
    */

   for(int i = (g_info->r)-1; i >= 0; i--){
      if(g_info->board[i][choice-1] == ' '){
	 g_info->board[i][choice-1] = color;
	 break;
      }
      else if((i == 0) and (g_info->board[i][choice-1] != ' ')){
	 cout << "Column " << choice << " is full. Next choice?: ";
	 cin >> choice;
	 i = g_info->r;
      }
   }
}

// done
/***************************************************************
 *Name: play_game
 *Description: plays the game
 *Input: game information struct
 *Output: modifies the table after user selects move
 * *************************************************************/
void play_game(struct game* g_info){// 9
   char* choice = NULL;
   choice = new char[g_info->p];

   /*allows the users to play the game. Unfortanately, if player 1 wins, 
    * they must wait until after player 2 has gone before being notified.
    * this is slightly forced by the given prototypes because we can't put
    * the check_winner function in this function.*/

   cout << "Player1, column?: ";
   cin >> choice;
   input_choice(g_info, choice, g_info->p1);
   print_table(g_info);
   cout << "Player2, column?: ";
   cin >> choice;
   input_choice(g_info, choice, g_info->p2);
   print_table(g_info);
   delete [] choice;
}

// done
/***************************************************************
 *Name: set_colors 
 *Description: sets the players color for the game
 *Input: game information strucrt
 *Output: set colors
 * *************************************************************/
void set_colors(struct game* &g_info){// 4

   //inputs the users color
   cout << "Player1, do you want to be red or yellow? (r/y): ";
   cin >> g_info->p1;//player1 chooses their color 
   while((g_info->p1 != 'r')and(g_info->p1 != 'y')){
      cout << "Error: please select the color red or yellow (r/y): ";
      cin >> g_info->p1;
   }
   if(g_info->p1 == 'r'){//player2 assigned color not selected by player1
      g_info->p2 = 'y';
   }
   else {
      g_info->p2 = 'r';
   }
}

// done
/***************************************************************
 *Name: print_start_table
 *Description: prints the table
 *Input: game information struct
 *Output: printed board on screen
 * *************************************************************/
void print_start_table(struct game* table){// 15
   int r = table->r;
   int c = table->c;

   clear_screen();

   //prints the game board before any player has gone. 

   for(int j = 0; j < r; j++){
      for(int k = 0; k < c; k++){
	 cout << "\033[34m" <<  "|" << "\033[0m" << table->board[j][k];
      }
      cout << "\033[34m" << "|" << "\033[0m" << endl;
      for(int i = 0; i < c; i++) {
	 cout << "--";
      }
      cout << "-" << endl;
   }
}

// done
/***************************************************************
 *Name: create_table
 *Description: allocates memory space for the board
 *Input: rows and columns entered by user
 *Output: built board
 * *************************************************************/
char** create_table(int r, int c){// 5
   char** table = NULL;//creates a double pointer for the 2d array

   table = new char* [r];//puts the array of characters on the heap
   for(int i = 0; i < r; i++){
      table[i] = new char [c];//points the pointers in first D to array in 2nd D
   }
   return table;
}

// done
/***************************************************************
 *Name: fill_start_table
 *Description: fills the beginning of game table after creation
 *Input: built table
 *Output: filled in table
 * *************************************************************/
void fill_start_table(struct game* &table){// 8
   int r = table->r;
   int c = table->c;

   //creates the game board and makes it look nice

   for(int i = 0; i < c; i++) {
      cout << "--";
   }
   cout << "-" << endl;
   for(int j = 0; j < r; j++){
      for(int k = 0; k < c; k++){
	 table->board[j][k] = ' ';//fills array elements with spaces
      }
   }
}

// done
/***************************************************************
 *Name: take_arguments
 *Description: takes in the arguments and sets them to things
 *Input: commandline argv and the game information struct
 *Output: sets up information in struct
 * *************************************************************/
void take_arguments(char* info[], game* &g_info){// 4
   char p[25];

   /* error checks that ensure the number of pieces to be connected is less
    * than the rows or the columns. Also ensures that bad inputs are prompted
    * and that the new input is a varified integer. Most importantly, this
    * function sets the rows, columns, and pieces for the game board. */
   for(int i = 0; i < 7; i++){
      if(!strcmp(info[i], "-r")) { g_info->r = atoi(info[i+1]); }
      if(!strcmp(info[i], "-c")) { g_info->c = atoi(info[i+1]); }
      if(!strcmp(info[i], "-p")) { g_info->p = atoi(info[i+1]); }
   }
   while(((g_info->p) > (g_info->r)) or ((g_info->p) > (g_info->c))){
      cout << "Error: Invalid number. P cannot be larger than r or c: ";
      cin >> p;
      while(!isdigit(*p)){
	 cout << "Error: Integer only: ";
	 cin >> p;
      }
      g_info->p = atoi(p);
   }
}

// done
/***************************************************************
 *Name: set_game_info
 *Description: sets up the board and player information for game 
 *Input: game struct with information, commandline argv
 *Output: ready-to-play game
 * *************************************************************/
void set_game_info(struct game* g_info, char* info[]){// 5
   take_arguments(info, g_info);//inputs arguments
   g_info->board = create_table(g_info->r, g_info->c);// builds board
   set_colors(g_info);//assigns colors
   fill_start_table(g_info);//fills beginning table
   print_start_table(g_info);//prints beginning table
}

// done
/***************************************************************
 *Name: check_commandline_switch
 *Description: checks to make sure argvs for switch are -r, -c, or -p
 *Input: commandline argv
 *Output: exits program with bad input
 * *************************************************************/
void check_commandline_switch(char* info[]){// 5
   //checks to make sure the switch arguments are eiter -r, -c, or -p
   for(int j = 1; j < 7; j += 2){
      if(!(!strcmp(info[j], "-r") or (!strcmp(info[j], "-c"))
	       or (!strcmp(info[j], "-p")))){
	 cout << "Error: Invalid argument" << endl;
	 exit(0);
      } 
   }
}

// done
/***************************************************************
 *Name: check_commandline_numbers
 *Description: makes sure argvs after switches are integers
 *Input: commandline argv
 *Output: go-ahead or not go-ahead to continue in program
 * *************************************************************/
int check_commandline_numbers(char* info[]){// 6
   //checks to make sure the numbers enter in commandline are in fact integers
   for(int i = 2; i < 7; i += 2){
      for(int j = 0; j < strlen(info[i]); j++){
	 if(!(isdigit(info[i][j]))){
	    cout << "Error: Invalid number. Integers only: ";
	    cin >> info[i];
	    return 0;
	 }
      }
   }
   return 1;
}

// done
/***************************************************************
 *Name: check_args
 *Description: makes sure theres an -r, -c, and -p
 *Input: commandline argv
 *Output: exits program if bad input
 * *************************************************************/
void check_args(char* info[]){
   //makes sure that there are no repeated arguments
   if((strcmp(info[1],"-r")and(strcmp(info[3], "-r"))
	    and(strcmp(info[5], "-r")))){
      cout << "Error: Invalid arguments." << endl;
      exit(0);
   }
   if((strcmp(info[1],"-c")and(strcmp(info[3], "-c"))
	    and(strcmp(info[5], "-c")))){
      cout << "Error: Invalid arguments." << endl;
      exit(0);
   }
   if((strcmp(info[1],"-p")and(strcmp(info[3], "-p"))
	    and(strcmp(info[5], "-p")))){
      cout << "Error: Invalid arguments." << endl;
      exit(0);
   }
}

// done
/***************************************************************
 *Name: is_valid_arguments 
 *Description: tells main whether or not the game is to be played
 *Input: commandline argv
 *Output: go-ahead to play game
 * *************************************************************/
bool is_valid_arguments(char* info[]){// 4
   //makes sure the arguments are valid so the board can be set
   int check = 0;
   check_commandline_switch(info);
   do{
      check = check_commandline_numbers(info);
      check_args(info);
   }while(check == 0);

   return 1;
}
