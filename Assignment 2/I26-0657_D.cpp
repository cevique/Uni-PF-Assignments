#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    int qn;
    bool validChoice = false;
    while (!validChoice) {
        cout << "Enter question number (1-8): ";
        if (cin >> qn) {
            if (qn >= 1 and qn <= 8) {
                validChoice = true;
            }
            else {
                cout << "Invalid question number. Enter a value between 1 and 8." << endl;
            }
        }
        else {
            cout << "Invalid input. Enter a number between 1 and 8." << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }

    switch (qn){

    case 1:
    {

    char type; cout<<"Player type: {A, T, G} ";
    while (!(cin >> type) or (type != 'A' and type != 'T' and type != 'G')) {
        cout << "Invalid input. Enter a value in [A, T, G]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int game; cout<<"\nGame {1..5}:"; cout<<"\n1. Red Light Green Light\n2. Honeycomb\n3. Tug of War\n4. Marbles\n5. Glass Bridge\n";
    while (!(cin >> game) or game < 1 or game > 5) {
        cout << "Invalid input. Enter a value in [1..5]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int timeLeft; cout<<"\nMinutes until the game starts.\ntimeLeft[0..120]: ";
    while (!(cin >> timeLeft) or timeLeft < 0 or timeLeft > 120) {
        cout << "Invalid input. Enter a value in [0..120]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int guardAlert; cout<<"guardAlert [0..100]: ";
    while (!(cin >> guardAlert) or guardAlert < 0 or guardAlert > 100) {
        cout << "Invalid input. Enter a value in [0..100]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int injuries; cout<<"Injuries [0..3]: ";
    while (!(cin >> injuries) or injuries < 0 or injuries > 3) {
        cout << "Invalid input. Enter a value in [0..3]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    bool lightsOn; cout<<"ligtsOn {0,1}: ";
    while (!(cin >> lightsOn) or lightsOn < 0 or lightsOn > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    bool cameras; cout<<"cameras {0,1}: ";
    while (!(cin >> cameras) or cameras < 0 or cameras > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    bool takeNeedles; cout<<"takeNeedles {0,1}: ";
    while (!(cin >> takeNeedles) or takeNeedles < 0 or takeNeedles > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    unsigned int needles=0;
    (takeNeedles)? cout<<"needles [0..40]: " : cout<<"";
    while (takeNeedles and (!(cin >> needles) or needles > 40)) {
        cout << "Invalid input. Enter a value in [0..40]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    (!takeNeedles)? (void)cin.ignore(100, '\n') : (void)0;
    bool takeBandages; cout<<"takeBandages {0,1}: ";
    while (!(cin >> takeBandages) or takeBandages < 0 or takeBandages > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    unsigned int bandages=0;
    (takeBandages)? cout<<"bandages [0..30]: " : cout<<"";
    while (takeBandages and (!(cin >> bandages) or bandages > 30)) {
        cout << "Invalid input. Enter a value in [0..30]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    (!takeBandages)? (void)cin.ignore(100, '\n') : (void)0;
    bool takeMarbles; cout<<"takeMarbles {0,1}: ";
    while (!(cin >> takeMarbles) or takeMarbles < 0 or takeMarbles > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    unsigned int marbles=0;
    (takeMarbles)? cout<<"marbles [0..100]: " : cout<<"";
    while (takeMarbles and (!(cin >> marbles) or marbles > 100)) {
        cout << "Invalid input. Enter a value in [0..100]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    (!takeMarbles)? (void)cin.ignore(100, '\n') : (void)0;
    bool takeRope; cout<<"takeRope {0,1}: ";
    while (!(cin >> takeRope) or takeRope < 0 or takeRope > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    unsigned int ropeM=0;
    (takeRope)? cout<<"ropeM [0..60]: meters of rope: " : cout<<"";
    while (takeRope and (!(cin >> ropeM) or ropeM > 60)) {
        cout << "Invalid input. Enter a value in [0..60]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    (!takeRope)? (void)cin.ignore(100, '\n') : (void)0;
    int packKg; cout<<"packKg [0..150]: ";
    while (!(cin >> packKg) or packKg < 0 or packKg > 150) {
        cout << "Invalid input. Enter a value in [0..150]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int stamina; cout<<"stamina [0..100]: ";
    while (!(cin >> stamina) or stamina < 0 or stamina > 100) {
        cout << "Invalid input. Enter a value in [0..100]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int playersLeft; cout<<"playersLeft [3..456]: ";
    while (!(cin >> playersLeft) or playersLeft < 3 or playersLeft > 456) {
        cout << "Invalid input. Enter a value in [3..456]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int bet; cout<<"bet {0,1,2}: 0 = No bet, 1 = SAFE, 2 = RISKY : ";
    while (!(cin >> bet) or bet < 0 or bet > 2) {
        cout << "Invalid input. Enter a value in [0..2]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int stake; cout<<"stake [0..2000]";
    while (!(cin >> stake) or stake < 0 or stake > 2000) {
        cout << "Invalid input. Enter a value in [0..2000]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    stake = (!bet? 0 : stake );
    int favor; cout<<"favor {0,1,2,3}: 0 = None, 1 = INSIDER, 2 = HUSH, 3 = MEDPASS : ";
    while (!(cin >> favor) or favor < 0 or favor > 3) {
        cout << "Invalid input. Enter a value in [0..3]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int cash; cout<<"cash [0..6000]: ";
    while (!(cin >> cash) or cash < 0 or cash > 6000) {
        cout << "Invalid input. Enter a value in [0..6000]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    int debt; cout<<"debt [0..3000]: ";
    while (!(cin >> debt) or debt < 0 or debt > 3000) {
        cout << "Invalid input. Enter a value in [0..3000]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    bool card; cout<<"card {0,1}: ";
    while (!(cin >> card) or card < 0 or card > 1) {
        cout << "Invalid input. Enter a value in [0..1]: ";
        cin.clear(); cin.ignore(100, '\n');
    }
    bool ally; cout<<"ally {0,1}: ";
    while (!(cin >> ally) or ally < 0 or ally > 1) {
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
    cout << endl;
    }
        break;

    case 2:
    {
    // Part A
    double U, th, D;
    cout << "Enter wind speed (U), terrain slope angle (th in radians), and vegetation fuel dryness index (D): ";
    cin >> U >> th >> D;
    double w=0.8, b=0.12, u=15.0, mew=3.4, d=0.5;
    double del_v = w*exp(b*U) + u*pow(sin(th), 2) + mew*log((D+1.0)/d) + sqrt(abs(U*cos(th)+1.0));
    cout << "1. Delta V: " << fixed << setprecision(4) << del_v << endl;
    
    // Part B
    int v_int = static_cast<int>(del_v);
    int F1 = static_cast<int>((del_v-v_int)*100);
    int F2 = static_cast<int>((del_v-v_int)*10000)%100;
    int R = 6570%89+10;
    int K = v_int*1000000 + F1*10000 + F2*100 + R;
    cout << "2. Telemetry key K: " << K << endl;

    // Part C
    int kR = K % 100;
    char c1 = 'A' + (K / 1000000) % 26;;
    char c2 = 'Z' - kR % 26;
    string c1c2 = {c1, c2};
    float v_float = static_cast<float>(K / 1000000) + static_cast<float>((K / 10000) % 100) / 100.0f + static_cast<float>((K / 100) % 100) / 10000.0f;
    double v_double = static_cast<double>(K / 1000000) + static_cast<double>((K / 10000) % 100) / 100.0 + static_cast<double>((K / 100) % 100) / 10000.0;
    cout << "3. Status Tag: " << c1c2 << endl;
    cout << "4. Precision Match Flag: " << boolalpha << (v_float == v_double) << endl;
    cout << "5. Threat Rating: " << kR + ((! (v_float == v_double)) * 25) + static_cast<int>(1.5 * v_double) << endl;
    }
        break;

    case 3:
    {

    // Murdoch navigation tracking
    int murVisitedBoilerRoom = 1;
    int murVisitedCargoHold = 0;
    int murVisitedThirdClass = 0;
    int murVisitedDiningSaloon = 0;
    int murVisitedPromenadeDeck = 0;
    int murVisitedBridge = 0;
    int murVisitedLifeboatDeck = 0;
    int murVisitedCrowsNest = 0;
    int murCurrent = 0;
    int murIsFrozen = 0;

    // Mary navigation tracking
    int maryVisitedBoilerRoom = 1;
    int maryVisitedCargoHold = 0;
    int maryVisitedThirdClass = 0;
    int maryVisitedDiningSaloon = 0;
    int maryVisitedPromenadeDeck = 0;
    int maryVisitedBridge = 0;
    int maryVisitedLifeboatDeck = 0;
    int maryVisitedCrowsNest = 0;
    int maryCurrent = 0;
    int maryIsFrozen = 0;

    cout << "Murdoch: Boiler Room\n";
    cout << "Mary: Boiler Room\n";

    // Murdoch: From Boiler Room, visit Cargo Hold or Third Class
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 0:
                    switch (murVisitedCargoHold) {
                        case 0:
                            murCurrent = 1;
                            cout << "Murdoch: Cargo Hold\n";
                            break;
                        case 1:
                            switch (murVisitedThirdClass) {
                                case 0:
                                    murCurrent = 2;
                                    cout << "Murdoch: Third Class\n";
                                    break;
                            }
                            break;
                    }
                    break;
            }
            switch (murCurrent) {
                case 1:
                    murVisitedCargoHold = 1;
                    break;
                case 2:
                    murVisitedThirdClass = 1;
                    break;
            }
            break;
        case 1:
            break;
    }

    // Murdoch: From Cargo Hold, visit Dining Saloon or Promenade Deck
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 1:
                    switch (murVisitedDiningSaloon) {
                        case 0:
                            murCurrent = 3; 
                            cout << "Murdoch: Dining Saloon\n";
                            break;
                        case 1:
                            switch (murVisitedPromenadeDeck) {
                                case 0:
                                    murCurrent = 4;
                                    cout << "Murdoch: Promenade Deck\n";
                                    break;
                            }
                            break;
                    }
                    break;
            }
            switch (murCurrent) {
                case 3:
                    murVisitedDiningSaloon = 1;
                    break;
                case 4:
                    murVisitedPromenadeDeck = 1;
                    break;
            }
            break;
        case 1:
            break;
    }

    // Murdoch: From Dining Saloon, visit Crow's Nest
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 3:
                    switch (murVisitedCrowsNest) {
                        case 0:
                            murCurrent = 7;
                            cout << "Murdoch: Crow's Nest\n";
                            break;
                        case 1:
                            break;
                    }
                    break;
            }
            switch (murCurrent) {
                case 7:
                    murVisitedCrowsNest = 1;
                    switch (murVisitedDiningSaloon) {
                        case 1:
                            cout << "DoorSealed\n";
                            murVisitedDiningSaloon = 0;
                            break;
                        case 0:
                            break;
                    }
                    break;
            }
            break;
        case 1:
            break;
    }

    // Murdoch: From Crow's Nest, return to Dining Saloon or Promenade Deck
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 7:
                    switch (murVisitedDiningSaloon) {
                        case 0:
                            murCurrent = 3;
                            cout << "Murdoch: Dining Saloon\n";
                            break;
                        case 1:
                            switch (murVisitedPromenadeDeck) {
                                case 0:
                                    murCurrent = 4;
                                    cout << "Murdoch: Promenade Deck\n";
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }
                    break;
            }
            switch (murCurrent) {
                case 3:
                    murVisitedDiningSaloon = 1;
                    break;
                case 4:
                    murVisitedPromenadeDeck = 1;
                    break;
            }
            break;
        case 1:
            break;
    }

    // Murdoch: From Dining Saloon, return to Cargo Hold if Third Class unvisited
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 3:
                    switch (murVisitedCargoHold) {
                        case 1:
                            switch (murVisitedCrowsNest) {
                                case 1:
                                    switch (murVisitedThirdClass) {
                                        case 0:
                                            cout << "TurnBack\n";
                                            murCurrent = 1;
                                            cout << "Murdoch: Cargo Hold\n";
                                            break;
                                        case 1:
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            switch (murCurrent) {
                case 1:
                    murVisitedCargoHold = 1;
                    break;
            }
            break;
        case 1:
            break;
    }

    // Murdoch: From Cargo Hold, visit next unvisited location (Third Class, Dining Saloon, or Promenade Deck)
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 1:
                    switch (murVisitedThirdClass) {
                        case 0:
                            murCurrent = 2;
                            cout << "Murdoch: Third Class\n";
                            break;
                        case 1:
                            switch (murVisitedDiningSaloon) {
                                case 0:
                                    murCurrent = 3;
                                    cout << "Murdoch: Dining Saloon\n";
                                    break;
                                case 1:
                                    switch (murVisitedPromenadeDeck) {
                                        case 0:
                                            murCurrent = 4;
                                            cout << "Murdoch: Promenade Deck\n";
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            switch (murCurrent) {
                case 2:
                    murVisitedThirdClass = 1;
                    break;
            }
            break;
        case 1:
            break;
    }

    // Mary: From Boiler Room, visit Cargo Hold or Third Class
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 0:
                    switch (maryVisitedCargoHold) {
                        case 0:
                            maryCurrent = 1;
                            cout << "Mary: Cargo Hold\n";
                            break;
                        case 1:
                            switch (maryVisitedThirdClass) {
                                case 0:
                                maryCurrent = 2;
                                cout << "Mary: Third Class\n";
                                break;
                            } break;
                    } break;
            }
            switch (maryCurrent) {
                case 1:
                    maryVisitedCargoHold = 1;
                    break;
                case 2:
                    maryVisitedThirdClass = 1;
                    break;
            } break;
        case 1: break;
    }

    // Mary: From Cargo Hold, return to Boiler Room or go to Dining Saloon/Promenade Deck
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 1:
                    switch (maryVisitedThirdClass) {
                        case 0:
                            maryCurrent = 0;
                            cout << "Mary: Boiler Room\n";
                            break;
                        case 1:
                            switch (maryVisitedDiningSaloon) {
                                case 0:
                                    maryCurrent = 3;
                                    cout << "Mary: Dining Saloon\n";
                                    break;
                                case 1:
                                    switch (maryVisitedPromenadeDeck) {
                                        case 0:
                                            maryCurrent = 4;
                                            cout << "Mary: Promenade Deck\n";
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            switch (maryCurrent) {
                case 0:
                    maryVisitedBoilerRoom = 1;
                    break;
                case 3:
                    maryVisitedDiningSaloon = 1;
                    break;
                case 4:
                    maryVisitedPromenadeDeck = 1;
                    break;
            }
            break;
        case 1:
            break;
    }

    // Mary: From Boiler Room, visit Third Class
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 0:
                    switch (maryVisitedCargoHold) {
                        case 1:
                            switch (maryVisitedThirdClass) {
                                case 0:
                                    maryCurrent = 2;
                                    cout << "Mary: Third Class\n";
                                    break;
                            }
                            break;
                    }
                    break;
            }
            switch (maryCurrent) {
                case 2:
                    maryVisitedThirdClass = 1;
                    break;
            }
            break;
        case 1:
            break;
    }

    // Mary: From Third Class, visit Bridge (triggers WaterRising event)
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 2:
                    switch (maryVisitedBridge) {
                        case 0:
                            cout << "WaterRising\n";
                            maryCurrent = 5;
                            cout << "Mary: Bridge\n";
                            maryVisitedBridge = 1;
                            break;
                        case 1:
                            switch (maryVisitedBridge) {
                                case 1:
                                    maryCurrent = 5;
                                    cout << "Mary: Bridge\n";
                                    break;
                            }
                            break;
                    }
                    break;
            }
            switch (maryCurrent) {
                case 5:
                    maryVisitedBridge = 1;
                    break;
            }
            break;
        case 1:
            break;
    }

    // Mary: From Bridge, visit Lifeboat Deck or Crow's Nest
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 5:
                    switch (maryVisitedLifeboatDeck) {
                        case 0:
                            maryCurrent = 6;
                            cout << "Mary: Lifeboat Deck\n";
                            break;
                        case 1:
                            switch (maryVisitedCrowsNest) {
                                case 0:
                                    maryCurrent = 7;
                                    cout << "Mary: Crow's Nest\n";
                                    break;
                            }
                            break;
                    } 
                    break;
            }
            switch (maryCurrent) {
                case 6:
                    maryVisitedLifeboatDeck = 1;
                    break;
                case 7:
                    maryVisitedCrowsNest = 1;
                    break;
            }
            switch (maryCurrent) {
                case 6:
                    cout << "Rescued\n";
                    maryIsFrozen = 1;
                    break;
            }
            break;
        case 1:
            break;
    }

    // Mary: At Lifeboat Deck, character is rescued (end state)
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 6:
                    cout << "Rescued\n";
                    maryIsFrozen = 1;
                    break;
            }
            break;
        case 1:
            break;
    }

    cout << endl << "Murdoch path: Boiler Room -> Cargo Hold -> Dining Saloon -> Crow's Nest -> Dining Saloon -> Cargo Hold -> Third Class\n";
    cout << "Mary path: Boiler Room -> Cargo Hold -> Boiler Room -> Third Class -> Bridge -> Lifeboat Deck\n";
    }
        break;

    case 4:
    {
        int n; cout<<"Enter size: "; cin>>n;
        if (n>0) {
            for (int r=0; r<n; r++) {
                for (int c = 0; c < n; ++c) {
                        int y = ((r<(n-1-r))? r : n-1-r);
                        int x = ((c<(n-1-c))? c : n-1-c);
                        int d = (x>y? x:y);
                        if (d % 2 == 0 or x == 0 or y == 0) {
                            cout << "* ";
                        }
                        else {
                            cout << "  ";
                        }
                    }
                    cout << '\n';
                }
            }
            else {
                cout << "Please enter a valid positive integer.\n";
            }
    }
        break;

    case 5:
    {
    
    char userChoice;
    cout << "Enter choice (A/B): "; cin >> userChoice;

    switch (userChoice) {
    case 'A': {
        int houseWidth, houseHeight, doorWidth, doorHeight, atticHeight, chimneyCount, walkwayHeight;
        bool isInputValid;

        // User Input & Validation
        while (true) {
            cout << "Width of house: ";
            while (!(cin >> houseWidth) or houseWidth < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(100, '\n');
            }
            cout << "Height of house: ";
            while (!(cin >> houseHeight) or houseHeight < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(100, '\n');
            }
            cout << "Width of door: ";
            while (!(cin >> doorWidth) or doorWidth < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(100, '\n');
            }
            cout << "Height of door: ";
            while (!(cin >> doorHeight) or doorHeight < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(100, '\n');
            }
            cout << "Height of attic (base to roof): ";
            while (!(cin >> atticHeight) or atticHeight < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(100, '\n');
            }
            cout << "Number of chimneys: ";
            while (!(cin >> chimneyCount) or chimneyCount < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(100, '\n');
            }
            cout << "Height of walkway: ";
            while (!(cin >> walkwayHeight) or walkwayHeight < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(100, '\n');
            }

            isInputValid = true;
            if (atticHeight < 1){
                cout << "Error: attic height must be at least 1.\n";
                isInputValid = false;
            }
            else if (walkwayHeight < 1){
                cout << "Error: walkway height must be at least 1.\n";
                isInputValid = false;
            }
            else if (houseWidth % 2 != 0 or doorWidth % 2 != 0){
                cout << "Error: house width and door width must both be even.\n";
                isInputValid = false;
            }
            else if (doorWidth < 4){
                cout << "Error: door width must be at least 4.\n";
                isInputValid = false;
            }
            else if (doorHeight < 3){
                cout << "Error: door height must be at least 3.\n";
                isInputValid = false;
            }
            else if (houseWidth < doorWidth + 20){
                cout << "Error: house too narr (width must be at least door width + 20).\n"; isInputValid = false;
            }
            else if (houseWidth < 2 * atticHeight + 2){
                cout << "Error: attic is too wide for the house width.\n";
                isInputValid = false;
            }
            else if (houseHeight < atticHeight + walkwayHeight + (doorHeight + 1 > 6 ? doorHeight + 1 : 6)){
                cout << "Error: house height too small for attic, door and walkway.\n";
                isInputValid = false;
            }
            else if (walkwayHeight > (houseWidth - doorWidth) / 2){
                cout << "Error: walkway too tall for this house width.\n";
                isInputValid = false;
            }
            else if (chimneyCount > 0 and atticHeight < 3){
                cout << "Error: attic must be at least 3 tall to hold chimneys.\n";
                isInputValid = false;
            }
            else if (chimneyCount > 0 and chimneyCount > 2 * ((houseWidth / 2 - atticHeight - 1) / 6)){
                cout << "Error: too many chimneys for this house width.\n";
                isInputValid = false;
            }
            if (isInputValid)
                break;
            
            cout << "Please re-enter all inputs.\n\n";
        }

        // Structural Dimensions Calculation
        int centerColumn = houseWidth / 2;
        int doorLeftColumn = (houseWidth - doorWidth) / 2;
        int doorBottomRow = houseHeight - walkwayHeight - 1;
        int doorTopRow = doorBottomRow - doorHeight + 1;
        int roofWingWidth = centerColumn - atticHeight - 1;
        int leftSideChimneys = (chimneyCount + 1) / 2;
        int rightSideChimneys = chimneyCount / 2;

        cout << "\n";

        // House ASCII Rendering
        for (int r = 0; r < houseHeight; r++) {
            for (int c = 0; c < houseWidth; c++) {
                char drawChar = ' ';

                if (r >= houseHeight - walkwayHeight) {
                    // Walkway Section
                    int walkRowOffset = r - (houseHeight - walkwayHeight);
                    if (c == doorLeftColumn - 1 - walkRowOffset) drawChar = '/';
                    else if (c == doorLeftColumn + doorWidth + walkRowOffset) drawChar = '\\';
                    else if (walkRowOffset == walkwayHeight - 1 and c >= doorLeftColumn - walkRowOffset and c < doorLeftColumn + doorWidth + walkRowOffset) drawChar = '_';
                }
                else if (r < atticHeight) {
                    // Attic & Chimneys Section
                    if (c == centerColumn - 1 - r) drawChar = '/';
                    else if (c == centerColumn + r) drawChar = '\\';
                    else if (atticHeight >= 4 and r == atticHeight - 2 and c == centerColumn - 1) drawChar = '[';
                    else if (atticHeight >= 4 and r == atticHeight - 2 and c == centerColumn) drawChar = ']';
                    else if (chimneyCount > 0 and r >= atticHeight - 3) {
                        int chimneyOffset = -1;
                        for (int side = 0; side < 2; side++) {
                            int segmentStart = (side == 0) ? 1 : centerColumn + atticHeight;
                            int chimneyCountOnSide = (side == 0) ? leftSideChimneys : rightSideChimneys;

                            if (chimneyCountOnSide > 0 and c >= segmentStart and c < segmentStart + roofWingWidth) {
                                int slotSize = roofWingWidth / chimneyCountOnSide;
                                int chimneyIndex = (c - segmentStart) / slotSize;
                                if (chimneyIndex < chimneyCountOnSide) {
                                    int offsetInChimney = c - (segmentStart + chimneyIndex * slotSize + (slotSize - 5) / 2);
                                    if (offsetInChimney >= 0 and offsetInChimney <= 4) chimneyOffset = offsetInChimney;
                                }
                            }
                        }

                        if (chimneyOffset >= 0) {
                            int chimneyRowOffset = r - (atticHeight - 3);
                            if (chimneyRowOffset == 0) { if (chimneyOffset == 1 or chimneyOffset == 3) drawChar = ')'; }
                            else if (chimneyRowOffset == 1) drawChar = '=';
                            else {
                                if (chimneyOffset == 1 or chimneyOffset == 3) drawChar = '|';
                                else if (chimneyOffset == 2) drawChar = '_';
                            }
                        }
                    }
                }
                else if (r == atticHeight) {
                    // Roof Baseline
                    if (c >= 1 and c <= houseWidth - 2) drawChar = '_';
                }
                else if (c == 0 or c == houseWidth - 1) {
                    // Outer Walls
                    drawChar = '|';
                }
                else if (c >= doorLeftColumn and c <= doorLeftColumn + doorWidth - 1) {
                    // Door Section
                    if (r == doorTopRow) {
                        if (c > doorLeftColumn and c < doorLeftColumn + doorWidth - 1) drawChar = '_';
                    }
                    else if (r > doorTopRow) {
                        if (c == doorLeftColumn or c == doorLeftColumn + doorWidth - 1) drawChar = '|';
                        else if (r == doorTopRow + doorHeight / 2 and c == doorLeftColumn + doorWidth - 2) drawChar = 'o';
                        else if (r == doorBottomRow) drawChar = '_';
                    }
                }
                else {
                    // Windows Section
                    if (r >= doorBottomRow - 4 and r <= doorBottomRow - 1) {
                        int regionStart = (c < doorLeftColumn) ? 1 : doorLeftColumn + doorWidth;
                        int regionWidth = doorLeftColumn - 1;
                        int windowsInRegion = regionWidth / 9;
                        int relativeCol = c - regionStart - (regionWidth - windowsInRegion * 9) / 2;

                        if (relativeCol >= 0 and relativeCol / 9 < windowsInRegion) {
                            int windowColOffset = relativeCol % 9 - 1;
                            int windowRowOffset = r - (doorBottomRow - 4);

                            if (windowColOffset >= 0 and windowColOffset <= 6) {
                                if (windowRowOffset == 0) { if (windowColOffset >= 1 and windowColOffset <= 5) drawChar = '_'; }
                                else if (windowRowOffset == 1) { if (windowColOffset == 0 or windowColOffset == 3 or windowColOffset == 6) drawChar = '|'; }
                                else if (windowRowOffset == 2) {
                                    if (windowColOffset == 0 or windowColOffset == 6) drawChar = '|';
                                    else if (windowColOffset == 3) drawChar = '+';
                                    else drawChar = '-';
                                }
                                else {
                                    if (windowColOffset == 0 or windowColOffset == 3 or windowColOffset == 6) drawChar = '|';
                                    else drawChar = '_';
                                }
                            }
                        }
                    }
                    if (r == doorBottomRow and drawChar == ' ') drawChar = '_';
                }
                cout << drawChar;
            }
            cout << "\n";
        }
        break;
    }
    case 'B': {
        int inputCode;
        cout << "Enter a 4 digit input : "; cin >> inputCode;

        // Extract Digits
        int firstDigit  = inputCode / 1000;
        int secondDigit = inputCode / 100 % 10;
        int thirdDigit  = inputCode / 10 % 10;
        int fourthDigit = inputCode % 10;

        // Train Car ASCII Rendering
        for (int r = 1; r <= 6; r++) {
            int currentDigit = 0;

            for (int cartPosition = 1; cartPosition <= 4; ++cartPosition) {
                if (cartPosition == 1)      currentDigit = firstDigit;
                else if (cartPosition == 2) currentDigit = secondDigit;
                else if (cartPosition == 3) currentDigit = thirdDigit;
                else if (cartPosition == 4) currentDigit = fourthDigit;

                // Row 1
                if (r == 1) {
                    if (currentDigit == 1)      cout << "   o O                          ";
                    else if (currentDigit == 2) cout << "                     ";
                    else if (currentDigit == 3) cout << "                      ";
                    else if (currentDigit == 4) cout << "                          ";
                }
                // Row 2
                else if (r == 2) {
                    if (currentDigit == 1)      cout << "   ___[ ]___  _________________  ";
                    else if (currentDigit == 2) cout << "  _________________  ";
                    else if (currentDigit == 3) cout << "|==================|  ";
                    else if (currentDigit == 4) cout << "       __[___]__          ";
                }
                // Row 3
                else if (r == 3) {
                    if (currentDigit == 1)      cout << " |_________|_| [ ]       [ ] |  ";
                    else if (currentDigit == 2) cout << " | []  []  []  []  | ";
                    else if (currentDigit == 3) cout << "|    |   []   |    |  ";
                    else if (currentDigit == 4) cout << " \'-===================-\'  ";
                }
                // Row 4
                else if (r == 4) {
                    if (currentDigit == 1)      cout << " |___( )___|_|_______________|  ";
                    else if (currentDigit == 2) cout << " | []  []  []  []  | ";
                    else if (currentDigit == 3) cout << "|    |   or   |    |  ";
                    else if (currentDigit == 4) cout << "(    ~~~~~~~~~~~~~~~    ) ";
                }
                // Row 5
                else if (r == 5) {
                    if (currentDigit == 1)      cout << "<============================]--";
                    else if (currentDigit == 2) cout << "-|_________________|-";
                    else if (currentDigit == 3) cout << "|____|___or___|____|--";
                    else if (currentDigit == 4) cout << " \'-====================-\',";
                }
                // Row 6
                else if (r == 6) {
                    if (currentDigit == 1)      cout << " (O)     (O)  (O)         (O)   ";
                    else if (currentDigit == 2) cout << "   (O)         (O)   ";
                    else if (currentDigit == 3) cout << "    (O)      (O)      ";
                    else if (currentDigit == 4) cout << "    (O)             (0)   ";
                }
            }
            cout << endl;
        }
        break;
    }
    default: cout << "Please choice A or B next time.\n"; break;
    }
    }
        break;

    case 6:
    {
    
    int size;
    cout << "Enter size (e.g. 16): ";
    cin >> size;

    int halfHeight = 3 * size / 2 + 1;
    int halfWidth = 7 * size / 4;
    int tip = 2 * halfHeight - 1;
    int figureWidth = 2 * tip + 1;
    int termWidth = 120;
    int leftPad = (termWidth > figureWidth) ? (termWidth - figureWidth) / 2 : 0;

    for (int row = -halfHeight; row <= halfHeight; row++)
    {
        for (int p = 0; p < leftPad; p++)
            cout << ' ';

        int distanceY = (row < 0) ? -row : row;
        int distanceFromTip = halfHeight - distanceY;
        int outerEdge = 2 * distanceFromTip;

        if (outerEdge > halfWidth)
            outerEdge = halfWidth;

        int innerEdge = 2 * distanceFromTip - 4;

        if (innerEdge > halfWidth - 2)
            innerEdge = halfWidth - 2;

        int scaledY = row * 16 / size;
        int vertical = scaledY * 19;

        for (int col = -tip; col <= tip; col++)
        {
            int distanceX = (col < 0) ? -col : col;
            int scaledX = col * 16 / size;
            int absScaledX = (scaledX < 0) ? -scaledX : scaledX;
            int horizontal = absScaledX * 10;
            int distanceSquared = horizontal * horizontal
                                + vertical * vertical;

            bool face = false;

            // FACE
            if (scaledY >= -8 and scaledY <= 8
                and distanceSquared <= 175 * 175
                and distanceSquared > 134 * 134)
                face = true;

            // Eyes - Rectangular, scaled with input
            // Right eye: scaledX in [4, 8], scaledY in [-5, -1]
            // Left eye: scaledX in [-8, -4], scaledY in [-5, -1]
            if (absScaledX >= 4 and absScaledX <= 8 and scaledY >= -5 and scaledY <= -1)
                face = true;

            // Sad mouth
            int mouthOuter = horizontal * horizontal * 4225
                           + (vertical - 95) * (vertical - 95) * 9025;

            int mouthInner = horizontal * horizontal * 1225
                           + (vertical - 95) * (vertical - 95) * 3600;

            if (vertical >= 20 and vertical <= 95
                and mouthOuter <= 9025 * 4225
                and mouthInner > 3600 * 1225)
                face = true;

            // Blood drops
            if (absScaledX == 23 and scaledY >= 1 and scaledY <= 3)
                face = true;

            if (absScaledX == 17 and scaledY >= 5 and scaledY <= 8)
                face = true;

            if (absScaledX == 12 and scaledY >= 8 and scaledY <= 10)
                face = true;

            if (absScaledX == 6 and scaledY >= 9 and scaledY <= 10)
                face = true;

            if (absScaledX <= 1 and scaledY >= 9 and scaledY <= 10)
                face = true;

            if (face)
                cout << "\033[91m#\033[0m";  // Bright red face
            else if (distanceX >= innerEdge and distanceX <= outerEdge)
                cout << "\033[37mX\033[0m";  // White border
            else if (distanceX >= 2 * distanceFromTip - 7
                     and distanceX <= 2 * distanceFromTip - 3)
                cout << "\033[36m+\033[0m";  // Cyan diagonal lines
            else if (distanceY == 0
                     and distanceX > halfWidth and distanceX <= tip)
                cout << "\033[36m+\033[0m";  // Cyan middle line
            else if (distanceX < innerEdge)
            {
                if ((distanceFromTip + distanceX) % 2 == 1)
                    cout << "\033[90m.\033[0m";  // Dark gray dotted interior
                else
                    cout << " ";
            }
            else
                cout << " ";
        }

        cout << '\n';
    }

    }
        break;

    case 7:
    {
    int value1 = 0, value2 = 0;
    int addoutput = 0, suboutputA_B = 0, suboutputB_A = 0;
    int multLow = 0, multHigh = 0, quotoutput = 0, remoutput = 0;
    char sign_choice;
    bool is_signed, valid;
    int temp, digit, len;
    bool only_binary;

    // INPUT A
    valid = false;
    while (!valid) {
        cout << "Input A : ";
        cin >> value1;

        if (value1 < 0) {
            cout << "Input must be greater than or equal to 0.\n";
            continue;
        }

        temp = value1;
        len = 0;
        only_binary = true;

        if (temp == 0) len = 1;

        while (temp > 0) {
            digit = temp % 10;
            if (digit != 0 and digit != 1) only_binary = false;
            len++;
            temp /= 10;
        }

        if (!only_binary or len > 6) {
            cout << "Invalid input. Enter only 0s and 1s, max 6 digits.\n";
            continue;
        }

        valid = true;
    }

    // INPUT B
    valid = false;
    while (!valid) {
        cout << "Input B : ";
        cin >> value2;

        if (value2 < 0) {
            cout << "Input must be greater than or equal to 0.\n";
            continue;
        }

        temp = value2;
        len = 0;
        only_binary = true;

        if (temp == 0) len = 1;

        while (temp > 0) {
            digit = temp % 10;
            if (digit != 0 and digit != 1) only_binary = false;
            len++;
            temp /= 10;
        }

        if (!only_binary or len > 6) {
            cout << "Invalid input. Enter only 0s and 1s, max 6 digits.\n";
            continue;
        }

        valid = true;
    }

    cout << "Are these numbers signed or unsigned? Y/N: ";
    cin >> sign_choice;
    is_signed = (sign_choice == 'Y' or sign_choice == 'y');

    int p10_5 = 100000;
    int bin_val, bits_len, dec_val, cur_p10, cur_p2;
    bool check_sign;

    // DISPLAY A IN DECIMAL
    bin_val = value1;
    bits_len = 6;
    check_sign = is_signed;
    dec_val = 0;
    cur_p10 = 1;
    cur_p2 = 1;

    for (int i = 0; i < bits_len - 1; i++) {
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cur_p10 *= 10;
        cur_p2 *= 2;
    }

    if (check_sign and ((bin_val / cur_p10) % 10 == 1))
        dec_val -= cur_p2;
    else
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

    cout << "A : " << dec_val << '\n';

    // DISPLAY B IN DECIMAL
    bin_val = value2;
    dec_val = 0;
    cur_p10 = 1;
    cur_p2 = 1;

    for (int i = 0; i < 5; i++) {
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cur_p10 *= 10;
        cur_p2 *= 2;
    }

    if (check_sign and ((bin_val / cur_p10) % 10 == 1))
        dec_val -= cur_p2;
    else
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

    cout << "B : " << dec_val << '\n';

    int sign_ext_A = is_signed ? (value1 / p10_5) % 10 : 0;
    int sign_ext_B = is_signed ? (value2 / p10_5) % 10 : 0;
    int p10_i, carry, s;

    // ADDITION
    int addoutput7 = 0;
    carry = 0;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bitA = (i < 6) ? (value1 / p10_i) % 10 : sign_ext_A;
        int bitB = (i < 6) ? (value2 / p10_i) % 10 : sign_ext_B;

        s = bitA + bitB + carry;

        if (i < 6)
            addoutput += (s % 2) * p10_i;

        addoutput7 += (s % 2) * p10_i;
        carry = s / 2;
        p10_i *= 10;
    }

    bool ovf_add = false;

    if (is_signed) {
        int bitA5 = (value1 / p10_5) % 10;
        int bitB5 = (value2 / p10_5) % 10;
        int sum5 = (addoutput / p10_5) % 10;

        if (bitA5 == bitB5 and sum5 != bitA5)
            ovf_add = true;
    } else {
        if ((addoutput7 / 1000000) % 10 != 0)
            ovf_add = true;
    }

    if (ovf_add) {
        bin_val = addoutput7;
        bits_len = 7;
    } else {
        bin_val = addoutput;
        bits_len = 6;
    }

    dec_val = 0;
    cur_p10 = 1;
    cur_p2 = 1;

    for (int i = 0; i < bits_len - 1; i++) {
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cur_p10 *= 10;
        cur_p2 *= 2;
    }

    if (is_signed and ((bin_val / cur_p10) % 10 == 1))
        dec_val -= cur_p2;
    else
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

    if (ovf_add)
        cout << "A + B = " << setw(7) << setfill('0') << addoutput7
             << " = " << dec_val << "\toverflow detected\n";
    else
        cout << "A + B = " << setw(6) << setfill('0') << addoutput
             << " = " << dec_val << "\tno overflow\n";

    // A - B: COMPLEMENT B AND ADD 1
    int compB7 = 0;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bitB = (i < 6) ? (value2 / p10_i) % 10 : sign_ext_B;
        compB7 += (1 - bitB) * p10_i;
        p10_i *= 10;
    }

    int negB7 = 0;
    int c = 1;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bit = (compB7 / p10_i) % 10;
        s = bit + c;
        negB7 += (s % 2) * p10_i;
        c = s / 2;
        p10_i *= 10;
    }

    int suboutputA_B7 = 0;
    carry = 0;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bitA = (i < 6) ? (value1 / p10_i) % 10 : sign_ext_A;
        int bitNegB = (negB7 / p10_i) % 10;

        s = bitA + bitNegB + carry;

        if (i < 6)
            suboutputA_B += (s % 2) * p10_i;

        suboutputA_B7 += (s % 2) * p10_i;
        carry = s / 2;
        p10_i *= 10;
    }

    bool ovf_subA_B = false;

    if (is_signed) {
        int bitA5 = (value1 / p10_5) % 10;
        int bitB5 = (value2 / p10_5) % 10;
        int sum5 = (suboutputA_B / p10_5) % 10;

        if (bitA5 != bitB5 and sum5 != bitA5)
            ovf_subA_B = true;
    } else {
        if (carry == 0)
            ovf_subA_B = true;
    }

    bin_val = ovf_subA_B ? suboutputA_B7 : suboutputA_B;
    bits_len = ovf_subA_B ? 7 : 6;
    dec_val = 0;
    cur_p10 = 1;
    cur_p2 = 1;

    for (int i = 0; i < bits_len - 1; i++) {
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cur_p10 *= 10;
        cur_p2 *= 2;
    }

    if (is_signed and ((bin_val / cur_p10) % 10 == 1))
        dec_val -= cur_p2;
    else
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

    if (ovf_subA_B)
        cout << "A - B = " << setw(7) << setfill('0') << suboutputA_B7
             << " = " << dec_val << "\toverflow detected\n";
    else
        cout << "A - B = " << setw(6) << setfill('0') << suboutputA_B
             << " = " << dec_val << "\tno overflow\n";

    // B - A: COMPLEMENT A AND ADD 1
    int compA7 = 0;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bitA = (i < 6) ? (value1 / p10_i) % 10 : sign_ext_A;
        compA7 += (1 - bitA) * p10_i;
        p10_i *= 10;
    }

    int negA7 = 0;
    c = 1;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bit = (compA7 / p10_i) % 10;
        s = bit + c;
        negA7 += (s % 2) * p10_i;
        c = s / 2;
        p10_i *= 10;
    }

    int suboutputB_A7 = 0;
    carry = 0;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bitB = (i < 6) ? (value2 / p10_i) % 10 : sign_ext_B;
        int bitNegA = (negA7 / p10_i) % 10;

        s = bitB + bitNegA + carry;

        if (i < 6)
            suboutputB_A += (s % 2) * p10_i;

        suboutputB_A7 += (s % 2) * p10_i;
        carry = s / 2;
        p10_i *= 10;
    }

    bool ovf_subB_A = false;

    if (is_signed) {
        int bitA5 = (value1 / p10_5) % 10;
        int bitB5 = (value2 / p10_5) % 10;
        int sum5 = (suboutputB_A / p10_5) % 10;

        if (bitB5 != bitA5 and sum5 != bitB5)
            ovf_subB_A = true;
    } else {
        if (carry == 0)
            ovf_subB_A = true;
    }

    bin_val = ovf_subB_A ? suboutputB_A7 : suboutputB_A;
    bits_len = ovf_subB_A ? 7 : 6;
    dec_val = 0;
    cur_p10 = 1;
    cur_p2 = 1;

    for (int i = 0; i < bits_len - 1; i++) {
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cur_p10 *= 10;
        cur_p2 *= 2;
    }

    if (is_signed and ((bin_val / cur_p10) % 10 == 1))
        dec_val -= cur_p2;
    else
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

    if (ovf_subB_A)
        cout << "B - A = " << setw(7) << setfill('0') << suboutputB_A7
             << " = " << dec_val << "\toverflow detected\n";
    else
        cout << "B - A = " << setw(6) << setfill('0') << suboutputB_A
             << " = " << dec_val << "\tno overflow\n";

    // GET POSITIVE MAGNITUDES FOR MULTIPLICATION AND DIVISION
    int magA_mul = value1;
    int magB_mul = value2;

    if (is_signed and (value1 / p10_5) % 10 == 1) {
        int comp = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            comp += (1 - ((value1 / p10_i) % 10)) * p10_i;
            p10_i *= 10;
        }

        c = 1;
        magA_mul = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            s = (comp / p10_i) % 10 + c;
            magA_mul += (s % 2) * p10_i;
            c = s / 2;
            p10_i *= 10;
        }
    }

    if (is_signed and (value2 / p10_5) % 10 == 1) {
        int comp = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            comp += (1 - ((value2 / p10_i) % 10)) * p10_i;
            p10_i *= 10;
        }

        c = 1;
        magB_mul = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            s = (comp / p10_i) % 10 + c;
            magB_mul += (s % 2) * p10_i;
            c = s / 2;
            p10_i *= 10;
        }
    }

    // MULTIPLICATION: TWO SIX-BIT CHUNKS, NO ARRAYS
    for (int i = 0; i < 6; i++) {
        int p10_shift = 1;

        for (int k = 0; k < i; k++)
            p10_shift *= 10;

        if ((magB_mul / p10_shift) % 10 == 1) {
            int newLow = 0, newHigh = 0;
            int p10_j = 1;
            carry = 0;

            for (int j = 0; j < 12; j++) {
                int bit_mult;
                int bit_shifted = 0;

                if (j < 6)
                    bit_mult = (multLow / p10_j) % 10;
                else
                    bit_mult = (multHigh / p10_j) % 10;

                if (j >= i and j - i < 6) {
                    int sourcePower = 1;

                    for (int k = 0; k < j - i; k++)
                        sourcePower *= 10;

                    bit_shifted = (magA_mul / sourcePower) % 10;
                }

                s = bit_mult + bit_shifted + carry;
                int outBit = s % 2;
                carry = s / 2;

                if (j < 6)
                    newLow += outBit * p10_j;
                else
                    newHigh += outBit * p10_j;

                if (j == 5 or j == 11)
                    p10_j = 1;
                else
                    p10_j *= 10;
            }

            multLow = newLow;
            multHigh = newHigh;
        }
    }

    // NEGATE THE 12-BIT PRODUCT IF REQUIRED
    bool is_mul_neg = is_signed and
        (((value1 / p10_5) % 10) != ((value2 / p10_5) % 10));

    if (is_mul_neg) {
        int compLow = 0, compHigh = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            compLow += (1 - ((multLow / p10_i) % 10)) * p10_i;
            compHigh += (1 - ((multHigh / p10_i) % 10)) * p10_i;
            p10_i *= 10;
        }

        multLow = 0;
        c = 1;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            s = (compLow / p10_i) % 10 + c;
            multLow += (s % 2) * p10_i;
            c = s / 2;
            p10_i *= 10;
        }

        multHigh = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            s = (compHigh / p10_i) % 10 + c;
            multHigh += (s % 2) * p10_i;
            c = s / 2;
            p10_i *= 10;
        }
    }

    int decimalProduct = 0;
    int productPower = 1;
    p10_i = 1;

    for (int i = 0; i < 12; i++) {
        int bit;

        if (i < 6)
            bit = (multLow / p10_i) % 10;
        else
            bit = (multHigh / p10_i) % 10;

        decimalProduct += bit * productPower;
        productPower *= 2;

        if (i == 5)
            p10_i = 1;
        else
            p10_i *= 10;
    }

    if (is_signed and (multHigh / 100000) % 10 == 1)
        decimalProduct -= 4096;

    cout << "A * B = " << setw(6) << setfill('0') << multHigh << setw(6) << setfill('0') << multLow << " = " << decimalProduct << "\t\tmust be 12 bits/digits long, sign/unsigned according to input\n";

    // DIVISION AND MODULO
    if (magB_mul == 0) {
        cout << "Division by zero is undefined.\n";
    } else {
        quotoutput = 0;
        remoutput = 0;

        for (int i = 5; i >= 0; i--) {
            int shiftPower = 1;

            for (int k = 0; k < i; k++)
                shiftPower *= 10;

            int incomingBit = (magA_mul / shiftPower) % 10;

            remoutput = remoutput * 10 + incomingBit;

            bool gte = true;
            int p10_k = 100000;

            for (int k = 5; k >= 0; k--) {
                int r_bit = (remoutput / p10_k) % 10;
                int b_bit = (magB_mul / p10_k) % 10;

                if (r_bit > b_bit) {
                    gte = true;
                    break;
                }

                if (r_bit < b_bit) {
                    gte = false;
                    break;
                }

                p10_k /= 10;
            }

            if (gte) {
                int compB = 0;
                p10_k = 1;

                for (int k = 0; k < 6; k++) {
                    compB += (1 - ((magB_mul / p10_k) % 10)) * p10_k;
                    p10_k *= 10;
                }

                int negB = 0;
                int cy = 1;
                p10_k = 1;

                for (int k = 0; k < 6; k++) {
                    s = (compB / p10_k) % 10 + cy;
                    negB += (s % 2) * p10_k;
                    cy = s / 2;
                    p10_k *= 10;
                }

                int newRem = 0;
                cy = 0;
                p10_k = 1;

                for (int k = 0; k < 6; k++) {
                    s = ((remoutput / p10_k) % 10)
                      + ((negB / p10_k) % 10) + cy;

                    newRem += (s % 2) * p10_k;
                    cy = s / 2;
                    p10_k *= 10;
                }

                remoutput = newRem;

                int qPower = 1;

                for (int k = 0; k < i; k++)
                    qPower *= 10;

                quotoutput += qPower;
            }
        }

        // NEGATE QUOTIENT WHEN SIGNS DIFFER
        if (is_signed and
            (((value1 / p10_5) % 10) != ((value2 / p10_5) % 10))) {

            int compQ = 0;
            int p10_k = 1;

            for (int k = 0; k < 6; k++) {
                compQ += (1 - ((quotoutput / p10_k) % 10)) * p10_k;
                p10_k *= 10;
            }

            int negQ = 0;
            int cy = 1;
            p10_k = 1;

            for (int k = 0; k < 6; k++) {
                s = (compQ / p10_k) % 10 + cy;
                negQ += (s % 2) * p10_k;
                cy = s / 2;
                p10_k *= 10;
            }

            quotoutput = negQ;
        }

        // NEGATE REMAINDER WHEN DIVIDEND IS NEGATIVE
        if (is_signed and (value1 / p10_5) % 10 == 1) {
            int compR = 0;
            int p10_k = 1;

            for (int k = 0; k < 6; k++) {
                compR += (1 - ((remoutput / p10_k) % 10)) * p10_k;
                p10_k *= 10;
            }

            int negR = 0;
            int cy = 1;
            p10_k = 1;

            for (int k = 0; k < 6; k++) {
                s = (compR / p10_k) % 10 + cy;
                negR += (s % 2) * p10_k;
                cy = s / 2;
                p10_k *= 10;
            }

            remoutput = negR;
        }

        // DISPLAY QUOTIENT
        bin_val = quotoutput;
        dec_val = 0;
        cur_p10 = 1;
        cur_p2 = 1;

        for (int i = 0; i < 5; i++) {
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cur_p10 *= 10;
            cur_p2 *= 2;
        }

        if (is_signed and ((bin_val / cur_p10) % 10 == 1))
            dec_val -= cur_p2;
        else
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

        cout << "A / B = " << setw(6) << setfill('0') << quotoutput
             << " = " << dec_val << "\t\tgive only the quotient\n";

        // DISPLAY REMAINDER
        bin_val = remoutput;
        dec_val = 0;
        cur_p10 = 1;
        cur_p2 = 1;

        for (int i = 0; i < 5; i++) {
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cur_p10 *= 10;
            cur_p2 *= 2;
        }

        if (is_signed and ((bin_val / cur_p10) % 10 == 1))
            dec_val -= cur_p2;
        else
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

        cout << "A % B = " << setw(6) << setfill('0') << remoutput
             << " = " << dec_val << "\t\tgive only the remainder, inheriting sign of dividend\n";
    }

    }
        break;

    case 8:
    {

    srand(time(NULL));

    int pmX = rand() % 20, pmY = rand() % 10;
    int clX = rand() % 20, clY = rand() % 10;
    int ikX = rand() % 20, ikY = rand() % 10;
    int pkX = rand() % 20, pkY = rand() % 10;
    int bkSpawn = rand() % 40;
    int bkPhase = (bkSpawn < 20) ? 0 : 1;
    int bkX = (bkSpawn < 20) ? bkSpawn : (bkSpawn - 20);
    int bkY = (bkPhase == 0) ? 2 : 7;

    int gmState = 0;

    while (gmState == 0) {
        for (int i = 0; i < 40; i++)
            cout << '\n';

        cout << "PAC-A-MAN!\n";
        cout << "Controls: W A S D + Enter" << endl << endl;

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 20; x++) {
                char ch = '*';
                ch = (x == pmX and y == pmY) ? '@' : ch;
                ch = (x == clX and y == clY) ? 'C' : ch;
                ch = (x == ikX and y == ikY) ? 'I' : ch;
                ch = (x == pkX and y == pkY) ? 'P' : ch;
                ch = (x == bkX and y == bkY) ? 'B' : ch;
                cout << ch << " ";
            }
            cout << endl;
        }

        char usrCmd;
        cout << "\nTurn: ";
        cin >> usrCmd;

        int prevX = pmX;
        int prevY = pmY;

        switch (usrCmd) {
            case 'W':
            case 'w':
                pmY--;
                break;
            case 'S':
            case 's': 
                pmY++; 
                break;
            case 'A':
            case 'a':
                pmX--;
                break;
            case 'D':
            case 'd':
                pmX++;
                break;
            default:
                break;
        }

        pmX = (pmX>0 ? (pmX > 19 ? 19 : pmX) : 0);
        pmY = (pmY>0? (pmY > 9 ? 9 : pmY) : 0);

        clX += pmX - prevX;
        clY += pmY - prevY;
        clX = (clX>0 ? (clX > 19 ? 19 : clX) : 0);
        clY = (clY>0 ? (clY > 9 ? 9 : clY): 0);
        gmState = (pmX == clX and pmY == clY) ? 1 : gmState;

        switch(gmState) {
            case 0:
            int distC = (clX - pmX) * (clX - pmX) + (clY - pmY) * (clY - pmY);
            int distI = (ikX - pmX) * (ikX - pmX) + (ikY - pmY) * (ikY - pmY);
            int distP = (pkX - pmX) * (pkX - pmX) + (pkY - pmY) * (pkY - pmY);
            int distB = (bkX - pmX) * (bkX - pmX) + (bkY - pmY) * (bkY - pmY);

            int inkyIsClosest = (distI <= distC and distI <= distP and distI <= distB) ? 1 : 0;

            int freeUp = (ikY > 0 and !(ikX == clX and ikY - 1 == clY) and !(ikX == pkX and ikY - 1 == pkY) and !(ikX == bkX and ikY - 1 == bkY)) ? 1 : 0;
            int freeRt = (ikX < 19 and !(ikX + 1 == clX and ikY == clY) and !(ikX + 1 == pkX and ikY == pkY) and !(ikX + 1 == bkX and ikY == bkY)) ? 1 : 0;
            int freeDn = (ikY < 9 and !(ikX == clX and ikY + 1 == clY) and !(ikX == pkX and ikY + 1 == pkY) and !(ikX == bkX and ikY + 1 == bkY)) ? 1 : 0;
            int freeLf = (ikX > 0 and !(ikX - 1 == clX and ikY == clY) and !(ikX - 1 == pkX and ikY == pkY) and !(ikX - 1 == bkX and ikY == bkY)) ? 1 : 0;

            int newIkX = inkyIsClosest ? (freeUp ? ikX : (freeRt ? ikX + 1 : (freeDn ? ikX : (freeLf ? ikX - 1 : ikX)))) : ikX;
            int newIkY = inkyIsClosest ? (freeUp ? ikY - 1 : (freeRt ? ikY : (freeDn ? ikY + 1 : (freeLf ? ikY : ikY)))) : ikY;

            ikX = newIkX;
            ikY = newIkY;

            gmState = (pmX == ikX and pmY == ikY) ? 2 : gmState;

            break;
        }

        switch(gmState) {
            case 0:
            int dx = pmX - pkX;
            int dy = pmY - pkY;
            int adx = (dx < 0) ? -dx : dx;
            int ady = (dy < 0) ? -dy : dy;
            int stepX = (dx > 0) ? 1 : (dx < 0 ? -1 : 0);
            int stepY = (dy > 0) ? 1 : (dy < 0 ? -1 : 0);

            int cmp = (adx > ady) ? 0 : (ady > adx ? 1 : 2);

            int newPkX = pkX + ((cmp == 0) ? stepX : (cmp == 2 ? stepX : 0));
            int newPkY = pkY + ((cmp == 1) ? stepY : (cmp == 2 ? stepY : 0));

            newPkX = (newPkX < 0) ? 0 : (newPkX > 19 ? 19 : newPkX);
            newPkY = (newPkY < 0) ? 0 : (newPkY > 9 ? 9 : newPkY);

            pkX = newPkX;
            pkY = newPkY;

            gmState = (pmX == pkX and pmY == pkY) ? 2 : gmState;
            
            break;
        }

        switch(gmState) {
            case 0:
            int step = (bkPhase == 0) ? 1 : -1;
            int nextX = bkX + step;

            int hitRight = (bkPhase == 0 and nextX > 19) ? 1 : 0;
            int hitLeft = (bkPhase == 1 and nextX < 0) ? 1 : 0;

            switch (hitRight * 2 + hitLeft) {
                case 2:
                    bkPhase = 1;
                    nextX = 19;
                    bkY = 7;
                    break;
                case 1:
                    bkPhase = 0;
                    nextX = 0;
                    bkY = 2;
                    break;
                default:
                    break;
            }

            bkX = nextX;

            gmState = (pmX == bkX and pmY == bkY) ? 2 : gmState;
            
            break;
        }
    }

    for (int i = 0; i < 40; i++) cout << '\n';

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 20; x++) {
            char ch = '*';
            ch = (x == clX and y == clY) ? 'C' : ch;
            ch = (x == ikX and y == ikY) ? 'I' : ch;
            ch = (x == pkX and y == pkY) ? 'P' : ch;
            ch = (x == bkX and y == bkY) ? 'B' : ch;
            ch = (x == pmX and y == pmY) ? '@' : ch;
            cout << ch << " ";
        }
        cout << endl;
    }

    switch (gmState) {
        case 1:
            cout << "\nSiren activated, you win!\n";
            break;
        case 2:
            cout << "\nGame over.\n";
            break;
    }

    }
        break;

    default:
        cout << "Invalid question number." << endl;
        break;
    }
    return 0;
}
