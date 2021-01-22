#include "HindmarshRoseModel.h"

vector<float> HindmarshRoseModel(float xO, float yO, float zO, float dT, HindmarshRoseParams &params,
                                 int start /*= 0*/, int stop /*= 2000*/, float I /*= 0*/)
{
    int t = stop - start;
    int steps = t / dT;
    vector<float> xMatrix;
    xMatrix.push_back(xO);
    for (int i = 1; i < steps; i++)
    {
        pair<float, pair<float, float>> p = HindmarshRoseStep(xMatrix.at(i - 1), yO, zO, i, dT, params, I);
        xMatrix.push_back(p.first);
        yO = p.second.first;
        zO = p.second.second;
    }
    return xMatrix;
}