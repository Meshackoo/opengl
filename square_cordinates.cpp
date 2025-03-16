#include <GL/glut.h>
#include <string.h>

// Function to render text on the OpenGL window
void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    for (const char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

// Original Square vertices
float originalSquare[4][2] = {
    {0, 4},  // A (0,4)
    {3, 4},  // B (3,4)
    {4, 0},  // C (4,0)
    {0, 0}   // D (0,0)
};

// Translated Square vertices (Shifted by 2 along X and Y)
float translatedSquare[4][2] = {
    {2, 6},  // A' (2,6)
    {5, 6},  // B' (5,6)
    {6, 2},  // C' (6,2)
    {2, 2}   // D' (2,2)
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw Original Square
    glColor3f(0.0, 1.0, 0.0); // Green color for original square
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 4; i++) {
            glVertex2f(originalSquare[i][0], originalSquare[i][1]);
        }
    glEnd();
    
    // Label Original Square vertices
    glColor3f(1.0, 1.0, 1.0); // White color for text
    renderBitmapString(0, 4, GLUT_BITMAP_HELVETICA_12, "A(0,4)");
    renderBitmapString(3, 4, GLUT_BITMAP_HELVETICA_12, "B(3,4)");
    renderBitmapString(4, 0, GLUT_BITMAP_HELVETICA_12, "C(4,0)");
    renderBitmapString(0, 0, GLUT_BITMAP_HELVETICA_12, "D(0,0)");
    
    // Draw Translated Square
    glColor3f(0.0, 0.0, 1.0); // Blue color for translated square
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 4; i++) {
            glVertex2f(translatedSquare[i][0], translatedSquare[i][1]);
        }
    glEnd();
    
    // Label Translated Square vertices
    glColor3f(1.0, 1.0, 0.0); // Yellow color for text
    renderBitmapString(2, 6, GLUT_BITMAP_HELVETICA_12, "A'(2,6)");
    renderBitmapString(5, 6, GLUT_BITMAP_HELVETICA_12, "B'(5,6)");
    renderBitmapString(6, 2, GLUT_BITMAP_HELVETICA_12, "C'(6,2)");
    renderBitmapString(2, 2, GLUT_BITMAP_HELVETICA_12, "D'(2,2)");
    
    // Draw coordinate axes
    glColor3f(1.0, 0.0, 0.0); // Red color for axes
    glBegin(GL_LINES);
        glVertex2i(-10, 0);
        glVertex2i(10, 0);
        glVertex2i(0, -10);
        glVertex2i(0, 10);
    glEnd();
    
    glFlush();
}

// Function to initialize the OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10); // Set coordinate system range
}

// Main function to initialize and run the OpenGL program
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("OpenGL Square Translation"); // Set window title
    init();
    glutDisplayFunc(display); // Register display callback function
    glutMainLoop(); // Enter the OpenGL main loop
    return 0;
}
