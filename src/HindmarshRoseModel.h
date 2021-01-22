#include <iostream>
#include <vector>
#include "HindmarshRoseStep.h"
using namespace std;

vector<float> HindmarshRoseModel(float xO, float yO, float zO, float dT, HindmarshRoseParams &params,
                                 int start = 0, int stop = 2000, float I = 0);