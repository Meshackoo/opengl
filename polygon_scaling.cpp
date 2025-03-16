#include <GL/glut.h>

// Function to render text labels
void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    for (const char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

// Original polygon vertices
float polygonVertices[6][2] = {
    {8, 4},
    {2, 4},
    {0, 8},
    {3, 12},
    {7, 12},
    {10, 8}
};

// Scaling factor
float scaleFactor = 2.0;

// Function to draw scaled polygon
void drawScaledPolygon() {
    glColor3f(1.0, 0.0, 0.0); // Red color (#FF0000)
    glBegin(GL_POLYGON);
        for (int i = 0; i < 6; i++) {
            glVertex2f(polygonVertices[i][0] * scaleFactor, polygonVertices[i][1] * scaleFactor);
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw scaled polygon
    drawScaledPolygon();
    
    // Label scaled polygon vertices
    glColor3f(1.0, 1.0, 1.0); // White text
    for (int i = 0; i < 6; i++) {
        renderBitmapString(polygonVertices[i][0] * scaleFactor, polygonVertices[i][1] * scaleFactor, GLUT_BITMAP_HELVETICA_12, "*");
    }
    
    // Draw coordinate axes
    glColor3f(1.0, 0.0, 0.0); // Red color for axes
    glBegin(GL_LINES);
        glVertex2i(-20, 0);
        glVertex2i(30, 0);
        glVertex2i(0, -20);
        glVertex2i(0, 30);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Background color black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 30, -20, 30); // Set coordinate system range
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Scaled Polygon");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
