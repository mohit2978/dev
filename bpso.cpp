#include<iostream>
#include<climits>
#include<ctime>
using namespace std;
int objective_function(int x){
   // return (x*x*x)-(12*x)+2;
   return -5*(x*x)+3+(14*x);
}
void display(float arr[],int n){
    for(int i=1;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}
void bpso(int nop,int itr,int xl,int xu){
    float pbest[nop+1];
    float x[nop+1];
    float velocity[nop+1];
    float gbest=INT_MIN;
    float fvalue[nop+1];
    for(int i=1;i<nop+1;i++){
        //generating best position of the particles
        pbest[i]=xl+static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(xu-xl)));
        x[i]=pbest[i];
        //velocity is initilaised to zero
        velocity[i]=0;
        //generating gbest 
        if(pbest[i]>gbest){
            gbest=pbest[i];
        }
        //generating fvalue
        fvalue[i]=objective_function(x[i]);
    }
    int c1=1;
    int c2=1;
    for(int i=0;i<itr;i++){
        //random variables
        float r1=0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1-0)));
        float r2=0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1-0)));
        //run for ALL partiles
        for(int j=1;j<=nop;j++){
            //prev velocity and prev position of particle
            int pv=velocity[j];
            int px=x[j];
            //finding new velocity
            velocity[j]=pv+c1*r1*(pbest[j]-x[j])+c2*r2*(gbest-x[j]);
            //finding new position
            x[j]=velocity[j]+px;
            //generating function value on new pos
            fvalue[j]=objective_function(x[j]);
             //if new particle pos function value is good than pbest then update pbest
            if(fvalue[j]>objective_function(pbest[j])){
                pbest[j]=x[j];
            }
             //if new particle pos function value is good than gbest then update gbest
            if(fvalue[j]>objective_function(gbest)){
                 gbest=x[j];
            }
        }
        display(pbest,nop+1);
        cout<<"\n";
    }
    cout<<gbest;
}
int main(){
    int xl=0;
    int xu=4;
    //cout<<"enter number of particles and iterations";
    int nop=10;
    int itr=50;
    //cin>>nop>>itr;
    bpso(nop,itr,xl,xu);
    return 0;
}