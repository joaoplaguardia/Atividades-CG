#include <GL/glut.h>
#include <stdio.h>

GLint tx, ty, angulo;
GLfloat ex,ey;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     //cor da linha
     glColor3f(0.0f, 0.0f, 0.0f);
     
     //espessura da linha
    glLineWidth(3);

     //desenha a linha horizontal
     glBegin(GL_LINES);
     glVertex2i(0,200);
     glVertex2i(0,-200);
     glEnd();

     //desenha a linha vertical
     glBegin(GL_LINES);
     glVertex2i(200,0);
     glVertex2i(-200,0);
     glEnd();

     // Especifica que a cor corrente é vermelha
     //         R     G     B
     //glTranslatef(-100.0f, -50.0f, 0.0f);
     glTranslatef(tx, ty, 0);
     glScalef(ex, ey, 1);
     glRotatef(angulo, 0, 0, 1);

     glColor3f(1.0f, 0.0f, 0.0f);


    

    // Desenha uma casa 
   
     glBegin(GL_TRIANGLES);
     glColor3f(0.0f, 0.0f, 1.0f);
     glVertex2i(50,100);
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2i(100,150);
     glColor3f(0.0f, 0.0f, 1.0f);
     glVertex2i(150,100);
     glEnd();
     glBegin(GL_LINE_LOOP);
     glVertex2i(50,1);
     glVertex2i(50,99);
     glVertex2i(150,99);
     glVertex2i(150,1);
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

void TeclasEspeciais(int key, int x, int y)
{ switch (key) {
     case GLUT_KEY_PAGE_UP:
     angulo+=1;
     break;
     case GLUT_KEY_PAGE_DOWN:
     angulo-=1;
     break;
     case GLUT_KEY_HOME:
     ex+=0.1; ey+=0.1;
     break;
     case GLUT_KEY_END:
     ex-=0.1; ey-=0.1;
     break;
     case GLUT_KEY_UP:
     ty+=5;
     break;
     case GLUT_KEY_DOWN:
     ty-=5;
     break;
     case GLUT_KEY_LEFT:
     tx-=5;
     break;
     case GLUT_KEY_RIGHT:
     tx+=5;
     break;
     }
     glutPostRedisplay();
}
// Inicializa parâmetros de rendering
void Inicializa (void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
    tx = ty = angulo = 0;
     ex = ey = 1;
}


// Programa Principal
int main(int argc, char ** argv)
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(400,350);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Casa");
     glutDisplayFunc(Desenha);
     glutSpecialFunc(TeclasEspeciais);
     Inicializa();
     glutMainLoop();
}
