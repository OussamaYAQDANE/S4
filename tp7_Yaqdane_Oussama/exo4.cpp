#include <iostream>
#include <vector>
using namespace std;

class Inventory;

class Object
{
private:
    string name;
    int quantity;
public:
    

    Object(string name, int quantity): name(name), quantity(quantity){}

    void add(int x){
        quantity += x;
    }
    void sub(int x){
        quantity -= x;
    }
    void setQuantity(int x){
        quantity = x;
    }
friend class Inventory;
};

class Inventory
{
private:
    vector<Object*> inventory;
public:
    void add_object(string name, int quantity){
        cout << "Adding " << name << " (x"<<quantity<<")." << endl;
        for (Object* object: inventory){
            if (object->name == name){
                object->add(quantity);
                return;
            }
            
        }
        inventory.push_back(new Object(name, quantity));
    }

    void remove_object(string name, int quantity){
        for (Object* object: inventory){
            if (object->name == name){
                if (quantity > object->quantity){
                    cout << "You don't even have " << quantity << " " << name << endl;
                    return;
                } else {
                    cout << "Removed " << name << " (x" << quantity << ")" << endl;
                    object->quantity -= quantity;
                    return;
                }
            }
        }
        cout << "Object " << name << " doesn't exist in your inventory." << endl;
    }

    void print_inventory(){
        cout << "Inventory:" << endl;
        for (Object* object : inventory){
            cout << "  -" << object->name << " (x" << object->quantity << ")" << endl;
        }
    }

    ~Inventory(){
        for (Object* object : inventory){
            delete object;
        }
        cout << "Inventory memory liberated successfully!" << endl;
    }
};

int main() {
    Inventory myInventory;
    myInventory.add_object("Apple", 3);
    myInventory.add_object("Sword", 7);
    myInventory.add_object("Apple", 1);
    myInventory.remove_object("Sword", 1);
    myInventory.remove_object("Apple", 20);
    myInventory.remove_object("haha", 55);
    myInventory.print_inventory();
}
