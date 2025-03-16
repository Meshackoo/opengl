#include <GL/glut.h>
#include <cmath>
#include <string>

// Ellipse Parameters
float centerX = 1, centerY = 2; // Center coordinates
float a = 6, b = 5;             // Semi-major and semi-minor axes

// Function to draw a single pixel
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Function to render text (coordinate labels)
void drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
}

// Midpoint Ellipse Algorithm to draw the ellipse
void drawEllipse() {
    int x = 0, y = b;
    float d1 = (b * b) - (a * a * b) + (0.25 * a * a);
    int dx = 2 * b * b * x;
    int dy = 2 * a * a * y;

    glColor3f(1.0, 1.0, 1.0); // White color for the ellipse
    glPointSize(2);

    // Region 1 of ellipse drawing
    while (dx < dy) {
        drawPixel(centerX + x, centerY + y);
        drawPixel(centerX - x, centerY + y);
        drawPixel(centerX + x, centerY - y);
        drawPixel(centerX - x, centerY - y);

        if (d1 < 0) {
            x++;
            dx += 2 * b * b;
            d1 += dx + (b * b);
        } else {
            x++;
            y--;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d1 += dx - dy + (b * b);
        }
    }

    // Region 2 of ellipse drawing
    float d2 = ((b * b) * (x + 0.5) * (x + 0.5)) + ((a * a) * (y - 1) * (y - 1)) - (a * a * b * b);
    while (y >= 0) {
        drawPixel(centerX + x, centerY + y);
        drawPixel(centerX - x, centerY + y);
        drawPixel(centerX + x, centerY - y);
        drawPixel(centerX - x, centerY - y);

        if (d2 > 0) {
            y--;
            dy -= 2 * a * a;
            d2 += (a * a) - dy;
        } else {
            y--;
            x++;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d2 += dx - dy + (a * a);
        }
    }

    glFlush();
}

// Function to fill the ellipse with orange color
void fillEllipse() {
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color (#FFA500)
    glBegin(GL_POLYGON);
    for (float angle = 0; angle < 360; angle += 1) {
        float rad = angle * (3.14159 / 180);
        glVertex2f(centerX + a * cos(rad), centerY + b * sin(rad));
    }
    glEnd();
    glFlush();
}

// Function to draw coordinate axes and labels
void drawAxes() {
    glColor3f(0.5, 0.5, 0.5); // Gray color for axes
    glBegin(GL_LINES);
    glVertex2f(-20, 0);
    glVertex2f(20, 0); // X-axis
    glVertex2f(0, -20);
    glVertex2f(0, 20); // Y-axis
    glEnd();

    // Label axes
    drawText(19, -1, "X");
    drawText(-1, 19, "Y");

    // Label center of ellipse
    drawText(centerX, centerY, "(" + std::to_string((int)centerX) + "," + std::to_string((int)centerY) + ")");
}

// Display function for rendering
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawAxes();      // Draw coordinate axes
    fillEllipse();   // Fill ellipse with orange
    drawEllipse();   // Draw the ellipse outline

    glFlush();
}

// Initialization function for OpenGL
void init() {
    glClearColor(0, 0, 0, 1); // Black background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20, 20, -20, 20); // Set coordinate system range
}

// Main function to run OpenGL program
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint Ellipse with Flood Fill and Labels");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
