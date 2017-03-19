#include "projet_Util.h"

int player = 0;
int gameFinished = 0;

int switchPlayer(){
	if (player == 1) player = 2;
	else player = 1;
	return player;
}

void util_init(){
  int i,j,k;
  for(i=0 ; i<4 ; i++){
    for(j=0 ; j<4 ; j++){
      for(k=0 ; k<4 ; k++){
        tabPion[i][j][k] = player;
      }
    }
  }
}


int testIsWinner(int x, int y, int z){
	// Test ligne
	if(tabPion[0][y][z] == player && 
		tabPion[1][y][z] == player && 
		tabPion[2][y][z] == player && 
		tabPion[3][y][z] == player) return 1;
	// Test colone
	if(tabPion[x][0][z] == player && 
		tabPion[x][1][z] == player && 
		tabPion[x][2][z] == player && 
		tabPion[x][3][z] == player) return 1;
	// Test hauteur
	if(tabPion[x][y][0] == player && 
		tabPion[x][y][1] == player && 
		tabPion[x][y][2] == player && 
		tabPion[x][y][3] == player) return 1;
	int i;
	// test TOUTES les diag sur x
	for (i = 0; i < 4; i++){
		if(tabPion[i][0][0] == player && 
			tabPion[i][1][1] == player && 
			tabPion[i][2][2] == player && 
			tabPion[i][3][3] == player) return 1;
		if(tabPion[i][3][0] == player && 
			tabPion[i][2][1] == player && 
			tabPion[i][1][2] == player && 
			tabPion[i][0][3] == player) return 1; 
	}
	// test TOUTES les diag sur y
	for (i = 0; i < 4; i++){
		if(tabPion[0][i][0] == player && 
			tabPion[1][i][1] == player && 
			tabPion[2][i][2] == player && 
			tabPion[3][i][3] == player) return 1;
		if(tabPion[0][i][3] == player && 
			tabPion[1][i][2] == player && 
			tabPion[2][i][1] == player && 
			tabPion[3][i][0] == player) return 1; 
	}
	// test TOUTES les diag sur z
	for (i = 0; i < 4; i++){
		if(tabPion[0][0][i] == player && 
			tabPion[1][1][i] == player && 
			tabPion[2][2][i] == player && 
			tabPion[3][3][i] == player) return 1;
		if(tabPion[0][3][i] == player && 
			tabPion[1][2][i] == player && 
			tabPion[2][1][i] == player && 
			tabPion[3][0][i] == player) return 1; 
	}
	// test les 2 diag globales
	if(tabPion[0][0][0] == player && 
		tabPion[1][1][1] == player && 
		tabPion[2][2][2] == player && 
		tabPion[3][3][3] == player) return 1;
	if(tabPion[0][3][0] == player && 
		tabPion[1][2][1] == player && 
		tabPion[2][1][2] == player && 
		tabPion[3][0][3] == player) return 1; 
	return 0;
}

int testIsNull(){
	int i,j;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if (tabPion[i][j][3] == 0) return 0;
		}
	}
	return 1;
}

void drawAtPos(int x, int y){
	if (gameFinished == 0 && tabPion[x][y][3] == 0){
		int z = -1;
		if (tabPion[x][y][0] == 0) z = 0;
		else if (tabPion[x][y][1] == 0) z = 1;
		else if (tabPion[x][y][2] == 0) z = 2;
		else if (tabPion[x][y][3] == 0) z = 3;
		
		tabPion[x][y][z] = switchPlayer();
		if (testIsWinner(x,y,z) == 1){
			gameFinished = 1;
			printf("Le joueur %d est le gagnant !\n", player);
		} else if (testIsNull() == 1){
			gameFinished = 1;
			printf("Partie nulle, aucun gagnant :/\n");
		}
	}
}

void restartGame(){
	player = 0;
	gameFinished = 0;
	util_init();
}
