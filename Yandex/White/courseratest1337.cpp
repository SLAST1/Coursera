#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int z, bin, i = 0;
    vector<int> v;
    while (N >=1){
        z = N % 2;
        N = N / 2;
        v.push_back(z);
        ++i;
    }
    for (bin = i - 1;bin >= 0;bin--) {
        cout << v[bin];
    }
    return 0;
}





#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> bits;

    cin >> n;
    while (n > 0) {
        bits.push_back(n % 2);
        n /= 2;
    }

    for (int i = bits.size() - 1; i >= 0; --i) {
        cout << bits[i];
    }
    return 0;
}