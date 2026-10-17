#include <iostream>
using namespace std;

int main(){

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

    // Murdoch: From Boiler Room, visit Cargo Hold or Third Class
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 0:
                    switch (murVisitedCargoHold) {
                        case 0: murCurrent = 1; break;
                        case 1:
                            switch (murVisitedThirdClass) {
                                case 0: murCurrent = 2; break;
                            } break;
                    } break;
            }
            switch (murCurrent) {
                case 1: murVisitedCargoHold = 1; break;
                case 2: murVisitedThirdClass = 1; break;
            } break;
        case 1: break;
    }

    // Murdoch: From Cargo Hold, visit Dining Saloon or Promenade Deck
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 1:
                    switch (murVisitedDiningSaloon) {
                        case 0: murCurrent = 3; break;
                        case 1:
                            switch (murVisitedPromenadeDeck) {
                                case 0: murCurrent = 4; break;
                            } break;
                    } break;
            }
            switch (murCurrent) {
                case 3: murVisitedDiningSaloon = 1; break;
                case 4: murVisitedPromenadeDeck = 1; break;
            } break;
        case 1: break;
    }

    // Murdoch: From Dining Saloon, visit Crow's Nest
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 3:
                    switch (murVisitedCrowsNest) {
                        case 0: murCurrent = 7; break;
                        case 1: break;
                    } break;
            }
            switch (murCurrent) {
                case 7:
                    murVisitedCrowsNest = 1;
                    switch (murVisitedDiningSaloon) {
                        case 1: cout << "DoorSealed\n"; murVisitedDiningSaloon = 0; break;
                        case 0: break;
                    } break;
            } break;
        case 1: break;
    }

    // Murdoch: From Crow's Nest, return to Dining Saloon or Promenade Deck
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 7:
                    switch (murVisitedDiningSaloon) {
                        case 0: murCurrent = 3; break;
                        case 1:
                            switch (murVisitedPromenadeDeck) {
                                case 0: murCurrent = 4; break;
                                case 1: break;
                            } break;
                    } break;
            }
            switch (murCurrent) {
                case 3: murVisitedDiningSaloon = 1; break;
                case 4: murVisitedPromenadeDeck = 1; break;
            } break;
        case 1: break;
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
                                        case 0: cout << "TurnBack\n"; murCurrent = 1; break;
                                        case 1: break;
                                    } break;
                            } break;
                    } break;
            }
            switch (murCurrent) {
                case 1: murVisitedCargoHold = 1; break;
            } break;
        case 1: break;
    }

    // Murdoch: From Cargo Hold, visit next unvisited location (Third Class, Dining Saloon, or Promenade Deck)
    switch (murIsFrozen) {
        case 0:
            switch (murCurrent) {
                case 1:
                    switch (murVisitedThirdClass) {
                        case 0: murCurrent = 2; break;
                        case 1:
                            switch (murVisitedDiningSaloon) {
                                case 0: murCurrent = 3; break;
                                case 1:
                                    switch (murVisitedPromenadeDeck) {
                                        case 0: murCurrent = 4; break;
                                    } break;
                            } break;
                    } break;
            }
            switch (murCurrent) {
                case 2: murVisitedThirdClass = 1; break;
            } break;
        case 1: break;
    }

    // Mary: From Boiler Room, visit Cargo Hold or Third Class
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 0:
                    switch (maryVisitedCargoHold) {
                        case 0: maryCurrent = 1; break;
                        case 1:
                            switch (maryVisitedThirdClass) {
                                case 0: maryCurrent = 2; break;
                            } break;
                    } break;
            }
            switch (maryCurrent) {
                case 1: maryVisitedCargoHold = 1; break;
                case 2: maryVisitedThirdClass = 1; break;
            } break;
        case 1: break;
    }

    // Mary: From Cargo Hold, return to Boiler Room or go to Dining Saloon/Promenade Deck
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 1:
                    switch (maryVisitedThirdClass) {
                        case 0: maryCurrent = 0; break;
                        case 1:
                            switch (maryVisitedDiningSaloon) {
                                case 0: maryCurrent = 3; break;
                                case 1:
                                    switch (maryVisitedPromenadeDeck) {
                                        case 0: maryCurrent = 4; break;
                                    } break;
                            } break;
                    } break;
            }
            switch (maryCurrent) {
                case 0: maryVisitedBoilerRoom = 1; break;
                case 3: maryVisitedDiningSaloon = 1; break;
                case 4: maryVisitedPromenadeDeck = 1; break;
            } break;
        case 1: break;
    }

    // Mary: From Boiler Room, visit Third Class
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 0:
                    switch (maryVisitedCargoHold) {
                        case 1:
                            switch (maryVisitedThirdClass) {
                                case 0: maryCurrent = 2; break;
                            } break;
                    } break;
            }
            switch (maryCurrent) {
                case 2: maryVisitedThirdClass = 1; break;
            } break;
        case 1: break;
    }

    // Mary: From Third Class, visit Bridge (triggers WaterRising event)
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 2:
                    switch (maryVisitedBridge) {
                        case 0: cout << "WaterRising\n"; maryCurrent = 5; maryVisitedBridge = 1; break;
                        case 1:
                            switch (maryVisitedBridge) {
                                case 1: maryCurrent = 5; break;
                            } break;
                    } break;
            }
            switch (maryCurrent) {
                case 5: maryVisitedBridge = 1; break;
            } break;
        case 1: break;
    }

    // Mary: From Bridge, visit Lifeboat Deck or Crow's Nest
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 5:
                    switch (maryVisitedLifeboatDeck) {
                        case 0: maryCurrent = 6; break;
                        case 1:
                            switch (maryVisitedCrowsNest) {
                                case 0: maryCurrent = 7; break;
                            } break;
                    } break;
            }
            switch (maryCurrent) {
                case 6: maryVisitedLifeboatDeck = 1; break;
                case 7: maryVisitedCrowsNest = 1; break;
            }
            switch (maryCurrent) {
                case 6: cout << "Rescued\n"; maryIsFrozen = 1; break;
            } break;
        case 1: break;
    }

    // Mary: At Lifeboat Deck, character is rescued (end state)
    switch (maryIsFrozen) {
        case 0:
            switch (maryCurrent) {
                case 6: cout << "Rescued\n"; maryIsFrozen = 1; break;
            } break;
        case 1: break;
    }

    cout << '\n';
    cout << "Murdoch path: Boiler Room -> Cargo Hold -> Dining Saloon -> Crow's Nest -> Dining Saloon -> Cargo Hold -> Third Class\n";
    cout << "Mary path: Boiler Room -> Cargo Hold -> Boiler Room -> Third Class -> Bridge -> Lifeboat Deck -> Lifeboat Deck\n";
    return 0;
}