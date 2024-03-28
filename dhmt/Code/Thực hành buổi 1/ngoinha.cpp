#include <GL/glut.h>
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f(0.25, 0.25, 0);
		glVertex3f(0.75, 0.25, 0);
		glVertex3f(0.75, 0.75, 0);
		glVertex3f(0.25, 0.75, 0);
	glEnd();

	//===========================
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.75, 0.75, 0);
		glVertex3f(0.25, 0.75, 0);
		glVertex3f(0.5, 1, 0);
	glEnd();

	glFlush();
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
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