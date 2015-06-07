#include <iostream>

#include "tbb/parallel_while.h"

using namespace tbb;

struct Item
{
    float data;

    Item* next;

    Item(float x)
    {
        data = x;
    }
};

class ItemStream
{
    private:

        Item* my_ptr;

    public:

        bool pop_if_present(Item*& item)
        {
            if (my_ptr != NULL)
            {
                item = my_ptr;
                my_ptr = my_ptr->next;
                return true;
            }
            else return false;
        }

        ItemStream(Item* root) : my_ptr(root) {}
};

class Double
{
    public:

        void operator()(Item* item) const
        {
            item->data *= 2;
        }

        typedef Item* argument_type;
};

void parallelDoubleToList(Item* root)
{
    parallel_while<Double> w;

    ItemStream stream(root);
    Double body;

    w.run(stream, body);
};

int main()
{
    Item* root = new Item(0);
    Item* ptr = root;

    for (int i = 1; i < 100; i++)
    {
        ptr->next = new Item(i);
        ptr = ptr->next;
    }

    parallelDoubleToList(root);

    ptr = root;
    while (ptr != NULL)
    {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }

    return 0;
}
