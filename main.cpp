/* -------------------------------------------------------------------------
 * @brief Example on how to capture mouse clicks in OpenGL
 * @author Leonardo Fl�rez-Valencia (florez-l@javeriana.edu.co)
 * -------------------------------------------------------------------------
 * Compilation on linux:
 *
 * g++ -std=c++17 mouse_click.cxx -lm -lGL -lGLU -lglut -o myMouseClickTest
 *
 * -------------------------------------------------------------------------
 */

#include <GLUT/glut.h>
#include <OpenGL/gl.h>

//#include <GL/freeglut.h>
//#include <GL/gl.h>

#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>


std::vector<float> lineaDDA;
std::vector<float> lineaBresen;
std::vector<float> interseccionDDA_y_Bresen;
int linea[4];
int height, width;
int numeroClicks = 0;

//--------------------------------------------------------------------------
vector<float> buscarPuntosIguales(vector<float> v1, vector<float> v2)
{
    vector<float> aux;
    int posAux=0;

    for(int i=0; i<v1.size()-1 && posAux<v2.size(); i+=2)
    {
        for(int j=posAux;j<v2.size()-1;j+=2)
        {
            if(v1[i]==v2[j] && v1[i+1]==v2[j+1])
            {
                aux.push_back(v1[i]);
                aux.push_back(v1[i+1]);

                posAux=j+2;
                j=v2.size();
            }
            else
            {
                if(v2[j]>v1[i] || (v1[i]==v2[j] && v2[j+1]>v1[i+1]))
                {
                    posAux=j;
                    j=v2.size();
                }
            }
        }
    }
    return aux;
}

// -------------------------------------------------------------------------
void Init( )
{
    glClearColor( 1.0, 1.0, 1.0, 0.0 );
    glColor3f( 0.0, 0.0, 0.0 );
    glPointSize( 1.0 );
    gluOrtho2D( 0.0, width, 0.0, height );
}
//---------------------------------------------------------------------
void DDA_0(int x0, int y0, int x1, int y1)
{
    float dx = x1-x0;
    float dy = y1-y0;
    float step = 1;

    if(abs(dy)< abs(dx))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    dx = dx/step;
    dy = dy/step;

    float x = x0;
    float y = y0;

    for(int i = 0; i< step; i++)
    {
        lineaDDA.push_back(x);
        lineaDDA.push_back(y);

        x = x + dx;
        y = y + dy;
    }
}

//---------------------------------------------------------------------
void BERNI(int x0,int y0,int x1,int y1)
{

    float dx,dy,aux,y,x;
    /*if(x1 < x0){
      dx = x0-x1;
      dy = y0-y1;
    }*/

    //if(x0 < x1){
    dx = x1-x0;
    dy = y1-y0;
    //}

    float yi = 1,xi = 1;
    if(abs(dy)<abs(dx))
    {

        //primercuadrante x dominante
        if(x0<=x1 && y0<=y1)
        {
            x = x0;
            y = y0;
            if(dy == 0)
            {
                while(x != x1)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    x = x +1;
                }
            }
            else
            {
                if (dy < 0)
                {
                    yi = -1;
                    dy = -dy;
                }
                float D;
                D = (2*dy) - dx;
                for(x; x<=x1; x++)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    if(D>0)
                    {
                        y = y + yi;
                        D = D - (2*dx);
                    }
                    D = D + (2*dy);
                }
            }
        }

        //cuartocuadrante x dominante
        if(x0<=x1 && y1 <= y0)
        {
            x = x0;
            y = y0;
            if(dy == 0)
            {
                while(x != x1)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    x = x +1;
                }
            }
            else
            {
                if (dy < 0)
                {
                    yi = -1;
                    dy = -dy;
                }
                float D;
                D = (2*dy) - dx;
                for(x; x<=x1; x++)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    if(D>0)
                    {
                        y = y + yi;
                        D = D - (2*dx);
                    }
                    D = D + (2*dy);
                }
            }
        }

        //segundo cuadrante x dominante
        if(x1<=x0 && y0<=y1)
        {
            aux = x0;
            x0 = x1;
            x1 = aux;

            aux = y0;
            y0 = y1;
            y1 = aux;

            x = x0;
            y = y0;

            dy = y1-y0;
            dx = x1-x0;
            if(dy == 0)
            {
                while(x != x1)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    x = x + 1;
                }
                lineaBresen.push_back(x);
                lineaBresen.push_back(y);
            }
            else
            {
                if (dy < 0)
                {
                    yi = -1;
                    dy = -dy;
                }
                float D;
                D = (2*dy) - dx;
                for(x; x<=x1; x++)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    if(D>0)
                    {
                        y = y + yi;
                        D = D - (2*dx);
                    }
                    D = D + (2*dy);
                }
            }

        }

        //tercer cuadrante x dominante
        if(x1<=x0 && y1 <= y0)
        {
            aux = x0;
            x0 = x1;
            x1 = aux;

            aux = y0;
            y0 = y1;
            y1 = aux;

            x = x0;
            y = y0;

            dy = y1-y0;
            dx = x1-x0;
            if(dy == 0)
            {
                while(x != x1)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    x = x + 1;
                }
                lineaBresen.push_back(x);
                lineaBresen.push_back(y);
            }
            else
            {
                if (dy < 0)
                {
                    yi = -1;
                    dy = -dy;
                }
                float D;
                D = (2*dy) - dx;
                for(x; x<=x1; x++)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    if(D>0)
                    {
                        y = y + yi;
                        D = D - (2*dx);
                    }
                    D = D + (2*dy);
                }
            }
        }
    }

    if(abs(dx)<abs(dy))
    {

        //primer cuadrante y dominante
        if(y0<=y1 && x0 <= x1)
        {
            x = x0;
            y = y0;
            if(dx == 0)
            {
                while(y != y1)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    y = y + 1;
                }
            }
            else
            {
                if (dx < 0)
                {
                    xi = -1;
                    dx = -dx;
                }
                float D;
                D = (2*dx) - dy;
                for(y; y<=y1; y++)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    if(D>0)
                    {
                        x = x + xi;
                        D = D - (2*dy);
                    }
                    D = D + (2*dx);
                }
            }
        }

        //segundo cuadrante y dominante
        if(y0<=y1 && x1 <= x0)
        {

            x = x0;
            y = y0;
            if(dx == 0)
            {
                while(y != y1)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    y = y + 1;
                }
            }
            else
            {
                if (dx < 0)
                {
                    xi = -1;
                    dx = -dx;
                }
                float D;
                D = (2*dx) - dy;
                for(y; y<=y1; y++)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    if(D>0)
                    {
                        x = x + xi;
                        D = D - (2*dy);
                    }
                    D = D + (2*dx);
                }
            }

        }

        //cuartocuadrante y dominante
        if(y1<=y0 && x0 <= x1)
        {
            aux = x0;
            x0 = x1;
            x1 = aux;

            aux = y0;
            y0 = y1;
            y1 = aux;

            dx = x1-x0;
            dy = y1-y0;

            x = x0;
            y = y0;

            if(dx == 0)
            {
                while(y != y1)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    y = y + 1;
                }
            }
            else
            {
                if (dx < 0)
                {
                    xi = -1;
                    dx = -dx;
                }
                float D;
                D = (2*dx) - dy;
                for(y; y<=y1; y++)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    if(D>0)
                    {
                        x = x + xi;
                        D = D - (2*dy);
                    }
                    D = D + (2*dx);
                }
            }
        }

        if(y1<=y0 && x1<=x0)
        {

            aux = x0;
            x0 = x1;
            x1 = aux;

            aux = y0;
            y0 = y1;
            y1 = aux;

            dx = x1-x0;
            dy = y1-y0;

            x = x0;
            y = y0;
            if(dx == 0)
            {
                while(y != y1)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    y = y + 1;
                }
            }
            else
            {
                if (dx < 0)
                {
                    xi = -1;
                    dx = -dx;
                }
                float D;
                D = (2*dx) - dy;
                for(y; y<=y1; y++)
                {
                    lineaBresen.push_back(x);
                    lineaBresen.push_back(y);
                    if(D>0)
                    {
                        x = x + xi;
                        D = D - (2*dy);
                    }
                    D = D + (2*dx);
                }
            }
        }
    }
}
// -------------------------------------------------------------------------
void MouseCbk( int button, int state, int x, int y )
{

    if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    {
        if(numeroClicks>0)
        {
            numeroClicks= 0;
            linea[2] = x;
            linea[3] = height-y;
            DDA_0(linea[0],linea[1],linea[2],linea[3]);
            BERNI(linea[0],linea[1],linea[2],linea[3]);
            interseccionDDA_y_Bresen=buscarPuntosIguales(lineaDDA,lineaBresen);
            glutPostRedisplay();
        }
        else
        {
            linea[0] = x;
            linea[1] = height-y;
            numeroClicks++;
        }
    } // end if


}

// -------------------------------------------------------------------------
void DisplayCbk( )
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    for(int i = 0; i<lineaDDA.size(); i = i+2)
    {
        glVertex2f(lineaDDA[i],lineaDDA[i+1]);
    }
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POINTS);
    glPointSize(10);
    for(int i = 0; i<lineaBresen.size(); i = i+2)
    {
        glVertex2f(lineaBresen[i],lineaBresen[i+1]);
    }
    glEnd();

    glColor3f(0.101,0.078,0.988);
    glBegin(GL_POINTS);
    glPointSize(10);
    for(int i = 0; i<interseccionDDA_y_Bresen.size(); i = i+2)
    {
        glVertex2f(interseccionDDA_y_Bresen[i],interseccionDDA_y_Bresen[i+1]);
    }
    glEnd();
    glutSwapBuffers();
}

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
    width = atoi(argv[1]);
    height = atoi(argv[2]);
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowPosition( 50, 50 );
    glutInitWindowSize( width, height );
    glutCreateWindow( "mouse_click test!!!" );
    glutDisplayFunc( DisplayCbk );
    glutMouseFunc( MouseCbk );
    Init( );
    glutMainLoop( );

    return( 0 );
}

