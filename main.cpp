//
//  main.cpp
//  Assignment4
//
//  Created by Cocan Darius-Cristian on 14.03.2024.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <iostream>


static float fRotSonne = 0., fRotRightArm = 0;
static float fRotArmLeftLateral = 0., fRotArmRightLateral = 0.;

static float fX = 1, fY = 1, fZ = 1;
bool rotateArmLeft = false;
bool rotateArmRight = false;
bool rotateArmLeftLateral = false, rotateArmRightLateral = false;

static float fRotLeftLowerLeg = 0.0, fRotRightLowerLeg = 0.0;
static float fRotLeftLeg = 0.0, fRotRightLeg = 0.0;

bool rotateLegUpperLeft = false;
bool rotateLegUpperRight = false;
bool rotateLegLowerLeft = false;
bool rotateLegLowerRight = false;


void KeyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 'l':
            rotateArmLeft=!rotateArmLeft;
            break;
        case 'r':
            rotateArmRight=!rotateArmRight;
            break;
        case 't':
            rotateArmLeftLateral =!rotateArmLeftLateral;
            break;
        case ';':
            rotateArmRightLateral =!rotateArmRightLateral;
            break;
        case 'z':
            rotateLegUpperLeft =! rotateLegUpperLeft;
            break;
        case 'x':
            rotateLegUpperRight=!rotateLegUpperRight;
            break;
            
    }
    
    glutPostRedisplay();
    
}
void Cub(GLdouble size) {

    glColor3f(1.0, 1.0, 1.0);
        glutSolidCube(size);

        
        glColor3f(0.0, 0.0, 0.0);
        glLineWidth(2);
        glutWireCube(size + 0.01);
}


void Init()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
}


void RenderScene()
{
    
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    gluLookAt(-1, 0, 4,
               0, 0, 0,
               0, 1, 0);

    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glColor3f(0.8, 0.5, 0.2);
    Cub(0.3);

    glPushMatrix();
    glScalef(1.3, 2., 0.8);
    glTranslatef(0.0, -0.25, 0.0);
    Cub(0.4);
    glPopMatrix();

    
    glPushMatrix();
    glScalef(0.4, 2.0, 0.3);
    glTranslatef(-1.0, 0.05, 0.0);
    glRotatef(30, 0.0, 0.0, 0.0);
    glRotatef(fRotSonne, 1.0, 0.0, 0.0);
    glRotatef(fRotArmLeftLateral, 0.0, 0.0, 1.0);
    Cub(0.3);
    
    
    glPushMatrix();
    glScalef(0.7, 0.5, 1.5);
    glTranslatef(0.05, -0.45, 0.15);
    Cub(0.3);
    glPopMatrix();



    glPushMatrix();
    glScalef(0.4, 2, 0.3);
    glTranslatef(1.0, 0.05, 0.0);
    glRotatef(30, 0.0, 0.0, 0.0);
    glRotatef(fRotRightArm, 1.0, 0.0, 0.0);
    glRotatef(fRotArmRightLateral, 0.0, 0.0, 1.0);
    Cub(0.3);
    

    glPushMatrix();
    glScalef(0.7, 0.5, 1.5);
    glTranslatef(-0.05, -0.45, 0.15);
    Cub(0.3);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 2., 0.3);
    glTranslatef(0, 0, 0.7);
    glRotatef(-45, 0.0, 0.0, 0.0);
    glRotatef(fRotLeftLeg, -1.0, 0.0, 0.0);
    glTranslatef(-0.4, -0.35, 0);
    Cub(0.2);
    glPopMatrix();
    
    glPushMatrix();
    glScalef(0.5, 2., 0.3);
    glTranslatef(0, 0, 0.7);
    glRotatef(-45, 0.0, 0.0, 0.0);
    glRotatef(fRotRightLeg, -1.0, 0.0, 0.0);
    glTranslatef(0.4, -0.35, 0.0);
    Cub(0.2);
    glPopMatrix();
        
    glPushMatrix();
    glScalef(0.5, 1.25, 0.3);
    glTranslatef(0, 0, 0.7);
    glRotatef(-45, 0.0, 0.0, 0.0);
    glRotatef(fRotRightLeg, -1.0, 0.0, 0.0);
    glTranslatef(0.4, -0.85, 0.0);
    glColor3f(0.8, 0.2, 0.2);
    Cub(0.2);
    glPopMatrix();
    

    glPushMatrix();
    glScalef(0.5, 1.25, 0.3);
    glTranslatef(0, 0, 0.7);
    glRotatef(-45, 0.0, 0.0, 0.0);
    glRotatef(fRotLeftLeg, -1, 0.0, 0.0);
    glTranslatef(-0.4, -0.85, 0.0);
    glColor3f(0.8, 0.2, 0.2);
    Cub(0.2);
    glPopMatrix();
    

    glutSwapBuffers();
}


void Reshape(int width, int height)
{

    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();

    glViewport(0, 0, width, height);
    gluPerspective(45., 1, 0.1, 8.);
    glMatrixMode(GL_MODELVIEW);


}

void Animate(int value) {
    const float rotationStep = 2.0;
    const float maxRotation = -90.0;
    if (rotateArmLeft) {
        float newRotation = fRotSonne + 2.0;

        if (newRotation > 45.0) {
            newRotation = 45.0;
            rotateArmLeft = false;
        }

        fRotSonne = newRotation;
    } else {
        float newRotation = fRotSonne - 2.0;

        if (newRotation < -45.0) {
            newRotation = -45.0;
            rotateArmLeft = false;
        }

        fRotSonne = newRotation;
    }
    if (rotateArmRight) {
        float newRotation = fRotRightArm + 2.0;

        if (newRotation > 45.0) {
            newRotation = 45.0;
            rotateArmRight = false;
        }

        fRotRightArm = newRotation;
    } else {
        float newRotation = fRotRightArm - 2.0;

        if (newRotation < -45.0) {
            newRotation = -45.0;
            rotateArmRight = false;
        }

        fRotRightArm = newRotation;
    }
    

    if (rotateArmRightLateral) {
            fRotArmRightLateral += rotationStep;
            
            if (fRotArmRightLateral >= 90.0) {
                fRotArmRightLateral = 90.0;
                rotateArmRightLateral = false;
            }
        }
        else {
            if (fRotArmRightLateral > 0) {
                fRotArmRightLateral -= rotationStep;
                if (fRotArmRightLateral < 0) fRotArmRightLateral = 0;
            }
        }
    if (rotateArmLeftLateral) {
            fRotArmLeftLateral -= rotationStep;
            
            
            if (fRotArmLeftLateral <= maxRotation) {
                fRotArmLeftLateral = maxRotation;
                rotateArmLeftLateral = false;
            }
        }
        else {
            if (fRotArmLeftLateral < 0) {
                fRotArmLeftLateral += rotationStep;
                if (fRotArmLeftLateral > 0) fRotArmLeftLateral = 0;
            }
        }
    if (rotateLegUpperLeft) {
        float newRotation = fRotLeftLeg + 2.0;

        if (newRotation > 45.0) {
            newRotation = 45.0;
            rotateLegUpperLeft = false;
        }

        fRotLeftLeg = newRotation;
    } else {
        float newRotation = fRotLeftLeg - 2.0;

        if (newRotation < -45.0) {
            newRotation = -45.0;
            rotateLegUpperLeft = false;
        }

        fRotLeftLeg = newRotation;
    }
    if (rotateLegUpperRight) {
        float newRotation = fRotRightLeg + 2.0;

        if (newRotation > 45.0) {
            newRotation = 45.0;
            rotateLegUpperRight = false;
        }

        fRotRightLeg = newRotation;
    } else {
        float newRotation = fRotRightLeg - 2.0;

        if (newRotation < -45.0) {
            newRotation = -45.0;
            rotateLegUpperRight = false;
        }

        fRotRightLeg = newRotation;
    }
    glutPostRedisplay();
    int wait_msec = 10;
    glutTimerFunc(wait_msec, Animate, ++value);
    
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Assignment4");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(KeyboardFunc);
    glutTimerFunc(10, Animate, 0);
    Init();
    glutMainLoop();
    return 0;
}

