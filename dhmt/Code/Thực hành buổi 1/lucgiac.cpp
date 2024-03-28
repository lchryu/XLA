#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <cmath>
void display(void) {
	GLfloat step = M_PI/ 3; // mỗi góc 60 độ
	register int i; // đỉnh từ 0->5
	GLfloat angle, r; // góc quay và bán kính
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0); // r = 1.0, g = 0, b = 0 ==> ngôi sao màu đỏ
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; ++i)
	{
		//r = (i % 2 == 0 ? 5 : 12); // bán kính nhỏ = 5, bán kính lớn = 12
		r = 12;
		angle = i * step; 
		glVertex3f(r * cos(angle), r * sin(angle), 0.0);
	}
	glEnd();



	glFlush();
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-15, 15, -15, 15, -1.0, 1.0);
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