/* -------------------------------------------------------------------------
 * @brief Example on how to draw simple 2D shapes
 * @author Leonardo Fl�rez-Valencia (florez-l@javeriana.edu.co)
 * -------------------------------------------------------------------------
 * Compilation on linux:
 *
 * g++ -std=c++17 simple_2d_scene.cxx -lm -lGL -lGLU -lglut -o mySimple2DScene
 *
 * -------------------------------------------------------------------------
 */

#include <GL/glut.h>
#include <cmath>
#include <iostream>

// -------------------------------------------------------------------------
#define _PI      3.14159265359
#define _2PI     6.28318530718
#define _SQRT3   1.73205080757
#define _SQRT3_2 0.86602540378
#define _SQRT3_3 0.57735026919
#define _SQRT3_4 0.43301270189

#define WORLD_MIN_X 0
#define WORLD_MIN_Y 0
#define WORLD_MAX_X 20
#define WORLD_MAX_Y  20

// -------------------------------------------------------------------------
void DrawCircle( GLenum mode, unsigned int samples )
{
  glBegin( mode );
  for( unsigned int i = 0; i < samples; ++i )
  {
    float t = _2PI * float( i ) / float( samples );
    glVertex2f( std::cos( t ), std::sin( t ) );
  } // end if
  glEnd( );
}

// -------------------------------------------------------------------------
void DrawSquare( GLenum mode )
{
  glBegin( mode );
  {
    glVertex2f( -0.5, -0.5 );
    glVertex2f( -0.5,  0.5 );
    glVertex2f(  0.5,  0.5 );
    glVertex2f(  0.5, -0.5 );
  }
  glEnd( );
}

// -------------------------------------------------------------------------
void DrawTriangle( GLenum mode )
{
  glBegin( mode );
  {
    glVertex2f( -0.5, -_SQRT3_4 );
    glVertex2f(  0.5, -_SQRT3_4 );
    glVertex2f(    0,  _SQRT3_4 );
  }
  glEnd( );
}

// -------------------------------------------------------------------------
void DrawBase( )
{
  glBegin( GL_LINES );
  {
    glColor3f( 1, 0, 0 );
    glVertex2f( WORLD_MIN_X * 0.75, 0 );
    glVertex2f( WORLD_MAX_X * 0.75, 0 );

    glColor3f( 0, 1, 0 );
    glVertex2f( 0, WORLD_MIN_Y * 0.75 );
    glVertex2f( 0, WORLD_MAX_Y * 0.75 );
  }
  glEnd( );
}

// -------------------------------------------------------------------------
void Init( )
{
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
}

// -------------------------------------------------------------------------
void ResizeCbk( int width, int height )
{
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glViewport( 0, 0, width, height );
  gluOrtho2D( WORLD_MIN_X, WORLD_MAX_X, WORLD_MIN_Y, WORLD_MAX_Y );
}
//--------------------------------------------------------------------------
void DrawCar(double x, double y,double z, double rColorWheel, double gColorWheel, double bColorWheel, double rColorHead, double gColorHead, double bColorHead, double rColorBody, double gColorBody, double bColorBody)
{
  //Ruedas
  //Rueda izquierda
  glLoadIdentity();
  glColor3f( rColorWheel, gColorWheel, bColorWheel );
  glTranslatef(x,y,z);
  //glRotatef(0,0,0,0);
  glScalef(0.5,0.5,0);
  DrawCircle( GL_POLYGON, 100 );
  //DrawSquare( GL_POLYGON );
  //DrawTriangle( GL_LINE_LOOP );
  //Rueda Derecha
  glLoadIdentity();
  glColor3f( rColorWheel, gColorWheel, bColorWheel );
  glTranslatef(x+3,y,z);
  //glRotatef(0,0,0,0);
  glScalef(0.5,0.5,0);
  DrawCircle( GL_POLYGON, 100 );

  //Cuerpo del carro
  glLoadIdentity();
  glColor3f( rColorBody, gColorBody, bColorBody );
  glTranslatef(x+1.5,y+1.5,z);
  glScalef(4,2,0);
  DrawSquare( GL_POLYGON );
  //Frente del carro
  glLoadIdentity();
  glColor3f( rColorHead, gColorHead, bColorHead  );
  glTranslatef(x+4,y+1,z);
  glScalef(1,1,0);
  DrawSquare( GL_POLYGON );
}
void DrawFloor(double x, double y,double z, double rx, double ry,double rz, double angleRot, double rColorFloor, double gColorFloor, double bColorFloor)
{
  //piso del carro
  glLoadIdentity();
  glColor3f( rColorFloor, gColorFloor, bColorFloor );
  glTranslatef(x,y,z);
  glRotatef(angleRot,rx,ry,rz);
  glScalef(7,1,0);
  DrawSquare( GL_POLYGON );
}
// -------------------------------------------------------------------------
void DrawHouse(double x, double y,double z, double rColorWall, double gColorWall, double bColorWall, double rColorRoof, double gColorRoof, double bColorRoof)
{
  //Casa
  //Pared de la casa
  glLoadIdentity();
  glColor3f( rColorWall, gColorWall, bColorWall );
  glTranslatef(x,y,z);
  glScalef(4.4,8,0);
  DrawSquare( GL_POLYGON );
  //Techo
  glLoadIdentity();
  glColor3f( rColorRoof, gColorRoof, bColorRoof );
  glTranslatef(x,y+5,z);
  glScalef(10,4.5,0);
  DrawTriangle( GL_POLYGON );
}
// -------------------------------------------------------------------------
void DrawTree(double x, double y,double z, double rColorRoot, double gColorRoot, double bColorRoot, double rColorTrunk, double gColorTrunk, double bColorTrunk)
{
  //Arbol
  double auxRamas=y+2;
  //Tronco
  glLoadIdentity();
  glColor3f( rColorTrunk, gColorTrunk, bColorTrunk );
  glTranslatef(x,y,z);
  glScalef(2.2,4,0);
  DrawSquare( GL_POLYGON );
  //Ramas
  glLoadIdentity();
  glColor3f( rColorRoot, gColorRoot, bColorRoot );
  glTranslatef(x,auxRamas,z);
  glScalef(4.3,3,0);
  DrawTriangle( GL_POLYGON );

  glLoadIdentity();
  glColor3f( rColorRoot, gColorRoot, bColorRoot );
  glTranslatef(x,auxRamas+1,z);
  glScalef(4.3,3,0);
  DrawTriangle( GL_POLYGON );

  glLoadIdentity();
  glColor3f( rColorRoot, gColorRoot, bColorRoot );
  glTranslatef(x,auxRamas+2,z);
  glScalef(4.3,3,0);
  DrawTriangle( GL_POLYGON );
  // Finish
}
// -------------------------------------------------------------------------

// -------------------------------------------------------------------------

void DisplayCbk( )
{
  // Reset viewport and model matrix
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity( );

  // Orthogonal base
  DrawBase( );
  DrawCar(1.5,2,0,1,1,1,1,1,0,0,0,1);

  glTranslatef(6.2,3,0);
  DrawTree(1.2,16,0,0.08,0.5,0.08,0.57,0.38,0.1);
  DrawTree(4.2,16,0,0.08,0.5,0.08,0.57,0.38,0.1);
  DrawTree(7.2,16,0,0.08,0.5,0.08,0.57,0.38,0.1);
  DrawTree(10.2,16,0,0.08,0.5,0.08,0.57,0.38,0.1);
  DrawTree(13.2,16,0,0.08,0.5,0.08,0.57,0.38,0.1);
  DrawTree(16.2,16,0,0.08,0.5,0.08,0.57,0.38,0.1);
  DrawTree(17.2,12,0,0.08,0.5,0.08,0.57,0.38,0.1);
  DrawTree(17.2,8,0,0.08,0.5,0.08,0.57,0.38,0.1);
  DrawTree(17.2,4,0,0.08,0.5,0.08,0.57,0.38,0.1);
  DrawHouse(10,7,0,1,1,1,0.08,0.5,0.08);
  DrawFloor(10,0.3,0,0,0,1,315,0.08,0.5,0.08);
  DrawFloor(14,0.3,0,0,0,1,315,0.08,0.5,0.08);
  glEnd();
  /* TO TEST
     glTranslate[f/d]( sx, sy, 0 );
     glScale[f/d]( sx, sy, 1 );
     glRotate[f/d]( theta, 0, 0, 1 );
   */


  //glPushMatrix();

  glutSwapBuffers( );
}

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowPosition( 50, 50 );
  glutInitWindowSize( 1000, 1000 );
  glutCreateWindow( "2D test!!!" );
  glutDisplayFunc( DisplayCbk );
  glutReshapeFunc( ResizeCbk );
  Init( );
  glutMainLoop( );

  return( 0 );
}

// eof - mouse_click.cxx
