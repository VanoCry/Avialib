#include "pch.h"
#include "framework.h"
#include "avialib.h"
#include <string> // Добавьте этот заголовок
#include <iostream>

namespace AviaLib {
    customer customer_operations::add_customer(std::string fio, std::string tel, std::string date, std::string adress) {

        customer new_cast = { fio, tel, date, adress };
        return new_cast;
    }
    customer customer_operations::input_customer() {
        customer new_customer;

        std::cout << "Введите ФИО покупателя: ";
        std::cin >> new_customer.fio;
        std::cout << "Введите номер телефона покупателя: ";
        std::cin >> new_customer.tel;
        std::cout << "Введите дату приобретения билета покупателем: ";
        std::cin >> new_customer.date;
        std::cout << "Введите адрес покупателя: ";
        std::cin >> new_customer.adress;
        std::cin.ignore(); // Очистить буфер после ввода чисел, чтобы корректно считать строку
        return new_customer;
    }
    ticket ticket_operations::add_ticket(std::string destination, std::string depart, std::string distributor, std::string price, std::string id, std::string customer_fio) {
        ticket new_ticket;
        new_ticket.destination = destination;
        new_ticket.depart = depart;
        new_ticket.distributor = distributor;
        new_ticket.price = price;
        new_ticket.id = id;
        new_ticket.customer_fio = customer_fio; // Устанавливаем ФИО пассажира
        return new_ticket;
    }
    ticket ticket_operations::input_ticket() {
        ticket new_ticket;

        std::cout << "Введите пункт назначения: ";
        std::cin >> new_ticket.destination;
        std::cout << "Введите место отправления: ";
        std::cin >> new_ticket.depart;
        std::cout << "Введите дистрибьютора: ";
        std::cin >> new_ticket.distributor;
        std::cout << "Введите цену: ";
        std::cin >> new_ticket.price;
        std::cout << "Введите ID: ";
        std::cin >> new_ticket.id;
        std::cout << "Введите ФИО пассажира: ";
        std::cin.ignore(); // Очистить буфер после ввода чисел, чтобы корректно считать строку
        std::getline(std::cin, new_ticket.customer_fio);

        return new_ticket;
    }
}

