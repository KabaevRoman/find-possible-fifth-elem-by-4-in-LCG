#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int main() {
    int x2_new, x3_new, x4_new, x5, c;
    int x[4];//= {157, 5054, 25789, 13214};
    for (int i = 0; i < 4; i++) {
        cout << "input " << i+1 << " element produced by generator: ";
        cin>>x[i];
    }
    int max_elem = *max_element(x, x + 3);
    vector<int> possibleFifthElem;
    cout << "possible coefficients (fifth element may duplicate)\n";
    for (int m = max_elem + 1; m < 65535; m++) {
        for (int a = 0; a < m; a++) {
            c = x[1] - ((x[0] * a) % m);
            if (c < 0)
                c += m;
            x2_new = (a * x[0] + c) % m;
            x3_new = (a * x2_new + c) % m;
            x4_new = (a * x3_new + c) % m;
            if ((x[1] == x2_new) && (x[2] == x3_new) && (x[3] == x4_new)) {
                cout << "m: " << m << " a: " << a << " c: " << c << endl;
                x5 = (a * x[3] + c) % m;
                auto temp = std::find(possibleFifthElem.begin(), possibleFifthElem.end(), x5);
                if (temp == possibleFifthElem.end())
                    possibleFifthElem.push_back(x5);
            }
        }
    }
    cout << "possible fifth element (duplicates removed):\n";
    for (auto t:possibleFifthElem) {
        cout << t << endl;
    }
    system("pause");
    return 0;
}