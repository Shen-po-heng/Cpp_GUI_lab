#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calculation_function.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect digit buttons
    connect(ui->Button_0, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->Button_1, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->Button_2, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->Button_3, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->Button_4, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->Button_5, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->Button_6, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->Button_7, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->Button_8, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->Button_9, SIGNAL(released()), this, SLOT(digitPressed()));

    // Connect operator buttons
    connect(ui->Button_add, SIGNAL(released()), this, SLOT(operatorPressed()));
    connect(ui->Button_subtract, SIGNAL(released()), this, SLOT(operatorPressed()));
    connect(ui->Button_multiply, SIGNAL(released()), this, SLOT(operatorPressed()));
    connect(ui->Button_divide, SIGNAL(released()), this, SLOT(operatorPressed()));
    connect(ui->Button_sqrt, SIGNAL(released()), this, SLOT(operatorPressed()));
    connect(ui->Button_pow, SIGNAL(released()), this, SLOT(operatorPressed()));
    connect(ui->Button_fact, SIGNAL(released()), this, SLOT(operatorPressed()));

    // Connect clear and equal buttons
    connect(ui->Button_clear, SIGNAL(released()), this, SLOT(on_Button_clear_clicked()));
    connect(ui->Button_equal, SIGNAL(released()), this, SLOT(on_Button_equal_clicked()));

     connect(ui->Button_del, SIGNAL(released()), this, SLOT(on_Button_del_clicked()));   // Del button
}

MainWindow::~MainWindow()
{
    delete ui;
}
// Calculate the expression string
double MainWindow::calculateExpression(const QString &expression)
{
    QStringList tokens = expression.split(' ', Qt::SkipEmptyParts);
    qDebug() << "Tokens:" << tokens; // Debug output

    if (tokens.isEmpty()) {
        throw std::invalid_argument("Empty expression");
    }

    // First Pass: Handle Factorial (!), Square Root (√), and Exponentiation (^)
    for (int i = 0; i < tokens.size(); ++i) {
        QString op = tokens[i];

        // Handle square root (√)
        if (op == "√") {
            if (i + 1 >= tokens.size()) {
                throw std::invalid_argument("Invalid expression after √");
            }
            double num = tokens[i + 1].toDouble();
            double sqrtResult = calculation_Function::sqrt(num);
            tokens[i] = QString::number(sqrtResult); // Replace √ and number with the result
            tokens.removeAt(i + 1); // Remove the number token after √
        }

        // Handle factorial (!)
        if (op == "!") {
            if (i == 0) {
                throw std::invalid_argument("Invalid factorial usage");
            }
            int num = static_cast<int>(tokens[i - 1].toDouble());
            double factResult = calculation_Function::factorial(num);
            tokens[i - 1] = QString::number(factResult); // Replace number with factorial result
            tokens.removeAt(i); // Remove '!'
            --i; // Adjust index
        }

        // Handle exponentiation (^)
        if (op == "^") {
            if (i + 1 >= tokens.size()) {
                throw std::invalid_argument("Invalid expression after ^");
            }
            double base = tokens[i - 1].toDouble();
            double exp = tokens[i + 1].toDouble();
            double powResult = calculation_Function::power(base, exp);
            tokens[i - 1] = QString::number(powResult); // Replace base with power result
            tokens.removeAt(i); // Remove '^'
            tokens.removeAt(i); // Remove exponent number
            --i; // Adjust index
        }
    }

    // Second Pass: Handle Multiplication (*) and Division (/)
    for (int i = 1; i < tokens.size(); i += 2) {
        QString op = tokens[i];

        if (op == "*" || op == "x" || op == "/") {
            double left = tokens[i - 1].toDouble();
            double right = tokens[i + 1].toDouble();
            double result;

            if (op == "*" || op == "x") {
                result = calculation_Function::multiply(left, right);
            } else if (op == "/") {
                if (right == 0) {
                    throw std::invalid_argument("Division by zero");
                }
                result = calculation_Function::divide(left, right);
            }

            tokens[i - 1] = QString::number(result); // Replace left operand with result
            tokens.removeAt(i); // Remove operator
            tokens.removeAt(i); // Remove right operand
            i -= 2; // Adjust index to continue
        }
    }

    // Final Pass: Handle Addition (+) and Subtraction (-)
    double result = tokens[0].toDouble(); // Start with the first number

    for (int i = 1; i < tokens.size(); i += 2) {
        QString op = tokens[i];
        double nextNum = tokens[i + 1].toDouble();

        if (op == "+") {
            result = calculation_Function::add(result, nextNum);
        } else if (op == "-") {
            result = calculation_Function::subtract(result, nextNum);
        } else {
            throw std::invalid_argument("Unknown operator");
        }
    }

    return result;
}






// When a digit is pressed, append it to the current input string and display
void MainWindow::digitPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString buttonValue = button->text();

    // Append the digit to the current input
    currentInput += buttonValue;
    ui->textBrowser->setText(currentInput);  // Use the QTextBrowser to display the input
}

// When an operator (+, -, *, /) is pressed, append it to the input
void MainWindow::operatorPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        currentInput += " " + button->text() + " "; // Append operator with spaces
        ui->textBrowser->setText(currentInput); // Update display
    }
}

// Clear button action, clear both display and current input
void MainWindow::on_Button_clear_clicked()
{
    currentInput = "";
   ui->textBrowser->setText(currentInput);  // Update the QTextBrowser
}

// When equal button is clicked, evaluate the expression
void MainWindow::on_Button_equal_clicked()
{
    QString expression = currentInput;

    // Trim any whitespace from the input before evaluating
    currentInput = currentInput.trimmed(); // Add this line to remove any leading/trailing whitespace

    double result;

    // Print the expression for debugging
    qDebug() << "Evaluating expression:" << expression;

    try {
        result = calculateExpression(expression); // Call the calculateExpression function
        ui->textBrowser->setText(QString::number(result)); // Display the result
    } catch (std::exception &e) {
        ui->textBrowser->setText("Error: " + QString::fromStdString(e.what())); // Display error
    }

    currentInput = QString::number(result); // Store the result as new input for next operations
}

void MainWindow::on_Button_del_clicked()
{
    if (!currentInput.isEmpty()) {
        currentInput.chop(1);
        currentInput.append(" ");        // Remove the last character from the string
    }
    ui->textBrowser->setText(currentInput); // Update the display
}
