# Advanced Mathematics Program

## Overview
This C++ console application provides a menu-driven interface for mathematical calculations and hotel management. Features include multiplication table generation, function calculation, average computation, sum series calculation, and hotel occupancy tracking. It supports colored output, logging to `program_log.txt`, result saving to `results.txt`, and robust input validation.

## Features
- **Calculation Tools**:
  - **Multiplication Table**: Generates a table (1 to N, max 10) in grid format.
  - **Function Calculator**: Computes `y = 3x^2 + 3x - 1` for x = a + i*h over n steps.
  - **Average Calculator**: Calculates average of user-entered numbers (0 to end input).
  - **Sum Calculator**: Computes series sum based on parameter M.
  - **Hotel Management**: Tracks room occupancy, displays statistics (total/vacant rooms, occupancy rate).
- **Interface**:
  - `displayHeader`: Shows ASCII headers for each tool.
  - Menu options: 1–5 for tools, 0 to exit.
  - `displayProgramDescription`: Shows program overview at startup.
  - `waitForReturn`: Prompts to return to menu.
- **Logger Class**:
  - Logs program start/end and errors to `program_log.txt` with timestamps.
- **Console Enhancements**:
  - Colored output (red, green, cyan, yellow, white) using Windows console API.
  - `setColor`/`resetColor`: Manages text color.
  - `clearScreen`: Clears console (Windows-specific).
- **Input Validation**:
  - `getValidInput`: Ensures inputs are within specified ranges.
  - Handles invalid inputs with retries.
- **File I/O**:
  - Saves operation timestamps to `results.txt`.
  - Logs errors/messages to `program_log.txt`.

## Requirements
- C++ compiler (e.g., g++, MSVC) with C++11 or later
- Windows OS (for `<windows.h>` and console color functions)
- Standard C++ libraries: `<iostream>`, `<iomanip>`, `<string>`, `<cmath>`, `<fstream>`, `<ctime>`, `<stdexcept>`, `<limits>`, `<vector>`
- Operating system: Windows (due to console functions)
- Write permissions for `program_log.txt` and `results.txt`

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Save the provided code as `math_program.cpp`.
3. Compile the program:
   ```bash
   g++ math_program.cpp -o math_program
   ```
4. Run the program:
   ```bash
   .\math_program
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Shows program description at startup.
   - Displays main menu with options:
     1. Multiplication Table
     2. Function Calculator
     3. Average Calculator
     4. Sum Calculator
     5. Hotel Management
     0. Exit
3. **Input**:
   - Select 0–5 to choose a tool.
   - Provide inputs (e.g., table size, function parameters, hotel data).
   - Invalid inputs trigger retries with error messages.
4. **Output**:
   - Multiplication Table: Grid (e.g., 1×2=2).
   - Function Calculator: y values for x steps (e.g., "y equals: 5.5").
   - Average Calculator: Mean of numbers (e.g., "The average is: 7.5").
   - Sum Calculator: Series sum (e.g., "sum S is: 2.34").
   - Hotel Management: Stats (e.g., "Occupancy Rate: 75.00%").
   - Errors logged to `program_log.txt`.
5. **Actions**:
   - Press Enter to return to menu after each tool.
   - Select 0 to exit.

## File Structure
- `math_program.cpp`: Main C++ source file with program logic.
- `program_log.txt`: Log file for program events/errors (created/appended).
- `results.txt`: Output file for operation timestamps (created/appended).
- `README.md`: This file, providing project documentation.

## Notes
- Windows-specific due to `<windows.h>` and console color functions; adapt for other OS (e.g., ANSI colors, `system("clear")`).
- Input validation ensures robust user interaction.
- `results.txt` only stores timestamps; extend to save calculation results.
- Extend by adding more tools, GUI, or cross-platform support.
- Ensure write permissions for `program_log.txt` and `results.txt`.
- No external dependencies beyond standard C++ libraries.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.