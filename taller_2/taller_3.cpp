//  introOpenGL.cpp
//  Creado por Andrea Rueda, 01/2018
//
//BRAYAN GARCIA
//NICOLAS LOPEZ FERNANDEZ

//WINDOWS
//#include <GL/glut.h>

//LINUX
#include <GL/freeglut.h>
#include <GL/gl.h>

//MAC
//#include <GLUT/glut.h>
//#include <OpenGL/gl.h>
//g++ -o pruebaApp taller1.cpp   -framework OpenGL -framework GLUT

#include<iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#define  RAND_MAX 1

int main_w, w1,w2;
GLfloat X=0.0f,Y=0.0f,Z=0.0f;
struct WindowData
{
  unsigned long Width, Height;
  double XMin, XMax, YMin, YMax;
};
WindowData win_data;

void myInit (void)
{
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
}

// -------------------------------------------------------------------------
void KeyboardCbk( unsigned char key, int x, int y ) //key: tecla oprimida x-y: posicion mouse
{
  printf("%i\n",key);
  switch (key) {
    //Letra w
    case 119:

    Y-=0.9f;
    break;
    //Letra a
    case 97:

    X+=0.9f;
    break;
    //Letra s
    case 115:

    Y+=0.9f;
    break;
    //letra d
    case 100:

    X-=0.9f;
    break;
  }
  glutPostRedisplay();
}
// -------------------------------------------------------------------------
void SpecialKeyboardCbk( int key, int x, int y ) //gluf_f1 glut _up.... x-y: mouse
{

  switch (key) {
    //Letra w
    case GLUT_KEY_UP:

    Y-=0.9f;
    break;
    //Letra a
    case GLUT_KEY_LEFT:

    X+=0.1f;
    break;
    //Letra s
    case GLUT_KEY_DOWN:

    Y+=0.1f;
    break;
    //letra d
    case GLUT_KEY_RIGHT:
    
    X-=0.1f;
    break;
  }
  glutPostRedisplay();
}
void pintar(int x0, int y0,int xf,int yf)
{
    for(int i = x0; i<=xf; i++)
    {
        for(int j = y0; j<yf; j++)
        {
            glVertex2i(i,j);
        }
    }
}


void myDisplay(int num)
{

  if(num == 1){
    glColor3f(0.84,0.85,0.79);
    glPointSize(1);
    glTranslatef(X,Y,0);
    glBegin(GL_POINTS);
      pintar(21,36,321,564);
    glEnd();

    //ROJO GENERAL
    glColor3f(0.93,0.37,0.14);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(21,120,323,405);
    glEnd();

    //BLANCO CENTRO
    glColor3f(0.9,0.89,0.87);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(50,186,294,318);
      pintar(110,173,210,186);
    glEnd();

    //ROJO CUADRAR
    glColor3f(0.93,0.37,0.14);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(120,307,210,390);
      pintar(24,117,320,120);
      pintar(27,114,317,117);
      pintar(30,111,314,114);
      pintar(50,108,305,111);
      pintar(56,105,299,108);
      pintar(62,102,293,105);
      pintar(90,96,284,102);
      pintar(114,93,249,96);
      pintar(126,90,234,93);
      pintar(21,405,30,408);
      pintar(21,408,24,411);
      pintar(312,405,321,408);
      pintar(315,408,321,411);
    glEnd();

    //AMARILLO
    glColor3f(0.686,0.556,0.254);
    glBegin(GL_POINTS);
    pintar(48,390,285,405);
    pintar(66,375,267,390);
    pintar(83,360,246,375);
    pintar(114,345,222,360);
    pintar(150,330,192,345);

    pintar(159,327,186,330);
    pintar(168,324,180,327);
    pintar(126,339,216,345);
    pintar(138,333,204,339);
    pintar(102,348,234,390);
    pintar(90,357,249,360);
    pintar(72,369,267,375);
    pintar(48,405,135,408);
    pintar(54,381,283,390);

    pintar(21,420,33,431);
    pintar(24,411,48,423);
    pintar(33,405,60,420);
    pintar(60,405,81,414);
    pintar(36,399,48,408);
    pintar(42,396,48,399);

    pintar(228,376,273,399);
    pintar(234,393,296,405);
    pintar(228,402,299,411);
    pintar(252,402,302,417);
    pintar(261,405,311,417);
    pintar(280,414,323,423);
    pintar(300,420,323,429);
    pintar(315,429,323,435);

    pintar(246,359,255,380);
    glEnd();

    //CIRCULO ROJO
    glColor3f(0.89,0.29,0.14);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(153,354,195,390);
    glEnd();

    //ARREGLAR

    glColor3f(0.0,0.0,0.0);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(0,0,60,60);
      pintar(0,0,54,69);
      pintar(0,0,48,72);
      pintar(0,0,69,51);
      pintar(0,0,78,45);
      pintar(0,0,35,99);
      pintar(0,0,90,39);

      pintar(291,0,360,60);
      pintar(278,0,360,51);
      pintar(251,0,360,45);
      pintar(297,0,360,69);
      pintar(309,0,360,81);

      pintar(0,540,42,600);
      pintar(0,555,69,600);
      pintar(0,548,51,600);
      pintar(0,554,51,600);

      pintar(291,548,360,600);
      pintar(297,539,360,600);
      pintar(313,480,360,600);
      pintar(270,555,360,600);

    glEnd();
    glColor3f(0.0,0.0,0.0);
  }

  if(num == 2){
    glClearColor(1-0.0,1-0.0,1-0.0,1-0.0);
    glColor3f(1-0.84,1-0.85,1-0.79);
    glTranslatef(X,Y,0);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(21,36,321,564);
    glEnd();

    //ROJO GENERAL
    glColor3f(1-0.93,1-0.37,1-0.14);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(21,120,323,405);
    glEnd();

    //BLANCO CENTRO
    glColor3f(1-0.9,1-0.89,1-0.87);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(50,186,294,318);
      pintar(110,173,210,186);
    glEnd();

    //ROJO CUADRAR
    glColor3f(1-0.93,1-0.37,1-0.14);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(120,307,210,390);
      pintar(24,117,320,120);
      pintar(27,114,317,117);
      pintar(30,111,314,114);
      pintar(50,108,305,111);
      pintar(56,105,299,108);
      pintar(62,102,293,105);
      pintar(90,96,284,102);
      pintar(114,93,249,96);
      pintar(126,90,234,93);
      pintar(21,405,30,408);
      pintar(21,408,24,411);
      pintar(312,405,321,408);
      pintar(315,408,321,411);
    glEnd();

    //AMARILLO
    glColor3f(1-0.686,1-0.556,1-0.254);
    glBegin(GL_POINTS);
    pintar(48,390,285,405);
    pintar(66,375,267,390);
    pintar(83,360,246,375);
    pintar(114,345,222,360);
    pintar(150,330,192,345);

    pintar(159,327,186,330);
    pintar(168,324,180,327);
    pintar(126,339,216,345);
    pintar(138,333,204,339);
    pintar(102,348,234,390);
    pintar(90,357,249,360);
    pintar(72,369,267,375);
    pintar(48,405,135,408);
    pintar(54,381,283,390);

    pintar(21,420,33,431);
    pintar(24,411,48,423);
    pintar(33,405,60,420);
    pintar(60,405,81,414);
    pintar(36,399,48,408);
    pintar(42,396,48,399);

    pintar(228,376,273,399);
    pintar(234,393,296,405);
    pintar(228,402,299,411);
    pintar(252,402,302,417);
    pintar(261,405,311,417);
    pintar(280,414,323,423);
    pintar(300,420,323,429);
    pintar(315,429,323,435);

    pintar(246,359,255,380);
    glEnd();

    //CIRCULO ROJO
    glColor3f(1-0.89,1-0.29,1-0.14);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(153,354,195,390);
    glEnd();

    //ARREGLAR

    glColor3f(1-1.0,1-1.0,1-1.0);
    glPointSize(1);
    glBegin(GL_POINTS);
      pintar(0,0,60,60);
      pintar(0,0,54,69);
      pintar(0,0,48,72);
      pintar(0,0,69,51);
      pintar(0,0,78,45);
      pintar(0,0,35,99);
      pintar(0,0,90,39);

      pintar(291,0,360,60);
      pintar(278,0,360,51);
      pintar(251,0,360,45);
      pintar(297,0,360,69);
      pintar(309,0,360,81);

      pintar(0,540,42,600);
      pintar(0,555,69,600);
      pintar(0,548,51,600);
      pintar(0,554,51,600);

      pintar(291,548,360,600);
      pintar(297,539,360,600);
      pintar(313,480,360,600);
      pintar(270,555,360,600);

    glEnd();
    glColor3f(1-0.0,1-0.0,1-0.0);
  }
    //BORDE ---------------------------------------------------
    glPointSize(1.0);
    glBegin(GL_POINTS);
//-----------------------------------Primera linea curva de abajo hacia arriba
    for(int j = 129; j<210; j++)
    {
        for(int i = 33; i<39; i++)
        {
            glVertex2i(j,i);
        }
    }
    pintar(111,35,129,39);
    pintar(96,38,111,42);
    pintar(87,41,105,45);
    pintar(78,44,93,48);
    pintar(72,47,87,51);
    pintar(63,50,78,54);
    pintar(60,53,66,57);
    pintar(54,56,62,60);
    pintar(51,59,54,63);
    pintar(47,62,54,66);
    pintar(42,65,51,69);
    pintar(39,68,45,72);
    pintar(36,71,42,75);
    pintar(35,71,39,78);
    pintar(33,77,36,90);
    pintar(30,77,33,111);
    pintar(27,90,30,123);
//---------------------------------------------------------------------------
    for(int i = 210; i<213; i++)
    {
        for(int j = 33; j<42; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 213; i<228; i++)
    {
        for(int j = 36; j<42; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 228; i<231; i++)
    {
        for(int j = 36; j<45; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 231; i<243; i++)
    {
        for(int j = 39; j<45; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 243; i<246; i++)
    {
        for(int j = 39; j<48; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 246; i<255; i++)
    {
        for(int j = 42; j<48; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 255; i<258; i++)
    {
        for(int j = 42; j<51; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 258; i<267; i++)
    {
        for(int j = 45; j<51; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 267; i<270; i++)
    {
        for(int j = 45; j<54; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 270; i<273; i++)
    {
        for(int j = 48; j<54; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 273; i<276; i++)
    {
        for(int j = 48; j<57; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 276; i<282; i++)
    {
        for(int j = 51; j<57; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i =282 ; i<288; i++)
    {
        for(int j = 54; j<60; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 288; i<294; i++)
    {
        for(int j = 57; j<63; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 294; i<297; i++)
    {
        for(int j = 60; j<66; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 297; i<300; i++)
    {
        for(int j = 63; j<69; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 300; i<306; i++)
    {
        for(int j = 66; j<72; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 306; i<309; i++)
    {
        for(int j = 69; j<75; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 309; i<312; i++)
    {
        for(int j = 72; j<81; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 312; i<315; i++)
    {
        for(int j = 78; j<87; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 315; i<318; i++)
    {
        for(int j = 81; j<96; j++)
        {
            glVertex2i(i,j);
        }
    }

//---------------------------------------------- lineas curvas de los lados (las lineas mas largas)
    for(int i = 318; i<321; i++)
    {
        for(int j = 90; j<174; j++)
        {
            glVertex2i(i,j);
        }
    }
    for(int i = 321; i<323; i++)
    {
        for(int j = 150; j<219; j++)
        {
            glVertex2i(i,j);
        }
    }
    for(int i = 322; i<325; i++)
    {
        for(int j = 219; j<453; j++)
        {
            glVertex2i(i,j);
        }
    }
    pintar(319,452,322,483);
    pintar(316,477,319,486);
    pintar(313,483,316,489);
    pintar(310,486,313,495);
    pintar(307,492,310,498);
    pintar(304,495,307,501);
    pintar(301,498,304,501);
    pintar(300,498,306,501);

    pintar(24,102,27,192);
    pintar(21,136,24,303);
    pintar(19,198,22,472);
    pintar(22,463,25,481);
    pintar(25,475,28,493);
    pintar(28,487,31,496);
    pintar(31,490,34,499);
//-------------Tapa--------------------------------------
    pintar(31,496,40,499);
    pintar(37,499,52,502);
    pintar(46,496,61,499);
    pintar(55,493,70,496);
    pintar(64,490,82,493);
    pintar(76,487,97,490);
    pintar(91,484,130,487);
    pintar(112,481,238,484);
    pintar(148,478,196,481);
    pintar(205,484,253,487);
    pintar(241,487,262,490);
    pintar(256,490,269,493);
    pintar(263,493,281,496);
    pintar(275,496,297,499);
    pintar(291,499,303,502);

    pintar(36,495,45,498);
    pintar(33,498,42,501);
    pintar(30,501,36,504);
    pintar(27,504,36,507);
    pintar(27,507,33,510);
    pintar(24,510,30,531);
    pintar(27,531,30,537);
    pintar(30,531,33,543);
    pintar(33,537,36,544);
    pintar(36,541,39,547);
    pintar(39,544,45,550);
    pintar(45,547,54,553);
    pintar(54,550,60,556);
    pintar(60,553,72,556);
    pintar(66,556,84,559);
    pintar(78,559,105,562);
    pintar(93,562,144,565);
    pintar(120,565,219,568);
    pintar(204,562,243,565);
    pintar(240,559,264,562);
    pintar(258,556,273,559);
    pintar(273,553,288,556);
    pintar(285,550,297,553);
    pintar(294,547,303,550);
    pintar(297,544,306,547);
    pintar(300,541,309,544);
    pintar(303,538,309,541);
    pintar(306,532,312,538);
    pintar(309,505,312,532);
    pintar(312,514,315,532);
    pintar(306,502,309,508);
    pintar(303,499,306,505);
    pintar(300,496,303,502);

//---------------------------------------------------
    pintar(315,411,325,420);
    pintar(312,408,315,414);
    pintar(306,405,312,411);
    pintar(303,402,309,408);
    pintar(300,399,303,405);
    pintar(297,396,300,402);
    pintar(294,393,297,399);
    pintar(288,390,294,396);
    pintar(282,384,288,393);
    pintar(279,381,282,387);
    pintar(273,378,279,384);
    pintar(270,375,273,381);
    pintar(267,372,270,378);
    pintar(261,369,267,375);
    pintar(258,366,264,372);
    pintar(252,363,258,369);
    pintar(249,360,255,366);
    pintar(243,357,249,363);
    pintar(240,354,246,360);
    pintar(234,351,240,357);
    pintar(228,348,234,354);
    pintar(225,345,231,351);
    pintar(222,342,225,348);
    pintar(216,339,222,345);
    pintar(210,336,216,342);
    pintar(204,333,210,339);
    pintar(198,330,207,336);
    pintar(192,327,201,333);
    pintar(186,324,192,330);
    pintar(180,321,186,327);

    pintar(168,318,180,324);//Centro

    pintar(160,321,168,327);
    pintar(154,324,160,330);
    pintar(145,327,154,333);
    pintar(139,330,145,336);
    pintar(133,333,139,339);
    pintar(127,336,133,342);
    pintar(121,339,127,345);
    pintar(115,342,121,348);
    pintar(109,345,115,351);
    pintar(103,348,109,354);
    pintar(100,351,103,357);
    pintar(94,353,100,359);
    pintar(91,356,94,362);
    pintar(85,359,91,365);
    pintar(82,362,85,368);
    pintar(76,365,82,371);
    pintar(73,368,79,374);
    pintar(67,371,73,377);
    pintar(64,374,67,380);
    pintar(59,377,64,383);
    pintar(57,380,59,386);
    pintar(52,383,57,389);
    pintar(50,386,52,392);
    pintar(48,389,50,395);
    pintar(43,392,48,398);
    pintar(41,395,43,401);
    pintar(36,398,41,404);
    pintar(34,401,36,407);
    pintar(32,404,34,410);
    pintar(27,407,32,414);
    pintar(21,410,27,420);

//--------------------------------

//Circulo arriba de Duff--------------

    pintar(195,369,201,381);
    pintar(195,360,198,369);
    pintar(192,357,195,366);
    pintar(189,354,192,360);
    pintar(186,354,189,357);
    pintar(183,351,186,357);
    pintar(159,351,186,354);
    pintar(168,348,177,351);
    pintar(156,354,165,357);
    pintar(153,357,159,360);
    pintar(150,360,156,363);
    pintar(147,363,153,381);
    pintar(150,381,153,387);
    pintar(153,384,156,390);
    pintar(156,387,159,393);
    pintar(156,390,189,393);
    pintar(162,393,183,396);
    pintar(186,387,195,390);
    pintar(189,384,198,387);
    pintar(192,381,198,384);

    for(int i = 312; i<318; i++)
    {
        for(int j = 114; j<120; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 309; i<312; i++)
    {
        for(int j = 111; j<117; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 306; i<309; i++)
    {
        for(int j = 111; j<114; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 303; i<306; i++)
    {
        for(int j = 108; j<114; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 300; i<303; i++)
    {
        for(int j = 105; j<111; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 294; i<300; i++)
    {
        for(int j = 105; j<108; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 291; i<294; i++)
    {
        for(int j = 102; j<108; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 288; i<291; i++)
    {
        for(int j = 102; j<105; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 285; i<288; i++)
    {
        for(int j = 99; j<105; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 279; i<285; i++)
    {
        for(int j = 99; j<102; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 276; i<279; i++)
    {
        for(int j = 96; j<102; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 267; i<276; i++)
    {
        for(int j = 96; j<99; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 264; i<267; i++)
    {
        for(int j = 93; j<99; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 252; i<264; i++)
    {
        for(int j = 93; j<96; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 249; i<252; i++)
    {
        for(int j = 87; j<96; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 237; i<249; i++)
    {
        for(int j = 87; j<93; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 234; i<237; i++)
    {
        for(int j = 84; j<93; j++)
        {
            glVertex2i(i,j);
        }
    }
//---------------------------------------------------- linea curva debajo de BEER
    for(int i = 125; i<234; i++)
    {
        for(int j = 84; j<90; j++)
        {
            glVertex2i(i,j);
        }
    }
    pintar(111,87,125,93);
    pintar(86,90,114,96);
    pintar(79,96,89,102);
    pintar(66,99,79,105);
    pintar(60,105,69,108);
    pintar(50,108,63,111);
    pintar(42,111,53,114);
    pintar(36,114,45,117);
    pintar(30,117,39,120);
    pintar(27,117,33,123);
//-----------------------------------------------------

//-----------------------------------------------------


    //LETRAS-------------------------------------------

    //LETRA B
    pintar(90,114,99,150);
    pintar(99,141,105,147);
    pintar(105,138,114,147);
    pintar(114,129,117,144);
    pintar(117,132,120,141);
    pintar(108,111,114,147);
    pintar(105,123,108,135);
    pintar(99,126,105,132);
    pintar(114,111,117,126);
    pintar(117,114,120,126);
    pintar(105,111,108,120);
    pintar(99,111,105,117);

    //LETRAS E
    pintar(138,108,147,144);
    pintar(147,135,162,144);
    pintar(147,120,159,129);
    pintar(147,108,162,114);

    pintar(183,108,192,144);
    pintar(192,135,207,144);
    pintar(192,120,204,129);
    pintar(192,108,207,114);

    //LETRA R
    pintar(231,111,243,147);
    pintar(243,141,261,147);
    pintar(261,135,264,144);
    pintar(249,138,261,141);
    pintar(252,135,261,138);
    pintar(246,132,261,135);
    pintar(243,123,255,132);
    pintar(249,120,267,123);
    pintar(255,123,258,129);
    pintar(258,123,264,126);
    pintar(252,117,267,120);
    pintar(258,114,264,117);

    //LETRA D
    pintar(69,162,75,348);
    pintar(66,315,69,348);
    pintar(75,162,84,345);
    pintar(84,165,90,342);
    pintar(90,165,93,249);
    pintar(90,309,105,312);
    pintar(90,318,93,339);
    pintar(93,315,96,339);
    pintar(96,315,99,336);
    pintar(99,312,105,333);
    pintar(105,303,108,330);
    pintar(108,297,111,327);
    pintar(111,291,114,324);
    pintar(114,282,117,321);
    pintar(117,273,120,318);
    pintar(93,168,96,198);
    pintar(96,171,99,201);
    pintar(99,171,102,204);
    pintar(102,174,105,207);
    pintar(105,177,108,210);
    pintar(108,177,111,216);
    pintar(111,183,114,222);
    pintar(114,186,117,234);
    pintar(117,189,120,243);
    pintar(120,192,123,315);
    pintar(123,198,126,312);
    pintar(126,204,129,309);
    pintar(129,207,132,303);
    pintar(132,213,135,297);
    pintar(135,219,138,291);
    pintar(138,234,141,282);
    pintar(141,249,144,270);

    //LETRA U
    pintar(147,207,150,249);
    pintar(150,201,153,252);
    pintar(153,194,162,252);
    pintar(159,191,183,194);
    pintar(162,194,165,249);
    pintar(165,194,171,219);
    pintar(171,194,174,246);
    pintar(174,194,183,252);
    pintar(183,198,186,252);
    pintar(186,204,189,252);
    pintar(189,210,192,249);

    //LETRA F
    pintar(189,180,192,189);
    pintar(192,171,204,192);
    pintar(198,165,204,171);
    pintar(198,224,201,231);
    pintar(201,213,207,234);
    pintar(207,216,210,237);
    pintar(210,219,213,237);
    pintar(204,162,207,189);
    pintar(207,162,210,186);
    pintar(210,162,213,195);
    pintar(213,162,216,330);
    pintar(216,162,219,333);
    pintar(219,162,222,336);
    pintar(222,165,228,339);
    pintar(228,171,231,339);
    pintar(231,177,234,336);
    pintar(234,177,237,180);
    pintar(234,228,237,270);
    pintar(234,309,237,336);
    pintar(237,177,240,192);
    pintar(237,228,240,249);
    pintar(237,306,240,333);
    pintar(240,174,243,195);
    pintar(240,231,243,252);
    pintar(240,306,243,333);
    pintar(243,168,246,195);
    pintar(243,231,246,252);
    pintar(243,306,246,330);
    pintar(246,168,249,195);
    pintar(246,234,249,255);
    pintar(246,309,249,321);
    pintar(249,165,252,195);
    pintar(249,234,252,255);
    pintar(249,312,252,318);
    pintar(252,165,255,192);
    pintar(252,237,255,318);
    pintar(255,165,258,336);
    pintar(258,165,261,339);
    pintar(261,165,264,342);
    pintar(264,165,267,345);
    pintar(267,171,270,348);
    pintar(270,180,273,348);
    pintar(273,243,276,264);
    pintar(273,321,276,348);
    pintar(276,243,279,267);
    pintar(276,318,279,345);
    pintar(279,246,285,267);
    pintar(285,249,288,267);
    pintar(279,318,282,345);
    pintar(282,318,285,342);
    pintar(285,321,288,339);
    pintar(288,324,291,330);

    //CUADRADO LETRAS
    pintar(129,306,216,309);
    pintar(150,303,174,306);
    pintar(204,309,213,312);
    pintar(57,315,66,318);
    pintar(48,318,63,321);
    pintar(51,189,54,321);
    pintar(48,300,51,321);
    pintar(54,186,57,192);
    pintar(57,186,66,189);
    pintar(63,183,69,186);
    pintar(108,177,117,180);
    pintar(108,174,150,177);
    pintar(132,171,195,174);
    pintar(180,174,195,177);
    pintar(270,186,285,189);
    pintar(276,189,291,192);
    pintar(288,192,297,195);
    pintar(291,195,294,207);
    pintar(294,195,297,333);
    pintar(297,234,300,333);
    pintar(291,327,294,330);

    //-------------------------------------------------


    //DONDE SE ABRE
    pintar(105,507,231,510);
    pintar(213,510,255,513);
    pintar(243,513,267,516);
    pintar(261,516,279,519);
    pintar(270,519,285,522);
    pintar(279,522,288,525);
    pintar(285,525,291,528);
    pintar(288,528,294,531);
    pintar(288,531,294,534);
    pintar(285,534,291,537);
    pintar(267,522,276,525);
    pintar(258,525,273,528);
    pintar(249,528,267,531);
    pintar(237,531,258,534);
    pintar(231,534,246,537);
    pintar(81,510,120,513);
    pintar(66,513,96,516);
    pintar(57,516,75,519);
    pintar(51,519,66,522);
    pintar(48,522,54,525);
    pintar(45,525,51,528);
    pintar(45,528,48,531);
    pintar(45,531,54,534);
    pintar(48,534,54,537);
    pintar(60,522,72,525);
    pintar(66,525,81,528);
    pintar(69,528,84,531);
    pintar(102,534,111,537);
    pintar(102,537,135,540);
    pintar(120,540,144,543);
    pintar(123,510,132,513);
    pintar(126,513,135,516);
    pintar(129,516,138,519);
    pintar(135,519,144,522);
    pintar(141,522,153,525);
    pintar(141,525,147,528);
    pintar(144,528,150,531);
    pintar(147,531,153,534);
    pintar(150,534,159,537);
    pintar(156,537,162,540);
    pintar(159,540,168,543);
    pintar(165,543,210,546);
    pintar(207,540,216,543);
    pintar(213,534,219,540);
    pintar(210,531,216,534);
    pintar(207,528,213,531);
    pintar(204,525,210,528);
    pintar(197,522,207,525);
    pintar(191,519,204,522);
    pintar(186,516,197,519);
    pintar(186,510,191,516);
    pintar(137,510,143,513);
    pintar(167,510,173,513);
    pintar(140,513,170,516);
    pintar(150,519,189,522);
    pintar(156,522,180,525);
    pintar(159,525,177,528);

    //Linea arriba del circulo--------------------
pintar(315,432,322,438);
pintar(312,429,315,435);
pintar(306,426,312,432);
pintar(300,423,306,429);
pintar(294,420,300,426);
pintar(276,420,294,423);
pintar(267,417,282,420);
pintar(252,414,273,417);
pintar(237,411,261,414);
pintar(222,408,246,411);
pintar(195,405,228,408);
pintar(120,402,216,405);
pintar(102,405,144,408);
pintar(81,408,114,411);
pintar(72,411,90,414);
pintar(60,414,78,417);
pintar(48,417,66,420);
pintar(42,420,54,423);
pintar(33,423,48,426);
pintar(27,426,41,429);
pintar(20,429,33,432);
pintar(20,432,26,438);
//--------------------------------------------

    glEnd();
    //FIN BORDE --------------------------------------------

}

void myResize (int w, int h)
{
    win_data.Width = w;
    win_data.Height = ( h> 0 )? h: 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,win_data.Width/2,0,win_data.Height);

    glViewport(0, 0, win_data.Width/2, win_data.Height);
    myDisplay(1);

    glViewport(win_data.Width/2, 0, win_data.Width/2, win_data.Height);
    myDisplay(2);

    glMatrixMode(GL_MODELVIEW);
    glFlush();
    glutSwapBuffers();

}

void pintar(void){
  glClearColor(0.0,0.0,0.0,0.0);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  //Colores


  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0,win_data.Width/2,0,win_data.Height);

  glViewport(0, 0, win_data.Width/2, win_data.Height);
  myDisplay(1);

  glViewport(win_data.Width/2, 0, win_data.Width/2, win_data.Height);
  myDisplay(2);

  glMatrixMode(GL_MODELVIEW);
  glFlush();
  glutSwapBuffers();
  glutKeyboardFunc(KeyboardCbk);
  glutSpecialFunc(SpecialKeyboardCbk);
}

int main (int argc, char** argv)
{
  win_data.Width = std::atoi( argv[ 1 ] );
  win_data.Height = std::atoi( argv[ 2 ] );

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowPosition(200, 100);

    glutInitWindowSize(win_data.Width, win_data.Height);

    glutCreateWindow("Duff Beer - Duff Beer Negativo");

    glutDisplayFunc(pintar);
    glutReshapeFunc(myResize);

    myInit();

    glutMainLoop();
    return 0;

}
