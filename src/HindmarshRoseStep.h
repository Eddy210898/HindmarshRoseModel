#include <iostream>
#include "HindmarshRoseParams.h"
#include "./../getNextRungeKuta/getNextRungeKuta.h"

using namespace std;
pair<float, pair<float, float>> HindmarshRoseStep(float xO, float yO, float zO, float t, float dT, HindmarshRoseParams &params, float I = 0);