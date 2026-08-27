/**
 * @file numerical integrators 
 * @author jillian spears
 */
#include "numerical_integrators.h"
#include <functional>
#include <array>

std::array<double, 2> rk4Step(std::function<double(double, double)> f, double yn, double tn, double h)
{    

    double k1 =  f(tn, yn);
    double k2 = f(tn + h/2, yn + k1 * (h/2));
    double k3 = f(tn + h/2, yn + k2 * h/2);
    double k4 = f(tn + h, yn + h * k3);

    double yn_step = yn + h/6 * (k1 + 2 * k2 + 2 * k3 + k4);
    double tn_step = tn + h;

    return {tn_step, yn_step};
}

