#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "projet_Draw.h"

int Zrotation = 0;
int turn = 0;

void keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 27:
		exit(0);
		break;
	default : break;
	}
	glutPostRedisplay();
}

void keyboardSpecial(int key, int x, int y){
	switch (key) {
	case GLUT_KEY_LEFT :
		turn = 1;
		break;
	case GLUT_KEY_RIGHT :
		turn = 2;
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

   	draw_init();
}

void my_timer(int v){

	switch (turn) {
	case 1 :
		Zrotation += 1;
		break;
	case 2 :
		Zrotation -= 1;
		break;
	default : break;
	}

	if (Zrotation % 90 == 0) {
		turn = 0;
	}
	
	glutTimerFunc(10, my_timer, 1);
	glutPostRedisplay();
}

void display(void){
	glClear(GL_DEPTH_BUFFER_BIT);
	glClear (GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	draw_Centre(); // Centre de la fenetre


	glTranslatef(0.0,-1.0,-3.0);
	glRotatef(100,1,0,0);
	glRotatef(10,0,0,1);

	glRotatef(Zrotation, 0, 0, 1);

	// Rotation du plateau
	//glRotatef(Xrotation, 1, 0, 0);
	//glRotatef(Yrotation, 0, 1, 0);
	//glRotatef(Zrotation, 0, 0, 1);


	drawPlateau();

	//draw_Piece(1);

	glPopMatrix();

	glutSwapBuffers();
}

void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Pour le mode filaire
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

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc (keyboardSpecial);
	glutTimerFunc(40, my_timer, 1);


	glutMainLoop();
	return 0;
}
