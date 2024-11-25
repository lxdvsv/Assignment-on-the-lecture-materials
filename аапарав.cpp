#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

const long long OPERATIONS = 500000000; // 500 000 000 

int main()
{
    double y; //Были моменты непонимания. Я искал как правильно сделать в интернете и постепенно постигал истину, как истинный воин.

    auto startTime = chrono::high_resolution_clock::now(); // до оптимизации юный воин измерил время
    for (size_t i = 0; i < 10; i++) {
        for (long long x = 1; x < OPERATIONS; x++) {
            y = 5.5 * pow(x, 7) - 3.3 * pow(x, 5) + 4.2 * pow(x, 4) - 7.8 * pow(x, 3) + 2.6 * pow(x, 2) + sin(x) - tan(x) + 1.2 / x; // алгебраическая функция как удар катаны: мощная и решительная. 
        }
    }
    auto finishTime = chrono::high_resolution_clock::now();
    auto executionTime = chrono::duration_cast<chrono::milliseconds>(finishTime - startTime).count();
    cout << endl << "Calculation result (before optimization): " << y << endl;
    cout << "Execution time (before optimization): " << executionTime << " ms" << endl;

    startTime = chrono::high_resolution_clock::now(); // замер времени, когда путь к совершенству уже пройден
    for (size_t i = 0; i < 10; i++) {
        for (long long x = 1; x < OPERATIONS; x++) {
            //Оптимизирую вычисления: как точность в каждом движении
            double x2 = x * x;
            double x3 = x2 * x;
            double x4 = x3 * x;
            double x5 = x4 * x;
            double x7 = x5 * x2;

            double sinx = sin(x);
            double tanx = tan(x);
            double frac = 1.2 / x;

            y = 5.5 * x7 - 3.3 * x5 + 4.2 * x4 - 7.8 * x3 + 2.6 * x2 + sinx - tanx + frac;
        }
    }
    finishTime = chrono::high_resolution_clock::now();
    executionTime = chrono::duration_cast<chrono::milliseconds>(finishTime - startTime).count();
    cout << endl << "Calculation result (after optimization): " << y << endl;
    cout << "Execution time (after optimization): " << executionTime << " ms" << endl;
}
