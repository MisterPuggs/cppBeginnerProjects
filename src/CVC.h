#pragma once
// Header for the Circle Volume Calculator file

#include <iostream>
#include <string>
#include <cmath>

int CVCmenu();
int CVCmain(int iter = 0);
int CVCEnsureFloatInput(std::string const& prompt, float defReturn = 0.0);