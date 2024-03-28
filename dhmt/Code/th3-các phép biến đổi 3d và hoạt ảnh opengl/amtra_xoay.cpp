#include <GL/glut.h>
int angle = 0.0;
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity(); /* clear the matrix */
	/* viewing transformation */
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glScalef(1.0, 2.0, 1.0); /* modeling transformation */
	glRotatef(angle, 1, 1, 1); // quay quanh đường chéo tạo bởi 1, 1, 1 và gốc toạ độ
	//glutWireCube(1.0);
	glutWireTeapot(1.0);
	glutSwapBuffers(); // lệnh đổi chỗ
	glFlush();
}

// tương tác sự kiện chuột
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		angle = (angle + 2) % 360;
		glutPostRedisplay(); // vẽ lại ảnh
	}
}

// tương tác với bàn phím
void keyboard(unsigned char key, int x, int y) {
	if (key == 'a') {
		angle = (angle + 2) % 360;
		glutPostRedisplay(); // vẽ lại ảnh
	}
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0); // phep chieu phoi canh
	glOrtho(-2.0, 2.0, -2.0, 2.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}