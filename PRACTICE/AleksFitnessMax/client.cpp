#include "SocketWrapper.h"
#include <iostream>

int main() {
    Client client;
    std::string host;
    std::cout << "Enter server IP: ";
    std::getline(std::cin, host);
    try {
        client.run(host, 12345);
    } catch (const std::exception& e) {
        std::cout << "[Client] Error: " << e.what() << std::endl;
    }
    return 0;
}


// выбор XOR шифрования обоснован тем, что он
// 1. Прост в реализации и демонстрации for(char& c : result) { c ^= key; } одна операция XOR
// 2. Демонстрация принципа симметрического шифрования: Один ключ 0x5A используется для шифр и дешифр. Т.к A XOR B XOR B = A, ф-ция работает в обе стороны.
// шифр encrypted = plaintext XOR key
// дешифр plaintext = encrypted XOR key
// 3. Минимальная нагрузка на CPU, Для локальной сети и учебноего проекта такой защиты за глаза.


// Контроль целостности не выбран ни один из алгоритмов.

// Реализован простейший логин/пароль
