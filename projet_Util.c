#include <stdio.h>
#include "projet_Util.h"

int gameFinished = 0;

void switchPlayer(){
	if (player == 1){
		player = 2;
		chaine = "Au joueur 2 de jouer";
	} else {
		player = 1;
		chaine = "Au joueur 1 de jouer";
	}
}

void init_plateau(){
	int i,j,k;
	for(i=0 ; i<4 ; i++){
		for(j=0 ; j<4 ; j++){
			for(k=0 ; k<4 ; k++){
				tabPion[i][j][k] = 0;
			}
		}
	}
}

void util_init(){
	chaine = "Bienvenue au Puissance 4 3D !!\nAu joueur 1 de jouer";
	player = 1;
	scoreJ1 = 0;
	scoreJ2 = 0;
	init_plateau();
}

void changeTextWin(){
	if (player == 1){
		chaine = "Le joueur 1 a GAGNE !!\n/*\\ FELICITATION /*\\";
		scoreJ1 = scoreJ1 + 1;
	} else {
		chaine = "Le joueur 2 a GAGNE !!\n/*\\ FELICITATION /*\\";
		scoreJ2 = scoreJ2 + 1;
	}
}

int testIsWinner(int x, int y, int z){
	// Test ligne
	if(tabPion[0][y][z] == player && 
		tabPion[1][y][z] == player && 
		tabPion[2][y][z] == player && 
		tabPion[3][y][z] == player) {

		tabPion[0][y][z] = 3;
		tabPion[1][y][z] = 3;
		tabPion[2][y][z] = 3;
		tabPion[3][y][z] = 3;
		changeTextWin();
		return 1;
	}

		// Test colone
	if(tabPion[x][0][z] == player && 
		tabPion[x][1][z] == player && 
		tabPion[x][2][z] == player && 
		tabPion[x][3][z] == player){

		tabPion[x][0][z] = 3;
		tabPion[x][1][z] = 3;
		tabPion[x][2][z] = 3;
		tabPion[x][3][z] = 3;
		changeTextWin();
		return 1;
	}
		// Test hauteur
	if(tabPion[x][y][0] == player && 
		tabPion[x][y][1] == player && 
		tabPion[x][y][2] == player && 
		tabPion[x][y][3] == player){

		tabPion[x][y][0] = 3;
		tabPion[x][y][1] = 3;
		tabPion[x][y][2] = 3;
		tabPion[x][y][3] = 3;
		changeTextWin();
		return 1;
	}

	int i;
		// test TOUTES les diag sur x
	for (i = 0; i < 4; i++){
		if(tabPion[i][0][0] == player && 
			tabPion[i][1][1] == player && 
			tabPion[i][2][2] == player && 
			tabPion[i][3][3] == player) {

			tabPion[i][0][0] = 3;
			tabPion[i][1][1] = 3;
			tabPion[i][2][2] = 3;
			tabPion[i][3][3] = 3;
			changeTextWin();
			return 1;
		}
		if(tabPion[i][3][0] == player && 
			tabPion[i][2][1] == player && 
			tabPion[i][1][2] == player && 
			tabPion[i][0][3] == player){

			tabPion[i][3][0] = 3;
			tabPion[i][2][1] = 3;
			tabPion[i][1][2] = 3;
			tabPion[i][0][3] = 3;
			changeTextWin();
			return 1;
		} 
	}
		// test TOUTES les diag sur y
	for (i = 0; i < 4; i++){
		if(tabPion[0][i][0] == player && 
			tabPion[1][i][1] == player && 
			tabPion[2][i][2] == player && 
			tabPion[3][i][3] == player) {

			tabPion[0][i][0] = 3;
			tabPion[1][i][1] = 3;
			tabPion[2][i][2] = 3;
			tabPion[3][i][3] = 3;
			changeTextWin();
			return 1;
		}
		if(tabPion[0][i][3] == player && 
			tabPion[1][i][2] == player && 
			tabPion[2][i][1] == player && 
			tabPion[3][i][0] == player) {

			tabPion[0][i][3] = 3;
			tabPion[1][i][2] = 3;
			tabPion[2][i][1] = 3;
			tabPion[3][i][0] = 3;
			changeTextWin();
			return 1;
		}
	}
		// test TOUTES les diag sur z
	for (i = 0; i < 4; i++){
		if(tabPion[0][0][i] == player && 
			tabPion[1][1][i] == player && 
			tabPion[2][2][i] == player && 
			tabPion[3][3][i] == player) {

			tabPion[0][0][i] = 3;
			tabPion[1][1][i] = 3;
			tabPion[2][2][i] = 3;
			tabPion[3][3][i] = 3;
			changeTextWin();
			return 1;
		}
		if(tabPion[0][3][i] == player && 
			tabPion[1][2][i] == player && 
			tabPion[2][1][i] == player && 
			tabPion[3][0][i] == player) {

			tabPion[0][3][i] = 3;
			tabPion[1][2][i] = 3;
			tabPion[2][1][i] = 3;
			tabPion[3][0][i] = 3;
			changeTextWin();
			return 1;
		}
	}
		// test les 2 diag globales
	if(tabPion[0][0][0] == player && 
		tabPion[1][1][1] == player && 
		tabPion[2][2][2] == player && 
		tabPion[3][3][3] == player) {

		tabPion[0][0][0] = 3;
		tabPion[1][1][1] = 3;
		tabPion[2][2][2] = 3;
		tabPion[3][3][3] = 3;
		changeTextWin();
		return 1;
	}
	if(tabPion[0][3][0] == player && 
		tabPion[1][2][1] == player && 
		tabPion[2][1][2] == player && 
		tabPion[3][0][3] == player) {

		tabPion[0][3][0] = 3;
		tabPion[1][2][1] = 3;
		tabPion[2][1][2] = 3;
		tabPion[3][0][3] = 3;	
		changeTextWin();
		return 1;
	}
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
		
		tabPion[x][y][z] = player;

		if (testIsWinner(x,y,z) == 1){
			gameFinished = 1;
			//printf("Le joueur %d est le gagnant !\n", player);
		} else if (testIsNull() == 1){
			gameFinished = 1;
			//printf("Partie nulle, aucun gagnant :/\n");
		} else {
			switchPlayer();
		}
	}
}

void restartGame(){
	chaine = "Et c'est reparti !!\nAu joueur 1 de jouer";
	player = 1;
	gameFinished = 0;
	init_plateau();
}
