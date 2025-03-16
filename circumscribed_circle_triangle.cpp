#include <GL/glut.h>
#include <cmath>

// Function to draw a circle using the midpoint algorithm
void drawCircle(float cx, float cy, float r) {
    glColor3f(1.0, 0.0, 0.0); // Red color for the circle
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        float x = r * cos(theta) + cx;
        float y = r * sin(theta) + cy;
        glVertex2f(x, y);
    }
    glEnd();
}

// Function to display the triangle with labeled vertices and a circumscribed circle
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 1.0, 1.0); // Set triangle color to white
    glBegin(GL_TRIANGLES);
        // Define the triangle vertices
        glVertex2i(-1, 6); // First vertex (-1,6)
        glVertex2i(2, 0);  // Second vertex (2,0)
        glVertex2i(-4, 9); // Third vertex (-4,9)
    glEnd();
    
    // Draw coordinate axes
    glColor3f(1.0, 0.0, 0.0); // Red color for axes
    glBegin(GL_LINES);
        glVertex2i(-10, 0);
        glVertex2i(10, 0);
        glVertex2i(0, -10);
        glVertex2i(0, 10);
    glEnd();
    
    // Label the axes
    glColor3f(1.0, 1.0, 1.0); // White color for labels
    glRasterPos2i(9, 1);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');
    glRasterPos2i(1, 9);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');
    
    // Compute the circumcenter and radius of the circumcircle
    float ax = -1, ay = 6;
    float bx = 2, by = 0;
    float cx = -4, cy = 9;
    float d = 2 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
    float ux = ((ax * ax + ay * ay) * (by - cy) + (bx * bx + by * by) * (cy - ay) + (cx * cx + cy * cy) * (ay - by)) / d;
    float uy = ((ax * ax + ay * ay) * (cx - bx) + (bx * bx + by * by) * (ax - cx) + (cx * cx + cy * cy) * (bx - ax)) / d;
    float radius = sqrt((ux - ax) * (ux - ax) + (uy - ay) * (uy - ay));
    
    // Draw the circumscribed circle
    drawCircle(ux, uy, radius);
    
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
    glutCreateWindow("OpenGL Triangle with Circumscribed Circle"); // Set window title
    init();
    glutDisplayFunc(display); // Register display callback function
    glutMainLoop(); // Enter the OpenGL main loop
    return 0;
}
