#include <iostream>
using namespace std;

class StationeryShop {
private:
    string items[100];
    double prices[100];
    int itemCount;

public:
    StationeryShop() : itemCount(0) {}

    void addItem(string item, double price) {
        if (itemCount < 100) {
            items[itemCount] = item;
            prices[itemCount] = price;
            itemCount++;
        } else {
            cout << "Item list is full!" << endl;
        }
    }

    void viewItems() {
        cout << "\nAvailable Items:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i] << " - $" << prices[i] << endl;
        }
    }

    void editPrice(int index, double newPrice) {
        if (index >= 0 && index < itemCount) {
            prices[index] = newPrice;
            cout << "Price updated successfully." << endl;
        } else {
            cout << "Invalid item index!" << endl;
        }
    }

    void generateReceipt() {
        int quantities[100] = {0};
        double total = 0.0;
        int choice, quantity;
        
        cout << "\nEnter item number and quantity (0 to stop):" << endl;
        while (true) {
            cin >> choice;
            if (choice == 0) break;
            cin >> quantity;
            if (choice > 0 && choice <= itemCount) {
                quantities[choice - 1] += quantity;
            } else {
                cout << "Invalid item number!" << endl;
            }
        }
        
        cout << "\nReceipt:" << endl;
        for (int i = 0; i < itemCount; i++) {
            if (quantities[i] > 0) {
                double cost = quantities[i] * prices[i];
                total += cost;
                cout << items[i] << " x " << quantities[i] << " = $" << cost << endl;
            }
        }
        cout << "Total: $" << total << endl;
    }
};

int main() {
    StationeryShop shop;
    int choice;
    string item;
    double price;
    
    while (true) {
        cout << "\nMenu:\n1. Add Item\n2. View Items\n3. Edit Item Price\n4. Generate Receipt\n5. Exit\nChoose an option: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> item;
                cout << "Enter item price: ";
                cin >> price;
                shop.addItem(item, price);
                break;
            case 2:
                shop.viewItems();
                break;
            case 3:
                int index;
                cout << "Enter item number to edit price: ";
                cin >> index;
                cout << "Enter new price: ";
                cin >> price;
                shop.editPrice(index - 1, price);
                break;
            case 4:
                shop.generateReceipt();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}
