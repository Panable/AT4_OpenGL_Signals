#include <iostream>
#include <csignal>
#include <unistd.h>

// Signal handler function for ProgramB
void signalHandler(int signum) {
    std::cout << "Signal received by ProgramB: " << signum << std::endl;
}

int main() {
    // Register the signal handler
    signal(SIGUSR1, signalHandler);

    // Get the process ID of ProgramB
    pid_t programB_PID;
    std::cout << "Enter the Process ID of ProgramB: ";
    std::cin >> programB_PID;

    // Send a signal to ProgramB
    if (kill(programB_PID, SIGUSR1) == 0) {
        std::cout << "Signal sent to ProgramB" << std::endl;
    } else {
        std::cerr << "Failed to send signal to ProgramB" << std::endl;
        return 1;
    }

    return 0;
}
