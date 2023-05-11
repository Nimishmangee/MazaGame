#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <GL/glut.h>
#include<math.h>
#include<vector>
#include <unistd.h>
#include<time.h>
#define pie 3.14

using namespace std;

int WIDTH = 800;
int HEIGHT = 800;
int regionX = 700;
int regionY = 700;
int regionWidth = 80;
int regionHeight = 50;

void init(){
    glClearColor(21 / 255.0, 14 / 255.0, 65 / 255.0, 1.0);
    gluOrtho2D(0, 800-1, 0, 800-1);
    
}

void display_text(string s, float  x=0, float y=0, float size=0.35){
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1, 1, 1);
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0,WIDTH-1,0,HEIGHT-1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(WIDTH*x, HEIGHT *y, 0);
    glScalef(size, size, 1);
    
    // Draw the outline/stroke
    glLineWidth(2.5);
    glColor3f(1.0, 1.0, 1.0);
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            glPushMatrix();
            glTranslatef(i, j, 0);
            for (char* p = &s[0]; *p; p++) {
                glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
            }
            glPopMatrix();
        }
    }

    // Draw the actual text
    glColor3f(1.0f, 1.0f, 1.0f);
    for (char* p = &s[0]; *p; p++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    }
    
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glDisable(GL_COLOR_MATERIAL);
    
    glDisable(GL_COLOR_MATERIAL);
}

void xAndyAxis(){
        //x
        glColor3ub(254, 0, 0);
        glBegin(GL_LINES);
        glVertex2f(-150.0, 0.0);
        glVertex2f(150, 0.0);
        glEnd();
    
        //y
        glColor3ub(200, 255, 0);
        glBegin(GL_LINES);
        glVertex2f(0.0,-150);
        glVertex2f(0.0,150);
        glEnd();

}

void stars(int x, int y){
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3ub(192, 192, 192);
    glVertex3f(x,y, 0);
    glEnd();

}
//************************ MAIN DISPLAY FUNCTION ****************************

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    xAndyAxis();
    
    glFlush();
}

//************************ SECOND DISPLAY FUNCTION ****************************
void introductionPage(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    //Play button
    glBegin(GL_QUADS);
    glColor3ub(48,201,114);
    glVertex2f(300, 550);
    glVertex2f(500, 550);
    glColor3ub(35,210,90);
    glVertex2f(500, 650);
    glVertex2f(300, 650);
    glEnd();
    
    
    //Instructions button
    glBegin(GL_QUADS);
    glColor3ub(36,167,239);
    glVertex2f(300, 400);
    glVertex2f(500, 400);
    glColor3ub(88,188,235);
    glVertex2f(500, 500);
    glVertex2f(300, 500);
    glEnd();
    
    //Credits button
    glBegin(GL_QUADS);
    glColor3ub(239,160,23);
    glVertex2f(300, 250);
    glVertex2f(500, 250);
    glColor3ub(241,195,1);
    glVertex2f(500, 350);
    glVertex2f(300, 350);
    glEnd();
    
    //Exit Button
    glBegin(GL_QUADS);
    glColor3ub(210,71,40);
    glVertex2f(300, 100);
    glVertex2f(500, 100);
    glColor3ub(246,91,66);
    glVertex2f(500, 200);
    glVertex2f(300, 200);
    glEnd();
    
    display_text("WELCOME TO MAZE TANK", 0.15, 0.91);
    display_text("PLAY", 0.42, 0.72);
    display_text("RULES", 0.41, 0.535);
    display_text("CREDITS", 0.39, 0.35);
    display_text("EXIT", 0.45, 0.16);
    display_text("Enter the Maze and defeat your digital opponent", 0.20, 0.06, 0.15);
    display_text("in the ultimate tank strategy game!", 0.30, 0.02, 0.15);
    
    int l=0, u=800;
    srand(time(0));
    
    for (int i = 0; i < 100; i++) {
        int num1 = (rand() % (u - l + 1)) + l;
        int num2 = (rand() % (u - l + 1)) + l;
        
        stars(num1, num2);
    }

    glFlush();
}

void popupWindowCredits(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glColor3f(0.0, 0.0, 0.0); // White color
    glRasterPos2f(0.1, 0.85);
    string team="TEAM MEMBERS";
    for(auto c:team)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
    
    glRasterPos2f(0.1, 0.7);
    string name2="1. Jannardhan Reddy S.(20BCS062)";
    for(auto c:name2)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    
    glRasterPos2f(0.1, 0.5);
    string name1="2. Nimish Mangee(20BCS094)";
    for(auto c:name1)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    
    glRasterPos2f(0.1, 0.3);
    string name3="3. Somisetty Sai Praneeth(20BCS125)";
    for(auto c:name3)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    
    glRasterPos2f(0.1, 0.1);
    string name4="4. Sri Hari L(20BCS129)";
    for(auto c:name4)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    
    
    glFlush();
}

void creditsPopup(){
    glutInitWindowSize(500, 200);
    glutInitWindowPosition(130S0, 400);
    int window = glutCreateWindow("Creators of The Maze Tank Game");
    gluOrtho2D(0, 1, 0, 1);
    glClearColor(0.37,0.74,0.92,1.0);
    
    glutDisplayFunc(popupWindowCredits);
}

void popupWindowRules(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glColor3f(0.0, 0.0, 0.0); // White color
    glRasterPos2f(0.1, 0.9);

    string rule1="- > HOW TO PLAY";
    for(auto c:rule1)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
    
    glRasterPos2f(0.1, 0.8);
    string rule2="(1) MOVE TANK: ";
    for(auto c:rule2)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    
    glRasterPos2f(0.15, 0.77);
    string rule3="(a) up arrow: move upword ";
    for(auto c:rule3)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);

    glRasterPos2f(0.15, 0.74);
    string rule4="(b) down arrow: move downwards " ;
    for(auto c:rule4)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);

    glRasterPos2f(0.15, 0.71);   
    string rule5="(c) left arrow: move left ";
    for(auto c:rule5)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
     glRasterPos2f(0.15, 0.68);
    string rule6="(d) right arrow: move right ";
    for(auto c:rule6)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);

    glRasterPos2f(0.1, 0.64);
    string rule7="(2) MOVE BOARD:";
    for(auto c:rule7)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);

    glRasterPos2f(0.15, 0.61);
    string rule8="(a) I: turns upward  ";
    for(auto c:rule8)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);

    glRasterPos2f(0.15, 0.58);
	string rule9="(b) J: turns left ";
    for(auto c:rule9)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);

      glRasterPos2f(0.15, 0.55);
        string rule10="(c) K: turns downward ";
    for(auto c:rule10)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);

      glRasterPos2f(0.15, 0.52);
	string rule11="(d) L: turns right ";
    for(auto c:rule11)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);

    glRasterPos2f(0.1, 0.47);
    string rule12="(3) ZOOM: ";
    for(auto c:rule12)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);

     glRasterPos2f(0.15, 0.44);
    string rule13="(a) +: zoom in ";
    for(auto c:rule13)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
        
    glRasterPos2f(0.15, 0.41);
        string rule14="(b) -: zoom out  ";
    for(auto c:rule14)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);

    glRasterPos2f(0.1, 0.36);
    string rule15="(4) SHOOT";
    for(auto c:rule15)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);

    glRasterPos2f(0.15, 0.33);
    string rule16="press *Space Bar* to shoot. ";
    for(auto c:rule16)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
        
      glRasterPos2f(0.1, 0.28);
    string rule17="(5) PRESS 'Esc' TO EXIT THE GAME";
    for(auto c:rule17)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
    
    glFlush();
} 
void rulesPopup(){
    glutInitWindowSize(500, 800);
    glutInitWindowPosition(100, 120);
    int window = glutCreateWindow("How to Play?");
    gluOrtho2D(0, 1, 0, 1);
    glClearColor(0.37,0.74,0.92,1.0);
    
    glutDisplayFunc(popupWindowRules);
}

void keyboard(unsigned char key, int x, int y){}

void mouse(int button, int state, int x, int y){
    int width=glutGet(GLUT_WINDOW_WIDTH);
    int height=glutGet(GLUT_WINDOW_HEIGHT);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        if(x>=0.375*width and x<=0.625*width and y>0.1875*height and y<=0.3125*height)
            system("./main");
        
        else if(x>=0.375*width and x<=0.625*width and y>=0.375*height and y<=0.5*height)
            rulesPopup();
        
        else if(x>=0.375*width and x<=0.625*width and y>=0.5625*height and y<=0.6875*height)
            creditsPopup();
        
        else if(x>=0.375*width and x<=0.625*width and y>=0.75*height and y<=0.875*height)
            exit(1);
    }
}

int main(int argc,char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    //glutInitWindowPosition(10,10);
    //glutInitWindowSize(1920, 1080);
    glutCreateWindow("Game Begins");
    glutFullScreen();
    init();
    glutDisplayFunc(introductionPage);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

