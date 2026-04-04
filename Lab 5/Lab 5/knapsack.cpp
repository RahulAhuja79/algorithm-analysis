#include<iostream>
#include<vector>
#include<algorithm>
# define MAX 10000
using namespace std;
struct Pair{
    int profit;
    int weight;
    
};

bool compare1(Pair a,Pair b ){
    
        return ((double)a.profit/a.weight)>=((double)b.profit/b.weight);
    
}
bool compare2(Pair a,Pair b ){
    
        return a.profit>=b.profit;
    
}
bool compare3(Pair a,Pair b ){
    
        return a.weight<=b.weight;
    
}


float knapsack3(Pair a[] ,int n,int M,double value){
    sort(a,a+n,compare3);

for(int i=0;i<n;i++){
    if(a[i].weight<=M && M>0 ){
      M-=a[i].weight;
      value+=a[i].profit;
    }
    else{
        value+=a[i].profit*((double)M/a[i].weight);
        break;
    }
}
return value;

}


float knapsack2(Pair a[] ,int n,int M,double value){
    sort(a,a+n,compare2);

for(int i=0;i<n;i++){
    if(a[i].weight<=M && M>0 ){
      M-=a[i].weight;
      value+=a[i].profit;
    }
    else{
        value+=a[i].profit*((double)M/a[i].weight);
        break;
    }
}
return value;

}
float knapsack1(Pair a[] ,int n,int M,double value){
    sort(a,a+n,compare1);

for(int i=0;i<n;i++){
    if(a[i].weight<=M && M>0 ){
      M-=a[i].weight;
      value+=a[i].profit;
    }
    else{
        value+=a[i].profit*((double)M/a[i].weight);
        break;
    }
}
return value;

}

int main(){
    int n;
    cout<<"size\tProfit with p/w\t\tProfit with profit\tProfit with weight"<<endl;
for(int i=10;i<=50;i+=10){
  n=i;

Pair arr[MAX];
 for (int i = 0; i < n; i++)
            { arr[i].profit = rand();
            arr[i].weight=rand();}

// Pair arr[MAX]={{10,20},{5,10},{6,15},{15,5},{10,2}};
    int M;

    M=rand();
    
   cout<<n<<"\t"<<knapsack1(arr,n,M,0.0)<< "\t\t\t" <<knapsack2(arr,n,M,0.0)<<"\t\t\t"<<knapsack3(arr,n,M,0.0)<<endl;
}
}