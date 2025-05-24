# 🧮🏨 Math & Management Suite Pro 📊
_A C++ console application offering a diverse toolkit for mathematical calculations, series analysis, and basic hotel occupancy management, with a colorful UI and logging._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features & Tools](#-key-features--tools)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Setup](#️-installation-and-setup)
6.  [Usage Guide](#️-usage-guide)
7.  [File Structure & Data Persistence](#-file-structure--data-persistence)
8.  [Technical Notes](#-technical-notes)
9.  [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**Math & Management Suite Pro**, developed by Adrian Lesniak, is a multifaceted C++ console application that provides a suite of tools for various mathematical computations and a basic hotel room management simulation. Users can generate multiplication tables, calculate values of a quadratic function over a range, compute the average of a set of numbers, and determine the sum of a specific series. Additionally, it includes a module for tracking hotel room occupancy and displaying related statistics. The program features a user-friendly, menu-driven interface with colorful output (enhanced on Windows), robust input validation, detailed logging of program events and errors to `program_log.txt`, and saves operation timestamps to `results.txt`.

## ✨ Key Features & Tools

The application offers a range of distinct tools accessible via a main menu:

### Mathematical Calculation Tools:
1.  ✖️ **Multiplication Table Generator**:
    *   Generates and displays a multiplication table from 1 up to a user-specified number N (maximum N is typically 10).
    *   Output is presented in a clear grid format.
2.  📉 **Function Calculator**:
    *   Computes and displays values for the function `y = 3x² + 3x - 1`.
    *   Calculates `y` for `x` starting at `a`, incrementing by `h`, for `n` steps (all parameters provided by the user).
3.  📊 **Average Calculator**:
    *   Allows the user to enter a series of numbers.
    *   Input is terminated by entering `0`.
    *   Calculates and displays the arithmetic mean (average) of the entered numbers (excluding the terminating zero).
4.  ➕ **Series Sum Calculator**:
    *   Computes the sum of a mathematical series based on a user-provided parameter `M`. (The specific series formula needs to be defined in the code).

### Management Tool:
5.  🏨 **Hotel Occupancy Management**:
    *   Tracks the occupancy status of rooms in a simulated hotel.
    *   Allows users to input data regarding total rooms and occupied rooms.
    *   Displays key statistics: total rooms, number of vacant rooms, and the occupancy rate (percentage).

### Common Features:
*   🖥️ **Interactive Console Interface**:
    *   `displayHeader`: Shows specific ASCII art headers for each tool/module, enhancing visual distinction.
    *   `displayProgramDescription`: Presents an overview of the program upon startup.
    *   **Menu System**: Provides a numbered list of options for easy navigation (1–5 for tools, 0 to exit).
    *   `waitForReturn`: Prompts the user to press a key to return to the main menu after each operation.
*   🌈 **Colorful Output**: Utilizes Windows console API (`SetConsoleTextAttribute`) via `setColor` and `resetColor` functions for distinct colors (red, green, cyan, yellow, white) to improve UI clarity.
*   ✍️ **Logging & File I/O**:
    *   **Logger Class**: A dedicated `Logger` (or similar mechanism) logs program start/end events and any errors encountered to `program_log.txt` with timestamps.
    *   Saves timestamps of successful operations to `results.txt`.
*   ✔️ **Robust Input Validation**:
    *   `getValidInput`: A specialized function to ensure user inputs are within specified valid ranges and of the correct type.
    *   Handles invalid inputs gracefully with error messages and prompts for re-entry.
*   ⚙️ **Console Enhancements**:
    *   `clearScreen`: Clears the console window (using `system("cls")` on Windows) for a cleaner display between tasks.

## 🖼️ Screenshots

**Coming soon!**

_This section will be updated with screenshots showcasing the main menu, inputs and outputs for each mathematical tool, the hotel management interface, and examples from `program_log.txt` and `results.txt`._

## ⚙️ System Requirements

*   **Operating System**: Windows (due to dependencies like `<windows.h>` for `SetConsoleTextAttribute` and console clearing/pausing utilities).
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<iomanip>`, `<string>`, `<vector>` (if used for dynamic data), `<cmath>`, `<fstream>`, `<ctime>`, `<stdexcept>`, `<limits>`.
*   **Write Permissions**: The application needs write permissions in its execution directory to create/modify `program_log.txt` and `results.txt`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Save Main Code**:
    Ensure your main program logic (including all tool implementations, UI functions, logging, and `main()`) is saved as `math_program.cpp` (or your chosen main file name) in the project directory. *(The description implies a single-file structure for the core logic, with utility functions for color, logging, etc., potentially also within this file if no separate utility header is mandated by the actual code for this project).*

3.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, etc.) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ math_program.cpp -o math_program.exe -std=c++11 -static-libgcc -static-libstdc++
    ```
    *(Adjust if you have separate utility `.cpp` files that need to be compiled and linked).*

4.  **Run the Program**:
    ```bash
    .\math_program.exe
    ```
    (or `math_program.exe` in CMD)

## 💡 Usage Guide

1.  Compile and run `math_program.exe` as detailed above.
2.  **Interface**:
    *   The program will first display a general program description.
    *   A main menu will then appear with the following options:
        1.  Multiplication Table
        2.  Function Calculator
        3.  Average Calculator
        4.  Sum Calculator
        5.  Hotel Management
        0.  Exit
3.  **Input**:
    *   Select a menu option (0–5) by typing the number and pressing Enter.
    *   Based on the selected tool, you will be prompted for specific inputs:
        *   **Multiplication Table**: Size of the table (N, up to 10).
        *   **Function Calculator**: Initial value `a`, step `h`, and number of steps `n`.
        *   **Average Calculator**: A sequence of numbers (input `0` to finish).
        *   **Sum Calculator**: Parameter `M` for the series.
        *   **Hotel Management**: Data like total rooms, occupied rooms.
    *   Invalid inputs will trigger error messages (logged to `program_log.txt`) and prompt for re-entry.
4.  **Output**:
    *   **Multiplication Table**: Displays the generated N x N grid (e.g., "1 x 2 = 2").
    *   **Function Calculator**: Shows the calculated `y` values for each step of `x` (e.g., "For x = ..., y = 5.50").
    *   **Average Calculator**: Outputs the mean of the entered numbers (e.g., "The average is: 7.50").
    *   **Sum Calculator**: Displays the computed sum of the series (e.g., "The sum S is: 2.34").
    *   **Hotel Management**: Shows statistics like total rooms, vacant rooms, and occupancy rate (e.g., "Occupancy Rate: 75.00%").
    *   Timestamps of successful operations are saved to `results.txt`.
    *   Errors are logged to `program_log.txt`.
5.  **Actions**:
    *   After each tool completes its task and displays results, you will be prompted to press Enter to return to the main menu.
    *   Select option `0` from the main menu to exit the application.

## 🗂️ File Structure & Data Persistence

*   `math_program.cpp`: The main C++ source file containing all program logic, including the implementations for each tool, UI management, the `Logger` class (or its instance), and input validation.
*   `program_log.txt`: A plain text file where program start/end events and error messages are recorded with timestamps. This file is created or appended to.
*   `results.txt`: A plain text file that stores timestamps of when operations were successfully completed. (Could be extended to store actual results). This file is created or appended to.
*   `README.md`: This documentation file.

## 📝 Technical Notes

*   **Windows Specifics**: The project relies on Windows-specific headers (`<windows.h>`) for console color manipulation (`SetConsoleTextAttribute`) and potentially other console utilities like `system("cls")` or `_getch()`. Adapting for true cross-platform compatibility would require using ANSI escape codes for colors and alternative methods for other console interactions on Unix-like systems.
*   **Input Validation**: The `getValidInput` function is crucial for ensuring robust user interaction by checking if inputs are within expected ranges and of the correct data type, using C++ stream states and `std::numeric_limits`.
*   **`results.txt` Content**: Currently, this file primarily stores timestamps of operations. For greater utility, it could be enhanced to save the actual input parameters and calculated results for each operation.
*   **Error Logging**: The `Logger` class provides a structured way to log errors and system events, which is beneficial for debugging and monitoring.
*   **Modularity**: Although in a single `.cpp` file, the functions for each tool and utility (like `setColor`, `displayHeader`) suggest a modular approach to the code's organization.

## 🤝 Contributing

Contributions to **Math & Management Suite Pro** are highly encouraged! If you have ideas for adding new mathematical tools, enhancing the hotel management features, improving cross-platform support, or refining the user interface:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourAwesomeTool`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourAwesomeTool'`).
4.  Push to the branch (`git push origin feature/YourAwesomeTool`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
💡 _A versatile console suite for calculations and simulations!_
