/*//Определите тип Incognizable, для которого следующий код будет корректен:
int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
//*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Incognizable
{
    private:
        vector<int> st;
    public:
    Incognizable(){}
    Incognizable(int a1){
        st.push_back(a1);
    }

    Incognizable(int a1, int a2){
    st.push_back(a1); st.push_back(a2);
    }
};





struct Incognizable {
  int x = 0;
  int y = 0;
};