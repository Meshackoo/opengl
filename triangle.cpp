#include <GL/glut.h>

// Function to display the triangle with labeled vertices
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
    glutCreateWindow("OpenGL Triangle with Labeled Axes"); // Set window title
    init();
    glutDisplayFunc(display); // Register display callback function
    glutMainLoop(); // Enter the OpenGL main loop
    return 0;
}
