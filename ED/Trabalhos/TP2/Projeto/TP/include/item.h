#ifndef ITEM_H_
#define ITEM_H_

#include <string>

using namespace std;

class Item
{
    private:
        string url_;
        int views_;
        int fita_;
    public:
        Item(string url, int views, int fita);
        int compara(const Item *item);
        string toString();
        int Fita() { return fita_; };
};

#endif