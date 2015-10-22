/********************************************************************
 *Library Name: connect.h
 *Author: William Buffum
 *Date: 4/12/15
 *Contents: Prototypes and structs for the entire connect_any game
 ******************************************************************/
#ifndef CONNECT_H
#define CONNECT_H

using namespace std;

struct game {
   char** board;
   int r,c,p;
   char p1;
   char p2;
};

//All the prototypes I used in my program.
bool is_valid_arguments(char* info[]);
void check_args(char* info[]);
void check_commandline_switch(char* info[]);
int check_commandline_numbers(char* info[]);
int check_p_lessthan_rc(char* info[], char** temp);
void set_game_info(struct game* g_info, char* info[]);
void take_arguments(char* info[], game* &g_info);
char** create_table(int r, int c);
void fill_start_table(struct game* &table);
void print_table(struct game* table);
void set_colors(struct game* &g_info);
void play_game(struct game* g_info);
int check_input(game* &g_info, char choice[]);
void input_choice(struct game* g_info, char temp[], char color);
void print_start_table(struct game* g_info);
bool check_winner(struct game g_info);
void check_p1(const game &g_info);
void check_p2(const game &g_info);
int horizontal_check(const game &g_info, char color, char other, string winner);
int vertical_check(const game &g_info, char color, char other, string winner);
int dia_dr_check(const game &g_info, char color, char other, string winner);
int dia_ur_check(const game &g_info, char color, char other, string winner);
void delete_table(struct game* g_info);
void clear_screen();

#endif
