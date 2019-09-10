#include <GL/glut.h>
#include <cmath>
#include <iostream>

// -------------------------------------------------------------------------
void DrawUnitaryCube( )
{
  float colors[ 8 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 1, 1 },
    { 1, 0, 1 },
    { 1, 1, 0 },
    { 0.5, 0.5, 0.5 },
    { 1, 1, 1 }
  };

  float points[ 8 ][ 3 ] =
  {
    { 0, 0, 0 },
    { 1, 0, 0 },
    { 0, 0, 1 },
    { 1, 0, 1 },
    { 0, 1, 0 },
    { 0, 1, 1 },
    { 1, 1, 0 },
    { 1, 1, 1 }
  };

  unsigned int faces[ 6 ][ 4 ] =
  {
    { 0, 1, 3, 2 },
    { 0, 2, 5, 4 },
    { 2, 3, 7, 5 },
    { 5, 7, 6, 4 },
    { 1, 6, 7, 3 },
    { 1, 0, 4, 6 }
  };

  for( unsigned int i = 0; i < 6; ++i )
  {
    glBegin( GL_LINE_LOOP );
    {
      for( unsigned int j = 0; j < 4; ++j )
      {
        glColor3fv( colors[ faces[ i ][ j ] ] );
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}
// -------------------------------------------------------------------------
void DrawUnitaryDiamond( )
{
  float colors[ 8 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 1, 1 },
    { 1, 0, 1 },
    { 1, 1, 0 },
    { 0.5, 0.5, 0.5 },
    { 1, 1, 1 }
  };

  float points[ 6 ][ 3 ] =
  {
    { 0,-1, 0 },
    { 0.5, 0, 0 },
    { 0, 0, 1 },
    {-0.5, 0, 0 },
    { 0, 0,-1 },
    { 0, 1, 0 },
  };

  unsigned int faces[ 8 ][ 3 ] =
  {
    { 0, 1, 2 },
    { 0, 2, 3 },
    { 0, 4, 3 },
    { 0, 4, 1 },
    { 5, 4, 1 },
    { 5, 4, 3 },
    { 5, 2, 3 },
    { 5, 2, 1 }
  };

  for( unsigned int i = 0; i < 8; ++i )
  {
    glBegin( GL_POLYGON );
    {
      for( unsigned int j = 0; j < 3; ++j )
      {
        glColor3fv( colors[ faces[ i ][ j ] ] );
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}
// -------------------------------------------------------------------------
void DrawUnitaryPyramid( )
{
  float colors[ 8 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 1, 1 },
    { 1, 0, 1 },
    { 1, 1, 0 },
    { 0.5, 0.5, 0.5 },
    { 1, 1, 1 }
  };

  float points[ 5 ][ 3 ] =
  {
    { 0, 1, 0 },
    { 0.5, 0, 0 },
    { 0, 0, 1 },
    {-0.5, 0, 0 }
  };

  unsigned int faces[ 3 ][ 3 ] =
  {
    { 0, 1, 2 },
    { 0, 2, 3 },
    { 0, 1, 3 }
  };

  for( unsigned int i = 0; i < 3; ++i )
  {
    glBegin( GL_POLYGON );
    {
      for( unsigned int j = 0; j < 3; ++j )
      {
        glColor3fv( colors[ faces[ i ][ j ] ] );
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}
// -------------------------------------------------------------------------
void DrawUnitarySquarePyramid( )
{
  float colors[ 8 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 1, 1 },
    { 1, 0, 1 },
    { 1, 1, 0 },
    { 0.5, 0.5, 0.5 },
    { 1, 1, 1 }
  };

  float points[ 5 ][ 3 ] =
  {
    { 0, 1, 0 },
    { 0.5, 0, 0 },
    { 0, 0, 1 },
    {-0.5, 0, 0 },
    { 0, 0,-1 }
  };

  unsigned int faces[ 4 ][ 3 ] =
  {
    { 0, 1, 2 },
    { 0, 2, 3 },
    { 0, 4, 3 },
    { 0, 4, 1 }
  };

  for( unsigned int i = 0; i < 4; ++i )
  {
    glBegin( GL_POLYGON );
    {
      for( unsigned int j = 0; j < 3; ++j )
      {
        glColor3fv( colors[ faces[ i ][ j ] ] );
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}
// -------------------------------------------------------------------------
void Init( )
{
  glClearColor( 0.7, 0.7, 0.7, 0.0 );
}

// -------------------------------------------------------------------------
void ResizeCbk( int width, int height )
{
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glViewport( 0, 0, width, height );

  // Ortho
  // glOrtho( -2, 6, 0, 8, -2, 200 );

  // Prespective
  gluPerspective(
    45,
    float( width ) / float( height ),
    0.01, 200
    );
}

// -------------------------------------------------------------------------
void DisplayCbk( )
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode( GL_MODELVIEW );

  // Camara
  glLoadIdentity( );
  gluLookAt( 1.5, 1.5, 10, 0, 0, 0, 0, 1, 0 );

  // Cubo 1
  glPushMatrix( );
  glScalef( 3, 3, 3 );
  DrawUnitaryCube( );

  // Cubo 2
  glPopMatrix( );
  glPushMatrix( );
  glTranslatef(1.8,1.5,-5);
  glRotatef(90,1,0,0);
  glScalef( 2, 1.5, 1 );
  DrawUnitaryPyramid( );

  // Finish
  glutSwapBuffers( );
}

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowPosition( 50, 50 );
  glutInitWindowSize( 500, 500 );
  glutCreateWindow( "3D test!!!" );
  glutDisplayFunc( DisplayCbk );
  glutReshapeFunc( ResizeCbk );
  Init( );
  glutMainLoop( );

  return( 0 );
}

// eof
