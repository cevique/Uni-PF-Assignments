#include <iostream>
#include <iomanip>

/* 
   terminal.h and helperCells.h both define readKey(),
   so I will rename the terminal.h version into termReadKey()
   before including helperCells.h to avoid a clash.
*/

#define readKey termReadKey
#include "terminal.h"
#undef readKey

#include "helperCells.h"

using namespace std;

bool useColors = true;

const char C_RESET[]   = "\033[0m";
const char C_DIM[]     = "\033[90m";
const char C_RED[]     = "\033[1;31m";
const char C_GREEN[]   = "\033[1;32m";
const char C_YELLOW[]  = "\033[1;33m";
const char C_BLUE[]    = "\033[1;34m";
const char C_MAGENTA[] = "\033[1;35m";
const char C_CYAN[]    = "\033[1;36m";

const char PALETTE[6][10] = {
    "\033[1;36m", // Cyan
    "\033[1;32m", // Green
    "\033[1;33m", // Yellow
    "\033[1;35m", // Magenta
    "\033[1;34m", // Blue
    "\033[1;31m"  // Red
};

void putColor(const char code[]) {
    if (useColors) {
        cout << code;
    }
}

void renderBanner(const char subtitle[]) {
    putColor(C_CYAN);
    cout << "  ____    _  _____ _____ _     _____ ____  \n";
    cout << " | __ )  / \\|_   _|_   _| |   | ____|  _ \\ \n";
    cout << " |  _ \\ / _ \\ | |   | | | |   |  _| | |_) |\n";
    cout << " | |_) / ___ \\| |   | | | |___| |___|  _ < \n";
    cout << " |____/_/   \\_|_|   |_| |_____|_____|_| \\_\\\n";
    putColor(C_RESET);

    putColor(C_YELLOW);
    cout << "╔══════════════════════════════════════════════════════╗\n";
    cout << "║  ";
    putColor(C_GREEN);
    cout << subtitle;

    int len = 0;
    while (subtitle[len] != '\0') ++len;
    for (int i = len; i < 50; ++i) cout << " ";

    putColor(C_YELLOW);
    cout << "║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n";
    putColor(C_RESET);
    cout << "\n";
}
// ===================== Question 1 =====================

int runQ1(){
    int n;
    cout << "Enter no. ";
    cin >> n;
    int left=1, top=1, right=n, bottom=n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int dist = i-left;
            if(j-top < dist) dist = j-top;
            if(right-i < dist) dist = right-i;
            if(bottom-j < dist) dist = bottom-j;
	        dist++;
            dist %= 10;
            putColor(PALETTE[dist % 6]);
            cout << dist << ' ';
            putColor(C_RESET);
        }
        cout << '\n';
    }
    return 0;
}

// ===================== Question 2 =====================

bool isLeapYear(int year){
    return (year%4==0 and year%100!=0) or year%400==0;
}

int getTotalDays(int year, int month){
    int y = year - 1;
    int totalDays = y*365 + y/4 - y/100 + y/400;

    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int m=0; m<month-1; m++){
        totalDays += monthDays[m];
    }

    if(month > 2 and isLeapYear(year) ){
        totalDays++;
    }

    return totalDays;
}

int getOffset(int year, int month){
    int offset = getTotalDays(year, month) % 7;
    return (offset+1) % 7;
}

void display(int spaces, int maxdays){
    int days = 1;

    for(int i=0; i<spaces*3; i++){
        cout << ' ';
    }

    for(int i=spaces; i<7; i++){
        if (i == 0 || i == 6) putColor(C_RED);
        cout << setw(2) << days++;
        if (i == 0 || i == 6) putColor(C_RESET);
        cout << ' ';
    }

    cout << '\n';

    while(days <=maxdays){
        for(int i=0; i<7; i++){
            if(days > maxdays){
                cout << '\n';
                return;
            }
            if (i == 0 || i == 6) putColor(C_RED);
            cout << setw(2) << days++;
            if (i == 0 || i == 6) putColor(C_RESET);
            cout << ' ';
        }
        cout << '\n';
    }

}

int runQ2(){
    int year, month;
    int maxdays;
    cout << "Year::: "; cin >> year;
    cout << "Month::: "; cin >> month;

    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            maxdays = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxdays = 30;
            break;
        case 2:
            maxdays = (isLeapYear(year)? 29 : 28);
            break;
        default:
            cout << "Invalid Month\n";
            return 1;
    }

    cout << '\n' << setw(11);

    switch(month){
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

    int sp = getOffset(year, month);
    display(sp, maxdays);

    return 0;
}

// ===================== Question 3 =====================

int runQ3(){

    int n; cout << "Enter n: "; cin >> n;
    
    if(n<=2 or n%2==0){
        cout << "Invalid input";
        return 1;
    }

    for(int i=0; i<n; i++){

        int left=0;
        int right=2*i;
        char c;

        for(int sp=n-1-i; sp>0; sp--){
            cout << ' ';
        }

        for(int j=0; j<=right; j++){
            int dist = (right-j < j-left? right-j : j-left);
            dist %= 4;
            if( ((n-1)/2) % 2 ){
                switch(dist){
                    case 0: c='O'; break;
                    case 1: c='-'; break;
                    case 2: c='*'; break;
                    case 3: c='.';
                }
            }
            else{
                switch(dist){
                    case 0: c = '*'; break;
                    case 1: c = '-'; break;
                    case 2: c = 'O'; break;
                    case 3: c = '.';
                }
            }
            putColor(PALETTE[dist]);
            cout << c;
            putColor(C_RESET);
        }
        cout << '\n';

    }

    for(int i=n-1; i>=0; i--){
        
        int left=0;
        int right=2*i-2;
        char c;

        for(int sp=0; sp<n-i; sp++){
            cout << ' ';
        }

        for(int j=0; j<=right; j++){
            int dist = (right-j < j-left? right-j : j-left);
            dist %= 4;
            if( ((n-1)/2) % 2 ){
                switch(dist){
                    case 0: c='O'; break;
                    case 1: c='-'; break;
                    case 2: c='*'; break;
                    case 3: c='.';
                }
            }
            else{
                switch(dist){
                    case 0: c = '*'; break;
                    case 1: c = '-'; break;
                    case 2: c = 'O'; break;
                    case 3: c = '.';
                }
            }
            putColor(PALETTE[dist]);
            cout << c;
            putColor(C_RESET);
            
        }
        cout << '\n';
    }

    return 0;
}

// ===================== Question 4 =====================

int fibonacci_sum(int f){
    int a=1, b=1;
    int s=0, t=0;
    for(int i=0; i<f; i++){
        s += a;
        t = b;
        b += a;
        a = t;
    }
    return s;
}

int runQ4(){
    int n; cout << "N: "; cin >> n;
    int base; cout << "Base: "; cin >> base;
    int seed; cout << "Seed: "; cin >> seed;
    int seedrow = n-1;
    int seedcol = n-1;
    int value;
    
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++){
            int r = i-seedrow;
            int c = j-seedcol;
            if( i <= seedrow and j>=seedcol ){
                value = seed + fibonacci_sum( max( abs(r), abs(c) ) );
            }
            else if( i > seedrow and j <= seedcol ){
                value = seed - fibonacci_sum( max( abs(r), abs(c) ) );
            }
            else if( i <= seedrow and j < seedcol ){
                if( c >= r )
                    value = seed + fibonacci_sum(-r);
                else
                    value = seed + 2*fibonacci_sum(-r) - fibonacci_sum(-c);
            }
            else {
                if( c <= r )
                    value = seed - fibonacci_sum(r);
                else
                    value = seed + fibonacci_sum(c) - 2*fibonacci_sum(r);
            }
            value = (value%base + base) % base;
            putColor(PALETTE[value % 6]);
            if (value < 10) cout << value << ' ';
            else cout << (char)('A' + (value - 10)) << ' ';
            putColor(C_RESET);
        }
        cout << '\n';
    }
    
    return 0;
}

// ===================== Question 5 =====================

int emptyCell = 0;
int wall = 1;
int start = 2;
int exitCell = 3;
int gold = 4;
int visited = 5;
int visitedGold = 6;
int visitedExitCell = 7;

int r0=0, r1=0, r2=0, r3=0, r4=0, r5=0, r6=0, r7=0, r8=0, r9=0;

int goldReachable = 0;
int exitCellReachable = 0;

int getRow(int r){
    switch(r){
        case 0: return r0;
        case 1: return r1;
        case 2: return r2;
        case 3: return r3;
        case 4: return r4;
        case 5: return r5;
        case 6: return r6;
        case 7: return r7;
        case 8: return r8;
        case 9: return r9;
    }
    return 0;
}

void setRow(int r, int value){
    switch(r){
        case 0: r0 = value; break;
        case 1: r1 = value; break;
        case 2: r2 = value; break;
        case 3: r3 = value; break;
        case 4: r4 = value; break;
        case 5: r5 = value; break;
        case 6: r6 = value; break;
        case 7: r7 = value; break;
        case 8: r8 = value; break;
        case 9: r9 = value;
    }
}

int getCell(int r, int c){
    int place = 1;
    for(int i=0; i<c; i++){
        place *= 8;
    }
    return getRow(r) / place % 8;
}

void setCell(int r, int c, int value){
    int row = getRow(r);
    int place = 1;
    int oldValue = 0;
    for(int i=0; i<c; i++){
        place *= 8;
    }
    oldValue = row / place % 8;
    row = row - oldValue*place  + value*place;
    setRow(r, row);
}

int visitCell(int r, int c){
    int cell = getCell(r, c);
    if(cell == emptyCell){
        setCell(r, c, visited);
        return 1;
    }
    if(cell == gold){
        setCell(r, c, visitedGold);
        goldReachable++;
        return 1;
    }
    if(cell == exitCell){
        setCell(r, c, visitedExitCell);
        exitCellReachable++;
        return 1;
    }
    return 0;
}

int runQ5(){
    int n; cin >> n;
    if(n < 2 or n > 10){
        cout << "Invalid input.";
        return 0;
    }
    int startR, startC;
    int state;
    char ch;

    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            cin >> ch;
            if(ch == 'S'){
                state = start;
                startR = r;
                startC = c;
            }
            else if(ch == '*'){
                state = wall;
            }
            else if(ch == '.'){
                state = emptyCell;
            }
            else if(ch == 'G'){
                state = gold;
            }
            else if(ch == 'E'){
                state = exitCell;
            }
            else{
                cout << "\nInvalid choice.";
                return 0;
            }
            setCell(r, c, state);
        }
    }

    setCell(startR, startC, visited);

    int changed;

    do{
        changed = 0;

        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                state = getCell(r,c);
                if(state == visited or state == visitedGold or state == visitedExitCell){
                    if(r > 0) changed += visitCell(r-1, c);
                    if(r < n-1) changed += visitCell(r+1, c);
                    if(c > 0) changed += visitCell(r, c-1);
                    if(c < n-1) changed += visitCell(r,c+1);
                }
            }
        }

    } while(changed > 0);

    if (exitCellReachable) {
        cout << "Solvable: "; putColor(C_GREEN); cout << "YES"; putColor(C_RESET); cout << '\n';
    }
    else {
        cout << "Solvable: "; putColor(C_RED); cout << "NO"; putColor(C_RESET); cout << '\n';
    }
    cout << "Gold reachable: "; putColor(C_YELLOW); cout << goldReachable; putColor(C_RESET); cout << '\n';  

    return 0;
}

// ===================== Question 6 =====================

int locateProcess(const int processIds[], int totalProcesses, int targetPid) {
    int low = 0, high = totalProcesses - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (processIds[mid] == targetPid) return mid;
        processIds[mid] < targetPid ? low = mid + 1 : high = mid - 1;
    }
    return -1;
}

bool requestMemory(int blockStarts[], int blockSizes[], int blockOwners[], int &blockCount, int requestedSize, int processId, int &startAddress) {
    const int memory_size = 100;
    if (requestedSize < 1 or requestedSize > memory_size) return false;
    
    for (int i = 0; i < blockCount; ++i) {
        if (blockOwners[i] or blockSizes[i] < requestedSize) continue;
        
        startAddress = blockStarts[i];
        if (blockSizes[i] == requestedSize) {
            blockOwners[i] = processId;
            return true;
        }
        
        for (int j = blockCount; j > i + 1; --j) {
            blockStarts[j] = blockStarts[j - 1];
            blockSizes[j] = blockSizes[j - 1];
            blockOwners[j] = blockOwners[j - 1];
        }
        blockStarts[i + 1] = blockStarts[i] + requestedSize;
        blockSizes[i + 1] = blockSizes[i] - requestedSize;
        blockOwners[i + 1] = 0;
        
        blockSizes[i] = requestedSize;
        blockOwners[i] = processId;
        ++blockCount;
        return true;
    }
    return false;
}

void returnMemory(int blockStarts[], int blockSizes[], int blockOwners[], int &blockCount, int processId) {
    int i = 0;
    while (i < blockCount and blockOwners[i] != processId) ++i;
    if (i == blockCount) return;
    
    blockOwners[i] = 0;
    
    if (i + 1 < blockCount and !blockOwners[i + 1]) {
        blockSizes[i] += blockSizes[i + 1];
        for (int j = i + 1; j + 1 < blockCount; ++j) {
            blockStarts[j] = blockStarts[j + 1];
            blockSizes[j] = blockSizes[j + 1];
            blockOwners[j] = blockOwners[j + 1];
        }
        --blockCount;
    }
    
    if (i > 0 and !blockOwners[i - 1]) {
        blockSizes[i - 1] += blockSizes[i];
        for (int j = i; j + 1 < blockCount; ++j) {
            blockStarts[j] = blockStarts[j + 1];
            blockSizes[j] = blockSizes[j + 1];
            blockOwners[j] = blockOwners[j + 1];
        }
        --blockCount;
    }
}

int calculateTotalFreeMemory(const int blockSizes[], const int blockOwners[], int blockCount) {
    int totalFree = 0;
    for (int i = 0; i < blockCount; ++i) {
        totalFree += blockOwners[i] ? 0 : blockSizes[i];
    }
    return totalFree;
}

int findLargestFreeBlock(const int blockSizes[], const int blockOwners[], int blockCount) {
    int largestBlock = 0;
    for (int i = 0; i < blockCount; ++i) {
        largestBlock = (!blockOwners[i] and blockSizes[i] > largestBlock) ? blockSizes[i] : largestBlock;
    }
    return largestBlock;
}

void printMemoryMap(const int blockSizes[], const int blockOwners[], int blockCount) {
    cout << "\nMemory Layout (0 to 99):\n";
    int currentPosition = 0;
    for (int i = 0; i < blockCount; ++i) {
        for (int k = 0; k < blockSizes[i]; ++k, ++currentPosition) {
            cout << blockOwners[i] << ' ';
            if ((currentPosition + 1) % 10 == 0) cout << '\n';
        }
    }
}

void rebuildMemory(int blockStarts[], int blockSizes[], int blockOwners[], int &blockCount, const int processIds[],
                   int memoryStartIndices[], const int memoryRequirements[], int totalProcesses) {
    const int memory_size = 100;
    int currentCursor = 0;
    blockCount = 0;
    
    for (int i = 0; i < totalProcesses; ++i) {
        if (memoryStartIndices[i] == -1) continue;
        
        blockStarts[blockCount] = currentCursor;
        blockSizes[blockCount] = memoryRequirements[i];
        blockOwners[blockCount] = processIds[i];
        memoryStartIndices[i] = currentCursor;
        
        currentCursor += memoryRequirements[i];
        ++blockCount;
    }
    
    if (currentCursor < memory_size) {
        blockStarts[blockCount] = currentCursor;
        blockSizes[blockCount] = memory_size - currentCursor;
        blockOwners[blockCount] = 0;
        ++blockCount;
    }
}

void printState(int statusCode) {
    if (statusCode == 0){
        putColor(C_YELLOW); cout << "New";
    }
    else if (statusCode == 1){
        putColor(C_GREEN); cout << "Ready";
    }
    else if (statusCode == 2){
        putColor(C_CYAN); cout << "Running";
    }
    else if (statusCode == 3){
        putColor(C_BLUE); cout << "Completed";
    }
    else {
        putColor(C_RED); cout << "Terminated";
    }
    putColor(C_RESET);
}

void runScheduler(int schedulingMode, const int processIds[], const int arrivalTimes[], const int burstTimes[], int remainingBurstTimes[], int completionTimes[], int turnaroundTimes[], int waitingTimes[], int processStates[], const int memoryStartIndices[], int totalProcesses, int timeQuantum) {

    const int max_processes = 100;
    int activeProcessesCount = 0;
    
    for (int i = 0; i < totalProcesses; ++i) {
        if (processStates[i] != 4 and memoryStartIndices[i] != -1) {
            ++activeProcessesCount;
            processStates[i] = 1;
        }
    }

    if (schedulingMode == 3)
        cout << "\n--- Round Robin Scheduling (Quantum = " << timeQuantum << ") ---\n";
    else
        cout << (schedulingMode == 1 ? "\n--- FCFS Scheduling Execution Order ---\n" : "\n--- SJF (Non-Preemptive) Scheduling ---\n");

    for (int i = 0; i < totalProcesses; ++i) {
        remainingBurstTimes[i] = burstTimes[i];
    }

    int processQueue[max_processes], queueHead = 0, queueTail = 0;
    int currentClockTime = 0, totalBusyTime = 0, executedCount = 0, carriedProcessIndex = -1;
    bool isInQueue[max_processes] = {false}, isFinished[max_processes] = {false};
    long totalTurnaroundSum = 0, totalWaitingSum = 0;

    while (executedCount < activeProcessesCount) {
        while (true) {
            int selectedProcessIndex = -1;
            for (int i = 0; i < totalProcesses; ++i) {
                if (processStates[i] == 4 or memoryStartIndices[i] == -1 or isFinished[i] or isInQueue[i] or arrivalTimes[i] > currentClockTime or i == carriedProcessIndex) continue;
                if (selectedProcessIndex == -1 or arrivalTimes[i] < arrivalTimes[selectedProcessIndex] or (arrivalTimes[i] == arrivalTimes[selectedProcessIndex] and i < selectedProcessIndex)) {
                    selectedProcessIndex = i;
                }
            }
            if (selectedProcessIndex == -1) break;
            
            if (schedulingMode == 2) {
                int pos = queueTail;
                while (pos > queueHead) {
                    int prevProcess = processQueue[pos - 1];
                    bool shouldSwap = burstTimes[prevProcess] > burstTimes[selectedProcessIndex] or (burstTimes[prevProcess] == burstTimes[selectedProcessIndex] and (arrivalTimes[prevProcess] > arrivalTimes[selectedProcessIndex] or(arrivalTimes[prevProcess] == arrivalTimes[selectedProcessIndex] and prevProcess > selectedProcessIndex)));
                    if (!shouldSwap) break;
                    processQueue[pos] = processQueue[pos - 1];
                    --pos;
                }
                processQueue[pos] = selectedProcessIndex;
                ++queueTail;
            } else {
                processQueue[queueTail % max_processes] = selectedProcessIndex;
                ++queueTail;
            }
            isInQueue[selectedProcessIndex] = true;
        }

        if (carriedProcessIndex != -1) {
            processQueue[queueTail % max_processes] = carriedProcessIndex;
            isInQueue[carriedProcessIndex] = true;
            ++queueTail;
            carriedProcessIndex = -1;
        }

        if (queueHead == queueTail) {
            int nextProcess = -1;
            for (int i = 0; i < totalProcesses; ++i)
                if (processStates[i] != 4 and memoryStartIndices[i] != -1 and !isFinished[i] and !isInQueue[i] and (nextProcess == -1 or arrivalTimes[i] < arrivalTimes[nextProcess])) {
                    nextProcess = i;
                }
            if (nextProcess == -1) break;
            currentClockTime = arrivalTimes[nextProcess];
            continue;
        }

        int currentProcess = processQueue[queueHead % max_processes];
        ++queueHead;
        isInQueue[currentProcess] = false;

        int executionSlice = schedulingMode == 3 ? (remainingBurstTimes[currentProcess] < timeQuantum ? remainingBurstTimes[currentProcess] : timeQuantum) : burstTimes[currentProcess];
        int finishTime = currentClockTime + executionSlice;
        
        cout << "PID " << processIds[currentProcess] << (schedulingMode == 3 ? " runs from " : " executed from time ")
             << currentClockTime << " to " << finishTime << '\n';
             
        currentClockTime = finishTime;
        totalBusyTime += executionSlice;

        if (schedulingMode == 3) {
            remainingBurstTimes[currentProcess] -= executionSlice;
            if (remainingBurstTimes[currentProcess] > 0) {
                carriedProcessIndex = currentProcess;
                continue;
            }
        }

        isFinished[currentProcess] = true;
        processStates[currentProcess] = 3;
        completionTimes[currentProcess] = currentClockTime;
        turnaroundTimes[currentProcess] = completionTimes[currentProcess] - arrivalTimes[currentProcess];
        waitingTimes[currentProcess] = turnaroundTimes[currentProcess] - burstTimes[currentProcess];
        
        totalTurnaroundSum += turnaroundTimes[currentProcess];
        totalWaitingSum += waitingTimes[currentProcess];
        ++executedCount;
    }

    if (!executedCount) {
        cout << "No valid active processes executed.\n";
        return;
    }

    cout << "\nPID\tCT\tTAT\tWT\n";
    for (int i = 0; i < totalProcesses; ++i)
        if (processStates[i] == 3)
            cout << processIds[i] << '\t' << completionTimes[i] << '\t' << turnaroundTimes[i] << '\t' << waitingTimes[i] << '\n';
            
    cout << "Average Turnaround Time: " << (double)totalTurnaroundSum / executedCount << '\n' << "Average Waiting Time: " <<(double)totalWaitingSum / executedCount << '\n' << "CPU Utilization: " << (currentClockTime > 0 ? (double)totalBusyTime / currentClockTime * 100.0 : 0.0) << "%\n";
}

int runQ6() {

    const int max_processes = 100;
    const int memory_size = 100;
    const int max_blocks = 2 * max_processes + 5;

    int processIds[max_processes], arrivalTimes[max_processes], burstTimes[max_processes], remainingBurstTimes[max_processes], priorities[max_processes];
    int completionTimes[max_processes], turnaroundTimes[max_processes], waitingTimes[max_processes], memoryRequirements[max_processes], memoryStartIndices[max_processes], processStates[max_processes];
    
    int blockStarts[max_blocks] = {0}, blockSizes[max_blocks] = {memory_size}, blockOwners[max_blocks] = {0}, blockCount = 1;

    int totalProcesses = 0, nextPid = 101, successfulAllocations = 0, failedAllocations = 0, choice = -1;

    while (choice != 0) {

        cout << "\n===== CRUEL ANGEL'S THESIS: NERV OS RECOVERY =====\n" << "1. Register process\n" << "2. Display processes\n" << "3. Search process\n" << "4. Allocate memory to a process\n" << "5. Terminate process\n" << "6. Display memory\n" << "7. Compact memory\n" << "8. Run FCFS\n" << "9. Run SJF\n" << "10. Run Round Robin\n" << "11. System statistics\n" << "12. Display processes by status\n" << "0. Quit\n" << "Choice: ";

        if (!(cin >> choice)) break;

        if (choice == 1) {
            if (totalProcesses >= max_processes) {
                cout << "Process limit reached (100).\n";
                continue;
            }
            int arrTime, burstTime, priority, memReq;
            cout << "Arrival time, burst time, priority, memory requirement: ";
            cin >> arrTime >> burstTime >> priority >> memReq;

            int startAddress = -1;
            bool isAllocated = requestMemory(blockStarts, blockSizes, blockOwners, blockCount, memReq, nextPid, startAddress);

            processIds[totalProcesses] = nextPid;
            arrivalTimes[totalProcesses] = arrTime;
            burstTimes[totalProcesses] = burstTime;
            remainingBurstTimes[totalProcesses] = burstTime;
            priorities[totalProcesses] = priority;
            memoryRequirements[totalProcesses] = memReq;
            completionTimes[totalProcesses] = turnaroundTimes[totalProcesses] = waitingTimes[totalProcesses] = 0;
            
            memoryStartIndices[totalProcesses] = isAllocated ? startAddress : -1;
            processStates[totalProcesses] = isAllocated ? 1 : 0;
            
            isAllocated ? ++successfulAllocations : ++failedAllocations;

            cout << "Process registered. PID = " << nextPid
                 << (isAllocated ? "; memory allocated.\n" : "; memory allocation FAILED.\n");
                 
            ++nextPid;
            ++totalProcesses;
            continue;
        }

        if (choice == 2) {
            if (!totalProcesses) {
                cout << "No registered processes.\n";
                continue;
            }
            cout << "\nPID\tAT\tBT\tPRI\tMEM\tStatus\tMemStart\n";
            for (int i = 0; i < totalProcesses; ++i) {
                cout << processIds[i] << '\t' << arrivalTimes[i] << '\t' << burstTimes[i] << '\t' << priorities[i]
                     << '\t' << memoryRequirements[i] << '\t';
                printState(processStates[i]);
                cout << '\t' << memoryStartIndices[i] << '\n';
            }
            continue;
        }

        if (choice == 3) {
            int targetPid;
            cout << "Enter PID to search: ";
            cin >> targetPid;
            int index = locateProcess(processIds, totalProcesses, targetPid);
            if (index == -1) {
                cout << "Process with PID " << targetPid << " not found.\n";
                continue;
            }
            cout << "Process Found:\n" << "PID: " << processIds[index] << '\n' << "Arrival Time: " << arrivalTimes[index] << '\n' << "Burst Time: " << burstTimes[index] << '\n' << "Remaining Burst: " << remainingBurstTimes[index] << '\n' << "Priority: " << priorities[index] << '\n' << "Memory Requirement: " << memoryRequirements[index] << '\n' << "Memory Start Index: " << memoryStartIndices[index] << '\n';
            continue;
        }

        if (choice == 4) {
            int targetPid;
            cout << "Enter PID to allocate memory for: ";
            cin >> targetPid;
            int index = locateProcess(processIds, totalProcesses, targetPid);
            if (index == -1) {
                cout << "Process not found.\n";
                continue;
            }
            if (memoryStartIndices[index] != -1) {
                cout << "Process already has memory allocated at index " << memoryStartIndices[index] << ".\n";
                continue;
            }
            int startAddress = -1;
            bool isAllocated = requestMemory(blockStarts, blockSizes, blockOwners, blockCount, memoryRequirements[index], targetPid, startAddress);
            
            isAllocated ? ++successfulAllocations : ++failedAllocations;
            if (isAllocated) {
                memoryStartIndices[index] = startAddress;
                processStates[index] = 1;
                cout << "Memory successfully allocated at index " << startAddress << '.' << '\n';
            } else {
                cout << "Memory allocation failed. Insufficient contiguous free space.\n";
            }
            continue;
        }

        if (choice == 5) {
            int targetPid;
            cout << "PID to terminate: ";
            cin >> targetPid;
            int index = locateProcess(processIds, totalProcesses, targetPid);
            if (index == -1) {
                cout << "Process not found.\n";
                continue;
            }
            if (memoryStartIndices[index] != -1) {
                returnMemory(blockStarts, blockSizes, blockOwners, blockCount, targetPid);
                memoryStartIndices[index] = -1;
            }
            processStates[index] = 4;
            cout << "Process terminated and its memory released.\n";
            continue;
        }

        if (choice == 6) {
            printMemoryMap(blockSizes, blockOwners, blockCount);
            int freeMem = calculateTotalFreeMemory(blockSizes, blockOwners, blockCount);
            cout << "Total Allocated Memory: " << memory_size - freeMem << '\n'
                 << "Total Free Memory: " << freeMem << '\n'
                 << "Largest Contiguous Free Region: " << findLargestFreeBlock(blockSizes, blockOwners, blockCount) << '\n';
            continue;
        }

        if (choice == 7) {
            rebuildMemory(blockStarts, blockSizes, blockOwners, blockCount, processIds, memoryStartIndices, memoryRequirements, totalProcesses);
            cout << "Memory compaction completed successfully.\n" << "Resulting contiguous free space: " << calculateTotalFreeMemory(blockSizes, blockOwners, blockCount) << '\n';
            continue;
        }

        if (choice == 8 or choice == 9) {
            runScheduler(choice - 7, processIds, arrivalTimes, burstTimes, remainingBurstTimes, completionTimes, turnaroundTimes, waitingTimes, processStates, memoryStartIndices, totalProcesses, 0);
            continue;
        }

        if (choice == 10) {
            int timeQuantum = 2;
            cout << "Enter Time Quantum (default 2): ";
            cin >> timeQuantum;
            runScheduler(3, processIds, arrivalTimes, burstTimes, remainingBurstTimes, completionTimes, turnaroundTimes, waitingTimes, processStates, memoryStartIndices, totalProcesses, timeQuantum < 1 ? 2 : timeQuantum);
            continue;
        }

        if (choice == 11) {
            int completedCount = 0, readyCount = 0, runningCount = 0;
            for (int i = 0; i < totalProcesses; ++i) {
                completedCount += (processStates[i] == 3);
                readyCount += (processStates[i] == 1);
                runningCount += (processStates[i] == 2);
            }
            int freeMem = calculateTotalFreeMemory(blockSizes, blockOwners, blockCount);
            cout << "\n===== NERV DIAGNOSTICS & STATISTICS =====\n" << "Total registered processes: " << totalProcesses << '\n' << "Number of completed processes: " << completedCount << '\n' << "Number of ready processes: " << readyCount << '\n' << "Number of running processes: " << runningCount << '\n' << "Total memory capacity: 100\n" << "Total allocated memory: " << memory_size - freeMem << '\n' << "Total free memory: " << freeMem << '\n' << "Largest contiguous free memory region: " << findLargestFreeBlock(blockSizes, blockOwners, blockCount) << '\n' << "Successful memory allocation requests: " << successfulAllocations << '\n' << "Failed memory allocation requests: " << failedAllocations << '\n';
            continue;
        }

        if (choice == 12) {
            int targetStatus;
            cout << "Enter status to filter by (0: New, 1: Ready, 2: Running, 3: Completed, 4: Terminated): ";
            cin >> targetStatus;
            if (targetStatus < 0 or targetStatus > 4) {
                cout << "Invalid status code.\n";
                continue;
            }
            cout << "\nProcesses with status ";
            printState(targetStatus);
            cout << ":\nPID\tAT\tBT\tPRI\tMEM\n";
            bool found = false;
            for (int i = 0; i < totalProcesses; ++i) {
                if (processStates[i] == targetStatus) {
                    cout << processIds[i] << '\t' << arrivalTimes[i] << '\t' << burstTimes[i] << '\t' << priorities[i] << '\t' << memoryRequirements[i] << '\n';
                    found = true;
                }
            }
            if (!found) cout << "None found.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Exiting NERV OS Recovery System. Good luck against the next Angel!\n";
            break;
        }

        cout << "Invalid choice. Please try again.\n";
    }

    return 0;
}

// ===================== Question 7 =====================

void initBoard(char board[6][7]) {
    for (int row = 0; row < 6; ++row)
        for (int col = 0; col < 7; ++col)
            board[row][col] = '.';
}

void printBoard(char board[6][7]) {
    cout << "\n";

    for (int row = 0; row < 6; ++row) {
        putColor(C_BLUE);
        cout << "|";
        putColor(C_RESET);
        cout << " ";
        for (int col = 0; col < 7; ++col) {
            char currentCell = board[row][col];
            if (currentCell == 'X') {
                putColor(C_RED);
                cout << "X ";
                putColor(C_RESET);
            } else if (currentCell == 'O') {
                putColor(C_YELLOW);
                cout << "O ";
                putColor(C_RESET);
            } else {
                putColor(C_DIM);
                cout << ". ";
                putColor(C_RESET);
            }
        }
        putColor(C_BLUE);
        cout << "|";
        putColor(C_RESET);
        cout << "\n";
    }

    putColor(C_BLUE);
    cout << "+---------------+";
    putColor(C_RESET);
    cout << "\n  ";

    for (int col = 0; col < 7; ++col)
        cout << col << " ";
    cout << '\n' << '\n';
}

int updateColumn(char board[6][7], int column, char mark) {

    if (column < 0 or column > 6)
        return -1;
 
    bool isRemoval = (mark == '.');

    for (int row = (isRemoval ? 0 : 5); (isRemoval ? row < 6 : row >= 0); (isRemoval ? ++row : --row)) {
        if ((isRemoval and board[row][column] != '.') or (!isRemoval and board[row][column] == '.')) {
            board[row][column] = mark;
            return row;
        }
    }

    return -1;
}

bool isBoardFull(char board[6][7]) {
    for (int col = 0; col < 7; ++col) {
        if (board[0][col] == '.')
            return false;
    }

    return true;
}

bool checkWin(char board[6][7], char player) {

    for (int row = 0; row < 6; ++row)
        for (int col = 0; col < 4; ++col)
            if (board[row][col] == player and board[row][col+1] == player and board[row][col+2] == player and board[row][col+3] == player)
                return true;

    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 7; ++col)
            if (board[row][col] == player and board[row+1][col] == player and board[row+2][col] == player and board[row+3][col] == player)
                return true;

    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 4; ++col)
            if (board[row][col] == player and board[row+1][col+1] == player and board[row+2][col+2] == player and board[row+3][col+3] == player)
                return true;

    for (int row = 3; row < 6; ++row)
        for (int col = 0; col < 4; ++col)
            if (board[row][col] == player and board[row-1][col+1] == player and board[row-2][col+2] == player and board[row-3][col+3] == player)
                return true;

    return false;
}

int evaluateWindow(int computerCount, int player_count, int empty_count) {
    return (computerCount == 3 and empty_count == 1) ? 5 : ((computerCount == 2 and empty_count == 2) ? 2 : ((player_count == 3 and empty_count == 1) ? -4 : 0));
}


int evaluateBoard(char board[6][7]) {
    int total_score = 0;

    int computer_count, player_count, empty_count;
    char cell;

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            computer_count = 0;
            player_count = 0;
            empty_count = 0;

            for (int k = 0; k < 4; ++k) {
                cell = board[row][col + k];

                if (cell == 'O')
                    computer_count++;
                else if (cell == 'X')
                    player_count++;
                else
                    empty_count++;
            }

            total_score += evaluateWindow(
                computer_count, player_count, empty_count
            );
        }
    }

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 7; ++col) {
            computer_count = 0;
            player_count = 0;
            empty_count = 0;

            for (int k = 0; k < 4; ++k) {
                cell = board[row + k][col];

                if (cell == 'O')
                    computer_count++;
                else if (cell == 'X')
                    player_count++;
                else
                    empty_count++;
            }

            total_score += evaluateWindow(
                computer_count, player_count, empty_count
            );
        }
    }

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 4; ++col) {
            computer_count = 0;
            player_count = 0;
            empty_count = 0;

            for (int k = 0; k < 4; ++k) {
                cell = board[row + k][col + k];

                if (cell == 'O')
                    computer_count++;
                else if (cell == 'X')
                    player_count++;
                else
                    empty_count++;
            }

            total_score += evaluateWindow(
                computer_count, player_count, empty_count
            );
        }
    }

    for (int row = 3; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            computer_count = 0;
            player_count = 0;
            empty_count = 0;

            for (int k = 0; k < 4; ++k) {
                cell = board[row - k][col + k];

                if (cell == 'O')
                    computer_count++;
                else if (cell == 'X')
                    player_count++;
                else
                    empty_count++;
            }

            total_score += evaluateWindow(
                computer_count, player_count, empty_count
            );
        }
    }

    for (int row = 0; row < 6; ++row) {
        if (board[row][3] == 'O')
            total_score += 3;
    }
    return total_score;
}


int minimax(char board[6][7], int ply, int L, int U) {
    if (ply > 3)
        return evaluateBoard(board);

    int column_order[7] = {3, 2, 4, 1, 5, 0, 6};

    for (int i = 0; i < 7; ++i) {
        int column = column_order[i];
        int row = updateColumn(board, column, (ply % 2 != 0) ? 'O' : 'X');

        if (row == -1)
            continue;

        int score = 0;

        if (ply == 1 and checkWin(board, 'O'))
            score = 100002;
        else if (ply == 2 and checkWin(board, 'X'))
            score = -100001;
        else if (ply == 3 and checkWin(board, 'O'))
            score = 100000;
        else if (isBoardFull(board))
            score = 0;
        else if (ply == 3)
            score = evaluateBoard(board);
        else
            score = minimax(board, ply + 1, L, U);

        updateColumn(board, column, '.');

        if (ply == 1 or ply == 3) {
            if (score > L)
                L = score;
        } else {
            if (score < U)
                U = score;
        }

        if (L >= U)
            break;
    }

    return (ply == 1 or ply == 3) ? L : U;
}

int getComputerMove(char board[6][7]) {
    int best_column = -1;
    int best_score = -2000000;
    int L = -1000000;
    int U = 1000000;
    int column_order[7] = {3, 2, 4, 1, 5, 0, 6};

    for (int i = 0; i < 7; ++i) {
        int column = column_order[i];
        int row = updateColumn(board, column, 'O');

        if (row == -1)
            continue;

        int score = checkWin(board, 'O') ? 100002 : minimax(board, 2, L, U);

        updateColumn(board, column, '.');

        if (best_column == -1 or score > best_score) {
            best_score = score;
            best_column = column;
        }

        if (score > L)
            L = score;

        if (L >= U)
            break;
    }

    return best_column;
}

int runQ7() {

    char board[6][7];
    initBoard(board);
    printBoard(board);

    while (true) {
  
        int user_column = -1;

        while (true) {
            cout << "\033[1;32mYour turn (Player X) - Enter column (0-6): \033[0m";
            cin >> user_column;

            if (cin.fail() or user_column < 0 or user_column > 6) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\033[1;31mInvalid input! Enter a valid column number between 0 and 6.\033[0m\n";
                continue;
            }

            int row = updateColumn(board, user_column, 'X');
            if (row == -1) {
                cout << "\033[1;31mColumn is full! Choose another column.\033[0m\n";
                continue;
            }

            break;
        }

        printBoard(board);

        if (checkWin(board, 'X')) {
            cout << "\033[1;32m🎉 Congratulations! You (X) won the game!$\rightarrow$ 👑🏆🗿 Bro actually cooked the AI!\033[0m\n";
            break;
        }

        if (isBoardFull(board)) {
            cout << "\033[1;33m🤝 It's a draw! Board is full.$\rightarrow$ 🥱Absolute Stalemate\033[0m\n";
            break;
        }

        cout << "\033[1;35mComputer (O) is calculating best move (3-ply search)...\033[0m\n";

        int computer_column = getComputerMove(board);

        if (computer_column == -1) {
            cout << "\033[1;33m🤝 It's a draw! No valid moves left.$\rightarrow$ 🥱Absolute Stalemate\033[0m\n";
            break;
        }

        updateColumn(board, computer_column, 'O');

        cout << "\033[1;35mComputer (O) placed mark in column: "
             << computer_column << "\033[0m\n";

        printBoard(board);

        if (checkWin(board, 'O')) {
            cout << "\033[1;31m💔 Computer (O) won the game! 🤡📉 Bro got checkmated by a toaster!\033[0m\n";
            break;
        }

        if (isBoardFull(board)) {
            cout << "\033[1;33m🤝 It's a draw! Board is full.$\rightarrow$ 🥱Absolute Stalemate\033[0m\n";
            break;
        }
    }

    return 0;
}

// ===================== Question 8 =====================

int slotFor(int world_base, int col)
{
    return (world_base + col) % 114;
}

int rockWidth(int kind)
{
    return (kind == 1) ? 6 : 8;
}

int rockHeight(int kind)
{
    return (kind == 1) ? 2 : 4;
}

char birdGlyph(int facing_right, int wing_state, int row, int col)
{
    const char upRight[2][11] = {"   |\\", "~==|_ \\o=>"};
    const char downRight[2][11] = {"~==|-/o=>", "    |/"};
    const char upLeft[2][11] = {"   /|", "<=o/_|==~"};
    const char downLeft[2][11] = {"<=o|-\\==~", "   \\|"};
    if (facing_right == 1)
    {
        if (wing_state == 0)
        {
            return upRight[row][col];
        }
        return downRight[row][col];
    }
    if (wing_state == 0)
    {
        return upLeft[row][col];
    }
    return downLeft[row][col];
}

char rockGlyph(int kind, int row, int col)
{
    const char smallRock[2][8] = {" .---.", "(#####)"};
    const char largeRock[4][9] = {"  ___   ", " _/##\\_ ", "(######)", " `----' "};
    if (kind == 1)
    {
        return smallRock[row][col];
    }
    if (kind == 2)
    {
        return largeRock[row][col];
    }
    return ' ';
}

void formatFive(int value, char buf[])
{
    buf[5] = '\0';
    for (int i = 4; i >= 0; --i)
    {
        buf[i] = (value % 10) + '0';
        value = value / 10;
    }
}

void resetWorld(int cave_center[], int cave_gap[], int &world_base, int &bird_row, int &facing_right,
                int &distance, int &game_state, int &frame_num, int &corridor_kind, int &corridor_dir,
                int &corridor_left, int &pending_kind, int &pending_top, int &pending_index, int &rock_count)
{
    bird_row = 14;
    facing_right = 1;
    distance = 0;
    game_state = 0;
    frame_num = 0;
    world_base = 0;
    corridor_kind = 0;
    corridor_dir = 0;
    corridor_left = 10;
    pending_kind = 0;
    pending_top = 0;
    pending_index = -1;
    rock_count = 0;
    for (int i = 0; i < 114; ++i)
    {
        cave_center[i] = 15;
        cave_gap[i] = 20;
    }
}

void moveRocks(int rock_kind[], int rock_top[], int rock_anchor[], int rock_lo[], int rock_hi[],
               int rock_flip[], int &rock_count, int facing_right, int &pending_index)
{
    int step = (facing_right == 1) ? -1 : 1;
    int i = 0;
    while (i < rock_count)
    {
        rock_anchor[i] = rock_anchor[i] + step;
        if (rock_flip[i] == 0)
        {
            while (rock_hi[i] >= rock_lo[i] and rock_anchor[i] + rock_hi[i] > 113)
            {
                rock_hi[i] = rock_hi[i] - 1;
            }
            while (rock_lo[i] <= rock_hi[i] and rock_anchor[i] + rock_lo[i] < 0)
            {
                rock_lo[i] = rock_lo[i] + 1;
            }
        }
        else
        {
            while (rock_hi[i] >= rock_lo[i] and rock_anchor[i] - rock_hi[i] < 0)
            {
                rock_hi[i] = rock_hi[i] - 1;
            }
            while (rock_lo[i] <= rock_hi[i] and rock_anchor[i] - rock_lo[i] > 113)
            {
                rock_lo[i] = rock_lo[i] + 1;
            }
        }
        if (rock_lo[i] > rock_hi[i])
        {
            int last = rock_count - 1;
            if (pending_index == last)
            {
                pending_index = i;
            }
            rock_kind[i] = rock_kind[last];
            rock_top[i] = rock_top[last];
            rock_anchor[i] = rock_anchor[last];
            rock_lo[i] = rock_lo[last];
            rock_hi[i] = rock_hi[last];
            rock_flip[i] = rock_flip[last];
            rock_count = last;
            if (pending_index >= rock_count)
            {
                pending_index = -1;
            }
        }
        else
        {
            i = i + 1;
        }
    }
}

void generateColumn(int cave_center[], int cave_gap[], int world_base, int new_col, int source_col,
                    int facing_right, int distance, int &corridor_kind, int &corridor_dir, int &corridor_left,
                    int &pending_kind, int &pending_top, int &pending_index,
                    int rock_kind[], int rock_top[], int rock_anchor[], int rock_lo[], int rock_hi[],
                    int rock_flip[], int &rock_count)
{
    int source_slot = slotFor(world_base, source_col);
    int new_slot = slotFor(world_base, new_col);
    int old_top = cave_center[source_slot] - cave_gap[source_slot] / 2;
    int old_bottom = old_top + cave_gap[source_slot];

    if (corridor_left <= 0)
    {
        int level = distance / 250;
        int rock_chance = 35 + 5 * level;
        if (rock_chance > 70)
        {
            rock_chance = 70;
        }
        if (distance >= 150 and randomInt(0, 99) < rock_chance)
        {
            corridor_kind = 1;
            corridor_left = 28;
            pending_kind = randomInt(0, 1) + 1;
            int height = rockHeight(pending_kind);
            int top_bound = old_top + 1;
            int bot_bound = old_bottom - 1 - height;
            pending_top = top_bound;
            if (top_bound <= bot_bound)
            {
                pending_top = randomInt(top_bound, bot_bound);
            }
            if (pending_top - old_top < 4 or old_bottom - (pending_top + height) < 4)
            {
                pending_top = old_top + 1;
            }
            pending_index = -1;
        }
        else
        {
            corridor_kind = 0;
            corridor_dir = randomInt(-1, 1);
            corridor_left = randomInt(6, 25);
        }
    }

    if (corridor_kind == 1)
    {
        cave_center[new_slot] = cave_center[source_slot];
        cave_gap[new_slot] = cave_gap[source_slot];
        int wave = 28 - corridor_left;
        int width = rockWidth(pending_kind);
        int rock_start = (28 - width) / 2;
        if (wave >= rock_start and wave < rock_start + width)
        {
            if (wave == rock_start)
            {
                if (rock_count < 128)
                {
                    rock_kind[rock_count] = pending_kind;
                    rock_top[rock_count] = pending_top;
                    rock_anchor[rock_count] = new_col;
                    rock_lo[rock_count] = 0;
                    rock_hi[rock_count] = 0;
                    rock_flip[rock_count] = (facing_right == 1) ? 0 : 1;
                    pending_index = rock_count;
                    rock_count = rock_count + 1;
                }
            }
            else
            {
                if (pending_index >= 0 and pending_index < rock_count and rock_hi[pending_index] < width - 1)
                {
                    rock_hi[pending_index] = rock_hi[pending_index] + 1;
                }
            }
        }
        corridor_left = corridor_left - 1;
    }
    else
    {
        int gap = cave_gap[source_slot];
        int centre = cave_center[source_slot] + corridor_dir;
        int roll = randomInt(0, 99);
        if (roll <= 7)
        {
            gap = gap + 1;
        }
        else
        {
            if (roll <= 15)
            {
                gap = gap - 1;
            }
        }
        int min_gap = 18 - distance / 250;
        if (min_gap < 9)
        {
            min_gap = 9;
        }
        if (gap < min_gap)
        {
            gap = min_gap;
        }
        if (gap > min_gap + 4)
        {
            gap = min_gap + 4;
        }
        int top = centre - gap / 2;
        if (top < 1)
        {
            top = 1;
            corridor_dir = 0;
        }
        if (top + gap > 29)
        {
            top = 29 - gap;
            corridor_dir = 0;
        }
        cave_center[new_slot] = top + gap / 2;
        cave_gap[new_slot] = gap;
        corridor_left = corridor_left - 1;
    }
}

void scrollWorld(int cave_center[], int cave_gap[], int &world_base, int facing_right, int distance,
                 int rock_kind[], int rock_top[], int rock_anchor[], int rock_lo[], int rock_hi[],
                 int rock_flip[], int &rock_count, int &corridor_kind, int &corridor_dir, int &corridor_left,
                 int &pending_kind, int &pending_top, int &pending_index)
{
    moveRocks(rock_kind, rock_top, rock_anchor, rock_lo, rock_hi, rock_flip, rock_count, facing_right, pending_index);
    if (facing_right == 1)
    {
        world_base = (world_base + 1) % 114;
        generateColumn(cave_center, cave_gap, world_base, 113, 112, facing_right, distance,
                       corridor_kind, corridor_dir, corridor_left, pending_kind, pending_top, pending_index,
                       rock_kind, rock_top, rock_anchor, rock_lo, rock_hi, rock_flip, rock_count);
    }
    else
    {
        world_base = (world_base + 113) % 114;
        generateColumn(cave_center, cave_gap, world_base, 0, 1, facing_right, distance,
                       corridor_kind, corridor_dir, corridor_left, pending_kind, pending_top, pending_index,
                       rock_kind, rock_top, rock_anchor, rock_lo, rock_hi, rock_flip, rock_count);
    }
}

bool solidAt(const int cave_center[], const int cave_gap[], int world_base,
             const int rock_kind[], const int rock_top[], const int rock_anchor[], const int rock_lo[],
             const int rock_hi[], const int rock_flip[], int rock_count, int row, int col)
{
    if (row < 0 or row > 29 or col < 0 or col > 113)
    {
        return true;
    }
    int slot = slotFor(world_base, col);
    int top = cave_center[slot] - cave_gap[slot] / 2;
    int bottom = top + cave_gap[slot];
    if (row <= top or row >= bottom)
    {
        return true;
    }
    for (int i = 0; i < rock_count; ++i)
    {
        int art_col;
        if (rock_flip[i] == 0)
        {
            art_col = col - rock_anchor[i];
        }
        else
        {
            art_col = rock_anchor[i] - col;
        }
        if (art_col < rock_lo[i] or art_col > rock_hi[i])
        {
            continue;
        }
        int kind = rock_kind[i];
        int height = rockHeight(kind);
        if (row >= rock_top[i] and row < rock_top[i] + height)
        {
            char ch = rockGlyph(kind, row - rock_top[i], art_col);
            if (ch != ' ')
            {
                return true;
            }
        }
    }
    return false;
}

bool checkCrash(const int cave_center[], const int cave_gap[], int world_base,
                const int rock_kind[], const int rock_top[], const int rock_anchor[], const int rock_lo[],
                const int rock_hi[], const int rock_flip[], int rock_count, int bird_row, int facing_right,
                int wing_state)
{
    for (int r = 0; r < 2; ++r)
    {
        for (int c = 0; c < 10; ++c)
        {
            char ch = birdGlyph(facing_right, wing_state, r, c);
            if (ch == ' ' or ch == '\0')
            {
                continue;
            }
            if (solidAt(cave_center, cave_gap, world_base, rock_kind, rock_top, rock_anchor,
                        rock_lo, rock_hi, rock_flip, rock_count, bird_row + r, 53 + c))
            {
                return true;
            }
        }
    }
    return false;
}

void drawWorld(const int cave_center[], const int cave_gap[], int world_base,
               const int rock_kind[], const int rock_top[], const int rock_anchor[], const int rock_lo[],
               const int rock_hi[], const int rock_flip[], int rock_count, int bird_row, int facing_right,
               int wing_state, int distance, int best_dist, int game_state)
{
    cursorHome();

    char grid[30][114];

    for (int col = 0; col < 114; ++col)
    {
        int slot = slotFor(world_base, col);
        int top = cave_center[slot] - cave_gap[slot] / 2;
        int bottom = top + cave_gap[slot];
        for (int row = 0; row < 30; ++row)
        {
            if (row <= top or row >= bottom)
            {
                grid[row][col] = '#';
            }
            else
            {
                grid[row][col] = ' ';
            }
        }
    }

    for (int i = 0; i < rock_count; ++i)
    {
        int kind = rock_kind[i];
        int height = rockHeight(kind);
        for (int a = rock_lo[i]; a <= rock_hi[i]; ++a)
        {
            int col;
            if (rock_flip[i] == 0)
            {
                col = rock_anchor[i] + a;
            }
            else
            {
                col = rock_anchor[i] - a;
            }
            if (col < 0 or col > 113)
            {
                continue;
            }
            for (int r = 0; r < height; ++r)
            {
                int row = rock_top[i] + r;
                if (row < 0 or row > 29)
                {
                    continue;
                }
                char ch = rockGlyph(kind, r, a);
                if (ch != ' ')
                {
                    grid[row][col] = ch;
                }
            }
        }
    }

    for (int r = 0; r < 2; ++r)
    {
        for (int c = 0; c < 10; ++c)
        {
            char ch = birdGlyph(facing_right, wing_state, r, c);
            if (ch == ' ' or ch == '\0')
            {
                continue;
            }
            int row = bird_row + r;
            int col = 53 + c;
            if (row >= 0 and row <= 29 and col >= 0 and col <= 113)
            {
                grid[row][col] = ch;
            }
        }
    }

    char edge[117];
    for (int x = 0; x < 116; ++x)
    {
        edge[x] = '-';
    }
    edge[0] = '+';
    edge[115] = '+';
    edge[116] = '\0';

    char line[117];
    line[0] = '|';
    line[115] = '|';
    line[116] = '\0';

    cout << edge << "\n";
    for (int row = 0; row < 30; ++row)
    {
        for (int col = 0; col < 114; ++col)
        {
            line[col + 1] = grid[row][col];
        }
        cout << line << "\n";
    }
    cout << edge << "\n";

    char dist_buf[6];
    char best_buf[6];
    formatFive(distance, dist_buf);
    formatFive(best_dist, best_buf);

    int wait_ms = 70 - distance / 40;
    if (wait_ms < 30)
    {
        wait_ms = 30;
    }
    int drop_ms = 70 - wait_ms;
    int gt_count = drop_ms / 4;
    if (gt_count > 10)
    {
        gt_count = 10;
    }

    cout << "DIST " << dist_buf << " BEST " << best_buf << " SPEED ";
    for (int i = 0; i < 10; ++i)
    {
        if (i < gt_count)
        {
            cout << '>';
        }
        else
        {
            cout << '-';
        }
    }
    cout << " FLYING ";
    if (facing_right == 1)
    {
        cout << ">>";
    }
    else
    {
        cout << "<<";
    }
    cout << "       \n";

    if (game_state == 0)
    {
        cout << "\r[PTERO] fly the cave. touch nothing. press any key to start.      \n";
    }
    else
    {
        if (game_state == 2)
        {
            cout << "\rSPLATTERED: distance " << distance << " best " << best_dist << " [r] fly again [q] quit\n";
        }
    }
}

int runQ8()
{
    termInit();

    int cave_center[114];
    int cave_gap[114];

    int rock_kind[128] = {0};
    int rock_top[128] = {0};
    int rock_anchor[128] = {0};
    int rock_lo[128] = {0};
    int rock_hi[128] = {0};
    int rock_flip[128] = {0};
    int rock_count = 0;

    int world_base = 0;
    int corridor_kind = 0;
    int corridor_dir = 0;
    int corridor_left = 0;
    int pending_kind = 0;
    int pending_top = 0;
    int pending_index = -1;

    int bird_row = 14;
    int facing_right = 1;
    int distance = 0;
    int best_dist = 0;
    int game_state = 0;
    int frame_num = 0;

    resetWorld(cave_center, cave_gap, world_base, bird_row, facing_right, distance, game_state,
               frame_num, corridor_kind, corridor_dir, corridor_left, pending_kind, pending_top,
               pending_index, rock_count);

    while (true)
    {
        if (game_state == 0)
        {
            int wing_state = (frame_num / 3) % 2;
            drawWorld(cave_center, cave_gap, world_base, rock_kind, rock_top, rock_anchor, rock_lo,
                      rock_hi, rock_flip, rock_count, bird_row, facing_right, wing_state, distance, best_dist, game_state);
            if (keyPressed())
            {
                int key = termReadKey();
                if (key == 'q' or key == 'Q')
                {
                    termRestore();
                    return 0;
                }
                game_state = 1;
            }
            sleepMs(50);
            frame_num = frame_num + 1;
            continue;
        }

        if (game_state == 1)
        {
            while (keyPressed())
            {
                int key = termReadKey();
                if (key == 'q' or key == 'Q')
                {
                    termRestore();
                    return 0;
                }
                if (key == 'w' or key == 'W' or key == KEY_ARROW_UP)
                {
                    if (bird_row > 0)
                    {
                        bird_row = bird_row - 1;
                    }
                }
                if (key == 's' or key == 'S' or key == KEY_ARROW_DOWN)
                {
                    if (bird_row < 28)
                    {
                        bird_row = bird_row + 1;
                    }
                }
                if (key == 'a' or key == 'A' or key == KEY_ARROW_LEFT)
                {
                    if (facing_right == 1)
                    {
                        facing_right = 0;
                        corridor_kind = 0;
                        corridor_dir = 0;
                        corridor_left = 10;
                        pending_kind = 0;
                        pending_index = -1;
                    }
                }
                if (key == 'd' or key == 'D' or key == KEY_ARROW_RIGHT)
                {
                    if (facing_right == 0)
                    {
                        facing_right = 1;
                        corridor_kind = 0;
                        corridor_dir = 0;
                        corridor_left = 10;
                        pending_kind = 0;
                        pending_index = -1;
                    }
                }
            }

            distance = distance + 1;
            if (distance > best_dist)
            {
                best_dist = distance;
            }

            scrollWorld(cave_center, cave_gap, world_base, facing_right, distance, rock_kind, rock_top,
                        rock_anchor, rock_lo, rock_hi, rock_flip, rock_count, corridor_kind, corridor_dir,
                        corridor_left, pending_kind, pending_top, pending_index);

            int wing_state = (frame_num / 3) % 2;
            if (checkCrash(cave_center, cave_gap, world_base, rock_kind, rock_top, rock_anchor, rock_lo,
                           rock_hi, rock_flip, rock_count, bird_row, facing_right, wing_state))
            {
                game_state = 2;
                flushKeys();
            }

            drawWorld(cave_center, cave_gap, world_base, rock_kind, rock_top, rock_anchor, rock_lo,
                      rock_hi, rock_flip, rock_count, bird_row, facing_right, wing_state, distance, best_dist, game_state);

            int wait_ms = 70 - distance / 40;
            if (wait_ms < 30)
            {
                wait_ms = 30;
            }
            sleepMs(wait_ms);
            frame_num = frame_num + 1;
        }
        else
        {
            if (game_state == 2)
            {
                int wing_state = (frame_num / 3) % 2;
                drawWorld(cave_center, cave_gap, world_base, rock_kind, rock_top, rock_anchor, rock_lo,
                          rock_hi, rock_flip, rock_count, bird_row, facing_right, wing_state, distance, best_dist, game_state);
                if (keyPressed())
                {
                    int key = termReadKey();
                    if (key == 'q' or key == 'Q')
                    {
                        termRestore();
                        return 0;
                    }
                    if (key == 'r' or key == 'R' or key == ' ')
                    {
                        resetWorld(cave_center, cave_gap, world_base, bird_row, facing_right, distance,
                                   game_state, frame_num, corridor_kind, corridor_dir, corridor_left,
                                   pending_kind, pending_top, pending_index, rock_count);
                        game_state = 1;
                    }
                }
                sleepMs(50);
            }
        }
    }

    termRestore();
    return 0;
}

// ===================== Question 9 =====================

typedef long long LongLong;

const int MAX_ROWS = 51, MAX_COLS = 26, VISIBLE_ROWS = 27, SCREEN_WIDTH = 116, MAX_STRING_SIZE = 2048;
const int t_empty = 0, t_num = 1, t_str = 2, t_err = 3, t_range = 4;

char raw_cells[MAX_ROWS][MAX_COLS][64], display_cells[MAX_ROWS][MAX_COLS][MAX_STRING_SIZE], cell_strings[MAX_ROWS][MAX_COLS][MAX_STRING_SIZE];
double cell_numbers[MAX_ROWS][MAX_COLS];
int cell_types[MAX_ROWS][MAX_COLS], visit_state[MAX_ROWS][MAX_COLS], column_widths[MAX_COLS];

// parser state
int token_types[80], token_rows[80], token_columns[80], token_count, token_position;
double token_values[80];
char token_strings[80][MAX_STRING_SIZE];
bool syntax_error;

// string helpers
int stringLength(const char s[]) {
    int length = 0;
    while (s[length] != '\0') length++;
    return length;
}

void stringCopy(char d[], const char s[]) {
    int i = 0;
    while (s[i] != '\0' and i < MAX_STRING_SIZE - 1) { d[i] = s[i]; i++; }
    d[i] = '\0';
}

void stringConcat(char d[], const char s[]) {
    int i = stringLength(d), j = 0;
    while (s[j] != '\0' and i < MAX_STRING_SIZE - 1) d[i++] = s[j++];
    d[i] = '\0';
}

void appendCharacter(char d[], char c) {
    int i = stringLength(d);
    d[i] = i < MAX_STRING_SIZE - 1 ? c : '\0';
    d[i < MAX_STRING_SIZE - 1 ? i + 1 : i] = '\0';
}

int stringCompare(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' and a[i] == b[i]) i++;
    return (unsigned char)a[i] - (unsigned char)b[i];
}

void toUpperCase(char s[]) {
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = (s[i] >= 'a' and s[i] <= 'z') ? char(s[i] - 32) : s[i];
}

void longLongToString(LongLong input_value, char screen_buffer[]) {
    int i = 0;
    bool is_negative = input_value < 0;
    LongLong current_value = is_negative ? -input_value : input_value;
    screen_buffer[i] = current_value == 0 ? '0' : '\0';
    i += current_value == 0 ? 1 : 0;
    while (current_value > 0) { screen_buffer[i++] = char('0' + (current_value % 10)); current_value /= 10; }
    screen_buffer[i] = is_negative ? '-' : '\0';
    i += is_negative ? 1 : 0;
    screen_buffer[i] = '\0';
    for (int l = 0, r = i - 1; l < r; l++, r--) {
        char temporary = screen_buffer[l]; screen_buffer[l] = screen_buffer[r]; screen_buffer[r] = temporary;
    }
}

void getCellAddress(int r, int c, char screen_buffer[]) {
    screen_buffer[0] = char('A' + c);
    longLongToString(r, screen_buffer + 1);
}

// math helpers
double doubleAbs(double input_value) {
    return input_value < 0.0 ? -input_value : input_value;
}

double doubleFloor(double input_value) {
    if (input_value >= 9e18 or input_value <= -9e18) return input_value;
    LongLong i = (LongLong)input_value;
    double d = (double)i;
    return (input_value < 0.0 and d != input_value) ? d - 1.0 : d;
}

double roundDecimal(double input_value, int decimal_places) {
    if (doubleAbs(input_value) >= 1e15) return input_value;
    bool is_negative = input_value < 0.0;
    double absolute_value = is_negative ? -input_value : input_value, power = 1.0;
    for (int i = 0; i < decimal_places; i++) power *= 10.0;
    LongLong integer_part = (LongLong)absolute_value;
    double fractional_part = absolute_value - (double)integer_part;
    LongLong fractional_remainder = (LongLong)(fractional_part * power + 0.5 + 1e-9), left_padding = (LongLong)power;
    integer_part += fractional_remainder >= left_padding ? 1 : 0;
    fractional_remainder -= fractional_remainder >= left_padding ? left_padding : 0;
    double result = (double)integer_part + (double)fractional_remainder / power;
    return is_negative ? -result : result;
}

double calculateSquareRoot(double input_value) {
    if (input_value <= 0.0) return 0.0;
    double r = input_value > 1.0 ? input_value : 1.0;
    for (int i = 0; i < 64; i++) r = 0.5 * (r + input_value / r);
    return r;
}

void formatNumber(double input_value, char screen_buffer[]) {
    if (input_value != input_value or doubleAbs(input_value) >= 1e15) { stringCopy(screen_buffer, "#NUM!"); return; }
    bool is_negative = input_value < 0.0;
    double absolute_value = is_negative ? -input_value : input_value;
    LongLong integer_part = (LongLong)absolute_value;
    LongLong fractional_remainder = (LongLong)((absolute_value - (double)integer_part) * 10000.0 + 0.5 + 1e-9);
    integer_part += fractional_remainder >= 10000 ? 1 : 0;
    fractional_remainder -= fractional_remainder >= 10000 ? 10000 : 0;
    if (integer_part >= 1000000000000000LL) { stringCopy(screen_buffer, "#NUM!"); return; }
    if (integer_part == 0 and fractional_remainder == 0) { stringCopy(screen_buffer, "0"); return; }
    screen_buffer[0] = '\0';
    if (is_negative) appendCharacter(screen_buffer, '-');
    char temporary_buffer[32];
    longLongToString(integer_part, temporary_buffer);
    stringConcat(screen_buffer, temporary_buffer);
    if (fractional_remainder > 0) {
        appendCharacter(screen_buffer, '.');
        char fraction_digits[5];
        fraction_digits[0] = char('0' + (fractional_remainder / 1000) % 10);
        fraction_digits[1] = char('0' + (fractional_remainder / 100) % 10);
        fraction_digits[2] = char('0' + (fractional_remainder / 10) % 10);
        fraction_digits[3] = char('0' + fractional_remainder % 10);
        fraction_digits[4] = '\0';
        int k = 3;
        while (k >= 0 and fraction_digits[k] == '0') fraction_digits[k--] = '\0';
        stringConcat(screen_buffer, fraction_digits);
    }
}

bool parseLiteralNumber(const char s[], double &screen_buffer) {
    int length = stringLength(s), i = (length > 0 and s[0] == '-') ? 1 : 0;
    if (i >= length or s[i] < '0' or s[i] > '9') return false;
    double current_value = 0.0;
    while (i < length and s[i] >= '0' and s[i] <= '9') current_value = current_value * 10.0 + (s[i++] - '0');
    if (i < length) {
        if (s[i++] != '.' or i >= length or s[i] < '0' or s[i] > '9') return false;
        double fraction = 0.1;
        while (i < length and s[i] >= '0' and s[i] <= '9') {
            current_value += (s[i++] - '0') * fraction;
            fraction *= 0.1;
        }
    }
    screen_buffer = (length > 0 and s[0] == '-') ? -current_value : current_value;
    return i == length;
}

// tokenize formula
void addToken(int token_type, double current_value = 0.0, const char s[] = "", int r = -1, int c = -1) {
    token_types[token_count] = token_type;
    token_values[token_count] = current_value;
    stringCopy(token_strings[token_count], s);
    token_rows[token_count] = r;
    token_columns[token_count] = c;
    token_count++;
}

void tokenizeFormula(const char expr[]) {
    token_count = 0;
    int i = 0, length = stringLength(expr);
    while (i < length) {
        char current_char = expr[i];
        if (current_char == ' ' or current_char == '\t') { i++; continue; }
        if (current_char == '"') {
            i++;
            char literal_string[64];
            int k = 0;
            while (i < length and expr[i] != '"' and k < 63) literal_string[k++] = expr[i++];
            literal_string[k] = '\0';
            if (i >= length) { addToken(20); return; }
            i++;
            addToken(2, 0.0, literal_string);
            continue;
        }
        if (current_char >= '0' and current_char <= '9') {
            double current_value = 0.0;
            while (i < length and expr[i] >= '0' and expr[i] <= '9') current_value = current_value * 10.0 + (expr[i++] - '0');
            if (i < length and expr[i] == '.') {
                i++;
                if (i >= length or expr[i] < '0' or expr[i] > '9') { addToken(20); return; }
                double fraction = 0.1;
                while (i < length and expr[i] >= '0' and expr[i] <= '9') { current_value += (expr[i++] - '0') * fraction; fraction *= 0.1; }
                if (i < length and expr[i] == '.') { addToken(20); return; }
            }
            if (i < length and ((expr[i] >= 'A' and expr[i] <= 'Z') or (expr[i] >= 'a' and expr[i] <= 'z'))) {
                addToken(20);
                return;
            }
            addToken(1, current_value);
            continue;
        }
        if ((current_char >= 'A' and current_char <= 'Z') or (current_char >= 'a' and current_char <= 'z')) {
            char column_letters[64], row_digits[64];
            int letter_count = 0, digit_count = 0;
            while (i < length and ((expr[i] >= 'A' and expr[i] <= 'Z') or (expr[i] >= 'a' and expr[i] <= 'z')) and letter_count < 63)
                column_letters[letter_count++] = (expr[i] >= 'a') ? char(expr[i++] - 32) : expr[i++];
            column_letters[letter_count] = '\0';
            while (i < length and expr[i] >= '0' and expr[i] <= '9' and digit_count < 63) row_digits[digit_count++] = expr[i++];
            row_digits[digit_count] = '\0';
            if (i < length and ((expr[i] >= 'A' and expr[i] <= 'Z') or (expr[i] >= 'a' and expr[i] <= 'z'))) {
                while (i < length and ((expr[i] >= 'A' and expr[i] <= 'Z') or (expr[i] >= 'a' and expr[i] <= 'z') or (expr[i] >= '0' and expr[i] <= '9')) and letter_count < 63)
                    column_letters[letter_count++] = expr[i++];
                column_letters[letter_count] = '\0';
                addToken(4, 0.0, column_letters);
            } else if (digit_count > 0) {
                int r = 0;
                for (int k = 0; k < digit_count; k++) r = r < 1000 ? r * 10 + (row_digits[k] - '0') : r;
                bool ok = (letter_count == 1 and r >= 0 and r < MAX_ROWS);
                addToken(3, 0.0, "", ok ? r : -1, ok ? (column_letters[0] - 'A') : -1);
            } else {
                addToken(4, 0.0, column_letters);
            }
            continue;
        }
        if (current_char == '<' and i + 1 < length and expr[i + 1] == '>') { addToken(15); i += 2; continue; }
        if (current_char == '<' and i + 1 < length and expr[i + 1] == '=') { addToken(17); i += 2; continue; }
        if (current_char == '>' and i + 1 < length and expr[i + 1] == '=') { addToken(19); i += 2; continue; }
        int token_type = current_char == '+' ? 5 : current_char == '-' ? 6 : current_char == '*' ? 7 : current_char == '/' ? 8 :
                current_char == '^' ? 9 : current_char == '(' ? 10 : current_char == ')' ? 11 : current_char == ',' ? 12 :
                current_char == ':' ? 13 : current_char == '=' ? 14 : current_char == '<' ? 16 : current_char == '>' ? 18 : 20;
        addToken(token_type);
        i++;
        if (token_type == 20) return;
    }
    addToken(0);
}

// recursive parser
void evaluateCell(int r, int c);
void parseExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column);
void setError(int &value_type, char string_value[], const char msg[]) {
    value_type = t_err;
    stringCopy(string_value, msg);
}

void parsePrimaryExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    is_empty = false;
    string_value[0] = '\0';
    int token_type = token_types[token_position];
    if (token_type == 1) {
        value_type = t_num; numeric_value = token_values[token_position++];
        return;
    }
    if (token_type == 2) {
        value_type = t_str; stringCopy(string_value, token_strings[token_position++]);
        return;
    }
    if (token_type == 10) {
        token_position++;
        parseExpression(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
        if (token_types[token_position] != 11) { syntax_error = true; return; }
        token_position++;
        if (!syntax_only and value_type == t_range) setError(value_type, string_value, "#VALUE!");
        return;
    }
    if (token_type == 3) {
        int ar = token_rows[token_position], ac = token_columns[token_position];
        token_position++;
        if (token_types[token_position] == 13) {
            token_position++;
            if (token_types[token_position] != 3) { syntax_error = true; return; }
            int br = token_rows[token_position], bc = token_columns[token_position];
            token_position++;
            if (syntax_only) return;
            if (ar < 0 or br < 0) { setError(value_type, string_value, "#REF!"); return; }
            value_type = t_range;
            start_row = ar < br ? ar : br; end_row = ar > br ? ar : br;
            start_column = ac < bc ? ac : bc; end_column = ac > bc ? ac : bc;
            return;
        }
        if (syntax_only) return;
        if (ar < 0) { setError(value_type, string_value, "#REF!"); return; }
        evaluateCell(ar, ac);
        int ct = cell_types[ar][ac];
        is_empty = (ct == t_empty);
        value_type = ct == t_empty ? t_num : ct;
        numeric_value = ct == t_empty ? 0.0 : cell_numbers[ar][ac];
        stringCopy(string_value, ct == t_str ? cell_strings[ar][ac] : (ct == t_err ? display_cells[ar][ac] : ""));
        return;
    }
    if (token_type == 4) {
        char function_name[64];
        stringCopy(function_name, token_strings[token_position++]);
        if (token_types[token_position] != 10) {
            if (!syntax_only) setError(value_type, string_value, "#NAME?");
            return;
        }
        token_position++;
        int argument_types[64], argument_start_rows[64], argument_start_columns[64], argument_end_rows[64], argument_end_columns[64], argument_count = 0;
        double argument_numbers[64];
        char argument_strings[64][MAX_STRING_SIZE];
        bool argument_is_empty[64];
        if (token_types[token_position] != 11) {
            while (true) {
                if (argument_count >= 64) { syntax_error = true; return; }
                parseExpression(syntax_only, argument_types[argument_count], argument_numbers[argument_count], argument_strings[argument_count], argument_is_empty[argument_count], argument_start_rows[argument_count], argument_start_columns[argument_count], argument_end_rows[argument_count], argument_end_columns[argument_count]);
                if (syntax_error) return;
                argument_count++;
                if (token_types[token_position] == 12) { token_position++; continue; }
                break;
            }
        }
        if (token_types[token_position] != 11) { syntax_error = true; return; }
        token_position++;
        if (syntax_only) return;
        bool is_aggregate_function = stringCompare(function_name, "SUM") == 0 or stringCompare(function_name, "AVG") == 0 or stringCompare(function_name, "MIN") == 0 or
                      stringCompare(function_name, "MAX") == 0 or stringCompare(function_name, "COUNT") == 0 or stringCompare(function_name, "MEDIAN") == 0;
        if (is_aggregate_function) {
            if (argument_count < 1) { setError(value_type, string_value, "#VALUE!"); return; }
            double numeric_values[2048];
            int number_count = 0;
            for (int i = 0; i < argument_count; i++) {
                if (argument_types[i] == t_err) { setError(value_type, string_value, argument_strings[i]); return; }
                if (argument_types[i] == t_range) {
                    for (int rr = argument_start_rows[i]; rr <= argument_end_rows[i]; rr++) {
                        for (int cc = argument_start_columns[i]; cc <= argument_end_columns[i]; cc++) {
                            evaluateCell(rr, cc);
                            if (cell_types[rr][cc] == t_err) { setError(value_type, string_value, display_cells[rr][cc]); return; }
                            if (cell_types[rr][cc] == t_num) numeric_values[number_count++] = cell_numbers[rr][cc];
                        }
                    }
                } else if (argument_types[i] == t_num and !argument_is_empty[i]) {
                    numeric_values[number_count++] = argument_numbers[i];
                }
            }
            if (stringCompare(function_name, "COUNT") == 0) { value_type = t_num; numeric_value = (double)number_count; return; }
            if (stringCompare(function_name, "SUM") == 0 or stringCompare(function_name, "MIN") == 0 or stringCompare(function_name, "MAX") == 0) {
                if (number_count == 0) { value_type = t_num; numeric_value = 0.0; return; }
                double result = numeric_values[0];
                for (int i = 1; i < number_count; i++)
                    result = stringCompare(function_name, "SUM") == 0 ? result + numeric_values[i] :
                          (stringCompare(function_name, "MIN") == 0 ? (numeric_values[i] < result ? numeric_values[i] : result) : (numeric_values[i] > result ? numeric_values[i] : result));
                value_type = t_num; numeric_value = result; return;
            }
            if (stringCompare(function_name, "AVG") == 0) {
                if (number_count == 0) { setError(value_type, string_value, "#DIV/0!"); return; }
                double s = 0.0;
                for (int i = 0; i < number_count; i++) s += numeric_values[i];
                value_type = t_num; numeric_value = s / (double)number_count; return;
            }
            if (number_count == 0) { setError(value_type, string_value, "#NUM!"); return; }
            for (int i = 1; i < number_count; i++) {
                double key = numeric_values[i];
                int j = i - 1;
                while (j >= 0 and numeric_values[j] > key) { numeric_values[j + 1] = numeric_values[j]; j--; }
                numeric_values[j + 1] = key;
            }
            value_type = t_num;
            numeric_value = (number_count % 2 == 1) ? numeric_values[number_count / 2] : 0.5 * (numeric_values[number_count / 2 - 1] + numeric_values[number_count / 2]);
            return;
        }
        if (stringCompare(function_name, "CONCAT") == 0) {
            if (argument_count < 1) { setError(value_type, string_value, "#VALUE!"); return; }
            string_value[0] = '\0';
            for (int i = 0; i < argument_count; i++) {
                if (argument_types[i] == t_err) { setError(value_type, string_value, argument_strings[i]); return; }
                if (argument_types[i] == t_range) {
                    for (int rr = argument_start_rows[i]; rr <= argument_end_rows[i]; rr++) {
                        for (int cc = argument_start_columns[i]; cc <= argument_end_columns[i]; cc++) {
                            evaluateCell(rr, cc);
                            if (cell_types[rr][cc] == t_err) { setError(value_type, string_value, display_cells[rr][cc]); return; }
                            stringConcat(string_value, display_cells[rr][cc]);
                        }
                    }
                } else if (argument_types[i] == t_str) {
                    stringConcat(string_value, argument_strings[i]);
                } else if (!argument_is_empty[i]) {
                    char formatted_number[32];
                    formatNumber(argument_numbers[i], formatted_number);
                    if (stringCompare(formatted_number, "#NUM!") == 0) { setError(value_type, string_value, formatted_number); return; }
                    stringConcat(string_value, formatted_number);
                }
            }
            value_type = t_str; return;
        }
        if (stringCompare(function_name, "ABS") == 0 or stringCompare(function_name, "SQRT") == 0 or stringCompare(function_name, "LEN") == 0 or stringCompare(function_name, "UPPER") == 0) {
            if (argument_count != 1 or argument_types[0] == t_range) { setError(value_type, string_value, "#VALUE!"); return; }
            if (argument_types[0] == t_err) { setError(value_type, string_value, argument_strings[0]); return; }
            if (stringCompare(function_name, "ABS") == 0 or stringCompare(function_name, "SQRT") == 0) {
                if (argument_types[0] != t_num) { setError(value_type, string_value, "#VALUE!"); return; }
                if (stringCompare(function_name, "SQRT") == 0 and argument_numbers[0] < 0.0) { setError(value_type, string_value, "#NUM!"); return; }
                value_type = t_num; numeric_value = stringCompare(function_name, "ABS") == 0 ? doubleAbs(argument_numbers[0]) : calculateSquareRoot(argument_numbers[0]); return;
            }
            char sh[MAX_STRING_SIZE];
            sh[0] = '\0';
            if (argument_types[0] == t_str) stringCopy(sh, argument_strings[0]);
            else if (!argument_is_empty[0]) formatNumber(argument_numbers[0], sh);
            if (stringCompare(sh, "#NUM!") == 0) { setError(value_type, string_value, sh); return; }
            if (stringCompare(function_name, "LEN") == 0) { value_type = t_num; numeric_value = (double)stringLength(sh); return; }
            toUpperCase(sh);
            value_type = t_str; stringCopy(string_value, sh); return;
        }
        if (stringCompare(function_name, "ROUND") == 0 or stringCompare(function_name, "POW") == 0 or stringCompare(function_name, "MOD") == 0) {
            if (argument_count != 2 or argument_types[0] == t_range or argument_types[1] == t_range) { setError(value_type, string_value, "#VALUE!"); return; }
            if (argument_types[0] == t_err) { setError(value_type, string_value, argument_strings[0]); return; }
            if (argument_types[1] == t_err) { setError(value_type, string_value, argument_strings[1]); return; }
            if (argument_types[0] != t_num or argument_types[1] != t_num) { setError(value_type, string_value, "#VALUE!"); return; }
            if (stringCompare(function_name, "ROUND") == 0) {
                int decimal_places = (int)argument_numbers[1];
                if ((double)decimal_places != argument_numbers[1] or decimal_places < 0 or decimal_places > 9) { setError(value_type, string_value, "#VALUE!"); return; }
                value_type = t_num; numeric_value = roundDecimal(argument_numbers[0], decimal_places); return;
            }
            if (stringCompare(function_name, "MOD") == 0) {
                if (argument_numbers[1] == 0.0) { setError(value_type, string_value, "#DIV/0!"); return; }
                value_type = t_num; numeric_value = argument_numbers[0] - argument_numbers[1] * doubleFloor(argument_numbers[0] / argument_numbers[1]); return;
            }
            LongLong ex = (LongLong)argument_numbers[1];
            if (doubleAbs(argument_numbers[1]) >= 9e18 or (double)ex != argument_numbers[1] or (argument_numbers[0] == 0.0 and ex < 0)) { setError(value_type, string_value, "#NUM!"); return; }
            double result = 1.0, base = argument_numbers[0];
            LongLong power = ex < 0 ? -ex : ex;
            while (power > 0) {
                result *= (power % 2 == 1) ? base : 1.0;
                if (doubleAbs(result) >= 1e15) { setError(value_type, string_value, "#NUM!"); return; }
                power /= 2;
                base *= power > 0 ? base : 1.0;
            }
            value_type = t_num; numeric_value = ex < 0 ? 1.0 / result : result; return;
        }
        if (stringCompare(function_name, "IF") == 0) {
            if (argument_count != 3 or argument_types[0] == t_range or argument_types[1] == t_range or argument_types[2] == t_range) { setError(value_type, string_value, "#VALUE!"); return; }
            if (argument_types[0] == t_err) { setError(value_type, string_value, argument_strings[0]); return; }
            if (argument_types[1] == t_err) { setError(value_type, string_value, argument_strings[1]); return; }
            if (argument_types[2] == t_err) { setError(value_type, string_value, argument_strings[2]); return; }
            if (argument_types[0] != t_num) { setError(value_type, string_value, "#VALUE!"); return; }
            int selected_index = argument_numbers[0] != 0.0 ? 1 : 2;
            value_type = argument_types[selected_index]; numeric_value = argument_numbers[selected_index]; stringCopy(string_value, argument_strings[selected_index]); return;
        }
        setError(value_type, string_value, "#NAME?");
        return;
    }
    syntax_error = true;
}

void parseUnaryExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column);
void parsePowerExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    parsePrimaryExpression(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
    if (syntax_error or token_types[token_position] != 9) return;
    token_position++;
    int right_value_type, right_start_row, right_start_column, right_end_row, right_end_column;
    double right_numeric_value;
    char right_string_value[MAX_STRING_SIZE];
    bool right_is_empty;
    parseUnaryExpression(syntax_only, right_value_type, right_numeric_value, right_string_value, right_is_empty, right_start_row, right_start_column, right_end_row, right_end_column);
    if (syntax_only or syntax_error) return;
    if (value_type == t_range or right_value_type == t_range) { setError(value_type, string_value, "#VALUE!"); return; }
    if (value_type == t_err) return;
    if (right_value_type == t_err) { setError(value_type, string_value, right_string_value); return; }
    if (value_type != t_num or right_value_type != t_num) { setError(value_type, string_value, "#VALUE!"); return; }
    LongLong ex = (LongLong)right_numeric_value;
    if (doubleAbs(right_numeric_value) >= 9e18 or (double)ex != right_numeric_value or (numeric_value == 0.0 and ex < 0)) { setError(value_type, string_value, "#NUM!"); return; }
    double result = 1.0, base = numeric_value;
    LongLong power = ex < 0 ? -ex : ex;
    while (power > 0) {
        result *= (power % 2 == 1) ? base : 1.0;
        if (doubleAbs(result) >= 1e15) { setError(value_type, string_value, "#NUM!"); return; }
        power /= 2;
        base *= power > 0 ? base : 1.0;
    }
    value_type = t_num; numeric_value = ex < 0 ? 1.0 / result : result; is_empty = false;
}

void parseUnaryExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    if (token_types[token_position] == 6) {
        token_position++;
        parseUnaryExpression(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
        if (syntax_only or syntax_error) return;
        if (value_type == t_range) { setError(value_type, string_value, "#VALUE!"); return; }
        if (value_type == t_err) return;
        if (value_type != t_num) { setError(value_type, string_value, "#VALUE!"); return; }
        numeric_value = -numeric_value; is_empty = false;
        return;
    }
    parsePowerExpression(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
}

void parseMultiplicationDivision(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    parseUnaryExpression(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
    while (!syntax_error and (token_types[token_position] == 7 or token_types[token_position] == 8)) {
        int operator_type = token_types[token_position++], right_value_type, right_start_row, right_start_column, right_end_row, right_end_column;
        double right_numeric_value;
        char right_string_value[MAX_STRING_SIZE];
        bool right_is_empty;
        parseUnaryExpression(syntax_only, right_value_type, right_numeric_value, right_string_value, right_is_empty, right_start_row, right_start_column, right_end_row, right_end_column);
        if (syntax_only or syntax_error) continue;
        if (value_type == t_range or right_value_type == t_range) { setError(value_type, string_value, "#VALUE!"); continue; }
        if (value_type == t_err) continue;
        if (right_value_type == t_err) { setError(value_type, string_value, right_string_value); continue; }
        if (value_type != t_num or right_value_type != t_num) { setError(value_type, string_value, "#VALUE!"); continue; }
        if (operator_type == 8 and right_numeric_value == 0.0) { setError(value_type, string_value, "#DIV/0!"); continue; }
        numeric_value = operator_type == 7 ? numeric_value * right_numeric_value : numeric_value / right_numeric_value;
        is_empty = false;
    }
}

void parseAdditionSubtraction(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    parseMultiplicationDivision(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
    while (!syntax_error and (token_types[token_position] == 5 or token_types[token_position] == 6)) {
        int operator_type = token_types[token_position++], right_value_type, right_start_row, right_start_column, right_end_row, right_end_column;
        double right_numeric_value;
        char right_string_value[MAX_STRING_SIZE];
        bool right_is_empty;
        parseMultiplicationDivision(syntax_only, right_value_type, right_numeric_value, right_string_value, right_is_empty, right_start_row, right_start_column, right_end_row, right_end_column);
        if (syntax_only or syntax_error) continue;
        if (value_type == t_range or right_value_type == t_range) { setError(value_type, string_value, "#VALUE!"); continue; }
        if (value_type == t_err) continue;
        if (right_value_type == t_err) { setError(value_type, string_value, right_string_value); continue; }
        if (value_type != t_num or right_value_type != t_num) { setError(value_type, string_value, "#VALUE!"); continue; }
        numeric_value = operator_type == 5 ? numeric_value + right_numeric_value : numeric_value - right_numeric_value;
        is_empty = false;
    }
}

void parseExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    parseAdditionSubtraction(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
    while (!syntax_error and token_types[token_position] >= 14 and token_types[token_position] <= 19) {
        int operator_type = token_types[token_position++], right_value_type, right_start_row, right_start_column, right_end_row, right_end_column;
        double right_numeric_value;
        char right_string_value[MAX_STRING_SIZE];
        bool right_is_empty;
        parseAdditionSubtraction(syntax_only, right_value_type, right_numeric_value, right_string_value, right_is_empty, right_start_row, right_start_column, right_end_row, right_end_column);
        if (syntax_only or syntax_error) continue;
        if (value_type == t_range or right_value_type == t_range) { setError(value_type, string_value, "#VALUE!"); continue; }
        if (value_type == t_err) continue;
        if (right_value_type == t_err) { setError(value_type, string_value, right_string_value); continue; }
        if (value_type != right_value_type) { setError(value_type, string_value, "#VALUE!"); continue; }
        bool comparison = value_type == t_num
            ? (operator_type == 14 ? numeric_value == right_numeric_value : operator_type == 15 ? numeric_value != right_numeric_value : operator_type == 16 ? numeric_value < right_numeric_value : operator_type == 17 ? numeric_value <= right_numeric_value : operator_type == 18 ? numeric_value > right_numeric_value : numeric_value >= right_numeric_value)
            : (operator_type == 14 ? stringCompare(string_value, right_string_value) == 0 : operator_type == 15 ? stringCompare(string_value, right_string_value) != 0 : operator_type == 16 ? stringCompare(string_value, right_string_value) < 0 :
               operator_type == 17 ? stringCompare(string_value, right_string_value) <= 0 : operator_type == 18 ? stringCompare(string_value, right_string_value) > 0 : stringCompare(string_value, right_string_value) >= 0);
        value_type = t_num; numeric_value = comparison ? 1.0 : 0.0; is_empty = false;
    }
}

// evaluate cell
void evaluateCell(int r, int c) {
    if (visit_state[r][c] == 2) return;
    if (visit_state[r][c] == 1) {
        cell_types[r][c] = t_err;
        stringCopy(display_cells[r][c], "#CYCLE!");
        return;
    }
    visit_state[r][c] = 1;
    double current_value = 0.0;
    if (raw_cells[r][c][0] == '\0') {
        cell_types[r][c] = t_empty;
        display_cells[r][c][0] = '\0';
    } else if (raw_cells[r][c][0] == '=') {
        tokenizeFormula(raw_cells[r][c] + 1);
        int value_type = t_err, start_row = 0, start_column = 0, end_row = 0, end_column = 0;
        double numeric_value = 0.0;
        char string_value[MAX_STRING_SIZE];
        string_value[0] = '\0';
        bool is_empty = false;
        syntax_error = (token_count <= 1 or token_types[token_count - 2] == 20);
        token_position = 0;
        if (!syntax_error) parseExpression(true, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
        if (syntax_error or token_position != token_count - 1) {
            cell_types[r][c] = t_err;
            stringCopy(display_cells[r][c], "#SYNTAX!");
        } else {
            token_position = 0;
            parseExpression(false, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
            if (value_type == t_range) {
                cell_types[r][c] = t_err;
                stringCopy(display_cells[r][c], "#VALUE!");
            } else if (value_type == t_err) {
                cell_types[r][c] = t_err;
                stringCopy(display_cells[r][c], string_value);
            } else if (value_type == t_str) {
                cell_types[r][c] = t_str;
                stringCopy(cell_strings[r][c], string_value);
                stringCopy(display_cells[r][c], string_value);
            } else {
                char formatted_number[32];
                formatNumber(numeric_value, formatted_number);
                cell_types[r][c] = stringCompare(formatted_number, "#NUM!") == 0 ? t_err : t_num;
                cell_numbers[r][c] = numeric_value;
                stringCopy(display_cells[r][c], formatted_number);
            }
        }
    } else if (parseLiteralNumber(raw_cells[r][c], current_value)) {
        char formatted_number[32];
        formatNumber(current_value, formatted_number);
        cell_types[r][c] = stringCompare(formatted_number, "#NUM!") == 0 ? t_err : t_num;
        cell_numbers[r][c] = current_value;
        stringCopy(display_cells[r][c], formatted_number);
    } else {
        cell_types[r][c] = t_str;
        stringCopy(cell_strings[r][c], raw_cells[r][c]);
        stringCopy(display_cells[r][c], raw_cells[r][c]);
    }
    visit_state[r][c] = 2;
}

void recalculateAllCells() {
    for (int r = 0; r < MAX_ROWS; r++)
        for (int c = 0; c < MAX_COLS; c++) visit_state[r][c] = 0;
    for (int r = 0; r < MAX_ROWS; r++)
        for (int c = 0; c < MAX_COLS; c++)
            if (visit_state[r][c] == 0) evaluateCell(r, c);
    for (int c = 0; c < MAX_COLS; c++) {
        int w = 8;
        for (int r = 0; r < MAX_ROWS; r++) {
            int ln = stringLength(display_cells[r][c]);
            w = ln > w ? ln : w;
        }
        column_widths[c] = w;
    }
}

int getLastVisibleColumn(int left_visible_column) {
    int used = 6, c = left_visible_column;
    while (c < MAX_COLS and used + column_widths[c] + 3 <= SCREEN_WIDTH) used += column_widths[c++] + 3;
    return c > left_visible_column ? c - 1 : left_visible_column;
}

// render screen
void appendString(char screen_buffer[], int &output_index, const char s[]) {
    for (int i = 0; s[i] != '\0'; i++) screen_buffer[output_index++] = s[i];
}

void appendRepeatedCharacter(char screen_buffer[], int &output_index, char current_char, int cnt) {
    for (int i = 0; i < cnt; i++) screen_buffer[output_index++] = current_char;
}

void renderSpreadsheet(int current_row, int current_column, int &top_visible_row, int &left_visible_column, bool is_editing) {
    top_visible_row = current_row < top_visible_row ? current_row : (current_row >= top_visible_row + VISIBLE_ROWS ? current_row - VISIBLE_ROWS + 1 : top_visible_row);
    left_visible_column = current_column < left_visible_column ? current_column : left_visible_column;
    while (current_column > getLastVisibleColumn(left_visible_column)) left_visible_column++;
    int right_visible_column = getLastVisibleColumn(left_visible_column);
    char table_separator[200], cell_address[8], number_buffer[16], screen_buffer[4800];
    int separator_index = 0, output_index = 0;
    appendString(table_separator, separator_index, "+----+");
    for (int c = left_visible_column; c <= right_visible_column; c++) {
        appendRepeatedCharacter(table_separator, separator_index, '-', column_widths[c] + 2);
        table_separator[separator_index++] = '+';
    }
    table_separator[separator_index] = '\0';
    getCellAddress(current_row, current_column, cell_address);
    appendString(screen_buffer, output_index, cell_address);
    appendString(screen_buffer, output_index, " > ");
    appendString(screen_buffer, output_index, raw_cells[current_row][current_column]);
    screen_buffer[output_index++] = '\n';
    appendString(screen_buffer, output_index, table_separator);
    screen_buffer[output_index++] = '\n';
    appendString(screen_buffer, output_index, "|    |");
    for (int c = left_visible_column; c <= right_visible_column; c++) {
        int left_padding = (column_widths[c] - 1) / 2, right_padding = column_widths[c] - 1 - left_padding;
        screen_buffer[output_index++] = ' ';
        appendRepeatedCharacter(screen_buffer, output_index, ' ', left_padding);
        screen_buffer[output_index++] = char('A' + c);
        appendRepeatedCharacter(screen_buffer, output_index, ' ', right_padding);
        appendString(screen_buffer, output_index, " |");
    }
    screen_buffer[output_index++] = '\n';
    appendString(screen_buffer, output_index, table_separator);
    screen_buffer[output_index++] = '\n';
    for (int r = top_visible_row; r < top_visible_row + VISIBLE_ROWS; r++) {
        appendString(screen_buffer, output_index, r < 10 ? "|  " : "| ");
        longLongToString(r, number_buffer);
        appendString(screen_buffer, output_index, number_buffer);
        appendString(screen_buffer, output_index, " |");
        for (int c = left_visible_column; c <= right_visible_column; c++) {
            int cell_padding = column_widths[c] - stringLength(display_cells[r][c]);
            bool is_selected = (r == current_row and c == current_column);
            screen_buffer[output_index++] = is_selected ? '[' : ' ';
            if (cell_types[r][c] == t_num) {
                appendRepeatedCharacter(screen_buffer, output_index, ' ', cell_padding);
                appendString(screen_buffer, output_index, display_cells[r][c]);
            } else {
                appendString(screen_buffer, output_index, display_cells[r][c]);
                appendRepeatedCharacter(screen_buffer, output_index, ' ', cell_padding);
            }
            screen_buffer[output_index++] = is_selected ? ']' : ' ';
            screen_buffer[output_index++] = '|';
        }
        screen_buffer[output_index++] = '\n';
    }
    appendString(screen_buffer, output_index, table_separator);
    screen_buffer[output_index++] = '\n';
    if (is_editing) {
        appendString(screen_buffer, output_index, cell_address);
        appendString(screen_buffer, output_index, " > ");
    } else {
        appendString(screen_buffer, output_index, "Arrows: move   Enter: edit   Delete: clear   Q: quit");
    }
    screen_buffer[output_index] = '\0';
    clearScreen();
    cout << screen_buffer;
    cout.flush();
}

// main loop
int runQ9() {
    int current_row = 0, current_column = 0, top_visible_row = 0, left_visible_column = 0;
    recalculateAllCells();
    while (true) {
        renderSpreadsheet(current_row, current_column, top_visible_row, left_visible_column, false);
        int pressed_key = readKey();
        if (pressed_key == 'q' or pressed_key == 'Q') return 0;
        current_row = pressed_key == KEY_UP ? (current_row > 0 ? current_row - 1 : 0) : (pressed_key == KEY_DOWN ? (current_row + 1 < MAX_ROWS ? current_row + 1 : MAX_ROWS - 1) : current_row);
        current_column = pressed_key == KEY_LEFT ? (current_column > 0 ? current_column - 1 : 0) : (pressed_key == KEY_RIGHT ? (current_column + 1 < MAX_COLS ? current_column + 1 : MAX_COLS - 1) : current_column);
        if (pressed_key == KEY_DELETE) {
            raw_cells[current_row][current_column][0] = '\0';
            recalculateAllCells();
        } else if (pressed_key == KEY_ENTER) {
            renderSpreadsheet(current_row, current_column, top_visible_row, left_visible_column, true);
            char input_buffer[64], current_char;
            int input_length = 0;
            while (cin.get(current_char) and current_char != '\n')
                if (current_char >= 32 and current_char <= 126 and input_length < 60) input_buffer[input_length++] = current_char;
            input_buffer[input_length] = '\0';
            if (input_length > 0) {
                stringCopy(raw_cells[current_row][current_column], input_buffer);
                recalculateAllCells();
            }
        }
    }
    return 0;
}

// ===================== TUI menu =====================
int main()
{
    int colorChoice = 1;
    cout << "Do you want colors or are you a boring black n white chump?\n" << "1. Yes\n" << "2. No (yes)\n" << "3. No\n" << "Choice: ";
    if (cin >> colorChoice and colorChoice == 3) {
        useColors = false;
    } else {
        cin.clear();
        useColors = true;
    }
    cin.ignore(1000, '\n');

    while (true)
    {
        clearScreen();
        cout << '\n';
        renderBanner("PF Assignment 3 - Question Navigator");
        cout << "  Select a question to display:\n\n";
        cout << "   1. Number Spiral\n";
        cout << "   2. Calendar\n";
        cout << "   3. Diamond Pattern\n";
        cout << "   4. Ripple Pond\n";
        cout << "   5. Lost In The Mine\n";
        cout << "   6. Cruel Angel's Thesis — NERV Systems Recovery Division\n";
        cout << "   7. Connect 4 AI\n";
        cout << "   8. PTERO, the Cave Flyer\n";
        cout << "   9. CELLS, a Terminal Spreadsheet\n\n";
        cout << "  Enter choice (1-9, q to quit): ";

        char selection;
        if (!(cin >> selection))
        {
            break;
        }
        cin.ignore(1000, '\n');

        if (selection == 'q' or selection == 'Q')
        {
            break;
        }
        if (selection < '1' or selection > '9')
        {
            cout << "\n  Invalid choice. Press Enter to continue...";
            cin.get();
            continue;
        }

        int question = selection - '0';

        clearScreen();
        cout << '\n';
        renderBanner("PF Assignment 3 - Question Navigator");
        cout << '\n';

        switch (question)
        {
            case 1: runQ1(); break;
            case 2: runQ2(); break;
            case 3: runQ3(); break;
            case 4: runQ4(); break;
            case 5: runQ5(); break;
            case 6: runQ6(); break;
            case 7: runQ7(); break;
            case 8: runQ8(); break;
            case 9: runQ9(); break;
        }

        char navigation;
        while (true)
        {
            cout << "\n  Press b to go back to the menu or q to quit: ";
            if (!(cin >> navigation))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            cin.ignore(1000, '\n');

            if (navigation == 'b' or navigation == 'B')
            {
                break;
            }
            if (navigation == 'q' or navigation == 'Q')
            {
                return 0;
            }
            cout << "  Invalid key.";
        }
    }

    return 0;
}
