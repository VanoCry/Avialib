#pragma once
#include <string>


namespace AviaLib {
    struct customer {
        std::string fio;
        std::string tel;
        std::string date;
        std::string adress;
    };
    struct ticket {
        std::string destination;
        std::string depart;
        std::string distributor;
        std::string price;
        std::string id;
        std::string customer_fio;
    };
    class customer_operations {
    public:
        static customer add_customer(std::string fio, std::string tel, std::string date, std::string adress);

    };
    class ticket_operations {
    public:
        static ticket add_ticket(std::string destination, std::string depart, std::string distributor, std::string price, std::string id, std::string customer_fio);
        static ticket input_ticket();
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