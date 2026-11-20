#include <iostream>
using namespace std;

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
    cout << (statusCode == 0 ? "New" : statusCode == 1 ? "Ready" : statusCode == 2 ? "Running" : statusCode == 3 ? "Completed" : "Terminated");
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

int main() {

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