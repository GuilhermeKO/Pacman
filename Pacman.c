#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h> 
#include <unistd.h> 
#include <time.h> 
// Compile with g++ Pacman.c because of conio.h :(
void printa_tela(char M[20][40], int score);
void build_map(char M[20][40]);


int main(){
	char M[20][40], symbol[5], command[5], var[4][5];
	int i, j, cont = 0, flag = 1, pos1 = 9, pos2 = 19, pos3 = 15, pos4 = 19;
	int positions[4][2];
	srand(time(NULL));

	positions[0][0] = 15;
	positions[0][1] = 19;
	positions[1][0] = 5;
	positions[1][1] = 4;
	positions[2][0] = 5;
	positions[2][1] = 20;
	positions[3][0] = 15;
	positions[3][1] = 22;

	M[pos1][pos2] = 'O';	
	M[pos3][pos4] = 'X';
	
	command[0] = 'w';
	symbol[0] = ' ';
	var[0][0] = '.';
	var[1][0] = '.';
	var[2][0] = '.';
	var[3][0] = '.';

	build_map(M);

	system("clear");
	printa_tela(M, cont);
	while(!kbhit()){
		system ("clear");
		printf("------------------------------------POX MAN------------------------------------\n");
		printf("                                  #O.......X#\n\n");
		printf("A 'game' by Guilherme K.\n\n\n\n\n\n");
		printf("Press any key to start\n");
		usleep(100000);

	}

	while (1){
		if(kbhit())
			command[0] = getch();
		else {
			if(command[0] == 'p')
				goto ready;
			else if(command[0] == 'w'){
				if(M[pos1-1][pos2] == '#' && pos1-1 >= 0)
					command[0] = 'p';
				else {
					if(M[pos1-1][pos2] == 'X'){
						M[pos1-1][pos2] = '+';
						M[pos1][pos2] = ' ';
							system("clear");
							printa_tela(M, cont);
							printf("GAME OVER\n");
							return 0;
					}

					M[pos1][pos2] = symbol[0];
					pos1 -= 1;
					if(pos1 < 0)
						pos1 = 19;
				}
		
			} else if((command[0] == 's')) {
				if(M[pos1+1][pos2] == '#' && pos1+1 <= 19)
					command[0] = 'p';
				else {
					if(M[pos1+1][pos2] == 'X'){
						M[pos1+1][pos2] = '+';
						M[pos1][pos2] = ' ';
							system("clear");
							printa_tela(M, cont);
							printf("GAME OVER\n");
							return 0;
					}

					M[pos1][pos2] = symbol[0];
					pos1 += 1;
					if(pos1 > 19)
						pos1 = 0;
				}

			} else if((command[0] == 'a')) {
				if(M[pos1][pos2-1] == '#' && pos2-1 >= 0)
					command[0] = 'p';
				else {
					if(M[pos1][pos2-1] == 'X'){
						M[pos1][pos2-1] = '+';
						M[pos1][pos2] = ' ';
							system("clear");
							printa_tela(M, cont);
							printf("GAME OVER\n");
							return 0;
					}
					M[pos1][pos2] = symbol[0];
						pos2 -= 1;
				
					if(pos2 < 1)
						pos2 = 38;
				}
			} else if((command[0] == 'd')) {
				if(M[pos1][pos2+1] == '#' && pos2+1 <= 39)
					command[0] = 'p';
				else {
					if(M[pos1][pos2+1] == 'X'){
						M[pos1][pos2+1] = '+';
						M[pos1][pos2] = ' ';
							system("clear");
							printa_tela(M, cont);
							printf("GAME OVER\n");
							return 0;
					}
					M[pos1][pos2] = symbol[0];
					pos2 += 1;
					if(pos2 > 38)
						pos2 = 1;
				}
			} else
				continue;
			
			//Score counter
			if(M[pos1][pos2] == '.')
				++cont;

			if (cont == 571){
				system("clear");
				printa_tela(M, cont);
				printf("CONGRATULATIONS!!!\nYOU WON!\n");
				return 0;
			}




			M[pos1][pos2] = 'O';
			
			ready:
			//Enemies
			if(flag == 1){

				for(int i = 0; i < 4; ++i){
					int num1 = rand() % 4;
					pos3 = positions[i][0];
					pos4 = positions[i][1];

					M[pos3][pos4] = var[i][0];
					if(num1 == 0){
						if(M[pos3-1][pos4] == '#' && pos3-1 >= 0 || M[pos3-1][pos4] == 'X')
							continue;
						else {
							pos3 -= 1;
							if(pos3 < 0)
								pos3 = 19;
							var[i][0] = M[pos3][pos4];
						}

					} else if(num1 == 1){
						if(M[pos3+1][pos4] == '#' && pos3+1 <= 39 || M[pos3+1][pos4] == 'X')
							continue;
						else {
							pos3 += 1;
							if(pos3 > 19)
								pos3 = 0;
							var[i][0] = M[pos3][pos4];							
						}
					} else if(num1 == 2){
						if(M[pos3][pos4-1] == '#' && pos4-1 >= 0 || M[pos3][pos4-1] == 'X')
							continue;
						else {
							pos4 -= 1;	
							if(pos4 < 1)
								pos4 = 38;
							var[i][0] = M[pos3][pos4];
						}
						
					} else if(num1 == 3){
						if(M[pos3][pos4+1] == '#' && pos4+1 <= 39 || M[pos3][pos4+1] == 'X')
							continue;
						else {
							pos4 += 1;	
							if(pos4 > 38)
								pos4 = 1;
							var[i][0] = M[pos3][pos4];
						}

					} else 
		 				continue;
					
					M[pos3][pos4] = 'X';
					flag = 0;

					positions[i][0] = pos3;
					positions[i][1] = pos4;
					
					for(int i = 0; i < 3; ++i){
						if(pos1 == positions[i][0] && pos2 == positions[i][1]){
							M[pos1][pos2] = '+';
							system("clear");
							printa_tela(M, cont);
							printf("GAME OVER\n");
							return 0;
						}
					}
				}

			} else 
				flag = 1;
			

			usleep(60000);
		}
		
		system("clear");
		printa_tela(M, cont);
	}
		
	return 0;
}

void printa_tela(char M[20][40], int score){
	for(int i = 0; i < 20; ++i){
		for(int j = 0; j < 40; ++j){
			printf(" %c", M[i][j]);
		}
		printf("\n");
	}

	printf("SCORE: %d\n", score);

}

void build_map(char M[20][40]){
	for(int i = 1; i < 20; ++i){
		for(int j = 1; j < 40; ++j){
			M[i][j] = '.';
		}
	}

	for(int i = 0; i < 20; ++ i){
		if(i < 8 || i > 11){
			M[i][0] = '#';
			M[i][39] = '#';
		} else {
			M[i][0] = ' ';
			M[i][39] = ' ';
		}
	}

	for(int i = 0; i < 40; ++ i){
		if(i < 18 || i > 21){
			M[0][i] = '#';
			M[19][i] = '#';
		} else {
			M[0][i] = ' ';
			M[19][i] = ' ';
		}
	}

	for(int i = 14; i < 26; ++i){
		M[7][i] = '#';
		M[8][i] = '#';
	}

	for(int i = 9; i < 13; ++i){
		M[i][14] = '#';
		M[i][15] = '#';
		M[i][24] = '#';
		M[i][25] = '#';
	}

	for(int i = 5; i < 15; ++i){
		M[i][6] = '#';
		M[i][7] = '#';
		M[i][32] = '#';
		M[i][33] = '#';
	}

	for(int i = 2; i < 6; ++i){
		M[2][i] = '#';
		M[3][i] = '#';
		M[16][i] = '#';
		M[17][i] = '#';
	}

	for(int i = 34; i < 38; ++i){
		M[2][i] = '#';
		M[3][i] = '#';
		M[16][i] = '#';
		M[17][i] = '#';
	}

}
