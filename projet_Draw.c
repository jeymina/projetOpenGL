#include <math.h>
#include <GL/glut.h>
#include "projet_Draw.h"
#include "projet_Util.h"

#define NBPTS 25

float pas;
float tabX[NBPTS];
float tabY[NBPTS];

void draw_sphere(float size, float r, float g, float b); 

#define transp 0.25
GLfloat pla1_ambient[] = { 239.0/255.0, 202.0/255.0, 141.0/255.0, 1.0 };
GLfloat pla1_ambientSelected[] = { 0.6, 0.6, 0.6, 1.0 };
GLfloat pla1_diffuse[] = {transp, transp, transp, 1.0 };
GLfloat pla1_specular[] = { 1, 1, 1, 1 };
GLfloat pla1_shininess[] = { 70.0 };
GLfloat pla1_emission[] = {0, 0, 0, 0};

GLfloat pla2_ambient[] = { 206.0/255.0, 170.0/255.0, 113.0/255.0, 1.0 };
GLfloat pla2_ambientSelected[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat pla2_diffuse[] = { transp, transp, transp, 1.0 };
GLfloat pla2_specular[] = { 1, 1, 1, 1 };
GLfloat pla2_shininess[] = { 70.0 };
GLfloat pla2_emission[] = {0, 0, 0, 0};

GLfloat jou1_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat jou1_diffuse[] = { transp, transp, transp, 1.0 };
GLfloat jou1_specular[] = { 1, 1, 1, 1 };
GLfloat jou1_shininess[] = { 70.0 };
GLfloat jou1_emission[] = {0, 0, 0, 0};

GLfloat jou2_ambient[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat jou2_diffuse[] = { transp, transp, transp, 1.0 };
GLfloat jou2_specular[] = { 1, 1, 1, 1 };
GLfloat jou2_shininess[] = { 50.0 };
GLfloat jou2_emission[] = {0, 0, 0, 0};

GLfloat jou3_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat jou3_diffuse[] = { transp, transp, transp, 1.0 };
GLfloat jou3_specular[] = { 1, 1, 1, 1 };
GLfloat jou3_shininess[] = { 50.0 };
GLfloat jou3_emission[] = {0, 0, 0, 0};

void draw_init(){
  int i;
  pas = 2 * M_PI / NBPTS;
  for ( i = 0 ; i < NBPTS ; i++){
    tabX[i] = cos(i*pas);
    tabY[i] = sin(i*pas);
  }
  xBarre = 0;
  yBarre = 0;
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

  glMaterialfv(GL_FRONT, GL_AMBIENT, pla1_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, pla1_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, pla1_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, pla1_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, pla1_emission);
  glColor3f (239.0/255.0, 202.0/255.0, 141.0/255.0);
  glBegin(GL_QUADS); // Haut
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0,0,0);
    glVertex3f(8,0,0);
    glVertex3f(8,8,0);
    glVertex3f(0,8,0);
  glEnd();
  glBegin(GL_QUADS); // Bas
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0,0,1);
    glVertex3f(8,0,1);
    glVertex3f(8,8,1);
    glVertex3f(0,8,1);
  glEnd();

  glMaterialfv(GL_FRONT, GL_AMBIENT, pla2_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, pla2_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, pla2_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, pla2_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, pla2_emission);
  glColor3f (206.0/255.0, 170.0/255.0, 113.0/255.0);
  glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0,0,0);
    glVertex3f(8,0,0);
    glVertex3f(8,0,1);
    glVertex3f(0,0,1);
  glEnd();
  glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(8,0,0);
    glVertex3f(8,8,0);
    glVertex3f(8,8,1);
    glVertex3f(8,0,1);
  glEnd();
  glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(8,8,0);
    glVertex3f(0,8,0);
    glVertex3f(0,8,1);
    glVertex3f(8,8,1);
  glEnd();
  glBegin(GL_QUADS);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0,8,0);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glVertex3f(0,8,1);
  glEnd();

  glPopMatrix();
}

void draw_Barre(int isSelected){
  glPushMatrix();

  int i;

  // Face Haute
  if (!isSelected) glMaterialfv(GL_FRONT, GL_AMBIENT, pla1_ambient);
  else  glMaterialfv(GL_FRONT, GL_AMBIENT, pla1_ambientSelected);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, pla1_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, pla1_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, pla1_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, pla1_emission);
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
  if (!isSelected) glMaterialfv(GL_FRONT, GL_AMBIENT, pla2_ambient);
  else  glMaterialfv(GL_FRONT, GL_AMBIENT, pla2_ambientSelected);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, pla2_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, pla2_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, pla2_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, pla2_emission);
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
  int i,j,k;
  for (i=0 ; i<4 ; i++){
    for (j=0 ; j<4 ; j++){
      glPushMatrix();
      glTranslatef(0.0,0.0,-2.0);
      if (i == xBarre && j == yBarre){
        glScalef(0.28,0.28,2.55);
        draw_Barre(1);
      } else {
        glScalef(0.2,0.2,2.5);
        draw_Barre(0);
      }
      glPopMatrix();

      glPushMatrix();
      /*glScalef(0.8,0.8,0.8);*/
      for (k=0; k<4; k++){
        if (k == 0){
          glTranslatef(0.0,0.0,-0.5);
        } else {
          glTranslatef(0.0,0.0,-1.1);
        }
        draw_Piece(tabPion[i][j][k]);
      }
      glPopMatrix ();

      glTranslatef(2.0,0.0,0.0);
    }
    glTranslatef(-8.0,2.0,0.0);
  }
  glPopMatrix();
}

void draw_Piece(int noJoueur){
  if (noJoueur == 0){
    // On ne dessine rien
    return;
  }

  //if 0 = bleu
  //if 1 = rouge
  glPushMatrix();
  //glTranslatef(-0.5,-0.5,0);

  if(noJoueur == 1){
    glMaterialfv(GL_FRONT, GL_AMBIENT, jou1_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, jou1_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, jou1_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, jou1_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, jou1_emission);
    glColor3f (1.0, 0.0, 0.0);
  }else if(noJoueur == 2){
    glMaterialfv(GL_FRONT, GL_AMBIENT, jou2_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, jou2_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, jou2_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, jou2_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, jou2_emission);
    glColor3f (0.0, 0.0, 1.0);

  }else if(noJoueur == 3){
    glMaterialfv(GL_FRONT, GL_AMBIENT, jou3_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, jou3_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, jou3_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, jou3_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, jou3_emission);
    glColor3f (1.0, 1.0, 1.0);

  }
  draw_sphere(0.6, 1,1,1);

  glPopMatrix();
}

///////////////////////////////////////////////////////////
//  Approximation icosaedrale  de sphere 
///////////////////////////////////////////////////////////

#define X .525731112119133606
#define Z .850650808352039932

GLfloat sommets[12][3] =
{
  {-X, 0, Z},
  {X, 0, Z},
  {-X, 0, -Z},
  {X, 0, -Z},
  {0, Z, X},
  {0, Z, -X},
  {0, -Z, X},
  {0, -Z, -X},
  {Z, X, 0},
  {-Z, X, 0},
  {Z, -X, 0},
  {-Z, -X, 0}
};

int index[20][3] =
{
  {0, 4, 1},
  {0, 9, 4},
  {9, 5, 4},
  {4, 5, 8},
  {4, 8, 1},
  {8, 10, 1},
  {8, 3, 10},
  {5, 3, 8},
  {5, 2, 3},
  {2, 7, 3},
  {7, 10, 3},
  {7, 6, 10},
  {7, 11, 6},
  {11, 0, 6},
  {0, 1, 6},
  {6, 1, 10},
  {9, 0, 11},
  {9, 11, 2},
  {9, 2, 5},
  {7, 2, 11},
};

void pousser_profondeur(float v[3]) {
   float d=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
   v[0]=v[0]/d;
   v[1]=v[1]/d;
   v[2]=v[2]/d;
} 

void draw_triangle(float* v1, float *v2, float *v3, int n, float r, float g, float b) {
  int xyz;
  float v[3][3];

  if(n==0)
   {
   glBegin(GL_TRIANGLES);
      glColor3f(r,g,b);
      glNormal3f(v1[0], v1[1], v1[2]);
      glVertex3f(v1[0], v1[1], v1[2]);
      glNormal3f(v2[0], v2[1], v2[2]);
      glVertex3f(v2[0], v2[1], v2[2]);
      glNormal3f(v3[0], v3[1], v3[2]);
      glVertex3f(v3[0], v3[1], v3[2]);
   glEnd();
   }
   else  {
   for(xyz=0; xyz<3; xyz++)
      {
      v[0][xyz]=(v1[xyz]+v2[xyz])/2;   
      v[1][xyz]=(v1[xyz]+v3[xyz])/2;   
      v[2][xyz]=(v3[xyz]+v2[xyz])/2;   
      }   

        pousser_profondeur(v[0]);
        pousser_profondeur(v[1]);
        pousser_profondeur(v[2]);


   draw_triangle(v1, v[0], v[1], n-1, r,g,b);
   draw_triangle(v[0], v2, v[2], n-1, r,g,b);
   draw_triangle(v[0], v[1], v[2], n-1, r,g,b);
   draw_triangle(v[1], v[2], v3, n-1, r,g,b);
   }
}

void draw_sphere(float size, float r, float g, float b) {
   int i;

   glPushMatrix();

   glScalef(size,size,size);

   for (i = 0; i <20; i++) {
    draw_triangle(sommets[index[i][2]], sommets[index[i][1]], sommets[index[i][0]], 1,r,g,b);
   }
   glPopMatrix();
}