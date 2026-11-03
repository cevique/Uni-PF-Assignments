#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to calculate the day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
int getStartDay(int year, int month) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    // Zeller's Congruence shifted to make 0 = Sunday
    int dayOfWeek = (1 + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;
    return (dayOfWeek + 6) % 7; 
}

void display(int spaces, int totaldays) {
    int day = 1;
    
    // Print leading empty spaces for the first week row
    cout << string(spaces * 3, ' ');
    
    // Handle the first week row specifically
    for (int j = spaces; j < 7; j++) {
        cout << setw(2) << day << ' ';
        day++;
    }
    cout << '\n';
    
    // Handle all subsequent rows
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
    cout << "Month (1-12)::: ";
    cin >> month;
    
    string mName;
    int maxdays = 31;
    
    switch(month) {
        case 1: mName="January"; break;
        case 2: 
            mName="February"; 
            maxdays = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
            break;
        case 3: mName="March"; break;
        case 4: mName="April"; maxdays = 30; break;
        case 5: mName="May"; break;
        case 6: mName="June"; maxdays = 30; break;
        case 7: mName="July"; break;
        case 8: mName="August"; break;
        case 9: mName="September"; maxdays = 30; break;
        case 10: mName="October"; break;
        case 11: mName="November"; maxdays = 30; break;
        case 12: mName="December"; break;
        default: cout << "Invalid Month\n"; return 1;
    }
    
    // Print Header
    cout << '\n' << setw(11) << mName << ' ' << year << '\n';
    cout << "Su Mo Tu We Th Fr Sa\n";
    
    // Dynamically calculate which day of the week the month starts on
    int sp = getStartDay(year, month);
    
    display(sp, maxdays);
    
    return 0;
}
