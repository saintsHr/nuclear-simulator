#pragma once

constexpr int WIDTH  = 800; 
constexpr int HEIGHT = 600;

constexpr double DT        = 0.001;
constexpr double SCALE     = 50.0;
constexpr double MAX_SPEED = 4.0;

constexpr int ELECTRON_SEGMENTS = 8;
constexpr int ELECTRON_RADIUS   = 4;

constexpr int NEUTRON_SEGMENTS = 16;
constexpr int NEUTRON_RADIUS   = 8;

constexpr int PROTON_SEGMENTS = 16;
constexpr int PROTON_RADIUS   = 8;

constexpr double CF_K    = 50.0;
constexpr double CF_SOFT = 0.5;

constexpr double LJ_EPSILON = 0.05;
constexpr double LJ_SIGMA   = 0.8;
constexpr double LJ_SIGMA6  = LJ_SIGMA*LJ_SIGMA*LJ_SIGMA*LJ_SIGMA*LJ_SIGMA*LJ_SIGMA;
constexpr double LJ_SIGMA12 = LJ_SIGMA6 * LJ_SIGMA6;

constexpr double NF_STRENGTH  = 800;
constexpr double NF_RANGE     = 0.5;
constexpr double NF_MAX_FORCE = 400;