#include <iostream>
#include "string"
#include "..\avialib\Avialib.h"
using namespace std;

int main()
{
    AviaLib::customer_operations customerOps; // Создаем объект класса customer_operations
    AviaLib::customer default_cast = customerOps.add_customer("John Doe", "123456789", "2023-09-27", "123 Main St");
    default_cast.tel = "88005553535";
    // Теперь у вас есть default_cast, который содержит данные, возвращенные функцией add_customer.
    return 0;
}
