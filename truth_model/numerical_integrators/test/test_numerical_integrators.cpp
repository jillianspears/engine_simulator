#include "numerical_integrators.h"
#include <gtest/gtest.h>

std::function<double(double, double)> f = [](double t, double y)
{
    return y;
};

TEST(NumericalIntegratorsTest, SetUp)
{

    double yn = 1;
    double tn = 1; 
    double h = 0.1;
    auto [t_result, y_result] = rk4Step(f, yn, tn, h);

    SUCCEED();
}