#include <bits/stdc++.h>

using namespace std;

// Hashtable to implement

class HashTable
{
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key);
    int getSize();
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const
{
    int sum{};
    for (int i{}; i < hashGroups; i++)
    {
        sum += table[i].size();
    }

    if (!sum)
    {
        return true;
    }

    return false;
}

int HashTable::hashFunction(int key)
{
    return key % hashGroups; // Key: 905, in return, this function will spit out 5.
}

int HashTable::getSize()
{
    int cnt{};
    auto bItr = begin(table);

    for (; bItr != end(table); bItr++)
    {
        if (!bItr->empty())
        {
            cnt++;
        }
    }

    return cnt;
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists. value replaced. " << endl;
            break;
        }
    }

    if (!keyExists)
    {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Item removed." << endl;
        }
    }

    if (!keyExists)
    {
        cout << "[WARNING] Key not found. Pair not removed." << endl;
    }
}

void HashTable::printTable()
{
    for (int i{}; i < hashGroups; i++)
    {
        if (table[i].size() == 0)
            continue;

        auto bItr = table[i].begin();

        for (; bItr != table[i].end(); bItr++)
        {
            cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << endl;
        }
    }

    return;
}

int main()
{
    HashTable HT;

    if (HT.isEmpty())
    {
        cout << "Correct answer. Good job.";
    }
    else
    {
        cout << "Oh oh. We need to check out code!" << endl;
    }

    HT.insertItem(901, "Jim");
    HT.insertItem(202, "Tom");
    HT.insertItem(303, "Bob");
    HT.insertItem(404, "Sally");
    HT.insertItem(505, "Sandy");
    HT.insertItem(606, "Barb");
    HT.insertItem(707, "Rob");
    HT.insertItem(808, "Yang");
    HT.insertItem(909, "Kim");

    HT.printTable();

    HT.removeItem(909);
    HT.removeItem(808);

    if (HT.getSize() == 7)
    {
        cout << "Correct answer!";
    }
    else
    {
        cout << "Oh oh. You need to fix your code." << endl;
    }

    return 0;
}