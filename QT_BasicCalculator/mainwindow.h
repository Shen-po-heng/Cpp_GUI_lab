#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digitPressed();                  // When a number is pressed
    void on_Button_clear_clicked();   // To clear the input
    void on_Button_equal_clicked();   // To calculate and display result
    void operatorPressed();               // When an operator (+, -, *, /, etc.) is pressed

private:
    Ui::MainWindow *ui;
    QString currentInput;  // Store the entire expression as a string
    double calculateExpression(const QString &expression); // Declaration of calculateExpression

};
#endif // MAINWINDOW_H
