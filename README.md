# C++ GUI lab
![Static Badge](https://img.shields.io/badge/Qt%20Version-QT6-green)

This repository is to practice GUI implementation of c++, so maybe each folder is not a big project, just a small scale project for practice. If you think it's helpful for you, you can just download them and welcome to leave any comments to suggest (or criticize) or ask me questions. I will answer you when I am available. 

## Project 1 : Basic Calculator
![Static Badge](https://img.shields.io/badge/build-passing-brightgreen) 
### Design Idea
The basic calculator is designed to perform arithmetic operations such as addition, subtraction, multiplication, and division, as well as advanced mathematical functions like square roots and factorials. It takes user input in a simple string format and evaluates the expression while ensuring correct operator precedence and error handling for invalid inputs. The user interface features buttons for digits and operators, allowing for a straightforward interaction.

### Function
1. **Basic Operations**: 
   - Addition (`+`)
   - Subtraction (`-`)
   - Multiplication (`*` or `x`)
   - Division (`/`)
2. **Advanced Operations**:
   - Square root (`√`)
   - Factorial (`!`)
   - Power (`^`)
3. **Error Handling**: 
   - Detects invalid expressions (e.g., missing operators, invalid characters).
   - Provides user feedback when an error occurs.

### Parameters
1. **Input Parameters**:
   - `QString expression`: A string containing the mathematical expression to be evaluated (e.g., `"8 + 5"` or `"√ 4 + 3!"`).

2. **Output Parameters**:
   - `double result`: The calculated result of the evaluated expression. If the expression is invalid, an error message is returned instead.

3. **Auxiliary Parameters** (if applicable):
   - `bool isError`: A flag to indicate whether an error occurred during evaluation, useful for handling error feedback.

### Example Usage
1. **Valid Input**: 
   - Input: `"7 + 3 * 2"`
   - Output: `13`
   
2. **Invalid Input**: 
   - Input: `"5 +"`
   - Output: `"Invalid expression: Expected a number after operator at position 2"`

### Demo
![Example video of BasicCalculator](/assets/Demo_calculator.gif)

## Project 2 :Timer
![Static Badge](https://img.shields.io/badge/planning-working-red)
### Design Idea

### Function

### Parameters

### Demo

## Project 3 : Personal To-Do list with Calender, memo
![Static Badge](https://img.shields.io/badge/planning-working-red)
### Design Idea

### Function

### Parameters

### Demo


---
## Try Project : TextFinder
![Static Badge](https://img.shields.io/badge/Qt%20Version-QT6-green)

This is just a source code from [QT getStarted tutorial](https://doc.qt.io/qtcreator/creator-writing-program.html). 
(I just wanted to give it a try, and also shared here for lazy humans like me.)
### Demo
![Example video of TextFinder](/assets/Demo_textFinder.gif)
