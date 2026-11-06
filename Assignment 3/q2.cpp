
#include <iostream>
#include <iomanip>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0);
}

int daysSinceEpoch(int year, int month) {
    int y = year - 1;
    int totalDays = y * 365 + y / 4 - y / 100 + y / 400;

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int m = 0; m < month - 1; m++) {
        totalDays += monthDays[m];
    }

    if (month > 2 && isLeapYear(year)) {
        totalDays++;
    }
    return totalDays;
}

int getStartDay(int year, int month) {
    int offset = daysSinceEpoch(year, month) % 7;
    return (offset + 1) % 7;
}

void display(int spaces, int totaldays) {
    int day = 1;

    for (int i = 0; i < spaces * 3; i++) {
        cout << ' ';
    }

    for (int j = spaces; j < 7; j++) {
        cout << setw(2) << day << ' ';
        day++;
    }

    cout << '\n';

    while (day <= totaldays) {
        for (int j = 0; j < 7; j++) {
            if (day > totaldays) {
                cout << '\n';
                return;
            }
            cout << setw(2) << day << ' ';
            day++;
        }
        cout << '\n';
    }
}

int main() {
    int year, month;
    cout << "Year::: ";
    cin >> year;
    cout << "Month::: ";
    cin >> month;

    int maxdays = 31;

    switch(month) {
        case 1: break;
        case 2:
            maxdays = isLeapYear(year) ? 29 : 28;
            break;
        case 3: break;
        case 4: maxdays = 30; break;
        case 5: break;
        case 6: maxdays = 30; break;
        case 7: break;
        case 8: break;
        case 9: maxdays = 30; break;
        case 10: break;
        case 11: maxdays = 30; break;
        case 12: break;
        default:
            cout << "Invalid Month\n";
            return 1;
    }

    cout << '\n' << setw(11);

    switch(month) {
        case 1: cout << "January"; break;
        case 2: cout << "February"; break;
        case 3: cout << "March"; break;
        case 4: cout << "April"; break;
        case 5: cout << "May"; break;
        case 6: cout << "June"; break;
        case 7: cout << "July"; break;
        case 8: cout << "August"; break;
        case 9: cout << "September"; break;
        case 10: cout << "October"; break;
        case 11: cout << "November"; break;
        case 12: cout << "December"; break;
    }

    cout << ' ' << year << '\n';
    cout << "Su Mo Tu We Th Fr Sa\n";

    int sp = getStartDay(year, month);

    display(sp, maxdays);

    return 0;
}
