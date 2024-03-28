//#include<glut.h>
#include<GL/glut.h>
//void display(void)
//{
//    glBegin(GL_TRIANGLES);
//    glVertex3f(0, 0, 0);
//    glVertex3f(0.8, 0, 0);
//    glVertex3f(0, 0.8, 0);
//
//    glEnd();
//    glFlush();
//}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glFlush();
}

//int main(int argc, char* argv[])
//{
//    glutInit(&argc, argv);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(1, 1);
//    glutCreateWindow("Triangle");
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);// Khởi tạo Glut và xử lí mọi dòng lệnh đối số, glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// sử dụng mô hình RGBA
	glutInitWindowSize(250, 250);// kích cỡ cửa sổ 
	glutInitWindowPosition(800, 400);// chỉ ra vị trí màn hình góc trên bên trái
	glutCreateWindow("hello"); // Tạo tiêu đề cửa sổ “hello”
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
