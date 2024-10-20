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

    // Connect clear and equal buttons
    connect(ui->Button_clear, SIGNAL(released()), this, SLOT(on_Button_clear_clicked()));
    connect(ui->Button_equal, SIGNAL(released()), this, SLOT(on_Button_equal_clicked()));
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

    // Check for a valid expression structure
    // Allow cases for single numbers (like "12")
    if (tokens.size() < 1 || (tokens.size() == 1 && tokens[0].toDouble() == 0 && tokens[0] != "0")) {
        throw std::invalid_argument("Invalid expression");
    }

    double result = tokens[0].toDouble(); // Start with the first number

    for (int i = 1; i < tokens.size(); i += 2) {
        QString op = tokens[i];
        double nextNum = tokens[i + 1].toDouble();

        // Print token values for debugging
        qDebug() << "Operator:" << op << ", NextNum:" << nextNum;

        // Perform the operation based on the operator
        if (op == "+") {
            result = calculation_Function::add(result, nextNum);
        } else if (op == "-") {
            result = calculation_Function::subtract(result, nextNum);
        } else if (op == "*") {
            result = calculation_Function::multiply(result, nextNum);
        } else if (op == "/") {
            if (nextNum == 0) {
                throw std::invalid_argument("Division by zero");
            }
            result = calculation_Function::divide(result, nextNum);
        } else if (op == "^") {
            result = calculation_Function::power(result, nextNum);
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
