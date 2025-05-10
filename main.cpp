#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <cmath>
#include <fstream>
#include <ctime>
#include <stdexcept>
#include <limits>
#include <vector>

// Logger class for error handling and logging
class Logger {
    std::ofstream logFile;
public:
    Logger() {
        logFile.open("program_log.txt", std::ios::app);
        log("Program started");
    }
    ~Logger() {
        log("Program ended");
        logFile.close();
    }
    void log(const std::string& message) {
        time_t now = time(0);
        logFile << ctime(&now) << ": " << message << std::endl;
    }
};

// Global logger instance
Logger logger;

// Color constants
enum Color {
    RED = FOREGROUND_RED | FOREGROUND_INTENSITY,
    GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
};

// Set console text color
void setColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Reset color to default
void resetColor() {
    setColor(WHITE);
}

// UI Helper functions
void displayHeader(const std::string& title) {
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << std::setw(25) << "" << title << "\n";
    std::cout << std::string(50, '=') << "\n";
}

// Input validation template
template<typename T>
T getValidInput(const std::string& prompt, T min, T max) {
    T value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            return value;
        }
        std::cout << "Invalid input! Please try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// New function for program description
void displayProgramDescription() {
    system("cls");
    displayHeader("PROGRAM DESCRIPTION");
    std::cout << "\nThis program provides various mathematical calculations and tools:\n\n"
              << "1. Multiplication Table\n"
              << "   - Generates a multiplication table from 1 to N (max 10)\n"
              << "   - Displays results in an organized grid format\n\n"
              << "2. Function Calculator\n"
              << "   - Calculates y(x) = 3x^2 + 3x - 1\n"
              << "   - Uses formula x = a + i*h for multiple steps\n\n"
              << "3. Average Calculator\n"
              << "   - Calculates average of entered numbers\n"
              << "   - Enter 0 to finish input\n\n"
              << "4. Sum Calculator\n"
              << "   - Calculates special sum series\n"
              << "   - Based on user-provided parameter M\n\n"
              << "5. Hotel Management\n"
              << "   - Tracks hotel room occupancy\n"
              << "   - Calculates occupancy statistics\n\n"
              << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("cls");
}

// New function for "return to menu" prompt
void waitForReturn() {
    std::cout << "\nPress Enter to return to main menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("cls");
}

// Hotel structure
struct Hotel {
    std::string name;
    int floors;
    std::vector<int> roomsPerFloor;
    std::vector<int> occupiedRooms;
};

// Hotel management functions
Hotel inputHotelData() {
    Hotel hotel;
    setColor(YELLOW);
    std::cout << "\nEnter hotel name: ";
    std::cin.ignore();
    std::getline(std::cin, hotel.name);
    
    hotel.floors = getValidInput<int>("Enter number of floors (1-100): ", 1, 100);
    
    hotel.roomsPerFloor.resize(hotel.floors);
    hotel.occupiedRooms.resize(hotel.floors);
    
    for(int i = 0; i < hotel.floors; i++) {
        setColor(GREEN);
        std::cout << "\nFloor " << i + 1 << ":\n";
        hotel.roomsPerFloor[i] = getValidInput<int>("Number of rooms (10-50): ", 10, 50);
        hotel.occupiedRooms[i] = getValidInput<int>("Occupied rooms: ", 0, hotel.roomsPerFloor[i]);
    }
    
    return hotel;
}

void displayHotelStats(const Hotel& hotel) {
    setColor(CYAN);
    int totalRooms = 0;
    int totalOccupied = 0;
    
    for(int i = 0; i < hotel.floors; i++) {
        totalRooms += hotel.roomsPerFloor[i];
        totalOccupied += hotel.occupiedRooms[i];
    }
    
    std::cout << "\nHOTEL STATISTICS\n";
    std::cout << "================\n";
    std::cout << "Hotel Name: " << hotel.name << "\n";
    std::cout << "Total Floors: " << hotel.floors << "\n";
    std::cout << "Total Rooms: " << totalRooms << "\n";
    std::cout << "Occupied Rooms: " << totalOccupied << "\n";
    std::cout << "Vacant Rooms: " << totalRooms - totalOccupied << "\n";
    std::cout << "Occupancy Rate: " << std::fixed << std::setprecision(2) 
              << (static_cast<double>(totalOccupied) / totalRooms * 100) << "%\n";
}

int main() {
    try {
        SetConsoleTitle("Advanced Mathematics Program");
        displayProgramDescription();  // Show description at startup
        
        while (true) {
            setColor(YELLOW);
            displayHeader("MAIN MENU");
            std::cout << "1. Multiplication Table\n"
                     << "2. Function Calculator\n"
                     << "3. Average Calculator\n"
                     << "4. Sum Calculator\n"
                     << "5. Hotel Management\n"
                     << "0. Exit\n";

            int choice = getValidInput<int>("Enter your choice (0-5): ", 0, 5);

            if (choice == 0) break;

            switch (choice) {
                case 1: {
                    setColor(GREEN);
                    displayHeader("MULTIPLICATION TABLE");
                    int n = getValidInput<int>("Enter table size (1-10): ", 1, 10);
                    std::cout << std::endl;

                    for (int a = -1; a <= n; a++) {
                        for (int b = 0; b <= n; b++) {
                            if (a == -1) {
                                if (b == 0)
                                    std::cout << std::setw(4) << " |";
                                else
                                    std::cout << std::setw(4) << b << " ";
                            } else if (a == 0) {
                                std::cout << "_____";
                            } else if (b == 0) {
                                std::cout << std::setw(2) << a << " |";
                            } else {
                                std::cout << std::setw(4) << a * b << " ";
                            }
                        }
                        std::cout << std::endl;
                    }
                    waitForReturn();
                    break;
                }
                case 2: {
                    setColor(CYAN);  // Changed from BLUE to CYAN
                    displayHeader("FUNCTION CALCULATOR");
                    int a = getValidInput<int>("Enter starting point a: ", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                    float h = getValidInput<float>("Enter step h: ", std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
                    int n2 = getValidInput<int>("Enter number of steps n: ", 1, std::numeric_limits<int>::max());

                    float y = 0;
                    double x = 0;

                    std::cout << " " << std::endl;
                    for (int i = 0; i <= n2; i++) {
                        x = a + (i * h);
                        y = (3 * x + (3 * sqrt(x))) - 1;
                        std::cout << "For the i that equals " << i << ", y equals: " << y << std::endl;
                    }
                    if (std::cin.fail()) {
                        throw std::runtime_error("Invalid input detected");
                    }
                    waitForReturn();
                    break;
                }
                case 3: {
                    setColor(GREEN);
                    displayHeader("AVERAGE CALCULATOR");
                    int suma = 0;
                    int liczba = 0;
                    int liczba_elementow = 0;

                    std::cout << "\nEnter whole numbers to calculate the average." << std::endl;
                    std::cout << "By entering 0 you will finish inputting and go to the result." << std::endl;
                    std::cout << "\nEnter the first number: ";
                    std::cin >> liczba;

                    while (liczba != 0) {
                        liczba_elementow += 1;
                        suma += liczba;
                        std::cout << "Enter another number or 0 to go to the result: ";
                        std::cin >> liczba;
                    }
                    if (liczba_elementow == 0) {
                        throw std::runtime_error("No numbers entered for average calculation");
                    }
                    std::cout << "The average of the given numbers is: " << (double)suma / liczba_elementow << std::endl;
                    waitForReturn();
                    break;
                }
                case 4: {
                    setColor(CYAN);  // Changed from BLUE to CYAN
                    displayHeader("SUM CALCULATOR");
                    int m = getValidInput<int>("Enter m: ", 1, std::numeric_limits<int>::max());

                    double sumaAll = 0;
                    double sumaS = 0;

                    for (int c = 0; c <= m; c++) {
                        sumaS = (c + 1) / (3.0 + (2 * pow(c, 3)));
                        sumaAll += sumaS;
                    }
                    if (m < 0) {
                        throw std::runtime_error("Negative value not allowed for sum calculation");
                    }
                    std::cout << "For M equal: " << m << ", sum S is: " << sumaAll << std::endl;
                    waitForReturn();
                    break;
                }
                case 5: {
                    setColor(YELLOW);
                    displayHeader("HOTEL MANAGEMENT");
                    char repeat;
                    do {
                        try {
                            Hotel hotel = inputHotelData();
                            system("cls");
                            displayHotelStats(hotel);
                            
                            setColor(WHITE);
                            std::cout << "\nProcess another hotel? (y/n): ";
                            std::cin >> repeat;
                        } catch (const std::exception& e) {
                            setColor(RED);
                            std::cerr << "Error: " << e.what() << std::endl;
                            repeat = 'n';
                        }
                    } while (repeat == 'y');
                    system("cls");  // Add this line to clear screen before returning to menu
                    waitForReturn();
                    break;
                }
            }
            resetColor();
            // Save results to file
            std::ofstream resultFile("results.txt", std::ios::app);
            resultFile << "Operation performed at: " << std::time(nullptr) << "\n";
            resultFile.close();
        }
    }
    catch (const std::exception& e) {
        setColor(RED);
        logger.log("Error: " + std::string(e.what()));
        std::cerr << "An error occurred: " << e.what() << std::endl;
        resetColor();
        return 1;
    }

    return 0;
}
