#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

// Circle center coordinates (scaled for window size)
int xc = 100, yc = 100;
// Circle radius (scaled for window size, assuming 10 pixels = 1cm)
int r = 40;
// Rotation angle in degrees (60 degrees clockwise)
double angle = -60 * M_PI / 180.0; // Convert degrees to radians

// Function to rotate a point around the center
void rotatePoint(int &x, int &y) {
    int xNew = xc + (x - xc) * cos(angle) - (y - yc) * sin(angle);
    int yNew = yc + (x - xc) * sin(angle) + (y - yc) * cos(angle);
    x = xNew;
    y = yNew;
}

// Function to plot filled circle using symmetric points
void plotPoints(int x, int y) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0); // Red color (RGB #FF0000)
    glVertex2i(xc, yc); // Center of the circle
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
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

// Function to draw a rotated circle using Bresenham’s Algorithm
void bresenhamCircle() {
    int x = 0, y = r;
    int d = 3 - 2 * r; // Decision parameter
    while (x <= y) {
        int rotatedX = x, rotatedY = y;
        rotatePoint(rotatedX, rotatedY); // Apply rotation to each point
        plotPoints(rotatedX, rotatedY);
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
    glColor3f(1.0, 0.0, 0.0); // Set color to red for the filled circle
    bresenhamCircle(); // Draw and rotate the filled circle
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
    glutCreateWindow("Rotated Filled Bresenham Circle"); // Create window with title
    init();
    glutDisplayFunc(display); // Register display function
    glutMainLoop(); // Start event loop
    return 0;
}
