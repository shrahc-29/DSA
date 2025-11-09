#include <iostream>
using namespace std;

// Structure for each Job Node
struct JobNode {
    string jobTitle;
    int jobPriority;
    JobNode* nextNode;
    JobNode* prevNode;
};

// Class for Double-Ended Queue (Deque)
class JobQueue {
    JobNode* frontNode;
    JobNode* rearNode;

public:
    JobQueue() {
        frontNode = rearNode = NULL;
    }

    bool isEmpty() {
        return (frontNode == NULL);
    }

    // Add job (based on priority)
    void addJob(string title, int priority) {
        JobNode* newJob = new JobNode;
        newJob->jobTitle = title;
        newJob->jobPriority = priority;
        newJob->nextNode = NULL;
        newJob->prevNode = NULL;

        if (isEmpty()) {
            frontNode = rearNode = newJob;
        } else {
            JobNode* currentNode = frontNode;
            while (currentNode != NULL && currentNode->jobPriority >= priority)
                currentNode = currentNode->nextNode;

            if (currentNode == frontNode) {
                newJob->nextNode = frontNode;
                frontNode->prevNode = newJob;
                frontNode = newJob;
            }
            else if (currentNode == NULL) {
                rearNode->nextNode = newJob;
                newJob->prevNode = rearNode;
                rearNode = newJob;
            }
            else {
                newJob->nextNode = currentNode;
                newJob->prevNode = currentNode->prevNode;
                currentNode->prevNode->nextNode = newJob;
                currentNode->prevNode = newJob;
            }
        }
        cout << "Job \"" << title << "\" added successfully with priority " << priority << ".\n";
    }

    // Remove job (from front)
    void removeJob() {
        if (isEmpty()) {
            cout << "No jobs in the queue!\n";
            return;
        }

        JobNode* tempNode = frontNode;
        cout << "Job \"" << tempNode->jobTitle << "\" with priority " << tempNode->jobPriority << " removed from queue.\n";

        if (frontNode == rearNode) {
            frontNode = rearNode = NULL;
        } else {
            frontNode = frontNode->nextNode;
            frontNode->prevNode = NULL;
        }
        delete tempNode;
    }

    // Display all jobs
    void displayJobs() {
        if (isEmpty()) {
            cout << "No jobs to display!\n";
            return;
        }

        cout << "\nCurrent Jobs in Queue (Front → Rear):\n";
        JobNode* currentNode = frontNode;
        while (currentNode != NULL) {
            cout << "Job Name: " << currentNode->jobTitle << " | Priority: " << currentNode->jobPriority << endl;
            currentNode = currentNode->nextNode;
        }
    }

    // Search for a job
    void searchJob(string title) {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        JobNode* currentNode = frontNode;
        bool found = false;
        while (currentNode != NULL) {
            if (currentNode->jobTitle == title) {
                cout << "Job found! Name: " << currentNode->jobTitle << " | Priority: " << currentNode->jobPriority << endl;
                found = true;
                break;
            }
            currentNode = currentNode->nextNode;
        }

        if (!found) {
            cout << "Job \"" << title << "\" not found in queue.\n";
        }
    }

    // Clear all jobs
    void clearQueue() {
        while (!isEmpty()) {
            removeJob();
        }
        cout << "All jobs cleared.\n";
    }
};

// Main program
int main() {
    JobQueue jobQueue;
    int userChoice, jobPriority;
    string jobTitle;

    do {
        cout << "\n---- JOB SCHEDULING SYSTEM (Double-Ended Queue) ----\n";
        cout << "1. Add Job\n";
        cout << "2. Remove Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Search Job\n";
        cout << "5. Clear All Jobs\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> userChoice;
        cin.ignore();

        switch (userChoice) {
        case 1:
            cout << "Enter job name: ";
            getline(cin, jobTitle);
            cout << "Enter job priority (higher number = higher priority): ";
            cin >> jobPriority;
            jobQueue.addJob(jobTitle, jobPriority);
            break;

        case 2:
            jobQueue.removeJob();
            break;

        case 3:
            jobQueue.displayJobs();
            break;

        case 4:
            cout << "Enter job name to search: ";
            getline(cin, jobTitle);
            jobQueue.searchJob(jobTitle);
            break;

        case 5:
            jobQueue.clearQueue();
            break;

        case 6:
            cout << "Exiting system. Thank you!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (userChoice != 6);

    return 0;
}

