#include <GL/glut.h>
#include <iostream>

using namespace std;

// Circle center coordinates (scaled for window size)
int xc = 100, yc = 100;
// Circle radius (scaled for window size, assuming 10 pixels = 1cm)
int r = 40;

// Function to plot symmetric points for the circle
void plotPoints(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y); // Octant 1
    glVertex2i(xc - x, yc + y); // Octant 2
    glVertex2i(xc + x, yc - y); // Octant 8
    glVertex2i(xc - x, yc - y); // Octant 7
    glVertex2i(xc + y, yc + x); // Octant 4
    glVertex2i(xc - y, yc + x); // Octant 3
    glVertex2i(xc + y, yc - x); // Octant 5
    glVertex2i(xc - y, yc - x); // Octant 6
    glEnd();
}

// Function to draw X and Y axes
void drawAxes() {
    glColor3f(1.0, 0.0, 0.0); // Red color for axes
    glBegin(GL_LINES);
    glVertex2i(0, yc); // X-axis line
    glVertex2i(200, yc);
    glVertex2i(xc, 0); // Y-axis line
    glVertex2i(xc, 200);
    glEnd();
}

// Function to label axes
void drawLabels() {
    glColor3f(1.0, 1.0, 1.0); // White color for text
    glRasterPos2i(190, yc + 5); // X-axis label position
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');
    glRasterPos2i(xc + 5, 190); // Y-axis label position
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');
}

// Function to draw a circle using Bresenham’s Algorithm
void bresenhamCircle() {
    int x = 0, y = r;
    int d = 3 - 2 * r; // Decision parameter
    while (x <= y) {
        plotPoints(x, y);
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    glFlush();
}

// Display function to draw the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear screen
    drawAxes(); // Draw X and Y axes
    drawLabels(); // Label axes
    glColor3f(1.0, 1.0, 1.0); // Set color to white for the circle
    bresenhamCircle(); // Draw the circle
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, 0, 200); // Set coordinate system range
}

// Main function to set up OpenGL and start the program
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("Bresenham Circle Drawing"); // Create window with title
    init();
    glutDisplayFunc(display); // Register display function
    glutMainLoop(); // Start event loop
    return 0;
}
