#pragma once

class Particle {
public:
    double x, y;
    double vx, vy;
    double ax, ay;

    double mass;
    double charge;

    virtual void draw() = 0;
    virtual ~Particle() = default;
};

class Electron : public Particle {
public:
    Electron() {
        mass = 1.0;
        charge = -1.0;
    }

    void draw() override;
};

class Neutron : public Particle {
public:
    Neutron() {
        mass = 1839.0;
        charge = 0.0;
    }

    void draw() override;
};

class Proton : public Particle {
public:
    Proton() {
        mass = 1836.0;
        charge = 1.0;
    }

    void draw() override;
};