#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack
{
    private:

        vector<T> elems; // elements

    public:

        void push(T const& elem); // push element

        void pop(); // pop element

        T top() const; // return top element

        bool empty() const // return whether the stack is empty
        {
            return elems.empty();
        }
};

template<typename T>
void Stack<T>::push(T const& elem)
{
    elems.push_back(elem);
}

template<typename T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    
    elems.pop_back();
}

template<typename T>
T Stack<T>::top() const
{
    if (elems.empty())
        throw out_of_range("Stack<>::top(): empty stack");

    elems.back();
}
