#include <GL/glut.h>

// Function to render text labels
void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    for (const char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

// Polygon vertices
float polygonVertices[6][2] = {
    {8, 4},
    {2, 4},
    {0, 8},
    {3, 12},
    {7, 12},
    {10, 8}
};

// Function to fill polygon with red color
void fillPolygon() {
    glColor3f(1.0, 0.0, 0.0); // Red color (#FF0000)
    glBegin(GL_POLYGON);
        for (int i = 0; i < 6; i++) {
            glVertex2f(polygonVertices[i][0], polygonVertices[i][1]);
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Fill polygon with red color
    fillPolygon();
    
    // Label polygon vertices
    glColor3f(1.0, 1.0, 1.0); // White text
    renderBitmapString(8, 4, GLUT_BITMAP_HELVETICA_12, "(8,4)");
    renderBitmapString(2, 4, GLUT_BITMAP_HELVETICA_12, "(2,4)");
    renderBitmapString(0, 8, GLUT_BITMAP_HELVETICA_12, "(0,8)");
    renderBitmapString(3, 12, GLUT_BITMAP_HELVETICA_12, "(3,12)");
    renderBitmapString(7, 12, GLUT_BITMAP_HELVETICA_12, "(7,12)");
    renderBitmapString(10, 8, GLUT_BITMAP_HELVETICA_12, "(10,8)");
    
    // Draw coordinate axes
    glColor3f(1.0, 0.0, 0.0); // Red color for axes
    glBegin(GL_LINES);
        glVertex2i(-10, 0);
        glVertex2i(15, 0);
        glVertex2i(0, -10);
        glVertex2i(0, 15);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Background color black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 15, -10, 15); // Set coordinate system range
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Filled Polygon");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
