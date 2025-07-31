// TeaPot3D.c - Isabel H. Manssour
// Um programa OpenGL que exemplifica a visualização
// de objetos 3D.
// Este código está baseado nos exemplos disponíveis no livro
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

GLdouble obsX=0, obsY=0, obsZ=200; //acrescente esta linha

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posição do observador e do alvo
                gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
}
void teclasEspeciais(int key, int x, int y){
	switch (key) {
	case GLUT_KEY_LEFT : obsX -=10; break;
	case GLUT_KEY_RIGHT : obsX +=10; break;
	case GLUT_KEY_UP : obsY +=10; break;
	case GLUT_KEY_DOWN : obsY -=10; break;
	case GLUT_KEY_HOME : obsZ +=10; break;
	case GLUT_KEY_END : obsZ -=10; break;
}
glLoadIdentity();
gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
glutPostRedisplay();
}
// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(45,1.16,0.5,500);		

	PosicionaObservador();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

   	// glMatrixMode(GL_MODELVIEW); //matrix em uso: modelview
   	glViewport(0, 0, 350, 300);

	
	glPushMatrix();
    glTranslatef(-50.0f, 0.0f, 0.0f); 
    glColor3f(1.0f, 0.0f, 0.0f); 
    glutWireCube(40.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50.0f, 0.0f, 25.0f); 
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireCube(20.0);
    glPopMatrix();

 	 	  
	// Executa os comandos OpenGL
	glutSwapBuffers();
 }

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 	    
    EspecificaParametrosVisualizacao();
 }


// Programa Principal

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(350,300);
    glutCreateWindow("Visualizacao 3D");
    glutDisplayFunc(Desenha);
	glutSpecialFunc(teclasEspeciais);
    Inicializa();
    glutMainLoop();
}
