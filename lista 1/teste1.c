#include <GL/glew.h>
#include <GL/freeglut.h>

void display() {
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glRotatef(45, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3f, 0.0f, 0.0f);
    glRotatef(45, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3f, 0.0f, 0.0f);
    glRotatef(45, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.49f, 0.0f);
    glRotatef(45, 0.0f, 0.0f, 1.0f);    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL - Quadrados Rotacionados");
    glewInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
