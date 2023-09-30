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
    struct avia_operations {
        bool operation_pir_ref;
        std::string date_of_operation;


    };
    class customer_operations {
    public:
        static customer add_customer(std::string fio, std::string tel, std::string date, std::string adress);
        static customer input_customer();
    };
    class ticket_operations {
    public:
        static ticket add_ticket(std::string destination, std::string depart, std::string distributor, std::string price, std::string id, std::string customer_fio);
        static ticket input_ticket();
    };
}
