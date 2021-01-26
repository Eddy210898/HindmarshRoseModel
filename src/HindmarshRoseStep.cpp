#include "HindmarshRoseStep.h"

pair<float, pair<float, float>> HindmarshRoseStep(float xO, float yO, float zO, float t, float dT, HindmarshRoseParams &params, float I /*= 0*/)
{
    float arg[] = {
        params.getA(),  //0
        params.getB(),  //1
        params.getC(),  //2
        params.getD(),  //3
        xO,             //4
        params.getXo(), //5
        yO,             //6
        zO,             //7
        I,              //8
        params.getR(),  //9
        params.getS()   //10
    };
    float x = getNextRungeKuta(
        t, xO, dT, [](float t, float x, float args[]) {
            float sE = args[0] * x * x * x;
            float tE = args[1] * x * x;
            return args[6] - sE + tE + args[8] - args[7];
        },
        arg);

    float y = getNextRungeKuta(
        t, yO, dT, [](float t, float y, float args[]) {
            float sE = args[3] * args[4] * args[4];
            return args[2] - sE - y;
        },
        arg);
    float z = getNextRungeKuta(
        t, zO, dT, [](float t, float z, float args[]) {
            float sE = args[4] - args[5];
            float tE = args[10] * sE;
            float fE = tE - args[7];
            return args[9] * fE;
        },
        arg);
    return make_pair(x, make_pair(y, z));
}