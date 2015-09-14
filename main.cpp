#include <iostream>

#include "hypercube.hpp"

using namespace hc;
using namespace std;

int main()
{
    
cout << "TEST 1: SEQUENCE FILL (T1 <- {0, ... , 23})" << endl;

    hypercube<4> hc1(2,3,2,2);
    {
        // COLUMN MAJOR ORDER FOR MATLAB/FORTRAN/ARMADILLO COMPATIBILITY!!!
        int i = 0;
        for (int d = 0; d < 2; ++d)
            for (int c = 0; c < 2; ++c)
                for (int b = 0; b < 3; ++b)
                    for (int a = 0; a < 2; ++a)
                    {
                        hc1(a,b,c,d) = i++;
                    }   
    }
    for (const auto& n : hc1) cout << n << ' ';

cout << endl << "TEST 2: CONSTANT FILL (T2 <- 3)" << endl;

    hyperfloat<3> hc2(2,3,4);
    hc2 = 3;
    for (const auto n : hc2) cout << n << ' ';
    cout << "(total size = " << hc2.size() << ")";

cout << endl << "TEST 3: COPY ASSIGNMENT WITH TYPE CONVERSION (T3 <- T1)" << endl;

    hyperint<4> hc3(2,3,2,2);
    hc3 = hc1;
    for (const auto& n : hc3) cout << n << ' ';

cout << endl << "TEST 4: CONSTANT ADDITION-ASSIGNMENT (T3 <- T3 + 2)" << endl;

    hc3 += 2;
    for (const auto& n : hc3) cout << n << ' ';

cout << endl << "TEST 5: ELEMENTWISE ADDITION-ASSIGNMENT (T3 <- T3 + T1)" << endl;
    
    hc3 += hc1;
    for (const auto& n : hc3) cout << n << ' ';

cout << endl << "TEST 6: CONSTANT ADDITION INTO A THIRD ARRAY (T4 <- 3 + T1 + 2)" << endl;

    hypercube<4> hc4(2,3,2,2);
    hc4 = 3 + hc1 + 2;
    for (const auto& n : hc4) cout << n << ' ';

cout << endl << "TEST 7: ELEMENTWISE ADDITION INTO A THIRD ARRAY (T4 <- T1 + T3)" << endl;

    hc4 = hc1 + hc3;
    for (const auto& n : hc4) cout << n << ' ';

cout << endl << "TEST 8: ELEMENTWISE MULTIPLY-AND-ADD INTO A THIRD ARRAY (T4 <- T1 * (T1 + T3))" << endl;

    hc4 = hc1 * (hc1 + hc3);
    for (const auto& n : hc4) cout << n << ' ';

cout << endl << "TEST 9: INITIALIZER LIST FILL" << endl;
    
    hypercube<3> hc5(2,2,2);
    hc5 = { 1, 2, 3, 4, 5, 6, 7, 8 };
    for (const auto& n : hc5) cout << n << ' ';

cout << endl << "TEST 10: EXP AND LOG, COMPLICATED EXPRESSION" << endl;

    hc5 = exp(1 + log(hc5 + hc5 - 1)) / 2;
    for (const auto& n : hc5) cout << n << ' ';

cout << endl;

}
