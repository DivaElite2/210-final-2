#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
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


struct MuffinCustomer {
    string name;
    string muffinType;
};

struct BraceletCustomer {
    string name;
    string braceletColor;
};

ListNode* createNode(const Customer& customer) {
    ListNode* newNode = new ListNode;
    newNode -> data = customer;
    newNode->  next = nullptr;
    return newNode;
}
void enqueue(ListNode*& head, ListNode*& tail, const Customer& customer) {
    ListNode* newNode = createNode(customer);

    if(tail == nullptr) {
        head = tail = newNode;
    }else {
        tail -> next = newNode;
        tail = newNode;
    }

}

Customer dequeue(ListNode*& head, ListNode*& tail) {
    if(head == nullptr) {
    return{"", ""};
}

Customer servedCustomer = head-> data;
ListNode* temp = head;
head = head->next;

if (head == nullptr) {
    tail = nullptr;
}

delete temp;
return servedCustomer;

}

bool isEmpty(ListNode* head) {
    return head == nullptr;
}
string getRandomName(const string names[], int size) {
    return names[rand() % size];
}

string getRandomDrink(const string drinks[], int size) {
    return drinks[rand() % size];

}
 string getRandomMuffin() {
    string muffins[] = {"Blueberry", "Chocolate Chip", "Banana Nut", "Apple Cinnamon", 
                        "Lemon Poppy", "Double Chocolate", "Bran", "Pumpkin"};
    int muffinCount = sizeof(muffins) / sizeof(muffins[0]);
    return muffins[rand() % muffinCount];
    }

    string getRandomBraceletColor() {
    string colors[] = {"Red", "Blue", "Green", "Yellow", "Purple", 
                       "Orange", "Pink", "Black", "White", "Rainbow"};
    int colorCount = sizeof(colors) / sizeof(colors[0]);
    return colors[rand() % colorCount];
}



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

   

int nameSize = sizeof(names) / sizeof(names[0]);
int drinkSize = sizeof(drinks) / sizeof(drinks[0]);

ListNode* head = nullptr;
ListNode*tail = nullptr;

deque<MuffinCustomer>muffinQueue;
vector<BraceletCustomer>braceletQueue;
cout << "Initialize queue with 3 customers..." <<endl;
for(int i =0; i < 3; i++) {
    Customer newCustomer;
    newCustomer.name = getRandomName(names, nameSize);
     newCustomer.drinkOrder = getRandomDrink(drinks, drinkSize);
enqueue(head, tail, newCustomer);
    cout <<"Added: " << newCustomer.name << "ordering " <<newCustomer.drinkOrder <<endl;

}
cout << "\nInitializing muffin booth queue with 3 customers..." << endl;
    for (int i = 0; i < 3; i++) {
        MuffinCustomer newCustomer;
        newCustomer.name = getRandomName(names, nameSize);
        newCustomer.muffinType = getRandomMuffin();  // CALLING getRandomMuffin() HERE
        muffinQueue.push_back(newCustomer);
        cout << "Muffin: " << newCustomer.name << " ordering " << newCustomer.muffinType << endl;
    }
    cout << endl;


    cout << "\nInitializing bracelet booth queue with 3 customers..." << endl;
    for (int i = 0; i < 3; i++) {
        BraceletCustomer newCustomer;
        newCustomer.name = getRandomName(names, nameSize);
        newCustomer.braceletColor = getRandomBraceletColor();
        braceletQueue.push_back(newCustomer);  // Using vector push_back
        cout << "Bracelet: " << newCustomer.name << " ordering " << newCustomer.braceletColor << endl;
    }
    cout << endl;

cout << "\n------Starting 10 round simulation--------" <<endl;
for(int round = 1; round <=10; round++) {
    cout << "\n-------Round" << round <<endl; 

    if (!isEmpty(head)) {
            Customer served = dequeue(head, tail);
            cout << "Served: " << served.name << " with " << served.drinkOrder << endl;
        } else {
            cout << "Queue empty - no customer served." << endl;
        }
     //drink order refined rand from previous assingment 
 if (rand() % 2 == 0) {  // 50% chance
            Customer newCustomer;
            newCustomer.name = getRandomName(names, nameSize);
            newCustomer.drinkOrder = getRandomDrink(drinks, drinkSize);
            
            enqueue(head, tail, newCustomer);
            cout << "New arrival: " << newCustomer.name << " ordering " << newCustomer.drinkOrder << endl;
        } else {
            cout << "No new customers this round." << endl;

        }

  



 cout << "\nMuffin Booth:" << endl;
        if (!muffinQueue.empty()) {
            MuffinCustomer served = muffinQueue.front();
            muffinQueue.pop_front();  // Using deque pop_front
            cout << "  Served: " << served.name << " with " << served.muffinType << endl;
        } else {
            cout << "  Queue empty - no customer served." << endl;
        }
        
        if (rand() % 2 == 0) {
            MuffinCustomer newCustomer;
            newCustomer.name = getRandomName(names, nameSize);
            newCustomer.muffinType = getRandomMuffin();
            muffinQueue.push_back(newCustomer);  // Using deque push_back
            cout << "  New arrival: " << newCustomer.name << " ordering " << newCustomer.muffinType << endl;
        } else {
            cout << "  No new customers this round." << endl;

        }

     cout << "\nBracelet Booth:" << endl;
        if (!braceletQueue.empty()) {
            // For vector, we serve from front (index 0) like a queue
            BraceletCustomer served = braceletQueue[0];
            braceletQueue.erase(braceletQueue.begin());  // Remove first element
            cout << "  Served: " << served.name << " with " << served.braceletColor << endl;
        } else {
            cout << "  Queue empty - no customer served." << endl;
        }
        
        if (rand() % 2 == 0) {
            BraceletCustomer newCustomer;
            newCustomer.name = getRandomName(names, nameSize);
            newCustomer.braceletColor = getRandomBraceletColor();
            braceletQueue.push_back(newCustomer);  // Using vector push_back
            cout << "  New arrival: " << newCustomer.name << " ordering " << newCustomer.braceletColor << endl;
        } else {
            cout << "  No new customers this round." << endl;
        }


       int queueSize = 0;
       ListNode* current = head;
       while(current != nullptr) {
        queueSize++;
        current = current ->next;
}
cout << "Que size afetr round " << round <<":" <<queueSize <<endl;
cout <<"muffin queue:" << muffinQueue.size() <<endl;
cout << "  Bracelet: " << braceletQueue.size() << endl;
}

 
while(!isEmpty(head)) {
    dequeue(head, tail);
 }

    return 0;
}


