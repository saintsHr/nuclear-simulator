#include "particles.hpp"
#include "settings.hpp"

#include <GL/gl.h>
#include <cmath>

void Electron::draw() {
    glColor3f(
        50.0f  / 255.0f,
        220.0f / 255.0f,
        255.0f / 255.0f
    );
    
    double cx = x * SCALE;
    double cy = y * SCALE;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);

        for (int i = 0; i <= ELECTRON_SEGMENTS; i++) {
            double angle = 2.0 * M_PI * i / ELECTRON_SEGMENTS;

            double sx = ELECTRON_RADIUS * cos(angle);
            double sy = ELECTRON_RADIUS * sin(angle);

            glVertex2f(cx + sx, cy + sy);
        }
    glEnd();
}

void Neutron::draw() {
    glColor3f(
        255.0f  / 255.0f,
        255.0f / 255.0f,
        215.0f / 255.0f
    );
    
    double cx = x * SCALE;
    double cy = y * SCALE;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);

        for (int i = 0; i <= NEUTRON_SEGMENTS; i++) {
            double angle = 2.0 * M_PI * i / NEUTRON_SEGMENTS;

            double sx = NEUTRON_RADIUS * cos(angle);
            double sy = NEUTRON_RADIUS * sin(angle);

            glVertex2f(cx + sx, cy + sy);
        }
    glEnd();
}

void Proton::draw() {
    glColor3f(
        200.0f  / 255.0f,
        15.0f / 255.0f,
        15.0f / 255.0f
    );
    
    double cx = x * SCALE;
    double cy = y * SCALE;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);

        for (int i = 0; i <= PROTON_SEGMENTS; i++) {
            double angle = 2.0 * M_PI * i / PROTON_SEGMENTS;

            double sx = PROTON_RADIUS * cos(angle);
            double sy = PROTON_RADIUS * sin(angle);

            glVertex2f(cx + sx, cy + sy);
        }
    glEnd();
}