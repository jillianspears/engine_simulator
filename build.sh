#!/usr/bin/env bash
set -e

g++ -std=c++17 \
  -I truth_model/numerical_integrators/include \
  truth_model/numerical_integrators/src/numerical_integrators.cpp \
  truth_model/numerical_integrators/test/test_numerical_integrators.cpp \
  -lgtest -lgtest_main -lpthread \
  -o test_numerical_integrators.exe

./test_numerical_integrators.exe
