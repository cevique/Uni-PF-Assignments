#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib> //q1 q8
#include<ctime> //q8
#include<chrono> //q8
#include<thread> //q8
using namespace std;
int main() {
	int question_number;
	cout << "Enter the question number from the assignment : ";
	cin >> question_number;

	switch (question_number)
	{
	case 1:
	{
		cout << "You have inputed 1 for Question 1 (The Reckoning)" << endl;

		//inputs
		char type;
		int game, timeLeft, guardAlert, injuries, needles, bandages, marbles, ropeM, packKg, stamina, playersLeft, bet, stake, favor, cash, debt;            /* 1 = Red Light Green Light, 2 = Honeycomb, 3 = Tug of War, 4 = Marbles, 5 = Glass Bridge*/
		bool lightsOn, cameras, takeNeedles, takeBandages, takeMarbles, takeRope, card, ally;
		cout << "Type : " << endl; //1
		cin >> type;
		(type == 'A' || type == 'T' || type == 'G') ? 0 : (cout << "Error: Type must be A, T, or G" << endl, exit(0),0);
		cout << "Game : " << endl; //2
		cin >> game;
		(game >= 1 && game <= 5) ? 0 : (cout << "Error: Game must be between 1 and 5" << endl, exit(0), 0);
		cout << "Time Left : " << endl; //3
		cin >> timeLeft;
		(timeLeft >= 0 && timeLeft <= 120) ? 0 : (cout << "Error: Time Left must be 0 to 120" << endl, exit(0), 0);
		cout << "Guard Alert : " << endl; //4
		cin >> guardAlert;
		(guardAlert >= 0 && guardAlert <= 100) ? 0 : (cout << "Error: Guard Alert must be 0 to 100" << endl, exit(0), 0);
		cout << "Injuries : " << endl; //5
		cin >> injuries;
		(injuries >= 0 && injuries <= 3) ? 0 : (cout << "Error: Injuries must be 0 to 3" << endl, exit(0), 0);
		cout << "Lights On : " << endl; //6
		cin >> lightsOn;
		(lightsOn == 0 || lightsOn == 1) ? 0 : (cout << "Error: Lights On must be 0 or 1" << endl, exit(0), 0);
		cout << "Cameras : " << endl; //7
		cin >> cameras;
		(cameras == 0 || cameras == 1) ? 0 : (cout << "Error: Cameras must be 0 or 1" << endl, exit(0), 0);
		cout << "Take needles ? " << endl; //8
		cin >> takeNeedles;
		(takeNeedles == 0 || takeNeedles == 1) ? 0 : (cout << "Error: Take Needles must be 0 or 1" << endl, exit(0), 0);
		cout << "Needles : " << endl; //9
		cin >> needles;
		(needles >= 0 && needles <= 40) ? 0 : (cout << "Error: Needles must be 0 to 40" << endl, exit(0), 0);
		cout << "Take Bandages ?" << endl; //10
		cin >> takeBandages;
		(takeBandages == 0 || takeBandages == 1) ? 0 : (cout << "Error: Take Bandages must be 0 or 1" << endl, exit(0), 0);
		cout << "Bandages : " << endl; //11
		cin >> bandages;
		(bandages >= 0 && bandages <= 30) ? 0 : (cout << "Error: Bandages must be 0 to 30" << endl, exit(0), 0);
		cout << "Take Marbles ?" << endl; //12
		cin >> takeMarbles;
		(takeMarbles == 0 || takeMarbles == 1) ? 0 : (cout << "Error: Take Marbles must be 0 or 1" << endl, exit(0), 0);
		cout << "Marbles : " << endl; //13
		cin >> marbles;
		(marbles >= 0 && marbles <= 100) ? 0 : (cout << "Error: Marbles must be 0 to 100" << endl, exit(0), 0);
		cout << "Take Rope? " << endl; //14
		cin >> takeRope;
		(takeRope == 0 || takeRope == 1) ? 0 : (cout << "Error: Take Rope must be 0 or 1" << endl, exit(0), 0);
		cout << "Rope in Meters : " << endl; //15
		cin >> ropeM;
		(ropeM >= 0 && ropeM <= 60) ? 0 : (cout << "Error: Rope in Meters must be 0 to 60" << endl, exit(0), 0);
		cout << "Pack in Kilos : " << endl; //16
		cin >> packKg;
		(packKg >= 0 && packKg <= 150) ? 0 : (cout << "Error: Pack in Kilos must be 0 to 150" << endl, exit(0), 0);
		cout << "Stamina : " << endl; //17
		cin >> stamina;
		(stamina >= 0 && stamina <= 100) ? 0 : (cout << "Error: Stamina must be 0 to 100" << endl, exit(0), 0);
		cout << "Players Left : " << endl; //18
		cin >> playersLeft;
		(playersLeft >= 2 && playersLeft <= 456) ? 0 : (cout << "Error: Players Left must be 2 to 456" << endl, exit(0), 0);
		cout << "Bet ? " << endl; //19
		cin >> bet;
		(bet >= 0 && bet <= 2) ? 0 : (cout << "Error: Bet must be 0, 1, or 2" << endl, exit(0), 0);
		cout << "Stake : " << endl; //20
		cin >> stake;
		(stake >= 0 && stake <= 2000) ? 0 : (cout << "Error: Stake must be 0 to 2000" << endl, exit(0), 0);
		cout << "Favor ? (0=none , 1 = insider , 2 = hush , 3 = risky) : " << endl; //21
		cin >> favor;
		(favor >= 0 && favor <= 3) ? 0 : (cout << "Error: Favor must be 0, 1, 2, or 3" << endl, exit(0), 0);
		cout << "Cash : " << endl; //22
		cin >> cash;
		(cash >= 0 && cash <= 6000) ? 0 : (cout << "Error: Cash must be 0 to 6000" << endl, exit(0), 0);
		cout << "Debt : " << endl; //23
		cin >> debt;
		(debt >= 0 && debt <= 3000) ? 0 : (cout << "Error: Debt must be 0 to 3000" << endl, exit(0), 0);
		cout << "Card ? " << endl; //24
		cin >> card;
		(card == 0 || card == 1) ? 0 : (cout << "Error: Card must be 0 or 1" << endl, exit(0), 0);
		cout << "Ally ? " << endl; //25
		cin >> ally;
		(ally == 0 || ally == 1) ? 0 : (cout << "Error: Ally must be 0 or 1" << endl, exit(0), 0);



		//Needle = 150 , Bandages = 350 , Marble = 60 , Rope = 120*
		//*Replaces unit prices above : Athelete : rope changes to 100 , Thinker : Needle costs 120 , Gambler = Marble costs 45  
		int needlecost, bandagecost, marblecost, ropecost;
		needlecost = 150, bandagecost = 350, marblecost = 60, ropecost = 120;
		ropecost = (type == 'A') ? 100 : 150;
		needlecost = (type == 'T') ? 120 : 150;
		marblecost = (type == 'G') ? 45 : 60;


		//pre-surcharge

		//needles
		int FullNeedleQty, DiscountNeedleQty, RawNeedleCost, DiscountNeedleUnit;
		FullNeedleQty = (needles > 10) ? 10 : needles;
		DiscountNeedleQty = (needles > 10) ? needles - 10 : 0;
		DiscountNeedleUnit = (needlecost * 75) / 100;
		RawNeedleCost = ((FullNeedleQty * needlecost) + (DiscountNeedleQty * DiscountNeedleUnit)) * takeNeedles;
		cout << "NeedleCost= " << RawNeedleCost << endl;
		//bandages
		int bandageworking, RawBandageCost;
		bandageworking = bandages - (bandages / 3);
		RawBandageCost = (bandageworking * bandagecost) * takeBandages;
		cout << "BandageCost= " << RawBandageCost << endl;
		//Marbles
		int FullMarbleQty, DiscountMarbleQty, RawMarblecost, DiscountMarbleUnit;
		FullMarbleQty = (marbles > 50) ? 50 : marbles;
		DiscountMarbleQty = (marbles > 50) ? marbles - 50 : 0;
		DiscountMarbleUnit = (marblecost * 50) / 100;
		RawMarblecost = ((FullMarbleQty * marblecost) + (DiscountMarbleQty * DiscountMarbleUnit)) * takeMarbles;
		cout << "MarbleCost= " << RawMarblecost << endl;
		//Rope
		int RawRopeCost, FinalRopeCost;
		RawRopeCost = ropeM * ropecost;
		FinalRopeCost = RawRopeCost * takeRope;
		cout << "RopeCost= " << FinalRopeCost << endl;



		//Alert Adjustment
		int alertAdj;
		alertAdj = guardAlert;
		alertAdj = (takeMarbles == 1) ? alertAdj + (marbles / 5) : alertAdj;
		alertAdj = (takeRope == 1) ? alertAdj + (ropeM / 3) : alertAdj;
		alertAdj = (lightsOn == 1) ? alertAdj + 10 : alertAdj;
		alertAdj = (cameras == 1) ? alertAdj + 5 : alertAdj;
		alertAdj = (alertAdj >= 100) ? 100 : alertAdj;

		//Danger Points
		int DangerPoints;
		DangerPoints = (playersLeft > 300) ? 3 : (playersLeft > 150) ? 2 : (playersLeft > 50) ? 1 : 0;
		DangerPoints = (alertAdj >= 70) ? DangerPoints + 2 : (alertAdj >= 40) ? DangerPoints + 1 : DangerPoints;
		DangerPoints = (game >= 4) ? DangerPoints + 2 : (game >= 2) ? DangerPoints + 1 : DangerPoints;
		DangerPoints = (cameras == 1) ? DangerPoints + 1 : DangerPoints;
		DangerPoints = (lightsOn == 0) ? DangerPoints - 1 : DangerPoints;
		DangerPoints = (DangerPoints <= 0) ? 0 : DangerPoints; //clamp
		cout << "DangerPoints= " << DangerPoints << endl;

		//Surcharge
		int surchargePct = (DangerPoints >= 7) ? 50 : (DangerPoints >= 5) ? 25 : (DangerPoints >= 3) ? 10 : 0;  //This is where I learned you can initialize variables as you begin working on them
		int NeedlesS = (RawNeedleCost * (100 + surchargePct)) / 100;
		int BandagesS = (RawBandageCost * (100 + surchargePct)) / 100;
		int MarbleS = (RawMarblecost * (100 + surchargePct)) / 100;
		int RopeS = (FinalRopeCost * (100 + surchargePct)) / 100;
		int itemsAfterSurcharge = NeedlesS + BandagesS + MarbleS + RopeS;
		cout << "SurchargePct%= " << surchargePct << "%" << endl;

		//Fees
		int lateFee = (timeLeft < 15) ? 250 : (timeLeft < 45) ? 100 : 0;
		int guardToll = 50 + (alertAdj / 10) * 5;
		guardToll = (card == 1 && cameras == 0) ? 0 : guardToll;
		int carryCap = (type == 'A') ? 40 : (type == 'T') ? 30 : 35;
		carryCap = (ally == 1) ? carryCap + 10 : carryCap;
		int extraKg = packKg - carryCap;
		int maxKg = (extraKg > 0) ? extraKg : 0;
		int penalty = 25 * maxKg;
		int weightPenalty = (penalty < 500) ? penalty : 500;
		int wager = (bet != 0) ? stake : 0;
		cout << "LateFee= " << lateFee << endl;
		cout << "GuardToll= " << guardToll << endl;
		cout << "WeightPenalty= " << weightPenalty << endl;
		cout << "Wager= " << wager << endl;

		//Rebates and Injury Tax
		int allyRebate = (ally == 1) ? 60 : 0;
		int calmRebate = (injuries == 0 && stamina >= 70) ? 40 : 0;
		int injuryTax = (injuries == 3) ? 200 : (injuries == 2) ? 90 : (injuries == 1) ? 30 : 0;

		//Favors 
		int insiderCalc = ((NeedlesS + MarbleS) * 15) / 100;
		int insiderDiscount = (game == 2 || game == 4) ? ((insiderCalc < 500) ? insiderCalc : 500) : 0;
		int hushCalc = ((lateFee + guardToll) * 50) / 100;
		int hushDiscount = (alertAdj >= 60) ? ((hushCalc < 250) ? hushCalc : 250) : 0;
		int medpassCalc = (BandagesS * 35) / 100;
		int medpassDiscount = (injuries >= 1) ? ((medpassCalc < 900) ? medpassCalc : 900) : 0;
		int FavorDiscount = (favor == 1) ? insiderDiscount : (favor == 2) ? hushDiscount : (favor == 3) ? medpassDiscount : 0;
		cout << "FavorDiscount= " << FavorDiscount << endl;

		//Settlement
		int gross = itemsAfterSurcharge + lateFee + guardToll + weightPenalty + wager;
		int netCalc = gross + injuryTax - allyRebate - calmRebate - FavorDiscount;
		int net = (netCalc > 0) ? netCalc : 0;
		int debtFeeCalc = 80 + (debt / 20);
		int DebtFee = (net > cash) ? debtFeeCalc : 0;
		int totalCalc = net + DebtFee;
		int Total = (totalCalc < 200) ? 200 : totalCalc;
		int Fees = lateFee + guardToll + weightPenalty + injuryTax + DebtFee;
		int CashUsed = (cash < Total) ? cash : Total;
		int Payable = Total - CashUsed;
		cout << "Fees= " << Fees << endl;
		cout << "Total= " << Total << endl;
		cout << "CashUsed= " << CashUsed << endl;
		cout << "Payable" << Payable << endl;

		//S.C & O
		int ropeBonusCalc = ropeM / 2;
		int ropeBonus = (takeRope == 1) ? ((ropeBonusCalc < 15) ? ropeBonusCalc : 15) : 0;
		int bandageBonusCalc = 2 * bandages;
		int bandageBonus = (takeBandages == 1) ? ((bandageBonusCalc < 12) ? bandageBonusCalc : 12) : 0;
		int staminaBonus = stamina / 4;
		int cardBonus = (card == 1) ? 8 : -25;
		int allyBonus = (ally == 1) ? 5 : 0;
		int weightDiff = packKg - carryCap;
		int weightOver = (weightDiff > 0) ? weightDiff : 0;
		int weightPenaltySurv = weightOver / 2;
		int surchargePenalty = 5 * (surchargePct / 10);
		int injuryPenalty = 8 * injuries;
		int gamePenalty = 4 * (game - 1);
		int debtPenalty = (DebtFee > 0) ? 12 : 0;
		int gameMatchBonus = (game == 2 && takeNeedles == 1 && needles >= 5) ? 10 : (game == 4 && takeMarbles == 1 && marbles >= 20) ? 10 : (game == 5 && takeRope == 1 && ropeM >= 10) ? 10 : 0;
		int SurvivalChance = 40 + ropeBonus + bandageBonus + staminaBonus + cardBonus + allyBonus - weightPenaltySurv - surchargePenalty - injuryPenalty - gamePenalty - debtPenalty + gameMatchBonus;
		SurvivalChance = (SurvivalChance < 0) ? 0 : SurvivalChance;
		SurvivalChance = (SurvivalChance > 100) ? 100 : SurvivalChance;
		cout << "SurvivalChance=" << SurvivalChance << endl;
		(SurvivalChance >= 55) ? (cout << "Outcome=" << "Survived" << endl) : (cout << "Outcome=" << "Eliminated" << endl);

		// Prize and Final Balance
		int prizePool = (456 - playersLeft) * 100;
		int PrizeShare = (SurvivalChance >= 55) ? (prizePool / playersLeft) : 0;
		int bet1Payout = (stake * 3) / 2;
		int bet2Payout = (SurvivalChance >= 75) ? (stake * 4) : 0;
		int rawBetPayout = (bet == 1) ? bet1Payout : (bet == 2) ? bet2Payout : 0;
		int BetPayout = (SurvivalChance >= 55) ? rawBetPayout : 0;
		int FinalBalance = cash - Total + PrizeShare + BetPayout;
		cout << "PrizeShare=" << PrizeShare << endl;
		cout << "BetPayout=" << BetPayout << endl;
		cout << "FinalBalance=" << FinalBalance << endl;

	}
		break;
	
	case 2:
	{
		//part A
		const double Wnot = 0.8, Beta = 0.12, Unot = 15.0, friction_const = 3.4, Dnot = 0.5;
		double WPV, Windspeed, angleinrad, vegetationfueldrynessindex;
		long long rollno;
		cout << "Input the following variables in order :\nU: Wind speed (in km/h).\nTheta : Terrain slope angle (in radians).\nD: Vegetation fuel dryness index.\nRoll No (last 4 digits)." << endl;
		cin >> Windspeed >> angleinrad >> vegetationfueldrynessindex >> rollno;
		WPV = Wnot * exp(Beta * Windspeed)+ Unot * pow(sin(angleinrad), 2.0)+ friction_const * log((vegetationfueldrynessindex + 1.0) / Dnot) + sqrt(Windspeed * cos(angleinrad) + 1.0);
		cout << "1. Delta V: " << fixed << setprecision(4) << WPV << endl;
		//part B
		long long Vint = static_cast<long long>(WPV);
		long long F1 = static_cast<long long>(WPV * 100) % 100;
		long long F2 = static_cast<long long>(WPV * 10000) % 100;
		long long rolloffset = (rollno % 89) + 10;
		long long K= (Vint * 1000000) + (F1 * 10000) + (F2 * 100) + rolloffset;
		cout << "2. Telemetry Key K: " << K << endl;
		//part C
		long long pR = K % 100; 
		long long pF2 = (K / 100) % 100;
		long long pF1 = (K / 10000) % 100;
		long long pVint = K / 1000000;
		char C1 = 'A' + (pVint % 26);
		char C2 = 'Z' - (pR % 26);
		float v_float = static_cast<float>(pVint)+ (static_cast<float>(pF1) / 100.0f)+ (static_cast<float>(pF2) / 10000.0f);
		double v_double = static_cast<double>(pVint)+ (static_cast<double>(pF1) / 100.0)+ (static_cast<double>(pF2) / 10000.0);
		bool is_exact = (v_float == v_double);
		int penalty = (!is_exact) * 25;
		int TR = static_cast<int>(pR) + penalty + static_cast<int>(1.5 * v_double);
		cout << "3. Status Tag: " << C1 << C2 << endl;
		cout << "4. Precision Match Flag: " << boolalpha << is_exact << endl;
		cout << "5. Threat Rating: " << TR << endl;

	}
		break;
	
	    case 3:{
            //md vars
            int murVisitedBoilerRoom = 1;
            int murVisitedCargoHold = 0;
            int murVisitedThirdClass = 0;
            int murVisitedDiningSaloon = 0;
            int murVisitedPromenadeDeck = 0;
            int murVisitedBridge = 0;
            int murVisitedLifeboatDeck = 0;
            int murVisitedCrowsNest = 0;
            int murCurrent = 0;
            int murFrozen = 0;
            //mary vars
            int maryVisitedBoilerRoom = 1;
            int maryVisitedCargoHold = 0;
            int maryVisitedThirdClass = 0;
            int maryVisitedDiningSaloon = 0;
            int maryVisitedPromenadeDeck = 0;
            int maryVisitedBridge = 0;
            int maryVisitedLifeboatDeck = 0;
            int maryVisitedCrowsNest = 0;
            int maryCurrent = 0;
            int maryFrozen = 0;

            //mds1
            switch (murFrozen)
            {
            case 0:
                switch (murCurrent)
                {
                case 0:
                    // Cn 1 2
                    switch (murVisitedCargoHold)
                    {
                    case 0:
                        murCurrent = 1;
                        break;

                    case 1:
                        switch (murVisitedThirdClass)
                        {
                        case 0:
                            murCurrent = 2;
                            break;
                        }
                        break;
                    }
                    break;
                }

                switch (murCurrent)
                {
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
            //mds2
            switch (murFrozen)
            {
            case 0:
                switch (murCurrent)
                {
                case 1:
                    // cn 0 3 4
                    switch (murVisitedDiningSaloon)
                    {
                    case 0:
                        murCurrent = 3;
                        break;

                    case 1:
                        switch (murVisitedPromenadeDeck)
                        {
                        case 0:
                            murCurrent = 4;
                            break;
                        }
                        break;
                    }
                    break;
                }

                switch (murCurrent)
                {
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
            //mds3
            switch (murFrozen)
            {
            case 0:
                switch (murCurrent)
                {
                case 3:
                    // cn 1 7
                    switch (murVisitedCrowsNest)
                    {
                    case 0:
                        murCurrent = 7;
                        break;

                    case 1:
                        break;
                    }
                    break;
                }

                switch (murCurrent)
                {
                case 7:
                    murVisitedCrowsNest = 1;

                    switch (murVisitedDiningSaloon)
                    {
                    case 1:
                        cout << "DoorSealed" << endl;
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
            //mds4
            switch (murFrozen)
            {
            case 0:
                switch (murCurrent)
                {
                case 7:
                    // 7 to 3 or 4
                    // 5 -> 7 is one-way (7 cannot return to 5.) regarding the diagrom drawn

                    switch (murVisitedDiningSaloon)
                    {
                    case 0:
                        murCurrent = 3;
                        break;

                    case 1:
                        switch (murVisitedPromenadeDeck)
                        {
                        case 0:
                            murCurrent = 4;
                            break;

                        case 1:
                            break;
                        }
                        break;
                    }
                    break;
                }

                switch (murCurrent)
                {
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
            //mds5
            switch (murFrozen)
            {
            case 0:
                switch (murCurrent)
                {
                case 3:
                    switch (murVisitedCargoHold)
                    {
                    case 1:
                        switch (murVisitedCrowsNest)
                        {
                        case 1:
                            switch (murVisitedThirdClass)
                            {
                            case 0:
                                cout << "TurnBack" << endl;
                                murCurrent = 1;
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

                switch (murCurrent)
                {
                case 1:
                    murVisitedCargoHold = 1;
                    break;
                }
                break;

            case 1:
                break;
            }
            //mds6
            switch (murFrozen)
            {
            case 0:
                switch (murCurrent)
                {
                case 1:
                    // 1 -> 2 (smallest unvisited)
                    switch (murVisitedThirdClass)
                    {
                    case 0:
                        murCurrent = 2;
                        break;

                    case 1:
                        switch (murVisitedDiningSaloon)
                        {
                        case 0:
                            murCurrent = 3;
                            break;

                        case 1:
                            switch (murVisitedPromenadeDeck)
                            {
                            case 0:
                                murCurrent = 4;
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                }

                switch (murCurrent)
                {
                case 2:
                    murVisitedThirdClass = 1;
                    break;
                }
                break;

            case 1:
                break;
            }
            //ms1
            switch (maryFrozen)
            {
            case 0:
                switch (maryCurrent)
                {
                case 0:
                    // finish decks one cord from 0
                    switch (maryVisitedCargoHold)
                    {
                    case 0:
                        maryCurrent = 1;
                        break;

                    case 1:
                        switch (maryVisitedThirdClass)
                        {
                        case 0:
                            maryCurrent = 2;
                            break;
                        }
                        break;
                    }
                    break;
                }

                switch (maryCurrent)
                {
                case 1:
                    maryVisitedCargoHold = 1;
                    break;

                case 2:
                    maryVisitedThirdClass = 1;
                    break;
                }
                break;

            case 1:
                break;
            }

            //ms2
            switch (maryFrozen)
            {
            case 0:
                switch (maryCurrent)
                {
                case 1:
                    switch (maryVisitedThirdClass)
                    {
                    case 0:
                        maryCurrent = 0;
                        break;

                    case 1:
                        switch (maryVisitedDiningSaloon)
                        {
                        case 0:
                            maryCurrent = 3;
                            break;

                        case 1:
                            switch (maryVisitedPromenadeDeck)
                            {
                            case 0:
                                maryCurrent = 4;
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                }

                switch (maryCurrent)
                {
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
            //ms3
            switch (maryFrozen)
            {
            case 0:
                switch (maryCurrent)
                {
                case 0:
                    switch (maryVisitedCargoHold)
                    {
                    case 1:
                        switch (maryVisitedThirdClass)
                        {
                        case 0:
                            maryCurrent = 2;
                            break;
                        }
                        break;
                    }
                    break;
                }

                switch (maryCurrent)
                {
                case 2:
                    maryVisitedThirdClass = 1;
                    break;
                }
                break;

            case 1:
                break;
            }
            //ms4
            switch (maryFrozen)
            {
            case 0:
                switch (maryCurrent)
                {
                case 2:
                    switch (maryVisitedBridge)
                    {
                    case 0:
                        cout << "Waterskiing" << endl;
                        maryCurrent = 5;
                        maryVisitedBridge = 1;
                        break;

                    case 1:
                        // cm 0 5 6
                        switch (maryVisitedBridge)
                        {
                        case 1:
                            switch (maryVisitedBridge)
                            {
                            case 1:
                                maryCurrent = 5;
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                }

                switch (maryCurrent)
                {
                case 5:
                    maryVisitedBridge = 1;
                    break;
                }
                break;

            case 1:
                break;
            }

            //ms5
            switch (maryFrozen)
            {
            case 0:
                switch (maryCurrent)
                {
                case 5:
                    // cn 2 6 7
                    switch (maryVisitedLifeboatDeck)
                    {
                    case 0:
                        maryCurrent = 6;
                        break;

                    case 1:
                        switch (maryVisitedCrowsNest)
                        {
                        case 0:
                            maryCurrent = 7;
                            break;
                        }
                        break;
                    }
                    break;
                }

                switch (maryCurrent)
                {
                case 6:
                    maryVisitedLifeboatDeck = 1;
                    break;

                case 7:
                    maryVisitedCrowsNest = 1;
                    break;
                }

                switch (maryCurrent)
                {
                case 6:
                    cout << "Rescued" << endl;
                    maryFrozen = 1;
                    break;
                }
                break;

            case 1:
                break;
            }


  //ms6
            switch (maryFrozen)
            {
            case 0:
                switch (maryCurrent)
                {
                case 6:
                    cout << "Rescued" << endl;
                    maryFrozen = 1;
                    break;
                }
                break;

            case 1:
                // frozen
                break;
            }
            cout << endl;
            cout << "Murdoch path: "<< "Boiler Room -> Cargo Hold -> Dining Saloon -> "<< "Crow's Nest -> Dining Saloon -> Cargo Hold -> Third Class"<< endl;
            cout << "Mary path: "  << "Boiler Room -> Cargo Hold -> Boiler Room -> Third Class -> "<< "Bridge -> Lifeboat Deck -> Lifeboat Deck" << endl;

        }


	case 4:
	{
		int size;
		cout << "Enter size: ";
        cin >> size;
		if (size > 0) {
			for (int r = 0; r < size; ++r) { //rows
				for (int c = 0; c < size; ++c) { //columns 
					//distance from border edges
					int y = min(r, size - 1 - r);
					int x = min(c, size - 1 - c);
					// ring has max distance
					int Depth = max(x, y);

					if (Depth % 2 == 0 || x == 0 || y == 0) { //if ==0 (edge cases) odd cases ignore , even cases add *
						cout << "* ";
					}
					else {
						cout << "  ";
					}
				}
				cout << "\n";
			}
		}
		else {
			cout << "Please enter a valid positive integer.\n";
		}

	}
		break;
	
    case 5: {
       
        char choice;
        cout << "Enter choice for Question 6 (A/B): ";cin >> choice;
        switch (choice) {
        case 'A':
        {
            int W, H, dw, dh, atticH, chimneys, walkH;
            bool ok;

           //inputs
            while (true) {
                cout << "Width of house: ";
                while (!(cin >> W) || W < 0) {
                    cout << "Invalid input. Enter a non-negative whole number: ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                cout << "Height of house: ";
                while (!(cin >> H) || H < 0) {
                    cout << "Invalid input. Enter a non-negative whole number: ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                cout << "Width of door: ";
                while (!(cin >> dw) || dw < 0) {
                    cout << "Invalid input. Enter a non-negative whole number: ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                cout << "Height of door: ";
                while (!(cin >> dh) || dh < 0) {
                    cout << "Invalid input. Enter a non-negative whole number: ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                cout << "Height of attic (base to roof): ";
                while (!(cin >> atticH) || atticH < 0) {
                    cout << "Invalid input. Enter a non-negative whole number: ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                cout << "Number of chimneys: ";
                while (!(cin >> chimneys) || chimneys < 0) {
                    cout << "Invalid input. Enter a non-negative whole number: ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
                cout << "Height of walkway: ";
                while (!(cin >> walkH) || walkH < 0) {
                    cout << "Invalid input. Enter a non-negative whole number: ";
                    cin.clear(); cin.ignore(10000, '\n');
                }

                ok = true;
                if (atticH < 1) {
                    cout << "Error: attic height must be at least 1.\n"; ok = false;
                }
                else if (walkH < 1) {
                    cout << "Error: walkway height must be at least 1.\n"; ok = false;
                }
                else if (W % 2 != 0 || dw % 2 != 0) {
                    cout << "Error: house width and door width must both be even.\n"; ok = false;
                }
                else if (dw < 4) {
                    cout << "Error: door width must be at least 4.\n"; ok = false;
                }
                else if (dh < 3) {
                    cout << "Error: door height must be at least 3.\n"; ok = false;
                }
                else if (W < dw + 20) {
                    cout << "Error: house too narrow (width must be at least door width + 20).\n"; ok = false;
                }
                else if (W < 2 * atticH + 2) {
                    cout << "Error: attic is too wide for the house width.\n"; ok = false;
                }
                else if (H < atticH + walkH + (dh + 1 > 6 ? dh + 1 : 6)) {
                    cout << "Error: house height too small for attic, door and walkway.\n"; ok = false;
                }
                else if (walkH > (W - dw) / 2) {
                    cout << "Error: walkway too tall for this house width.\n"; ok = false;
                }
                else if (chimneys > 0 && atticH < 3) {
                    cout << "Error: attic must be at least 3 tall to hold chimneys.\n"; ok = false;
                }
                else if (chimneys > 0 && chimneys > 2 * ((W / 2 - atticH - 1) / 6)) {
                    cout << "Error: too many chimneys for this house width.\n"; ok = false;
                }

                if (ok) break;
                cout << "Please re-enter all inputs.\n\n";
            }
            int c = W / 2;                        // centre column
            int dl = (W - dw) / 2;                // door left column
            int doorBottom = H - walkH - 1;
            int doorTop = doorBottom - dh + 1;
            int L = c - atticH - 1;               // width of each wing beside the attic
            int leftM = (chimneys + 1) / 2;       // chimneys on the left side of the house
            int rightM = chimneys / 2;            // chimneys on the right side of the house
            cout << "\n";
            for (int r = 0; r < H; r++) {
                for (int col = 0; col < W; col++) {
                    char ch = ' ';
                    if (r >= H - walkH) {
                        // Walkway: widens going down
                        int i = r - (H - walkH);
                        if (col == dl - 1 - i) ch = '/';
                        else if (col == dl + dw + i) ch = '\\';
                        else if (i == walkH - 1 && col >= dl - i && col < dl + dw + i) ch = '_';

                    }
                    else if (r < atticH) {
                        // Attic triangle
                        if (col == c - 1 - r) ch = '/';
                        else if (col == c + r) ch = '\\';
                        else if (atticH >= 4 && r == atticH - 2 && col == c - 1) ch = '[';
                        else if (atticH >= 4 && r == atticH - 2 && col == c) ch = ']';
                        else if (chimneys > 0 && r >= atticH - 3) {
                            // Chimneys: find offset j (0-4) inside a chimney, else -1
                            int j = -1;
                            for (int side = 0; side < 2; side++) {
                                int segStart = (side == 0) ? 1 : c + atticH;
                                int m = (side == 0) ? leftM : rightM;
                                if (m > 0 && col >= segStart && col < segStart + L) {
                                    int slot = L / m;
                                    int k = (col - segStart) / slot;
                                    if (k < m) {
                                        int off = col - (segStart + k * slot + (slot - 5) / 2);
                                        if (off >= 0 && off <= 4) j = off;
                                    }
                                }
                            }
                            if (j >= 0) {
                                int k = r - (atticH - 3);
                                if (k == 0) { if (j == 1 || j == 3) ch = ')'; }
                                else if (k == 1) ch = '=';
                                else {
                                    if (j == 1 || j == 3) ch = '|';
                                    else if (j == 2) ch = '_';
                                }
                            }
                        }
                    }
                    else if (r == atticH) {
                        // Roof line of the main body
                        if (col >= 1 && col <= W - 2) ch = '_';
                    }
                    else if (col == 0 || col == W - 1) {
                        // Outer walls
                        ch = '|';
                    }
                    else if (col >= dl && col <= dl + dw - 1) {
                        // Door
                        if (r == doorTop) {
                            if (col > dl && col < dl + dw - 1) ch = '_';
                        }
                        else if (r > doorTop) {
                            if (col == dl || col == dl + dw - 1) ch = '|';
                            else if (r == doorTop + dh / 2 && col == dl + dw - 2) ch = 'o';
                            else if (r == doorBottom) ch = '_';
                        }
                    }
                    else {
                        // whatever the amount of windows that can fit in the valud inputs
                        if (r >= doorBottom - 4 && r <= doorBottom - 1) {
                            int rs = (col < dl) ? 1 : dl + dw;     // region start
                            int rw = dl - 1;                        // region width
                            int n = rw / 9;                         // windows in region
                            int rel = col - rs - (rw - n * 9) / 2;
                            if (rel >= 0 && rel / 9 < n) {
                                int j = rel % 9 - 1;                // offset 0-6 inside window
                                int k = r - (doorBottom - 4);       // row 0-3 inside window
                                if (j >= 0 && j <= 6) {
                                    if (k == 0) { if (j >= 1 && j <= 5) ch = '_'; }
                                    else if (k == 1) { if (j == 0 || j == 3 || j == 6) ch = '|'; }
                                    else if (k == 2) {
                                        if (j == 0 || j == 6) ch = '|';
                                        else if (j == 3) ch = '+';
                                        else ch = '-';
                                    }
                                    else {
                                        if (j == 0 || j == 3 || j == 6) ch = '|';
                                        else ch = '_';
                                    }
                                }
                            }
                        }
                        // last line?
                        if (r == doorBottom && ch == ' ') ch = '_';
                    }
                    cout << ch;
                }
                cout << "\n";
            }
            //couple issues , review the [] to a [_] ? maybe. Try to add the ::::: inside the home and everything else.
            break;
        }
        case 'B': {
            int input;
            cout << "Enter a 4 digit input : ";
            cin >> input;

            int d1 = input / 1000;
            int d2 = (input / 100) % 10;
            int d3 = (input / 10) % 10;
            int d4 = input % 10;

        
            for (int row = 1; row <= 6; ++row) {
                int currentDigit = 0;

             
                for (int pos = 1; pos <= 4; ++pos) {
                    if (pos == 1) currentDigit = d1;
                    else if (pos == 2) currentDigit = d2;
                    else if (pos == 3) currentDigit = d3;
                    else if (pos == 4) currentDigit = d4;

                    // r1
                    if (row == 1) {
                        if (currentDigit == 1)      cout << "   o O                          ";
                        else if (currentDigit == 2) cout << "                     ";
                        else if (currentDigit == 3) cout << "                      ";
                        else if (currentDigit == 4) cout << "                          ";
                    }
                    // r2
                    else if (row == 2) {
                        if (currentDigit == 1)      cout << "  ___[ ]___  _________________  ";
                        else if (currentDigit == 2) cout << "  _________________  ";
                        else if (currentDigit == 3) cout << "|==================|  ";
                        else if (currentDigit == 4) cout << "       __[___]__          ";
                    }
                    // r3
                    else if (row == 3) {
                        if (currentDigit == 1)      cout << " |_________|_| [ ]       [ ] |  ";
                        else if (currentDigit == 2) cout << " | []  []  []  []  | ";
                        else if (currentDigit == 3) cout << "|    |   []   |    |  ";
                        else if (currentDigit == 4) cout << " '-===================-'  ";
                    }
                    // r4
                    else if (row == 4) {
                        if (currentDigit == 1)      cout << " |___( )___|_|_______________|  ";
                        else if (currentDigit == 2) cout << " | []  []  []  []  | ";
                        else if (currentDigit == 3) cout << "|    |   ||   |    |  ";
                        else if (currentDigit == 4) cout << "(    ~~~~~~~~~~~~~~~    ) ";
                    }
                    // r5
                    else if (row == 5) {
                        if (currentDigit == 1)      cout << "<============================]--";
                        else if (currentDigit == 2) cout << "-|_________________|-";
                        else if (currentDigit == 3) cout << "|____|___||___|____|--";
                        else if (currentDigit == 4) cout << " -======================-,";
                    }
                    // r6
                    else if (row == 6) {
                        if (currentDigit == 1)      cout << " (O)     (O)  (O)         (O)   ";
                        else if (currentDigit == 2) cout << "   (O)         (O)   ";
                        else if (currentDigit == 3) cout << "    (O)      (O)      ";
                        else if (currentDigit == 4) cout << "    (O)             (0)   ";
                    }
                }
                cout << "\n";
            }

            /* cart 1
            cout << "   o O\n"
              << "  ___[ ]___  _________________\n"
              << " |_________|_| [ ]       [ ] |\n"
              << " |___( )___|_|_______________|\n"
              << "<============================]--\n"
              << " (O)     (O)  (O)         (O)"
            cart 2
          cout<<" _________________\n"
              <<"| []  []  []  []  |\n"
              <<"| []  []  []  []  |\n"
             <<"-|_________________|-\n"
              <<"  (O)         (O)"           
            cart 3
            cout<<"|==================|\n"
                <<"|    |   []   |    |\n"
                <<"|    |   ||   |    |\n"
                <<"|____|___||___|____|--\n"
                <<"    (O)      (O)\n"
             cart 4
            cout<<"       __[___]__\n"
                <<" \'-===================-\'\n"
                <<"(    ~~~~~~~~~~~~~~~    )\n"
                <<" -======================-,\n"
                <<"    (O)             (O)
            */


            break;
        }
          
        default: cout << "Please choice A or B next time." << endl; break;

        }
    case 6:
    {
        cout << "GG, I give up." << endl;
    }
        break;
    case 7:
    {
        long long value1 = 0, value2 = 0;
        long long addoutput = 0, suboutputA_B = 0, suboutputB_A = 0;
        long long multoutput = 0, quotoutput = 0, remoutput = 0;
        char sign_choice;
        bool is_signed;

        // Input Validation for A
        bool valid = false;
        while (!valid) {
            cout << "Input A : ";
            cin >> value1;
            if (value1 < 0) { //chekc if >0
                cout << "Input must be greater than or equal to 0.\n";
                continue;
            }
            long long temp = value1;
            int len = 0;
            bool only_binary = true;
            if (temp == 0) len = 1;
            while (temp > 0) { 
                int digit = temp % 10; //check if 0 or 1
                if (digit != 0 && digit != 1) only_binary = false;
                len++;
                temp /= 10;
            }
            if (!only_binary || len > 6) { //doesnt exit until valid input is less than 7 digits
                 cout << "Invalid input. Must consist of only 1s and 0s and be max 6 digits long.\n";
                continue;
            }
            valid = true;
        }

        // Input Validation for B cpy pst from A
        valid = false;
        while (!valid) {
            cout << "Input B : ";
            cin >> value2;
            if (value2 < 0) {
                cout << "Input must be greater than or equal to 0.\n";
                continue;
            }
            long long temp = value2;
            int len = 0;
            bool only_binary = true;
            if (temp == 0) len = 1;
            while (temp > 0) {
                int digit = temp % 10;
                if (digit != 0 && digit != 1) only_binary = false;
                len++;
                temp /= 10;
            }
            if (!only_binary || len > 6) {
                cout << "Invalid input. Must consist of only 1s and 0s and be max 6 digits long.\n";
                continue;
            }
            valid = true;
        }

        cout << "Are these numbers signed or unsigned? Y/N : ";
        cin >> sign_choice;
        is_signed = (sign_choice == 'Y' || sign_choice == 'y');
        cout << "... Calculating ...\n";
        long long p10_5 = 100000;
        long long bin_val;
        int bits_len;
        bool check_sign;
        long long dec_val;
        long long cur_p10;
        long long cur_p2;

        // Display A dec
        bin_val = value1; bits_len = 6; check_sign = is_signed; dec_val = 0; cur_p10 = 1; cur_p2 = 1; //current power of 10 is var name btw
        for (int i = 0; i < bits_len - 1; i++) { //first 5 digit iteration
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2; 
            cur_p10 *= 10; cur_p2 *= 2; 
        }
        if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2; //check is_signed bool ? yes then -32PW
        else dec_val += ((bin_val / cur_p10) % 10) * cur_p2; //* by BPW (1,2,4,8,16)
        cout << "A : " << dec_val << "\n";

        // Display B dec same logic as above code brick
        bin_val = value2; bits_len = 6; check_sign = is_signed; dec_val = 0; cur_p10 = 1; cur_p2 = 1;
        for (int i = 0; i < bits_len - 1; i++) {
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cur_p10 *= 10; cur_p2 *= 2;
        }
        if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2;
        else dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cout << "B : " << dec_val << "\n";


        // addition place (carry adder circuit)
        long long addoutput7 = 0;
        int carry = 0;
        int sign_ext_A = is_signed ? ((value1 / p10_5) % 10) : 0;
        int sign_ext_B = is_signed ? ((value2 / p10_5) % 10) : 0;
        long long p10_i = 1;   

        for (int i = 0; i < 7; i++) { //run loop 7 times pull i-th bit of A
            int bitA = (i < 6) ? ((value1 / p10_i) % 10) : sign_ext_A; //check if 6th bit is 0 or 1 & works accordingly
            int bitB = (i < 6) ? ((value2 / p10_i) % 10) : sign_ext_B;
            int sum = bitA + bitB + carry;  
            if (i < 6) addoutput += (sum % 2) * p10_i; 
            addoutput7 += (sum % 2) * p10_i; 
            carry = sum / 2;
            p10_i *= 10;
        }

        bool ovf_add = false;
        if (is_signed) {
            int bitA5 = (value1 / p10_5) % 10;
            int bitB5 = (value2 / p10_5) % 10;
            int sum5 = (addoutput / p10_5) % 10;
            if (bitA5 == bitB5 && sum5 != bitA5) ovf_add = true;
        }
        else {
            if (carry == 1 || ((addoutput7 / 1000000) % 10 != 0)) ovf_add = true;
        }

        if (ovf_add) {
            bin_val = addoutput7; bits_len = 7; check_sign = is_signed; dec_val = 0; cur_p10 = 1; cur_p2 = 1;
            for (int i = 0; i < bits_len - 1; i++) {
                dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
                cur_p10 *= 10; cur_p2 *= 2;
            }
            if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2;
            else dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cout << "A + B = " << setfill('0') << setw(7) << addoutput7 << " = " << dec_val << "\t\toverflow detected, answer given in 7 bits\n";
        }
        else {
            bin_val = addoutput; bits_len = 6; check_sign = is_signed; dec_val = 0; cur_p10 = 1; cur_p2 = 1;
            for (int i = 0; i < bits_len - 1; i++) {
                dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
                cur_p10 *= 10; cur_p2 *= 2;
            }
            if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2;
            else dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cout << "A + B = " << setfill('0') << setw(6) << addoutput << " = " << dec_val << "\t\tno overflow, so 6 bits\n";
        }


        // a-b subtraction
        long long compB7 = 0;
        p10_i = 1;
        for (int i = 0; i < 7; i++) {
            int bitB = (i < 6) ? ((value2 / p10_i) % 10) : sign_ext_B;
            compB7 += (1 - bitB) * p10_i;
            p10_i *= 10;
        }

        long long negB7 = 0;
        int c = 1;
        p10_i = 1;
        for (int i = 0; i < 7; i++) {
            int bit = (compB7 / p10_i) % 10;
            int s = bit + c;
            negB7 += (s % 2) * p10_i;
            c = s / 2;
            p10_i *= 10;
        }

        long long suboutputA_B7 = 0;
        carry = 0;
        p10_i = 1;
        for (int i = 0; i < 7; i++) {
            int bitA = (i < 6) ? ((value1 / p10_i) % 10) : sign_ext_A;
            int bitNegB = (negB7 / p10_i) % 10;
            int sum = bitA + bitNegB + carry;
            if (i < 6) suboutputA_B += (sum % 2) * p10_i;
            suboutputA_B7 += (sum % 2) * p10_i;
            carry = sum / 2;
            p10_i *= 10;
        }

        bool ovf_subA_B = false;
        if (is_signed) {
            int bitA5 = (value1 / p10_5) % 10;
            int bitB5 = (value2 / p10_5) % 10;
            int sum5 = (suboutputA_B / p10_5) % 10;
            if (bitA5 != bitB5 && sum5 != bitA5) ovf_subA_B = true;
        }
        else {
            if (carry == 0) ovf_subA_B = true;
        }

        if (ovf_subA_B) {
            bin_val = suboutputA_B7; bits_len = 7; check_sign = is_signed || (!is_signed && ovf_subA_B); dec_val = 0; cur_p10 = 1; cur_p2 = 1;
            for (int i = 0; i < bits_len - 1; i++) {
                dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
                cur_p10 *= 10; cur_p2 *= 2;
            }
            if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2;
            else dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cout << "A - B = " << setfill('0') << setw(7) << suboutputA_B7 << " = " << dec_val << "\t\toverflow detected, answer given in 7 bits\n";
        }
        else {
            bin_val = suboutputA_B; bits_len = 6; check_sign = is_signed; dec_val = 0; cur_p10 = 1; cur_p2 = 1;
            for (int i = 0; i < bits_len - 1; i++) {
                dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
                cur_p10 *= 10; cur_p2 *= 2;
            }
            if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2;
            else dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cout << "A - B = " << setfill('0') << setw(6) << suboutputA_B << " = " << dec_val << "\t\tno overflow, so 6 bits\n";
        }


        // b-a subtraction
        long long compA7 = 0;
        p10_i = 1;
        for (int i = 0; i < 7; i++) {
            int bitA = (i < 6) ? ((value1 / p10_i) % 10) : sign_ext_A;
            compA7 += (1 - bitA) * p10_i;
            p10_i *= 10;
        }

        long long negA7 = 0;
        c = 1;
        p10_i = 1;
        for (int i = 0; i < 7; i++) { 
            int bit = (compA7 / p10_i) % 10;
            int s = bit + c;
            negA7 += (s % 2) * p10_i;
            c = s / 2;
            p10_i *= 10;
        }

        long long suboutputB_A7 = 0;
        carry = 0;
        p10_i = 1;
        for (int i = 0; i < 7; i++) {
            int bitB = (i < 6) ? ((value2 / p10_i) % 10) : sign_ext_B;
            int bitNegA = (negA7 / p10_i) % 10;
            int sum = bitB + bitNegA + carry;
            if (i < 6) suboutputB_A += (sum % 2) * p10_i;
            suboutputB_A7 += (sum % 2) * p10_i;
            carry = sum / 2;
            p10_i *= 10;
        }

        bool ovf_subB_A = false;
        if (is_signed) {
            int bitA5 = (value1 / p10_5) % 10;
            int bitB5 = (value2 / p10_5) % 10;
            int sum5 = (suboutputB_A / p10_5) % 10;
            if (bitB5 != bitA5 && sum5 != bitB5) ovf_subB_A = true;
        }
        else {
            if (carry == 0) ovf_subB_A = true;
        }

        if (ovf_subB_A) {
            bin_val = suboutputB_A7; bits_len = 7; check_sign = is_signed || (!is_signed && ovf_subB_A); dec_val = 0; cur_p10 = 1; cur_p2 = 1;
            for (int i = 0; i < bits_len - 1; i++) {
                dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
                cur_p10 *= 10; cur_p2 *= 2;
            }
            if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2;
            else dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cout << "B - A = " << setfill('0') << setw(7) << suboutputB_A7 << " = " << dec_val << "\t\toverflow detected, answer given in 7 bits\n";
        }
        else {
            bin_val = suboutputB_A; bits_len = 6; check_sign = is_signed; dec_val = 0; cur_p10 = 1; cur_p2 = 1;
            for (int i = 0; i < bits_len - 1; i++) {
                dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
                cur_p10 *= 10; cur_p2 *= 2;
            }
            if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2;
            else dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cout << "B - A = " << setfill('0') << setw(6) << suboutputB_A << " = " << dec_val << "\t\tno overflow, so 6 bits\n";
        }


        // multiplication place
        long long magA_mul = value1;
        if (is_signed && (value1 / p10_5) % 10 == 1) {
            long long comp = 0;
            p10_i = 1;
            for (int i = 0; i < 6; i++) { //get +ve magnitudes
                comp += (1 - ((value1 / p10_i) % 10)) * p10_i;
                p10_i *= 10;
            }
            c = 1; magA_mul = 0; p10_i = 1;
            for (int i = 0; i < 6; i++) {
                int s = (comp / p10_i) % 10 + c;
                magA_mul += (s % 2) * p10_i;
                c = s / 2;
                p10_i *= 10;
            }
        }
         
        long long magB_mul = value2;    //get -ve magnitudes
        if (is_signed && (value2 / p10_5) % 10 == 1) {
            long long comp = 0;
            p10_i = 1;
            for (int i = 0; i < 6; i++) {
                comp += (1 - ((value2 / p10_i) % 10)) * p10_i;
                p10_i *= 10;
            }
            c = 1; magB_mul = 0; p10_i = 1;
            for (int i = 0; i < 6; i++) {
                int s = (comp / p10_i) % 10 + c;
                magB_mul += (s % 2) * p10_i;
                c = s / 2;
                p10_i *= 10;
            }
        }

        p10_i = 1;
        for (int i = 0; i < 6; i++) {
            if ((magB_mul / p10_i) % 10 == 1) {
                carry = 0;
                long long temp_res = 0;
                long long p10_j = 1;
                long long p10_shift = 1;
                for (int s = 0; s < i; s++) p10_shift *= 10;

                for (int j = 0; j < 12; j++) {
                    int bit_mult = (multoutput / p10_j) % 10;
                    int bit_shifted = (j >= i && j - i < 6) ? ((magA_mul / (p10_j / p10_shift)) % 10) : 0;
                    int sum = bit_mult + bit_shifted + carry;
                    temp_res += (sum % 2) * p10_j;
                    carry = sum / 2;
                    p10_j *= 10;
                }
                multoutput = temp_res;
            }
            p10_i *= 10;
        }

        bool is_mul_neg = is_signed && (((value1 / p10_5) % 10) != ((value2 / p10_5) % 10));
        if (is_mul_neg) {
            long long comp12 = 0;
            long long p10_k = 1;
            for (int i = 0; i < 12; i++) {
                comp12 += (1 - ((multoutput / p10_k) % 10)) * p10_k;
                p10_k *= 10;
            }
            multoutput = 0; c = 1; p10_k = 1;
            for (int i = 0; i < 12; i++) {
                int s = (comp12 / p10_k) % 10 + c;
                multoutput += (s % 2) * p10_k;
                c = s / 2;
                p10_k *= 10;
            }
        }

        bin_val = multoutput; bits_len = 12; check_sign = is_signed; dec_val = 0; cur_p10 = 1; cur_p2 = 1;
        for (int i = 0; i < bits_len - 1; i++) {
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cur_p10 *= 10; cur_p2 *= 2;
        }
        if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2;
        else dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

        cout << "A * B = " << setfill('0') << setw(12) << multoutput << " = " << dec_val << "\t\tmust be 12 bits/digits long, sign/unsigned according to input\n";


        // divison and mod place
        if (magB_mul != 0) { //stop crashesss
            for (int i = 5; i >= 0; i--) {
                long long p10_shift_i = 1;
                for (int k = 0; k < i; k++) p10_shift_i *= 10;

                long long temp_rem = 0;
                long long p10_j = 1;
                for (int j = 0; j < 6; j++) {
                    int bit_rem = (j > 0) ? ((remoutput / (p10_j / 10)) % 10) : ((magA_mul / p10_shift_i) % 10);
                    temp_rem += bit_rem * p10_j;
                    p10_j *= 10;
                }
                remoutput = temp_rem;

                bool gte = true;
                long long p10_k = 100000;
                for (int k = 5; k >= 0; k--) {
                    int r_bit = (remoutput / p10_k) % 10;
                    int b_bit = (magB_mul / p10_k) % 10;
                    if (r_bit > b_bit) { gte = true; break; }
                    if (r_bit < b_bit) { gte = false; break; }
                    p10_k /= 10;
                }

                if (gte) {
                    long long compB_div = 0;
                    p10_k = 1;
                    for (int k = 0; k < 6; k++) {
                        compB_div += (1 - ((magB_mul / p10_k) % 10)) * p10_k;
                        p10_k *= 10;
                    }
                    long long negB_div = 0;
                    int cy = 1;
                    p10_k = 1;
                    for (int k = 0; k < 6; k++) {
                        int s = (compB_div / p10_k) % 10 + cy;
                        negB_div += (s % 2) * p10_k;
                        cy = s / 2;
                        p10_k *= 10;
                    }

                    long long new_rem = 0;
                    cy = 0;
                    p10_k = 1;
                    for (int k = 0; k < 6; k++) {
                        int s = ((remoutput / p10_k) % 10) + ((negB_div / p10_k) % 10) + cy;
                        new_rem += (s % 2) * p10_k;
                        cy = s / 2;
                        p10_k *= 10;
                    }
                    remoutput = new_rem;

                    long long new_quot = 0;
                    cy = 0;
                    p10_k = 1;
                    for (int k = 0; k < 6; k++) {
                        int q_bit = (quotoutput / p10_k) % 10;
                        int add_bit = (k == i) ? 1 : 0;
                        int s = q_bit + add_bit + cy;
                        new_quot += (s % 2) * p10_k;
                        cy = s / 2;
                        p10_k *= 10;
                    }
                    quotoutput = new_quot;
                }
            }
        }

        if (is_signed && magB_mul != 0 && (((value1 / p10_5) % 10) != ((value2 / p10_5) % 10))) {
            long long compQ = 0;
            long long p10_k = 1;
            for (int k = 0; k < 6; k++) {
                compQ += (1 - ((quotoutput / p10_k) % 10)) * p10_k;
                p10_k *= 10;
            }
            long long negQ = 0;
            int cy = 1;
            p10_k = 1;
            for (int k = 0; k < 6; k++) {
                int s = (compQ / p10_k) % 10 + cy;
                negQ += (s % 2) * p10_k;
                cy = s / 2;
                p10_k *= 10;
            }
            quotoutput = negQ;
        }

        if (is_signed && magB_mul != 0 && (value1 / p10_5) % 10 == 1) {
            long long compR = 0;
            long long p10_k = 1;
            for (int k = 0; k < 6; k++) {
                compR += (1 - ((remoutput / p10_k) % 10)) * p10_k;
                p10_k *= 10;
            }
            long long negR = 0;
            int cy = 1;
            p10_k = 1;
            for (int k = 0; k < 6; k++) {
                int s = (compR / p10_k) % 10 + cy;
                negR += (s % 2) * p10_k;
                cy = s / 2;
                p10_k *= 10;
            }
            remoutput = negR;
        }

        // Quotient layouts
        bin_val = quotoutput; bits_len = 6; check_sign = is_signed; dec_val = 0; cur_p10 = 1; cur_p2 = 1;
        for (int i = 0; i < bits_len - 1; i++) {
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cur_p10 *= 10; cur_p2 *= 2;
        }
        if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2;
        else dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cout << "A / B = " << setfill('0') << setw(6) << quotoutput << " = " << dec_val << "\t\tgive only the quotient\n";

        // Remander Layout
        bin_val = remoutput; bits_len = 6; check_sign = is_signed; dec_val = 0; cur_p10 = 1; cur_p2 = 1;
        for (int i = 0; i < bits_len - 1; i++) {
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cur_p10 *= 10; cur_p2 *= 2;
        }
        if (check_sign && ((bin_val / cur_p10) % 10 == 1)) dec_val -= cur_p2;
        else dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cout << "A % B = " << setfill('0') << setw(6) << remoutput << " = " << dec_val << "\t\tgive only the remainder, inheriting sign of dividend\n";
    }
        break;


    case 8:
    {
        srand(time(NULL)); //seeded rng 

            //random x positions for everything 
        int Px = rand() % 20, Py = rand() % 10; //packmax x,y position
        int Cx = rand() % 20, Cy = rand() % 10; //clyde x,y position
        int Ix = rand() % 20, Iy = rand() % 10; //Inky x,y position
        int Pix = rand() % 20, Piy = rand() % 10; //pinky x,y position

        // Blinky (y=2 , y =7 )
        int start_B = rand() % 40; // <20 spawn top y=2 , >20 spawn bot y=7
        int B_state = (start_B < 20) ? 0 : 1; // 0: Top moving right, 1: Bottom moving left
        int Bx = (start_B < 20) ? start_B : (start_B - 20);
        int By = (B_state == 0) ? 2 : 7;

        int game_state = 0; // 0 = Playing, 1 = Win, 2 = Loss

        while (game_state == 0) {
     
            for (int i = 0; i < 40; i++) cout << '\n';
            this_thread::sleep_for(chrono::milliseconds(20));

            cout << "PAC-A-MAN!\n";
            cout << "Controls: W A S D + Enter\n\n";
            cout << "ps I actually dont think this is winnable." << endl;

            // board
            for (int y = 0; y < 10; y++) {
                for (int x = 0; x < 20; x++) {
                    char cell = '*'; 

                    // Overlap display priority
                    cell = (x == Cx && y == Cy) ? 'C' : cell;
                    cell = (x == Ix && y == Iy) ? 'I' : cell;
                    cell = (x == Pix && y == Piy) ? 'P' : cell;
                    cell = (x == Bx && y == By) ? 'B' : cell;
                    cell = (x == Px && y == Py) ? '@' : cell;

                    cout << cell << ' ';
                }
                cout << '\n';
            }

            // PC input and mvmnt
            char input;
            cout << "\nMove: ";
            cin >> input;

            int old_Px = Px;
            int old_Py = Py;

            //movement
            switch (input) {
            case 'w': case 'W': Py--; break;
            case 's': case 'S': Py++; break;
            case 'a': case 'A': Px--; break;
            case 'd': case 'D': Px++; break;
            default: break;
            }

            //boundry rules
            Px = (Px < 0) ? 0 : ((Px > 19) ? 19 : Px); //throws the man back into the game if he wanders off screen
            Py = (Py < 0) ? 0 : ((Py > 9) ? 9 : Py);

            // Clyde logics
            //move like the man
            int pac_dx = Px - old_Px;
            int pac_dy = Py - old_Py;
            Cx += pac_dx;
            Cy += pac_dy;

            Cx = (Cx < 0) ? 0 : ((Cx > 19) ? 19 : Cx);
            Cy = (Cy < 0) ? 0 : ((Cy > 9) ? 9 : Cy);

            //wincheck
            game_state = (Px == Cx && Py == Cy) ? 1 : game_state;


            // Inky's logics
            // Calculate Euclidean distance
            long long dC = (Cx - Px) * (Cx - Px) + (Cy - Py) * (Cy - Py);  //using distance formula in a cartesian plane
            long long dI = (Ix - Px) * (Ix - Px) + (Iy - Py) * (Iy - Py);
            long long dP = (Pix - Px) * (Pix - Px) + (Piy - Py) * (Piy - Py);
            long long dB = (Bx - Px) * (Bx - Px) + (By - Py) * (By - Py);

            bool inky_closest = (dI <= dC) && (dI <= dP) && (dI <= dB);

            // Check clockwise free spaces on top right bottom and left.
            bool free_top = (Py - 1 >= 0) && !(Px == Cx && Py - 1 == Cy) && !(Px == Pix && Py - 1 == Piy) && !(Px == Bx && Py - 1 == By) && !(Px == Px && Py - 1 == Py); 
            bool free_rgt = (Px + 1 <= 19) && !(Px + 1 == Cx && Py == Cy) && !(Px + 1 == Pix && Py == Piy) && !(Px + 1 == Bx && Py == By) && !(Px + 1 == Px && Py == Py);
            bool free_bot = (Py + 1 <= 9) && !(Px == Cx && Py + 1 == Cy) && !(Px == Pix && Py + 1 == Piy) && !(Px == Bx && Py + 1 == By) && !(Px == Px && Py + 1 == Py);
            bool free_lft = (Px - 1 >= 0) && !(Px - 1 == Cx && Py == Cy) && !(Px - 1 == Pix && Py == Piy) && !(Px - 1 == Bx && Py == By) && !(Px - 1 == Px && Py == Py);

            int new_Ix = inky_closest ? (free_top ? Px : (free_rgt ? Px + 1 : (free_bot ? Px : (free_lft ? Px - 1 : Ix)))) : Ix;
            int new_Iy = inky_closest ? (free_top ? Py - 1 : (free_rgt ? Py : (free_bot ? Py + 1 : (free_lft ? Py : Iy)))) : Iy;

            // update if not won by clyde?
            Ix = (game_state == 0) ? new_Ix : Ix;
            Iy = (game_state == 0) ? new_Iy : Iy;

            //Inky losscheck
            game_state = (game_state == 0 && Px == Ix && Py == Iy) ? 2 : game_state;


            //Pinky logics
            // Moves one unit based on the largest distance to Pac-Man, or diagonal on a tie
            int pinky_dx = Px - Pix;
            int pinky_dy = Py - Piy;
            int abs_pdx = (pinky_dx < 0) ? -pinky_dx : pinky_dx;
            int abs_pdy = (pinky_dy < 0) ? -pinky_dy : pinky_dy;

            int sx = (pinky_dx > 0) ? 1 : ((pinky_dx < 0) ? -1 : 0);
            int sy = (pinky_dy > 0) ? 1 : ((pinky_dy < 0) ? -1 : 0);

            int new_Pix = Pix + ((abs_pdx > abs_pdy) ? sx : ((abs_pdx == abs_pdy) ? sx : 0));
            int new_Piy = Piy + ((abs_pdy > abs_pdx) ? sy : ((abs_pdx == abs_pdy) ? sy : 0));

            Pix = (game_state == 0) ? new_Pix : Pix;
            Piy = (game_state == 0) ? new_Piy : Piy;

            //Pinky losscheck
            game_state = (game_state == 0 && Px == Pix && Py == Piy) ? 2 : game_state;


            //Blinky logics
            // traverse lines and teleport
            int new_Bx = Bx + ((B_state == 0) ? 1 : -1);
            bool top_end = (B_state == 0 && new_Bx > 19);
            bool bot_end = (B_state == 1 && new_Bx < 0);

            B_state = top_end ? 1 : (bot_end ? 0 : B_state);
            new_Bx = top_end ? 19 : (bot_end ? 0 : new_Bx);
            int new_By = top_end ? 7 : (bot_end ? 2 : By);

            Bx = (game_state == 0) ? new_Bx : Bx;
            By = (game_state == 0) ? new_By : By;

            //binky loss check
            game_state = (game_state == 0 && Px == Bx && Py == By) ? 2 : game_state;
        }

        for (int i = 0; i < 40; i++) cout << '\n';

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 20; x++) {
                char cell = '*';
                cell = (x == Cx && y == Cy) ? 'C' : cell;
                cell = (x == Ix && y == Iy) ? 'I' : cell;
                cell = (x == Pix && y == Piy) ? 'P' : cell;
                cell = (x == Bx && y == By) ? 'B' : cell;
                cell = (x == Px && y == Py) ? '@' : cell;
                cout << cell << ' ';
            }
            cout << '\n';
        }
        //outputs
        switch (game_state) {
        case 1:
            cout << "\nSiren activated , you win.\n";
            break;
        case 2:
            cout << "\nGame over gg.\n";
            break;
    }
        break;
   
    }
	default:
		cout << "The Question Number you entered was not part of the assignment ,session terminated." << endl;
		break;
	}
  }
	return 0;
 
 }