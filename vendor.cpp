#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Customer {
    string name;
    string drinkOrder;
};

struct ListNode {
    Customer data;
    ListNode* next;
};

int main()
{
    srand(time(0));

    string names[] = {"Alice", "Bob", "Charlie", "Diana", "Ethan",
        "Fiona", "George", "Hannah", "Ian", "Julia",
        "Kevin", "Luna", "Mike", "Nora", "Oscar"
    };
    
    string drinks[] = { "Espresso", "Latte", "Cappuccino", "Americano", "Mocha",
        "Macchiato", "Flat White", "Cold Brew", "Tea", "Hot Chocolate",
        "Iced Coffee", "Frappe", "Matcha Latte", "Chai Tea", "Affogato"
    };



    
    return 0;
}


