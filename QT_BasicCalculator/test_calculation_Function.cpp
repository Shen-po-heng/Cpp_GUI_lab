#include <QtTest/QtTest>
#include "calculation_Function.h"

class TestCalculationFunction : public QObject {
    Q_OBJECT

private slots:
    void testAdd() {
        calculation_Function calc;
        QCOMPARE(calc.add(3.0, 4.0), 7.0);
    }

    void testSubtract() {
        calculation_Function calc;
        QCOMPARE(calc.subtract(10.0, 5.0), 5.0);
    }

    void testMultiply() {
        calculation_Function calc;
        QCOMPARE(calc.multiply(2.0, 3.0), 6.0);
    }

    void testDivide() {
        calculation_Function calc;
        QCOMPARE(calc.divide(10.0, 2.0), 5.0);
    }

    void testDivideByZero() {
        calculation_Function calc;
        QVERIFY_EXCEPTION_THROWN(calc.divide(10.0, 0.0), std::invalid_argument);
    }

    void testSqrt() {
        calculation_Function calc;
        QCOMPARE(calc.sqrt(16.0), 4.0);
    }

    void testSqrtNegative() {
        calculation_Function calc;
        QVERIFY_EXCEPTION_THROWN(calc.sqrt(-1.0), std::invalid_argument);
    }

    void testPi() {
        calculation_Function calc;
        QCOMPARE(calc.pi(), M_PI);
    }

    void testPower() {
        calculation_Function calc;
        QCOMPARE(calc.power(2.0, 3.0), 8.0);
    }

    void testFactorial() {
        calculation_Function calc;
        QCOMPARE(calc.factorial(5), 120);
    }

    void testFactorialNegative() {
        calculation_Function calc;
        QVERIFY_EXCEPTION_THROWN(calc.factorial(-1), std::invalid_argument);
    }
};

QTEST_MAIN(TestCalculationFunction)
#include "test_calculation_Function.moc"
