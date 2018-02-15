#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<math.h>

#define WIDTH 800
#define HEIGHT 800

enum {TRANSLATE = 0, SCALE, ROTATE} transformMode;

void init (void);
void display(void);
void keyboard(unsigned char  key, int x, int y);
void keyboard2(int key, int mouse_x, int mouse_y);

GLint faces[6][4] = {
{0,1,2,3}, {3,2,6,7}, {7,6,5,4},
{4,5,1,0}, {5,6,2,1}, {7,4,0,3}
};

GLfloat v[8][3];
GLfloat v2[8][3];
GLfloat v3[8][3];
GLfloat v4[8][3];
GLfloat v5[8][3];
GLfloat v6[8][3];
GLfloat v7[8][3];
GLfloat v8[8][3];
GLfloat v9[8][3];
GLfloat v10[8][3];
GLfloat v11[8][3];
GLfloat v12[8][3];
GLfloat v13[8][3];
GLfloat v14[8][3];

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Labirinto!");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboard2);
    init();
    glutMainLoop();
    return 0;
}

void init(void){
glEnable(GL_DEPTH_TEST);
transformMode = TRANSLATE;

v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
v[1][2] = v[2][2] = v[5][2] = v[6][2] = -80;

v2[0][0] = v2[1][0] = v2[2][0] = v2[3][0] = 1;
v2[4][0] = v2[5][0] = v2[6][0] = v2[7][0] = 10;
v2[0][1] = v2[1][1] = v2[4][1] = v2[5][1] = -1;
v2[2][1] = v2[3][1] = v2[6][1] = v2[7][1] = 1;
v2[0][2] = v2[3][2] = v2[4][2] = v2[7][2] = -12;
v2[1][2] = v2[2][2] = v2[5][2] = v2[6][2] = -14;

v3[0][0] = v3[1][0] = v3[2][0] = v3[3][0] = 3;
v3[4][0] = v3[5][0] = v3[6][0] = v3[7][0] = 45;
v3[0][1] = v3[1][1] = v3[4][1] = v3[5][1] = -1;
v3[2][1] = v3[3][1] = v3[6][1] = v3[7][1] = 1;
v3[0][2] = v3[3][2] = v3[4][2] = v3[7][2] = 1;
v3[1][2] = v3[2][2] = v3[5][2] = v3[6][2] = -1;

v4[0][0] = v4[1][0] = v4[2][0] = v4[3][0] = 3;
v4[4][0] = v4[5][0] = v4[6][0] = v4[7][0] = 5;
v4[0][1] = v4[1][1] = v4[4][1] = v4[5][1] = -1;
v4[2][1] = v4[3][1] = v4[6][1] = v4[7][1] = 1;
v4[0][2] = v4[3][2] = v4[4][2] = v4[7][2] = -1;
v4[1][2] = v4[2][2] = v4[5][2] = v4[6][2] = -8;

v5[0][0] = v5[1][0] = v5[2][0] = v5[3][0] = 3;
v5[4][0] = v5[5][0] = v5[6][0] = v5[7][0] = 10;
v5[0][1] = v5[1][1] = v5[4][1] = v5[5][1] = -1;
v5[2][1] = v5[3][1] = v5[6][1] = v5[7][1] = 1;
v5[0][2] = v5[3][2] = v5[4][2] = v5[7][2] = -8;
v5[1][2] = v5[2][2] = v5[5][2] = v5[6][2] = -10;

v6[0][0] = v6[1][0] = v6[2][0] = v6[3][0] = 10;
v6[4][0] = v6[5][0] = v6[6][0] = v6[7][0] = 12;
v6[0][1] = v6[1][1] = v6[4][1] = v6[5][1] = -1;
v6[2][1] = v6[3][1] = v6[6][1] = v6[7][1] = 1;
v6[0][2] = v6[3][2] = v6[4][2] = v6[7][2] = -3;
v6[1][2] = v6[2][2] = v6[5][2] = v6[6][2] = -10;

glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0f,
                    (float)WIDTH/(float)HEIGHT,
                    1.0f, 100.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glTranslatef(0.0,0.0,-5.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void drawCube(){
int i;
    for(i=0; i<6; i++){
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3fv(&v[faces[i][0]][0]);
    glColor3f(0.0,1.0,0.0);
    glVertex3fv(&v[faces[i][1]][0]);
    glColor3f(0.0,0.0,1.0);
    glVertex3fv(&v[faces[i][2]][0]);
    glColor3f(1.0,1.0,1.0);
    glVertex3fv(&v[faces[i][3]][0]);


    glColor3f(1.0,0.0,0.0);
    glVertex3fv(&v2[faces[i][0]][0]);
    glColor3f(0.0,1.0,0.0);
    glVertex3fv(&v2[faces[i][1]][0]);
    glColor3f(0.0,0.0,1.0);
    glVertex3fv(&v2[faces[i][2]][0]);
    glColor3f(1.0,1.0,1.0);
    glVertex3fv(&v2[faces[i][3]][0]);

    glColor3f(1.0,0.0,0.0);
    glVertex3fv(&v3[faces[i][0]][0]);
    glColor3f(0.0,1.0,0.0);
    glVertex3fv(&v3[faces[i][1]][0]);
    glColor3f(0.0,0.0,1.0);
    glVertex3fv(&v3[faces[i][2]][0]);
    glColor3f(1.0,1.0,1.0);
    glVertex3fv(&v3[faces[i][3]][0]);

    glColor3f(1.0,0.0,0.0);
    glVertex3fv(&v4[faces[i][0]][0]);
    glColor3f(0.0,1.0,0.0);
    glVertex3fv(&v4[faces[i][1]][0]);
    glColor3f(0.0,0.0,1.0);
    glVertex3fv(&v4[faces[i][2]][0]);
    glColor3f(1.0,1.0,1.0);
    glVertex3fv(&v4[faces[i][3]][0]);

    glColor3f(1.0,0.0,0.0);
    glVertex3fv(&v5[faces[i][0]][0]);
    glColor3f(0.0,1.0,0.0);
    glVertex3fv(&v5[faces[i][1]][0]);
    glColor3f(0.0,0.0,1.0);
    glVertex3fv(&v5[faces[i][2]][0]);
    glColor3f(1.0,1.0,1.0);
    glVertex3fv(&v5[faces[i][3]][0]);

    glColor3f(1.0,0.0,0.0);
    glVertex3fv(&v6[faces[i][0]][0]);
    glColor3f(0.0,1.0,0.0);
    glVertex3fv(&v6[faces[i][1]][0]);
    glColor3f(0.0,0.0,1.0);
    glVertex3fv(&v6[faces[i][2]][0]);
    glColor3f(1.0,1.0,1.0);
    glVertex3fv(&v6[faces[i][3]][0]);


    glEnd();
    }
}
void display(void ){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    drawCube();

    glFlush();
}
void keyboard(unsigned char key, int x, int y){
    static float posx = 0.0, posz = -5.0, angle = 0.0;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,
                    (float)WIDTH/(float)HEIGHT, 1.0f, 100.0f);
    switch(key){
        case 27:
        exit(0);
        break;
        case 't':
        case 'T':
            transformMode = TRANSLATE;
        break;
        case 'c':
        case 'C':
            transformMode = SCALE;
        break;
        case 'r':
        case 'R':
            transformMode = ROTATE;
        break;
        case 'w':
        case 'W':
            posz += 0.1*cos(M_PI*angle/180.0);
            posx += 0.1*sin(M_PI*angle/180.0);
        break;
        case 's':
        case 'S':
            posz -= 0.1*cos(M_PI*angle/180.0);
            posx -= 0.1*sin(M_PI*angle/180.0);
        case 'q':
        case 'Q':
            posz += -0.1*sin(M_PI*angle/180.0);
            posx += 0.1*cos(M_PI*angle/180.0);
        case 'e':
        case 'E':
            posz -= -0.1*sin(M_PI*angle/180.0);
            posx -= 0.1*cos(M_PI*angle/180.0);
        break;
        case 'a':
        case 'A':
            angle += 5;
        break;
        case 'd':
        case 'D':
            angle -= 5;
        break;
    }
    glRotatef(-angle, 0.0, 1.0, 0.0);
    glTranslatef(posx, 0.0, posz);

    glutPostRedisplay();
}
void keyboard2(int key, int mouse_x, int mouse_y){
    int x = 0, y = 0, z = 0;

    switch(key){
        case GLUT_KEY_PAGE_UP:
            z++;
        break;
        case GLUT_KEY_PAGE_DOWN:
            z--;
        break;
        case GLUT_KEY_UP:
            y++;
        break;
        case GLUT_KEY_DOWN:
            y--;
        break;
        case GLUT_KEY_LEFT:
            x--;
        break;
        case GLUT_KEY_RIGHT:
         x++;
        break;
    }
    glMatrixMode(GL_MODELVIEW);
    switch(transformMode){
        case TRANSLATE:
            glTranslatef(x,y,z);
        break;
        case ROTATE:
            glRotatef(5.0,x,y,z);
        break;
        case SCALE:
            glScalef(1.0 + x/10.0, 1.0 + y/1.0, 1.0 + z/10.0);
        break;
    }
    glutPostRedisplay();
}








