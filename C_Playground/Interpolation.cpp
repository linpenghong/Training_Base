/*******************************************************************************
 * Author: Mingxu Hu
 * Dependency: 
 * Test:
 * Execution:
 * Description:
 *
 * Manual:
 * ****************************************************************************/

#include <iostream>

#include "Interpolation.h"

using namespace std;

int main()
{
    {
        cout << "BI_LINEAR" << endl;

        double v[2][2] = {{1, 2}, {3, 4}};

        cout << v[0][0] << endl;
        cout << v[0][1] << endl; // v[0] = {1, 2}
        cout << v[1][0] << endl;
        cout << v[1][1] << endl; // v[1] = {3, 4}
        double wd1[2] = {0.5, 0.5};
        cout << BI_LINEAR(v, wd1) << endl;
        double wd2[2] = {0.5, 0};
        cout << BI_LINEAR(v, wd2) << endl;
        double wd3[2] = {0.5, 1};
        cout << BI_LINEAR(v, wd3) << endl;
    }

    {
        cout << "WG_NEAREST" << endl;

        double w[2];
        int x0;

        WG_NEAREST(w, x0, 0.5);
        cout << x0 << endl;
        cout << w[0] << " " << w[1] << endl;

        WG_NEAREST(w, x0, 0.1);
        cout << x0 << endl;
        cout << w[0] << " " << w[1] << endl;

        WG_NEAREST(w, x0, 0.9);
        cout << x0 << endl;
        cout << w[0] << " " << w[1] << endl;
    }

    {
        cout << "WG_TRI_NEAREST" << endl;
        double w[2][2][2];
        int x0[3];

        double x1[3] = {0.1, 0.9, 0.9};
        WG_TRI_NEAREST(w, x0, x1);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                    cout << w[i][j][k] << " ";
                cout << endl;
            }
    }
    
    {
        cout << "WG_BI_LINEAR" << endl;
        double w[2][2];
        int x0[2];

        double x1[2] = {0.5, 0.5};
        WG_BI_LINEAR(w, x0, x1); 

        FOR_CELL_DIM_2 cout << w[i][j] << endl;
    }

    {
        cout << "WG_TRI_LINEAR" << endl;
        double w[2][2][2];
        int x0[3];

        double x1[3] = {0.5, 0.5, 0.5};
        WG_TRI_LINEAR(w, x0, x1);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                    cout << w[i][j][k] << " ";
                cout << endl;
            }
    }

    return 0;
}
