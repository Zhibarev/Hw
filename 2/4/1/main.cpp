#include <iostream>
#include <string>
#include "hashtable.h"
#include "hashsimple.h"
#include "hashrot13.h"
#include "hashfaq6.h"
#include "hashfunction.h"
#include "hashtest.h"
#include "hashfunctiontest.h"

int main()
{
    HashTest testHash;
    QTest::qExec(&testHash);
    HashFunctionTest testHashFunction;
    QTest::qExec(&testHashFunction);
    enum {add, remove, search, chooseHash, infoHash, help, exit, loadfactor = 0, lengthOfMaxColumn, printMaxColumn, simple = 0, hash1, hash2};
    HashFunction *hash = new HashSimple();
    HashTable *table = new HashTable(hash, 97);
    int command = help;
    std::string str = "";
    while (command != exit)
    {
        switch(command)
        {
            case add:
            {
                std::cout << "Enter string\n";
                std::cin >> str;
                table->add(str);
                break;
            }
            case remove:
            {
                std::cout << "Enter string\n";
                std::cin >> str;
                table->remove(str);
                break;
            }
            case search:
            {
                std::cout << "Enter string\n";
                std::cin >> str;
                if (table->search(str))
                    std::cout << "Include\n";
                else
                    std::cout << "Not include\n";
                break;
            }
            case chooseHash:
            {
                std::cout << "Enter command\n0 - string[i]*i\n1 - FAQ6\n2 - ROT13\n";
                std::cin >> command;
                switch(command)
                {
                    case simple:
                    {
                        delete hash;
                        hash = new HashSimple();
                        table->changeHash(hash);
                        break;
                    }
                    case hash1:
                    {
                        delete hash;
                        hash = new HashFAQ6();
                        table->changeHash(hash);
                        break;
                    }
                    case hash2:
                    {
                        delete hash;
                        hash = new HashROT13();
                        table->changeHash(hash);
                        break;
                    }
                }
                break;
            }
            case infoHash:
            {
                std::cout << "Enter command\n0 - loadfactor\n1 - length of max column\n2 - print max column\n";
                std::cin >> command;
                switch(command)
                {
                    case loadfactor:
                    {
                        std::cout << "Load Factor:\n" << table->loadFactor() << "\n";
                        break;
                    }
                    case lengthOfMaxColumn:
                    {
                        std::cout << "Length:\n" << table->lengthOfMaxColumn() << "\n";
                        break;
                    }
                    case printMaxColumn:
                    {
                        std::cout << "Max column:\n";
                        table->printMaxColumn();
                        std::cout << "\n";
                        break;
                    }
                }
                break;
            }
            case help:
            {
                std::cout << "0 - add\n1 - remove\n2 - search\n3 - choose hash function\n4 - info about table\n5 - help\n6 - exit\n";
                break;
            }
        }
        std::cout << "Enter command\n";
        std::cin >> command;
    }
    delete hash;
    return 0;
}
