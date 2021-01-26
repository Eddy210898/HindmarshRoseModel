#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "src/HindmarshRoseModel.h"
#include "src/HindmarshRoseParams.h"

using namespace std;

int main(int argc, char *argv[])
{
    HindmarshRoseParams params;
    params.a = 1;
    params.b = 3;
    params.c = 1;
    params.d = 5;
    params.r = 0.001;

    float xO = -1.5, yO = 1 - 5 * (pow(xO, 2)), zO = params.getS() * (xO + 1.6);
    params.xO = xO;
    vector<float>
        p = HindmarshRoseModel(xO, yO, zO, 0.1, params, 1, 15000, 1);

    fstream exampleSimulation;
    exampleSimulation.open("example.txt", ios::out);
    if (!exampleSimulation)
    {
        throw "File not created!";
    }
    else
    {
        int n = p.size();
        cout << "File created successfully!";
        float count = 1;
        for (auto i = p.begin(); i != p.end(); ++i)
        {
            exampleSimulation << *i << "\t" << count << endl;
            count = count + 0.1;
        }
        exampleSimulation.close();
    }
}