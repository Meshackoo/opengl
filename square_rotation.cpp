#include <GL/glut.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846

// Function to render text on the OpenGL window
void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    for (const char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

// Original square vertices
float squareVertices[4][2] = {
    {0, 4},  // A (0,4)
    {3, 4},  // B (3,4)
    {4, 0},  // C (4,0)
    {0, 0}   // D (0,0)
};

// Translated square vertices (Shifted by +2 along X and Y axis)
float translatedVertices[4][2];
// Rotated square vertices
float rotatedVertices[4][2];

// Function to compute translation
void translateSquare() {
    for (int i = 0; i < 4; i++) {
        translatedVertices[i][0] = squareVertices[i][0] + 2;
        translatedVertices[i][1] = squareVertices[i][1] + 2;
    }
}

// Function to compute rotation
void rotateSquare(float angle) {
    float rad = angle * PI / 180.0; // Convert to radians
    for (int i = 0; i < 4; i++) {
        float x = translatedVertices[i][0];
        float y = translatedVertices[i][1];
        rotatedVertices[i][0] = x * cos(rad) - y * sin(rad);
        rotatedVertices[i][1] = x * sin(rad) + y * cos(rad);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw original square
    glColor3f(0.0, 1.0, 0.0); // Green color
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 4; i++) {
            glVertex2f(squareVertices[i][0], squareVertices[i][1]);
        }
    glEnd();
    // Label original square vertices
    glColor3f(1.0, 1.0, 1.0); // White color
    renderBitmapString(0, 4, GLUT_BITMAP_HELVETICA_12, "A(0,4)");
    renderBitmapString(3, 4, GLUT_BITMAP_HELVETICA_12, "B(3,4)");
    renderBitmapString(4, 0, GLUT_BITMAP_HELVETICA_12, "C(4,0)");
    renderBitmapString(0, 0, GLUT_BITMAP_HELVETICA_12, "D(0,0)");

    // Draw translated square
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 4; i++) {
            glVertex2f(translatedVertices[i][0], translatedVertices[i][1]);
        }
    glEnd();
    // Label translated square vertices
    glColor3f(1.0, 1.0, 0.0); // Yellow color
    renderBitmapString(2, 6, GLUT_BITMAP_HELVETICA_12, "A'(2,6)");
    renderBitmapString(5, 6, GLUT_BITMAP_HELVETICA_12, "B'(5,6)");
    renderBitmapString(6, 2, GLUT_BITMAP_HELVETICA_12, "C'(6,2)");
    renderBitmapString(2, 2, GLUT_BITMAP_HELVETICA_12, "D'(2,2)");
    
    // Draw rotated square
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 4; i++) {
            glVertex2f(rotatedVertices[i][0], rotatedVertices[i][1]);
        }
    glEnd();
    // Label rotated square vertices
    glColor3f(0.0, 1.0, 1.0); // Cyan color
    renderBitmapString(rotatedVertices[0][0], rotatedVertices[0][1], GLUT_BITMAP_HELVETICA_12, "A''");
    renderBitmapString(rotatedVertices[1][0], rotatedVertices[1][1], GLUT_BITMAP_HELVETICA_12, "B''");
    renderBitmapString(rotatedVertices[2][0], rotatedVertices[2][1], GLUT_BITMAP_HELVETICA_12, "C''");
    renderBitmapString(rotatedVertices[3][0], rotatedVertices[3][1], GLUT_BITMAP_HELVETICA_12, "D''");
    
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
    glutCreateWindow("OpenGL Square Transformations"); // Set window title
    init();
    translateSquare(); // Compute translation
    rotateSquare(55.0); // Compute rotation by 55 degrees
    glutDisplayFunc(display); // Register display callback function
    glutMainLoop(); // Enter the OpenGL main loop
    return 0;
}
