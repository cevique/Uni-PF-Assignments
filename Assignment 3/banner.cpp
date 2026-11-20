#include <iostream>

void renderBanner(const char* subtitle) {
    std::cout << "\033[1;36m";
    std::cout << "  ____    _  _____ _____ _     _____ ____  \n";
    std::cout << " | __ )  / \\|_   _|_   _| |   | ____|  _ \\ \n";
    std::cout << " |  _ \\ / _ \\ | |   | | | |   |  _| | |_) |\n";
    std::cout << " | |_) / ___ \\| |   | | | |___| |___|  _ < \n";
    std::cout << " |____/_/   \\_|_|   |_| |_____|_____|_| \\_\\\n";
    std::cout << "\033[0m";

    std::cout << "\033[1;33m";
    std::cout << "╔══════════════════════════════════════════════════════╗\n";
    std::cout << "║  " << "\033[1;32m" << subtitle;
    
    int len = 0;
    while (subtitle[len] != '\0') ++len;
    for (int i = len; i < 50; ++i) std::cout << " ";
    
    std::cout << "\033[1;33m║\n";
    std::cout << "╚══════════════════════════════════════════════════════╝\n";
    std::cout << "\033[0m\n";
}

int main(){
    renderBanner("FAST-NUCES Islamabad - Connect 4 AI Battler");
    return 0;
}