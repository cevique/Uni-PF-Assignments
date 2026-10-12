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
    unsigned int marbles=0;
    if(takeMarbles){
        cout<<"marbles [0..100] "; cin>>marbles;
    }
    bool takeRope; cout<<"takeRope {0,1}: "; cin>>takeRope;
    unsigned int ropeM=0;
    if(takeRope){
        cout<<"ropeM [0..60]: meters of rope: "; cin>>ropeM;
    }
    int packKg; cout<<"packKg [0..150]: "; cin>>packKg;
    int stamina; cout<<"stamina [0..100]: "; cin>>stamina;
    int playersLeft; cout<<"playersLeft [3..456]: " cin>>playersLeft;
    int bet; cout<<"bet {0,1,2}: 0 = No bet, 1 = SAFE, 2 = RISKY : "; cin>>bet;
    int favor; cout<<"favor {0,1,2,3}: 0 = None, 1 = INSIDER, 2 = HUSH, 3 = MEDPASS : "; cin>>favor;
    int cash; cout<<"cash [0..6000]: "; cin>>cash;
    int debt; cout<<"debt [0..3000]: "; cin>>debt;
    bool card; cout<<"card {0,1}: "; cin>>card;
    bool ally; cout<<"ally {0,1}: "; cin>>ally;

    int needlePriceBase=150, bandagePriceBase=350, marblePriceBase=60, ropePriceBase=120;
    if(type=='A') ropePriceBase=100; else if(type=='T') needlePriceBase=120; else if(type=='G') marblePriceBase=45;

    double needleCost=0, marbleCost=0, bandageCost=0, ropeCost=0;
    if(needles>10) needleCost=10*needlePriceBase+(n-10)*(needlePriceBase*75/100); else needleCost=needles*needlePriceBase;
    if(marbles>50) marbleCost=50*marblePriceBase+(n-50)*(marblePriceBase*50/100); else marbleCost=marbles*marblePriceBase;

    return 0;   
}