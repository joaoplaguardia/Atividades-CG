#include <GL/glut.h>

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
     

     //desenha a linha vertical
     

     // Especifica que a cor corrente é vermelha
     //         R     G     B
    glColor3f(1.0f, 0.0f, 0.0f);


    

    // Desenha uma casa 
   


     // Executa os comandos OpenGL
     glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
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
     Inicializa();
     glutMainLoop();
}
