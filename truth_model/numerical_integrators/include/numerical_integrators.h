#pragma once
#include <array>
#include <functional>

/**
 * Runge-Kutta Method
 * @param yn current y
 * @param tn current time
 * author: Jillian Spears
 * https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods#:~:text=Now%20we%20pick%20a%20step%2Dsize%20h%20%3E%200%20and%20define%3A
 */
std::array<double, 2> rk4Step(std::function<double(double, double)> f, double yn, double tn, double h);
