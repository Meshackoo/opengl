#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Function to draw a pixel
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Function to draw a parabola using the midpoint method
void drawParabola() {
    int y = 0;
    int x = 0;
    int p = 1 - 2 * y; // Initial decision parameter
    
    // Loop for y from -10 to 10
    for (y = -10; y <= 10; y++) {
        x = y * y; // Parabola equation: x = y^2
        drawPixel(x, y);
        drawPixel(-x, y); // Symmetric point
    }
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // White color for the parabola
    glPointSize(2.0);
    
    drawParabola();
    
    glFlush();
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50, 50, -15, 15); // Define the coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Parabola Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
