# Matrix Operations Program

A modular C program that performs standard matrix mathematics. This program was developed for **Task 2** of an internship assignment, heavily utilizing custom functions and 2D arrays to ensure clean, reusable, and modular code.

## 🚀 Features
* **Matrix Addition:** Adds two matrices of identical dimensions.
* **Matrix Multiplication:** Multiplies two matrices, complete with a mathematical validation check (ensuring Columns of Matrix A equal Rows of Matrix B).
* **Matrix Transpose:** Flips a matrix over its main diagonal, switching its row and column indices.
* **Modular Design:** Every matrix operation, as well as inputting and printing the grids, is segregated into distinct, reusable `void` functions.

## 🛠️ Compilation & Execution

1. Open your terminal in Visual Studio Code.
2. Compile the source code using GCC:
   ```bash
   gcc matrix_operations.c -o matrix_operations

  Run the executable:

On Windows: .\matrix_operations.exe

On macOS / Linux: ./matrix_operations

📋 Usage Instructions
Upon running the program, a menu will appear asking you to select an operation (1, 2, or 3).

You will then be prompted to input the dimensions for your matrices, followed by the individual integer elements for each coordinate. The results are formatted using tab-spacing (\t) for a clean, grid-like output.
