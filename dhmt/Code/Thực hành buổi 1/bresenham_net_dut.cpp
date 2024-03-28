#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <cmath>
int cnt = 0;
void bresenham(int x1, int y1, int x2, int y2) {
	int x, y, dx, dy, d;
	x = x1, y = y1, dx = x2 - x1, dy = y2 - y1;
	d = dx - 2 * dy;
	while (x < x2) {
		cnt++;
		if (cnt % 20 == 0) // cứ 20 lần thì vẽ 1 phát
			for (int i = -5; i < 5; i++) glVertex2i(x, y + i); // vẽ 10 điểm 5 trên 5 dưới để tăng độ dày đường thẳng
		if (d > 0) d -= 2 * dy;
		else {
			d += 2 * dx;
			y++;
		}
		x++;
	}
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0); // r = 1.0, g = 0, b = 0 ==> ngôi sao màu đỏ
	glBegin(GL_POINTS);
		bresenham(10, 10, 150, 120); // dx > dy để đảm bảo sự biến thiên x > y
	glEnd();



	glFlush();
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50, 200, -50, 200, -1.0, 1.0);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);// Khởi tạo Glut và xử lí mọi dòng lệnh đối số, glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// sử dụng mô hình RGBA
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(800, 400);
	glutCreateWindow("hello");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}