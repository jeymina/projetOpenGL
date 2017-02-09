#include <math.h>

#define NBPTS 25

float pas;
float tabX[NBPTS];
float tabY[NBPTS];

void draw_init(){
  int i;
  pas = 2 * M_PI / NBPTS;
  for ( i = 0 ; i < NBPTS ; i++){
    tabX[i] = cos(i*pas);
    tabY[i] = sin(i*pas);
  }
}

void draw_Centre(){
  glPushMatrix();
  glScalef(0.1,0.1,0.1);
  glColor3f (1,0,0);
  glBegin(GL_QUADS);
  glVertex3f(0,0,0);
  glVertex3f(1,0,0);
  glVertex3f(1,1,0);
  glVertex3f(0,1,0);
  glEnd();
  glPopMatrix();
}

void draw_Socle(){
  glPushMatrix();

  glColor3f (239.0/255.0, 202.0/255.0, 141.0/255.0);
  glBegin(GL_QUADS);
  glVertex3f(0,0,0);
  glVertex3f(8,0,0);
  glVertex3f(8,8,0);
  glVertex3f(0,8,0);
  glEnd();
  glBegin(GL_QUADS);
  glVertex3f(0,0,1);
  glVertex3f(8,0,1);
  glVertex3f(8,8,1);
  glVertex3f(0,8,1);
  glEnd();


  glColor3f (206.0/255.0, 170.0/255.0, 113.0/255.0);
  glBegin(GL_QUADS);
  glVertex3f(0,0,0);
  glVertex3f(8,0,0);
  glVertex3f(8,0,1);
  glVertex3f(0,0,1);
  glEnd();
  glBegin(GL_QUADS);
  glVertex3f(8,0,0);
  glVertex3f(8,8,0);
  glVertex3f(8,8,1);
  glVertex3f(8,0,1);
  glEnd();
  glBegin(GL_QUADS);
  glVertex3f(8,8,0);
  glVertex3f(0,8,0);
  glVertex3f(0,8,1);
  glVertex3f(8,8,1);
  glEnd();
  glBegin(GL_QUADS);
  glVertex3f(0,8,0);
  glVertex3f(0,0,0);
  glVertex3f(0,0,1);
  glVertex3f(0,8,1);
  glEnd();

  glPopMatrix();
}

void draw_Barre(){
  glPushMatrix();
  int i;

  // Face Haute
  glColor3f (239.0/255.0, 202.0/255.0, 141.0/255.0);
  glBegin(GL_POLYGON);
  for ( i = 0 ; i < NBPTS ; i++){
    glVertex3f (tabX[i], tabY[i], -1);
  }
  glEnd();

  // Face Basse
  glBegin(GL_POLYGON);
  for ( i = 0 ; i < NBPTS ; i++){
    glVertex3f (tabX[i], tabY[i], 1);
  }
  glEnd();

  // Cotes
  glColor3f (206.0/255.0, 170.0/255.0, 113.0/255.0);
  for ( i = 0 ; i < NBPTS ; i++){
    glBegin(GL_POLYGON);
    glVertex3f (tabX[i], tabY[i], -1);
    glVertex3f (tabX[i], tabY[i], 1);

    glVertex3f (tabX[(i+1)%NBPTS], tabY[(i+1)%NBPTS], 1);
    glVertex3f (tabX[(i+1)%NBPTS], tabY[(i+1)%NBPTS], -1);
    glEnd();
  }
  glPopMatrix();
}

void drawPlateau(){

  glPushMatrix();
  glTranslatef(-4.0,-4.0,0.0);
  draw_Socle();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-3.0,-3.0,0.0);
  int i,j;
  for (i=0 ; i<4 ; i++){
    for (j=0 ; j<4 ; j++){
      glPushMatrix();
      glTranslatef(0.0,0.0,-2.0);
      glScalef(0.2,0.2,2);
      draw_Barre();
      glPopMatrix();
      glTranslatef(2.0,0.0,0.0);
    }
    glTranslatef(-8.0,2.0,0.0);
  }
  glPopMatrix();


}

void draw_Piece(int noJoueur){
  //if 0 = bleu
  //if 1 = rouge

  if(noJoueur == 1){
    glPushMatrix();
    glTranslatef(0,2,0);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0, 1, 0);
    glVertex3f (1, 1, 0);
    glVertex3f (1, 0, 0);
    glVertex3f (0, 0, 0);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0, 1, 0);
    glVertex3f (1, 1, 0);
    glVertex3f (1, 1, 1);
    glVertex3f (0, 1, 1);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (1, 1, 1);
    glVertex3f (0, 1, 1);
    glVertex3f (0, 0, 1);
    glVertex3f (1, 0, 1);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (1, 0, 1);
    glVertex3f (0, 0, 1);
    glVertex3f (0, 0, 0);
    glVertex3f (1, 0, 0);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (1, 1, 0);
    glVertex3f (1, 0, 0);
    glVertex3f (1, 0, 1);
    glVertex3f (1, 1, 1);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0, 1, 0);
    glVertex3f (0, 1, 1);
    glVertex3f (0, 0, 1);
    glVertex3f (0, 0, 0);
    glEnd();
    glPopMatrix();

  }else if(noJoueur == 0){

    glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0, 1, 0);
    glVertex3f (1, 1, 0);
    glVertex3f (1, 0, 0);
    glVertex3f (0, 0, 0);
    glEnd();

  glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0, 1, 0);
    glVertex3f (1, 1, 0);
    glVertex3f (1, 1, 1);
    glVertex3f (0, 1, 1);
    glEnd();

    glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (1, 1, 1);
    glVertex3f (0, 1, 1);
    glVertex3f (0, 0, 1);
    glVertex3f (1, 0, 1);
    glEnd();

    glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (1, 0, 1);
    glVertex3f (0, 0, 1);
    glVertex3f (0, 0, 0);
    glVertex3f (1, 0, 0);
    glEnd();

    glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (1, 1, 0);
    glVertex3f (1, 0, 0);
    glVertex3f (1, 0, 1);
    glVertex3f (1, 1, 1);
    glEnd();

    glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0, 1, 0);
    glVertex3f (0, 1, 1);
    glVertex3f (0, 0, 1);
    glVertex3f (0, 0, 0);
    glEnd();


  }

}
