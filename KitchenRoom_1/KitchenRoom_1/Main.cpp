#include "glut.h"
#include <math.h>

bool light_1_On = false;
GLfloat rotationAngle = 0.5f;
GLfloat len = 0.8, thickness = 0.05;

void DrawTable() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glShadeModel(GL_SMOOTH);
	GLfloat mat_specular[] = { 0.521, 0.376, 0.247, 1.0 };
	GLfloat mat_diffuse[] = { 0.521, 0.376, 0.247, 1.0 };
	GLfloat mat_ambient[] = { 0.521, 0.376, 0.247, 1.0 };
	GLfloat mat_shininess = 5.0;
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
	/// Table top
	glPushMatrix();
	glColor3d(0, 1, 0);
	glTranslatef(0.0f, -6.0f, 0.0f);
	glScalef(2.0, thickness, 1.5);
	glutSolidCube(len);
	glPopMatrix();

	/// Table Legs
	glColor3d(0, 1, 0);
	static GLUquadric* gluQuadric = gluNewQuadric();
	glPushMatrix();
	glTranslatef(-len + thickness, -6 ,3 * len / 4 - thickness);
	glRotatef(90, 1, 0, 0);
	gluCylinder(gluQuadric, thickness, thickness, 1.5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(len - thickness, -6, 3 * len / 4 - thickness);
	glRotatef(90, 1, 0, 0);
	gluCylinder(gluQuadric, thickness, thickness, 1.5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-len + thickness, -6, -3 * len / 4 + thickness);
	glRotatef(90, 1, 0, 0);
	gluCylinder(gluQuadric, thickness, thickness, 1.5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(len - thickness, -6, -3 * len / 4 + thickness);
	glRotatef(90, 1, 0, 0);
	gluCylinder(gluQuadric, thickness, thickness, 1.5, 50, 50);
	glPopMatrix();
	glPopAttrib();
}

void DrawChair() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glShadeModel(GL_SMOOTH);
	GLfloat mat_specular[] = { 0.521, 0.376, 0.247, 1.0 };
	GLfloat mat_diffuse[] = { 0.521, 0.376, 0.247, 1.0 };
	GLfloat mat_ambient[] = { 0.521, 0.376, 0.247, 1.0 };
	GLfloat mat_shininess = 5.0;
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	// Chair Seat
	glPushMatrix();
	glColor3d(0.545, 0.271, 0.075);
	glTranslatef(-len + thickness + 1.2, -5.7f, 2.45f);
	glRotated(90, 1, 0, 0);
	glScalef(1.0, thickness, 1.0);
	glutSolidCube(len - 2 * thickness); // Điều chỉnh kích thước ghế so với bàn
	glPopMatrix();

	glPushMatrix();
	glColor3d(0, 1, 0);
	glTranslatef(-len + thickness + 1.2, -6.0f, 2.1f);
	glScalef(1.0, thickness, 1.0);
	glutSolidCube(len - 2 * thickness); // Điều chỉnh kích thước ghế so với bàn
	glPopMatrix();

	// Chair Legs
	glColor3d(0, 1, 0);
	static GLUquadric* gluQuadric = gluNewQuadric();

	glPushMatrix();
	glTranslatef(-len + thickness + 1, -6, 2);
	glRotatef(90, 1, 0, 0);
	gluCylinder(gluQuadric, thickness, thickness, 4, 50, 50); // Điều chỉnh chiều cao của chân ghế
	glPopMatrix();

	glPushMatrix();
	glTranslatef(len - thickness, -6, 2);
	glRotatef(90, 1, 0, 0);
	gluCylinder(gluQuadric, thickness, thickness, 4, 50, 50); // Điều chỉnh chiều cao của chân ghế
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-len + thickness + 1, -6, 2.4);
	glRotatef(90, 1, 0, 0);
	gluCylinder(gluQuadric, thickness, thickness, 4, 50, 50); // Điều chỉnh chiều cao của chân ghế
	glPopMatrix();

	glPushMatrix();
	glTranslatef(len - thickness, -6, 2.4);
	glRotatef(90, 1, 0, 0);
	gluCylinder(gluQuadric, thickness, thickness, 4, 50, 50); // Điều chỉnh chiều cao của chân ghế
	glPopMatrix();

	glPopAttrib();
}

void DrawKitchenCounter() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glShadeModel(GL_SMOOTH);
	GLfloat mat_specular[] = { 0.521, 0.376, 0.247, 1.0 };
	GLfloat mat_diffuse[] = { 0.521, 0.376, 0.247, 1.0 };
	GLfloat mat_ambient[] = { 0.521, 0.376, 0.247, 1.0 };
	GLfloat mat_shininess = 5.0;
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	// Kitchen Counter Top
	glPushMatrix();
	glColor3d(0.545, 0.271, 0.075); // Màu gỗ
	glTranslatef(-1.0f, -6.2f, -2.1f); // Điều chỉnh vị trí
	glScalef(1.0, thickness, 0.5); // Điều chỉnh kích thước
	glutSolidCube(len * 2); // Điều chỉnh kích thước
	glPopMatrix();

	// Kitchen Counter Legs
	glColor3d(0.545, 0.271, 0.075); // Màu gỗ
	static GLUquadric* gluQuadric = gluNewQuadric();

	glPopAttrib();
}

void DrawCabinet() {
	float room_size = 10.0f; // Kích thước căn phòng

	// Tính toán vị trí của các mặt phẳng
	float left = -room_size / 2.0f;
	float right = room_size / 2.0f;
	float bottom = -room_size / 2.0f;
	float top = room_size / 2.0f;
	float back = -room_size / 2.0f;
	float front = room_size / 2.0f;

	GLfloat wood_color[] = { 0.55f, 0.27f, 0.07f, 1.0f }; // Màu gỗ

	// Sử dụng màu gỗ cho tủ bếp
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, wood_color);

	// Kích thước mới cho tủ bếp
	float cabinet_width = 6.0f;
	float cabinet_height = 2.0f;
	float cabinet_depth = 1.0f;

	// Vị trí mới cho tủ bếp
	float cabinet_x = left + room_size * 0.1f;
	float cabinet_y = bottom + room_size * 0.05f;
	float cabinet_z = back + room_size * 0.1f;

	// Vẽ tủ bếp (hình hộp)
	glBegin(GL_QUADS);
	// Mặt trước
	glVertex3f(cabinet_x, cabinet_y, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y + cabinet_height, cabinet_z);
	glVertex3f(cabinet_x, cabinet_y + cabinet_height, cabinet_z);

	// Mặt dưới
	glVertex3f(cabinet_x, cabinet_y, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y, cabinet_z + cabinet_depth);
	glVertex3f(cabinet_x, cabinet_y, cabinet_z + cabinet_depth);

	// Mặt trên
	glVertex3f(cabinet_x, cabinet_y + cabinet_height, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y + cabinet_height, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y + cabinet_height, cabinet_z + cabinet_depth);
	glVertex3f(cabinet_x, cabinet_y + cabinet_height, cabinet_z + cabinet_depth);

	// Mặt sau
	glVertex3f(cabinet_x, cabinet_y, cabinet_z + cabinet_depth);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y, cabinet_z + cabinet_depth);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y + cabinet_height, cabinet_z + cabinet_depth);
	glVertex3f(cabinet_x, cabinet_y + cabinet_height, cabinet_z + cabinet_depth);
	glEnd();
}

void DrawCabinetPerpendicular() {
	float room_size = 10.0f; // Kích thước căn phòng

	// Tính toán vị trí của các mặt phẳng
	float left = -room_size / 2.0f;
	float right = room_size / 2.0f;
	float bottom = -room_size / 2.0f;
	float top = room_size / 2.0f;
	float back = -room_size / 2.0f;
	float front = room_size / 2.0f;

	GLfloat wood_color[] = { 0.55f, 0.27f, 0.07f, 1.0f }; // Màu gỗ

	// Sử dụng màu gỗ cho tủ bếp
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, wood_color);

	// Kích thước mới cho tủ bếp
	float cabinet_width =2.0f;
	float cabinet_height = 2.0f;
	float cabinet_depth = 3.5f;

	// Vị trí mới cho tủ bếp
	float cabinet_x = left + room_size * 0.005f;
	float cabinet_y = bottom + room_size * 0.01f;
	float cabinet_z = back + room_size * 0.05f;

	// Vẽ tủ bếp (hình hộp)
	glBegin(GL_QUADS);
	// Mặt trước
	glVertex3f(cabinet_x, cabinet_y, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y + cabinet_height, cabinet_z);
	glVertex3f(cabinet_x, cabinet_y + cabinet_height, cabinet_z);

	// Mặt dưới
	glVertex3f(cabinet_x, cabinet_y, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y, cabinet_z + cabinet_depth);
	glVertex3f(cabinet_x, cabinet_y, cabinet_z + cabinet_depth);

	// Mặt trên
	glVertex3f(cabinet_x, cabinet_y + cabinet_height, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y + cabinet_height, cabinet_z);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y + cabinet_height, cabinet_z + cabinet_depth);
	glVertex3f(cabinet_x, cabinet_y + cabinet_height, cabinet_z + cabinet_depth);

	// Mặt sau
	glVertex3f(cabinet_x, cabinet_y, cabinet_z + cabinet_depth);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y, cabinet_z + cabinet_depth);
	glVertex3f(cabinet_x + cabinet_width, cabinet_y + cabinet_height, cabinet_z + cabinet_depth);
	glVertex3f(cabinet_x, cabinet_y + cabinet_height, cabinet_z + cabinet_depth);
	glEnd();
}

void DrawFan() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glShadeModel(GL_SMOOTH);
	GLfloat mat_specular[] = { 0.784, 0.776, 0.654, 1.0 };
	GLfloat mat_diffuse[] = { 0.784, 0.776, 0.654, 1.0 };
	GLfloat mat_ambient[] = { 0.784, 0.776, 0.654, 1.0 };
	GLfloat mat_shininess = 5.0;
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	// Vị trí và kích thước mới cho quạt
	float fan_x = 2.0f; // Vị trí theo trục x
	float fan_y = 5.0f; // Vị trí theo trục y
	float fan_z = 3.0f; // Vị trí theo trục z
	float fan_scale = 1.0f; // Tỉ lệ kích thước

	glTranslatef(fan_x, fan_y, fan_z);
	glScalef(fan_scale, fan_scale, fan_scale);
	//glRotatef(90, 1, 0, 0);
	//Cube
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(1, 1.2, 1);
	glScalef(.5, .4, .5);
	glTranslatef(0, -2.0, 0);
	glScalef(1.0f, 0.7f, 1.0f);
	glTranslatef(0, -0.5, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
	glTranslatef(0, -1.05, 0);
	glScalef(0.15, .15, .15);
	glTranslatef(0.0f, -2.2f, 0.0f);
	glBegin(GL_QUAD_STRIP);
	for (int j = 0; j <= 360; j += 5) {
		glColor3f(0.302, 0.149, 0.0);
		glVertex3f(cos(j), +1, sin(j));
		glColor3f(0.6, 0.302, 0.0);
		glVertex3f(cos(j), -1, sin(j));
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(.3, .3, .3);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, 1.55);
	glScalef(.25, .25, .25);
	glutSolidTorus(.1, .72, 25, 25);
	glPopMatrix();

	glPushMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.4);
	glTranslatef(-1, -1.55, 0);
	glScalef(2.5, .1, .75);
	glutSolidCube(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.55, 0);
	glScalef(0.05, .11, .05);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -5);
	glScalef(1, 1, 2.4);
	glBegin(GL_QUAD_STRIP);
	for (int j = 0; j <= 360; j += 5) {
		glColor3f(.3, .3, .3);
		glVertex3f(cos(j), +1, sin(j));
		glColor3f(.7, .7, .7);
		glVertex3f(cos(j), -1, sin(j));
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.4);
	glTranslatef(-1, -1.55, 0);
	glScalef(2.5, .1, .75);
	glutSolidCube(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.55, 0);
	glScalef(0.05, .11, .05);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -5);
	glScalef(1, 1, 2.4);
	glBegin(GL_QUAD_STRIP);
	for (int j = 0; j <= 360; j += 5) {
		glColor3f(.3, .3, .3);
		glVertex3f(cos(j), +1, sin(j));
		glColor3f(.7, .7, .7);
		glVertex3f(cos(j), -1, sin(j));
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.4);
	glTranslatef(-1, -1.55, 0);
	glScalef(2.5, .1, .75);
	glutSolidCube(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.55, 0);
	glScalef(0.05, .11, .05);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -5);
	glScalef(1, 1, 2.4);
	glBegin(GL_QUAD_STRIP);
	for (int j = 0; j <= 360; j += 5) {
		glColor3f(.3, .3, .3);
		glVertex3f(cos(j), +1, sin(j));
		glColor3f(.7, .7, .7);
		glVertex3f(cos(j), -1, sin(j));
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glRotatef(270, 0, 1, 0);
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.4);
	glTranslatef(-1, -1.55, 0);
	glScalef(2.5, .1, .75);
	glutSolidCube(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.55, 0);
	glScalef(0.05, .11, .05);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -5);
	glScalef(1, 1, 2.4);
	glBegin(GL_QUAD_STRIP);
	for (int j = 0; j <= 360; j += 5) {
		glColor3f(.3, .3, .3);
		glVertex3f(cos(j), +1, sin(j));
		glColor3f(.7, .7, .7);
		glVertex3f(cos(j), -1, sin(j));
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	glPopAttrib();
}

void RotateFan() {
	rotationAngle += 3.0f;
	glutPostRedisplay();
}

void DrawRefrigerator() {
	float room_size = 10.0f; // Kích thước căn phòng

	// Tính toán vị trí của các mặt phẳng
	float left = -room_size / 2.0f;
	float right = room_size / 2.0f;
	float bottom = -room_size / 2.0f;
	float top = room_size / 2.0f;
	float back = -room_size / 2.0f;
	float front = room_size / 2.0f;

	//GLfloat fridge_color[] = { 0.4f, 0.4f, 0.4f, 1.0f }; // Màu tủ lạnh

	// Màu cho mặt trên tủ lạnh
	GLfloat fridge_top_color[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	// Màu cho mặt trước tủ lạnh
	GLfloat fridge_front_color[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	// Màu cho các mặt khác của tủ lạnh
	GLfloat fridge_color[] = { 0.4f, 0.4f, 0.4f, 1.0f };

	// Sử dụng màu cho tủ lạnh
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fridge_color);

	// Kích thước của tủ lạnh
	float fridge_width = 2.0f;
	float fridge_height = 5.0f;
	float fridge_depth = 2.0f;

	// Vị trí của tủ lạnh
	float fridge_x = -5.0f;
	float fridge_y = -5.0f; // Nằm trên mặt phẳng y = 0
	float fridge_z = -1.0f;

	// Vẽ tủ lạnh
	glBegin(GL_QUADS);
	// Mặt trước
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fridge_color);
	glVertex3f(fridge_x, fridge_y, fridge_z);
	glVertex3f(fridge_x + fridge_width, fridge_y, fridge_z);
	glVertex3f(fridge_x + fridge_width, fridge_y + fridge_height, fridge_z);
	glVertex3f(fridge_x, fridge_y + fridge_height, fridge_z);
	glEnd();

	glBegin(GL_QUADS);
	// Mặt dưới
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fridge_color);
	glVertex3f(fridge_x, fridge_y, fridge_z);
	glVertex3f(fridge_x + fridge_width, fridge_y, fridge_z);
	glVertex3f(fridge_x + fridge_width, fridge_y, fridge_z + fridge_depth);
	glVertex3f(fridge_x, fridge_y, fridge_z + fridge_depth);
	glEnd();

	glBegin(GL_QUADS);
	// Mặt trên
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fridge_top_color);
	glVertex3f(fridge_x, fridge_y + fridge_height, fridge_z);
	glVertex3f(fridge_x + fridge_width, fridge_y + fridge_height, fridge_z);
	glVertex3f(fridge_x + fridge_width, fridge_y + fridge_height, fridge_z + fridge_depth);
	glVertex3f(fridge_x, fridge_y + fridge_height, fridge_z + fridge_depth);
	glEnd();

	glBegin(GL_QUADS);
	// Mặt sau
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fridge_color);
	glVertex3f(fridge_x, fridge_y, fridge_z + fridge_depth);
	glVertex3f(fridge_x + fridge_width, fridge_y, fridge_z + fridge_depth);
	glVertex3f(fridge_x + fridge_width, fridge_y + fridge_height, fridge_z + fridge_depth);
	glVertex3f(fridge_x, fridge_y + fridge_height, fridge_z + fridge_depth);
	glEnd();

	glBegin(GL_QUADS);
	// Các mặt bên
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fridge_front_color);
	glVertex3f(fridge_x, fridge_y, fridge_z);
	glVertex3f(fridge_x, fridge_y, fridge_z + fridge_depth);
	glVertex3f(fridge_x, fridge_y + fridge_height, fridge_z + fridge_depth);
	glVertex3f(fridge_x, fridge_y + fridge_height, fridge_z);

	// Vẽ đoạn thẳng chia đôi mặt phẳng
	glColor3f(0.0f, 0.0f, 0.0f); // Màu đen
	glVertex3f(fridge_x, fridge_y + fridge_height / 1.0f, fridge_z);
	glVertex3f(fridge_x, fridge_y + fridge_height / 1.0f, fridge_z + fridge_depth);

	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(fridge_x + fridge_width, fridge_y, fridge_z);
	glVertex3f(fridge_x + fridge_width, fridge_y, fridge_z + fridge_depth);
	glVertex3f(fridge_x + fridge_width, fridge_y + fridge_height, fridge_z + fridge_depth);
	glVertex3f(fridge_x + fridge_width, fridge_y + fridge_height, fridge_z);
	glEnd();

	//glBegin(GL_LINES);
	//// Đặt màu cho đường ngăn cách (ví dụ: màu đen)
	//glColor3f(0.0f, 0.0f, 0.0f);
	//// Vẽ đường ngăn cách
	//glVertex3f(fridge_x, fridge_y + fridge_height / 2.0f, fridge_z);
	//glVertex3f(fridge_x + fridge_width, fridge_y + fridge_height / 2.0f, fridge_z);

	//glVertex3f(fridge_x, fridge_y + fridge_height / 2.0f, fridge_z + fridge_depth);
	//glVertex3f(fridge_x + fridge_width, fridge_y + fridge_height / 2.0f, fridge_z + fridge_depth);

	//glEnd();
}




void DrawRoom() {

	// Vật liệu cho các mặt phẳng
	GLfloat left_right_wall_diffuse[] = { 46, 138, 138, 1 }; // Màu sắc khối lượng tán phản xạ cho tường bên trái và bên phải
	GLfloat back_wall_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // Màu sắc khối lượng tán phản xạ cho tường sau
	GLfloat floor_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // Màu sắc khối lượng tán phản xạ cho sàn 
	GLfloat mau_kem[] = { 0.94, 0.81, 0.71, 1.0 }; // Màu kem
	GLfloat ceiling_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // Màu sắc khối lượng tán phản xạ cho trần
	GLfloat red_color[] = { 0.8, 0.0, 0.0, 1.0 }; // Màu đỏ cho trần


	// Kích thước mới cho các mặt phẳng
	float room_size = 10.0f; // Kích thước căn phòng
	float wall_thickness = 0.2f; // Độ dày của tường

	// Tính toán vị trí của các mặt phẳng
	float left = -room_size / 2.0f;
	float right = room_size / 2.0f;
	float bottom = -room_size / 2.0f;
	float top = room_size / 2.0f;
	float back = -room_size / 2.0f;
	float front = room_size / 2.0f;

	// Vẽ các mặt phẳng để tạo thành tường, sàn và trần
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, left_right_wall_diffuse); // Sử dụng vật liệu cho các tường bên trái và bên phải
	glBegin(GL_QUADS);
	// Tường bên trái
	glVertex3f(left, bottom, back);
	glVertex3f(left, bottom, front);
	glVertex3f(left, top, front);
	glVertex3f(left, top, back);
	// Tường bên phải
	glVertex3f(right, bottom, back);
	glVertex3f(right, bottom, front);
	glVertex3f(right, top, front);
	glVertex3f(right, top, back);
	glEnd();


	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mau_kem); // Sử dụng vật liệu cho tường sau
	glBegin(GL_QUADS);
	// Tường sau
	glVertex3f(left, bottom, back);
	glVertex3f(right, bottom, back);
	glVertex3f(right, top, back);
	glVertex3f(left, top, back);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, floor_diffuse);
	glBegin(GL_QUADS);
	// Sàn
	glVertex3f(left, bottom, back);
	glVertex3f(right, bottom, back);
	glVertex3f(right, bottom, front);
	glVertex3f(left, bottom, front);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ceiling_diffuse);
	glBegin(GL_QUADS);
	// Trần
	glVertex3f(left, top, back);
	glVertex3f(right, top, back);
	glVertex3f(right, top, front);
	glVertex3f(left, top, front);
	glEnd();

	// Vẽ tủ bếp (hình hộp)
	DrawCabinet();
	DrawCabinetPerpendicular();
	DrawRefrigerator();
	DrawFan();
	DrawTable();
	DrawChair();
	DrawKitchenCounter();
}






void DrawLamp() {
	//GLfloat light_position[] = { 0.0, -10.0, 0.0, 1.0 }; // Vị trí nguồn sáng
	//GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // Màu sắc ánh sáng

	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

	// Set material properties for the lamp stand
	//GLfloat lamp_stand_color[] = { 0.5f, 0.5f, 0.5f, 1.0f }; // Gray color
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lamp_stand_color);

	// Set material properties for the lamp shade
	GLfloat lamp_shade_color[] = { 0.8f, 0.8f, 0.8f, 1.0f }; // Light gray color
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lamp_shade_color);

	// Draw the lamp shade
	glPushMatrix();
	glTranslatef(0.0f, 3.8f, 0.0f); ;
	glScalef(0.2f, 0.1f, 0.2f);
	glutSolidSphere(1.0f, 20, 20);
	glPopMatrix();
}

void Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		//glTranslatef(0, -1, 0);
		gluLookAt(0.0f, 0.0f, 8.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glutPostRedisplay();
		break;
	case 's':
		//glTranslatef(0, 1, 0);
		gluLookAt(0.0f, 0.0f, -8.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glutPostRedisplay();
		break;
	case 'd':
		//glTranslatef(-1, 0, 0);
		//gluLookAt(0.0f, 0.0f, 8.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glutPostRedisplay();
		break;
	case 'a':
		//glTranslatef(1, 0, 0);
		//gluLookAt(0.0f, 0.0f, 8.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glutPostRedisplay();
		break;
	case '1':
		// Bật hoặc tắt đèn
		light_1_On = !light_1_On;
		if (light_1_On) {
			glEnable(GL_LIGHT0); // Bật đèn
		}
		else {
			glDisable(GL_LIGHT0); // Tắt đèn
		}
		glutPostRedisplay(); // Yêu cầu vẽ lại cảnh
		break;
	}
}


void Display()
{
	// Vẽ phòng

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glPushMatrix();
	//glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	DrawRoom(); // Vẽ căn phòng
	glPopMatrix();
	glFlush();

	//glPushMatrix();
	//DrawLamp(); // Vẽ đèn
	//glPopMatrix();
	//glFlush();

	// Sau mỗi lần vẽ, cập nhật lại vật liệu để đảm bảo các đối tượng không mất màu
	// Bạn cần cập nhật vật liệu của các đối tượng ở đây

	glutSwapBuffers();
	
}

void Init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);
	// Sử dụng 1 trong 2 góc nhìn dưới đây để thấy ánh sáng của spot chiếu như thế nào
	//gluLookAt(-1, 2, 1, 0, 0, 0, 0, 1, 0);  // Góc nhìn chéo từ trên xuống
	gluLookAt(5, 1, 8, -2, 0, 0, 0, 1, 0);  // Góc nhìn thẳng
	//gluLookAt(0, 10, 0, 0, 0, 0, 0, 0, -1); // Góc nhìn từ trên xuống dưới
	//gluLookAt(0.0f, 0.0f, 8.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Working room");
	Init();
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutIdleFunc(RotateFan);
	glutMainLoop();
	return 0;
}