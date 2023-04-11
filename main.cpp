#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<Windows.h>

void *font;
void *currentfont;
int fontType,flag=0;
int in_about;
int enter;
float i,j;
float x2,y2,r,r1=80,r2=5.0,r3=27.5,r4=6,r5=6,x,y,angle,angle_radians,r6=23,r7=2,r8=3,r9=6,r10=18,r11=10,r12=26,r13=14;
int k=0;
int p=0;

void delay(int x)
{
    int i,j;
    for(i=0; i<x; i++)
    {
        for(j=0; j<i*1000; j++)
            ;
    }
}

void display()
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(200, 200, 350, 200, 200, 200, 0, 1, 0);

    glLineWidth(6.0);
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(0.6,0.6,0.6);
    float rx=105;
    for(i=0; i<380; i=i+5)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.6-((float)abs(90-angle)/180),0.6-((float)abs(90-angle)/180),0.6-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 26 + rx* (float)cos(angle_radians);
            float z = 200 + rx* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }

    GLfloat vertices1[][3] =
    {
        {-170, -65, -400}, {560, -65, -400},
        {570, -55, -400}, {-180, -55, -400},
        {0, -65, 0}, {405, -65, 0},
        {390, -55, 0}, {10, -55, 0}
    };

    // Define cube faces
    GLint faces1[][4] =
    {
        {0, 1, 2, 3}, {1, 5, 6, 2},
        {4, 5, 6, 7}, {0, 4, 7, 3},
        {0, 1, 5, 4}, {3, 2, 6, 7}
    };

    // Draw cube
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++)
    {
        glColor3f(0.3+0.1*i, 0.3+0.1*i, 0.3+0.1*i);
        for (int j = 0; j < 4; j++)
        {
            glVertex3fv(vertices1[faces1[i][j]]);
        }
    }
    glEnd();


    GLfloat vertices2[][3] =
    {
        {-170, 325, -400}, {570, 325, -400},
        {580, 315, -400}, {-180, 315, -400},
        {0, 325, 0}, {405, 325, 0},
        {390, 315, 0}, {10, 315, 0}
    };

    // Define cube faces
    GLint faces2[][4] =
    {
        {0, 1, 2, 3}, {1, 5, 6, 2},
        {4, 5, 6, 7}, {0, 4, 7, 3},
        {0, 1, 5, 4}, {3, 2, 6, 7}
    };

    // Draw cube
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++)
    {
        glColor3f(0.3+0.1*i, 0.3+0.1*i, 0.3+0.1*i);
        for (int j = 0; j < 4; j++)
        {
            glVertex3fv(vertices2[faces2[i][j]]);
        }
    }
    glEnd();

    //draw 1st inner container
    float rx2=40;
    for(i=0; i<300; i=i+5)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.2-((float)abs(90-angle)/180),0.2-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = -20 + rx2* (float)cos(angle_radians);
            float z = 200 + rx2* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }

    // top cap
    float rx7 = 26;
    float z_center3 = 219;

    for (i = 0; i < 300; i += 5)
    {
        glBegin(GL_POLYGON);
        for (int angle = 0; angle <= 180; angle += 5)
        {
            glColor3f(0.8 - ((float)abs(50 - angle) / 380), 0.2 - ((float)abs(50 - angle) / 380), 0.2 - ((float)abs(50 - angle) / 380));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 61 + rx7 * (float)cos(angle_radians);
            float y = z_center3 + rx7 * (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x, y, 0);
        }
        glEnd();


    }

    // core
    float rx6=25;
    for(i=80; i<200; i=i+5)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.6-((float)abs(90-angle)/180),0.2-((float)abs(90-angle)/180),0.2-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = -20 + rx6* (float)cos(angle_radians);
            float z = 200 + rx6* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }

    // bottom plate
    float rx8=25;
    glBegin(GL_POLYGON);
    for( int angle=0; angle<=180; angle=angle+5)
    {
        glColor3f(0.6-((float)abs(90-angle)/180),0.2-((float)abs(90-angle)/180),0.2-((float)abs(90-angle)/180));
        float angle_radians = angle * (float)3.14159 / (float)180;
        float x = -20 + rx8* (float)cos(angle_radians);
        float z = 200 + rx8* (float)sin(angle_radians);
        glLineWidth(12.0);
        glVertex3f(x, 13,-z);
    }
    glEnd();

    // fuel rods
    float rx9=2;
    for(i=90; i<180; i=i+5)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=360; angle=angle+5)
        {
            glColor3f(0.7-((float)abs(180-angle)/360),0.5-((float)abs(180-angle)/360),0.7-((float)abs(180-angle)/360));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = -35 + rx9* (float)cos(angle_radians);
            float z = 200 + rx9* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }
    for(i=90; i<180; i=i+5)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=360; angle=angle+5)
        {
            glColor3f(0.7-((float)abs(180-angle)/360),0.5-((float)abs(180-angle)/360),0.7-((float)abs(180-angle)/360));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = -25 + rx9* (float)cos(angle_radians);
            float z = 200 + rx9* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }
    for(i=90; i<180; i=i+5)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=360; angle=angle+5)
        {
            glColor3f(0.7-((float)abs(180-angle)/360),0.5-((float)abs(180-angle)/360),0.7-((float)abs(180-angle)/360));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = -15 + rx9* (float)cos(angle_radians);
            float z = 200 + rx9* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }
    for(i=90; i<180; i=i+5)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=360; angle=angle+5)
        {
            glColor3f(0.7-((float)abs(180-angle)/360),0.5-((float)abs(180-angle)/360),0.7-((float)abs(180-angle)/360));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = -5 + rx9* (float)cos(angle_radians);
            float z = 200 + rx9* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }

    // control rods
    for(i=85; i<200; i=i+5)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=360; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(180-angle)/360),0.65-((float)abs(180-angle)/360),0.0-((float)abs(180-angle)/360));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = -30 + rx9* (float)cos(angle_radians);
            float z = 200 + rx9* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }
    for(i=85; i<200; i=i+5)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=360; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(180-angle)/360),0.65-((float)abs(180-angle)/360),0.0-((float)abs(180-angle)/360));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = -20 + rx9* (float)cos(angle_radians);
            float z = 200 + rx9* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }
    for(i=85; i<200; i=i+5)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=360; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(180-angle)/360),0.65-((float)abs(180-angle)/360),0.0-((float)abs(180-angle)/360));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = -10 + rx9* (float)cos(angle_radians);
            float z = 200 + rx9* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }


    // exchanger
    float rx3=30;
    for(i=80; i<300; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+1)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.5-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 80 + rx3* (float)cos(angle_radians);
            float z = 200 + rx3* (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }

    //top cap
    float rx4 = 19;
    float z_center1 = 219;

    for (i = 0; i < 300; i += 5)
    {
        glBegin(GL_POLYGON);
        for (int angle = 0; angle <= 180; angle += 5)
        {
            glColor3f(0.8 - ((float)abs(50 - angle) / 380), 0.5 - ((float)abs(50 - angle) / 380), 0.1 - ((float)abs(50 - angle) / 380));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 124 + rx4 * (float)cos(angle_radians);
            float y = z_center1 + rx4 * (float)sin(angle_radians);
            glLineWidth(12.0);
            glVertex3f(x, y, 0);
        }
        glEnd();
    }

    // bottom cap
    float rx5 = 19;
    float z_center2 = 87;

    for (i = 0; i < 300; i += 5)
    {
        glBegin(GL_POLYGON);
        for (int angle = 0; angle <= 180; angle += 5)
        {
            glColor3f(0.8 - ((float)abs(50 - angle) / 380), 0.5 - ((float)abs(50 - angle) / 380), 0.1 - ((float)abs(50 - angle) / 380));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 124 + rx5 * (float)cos(angle_radians);
            float y = z_center2 + rx5 * (float)sin(-angle_radians);
            glLineWidth(12.0);
            glVertex3f(x, y, 0);
        }
        glEnd();
    }

    // turbine room
    GLfloat vertices3[][3] =
    {
        {210, -65, -350}, {370, -65, -350},
        {370, 350, -350}, {210, 200, -350},
        {215, -65, -150}, {375, -65, -150},
        {375, 350, -150}, {215, 200, -150}
    };

    // Define cube faces
    GLint faces3[][4] =
    {
        {0, 1, 2, 3}, {1, 5, 6, 2},
        {0, 4, 7, 3},
        {0, 1, 5, 4}, {3, 2, 6, 7}
    };

    // Draw cube
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++)
    {
        glColor3f(0.3+0.1*i, 0.3+0.1*i, 0.3+0.1*i);
        for (int j = 0; j < 4; j++)
        {
            glVertex3fv(vertices3[faces3[i][j]]);
        }
    }
    glEnd();

//pump1
// Set up lighting and materials
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_position[] = { 100.0f, 100.0f, 100.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    GLfloat ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat shininess[] = { 100.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

// ring1
    GLdouble torusRadius = 15;
    GLdouble tubeRadius = 5;
    GLint nsides = 200;//default: 200
    GLint rings = 200;

    glPushMatrix();
    glTranslatef(50, -35, -200);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(tubeRadius, torusRadius, nsides, rings);
    glPopMatrix();

// ring2
    GLdouble torusRadius2 = 15;
    GLdouble tubeRadius2 = 5;
    GLint nsides2 = 200;
    GLint rings2 = 200;

    glPushMatrix();
    glTranslatef(100, -35, -200);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(tubeRadius2, torusRadius2, nsides2, rings2);
    glPopMatrix();


//cylinder body
    GLUquadricObj* quadratic;
    quadratic = gluNewQuadric();
    gluQuadricNormals(quadratic, GLU_SMOOTH);
    gluQuadricTexture(quadratic, GL_TRUE);
    glPushMatrix();
    glTranslatef(50, -35, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic, 15, 15, 50.0f, 32, 32);
    glPopMatrix();
    gluDeleteQuadric(quadratic);

// Disable lighting
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

//pump2
// Set up lighting and materials
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_position2[] = { 100.0f, 100.0f, 100.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position2);
    GLfloat ambient2[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse2[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat shininess2[] = { 100.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient2);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse2);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular2);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess2);

    // ring1
    GLdouble torusRadius3 = 15;
    GLdouble tubeRadius3 = 5;
    GLint nsides3 = 200;
    GLint rings3 = 200;

    glPushMatrix();
    glTranslatef(145, 100, -200);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(tubeRadius3, torusRadius3, nsides3, rings3);
    glPopMatrix();

// ring2
    GLdouble torusRadius4 = 15;
    GLdouble tubeRadius4 = 5;
    GLint nsides4 = 200;
    GLint rings4 = 200;

    glPushMatrix();
    glTranslatef(185, 100, -200);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(tubeRadius4, torusRadius4, nsides4, rings4);
    glPopMatrix();

// cylinder body
    GLUquadricObj* quadratic2;
    quadratic2 = gluNewQuadric();
    gluQuadricNormals(quadratic2, GLU_SMOOTH);
    gluQuadricTexture(quadratic2, GL_TRUE);
    glPushMatrix();
    glTranslatef(145, 100, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic, 15, 15, 40.0f, 32, 32);
    glPopMatrix();
    gluDeleteQuadric(quadratic2);

    // Disable lighting
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    // generator room
    GLfloat vertices4[][3] =
    {
        {370, 50, -350}, {450, 50, -350},
        {450, 350, -350}, {370, 350, -350},
        {375, 50, -150}, {455, 50, -150},
        {455, 350, -150}, {375, 350, -150}
    };

    // Define cube faces
    GLint faces4[][4] =
    {
        {0, 1, 2, 3}, {1, 5, 6, 2},
        {0, 4, 7, 3},
        {0, 1, 5, 4}, {3, 2, 6, 7}
    };

    // Draw cube
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++)
    {
        glColor3f(0.3+0.1*i, 0.3+0.1*i, 0.3+0.1*i);
        for (int j = 0; j < 4; j++)
        {
            glVertex3fv(vertices4[faces4[i][j]]);
        }
    }
    glEnd();


// Set up lighting and materials
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_position3[] = { 100.0f, 100.0f, 100.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position3);
    GLfloat ambient3[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse3[] = { 0.7f, 0.7f, 0.8f, 1.0f };
    GLfloat specular3[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat shininess3[] = { 80.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient3);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse3);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular3);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess3);

    //generator shaft
    GLUquadricObj* quadratic3;
    quadratic3 = gluNewQuadric();
    gluQuadricNormals(quadratic3, GLU_SMOOTH);
    gluQuadricTexture(quadratic3, GL_TRUE);
    glPushMatrix();
    glTranslatef(215, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic3, 15, 15, 240.0f, 32, 32);
    glPopMatrix();

//    turbine
    GLUquadricObj* quadratic4;
    quadratic4 = gluNewQuadric();
    gluQuadricNormals(quadratic4, GLU_SMOOTH);
    gluQuadricTexture(quadratic4, GL_TRUE);

//    blade1
    glPushMatrix();
    glTranslatef(230, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic4, 35, 45, 15, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(230, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic, 0.0, 35, 32, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(245, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic, 0.0, 45, 32, 1);
    glPopMatrix();

//    blade 2
    GLUquadricObj* quadratic5;
    quadratic5 = gluNewQuadric();
    gluQuadricNormals(quadratic5, GLU_SMOOTH);
    gluQuadricTexture(quadratic5, GL_TRUE);
    glPushMatrix();
    glTranslatef(260, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic5, 45, 55, 15, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(260, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic, 0.0, 45, 32, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(275, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic, 0.0, 55, 32, 1);
    glPopMatrix();

//    blade3
    GLUquadricObj* quadratic6;
    quadratic6 = gluNewQuadric();
    gluQuadricNormals(quadratic6, GLU_SMOOTH);
    gluQuadricTexture(quadratic6, GL_TRUE);
    glPushMatrix();
    glTranslatef(290, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic6, 55, 65, 15, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(290, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic, 0.0, 55, 32, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic, 0.0, 65, 32, 1);
    glPopMatrix();


//    blade4

    GLUquadricObj* quadratic7;
    quadratic7 = gluNewQuadric();
    gluQuadricNormals(quadratic7, GLU_SMOOTH);
    gluQuadricTexture(quadratic7, GL_TRUE);
    glPushMatrix();
    glTranslatef(320, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic7, 65, 75, 15, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic, 0.0, 65, 32, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic, 0.0, 75, 32, 1);
    glPopMatrix();

//    joint1
    GLUquadricObj* quadratic8;
    quadratic8 = gluNewQuadric();
    gluQuadricNormals(quadratic8, GLU_SMOOTH);
    gluQuadricTexture(quadratic8, GL_TRUE);
    glPushMatrix();
    glTranslatef(245, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic8, 25, 25, 15, 4, 32);
    glPopMatrix();

//    joint2
    GLUquadricObj* quadratic9;
    quadratic9 = gluNewQuadric();
    gluQuadricNormals(quadratic9, GLU_SMOOTH);
    gluQuadricTexture(quadratic9, GL_TRUE);
    glPushMatrix();
    glTranslatef(275, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic9, 35, 35, 15, 4, 32);
    glPopMatrix();

//    joint3
    GLUquadricObj* quadratic10;
    quadratic10 = gluNewQuadric();
    gluQuadricNormals(quadratic10, GLU_SMOOTH);
    gluQuadricTexture(quadratic10, GL_TRUE);
    glPushMatrix();
    glTranslatef(305, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic10, 45, 45, 15, 4, 32);
    glPopMatrix();

    // Disable lighting
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);


//Pipes
    float rx10=6;
    for(i=40; i<115; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 125 + rx10* (float)cos(angle_radians);
            float z = 200 + rx10* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-65+i,-z);
        }
        glEnd();
    }

    float rx11=10;
    for(i=-65; i<130; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = -35 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }

    for(i=23; i<230; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = -69 + rx10* (float)cos(angle_radians);
            float z = 200 + rx10* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

    for(i=-75; i<-45; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = 155 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }

    for(i=0; i<76; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = 210 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }

    for(i=105; i<290; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 80 + rx10* (float)cos(angle_radians);
            float z = 200 + rx10* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

    for(i=75; i<120; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = 40 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }

    for(i=100; i<195; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = 100 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }

    for(i=50; i<180; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 200 + rx10* (float)cos(angle_radians);
            float z = 200 + rx10* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

    for(i=195; i<245; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = -30 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }

    //steam carrier
    float rx12 = 15;
    for(i=100; i<155; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = 210 + rx12* (float)cos(angle_radians);
            float z = 200 + rx12* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y, -z);
        }
        glEnd();
    }

    for(i=160; i<340; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = 30 + rx12* (float)cos(angle_radians);
            float z = 200 + rx12* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }


    for(i=83; i<295; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 165 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

//    steam out
    for(i=83; i<150; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 240 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

    for(i=83; i<140; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 270 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

    for(i=83; i<130; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 300 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

    for(i=83; i<120; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 330 + rx11* (float)cos(angle_radians);
            float z = 200 + rx11* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

//    to condensor
    float rx13 = 20;
    for(i=370; i<580; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 350 + rx13 * (float)cos(angle_radians);
            float z = 300 + rx13 * (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

    for(i=370; i<580; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 350 + rx13 * (float)cos(angle_radians);
            float z = 200 + rx13 * (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

// from condensor
    for(i=300; i<595; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = -35 + rx13* (float)cos(angle_radians);
            float z = 200 + rx13* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }

    for(i=300; i<595; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = -35 + rx13* (float)cos(angle_radians);
            float z = 250 + rx13* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }

    for(i=50; i<500; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 500 + rx13*0.60 * (float)cos(angle_radians);
            float z = 200 + rx13*0.60 * (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

    for(i=50; i<500; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 500 + rx13*0.60 * (float)cos(angle_radians);
            float z = 250 + rx13*0.60 * (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

    for(i=430; i<515; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = 405 + rx13* (float)cos(angle_radians);
            float z = 200 + rx13* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }

    for(i=430; i<515; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.1-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = 405 + rx13* (float)cos(angle_radians);
            float z = 250 + rx13* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }

//    cooling tower
    float rx14 = 850;
    for(i=400; i<800; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.8-((float)abs(90-angle)/180),0.8-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 350 + pow(rx14, (800-i*0.55)/800) * (float)cos(angle_radians);
            float z = 200 + pow(rx14, (800-i*0.55)/800) * (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

    for(i=450; i<800; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            glColor3f(0.8-((float)abs(90-angle)/180),0.8-((float)abs(90-angle)/180),0.8-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 350 + pow(rx14, (800-i*0.55)/800) * (float)cos(angle_radians);
            float z = 250 + pow(rx14, (800-i*0.55)/800) * (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z);
        }
        glEnd();
    }

//    external pumps
//pump1
// Set up lighting and materials
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_position4[] = { 100.0f, 100.0f, 100.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position4);
    GLfloat ambient4[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse4[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular4[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat shininess4[] = { 100.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient4);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse4);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular4);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess4);

// ring1
    GLdouble torusRadius5 = 25;
    GLdouble tubeRadius5 = 4;
    GLint nsides5 = 200;//default: 200
    GLint rings5 = 200;

    glPushMatrix();
    glTranslatef(480, -35, -200);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(tubeRadius5, torusRadius5, nsides5, rings5);
    glPopMatrix();

// ring2
    GLdouble torusRadius6 = 25;
    GLdouble tubeRadius6 = 4;
    GLint nsides6 = 200;
    GLint rings6 = 200;

    glPushMatrix();
    glTranslatef(530, -35, -200);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(tubeRadius6, torusRadius6, nsides6, rings6);
    glPopMatrix();


//cylinder body
    GLUquadricObj* quadratic11;
    quadratic11 = gluNewQuadric();
    gluQuadricNormals(quadratic11, GLU_SMOOTH);
    gluQuadricTexture(quadratic11, GL_TRUE);
    glPushMatrix();
    glTranslatef(480, -35, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic11, 30, 30, 50.0f, 32, 32);
    glPopMatrix();
    gluDeleteQuadric(quadratic11);

// ring3
    GLdouble torusRadius9 = 16;
    GLdouble tubeRadius9 = 4;
    GLint nsides9 = 200;
    GLint rings9 = 200;

    glPushMatrix();
    glTranslatef(500, 40, -200);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(tubeRadius9, torusRadius9, nsides9, rings9);
    glPopMatrix();

//cylinder body
    GLUquadricObj* quadratic13;
    quadratic13 = gluNewQuadric();
    gluQuadricNormals(quadratic13, GLU_SMOOTH);
    gluQuadricTexture(quadratic13, GL_TRUE);
    glPushMatrix();
    glTranslatef(500, -10, -200);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic13, 16, 16, 50.0f, 32, 32);
    glPopMatrix();
    gluDeleteQuadric(quadratic13);

// Disable lighting
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

//pump2
// Set up lighting and materials
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_position5[] = { 100.0f, 100.0f, 100.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position5);
    GLfloat ambient5[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse5[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular5[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat shininess5[] = { 100.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient5);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse5);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular5);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess5);

// ring1
    GLdouble torusRadius7 = 25;
    GLdouble tubeRadius7 = 4;
    GLint nsides7 = 200;
    GLint rings7 = 200;

    glPushMatrix();
    glTranslatef(480, -35, -250);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(tubeRadius7, torusRadius7, nsides7, rings7);
    glPopMatrix();

// ring2
    GLdouble torusRadius8 = 25;
    GLdouble tubeRadius8 = 4;
    GLint nsides8 = 200;
    GLint rings8 = 200;

    glPushMatrix();
    glTranslatef(530, -35, -250);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(tubeRadius8, torusRadius8, nsides8, rings8);
    glPopMatrix();


//cylinder body
    GLUquadricObj* quadratic12;
    quadratic12 = gluNewQuadric();
    gluQuadricNormals(quadratic12, GLU_SMOOTH);
    gluQuadricTexture(quadratic12, GL_TRUE);
    glPushMatrix();
    glTranslatef(480, -35, -250);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic12, 30, 30, 50.0f, 32, 32);
    glPopMatrix();
    gluDeleteQuadric(quadratic12);

// ring3
    GLdouble torusRadius10 = 16;
    GLdouble tubeRadius10 = 4;
    GLint nsides10 = 200;
    GLint rings10 = 200;

    glPushMatrix();
    glTranslatef(500, 40, -250);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(tubeRadius10, torusRadius10, nsides10, rings10);
    glPopMatrix();

//cylinder body
    GLUquadricObj* quadratic14;
    quadratic14 = gluNewQuadric();
    gluQuadricNormals(quadratic14, GLU_SMOOTH);
    gluQuadricTexture(quadratic14, GL_TRUE);
    glPushMatrix();
    glTranslatef(500, -10, -250);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic14, 16, 16, 50.0f, 32, 32);
    glPopMatrix();
    gluDeleteQuadric(quadratic14);

    // Disable lighting
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);


//    water
// reactor
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glTranslatef(-18, 230, -200);
    glRotatef(90, 1, 0, 0);

    glColor4f(0.5f, 0.5f, 1.0f, 0.4f); // blue color with alpha value of 0.5

    GLUquadricObj* cylinder = gluNewQuadric();
    gluQuadricNormals(cylinder, GLU_SMOOTH);
    gluQuadricTexture(cylinder, GL_FALSE);
    gluQuadricDrawStyle(cylinder, GLU_FILL);

//    gluDisk(cylinder, 0.0f, 100.0f, 32, 1);
    gluCylinder(cylinder, 37.0f, 37.0f, 285.0f, 32, 1);
//    glTranslatef(80, 85, -200);
//    gluDisk(cylinder, 0.0f, 1.0f, 32, 1);

    gluDeleteQuadric(cylinder);
    glPopMatrix();
    glDisable(GL_BLEND);


// exchanger
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glTranslatef(80, 170, -200);
    glRotatef(90, 1, 0, 0);

    glColor4f(0.1f, 0.4f, 1.0f, 0.6f);

    GLUquadricObj* cylinder2 = gluNewQuadric();
    gluQuadricNormals(cylinder2, GLU_SMOOTH);
    gluQuadricTexture(cylinder2, GL_FALSE);
    gluQuadricDrawStyle(cylinder2, GLU_FILL);

    gluCylinder(cylinder2, 28.0f, 28.0f, 140.0f, 32, 1);

    gluDeleteQuadric(cylinder2);
    glPopMatrix();
    glDisable(GL_BLEND);


// cooling tower
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glColor4f(0.1f, 0.4f, 1.0f, 0.6f);

    glColor4f(0.1f, 0.4f, 1.0f, 0.6f);
    for(i=450; i<800; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 350 + pow(rx14-50, (800-i*0.55)/800) * (float)cos(angle_radians);
            float z = 250 + pow(rx14-50, (800-i*0.55)/800) * (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z+1);
        }
        glEnd();
    }

    for(i=400; i<500; i=i+1)
    {
        glBegin(GL_POLYGON);
        for( int angle=0; angle<=180; angle=angle+5)
        {
            float angle_radians = angle * (float)3.14159 / (float)180;
            float x = 350 + pow(rx14-50, (800-i*0.55)/800) * (float)cos(angle_radians);
            float z = 200 + pow(rx14-50, (800-i*0.55)/800) * (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(x,-70+i,-z+1);
        }
        glEnd();
    }

    glPopMatrix();
    glDisable(GL_BLEND);

// turbine room
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glColor4f(0.1f, 0.4f, 1.0f, 0.6f);

    GLfloat vertices5[][3] =
    {
        {210, -65, -350}, {370, -65, -350},
        {370, -20, -350}, {210, -20, -350},
        {215, -65, -150}, {375, -65, -150},
        {375, -20, -150}, {215, -20, -150}
    };

    GLint faces5[][4] =
    {
        {0, 1, 2, 3}, {1, 5, 6, 2},
        {0, 4, 7, 3}, {4, 5, 6, 7},
        {0, 1, 5, 4}, {3, 2, 6, 7}
    };

    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            glVertex3fv(vertices5[faces5[i][j]]);
        }
    }
    glEnd();

    glPopMatrix();
    glDisable(GL_BLEND);


//    generator
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_position6[] = { 100.0f, 100.0f, 100.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position6);
    GLfloat ambient6[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse6[] = { 0.8f, 0.0f, 0.0f, 0.75f };
    GLfloat specular6[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat shininess6[] = { 100.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient6);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse6);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular6);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess6);

    // armature
    GLUquadricObj* quadratic15;
    quadratic15 = gluNewQuadric();
    gluQuadricNormals(quadratic15, GLU_SMOOTH);
    gluQuadricTexture(quadratic15, GL_TRUE);

    // set1
    glPushMatrix();
    glTranslatef(400, 135, -200);

    glRotatef(0, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(45, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(90, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(135, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(180, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);


    glRotatef(225, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(270, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(315, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glPopMatrix();

    // set2
    glPushMatrix();
    glTranslatef(420, 135, -200);

    glRotatef(0, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(45, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(90, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(135, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(180, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);


    glRotatef(225, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(270, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(315, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glPopMatrix();

    // set3
    glPushMatrix();
    glTranslatef(440, 135, -200);

    glRotatef(0, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(45, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(90, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(135, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(180, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);


    glRotatef(225, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(270, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glRotatef(315, 1, 0, 0);
    gluCylinder(quadratic15, 5, 10, 40.0f, 6, 32);

    glPopMatrix();



//  magnets
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(0.1f, 0.1f, 0.1f, 0.99);

    gluQuadricNormals(quadratic15, GLU_SMOOTH);
    gluQuadricTexture(quadratic15, GL_FALSE);
    gluQuadricDrawStyle(quadratic15, GLU_FILL);

    // set1
    glPushMatrix();
    glTranslatef(395, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic15, 50.0, 65, 32, 1);
    gluCylinder(quadratic15, 65, 65, 10.0f, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(405, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic15, 50.0, 65, 32, 1);
    glPopMatrix();

    // set2
    glPushMatrix();
    glTranslatef(415, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic15, 50.0, 65, 32, 1);
    gluCylinder(quadratic15, 65, 65, 10.0f, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(425, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic15, 50.0, 65, 32, 1);
    glPopMatrix();

    // set3
    glPushMatrix();
    glTranslatef(435, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic15, 50.0, 65, 32, 1);
    gluCylinder(quadratic15, 65, 65, 10.0f, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(445, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluDisk(quadratic15, 50.0, 65, 32, 1);
    glPopMatrix();

    glDisable(GL_BLEND);

    // Disable lighting
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

//    motor shaft
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(390, 135, -200);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadratic3, 16, 16, 60.0f, 32, 32);
    glPopMatrix();

    gluDeleteQuadric(quadratic15);

//    casing
    float rx15=68;
    for(i=376; i<450; i=i+1)
    {
        glBegin(GL_LINE_STRIP);
        for( int angle=-45; angle<=225; angle=angle+5)
        {
            glColor3f(0.1-((float)abs(90-angle)/180),0.3-((float)abs(90-angle)/180),0.8-((float)abs(90-angle)/180));
            float angle_radians = angle * (float)3.14159 / (float)180;
            float y = 135 + rx15* (float)cos(angle_radians);
            float z = 200 + rx15* (float)sin(angle_radians);
            glLineWidth(1.0);
            glVertex3f(i, y,-z);
        }
        glEnd();
    }






    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1400, 700);
    glutCreateWindow("Line");

    glEnable(GL_DEPTH_TEST);
    gluOrtho2D(0.0,400.0,0.0,300.0);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
