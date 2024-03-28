#include <GL/glut.h>
#include <cmath>
void display(void) {
	GLfloat step = 3.14 / 90; 
	register int i; // đỉnh từ 0->9
	GLfloat angle, r; // góc quay và bán kính
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 180; ++i) 
		{
			r = (i % 2 == 0 ? 5 : 12);
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