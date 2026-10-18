#include<iostream>
using namespace std;
int main(){

    char type; cout<<"Player type: {A, T, G} ";
    while (!(cin >> type) || (type != 'A' && type != 'T' && type != 'G')) {
        cout << "Invalid input. Enter a value in [A, T, G]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int game; cout<<"\nGame {1..5}:"; cout<<"\n1. Red Light Green Light\n2. Honeycomb\n3. Tug of War\n4. Marbles\n5. Glass Bridge\n";
    while (!(cin >> game) || game < 1 || game > 5) {
        cout << "Invalid input. Enter a value in [1..5]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int timeLeft; cout<<"\nMinutes until the game starts.\ntimeLeft[0..120]: ";
    while (!(cin >> timeLeft) || timeLeft < 0 || timeLeft > 120) {
        cout << "Invalid input. Enter a value in [0..120]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int guardAlert; cout<<"guardAlert [0..100]: ";
    while (!(cin >> guardAlert) || guardAlert < 0 || guardAlert > 100) {
        cout << "Invalid input. Enter a value in [0..100]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int injuries; cout<<"Injuries [0..3]: ";
    while (!(cin >> injuries) || injuries < 0 || injuries > 3) {
        cout << "Invalid input. Enter a value in [0..3]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    bool lightsOn; cout<<"ligtsOn {0,1}: ";
    while (!(cin >> lightsOn) || lightsOn < 0 || lightsOn > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    bool cameras; cout<<"cameras {0,1}: ";
    while (!(cin >> cameras) || cameras < 0 || cameras > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    bool takeNeedles; cout<<"takeNeedles {0,1}: ";
    while (!(cin >> takeNeedles) || takeNeedles < 0 || takeNeedles > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    unsigned int needles=0;
    (takeNeedles)? cout<<"needles [0..40]: " : cout<<"";
    while (takeNeedles && (!(cin >> needles) || needles > 40)) {
        cout << "Invalid input. Enter a value in [0..40]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    (!takeNeedles)? (void)cin.ignore(100, '\n') : (void)0;
    bool takeBandages; cout<<"takeBandages {0,1}: ";
    while (!(cin >> takeBandages) || takeBandages < 0 || takeBandages > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    unsigned int bandages=0;
    (takeBandages)? cout<<"bandages [0..30]: " : cout<<"";
    while (takeBandages && (!(cin >> bandages) || bandages > 30)) {
        cout << "Invalid input. Enter a value in [0..30]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    (!takeBandages)? (void)cin.ignore(100, '\n') : (void)0;
    bool takeMarbles; cout<<"takeMarbles {0,1}: ";
    while (!(cin >> takeMarbles) || takeMarbles < 0 || takeMarbles > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    unsigned int marbles=0;
    (takeMarbles)? cout<<"marbles [0..100]: " : cout<<"";
    while (takeMarbles && (!(cin >> marbles) || marbles > 100)) {
        cout << "Invalid input. Enter a value in [0..100]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    (!takeMarbles)? (void)cin.ignore(100, '\n') : (void)0;
    bool takeRope; cout<<"takeRope {0,1}: ";
    while (!(cin >> takeRope) || takeRope < 0 || takeRope > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    unsigned int ropeM=0;
    (takeRope)? cout<<"ropeM [0..60]: meters of rope: " : cout<<"";
    while (takeRope && (!(cin >> ropeM) || ropeM > 60)) {
        cout << "Invalid input. Enter a value in [0..60]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    (!takeRope)? (void)cin.ignore(100, '\n') : (void)0;
    int packKg; cout<<"packKg [0..150]: ";
    while (!(cin >> packKg) || packKg < 0 || packKg > 150) {
        cout << "Invalid input. Enter a value in [0..150]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int stamina; cout<<"stamina [0..100]: ";
    while (!(cin >> stamina) || stamina < 0 || stamina > 100) {
        cout << "Invalid input. Enter a value in [0..100]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int playersLeft; cout<<"playersLeft [3..456]: ";
    while (!(cin >> playersLeft) || playersLeft < 3 || playersLeft > 456) {
        cout << "Invalid input. Enter a value in [3..456]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int bet; cout<<"bet {0,1,2}: 0 = No bet, 1 = SAFE, 2 = RISKY : ";
    while (!(cin >> bet) || bet < 0 || bet > 2) {
        cout << "Invalid input. Enter a value in [0..2]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int stake; cout<<"stake [0..2000]";
    while (!(cin >> stake) || stake < 0 || stake > 2000) {
        cout << "Invalid input. Enter a value in [0..2000]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    stake = (!bet? 0 : stake );
    int favor; cout<<"favor {0,1,2,3}: 0 = None, 1 = INSIDER, 2 = HUSH, 3 = MEDPASS : ";
    while (!(cin >> favor) || favor < 0 || favor > 3) {
        cout << "Invalid input. Enter a value in [0..3]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int cash; cout<<"cash [0..6000]: ";
    while (!(cin >> cash) || cash < 0 || cash > 6000) {
        cout << "Invalid input. Enter a value in [0..6000]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int debt; cout<<"debt [0..3000]: ";
    while (!(cin >> debt) || debt < 0 || debt > 3000) {
        cout << "Invalid input. Enter a value in [0..3000]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    bool card; cout<<"card {0,1}: ";
    while (!(cin >> card) || card < 0 || card > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    bool ally; cout<<"ally {0,1}: ";
    while (!(cin >> ally) || ally < 0 || ally > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }

    int needlePriceBase=150, bandagePriceBase=350, marblePriceBase=60, ropePriceBase=120;
    ropePriceBase = (type=='A')? 100 : ropePriceBase;
    needlePriceBase = (type=='T')? 120 : needlePriceBase;
    marblePriceBase = (type=='G')? 45 : marblePriceBase;

    double needleCost=0, marbleCost=0, bandageCost=0, ropeCost=0;
    needleCost = ( needles>10? 10*needlePriceBase+(needles-10)*(needlePriceBase*75/100) : needles*needlePriceBase);
    marbleCost= ( marbles>50? 50*marblePriceBase+(marbles-50)*(marblePriceBase*50/100) : marbles*marblePriceBase);
    bandageCost = (bandages - bandages/3) * bandagePriceBase;
    ropeCost = ropeM * ropePriceBase;

    int alertAdj = guardAlert;
    alertAdj += takeMarbles*marbles/5;
    alertAdj += takeRope*ropeM/3;
    alertAdj += lightsOn*10;
    alertAdj += cameras*5;

    alertAdj = (alertAdj>100)? 100 : alertAdj;

    int Crowd=0, Alert=0, Game=0, Cameras=0, Darkness=0;
    Crowd = (playersLeft>300? 3 : playersLeft>150? 2 : playersLeft>50? 1 : 0);
    Alert = (alertAdj>=70? 2 : alertAdj>=40? 1 : 0);
    Game = (game>=4? 2 :  (game>=2? 1 : 0) );
    Cameras = (cameras? 1 : 0);
    Darkness = (!lightsOn? -1 : 0);

    // Dangerpoints

    int dangerPoints = Crowd + Game + Cameras + Darkness;
    dangerPoints = (dangerPoints<0? 0 : dangerPoints);

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
    carryCap = base + (ally? 10 : 0);
    int weightPenalty = ( ( 500 < 25 * ( 0 > (packKg-carryCap)? 0 : (packKg-carryCap)) )? 500 : 25* ( 0 > (packKg-carryCap)? 0 : (packKg-carryCap)));
    int wager = stake;

    //  Rebates and Injury Tax

    int allyRebate = (ally? 60 : 0);
    int calmRebate = ((!injuries and stamina>=70)? 40 : 0);
    int injuryTax = (injuries==1? 30 : injuries==2? 90 : injuries==3? 200 : 0);

    // Favors

    double favorDiscount = ( (favor==1 and (game==2 or game==4) )? 0.15*(NeedleS+MarbleS): (favor==2 and alertAdj>=60)? 0.5*(lateFee+guardToll): (favor==3 and injuries)? 0.35*(BandageS) : 0);

    favorDiscount = ( (favor==1 and favorDiscount>500)? 500 : (favor==2 and favorDiscount>250)? 250 : (favor==3 and favorDiscount>900)? 900 : favorDiscount );

    // Settlement

    int gross = itemsAfterSurcharge + lateFee + guardToll + weightPenalty + wager;
    int net = ( 0 > (gross + injuryTax - allyRebate - calmRebate - favorDiscount)? 0 : (gross + injuryTax - allyRebate - calmRebate - favorDiscount)  );
    int DebtFee = ( (net>cash)? (80 + debt/20) : 0);
    int Total = net + DebtFee;
    Total = (Total<200? 200 : Total);
    int Fees = lateFee + guardToll + weightPenalty + injuryTax + DebtFee;
    int CashUsed = (cash<Total? cash : Total);
    int Payable = Total - CashUsed;

    // Survival Chance and Outcome

    int SurvivalChance = 40;
    SurvivalChance = (takeRope? SurvivalChance+(15<ropeM/2? 15 : ropeM/2) : SurvivalChance);
    SurvivalChance = (takeBandages? SurvivalChance+(12<2*bandages? 12 : 2*bandages) : SurvivalChance );
    SurvivalChance += stamina/4;
    SurvivalChance = (card? SurvivalChance+8 : SurvivalChance-25);
    SurvivalChance = (ally? SurvivalChance+5 : SurvivalChance);
    SurvivalChance -= (0>packKg-carryCap? 0 : packKg-carryCap)/2;
    SurvivalChance -= 5*(SurchargePct/10);
    SurvivalChance -= 8*injuries;
    SurvivalChance -= 4*(game-1);
    SurvivalChance -= (DebtFee>0? 12:0);
    SurvivalChance += (game==2? ( (takeNeedles and needles>=5)? 10 : 0) : game==4? ( (takeMarbles and marbles>=20)? 10 : 0 ) : game==5? ( (takeRope and ropeM>=10)? 10 : 0 ) : 0 );

    SurvivalChance = (SurvivalChance>100? 100 : (SurvivalChance<0? 0 : SurvivalChance));

    bool Outcome = SurvivalChance>=55;

    // Prize and Final Balance

    int prizePool = (456-playersLeft)*100;
    int PrizeShare = (Outcome? prizePool/playersLeft : 0) ;
    int BetPayout = (Outcome? (bet==1? (stake*3)/2 : bet==2? (stake*4*(SurvivalChance>=75)) : 0) : 0);
    int FinalBalance = cash - Total + PrizeShare + BetPayout;

    // Output

    cout << "\nNeedleCost=" << needleCost;
    cout << "\nBandageCost=" << bandageCost;
    cout << "\nMarbleCost=" << marbleCost;
    cout << "\nRopeCost=" << ropeCost;
    cout << "\nDanger Points=" << dangerPoints;
    cout << "\nSurchargePct=" << SurchargePct << "%";
    cout << "\nLateFee=" << lateFee;
    cout << "\nGuardToll=" << guardToll;
    cout << "\nWeightPenalty=" << weightPenalty;
    cout << "\nWager=" << wager;
    cout << "\nFavorDiscount=" << favorDiscount;
    cout << "\nFees=" << Fees;
    cout << "\nTotal=" << Total;
    cout << "\nCashUsed=" << CashUsed;
    cout << "\nPayable=" << Payable;
    cout << "\nSurvivalChance=" << SurvivalChance;
    cout << "\nOutcome=" << Outcome;
    cout << "\nPrizeShare=" << PrizeShare;
    cout << "\nBetPayout=" << BetPayout;
    cout << "\nFinalBalance=" << FinalBalance;  
    cout << endl;`
    return 0;   
}