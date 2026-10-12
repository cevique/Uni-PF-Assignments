#include<iostream>
using namespace std;
int main(){

    int type; cout<<"Player type: {A, T, G} "; cin>>type;
    int game; cout<<"\nGame {1..5}:"; cout<<"\n1. Red Light Green Light\n2. Honeycomb\n3. Tug of War\n4. Marbles\n5. Glass Bridge\n"; cin>>game;
    int timeLeft; cout<<"\nMinutes until the game starts.\ntimeLeft[0..120]: "; cin>>timeLeft;
    int guardAlert; cout<<"guardAlert [0..100]: "; cin>>guardAlert;
    int injuries; cout<<"Injuries [0..3]: "; cin>>injuries;
    bool lightsOn; cout<<"ligtsOn {0,1}: "; cin>>lightsOn;
    bool cameras; cout<<"cameras {0,1}: "; cin>>cameras;
    bool takeNeedles; cout<<"takeNeedles {0,1}: "; cin>>takeNeedles;
    unsigned int needles=0;
    if(takeNeedles){
        cout<<"needles [0..40]: "; cin>>needles;
    }
    bool takeBandages; cout<<"takeBandages {0,1}: "; cin>>takeBandages;
    unsigned int bandages=0;
    if(takeBandages){
        cout<<"bandages [0..30]: "; cin>>bandages;
    }
    bool takeMarbles; cout<<"takeMarbles {0,1}: "; cin>>takeMarbles;
    


    return 0;   
}