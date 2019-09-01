#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<glut.h>

//Game Speed
int FPS = 50;
//Game Track
int start = 0;
int gv = 0;
int level = 0;

//Track Score
int score = 0;

//For astr Left / RIGHT
int lrIndex = 0; //main astr

				 //astr Coming
int astr1 = 0;
int lrIndex1 = 0; //red astr
int astr2 = +35;
int lrIndex2 = 0;//violet astr
int astr3 = +70;
int lrIndex3 = 0;

//For Display TEXT
const int font1 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2 = (int)GLUT_BITMAP_HELVETICA_18;
const int font3 = (int)GLUT_BITMAP_8_BY_13;


void renderBitmapString(float x, float y, void *font, const char *string) {
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}


const float DEG2RAD = 3.14159 / 180;
void display1();

void stars();
int p;
void stars1();
void static_rocket();
void rocket_to_cam_pos();
void rocket_in_motion();
void moon(float radius);

float i, j,
count = 0,    /*used to count delay in launching*/
count1 = 0,  /*used to count blue sky delay*/
count3 = 0,  /*used to count black sky delay*/
flag = 0, flag1 = 0, t = 0, f = 0, flag3 = 0,
t1 = 0     /* used to translate rocket initially*/
;
void semicircle(float radius, float u, float v)//Antenna dish
{

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);

	for (int i = 135; i <= 315; i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex2f(u + cos(degInRad)*radius, v + (sin(degInRad))*radius);//100,100 specifies centre of the circle
	}

	glEnd();
}

void display1()
{

	count1++;
	//if(count1==250)
	  // flag=1;
	if (flag == 0)
		static_rocket();
	else if ((count1 == 751) || (count1 == 752))
		rocket_to_cam_pos();
	else
		rocket_in_motion();
}

void stars()
{

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(0.37);
	glBegin(GL_POINTS);
	glVertex2i(10, 20);
	glVertex2i(20, 100);
	glVertex2i(30, 10);
	glVertex2i(15, 150);
	glVertex2i(17, 80);
	glVertex2i(200, 200);
	glVertex2i(55, 33);
	glVertex2i(400, 300);
	glVertex2i(330, 110);
	glVertex2i(125, 63);
	glVertex2i(63, 125);
	glVertex2i(20, 10);
	glVertex2i(110, 330);
	glVertex2i(440, 430);
	glVertex2i(32, 65);
	glVertex2i(110, 440);
	glVertex2i(210, 230);
	glVertex2i(390, 490);
	glVertex2i(12, 90);
	glVertex2i(400, 322);
	glVertex2i(420, 366);
	glVertex2i(455, 400);
	glVertex2i(20, 20);
	glVertex2i(111, 120);
	glVertex2i(401, 200);
	glVertex2i(230, 30);
	glVertex2i(220, 20);
	glVertex2i(122, 378);
	glVertex2i(133, 340);
	glVertex2i(345, 420);
	glVertex2i(130, 360);
	glVertex2i(333, 120);
	glVertex2i(250, 22);
	glVertex2i(242, 11);
	glVertex2i(280, 332);
	glVertex2i(233, 40);
	glVertex2i(210, 418);
	glVertex2i(256, 12);
	glVertex2i(288, 232);
	glVertex2i(247, 36);
	glVertex2i(229, 342);
	glVertex2i(257, 47);
	glVertex2i(290, 63);
	glVertex2i(232, 72);
	glVertex2i(243, 143);
	glVertex2i(100, 200);
	glVertex2i(90, 250);
	glVertex2i(80, 225);
	glVertex2i(50, 333);
	glVertex2i(60, 350);
	glVertex2i(243, 143);
	glVertex2i(243, 143);
	glEnd();
}

void stars1()
{
	int l;
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(0.3);
	glBegin(GL_POINTS);
	glVertex2i(50, 20);
	glVertex2i(70, 100);
	glVertex2i(80, 10);
	glVertex2i(65, 150);
	glVertex2i(67, 80);
	glVertex2i(105, 33);
	glVertex2i(450, 300);
	glVertex2i(380, 110);
	glVertex2i(175, 63);
	glVertex2i(113, 125);
	glVertex2i(70, 10);
	glVertex2i(160, 330);
	glVertex2i(490, 430);
	glVertex2i(82, 65);
	glVertex2i(160, 440);
	glVertex2i(440, 490);
	glVertex2i(62, 90);
	glVertex2i(450, 322);
	glVertex2i(420, 366);
	glVertex2i(455, 400);
	glVertex2i(60, 20);
	glVertex2i(111, 120);
	glVertex2i(451, 200);
	glVertex2i(280, 30);
	glVertex2i(220, 20);
	glVertex2i(132, 378);
	glVertex2i(173, 340);
	glVertex2i(325, 420);
	glVertex2i(180, 360);
	glVertex2i(383, 120);
	glVertex2i(200, 22);
	glVertex2i(342, 11);
	glVertex2i(330, 332);
	glVertex2i(283, 40);
	glVertex2i(210, 418);
	glVertex2i(256, 12);
	glVertex2i(288, 232);
	glVertex2i(247, 36);
	glVertex2i(229, 342);
	glVertex2i(257, 47);
	glVertex2i(290, 63);
	glVertex2i(232, 72);
	glVertex2i(243, 143);
	glVertex2i(100, 200);
	glVertex2i(90, 250);
	glVertex2i(80, 225);
	glVertex2i(50, 333);
	glVertex2i(60, 350);
	glVertex2i(243, 143);
	glVertex2i(243, 143);
	glEnd();
	for (l = 0; l <= 10000; l++)
		;
}
void static_rocket()//before launch
{

	count1++;
	if (count1 == 750)
		flag = 1;
	if (flag == 0)
	{
		glClearColor(0.196078, 0.6, 0.8, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (t1>230)
		{
			glPushMatrix();
			glTranslatef(0, -t1 + 230, 0);
		}
		glColor3f(0.1, 0.5, 0.1);
		glBegin(GL_POLYGON);//green ground on side1 of the road
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 250.0);
		glVertex2f(270.0, 250.0);
		glVertex2f(500.0, 50.0);
		glVertex2f(500.0, 0.0);
		glEnd();
		glBegin(GL_POLYGON);//green ground on side2 of the road
		glVertex2f(280.0, 250.0);
		glVertex2f(500.0, 250.0);
		glVertex2f(500.0, 60.0);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);//road
		glVertex2f(260.0, 250.0);
		glVertex2f(290.0, 250.0);
		glVertex2f(500.0, 70.0);
		glVertex2f(500.0, 40.0);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);


		glColor3f(0.8, 0.498039, 0.196078);
		glBegin(GL_POLYGON);//house 1
		glVertex2f(250.0, 250.0);
		glVertex2f(300.0, 250.0);
		glVertex2f(300.0, 350.0);
		glVertex2f(250.0, 350.0);
		glEnd();
		glColor3f(0.7, 0.7, 0.7);
		glBegin(GL_POLYGON);//HOUSE windowA
		glVertex2f(255, 267.5);
		glVertex2f(275.0, 267.5);
		glVertex2f(275.0, 277.5);
		glVertex2f(255.0, 277.5);
		glEnd();
		glBegin(GL_POLYGON);//HOUSE windowB
		glVertex2f(255, 285.0);
		glVertex2f(275.0, 285);
		glVertex2f(275.0, 295);
		glVertex2f(255.0, 295);
		glEnd();

		glBegin(GL_POLYGON);//HOUSE windowC
		glVertex2f(255, 302.5);
		glVertex2f(275.0, 302.5);
		glVertex2f(275.0, 312.5);
		glVertex2f(255.0, 312.5);
		glEnd();

		glBegin(GL_POLYGON);//HOUSE windowD
		glVertex2f(255, 320.0);
		glVertex2f(275.0, 320.0);
		glVertex2f(275.0, 330.0);
		glVertex2f(255.0, 330.0);
		glEnd();

		glBegin(GL_POLYGON);//HOUSE windowE
		glVertex2f(285, 267.5);
		glVertex2f(295.0, 267.5);
		glVertex2f(295.0, 277.5);
		glVertex2f(285.0, 277.5);
		glEnd();

		glBegin(GL_POLYGON);//HOUSE windowF
		glVertex2f(285, 285.0);
		glVertex2f(295.0, 285);
		glVertex2f(295.0, 295);
		glVertex2f(285.0, 295);
		glEnd();

		glBegin(GL_POLYGON);//HOUSE windowG
		glVertex2f(285, 302.5);
		glVertex2f(295.0, 302.5);
		glVertex2f(295.0, 312.5);
		glVertex2f(285.0, 312.5);
		glEnd();

		glBegin(GL_POLYGON);//HOUSE windowH
		glVertex2f(285, 320.0);
		glVertex2f(295.0, 320.0);
		glVertex2f(295.0, 330.0);
		glVertex2f(285.0, 330.0);
		glEnd();
		glColor3f(0.5, 0.1, 0.1);
		glBegin(GL_POLYGON);//solid cone of antenna
		glVertex2f(26, 250);
		glVertex2f(52, 250);
		glVertex2f(39, 290);
		glEnd();
		semicircle(20.0, 50, 300);

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);//antenna wires
		glVertex2f(37, 313);
		glVertex2f(62, 310);
		glVertex2f(63, 287);
		glVertex2f(62, 310);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);

		glEnd();
		glPointSize(2.0);

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POINTS);//road paint
		glVertex2f(497, 56);
		glVertex2f(488, 65);
		glVertex2f(479, 74);
		glVertex2f(470, 83);
		glVertex2f(460, 92);
		glVertex2f(450, 101);
		glVertex2f(439, 110);
		glVertex2f(428, 119);
		glVertex2f(418, 128);
		glVertex2f(408, 137);
		glVertex2f(398, 146);
		glVertex2f(388, 155);
		glVertex2f(378, 164);
		glVertex2f(366, 173);
		glVertex2f(356, 182);
		glVertex2f(346, 191);
		glVertex2f(336, 200);
		glVertex2f(324, 209);
		glVertex2f(314, 218);
		glVertex2f(304, 227);
		glVertex2f(294, 234);
		glVertex2f(284, 243);
		glVertex2f(278, 248);

		glEnd();
		glPushMatrix();
		glTranslatef(0, t1, 0);
		t1++;
		glColor3f(0.8, 0.498039, 0.196078);
		glBegin(GL_POLYGON);//rocket core
		glVertex2f(237.5, 20.0);
		glVertex2f(262.5, 20.0);
		glVertex2f(262.5, 120.0);
		glVertex2f(237.5, 120.0);


		glEnd();

		glColor3f(1.0, 1.0, 1.0);//rocket bonnet
		glBegin(GL_POLYGON);//front
		glVertex2f(237.5, 120.0);
		glVertex2f(262.5, 120.0);
		glVertex2f(250, 170.0);
		glEnd();
		glColor3f(1.0, 0.0, 1.0);
		glBegin(GL_POLYGON);//left_side_top fin
		glVertex2f(237.5, 120.0);
		glVertex2f(217.5, 95.0);
		glVertex2f(237.5, 95.0);
		glEnd();
		glBegin(GL_POLYGON);//left_side_bottom fin
		glVertex2f(237.5, 20.0);
		glVertex2f(217.5, 20.0);
		glVertex2f(237.5, 70.0);
		glEnd();
		glBegin(GL_POLYGON);//right_side_bottom fin
		glVertex2f(262.5, 20.0);
		glVertex2f(282.5, 20.0);
		glVertex2f(262.5, 70.0);
		glEnd();
		glBegin(GL_POLYGON);//right_side_top fin
		glVertex2f(262.5, 120.0);
		glVertex2f(262.5, 95.0);
		glVertex2f(282.5, 95.0);
		glEnd();
		glColor3f(1.0, 0., 0.19608);
		glBegin(GL_POLYGON);//bottom_1_exhaust flame
		glVertex2f(237.5, 20.0);
		glVertex2f(244.5, 20.0);
		glVertex2f(241, 0.0);
		glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust flame
		glVertex2f(246.5, 20.0);
		glVertex2f(253.5, 20.0);
		glVertex2f(249.5, 0.0);
		glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust flame
		glVertex2f(262.5, 20.0);
		glVertex2f(255.5, 20.0);
		glVertex2f(258.5, 0.0);
		glEnd();



		for (j = 0; j <= 1000000; j++)
			;
		glPopMatrix();
		glPushMatrix();
		glTranslatef(200, 0, 0);
		glRotatef(t1, 0, 0, 1);
		glTranslatef(-200, 0, 0);
		glColor3f(0.543, 0.20321, 0.9);
		glBegin(GL_POLYGON);//left_stand_holder
		glVertex2f(182.5, 85.0);
		glVertex2f(182.5, 0.0);
		glVertex2f(187.5, 0.0);
		glVertex2f(187.5, 80.0);
		glVertex2f(237.5, 80.0);
		glVertex2f(237.5, 85.0);
		glVertex2f(182.5, 85.0);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(300, 0, 0);
		glRotatef(-t1, 0, 0, 1);
		glTranslatef(-300, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(312.5, 85.0);//right_stand_holder
		glVertex2f(312.5, 0.0);
		glVertex2f(307.5, 0.0);
		glVertex2f(307.5, 80.0);
		glVertex2f(262.5, 80.0);
		glVertex2f(262.5, 85.0);
		glVertex2f(312.5, 85.0);
		glEnd();
		glPopMatrix();
		glPopMatrix();
		if (t1>230)
			glPopMatrix();
	}
	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();
}
void rocket_to_cam_pos()//rocket after  launach but before outer space
{
	count++;
	count3++;

	for (i = 0; i <= 200; i++)
	{
		if (count1 == 751)
			glClearColor(0.0, 0, 1 - (i) / 200, 1.0);
		else glClearColor(0.0, 0, 0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glColor3f(0.8, 0.498039, 0.196078);
		glBegin(GL_POLYGON);//core after launach but before outer space
		glVertex2f(237.5, 20.0 + i);
		glVertex2f(262.5, 20.0 + i);
		glVertex2f(262.5, 120.0 + i);
		glVertex2f(237.5, 120.0 + i);


		glEnd();

		glColor3f(1.0, 1.0, 1.0);//bonnet
		glBegin(GL_POLYGON);//front
		glVertex2f(237.5, 120.0 + i);
		glVertex2f(262.5, 120.0 + i);
		glVertex2f(250, 170.0 + i);
		glEnd();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);//left_side_top fin
		glVertex2f(237.5, 120.0 + i);
		glVertex2f(217.5, 95.0 + i);
		glVertex2f(237.5, 95.0 + i);
		glEnd();
		glBegin(GL_POLYGON);//left_side_bottom fin
		glVertex2f(237.5, 20.0 + i);
		glVertex2f(217.5, 20.0 + i);
		glVertex2f(237.5, 70.0 + i);
		glEnd();
		glBegin(GL_POLYGON);//right_side_bottom fin
		glVertex2f(262.5, 20.0 + i);
		glVertex2f(282.5, 20.0 + i);
		glVertex2f(262.5, 70.0 + i);
		glEnd();
		glBegin(GL_POLYGON);//right_side_top fin
		glVertex2f(262.5, 120.0 + i);
		glVertex2f(262.5, 95.0 + i);
		glVertex2f(282.5, 95.0 + i);
		glEnd();
		glColor3f(0.556863, 0.137255, 0.419608);
		glBegin(GL_POLYGON);//bottom_1_exhaust
		glVertex2f(237.5, 20.0 + i);
		glVertex2f(244.5, 20.0 + i);
		glVertex2f(241, 0.0 + i);
		glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
		glVertex2f(246.5, 20.0 + i);
		glVertex2f(253.5, 20.0 + i);
		glVertex2f(249.5, 0.0 + i);
		glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
		glVertex2f(262.5, 20.0 + i);
		glVertex2f(255.5, 20.0 + i);
		glVertex2f(258.5, 0.0 + i);
		glEnd();

		if ((p % 2) == 0)
			glColor3f(1.0, 0.0, 0.2);
		else
			glColor3f(1.0, 0.0, 0.11);

		glBegin(GL_POLYGON);//outer fume
		glVertex2f(237.5, 20 + i);
		glVertex2f(234.16, 16.66 + i);
		glVertex2f(230.82, 13.32 + i);
		glVertex2f(227.48, 9.98 + i);
		glVertex2f(224.14, 6.64 + i);
		glVertex2f(220.8, 3.3 + i);
		glVertex2f(217.5, 0 + i);
		glVertex2f(221.56, -5 + i);
		glVertex2f(225.62, -10 + i);
		glVertex2f(229.68, -15 + i);
		glVertex2f(233.74, -20 + i);
		glVertex2f(237.8, -25 + i);
		glVertex2f(241.86, -30 + i);
		glVertex2f(245.92, -35 + i);
		glVertex2f(250, -40 + i);
		glVertex2f(254.06, -35 + i);
		glVertex2f(258.12, -30 + i);
		glVertex2f(262.18, -25 + i);
		glVertex2f(266.24, -20 + i);
		glVertex2f(270.3, -15 + i);
		glVertex2f(274.36, -10 + i);
		glVertex2f(278.42, -5 + i);
		glVertex2f(282.5, 0 + i);
		glVertex2f(278.5, 4 + i);
		glVertex2f(274.5, 8 + i);
		glVertex2f(270.5, 12 + i);
		glVertex2f(266.5, 16 + i);
		glVertex2f(262.5, 20 + i);//28 points
		glEnd();

		if ((p % 2) == 0)
			glColor3f(1.0, 0.816, 0.0);
		else
			glColor3f(1.0, 0.25, 0.0);

		glBegin(GL_POLYGON);//inner fume
		glVertex2f(237.5, 20 + i);
		glVertex2f(236.5, 17.5 + i);
		glVertex2f(235.5, 15 + i);
		glVertex2f(234.5, 12.5 + i);
		glVertex2f(233.5, 10 + i);
		glVertex2f(232.5, 7.5 + i);
		glVertex2f(236, 5 + i);
		glVertex2f(239.5, 2.5 + i);
		glVertex2f(243, 0 + i);
		glVertex2f(246.5, -2.5 + i);
		glVertex2f(250, -5 + i);
		glVertex2f(253.5, -2.5 + i);
		glVertex2f(257, 0 + i);
		glVertex2f(260.5, 2.5 + i);
		glVertex2f(264, 5 + i);
		glVertex2f(267.5, 7.5 + i);
		glVertex2f(266.5, 10 + i);
		glVertex2f(265.5, 12.5 + i);
		glVertex2f(264.5, 15 + i);
		glVertex2f(263.5, 17.5 + i);
		glVertex2f(262.5, 20 + i);//21 points

		glEnd();
		p = p + 1;
		for (j = 0; j <= 1000000; j++)
			;
		glutSwapBuffers();
		//	glutPostRedisplay();
		glFlush();
	}
}
void rocket_in_motion()//rocket in outer space
{
	count++;


	for (i = 195; i <= 200; i++)
	{
		if (count >= 5)
		{
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			if (flag1 == 0)
			{
				stars();
				flag1 = 1;
			}
			else
			{
				stars1();

				flag1 = 0;
			}

		}
		else
		{
			glClearColor(0.0, 0, 0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		if (count >= 100)
			moon(20.0);


		glColor3f(0.8, 1.498039, 0.0);
		glBegin(GL_POLYGON);//core of the rocket
		glVertex2f(lrIndex + 237.5, -100.0 + i);
		glVertex2f(lrIndex + 262.5, -100.0 + i);
		glVertex2f(lrIndex + 262.5, 10.0 + i);
		glVertex2f(lrIndex + 237.5, 10.0 + i);


		glEnd();

		glColor3f(1.0, 1.0, 1.0);//bonnet
		glBegin(GL_POLYGON);//front
		glVertex2f(lrIndex + 237.5, 10.0 + i);
		glVertex2f(lrIndex + 262.5, 10.0 + i);
		glVertex2f(lrIndex + 250, 60.0 + i);
		glEnd();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);//left_side_top fin
		glVertex2f(lrIndex + 237.5, 10.0 + i);
		glVertex2f(lrIndex + 217.5, -15.0 + i);
		glVertex2f(lrIndex + 237.5, -15.0 + i);
		glEnd();
		glBegin(GL_POLYGON);//left_side_bottom fin
		glVertex2f(lrIndex + 237.5, -100.0 + i);
		glVertex2f(lrIndex + 217.5, -100.0 + i);
		glVertex2f(lrIndex + 237.5, -50.0 + i);
		glEnd();
		glBegin(GL_POLYGON);//right_side_bottom fin
		glVertex2f(lrIndex + 262.5, -100.0 + i);
		glVertex2f(lrIndex + 282.5, -100.0 + i);
		glVertex2f(lrIndex + 262.5, -50.0 + i);
		glEnd();
		glBegin(GL_POLYGON);//right_side_top fin  
		glVertex2f(lrIndex + 262.5, 10.0 + i);
		glVertex2f(lrIndex + 262.5, -15.0 + i);
		glVertex2f(lrIndex + 282.5, -15.0 + i);
		glEnd();
		glColor3f(0.556863, 0.137255, 0.419608);
		glBegin(GL_POLYGON);//bottom_1_exhaust
		glVertex2f(lrIndex + 237.5, -100.0 + i);
		glVertex2f(lrIndex + 244.5, -100.0 + i);
		glVertex2f(lrIndex + 241, -100.0 + i);
		glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
		glVertex2f(lrIndex + 246.5, -100.0 + i);
		glVertex2f(lrIndex + 253.5, -100.0 + i);
		glVertex2f(lrIndex + 249.5, -100.0 + i);
		glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
		glVertex2f(lrIndex + 262.5, -100.0 + i);
		glVertex2f(lrIndex + 255.5, -100.0 + i);
		glVertex2f(lrIndex + 258.5, -100.0 + i);
		glEnd();
		if ((p % 2) == 0)
			glColor3f(1.0, 0.25, 0.0);
		else
			glColor3f(1.0, 0.816, 0.0);

		glBegin(GL_POLYGON);//outer fume
		glVertex2f(lrIndex + 237.5, -100 + i);
		glVertex2f(lrIndex + 234.16, -104.44 + i);
		glVertex2f(lrIndex + 230.82, -107.78 + i);
		glVertex2f(lrIndex + 227.48, -111.12 + i);
		glVertex2f(lrIndex + 224.14, -114.46 + i);
		glVertex2f(lrIndex + 220.8, -117.7 + i);
		glVertex2f(lrIndex + 217.5, -120 + i);
		glVertex2f(lrIndex + 221.56, -125 + i);
		glVertex2f(lrIndex + 225.62, -130 + i);
		glVertex2f(lrIndex + 229.68, -135 + i);
		glVertex2f(lrIndex + 233.74, -140 + i);
		glVertex2f(lrIndex + 237.8, -145 + i);
		glVertex2f(lrIndex + 241.86, -150 + i);
		glVertex2f(lrIndex + 245.92, -155 + i);
		glVertex2f(lrIndex + 250, -160 + i);
		glVertex2f(lrIndex + 254.06, -165 + i);
		glVertex2f(lrIndex + 258.12, -150 + i);
		glVertex2f(lrIndex + 262.18, -145 + i);
		glVertex2f(lrIndex + 266.24, -140 + i);
		glVertex2f(lrIndex + 270.3, -135 + i);
		glVertex2f(lrIndex + 274.36, -130 + i);
		glVertex2f(lrIndex + 278.42, -125 + i);
		glVertex2f(lrIndex + 282.5, -120 + i);
		glVertex2f(lrIndex + 278.5, -116 + i);
		glVertex2f(lrIndex + 274.5, -112 + i);
		glVertex2f(lrIndex + 270.5, -108 + i);
		glVertex2f(lrIndex + 266.5, -104 + i);
		glVertex2f(lrIndex + 262.5, -100 + i);//28 points
		glEnd();

		if ((p % 2) == 0)
			glColor3f(1.0, 0.816, 0.0);
		else
			glColor3f(1.0, 0.25, 0.0);

		glBegin(GL_POLYGON);//inner fume
		glVertex2f(lrIndex + 237.5, -100 + i);
		glVertex2f(lrIndex + 236.5, -103.5 + i);
		glVertex2f(lrIndex + 235.5, -105 + i);
		glVertex2f(lrIndex + 234.5, -108.5 + i);
		glVertex2f(lrIndex + 233.5, -110 + i);
		glVertex2f(lrIndex + 232.5, -113.5 + i);
		glVertex2f(lrIndex + 236, -115 + i);
		glVertex2f(lrIndex + 239.5, -118.5 + i);
		glVertex2f(lrIndex + 243, -120 + i);
		glVertex2f(lrIndex + 246.5, -122.5 + i);
		glVertex2f(lrIndex + 250, -125 + i);
		glVertex2f(lrIndex + 253.5, -122.5 + i);
		glVertex2f(lrIndex + 257, -120 + i);
		glVertex2f(lrIndex + 260.5, -122.5 + i);
		glVertex2f(lrIndex + 264, -125 + i);
		glVertex2f(lrIndex + 267.5, -127.5 + i);
		glVertex2f(lrIndex + 266.5, -130 + i);
		glVertex2f(lrIndex + 265.5, -132.5 + i);
		glVertex2f(lrIndex + 264.5, -135 + i);
		glVertex2f(lrIndex + 263.5, -137.5 + i);
		glVertex2f(lrIndex + 262.5, -140 + i);//21 points

		glEnd();
		p = p + 1;


		//Score Board On The Running Game Screen
		glColor3f(1.000, 0.000, 0.000);
		glBegin(GL_POLYGON);
		glVertex2f(10, 90);
		glVertex2f(110, 90);
		glVertex2f(110, 90 - 40);
		glVertex2f(10, 90 - 40);
		glEnd();
		//Asteroid 
		//Opposite Asteroid1
		glColor3f(1.000, 0.000, 0.000);
		glBegin(GL_POLYGON);//Body of the asteroid
		glVertex2f(lrIndex1 + 95, astr1 + 500);
		glVertex2f(lrIndex1 + 105, astr1 + 510 - 9);

		glVertex2f(lrIndex1 + 110, astr1 + 505 - 2);
		glVertex2f(lrIndex1 + 99, astr1 + 495 - 7);

		glVertex2f(lrIndex1 + 140, astr1 + 509 - 7);
		glVertex2f(lrIndex1 + 142, astr1 + 514);

		glVertex2f(lrIndex1 + 95 + 2, astr1 + 500 - 2);
		glEnd();
		astr1--;
		if (astr1<-500) {
			astr1 = 0;
			lrIndex1 = lrIndex;
			printf("%d", astr1);
		}
		//KIll check asteroid
		if ((abs(lrIndex - lrIndex1)<8) && (astr1 + 500<10)) {
			start = 0;
			gv = 1;


		}
		//Opposite asteroid 2
		glColor3f(0.294, 0.00, 0.510);
		glBegin(GL_POLYGON);//Body of the asteroid
		glVertex2f(lrIndex2 + 400, astr2 + 399);
		glVertex2f(lrIndex2 + 420, astr2 + 410 - 7);
		glVertex2f(lrIndex2 + 430 - 2, astr2 + 430 - 2);
		glVertex2f(lrIndex2 + 447 + 2, astr2 + 435 - 2);

		glVertex2f(lrIndex2 + 450 - 2, astr2 + 399 - 2);
		glVertex2f(lrIndex2 + 400 + 2, astr2 + 388 - 2);

		glVertex2f(lrIndex2 + 410, astr2 + 390);
		glEnd();
		astr2--;
		if (astr2<-500) {
			astr2 = 0;
			//Score
			score++;
			lrIndex2 = lrIndex;
		}
		//KIll check asteroid2
		if ((abs(lrIndex - lrIndex2)<8) && (astr2 + 500<10)) {
			start = 0;
			gv = 1;
		}


		//Opposite asteroid 3
		glColor3f(0.02390, 0.571, 0.0);
		glBegin(GL_POLYGON);//Body of the asteroid
		glVertex2f(lrIndex3 + 270, astr3 + 500);
		glVertex2f(lrIndex3 + 280, astr3 + 520 - 7);
		glVertex2f(lrIndex3 + 330, astr3 + 500 - 9);
		glVertex2f(lrIndex3 + 310 - 2, astr3 + 490 - 2);
		glVertex2f(lrIndex3 + 295 + 2, astr3 + 500 - 2);
		glEnd();
		astr3--;
		if (astr3<-500) {
			astr3 = 0;
			lrIndex3 = lrIndex;
		}
		//KIll check asteroid3

		if ((abs(lrIndex - lrIndex3)<8) && (astr3 + 500<10)) {
			start = 0;
			gv = 1;

		}



		//Print Score inside score board
		char buffer[50];
		sprintf_s(buffer, "SCORE: %d", score);
		glColor3f(0.000, 1.000, 0.000);
		renderBitmapString(12, 78, (void *)font3, buffer);

		//Speed Print  inside score board
		char buffer1[50];
		sprintf_s(buffer1, "SPEED:%dKm/h", FPS);
		glColor3f(0.000, 1.000, 0.000);
		renderBitmapString(12, 90 - 22, (void *)font3, buffer1);
		//level Print  inside score board
		if (score % 50 == 0) {
			int last = score / 50;
			if (last != level) {
				level = score / 50;
				FPS = FPS + 2;
			}
		}
		char level_buffer[50];
		sprintf_s(level_buffer, "LEVEL: %d", level);
		glColor3f(0.000, 1.000, 0.000);
		renderBitmapString(12, 90 - 32, (void *)font3, level_buffer);

		if (gv == 1)
		{
			glClearColor(0.009, 0.0077, 0.397845, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(1.000, 1.000, 1.070);
			renderBitmapString(190, 260 + 10, (void *)font1, "GAME OVER");
			renderBitmapString(139, 220 + 10, (void *)font1, "SPACEBAR TO RESTART");
			renderBitmapString(179, 190 + 10, (void *)font1, "ESC TO EXIT");

		}


		for (j = 0; j <= 1000000; j++)
			;


		glutSwapBuffers();
		glutPostRedisplay();
		glFlush();
	}

}
//Special functions
void spe_key(int key, int x, int y)
{

	switch (key) {
	case GLUT_KEY_DOWN://FPS is initially 50
		if (FPS>(50 + (level * 2)))
			FPS = FPS - 2;
		break;
	case GLUT_KEY_UP:
		FPS = FPS + 2;
		break;

	case GLUT_KEY_LEFT:
		if (lrIndex >= -100) {
			lrIndex = lrIndex - (FPS / 10);//(FPS/10)gives speed of left movement
			if (lrIndex<-100) {
				lrIndex = -101;
			}
		}
		break;


	case GLUT_KEY_RIGHT://44 indictaes border of the road
		if (lrIndex <= 150) {
			lrIndex = lrIndex + (FPS / 10);
			if (lrIndex>600) {
				lrIndex = 45;
			}
		}
		break;

	default:
		break;
	}

}

void processKeys(unsigned char key, int x, int y) {

	switch (key)
	{
	case ' ':
		if (start == 0) {
			start = 1;
			gv = 0;
			FPS = 50;
			lrIndex = 0;
			astr1 = 0;
			lrIndex1 = 0;
			astr2 = +35;
			lrIndex2 = 0;
			astr3 = +70;
			lrIndex3 = 0;
			score = 0;
			level = 0;
		}
		break;

	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void moon(float radius)//moon
{

	
	glBegin(GL_POLYGON);

	for (int i = 0; i <= 359; i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex2f(300 + f + cos(degInRad)*radius, 500 - t + (sin(degInRad))*radius);
		//100,100 specifies centre of the circle
	}

	glEnd();
	t = t + 0.1;
	f = f + 0.1;
}


void myinit()
{
	
	glClearColor(0.196078, 0.6, 0.8, 1.0);


	glPointSize(1.0);
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("rocket");

	glutIdleFunc(display1);
	glutDisplayFunc(display1);
	glutSpecialFunc(spe_key);
	glutKeyboardFunc(processKeys);

	myinit();


	glutMainLoop();
	return 0;
}

