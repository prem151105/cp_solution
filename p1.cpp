#include <GL/glut.h>

void plot(int xc,int yc,int x,int y){
    glVertex2i(xc+x,yc+y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc-y);
    glVertex2i(xc+y,yc+x);
    glVertex2i(xc-y,yc+x);
    glVertex2i(xc+y,yc-x);
    glVertex2i(xc-y,yc-x);
}
void circle(int xc,int yc,int r){
    int x=0,y=r;
    int p=1-r;
    glBegin(GL_POINTS);
    while(x<=y){
        x++;
        if(p<0){
            p+=2*x+1;
        }
        else{
            y--;
            p+=2*x-2*y+1;
        }
        plot(xc,yc,x,y);
    }
    glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    circle(250,250,100);
    glFlush();
}
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Circle");
    gluOrtho2D(0,500,0,500);
    glutDisplayFunc(display);
    glutMainLoop();
}