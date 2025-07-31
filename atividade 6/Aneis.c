///////////////////////////////////////////////////////////////////////////////////////////        
//
//Este programa desenha três anéis circulares de aparência idêntica utilizando três caminhos diferentes.
// 
// INteração:
// Pressiona a barra para alterar entre os modos wireframe e preenchimento sólido
// Sumanta Guha.
/////////////////////////////////////////////////////////////////////////////////////////// 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#include <GL/glut.h>


#define PI 3.14159265
#define N 40.0 // Número de vértice nas bordas do disco



// Globals.
static int isWire = 0; // É wireframe?
static long font = (long)GLUT_BITMAP_8_BY_13; // Seleção fonte.

// Rotinha para desenhar uma string 
void escreveBitmapString(void *font, char *string)
{  
   //char *c;

   //for (c = string; *c != '\0'; c++) 
   while (*string) glutBitmapCharacter(font, *string++);
} 

// Função que desenha um disco com centro em (X,Y,Z), raio r, paralelo ao plano xy

void desenhaDisco(float R, float X, float Y, float Z)
{
   float t;
   int i;
   

   glBegin(GL_TRIANGLE_FAN);
      glVertex3f( X, Y, Z);
      for(i = 0; i <= N; ++i)
	  {
         t = 2 * PI * i / N; 
         glVertex3f(X + cos(t) * R, Y + sin(t) * R, Z);
	  }
   glEnd();
}


void desenhaCena(void)
{  
   float angle;
   int i;
   

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

   glPolygonMode(GL_FRONT, GL_FILL);

   //Anel superior esquerdo: disco branco sobrescrevendo o disco vermelho. 
   
   glColor3f(1.0, 1.0, 1.0);
   desenhaDisco(10.0, 25.0, 75.0, 0.0);
   glColor3f(1.0, 0.0, 0.0);
   desenhaDisco(20.0, 25.0, 75.0, 0.0);
   

   // Anel superior direito: o disco branco está na frente do disco vermelho que o bloqueia.
   
   //glEnable(GL_DEPTH_TEST); // Ativa teste de profundidade   
   glColor3f(1.0, 1.0, 1.0);
   desenhaDisco(10.0, 75.0, 75.0, 0.5);  
   glColor3f(1.0, 0.0, 0.0);
   desenhaDisco(20.0, 75.0, 75.0, 0.0);  
   //glDisable(GL_DEPTH_TEST); // Desativa teste de profundidade

   //Anel circular inferior: com furo verdadeiro.
   if (isWire) glPolygonMode(GL_FRONT, GL_LINE);
   else glPolygonMode(GL_FRONT, GL_FILL);
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_TRIANGLE_STRIP);
      for(i = 0; i <= N; ++i)
	  {
         angle = 2 * PI * i / N; 
         glVertex3f(50 + cos(angle) * 10.0, 30 + sin(angle) * 10.0, 0.0);
         glVertex3f(50 + cos(angle) * 20.0, 30 + sin(angle) * 20.0, 0.0);
	  }
   glEnd();

   // Escreve o texto
   glColor3f(0.0, 0.0, 0.0);
   glRasterPos3f(15.0, 51.0, 0.0);
   escreveBitmapString((void*)font,(char*)"Sobrescreve");
   glRasterPos3f(69.0, 51.0, 0.0);
   escreveBitmapString((void*)font,(char*)"Flutuante.");
   glRasterPos3f(38.0, 6.0, 0.0);
   escreveBitmapString((void*)font,(char*)"Verdadeiro!");

   glFlush();
}


void inicializa(void) 
{
   glClearColor(1.0, 1.0, 1.0, 0.0);  
}


void AlteraTamanhoJanela(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


void teclado(unsigned char key, int x, int y)
{
   switch(key) 
   {
      case ' ':
         if (isWire == 0) isWire = 1;
         else isWire = 0;      
         break;	  
      case 27:
         exit(0);    
   }
   glutPostRedisplay();
}



int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("Aneis circulares");
   inicializa();
   glutDisplayFunc(desenhaCena); 
   glutReshapeFunc(AlteraTamanhoJanela);  
   glutKeyboardFunc(teclado);
   glutMainLoop(); 

   return 0;  
}