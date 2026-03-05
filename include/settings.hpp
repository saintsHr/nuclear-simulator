#pragma once

constexpr int WIDTH  = 800; 
constexpr int HEIGHT = 600;

constexpr double DT        = 0.002;
constexpr double SCALE     = 50.0;
constexpr double MAX_SPEED = 8.0;

constexpr int ELECTRON_SEGMENTS = 8;
constexpr int ELECTRON_RADIUS   = 4;

constexpr int NEUTRON_SEGMENTS = 16;
constexpr int NEUTRON_RADIUS   = 8;

constexpr int PROTON_SEGMENTS = 16;
constexpr int PROTON_RADIUS   = 8;

constexpr double CF_K    = 100.0;
constexpr double CF_SOFT = 0.1;

constexpr double LJ_EPSILON = 0.2;
constexpr double LJ_SIGMA   = 1.0;
constexpr double LJ_SIGMA6  = LJ_SIGMA*LJ_SIGMA*LJ_SIGMA*LJ_SIGMA*LJ_SIGMA*LJ_SIGMA;
constexpr double LJ_SIGMA12 = LJ_SIGMA6 * LJ_SIGMA6;