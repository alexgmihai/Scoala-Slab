#include <iostream>
#include <math.h>
using namespace std;

int countPrefix[101];
int countSufix[101];

int prefix(int x) {
    while (x > 99)
        x /= 10;
    return x;
}

int sufix(int x) {
    float aux = x / 100.0;
    aux = aux - floor(aux);
    return round(aux * 100);
}

int main() {
    int x;

    while (cin >> x) {
        if (x > 99) {
            countSufix[sufix(x)]++;
            countPrefix[prefix(x)]++;
        }
    }

    int cnt = 0;
    for (int i = 10; i <= 100; i++)
        if (countPrefix[i] && countPrefix[i] == countSufix[i])
            cnt++;
    cout << cnt;
    
    return 0;
}