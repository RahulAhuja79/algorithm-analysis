
#include<iostream>
using namespace std;
int findTips(double v)
{
    int tips=0;
    if(v<1.0)
    return 0;

    return 1+ findTips(v-0.425);
}
int main()
{
    cout<<"no of tips : "<<findTips(2)<<endl;
    return 0;
}