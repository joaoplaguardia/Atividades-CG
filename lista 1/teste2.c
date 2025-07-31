#include <GL/glew.h>
#include <GL/freeglut.h>

void display() {
    glLineWidth(3.0f);
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0f, 1.0f);
    glColor3f(0.8f, 0.2f, 0.0f);
    glVertex2f(-0.3f, 0.1f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, -0.6f);
    glColor3f(0.5f, 0.0f, 0.7f);
    glVertex2f(0.0f, -0.3f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.8f, -0.6f);
    glColor3f(0.0f, 0.8f, 0.2f);
    glVertex2f(0.3f, 0.1f);
    glEnd();
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("OpenGL - Estrela de 3 pontas");
    glewInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
