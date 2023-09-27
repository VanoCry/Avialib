#pragma once
#include <string>


namespace AviaLib {
    struct customer {
        std::string fio;
        std::string tel;
        std::string date;
        std::string adress;
    };
    class customer_operations {
    public:
        static customer add_customer(std::string fio, std::string tel, std::string date, std::string adress);
    };
}













 /*  namespace MathLibrary
    {
    class Arithmetic
    {
    public:
        // Returns a + b
        static double Add(double a, double b);

        // Returns a - b
        static double Subtract(double a, double b);

        // Returns a * b
        static double Multiply(double a, double b);

        // Returns a / b
        static double Divide(double a, double b);
    };
    }
    */