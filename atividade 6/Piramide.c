#include <GL/glut.h>
#include <stdio.h>

GLfloat rx, ry, rz;
GLfloat tx, ty, tz;
int ex, ey, ez;

void AlteraTamanhoJanela(int width, int height) {
    if (height == 0) height = 1;  // Evita divisão por zero
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (GLfloat)width / (GLfloat)height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void inicializa() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_NEVER);
    
    tx = ty = tz = 0;
    rx = 15;
    ry = -45;
    rz = 15;
    ex = 1;
    ey = ez = 0;
    
    printf("Inicialização concluída.\n"); // Verifica se o printf funciona
}

void desenha() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Reseta a matriz de modelagem

    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(rx, 1.0f, 0.0f, 0.0f);
    glRotatef(ry, 0.0f, 1.0f, 0.0f);
    glRotatef(rz, 0.0f, 0.0f, 1.0f);
    glTranslatef(tx, ty, tz);

    // Desenha a pirâmide
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.8, 0.0, 0.0);
        glVertex3d(0.3, 0.6, 0.3);
        glVertex3d(0.3, 0.0, 0.0);
        glVertex3d(0.0, 0.0, 0.6);        
        glVertex3d(0.6, 0.0, 0.6);
        glVertex3d(0.3, 0.0, 0.0);
    glEnd();
       
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex3d(0.3, 0.0, 0.0);
        glVertex3d(0.0, 0.0, 0.6);
        glVertex3d(0.6, 0.0, 0.6);
    glEnd();

    glutSwapBuffers();
}

void teclasEspecias(int key, int x, int y) {
    printf("Teclas especiais\n %d %d %d \n", ex, ey, ez);
    switch(key) {
        case GLUT_KEY_DOWN:
            if (ex) rx -= 5; else if (ey) ry -= 5; else if (ez) rz -= 5;
            break;
        case GLUT_KEY_UP:
            if (ex) rx += 5; else if (ey) ry += 5; else if (ez) rz += 5;
            break;
        case GLUT_KEY_LEFT:
            if (ex) tx -= 0.2; else if (ey) ty -= 0.2; else if (ez) tz -= 0.2;
            break;
        case GLUT_KEY_RIGHT:
            if (ex) tx += 0.2; else if (ey) ty += 0.2; else if (ez) tz += 0.2;
            break;   
    }
    glutPostRedisplay();
}

void teclado(unsigned char key, int x, int y) {
    switch (key) {
        case 'x':
        case 'X':
            ex = 1; ey = ez = 0;
            break;
        case 'y':
        case 'Y':
            ey = 1; ex = ez = 0;
            break;
        case 'z':
        case 'Z':
            ez = 1; ey = ex = 0;
            break;
    }
    printf("Teclado\n %d %d %d \n", ex, ey, ez);
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(450, 450);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Pirâmides");
    inicializa();
    glutDisplayFunc(desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(teclasEspecias);
    glutMainLoop();
    return 0;
}
