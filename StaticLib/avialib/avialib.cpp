#include "pch.h"
#include "framework.h"
#include "avialib.h"
#include <string> // Добавьте этот заголовок

namespace AviaLib {
    customer customer_operations::add_customer(std::string fio, std::string tel, std::string date, std::string adress) {

        customer new_cast = { fio, tel, date, adress };
        return new_cast;
    }
}



/*namespace MathLibrary
{
    double Arithmetic::Add(double a, double b)
    {
        return a + b;
    }

    double Arithmetic::Subtract(double a, double b)
    {
        return a - b;
    }

    double Arithmetic::Multiply(double a, double b)
    {
        return a * b;
    }

    double Arithmetic::Divide(double a, double b)
    {
        return a / b;
    }
}*/