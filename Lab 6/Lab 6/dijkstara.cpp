//DIJKASTARA ALGORITHM
#include<iostream>
#define M 4
using namespace std;
void print(int arr[M][M],int start,int visited[M]);
void dijkastre(int arr[M][M],int start){
    int visited[M];
    for(int i=0;i<M;i++){
        visited[i]=0;
    }
    visited[start]=1;
        for(int i=0;i<M;i++){
            int minimum=99999999;
            int index;
            for(int j=0;j<M;j++){ 
                if(visited[j]==0 && arr[start][j]<minimum){
                    minimum=arr[start][j];
                    index=j;
                }
            }
             visited[index]=1;
                for(int k=0;k<M;k++){
                    if(visited[k]==0 && arr[index][k]<arr[start][k]){
                        arr[start][k]=arr[index][k];

                    }

                }
        }
        print(arr,start,visited);
}
void print(int arr[M][M],int start,int visited[M]){
    
    for(int i=0;i<M;i++){
        if(visited[i]==1){
        cout<<"the shortest path from "<<start<<" to "<<i<<" is "<<arr[start][i]<<endl;
        }
    }
} 
int main(){
    int array[M][M];
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
           cout<<"enter the element in array at "<<i<<" and "<<j<<": ";
           cin>>array[i][j]; 
        }
    }
    int start;
    cout<<"enter the starting point";
    cin>>start;
    dijkastre(array,start);
    return 0;
}