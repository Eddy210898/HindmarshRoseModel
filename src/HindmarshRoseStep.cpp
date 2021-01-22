#include "HindmarshRoseStep.h"

pair<float, pair<float, float>> HindmarshRoseStep(float xO, float yO, float zO, float t, float dT, HindmarshRoseParams &params, float I /*= 0*/)
{
    float arg[] = {
        params.getEi(), //0
        params.getS(),  //1
        params.getU(),  //2
        xO,             //3
        yO,             //4
        zO,             //5
        I               //6
    };
    float x = getNextRungeKuta(
        t, xO, dT, [](float t, float x, float args[]) {
            float sE = 3 * x * x;
            float tE = x * x * x;
            return args[4] + sE - tE - args[5] + args[0];
        },
        arg);

    float y = getNextRungeKuta(
        t, yO, dT, [](float t, float y, float args[]) {
            float sE = 5 * args[3] * args[3];
            return 1 - sE - y;
        },
        arg);
    //u*(-zi +S*(x+1.6))
    // a = (x+1.6)
    //  b =S*a
    // c = -zi +b
    float z = getNextRungeKuta(
        t, zO, dT, [](float t, float z, float args[]) {
            float a = args[3] + 1.6;
            float b = args[1] * a;
            float c = -z + b;
            return args[2] * c;
        },
        arg);
    return make_pair(x, make_pair(y, z));
}