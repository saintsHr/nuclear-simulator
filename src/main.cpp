#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <vector>
#include <memory>
#include <cmath>

#include "settings.hpp"
#include "particles.hpp"

std::vector<std::unique_ptr<Particle>> particles;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    static_cast<void>(scancode);
    static_cast<void>(mods);

    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
        auto e = std::make_unique<Electron>();
        e->x = mouseX / SCALE;
        e->y = mouseY / SCALE;
        particles.push_back(std::move(e));
    }

    if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
        auto n = std::make_unique<Neutron>();
        n->x = mouseX / SCALE;
        n->y = mouseY / SCALE;
        particles.push_back(std::move(n));
    }

    if (key == GLFW_KEY_3 && action == GLFW_PRESS) {
        auto p = std::make_unique<Proton>();
        p->x = mouseX / SCALE;
        p->y = mouseY / SCALE;
        particles.push_back(std::move(p));
    }
}

int main(void) {
    if (!glfwInit()) return -1;

    // creates window
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Nuclear", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // configs GLFW
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_FALSE);
    glfwSetKeyCallback(window, key_callback);

    // configs OpenGL
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // --- Resets Acceleration ---
        for (auto& p : particles) {
            p->ax = 0.0;
            p->ay = 0.0;
        }

        // --- Calc Forces ---
        for (size_t i = 0; i < particles.size(); i++) {
            for (size_t j = i + 1; j < particles.size(); j++) {
                auto& a = *particles[i];
                auto& b = *particles[j];

                double fx = 0;
                double fy = 0;

                // --- Coulomb ---
                double dx = a.x - b.x;
                double dy = a.y - b.y;

                double r2 = dx*dx + dy*dy;
                if (r2 < CF_SOFT) r2 = CF_SOFT;
                double r  = std::sqrt(r2);

                double cf_f = CF_K * (a.charge * b.charge) / r2;

                fx += cf_f * dx / r;
                fy += cf_f * dy / r;

                // --- Lennard-Jones ---
                double inv_r2 = 1.0 / r2;
                double inv_r6 = inv_r2 * inv_r2 * inv_r2;

                double lj_scalar = (
                    24 * LJ_EPSILON * inv_r2 *
                    (2 * LJ_SIGMA12 *
                    inv_r6 * inv_r6 - LJ_SIGMA6 * inv_r6)
                );

                fx += lj_scalar * dx;
                fy += lj_scalar * dy;

                // -- Apply Forces ---
                a.ax += fx / a.mass;
                a.ay += fy / a.mass;

                b.ax -= fx / b.mass;
                b.ay -= fy / b.mass;
            }
        }

        // --- Integration ---
        for (auto& p : particles) {
            // --- Damping ---
            double speed2 = p->vx*p->vx + p->vy*p->vy;

            if (speed2 > MAX_SPEED*MAX_SPEED) {
                p->vx *= 0.95;
                p->vy *= 0.95;
            }

            // --- Integrates ---
            p->vx += p->ax * DT;
            p->vy += p->ay * DT;

            p->x += p->vx * DT;
            p->y += p->vy * DT;
        }

        // --- Draws Particles ---
        for (auto& p : particles) {
            p->draw();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}