#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "projet_Draw.h"
#include "projet_Util.h"

float Zrotation = 0;
float Xrotation = 0;
float Yrotation = 0;
float orientation = 0;
int turn = 0;
int oldTurn = 0;
int upDown = 0;
int facing = 0; // De 0 a 3
int goFace = -1;

GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 0 };
GLfloat light_diffuse[] = { 0.9, 0.9, 0.9, 0 };
GLfloat light_specular[] = { .9, .9,.9, 0 };
GLfloat light_position[] = { -5.0, -5.0, 5.0, 1.0 };
GLfloat general_light_ambient[] = { 0.8, 0.8, 0.8, 1.0 };

void keyboard(unsigned char key, int x, int y){

	switch (key) {
	case 27: exit(0); break;
	case 'p': restartGame(); break;
	case 32: drawAtPos(xBarre, yBarre); break;
	default :
		switch(facing){
		case 0 :
			switch (key) {
			case 'z': if (xBarre > 0) xBarre--; break;
			case 'q': if (yBarre > 0) yBarre--; break;
			case 's': if (xBarre < 3) xBarre++; break;
			case 'd': if (yBarre < 3) yBarre++; break;
			default : break;
			}
			break;
		case 1 :
			switch (key) {
			case 'z': if (yBarre > 0) yBarre--; break;
			case 'q': if (xBarre < 3) xBarre++; break;
			case 's': if (yBarre < 3) yBarre++; break;
			case 'd': if (xBarre > 0) xBarre--; break;
			default : break;
			}
			break;
		case 2 :
			switch (key) {
			case 'z': if (xBarre < 3) xBarre++; break;
			case 'q': if (yBarre < 3) yBarre++; break;
			case 's': if (xBarre > 0) xBarre--; break;
			case 'd': if (yBarre > 0) yBarre--; break;
			default : break;
			}
			break;
		case 3 :
			switch (key) {
			case 'z': if (yBarre < 3) yBarre++; break;
			case 'q': if (xBarre > 0) xBarre--; break;
			case 's': if (yBarre > 0) yBarre--; break;
			case 'd': if (xBarre < 3) xBarre++; break;
			default : break;
			}
			break;
		default : break;
		}
		break;
	}
	glutPostRedisplay();
}

void keyboardSpecial(int key, int x, int y){
	switch (key) {
	case GLUT_KEY_LEFT :
		oldTurn = turn;
		turn = 2;
		break;
	case GLUT_KEY_RIGHT :
		oldTurn = turn;
		turn = 1;
		break;
	case GLUT_KEY_UP :
		upDown = 1;
		break;
	case GLUT_KEY_DOWN :
		upDown = 2;
		break;
	default : break;	
	}
	glutPostRedisplay();
}

void init(void) {
	glClearColor (229.0/255.0, 220.0/255.0, 193.0/255.0, 0.0);

	glClear (GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();
   	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   	util_init();
   	draw_init();
}

void changeOrientation(){
	float pas = orientation / 90;
	switch (facing){
		case 0 :
			switch (goFace){
				case 1 :
					// X : ori -> 0
					// Y : 0 -> ori*-1
					Xrotation = Xrotation - pas;
					Yrotation = Yrotation - pas;
					break;
				case 3 :
					// X : ori -> 0
					// Y : 0 -> ori
					Xrotation = Xrotation - pas;
					Yrotation = Yrotation + pas;
					break;
				case 0 :
					if (oldTurn == 1){
						Xrotation = Xrotation + pas;
						Yrotation = Yrotation + pas;
					} else {
						Xrotation = Xrotation + pas;
						Yrotation = Yrotation - pas;
					}
					break;
				default :
					Xrotation = orientation;
					Yrotation = 0;
					break;
			}
			break;
		case 1 :
			switch (goFace){
				case 2 :
					// X : 0 -> ori-1
					// Y : ori-1 -> 0
					Xrotation = Xrotation - pas;
					Yrotation = Yrotation + pas;
					break;
				case 0 :
					// X : 0 -> ori
					// Y : ori-1 -> 0
					Xrotation = Xrotation + pas;
					Yrotation = Yrotation + pas;
					break;
				case 1 :
					if (oldTurn == 1){
						Xrotation = Xrotation + pas;
						Yrotation = Yrotation - pas;
					} else {
						Xrotation = Xrotation - pas;
						Yrotation = Yrotation - pas;
					}
					break;
				default :
					Xrotation = 0;
					Yrotation = orientation * -1;
					break;
			}
			break;
		case 2 :
			switch (goFace){
				case 3 :
					// X : ori-1 -> 0
					// Y : 0 -> ori
					Xrotation = Xrotation + pas;
					Yrotation = Yrotation + pas;
					break;
				case 1 :
					// X : ori-1 -> 0
					// Y : 0 -> ori*-1
					Xrotation = Xrotation + pas;
					Yrotation = Yrotation - pas;
					break;
				case 2 :
					if (oldTurn == 1){
						Xrotation = Xrotation - pas;
						Yrotation = Yrotation - pas;
					} else {
						Xrotation = Xrotation - pas;
						Yrotation = Yrotation + pas;
					}
					break;
				default :
					Xrotation = orientation * -1;
					Yrotation = 0;
					break;
			}
			break;
		case 3 :
			switch (goFace){
				case 0 :
					// X : 0 -> ori
					// Y : ori -> 0
					Xrotation = Xrotation + pas;
					Yrotation = Yrotation - pas;
					break;
				case 2 :
					// X : 0 -> ori-1
					// Y : ori -> 0
					Xrotation = Xrotation - pas;
					Yrotation = Yrotation - pas;
					break;
				case 3 :
					if (oldTurn == 1){
						Xrotation = Xrotation - pas;
						Yrotation = Yrotation + pas;
					} else {
						Xrotation = Xrotation + pas;
						Yrotation = Yrotation + pas;
					}
					break;
				default :
					Xrotation = 0;
					Yrotation = orientation;
					break;
			}
			break;
		default : break;
	}
}

void my_timer(int v){
	changeOrientation();
	if (upDown == 0){
		switch (turn) {
		case 1 :
			Zrotation += 1;
			if (oldTurn == 2) {
				goFace = facing;
			} else {
				goFace = (facing + 1) % 4;
			}
			break;
		case 2 :
			if (Zrotation == 0){
				Zrotation = 360;
			}
			Zrotation -= 1;
			if (oldTurn == 1) {
				goFace = facing;
			} else {
				goFace = (4 + facing - 1) % 4; 
			}
			break;
		default : break;
		}
	}
	if (turn == 0){
		switch (upDown) {
		case 1 :
			if (orientation >= 60) {
				upDown = 0;
			} else {
				orientation += 1;
			}
			break;
		case 2 :
			if (orientation <= 0) {
				upDown = 0;
			} else {
				orientation -= 1;
			}
			break;
		default : break;
		}
	}

	int tmp = Zrotation;
	if (tmp % 90 == 0) {
		if (Zrotation >= 360) {
			Zrotation = 0;
		}
		if (Zrotation == 0){
			facing = 0;
		}
		if (Zrotation == 90){
			facing = 1;
		}
		if (Zrotation == 180){
			facing = 2;
		}
		if (Zrotation == 270){
			facing = 3;
		}
		
		oldTurn = turn;
		turn = 0;
		goFace = -1;
	}
	tmp = orientation;
	if (tmp % 20 == 0) {
		upDown = 0;
	}

	//printf("F%d go%d, o %f, XYZ %f|%f|%f\n", facing, goFace, orientation, Xrotation, Yrotation, Zrotation);
	glutTimerFunc(10, my_timer, 1);
	glutPostRedisplay();
}

void text(){
	if (player == 1){
		glColor3f(1, 0, 0);
	} else {
		glColor3f(0, 0, 1);
	}
	glWindowPos2i(10, 460);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, chaine);

	glColor3f(0, 0, 0);
	glWindowPos2i(10, 60);
	char * commande = "'ZQSD'  : Choix Tige\nFleches : Camera\n'P'         : Recommencer\nEchap   : Quitter";
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, commande);

	glColor3f(1, 0, 0);
	glWindowPos2i(380, 50);
	char str[80];
    sprintf(str, "Joueur 1 : %d", scoreJ1);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, str);

	glColor3f(0, 0, 1);
	glWindowPos2i(380, 20);
	char str2[80];
    sprintf(str2, "Joueur 2 : %d", scoreJ2);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, str2);
	glutSwapBuffers();
}

void display(void){
	glClear(GL_DEPTH_BUFFER_BIT);
	glClear (GL_COLOR_BUFFER_BIT);
	glEnable (GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, general_light_ambient);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);

	glPushMatrix();

	//draw_Centre(); // Centre de la fenetre

	glTranslatef(0.0,-1.0,-3.0);
	glRotatef(100,1,0,0);
	glRotatef(10,0,0,1);

	// Rotation du plateau
	glRotatef(Zrotation, 0, 0, 1);
	glRotatef(Xrotation, 1, 0, 0);
	glRotatef(Yrotation, 0, 1, 0);

	drawPlateau();
	glPopMatrix();
	
	// TEXT Field !/////////////
	glDisable(GL_NORMALIZE);
	glDisable(GL_LIGHTING);

	text();
}

void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Pour le mode filaire
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();

    gluPerspective(120,w/h,0.1,20);
	glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc (keyboardSpecial);
	glutTimerFunc(40, my_timer, 1);

	glutMainLoop();
	return 0;
}