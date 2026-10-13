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
    int stake; cout<<"stake [0..2000]"; cin>>stake;
    stake = (!bet? 0 : stake );
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
    bandageCost = (bandages - bandages/3) * bandagePriceBase;

    int alertAdj = guardAlert;
    if(takeMarbles) alertAdj += marbles/5;
    if(takeRope) alertAdj += ropeM/3;
    if(lightsOn) alertAdj += 10;
    if(cameras) alertAdj += 5;

    if(alertAdj>100) alertAdj = 100;

    int Crowd=0, Alert=0, Game=0, Cameras=0, Darkness=0;
    if(playersLeft>300) Crowd = 3; else if(playersLeft>150) Crowd = 2; else if(playersLeft>50) Crowd = 1; else Crowd = 0;
    if(alertAdj>=70) Alert = 2; else if(alertAdj>=40) Alert = 1; else Alert = 0;
    Game = (game>=4? 2 :  (game>=2? 1 : 0) );
    Cameras = (cameras? 1 : 0);
    Darkness = (!lightOn? -1 : 0);

    // Dangerpoints

    int dangerPoints = Crowd + Game + Cameras + Darkness;
    dangerpoints = (dangerpoints<0? 0 : dangerPoints);

    // Surcharge

    int SurchargePct = ( dangerPoints>=7? 50 : ( dangerPoints>=5? 25 : ( dangerPoints>=3? 10 : 0 ) ) );

    int NeedleS = (needleCost*(100+SurchargePct))/100;
    int BandageS = (bandageCost*(100+SurchargePct))/100;
    int MarbleS = (marbleCost*(100+SurchargePct))/100;
    int RopeS = (ropeCost*(100+SurchargePct))/100;

    int itemsAfterSurcharge = NeedleS + BandageS + MarbleS + RopeS;

    // Fees

    int lateFee = ( timeLeft<15? 250: ( timeLeft<45? 100 : 0) );
    int guardToll = 50 + (alertAdj/10)*5;
    guardToll = ( (card and !cameras)? 0 : guardToll );
    
    int base = ( type=='A'? 40 : (type=='T'? 30 : (type=='G'? 35 : 0 ) ) );
    int carryCap;
    carryCap = (ally? base + 10 : 0);
    int weightPenalty = ( ( 500 < 25 * ( 0 > (packKg-carryCap)? 0 : (packKg-carryCap)) )? 500 : 25* ( 0 > (packKg-carryCap)? 0 : (packKg-carryCap)));
    int wager = stake;

    //  Rebates and Injury Tax

    int allyRebate = (ally? 60 : 0);
    int calmRebate = ((!injuries? and stamina>=70) 40 : 0);
    int injuryTax = (injuries==1? 30 : injuries==2? 90 : injuries==3? 200 : 0);

    // Favors

    double favorDiscount = ( (favor==1 and (game==2 or game==4) )? 0.15*(NeedleS+MarbleS): (favor==2 and alertAdj>=60)? 0.5*(lateFee+guardToll): (favor==3 and injuries)? 0.35*(BandageS) : 0);

    favorDiscount = ( (favor==1 and favorDiscount>500)? 500 : (favor==2 and favorDiscount>250)? 250 : (favor==3 and favorDiscount>900)? 900 : favorDiscount );

    // Settlement

    int gross = itemsAfterSurcharge + lateFee + guardToll + weightPenalty + wager;
    int net = ( 0 > (gross + injuryTax - allyRebate - calmRebate - favorDiscount)? 0 : (gross + injuryTax - allyRebate - calmRebate - favorDiscount)  );
    int debtFee = ( (net>cash)? (80 + debt/20) : 0);

    return 0;   
}