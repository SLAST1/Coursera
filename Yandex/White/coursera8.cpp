/*
2x^2 5x +2 = 0
D = 25 - 4*2*2 = 25 - 16 = 9 = 3^2        // 2 корня
x1 = -5-3/4 = -2                          //-b+-vD/2a
x2 = -5+3/4 = 0.5

2x^2 + 4x + 2 = 0
D = 16 - 4*2*2 = 16 - 16 = 0              // 1 корень
x = -4/4 = -1                             //-b/2a

2x^2 + x + 2 = 0
D = 1 - 4*2*2 = -7                        //реш нет
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{  
   double a, b, c;
   cin >> a >> b >> c;
   //ax2 + bx + c = 0
   //D = b^2 - 4ac
   //x1,2 = -b*vD/2a
   double D = b*b - 4*a*c;

   if (a == 0 && b != 0) {
        cout << -c / b << endl;
   } else if (a != 0) {
         if (D > 0) {
         cout << (-b + sqrt(D)) / 2 / a << " " << (-b - sqrt(D)) / 2 / a << endl;
         } else if (D == 0) {
            cout << -b / 2 / a << endl;
         }
   }
   return 0;
}








#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double A, B, C;
  cin >> A >> B >> C;

  // найдём дискриминант
  double D = B * B - 4 * A * C;

  // если A равно нулю, то уравнение линейное: Bx + C = 0
  if (A == 0) {
    
    // Bx = -C => x = -C / B
    if (B != 0) {
      cout << -C / B << endl;
    }
    // если B равно нулю, корней нет
    
  } else if (D == 0) {  // случай с нулевым дискриминантом
    
    // корень ровно один
    cout << -B / (2 * A) << endl;
    
  } else if (D > 0) {  // в случае с положительным дискриминантом корня два
  
    double r1 = (-B + sqrt(D)) / (2 * A);
    double r2 = (-B - sqrt(D)) / (2 * A);

    cout << r1 << " " << r2 << endl;
    
  }
  // если дискриминант отрицателен, действительных корней нет

  return 0;
}