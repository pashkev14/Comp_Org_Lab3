#include "stdio.h";
#include "math.h";
#include "dos.h";
#include "graphics.h";
#include "string.h";
#include "conio.h";

// declaring variables
int x_max, y_max;
float begin = 1.57; // equals to pi/2
float end = 18.84;  // equals to 6pi
float step = 0.001;
int x_top, y_top, x_left, y_left, x_bottom, y_bottom, x_right, y_right;
float x, y;
float max_value = 0;

int graph_driver;
int graph_mode;

int i, j;

char cmax_value[10];
char str[24];

int main() {
	clrscr();
	// init graphs
	graph_driver = DETECT;
	graph_mode = 0;
	initgraph(&graph_driver, &graph_mode, "C:\\TurboC3\\BGI");
	// define size of window
	x_max = getmaxx();
	y_max = getmaxy();
	// define plot key points
	x_top = x_bottom = 80;
	y_top = 20; y_bottom = y_max - 20;
	y_left = y_right = (y_bottom - y_top) / 2;
	x_left = 20; x_right = x_max - 20;
	// draw a frame
	setlinestyle(SOLID_LINE, 1, THICK_WIDTH);
	setcolor(LIGHTBLUE);
	rectangle(0, 0, x_max, y_max);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(20, 20, BLUE);
	// draw plot axes
	setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
	line(x_left, y_left, x_right, y_right);
	line(x_top, y_top, x_bottom, y_bottom);
	// draw arrows
	line(x_top - 5, y_top + 10, x_top, y_top);
	line(x_top + 5, y_top + 10, x_top, y_top);
	line(x_right - 10, y_right - 5, x_right, y_right);
	line(x_right - 10, y_right + 5, x_right, y_right);
	// display text
	setcolor(WHITE);
	outtextxy(x_top + 10, y_top + 10, "f(x) = cos^3(x)+sin^3(x)");
	outtextxy(x_top + 10, y_top - 10, "y");
	outtextxy(x_right, y_right + 10, "x");
	setcolor(LIGHTBLUE);
	// draw meters
	for (i = 0; i < 14; ++i) {
		line((x_left + (40 * i)) + 20, y_left, (x_left + (40 * i)) + 20, y_left - 5);
	}
	line(x_top, y_left - 180, x_top + 5, y_left - 180);
	line(x_top, y_left - 90, x_top + 5, y_left - 90);
	line(x_top, y_left + 90, x_top + 5, y_left + 90);
	line(x_top, y_left + 180, x_top + 5, y_left + 180);
	line(x_top + 31.4, y_left, x_top + 31.4, y_left - 5);
	line(x_top + 376.8, y_left, x_top + 376.8, y_left - 5);
	// display meters
	setcolor(WHITE);
	outtextxy(x_left + 10, y_left + 5, "-2");
	outtextxy(x_top - 10, y_left + 5, "0");
	outtextxy(x_left + 97, y_left + 5, "2");
	outtextxy(x_left + 137, y_left + 5, "4");
	outtextxy(x_left + 177, y_left + 5, "6");
	outtextxy(x_left + 217, y_left + 5, "8");
	outtextxy(x_left + 254, y_left + 5, "10");
	outtextxy(x_left + 294, y_left + 5, "12");
	outtextxy(x_left + 334, y_left + 5, "14");
	outtextxy(x_left + 374, y_left + 5, "16");
	outtextxy(x_left + 414, y_left + 5, "18");
	outtextxy(x_left + 454, y_left + 5, "20");
	outtextxy(x_left + 494, y_left + 5, "22");
	outtextxy(x_left + 534, y_left + 5, "24");
	outtextxy(x_top + 2, y_left + 5, "pi/2");
	outtextxy(x_left + 430, y_left + 5, "6pi");
	outtextxy(x_top - 10, y_left - 93, "1");
	outtextxy(x_top - 10, y_left - 183, "2");
	outtextxy(x_top - 20, y_left + 87, "-1");
	outtextxy(x_top - 20, y_left + 177, "-2");
	setcolor(LIGHTBLUE);
	// calculate max value
	x = begin;
	while (x < end) {
		y = (float)(pow(cos(x), 3.0) + pow(sin(x), 3.0));
		if (y > max_value) max_value = y;
		x += step;
	}
	// draw a graph
	x = begin;
	while (x < end) {
		y = (float)(pow(cos(x), 3.0) + pow(sin(x), 3.0));
		putpixel(x_top + (x * 20), y_left - (y * 90), LIGHTGREEN);
		x += step;
	}
	getch();
	// output max value to screen
	sprintf(cmax_value, "%f", max_value);
	strcpy(str, "max(f(x)) = ");
	strcat(str, cmax_value);
	setcolor(WHITE);
	outtextxy(x_bottom + 10, y_bottom + 10, str);
	// wait for "press any key to continue" and close the program
	getch();
	closegraph();
	return 0;
}