#include "avialib.h"
#include <string> 
#include <iostream>
#include <vector>
using namespace std;
/*
*
*
*
*
*/
namespace AviaLib {
    Customer::Customer(string fio, int tel, string date, string adress) {
        this->fio = fio;
        this->tel = tel;
        this->date = date;
        this->adress = adress;
    }
    string Customer::GetFIO() {
        return fio;
    }
    int Customer::GetTel() {
        return tel;
    }
    string Customer::GetDate() {
        return date;
    }
    string Customer::GetAdress() {
        return adress;
    }
    void Customer::AddCustomerToDB(struct Avia_DataBase* db, Customer& new_cast) {
        struct Customer customerToAdd(
            new_cast.GetFIO(),
            new_cast.GetTel(),
            new_cast.GetDate(),
            new_cast.GetAdress()
        );
        // ����������� ������ ������ ����������� � ��������� ������ ����������
        db->customer_count++;
        db->customer_list = (struct Customer*)realloc(db->customer_list, db->customer_count * sizeof(struct Customer));
        db->customer_list[db->customer_count - 1] = customerToAdd;
    }
    Customer Customer::InputCustomer() {
        string fio;
        int tel;
        string date;
        string address;

        cout << "������� ���: ";
        getline(cin, fio);

        cout << "������� �������: ";
        cin >> tel;

        cout << "������� ����: ";
        cin.ignore(); // ������� ����� ����� ����� �����
        getline(cin, date);

        cout << "������� �����: ";
        cin.ignore(); // ������� ����� ����� ����� �����
        getline(cin, address);

        return Customer(fio, tel, date, address);
    }
    //-----------------------------------------------------------------------------------------
    Order::Order(string company_name, string distributor, int price, int ticket_id) {
        this->company_name = company_name;
        this->distributor = distributor;
        this->price = price;
        this->ticket_id = ticket_id;
    }
    string Order::getCompany() {
        return company_name;
    }

    string Order::getDistributor() {
        return distributor;
    }

    int Order::getPrice() {
        return price;
    }

    int Order::getTicketID() {
        return ticket_id;
    }
    void Order::AddOrderToDB(struct Avia_DataBase* db, Order& new_order) {
        // �������� ������ ��� ������ ������
        new_order.company_name = new_order.getCompany(); // ��������� ������ � ����������� ������
        new_order.distributor = new_order.getDistributor();
        new_order.price = new_order.getPrice();
        new_order.ticket_id = new_order.getTicketID();

        // ����������� ������ ������ ������� � ��������� ����� �����
        db->order_count++;
        db->order_list = (struct Order*)realloc(db->order_list, db->order_count * sizeof(struct Order));
        db->order_list[db->order_count - 1] = new_order;
    }
    Order Order::InputOrder() {
        string company_name;
        string distributor;
        int price;
        int ticket_id;

        cout << "������� �������� ��������: ";
        getline(cin, company_name);

        cout << "������� �������������: ";
        getline(cin, distributor);

        cout << "������� ����: ";
        cin >> price;

        cout << "������� ����� ������: ";
        cin >> ticket_id;

        cin.ignore(); // ������� ����� ����� ����� �����

        return Order(company_name, distributor, price, ticket_id);
    }
    //-----------------------------------------------------------------------------------------
    Ticket::Ticket(string depart, string destination, string distributor, int price, int ticket_id, string fio) {
        this->depart = depart;
        this->destination = destination;
        this->distributor = distributor;
        this->price = price;
        this->ticket_id = ticket_id;
        this->fio = fio;
    }
    Ticket::Ticket(string depart, string destination, string distributor, int price, int ticket_id, Customer& new_cust) {
        this->depart = depart;
        this->destination = destination;
        this->distributor = distributor;
        this->price = price;
        this->ticket_id = ticket_id;
        this->fio = new_cust.GetFIO();
    }
    string Ticket::getDepart() {
        return depart;
    }
    string Ticket::getDestination() {
        return destination;
    }
    string Ticket::getDistributor() {
        return distributor;
    }
    int Ticket::getPrice() {
        return price;
    }
    int Ticket::getTicketID() {
        return ticket_id;
    }
    string Ticket::getFIO() {
        return fio;
    }
    void Ticket::AddTicketToDB(struct Avia_DataBase* db, struct Ticket& new_ticket) {
        // �������� ������ ��� ������ ������
        // ��������� ����� ����� ������� �� ��������� new_ticket
        struct Ticket ticketToAdd(
            new_ticket.getDepart(),
            new_ticket.getDestination(),
            new_ticket.getDistributor(),
            new_ticket.getPrice(),
            new_ticket.getTicketID(),
            new_ticket.getFIO()
        );
        // ����������� ������ ������ ������� � ��������� ����� �����
        db->ticket_count++;
        db->ticket_list = (struct Ticket*)realloc(db->ticket_list, db->ticket_count * sizeof(struct Ticket));
        db->ticket_list[db->ticket_count - 1] = ticketToAdd;
    }
    Ticket Ticket::InputTicket() {
        string depart;
        string destination;
        string distributor;
        int price;
        int ticket_id;
        string fio;

        cout << "������� ����� �����������: ";
        getline(cin, depart);

        cout << "������� ����� ����������: ";
        getline(cin, destination);

        cout << "������� �������������: ";
        getline(cin, distributor);

        cout << "������� ����: ";
        cin >> price;

        cout << "������� ����� ������: ";
        cin >> ticket_id;

        cin.ignore(); // ������� ����� ����� ����� �����

        cout << "������� ���: ";
        getline(cin, fio);

        return Ticket(depart, destination, distributor, price, ticket_id, fio);
    }
    //-----------------------------------------------------------------------------------------
    Operation::Operation(string ticket_operation, string operation_date, static Ticket& new_ticket, static Customer& new_cust) {
        this->ticket_operation = ticket_operation;
        this->operation_date = operation_date;
        this->tel = new_cust.GetTel();
        this->ticket_id = new_ticket.getTicketID();
    }
    Operation::Operation(string ticket_operation, string operation_date, int tel, int ticketID) {
        this->ticket_operation = ticket_operation;
        this->operation_date = operation_date;
        this->tel = tel;
        this->ticket_id = ticketID;
    }
    string Operation::getOperation() {
        return ticket_operation;
    }
    string Operation::getOperationDate() {
        return operation_date;
    }
    int Operation::getTicketID() {
        return ticket_id;
    }
    int Operation::getTel() {
        return tel;
    }
    void Operation::AddOperationToDB(struct Avia_DataBase* db, struct Operation& new_op) {
        // �������� ������ ��� ������ ������
        // ��������� ����� ����� ������� �� ��������� new_ticket
        struct Operation opToAdd(
            new_op.getOperation(),
            new_op.getOperationDate(),
            new_op.getTicketID(),
            new_op.getTel()
        );
        // ����������� ������ ������ ������� � ��������� ����� �����
        db->operation_count++;
        db->operation_list = (struct Operation*)realloc(db->operation_list, db->operation_count * sizeof(struct Operation));
        db->operation_list[db->operation_count - 1] = opToAdd;
    }
    Operation Operation::InputOperation() {
        string ticket_operation;
        string operation_date;
        int ticket_id;
        int tel;

        cout << "������� ��� �������� (������ ������ ��� ������� ������): ";
        getline(cin, ticket_operation);

        cout << "������� ���� ��������: ";
        getline(cin, operation_date);

        cout << "������� ����� ������: ";
        cin >> ticket_id;

        cout << "������� ����� ��������: ";
        cin >> tel;

        cin.ignore(); // ������� ����� ����� ����� �����

        return Operation(ticket_operation, operation_date, ticket_id, tel);
    }
    //-----------------------------------------------------------------------------------------
    struct Avia_DataBase* Avia_DataBase::createAviaDataBase() {
        struct Avia_DataBase* db = (struct Avia_DataBase*)malloc(sizeof(struct Avia_DataBase));
        if (db == NULL) {
            return NULL; // ������ ��������� ������
        }

        // �������������� ������ ��� ������
        db->order_list = NULL;
        db->customer_list = NULL;
        db->operation_list = NULL;
        db->ticket_list = NULL;
        db->order_count = 0;
        db->customer_count = 0;
        db->operation_count = 0;
        db->ticket_count = 0;

        return db;
    }
    void Avia_DataBase::destroyAviaDataBase(struct Avia_DataBase* db) {
        if (db == NULL) {
            return;
        }

        // ����������� ������ ��� ������� � �� ���������
        free(db->order_list);
        free(db->customer_list);
        free(db->operation_list);
        free(db->ticket_list);

        // ����������� ������ ��� ����� ���� ������
        free(db);
    }
    void Avia_DataBase::PrintCustomerList() {
        if (customer_count > 0) {
            cout << "            ������ �����������" << endl;
            cout << "-----------------------------------------" << endl;
            for (size_t i = 0; i < customer_count; ++i) {
                cout << "���: " << customer_list[i].GetFIO() << endl;
                cout << "�������: " << customer_list[i].GetTel() << endl;
                cout << "����: " << customer_list[i].GetDate() << endl;
                cout << "�����: " << customer_list[i].GetAdress() << endl;
                cout << "-----------------------------------------" << endl;
            }
        }
        else cout << "������ ����������� ����..." << endl;
    }
    void Avia_DataBase::PrintTicketList() {
        if (ticket_count > 0) {
            cout << "            ������ �������" << endl;
            cout << "-----------------------------------------" << endl;
            for (size_t i = 0; i < ticket_count; ++i) {
                cout << "����� #" << i + 1 << endl;
                cout << "�����������: " << ticket_list[i].getDepart() << endl;
                cout << "��������: " << ticket_list[i].getDestination() << endl;
                cout << "������������: " << ticket_list[i].getDistributor() << endl;
                cout << "����: " << ticket_list[i].getPrice() << endl;
                cout << "ID ������: " << ticket_list[i].getTicketID() << endl;
                cout << "���: " << ticket_list[i].getFIO() << endl;
                cout << "-----------------------------------------" << endl;
            }
        }
        else cout << "������ ������� ����...";
    }

    void Avia_DataBase::PrintOrderList() {
        if (order_count > 0) {
            cout << "              ������ �������" << endl;
            cout << "-----------------------------------------" << endl;
            for (size_t i = 0; i < order_count; ++i) {
                cout << "����� #" << i + 1 << endl;
                cout << "�������� ��������: " << order_list[i].getCompany() << endl;
                cout << "������������: " << order_list[i].getDistributor() << endl;
                cout << "����: " << order_list[i].getPrice() << endl;
                cout << "ID ������: " << order_list[i].getTicketID() << endl;
                cout << "-----------------------------------------" << endl;
            }
        }
        else cout << "������ ������� ����..." << endl;
    }

    void Avia_DataBase::PrintOperationList() {
        if (operation_count > 0) {
            cout << "              ������ ��������" << endl;
            cout << "-----------------------------------------" << endl;
            for (size_t i = 0; i < operation_count; ++i) {
                cout << "�������� #" << i + 1 << endl;
                cout << "��� ��������: " << operation_list[i].getOperation() << endl;
                cout << "���� ��������: " << operation_list[i].getOperationDate() << endl;
                cout << "ID ������: " << operation_list[i].getTicketID() << endl;
                cout << "�������: " << operation_list[i].getTel() << endl;
                cout << "-----------------------------------------" << endl;
            }
        }
        else cout << "������ �������� ����..." << endl;
    }
}
