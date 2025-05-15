#include <iostream>
#include <string>

using namespace std;


#define TAX_RATE_PREPROCESSOR 0.07

// Function to display an introductory message
void displayIntroMessage() {
    cout << "Welcome to the Product Sales and Inventory Analysis Program!" << endl;
    cout << "This program helps you analyse product sales and inventory for your store." << endl;
    cout << "Note: Remember that C++ is a compiled language." << endl << endl;
}

int main() {
    // Display the intrroductory message
    displayIntroMessage();

    /// Declare product detail variables
    string productName; // Product name
    int productCategory; // Product category (1 to 5)
    int initialInventory; // Initial inventory quantity
    float productPrice; // Product price per unit
    int itemsSold; // Number of items sold

    // Declare computed value variables
    int newInventory; // New inventory
    float totalSalesAmount; // Total sales amount
    string inventoryStatus; // Inventory status

    // Demonstrate different initialization methods
    int sampleInt1 = 10; // Direct initialization
    float sampleFloat; // Declaration
    sampleFloat = 20.5; // Assignment after declaration
    int sampleInt2{30}; // List initialization

    // Define constants
    const float TAX_RATE_CONST = 0.07; // Tax rate constant using const keyword

    // Input from thhe users
    cout << "Enter the product name: ";
    cin >> productName;
    cout << "Enter the product category (1 to 5): ";
    cin >> productCategory;
    cout << "Enter the initial inventory quantity: ";
    cin >> initialInventory;
    cout << "Enter the product price per unit: ";
    cin >> productPrice;
    cout << "Enter the number of items sold: ";
    cin >> itemsSold;

    // Perform calculations
    newInventory = initialInventory; // Initialize new inventory with initial inventory
    newInventory -= itemsSold; // Subtract items sold from initial inventory
    totalSalesAmount = itemsSold * productPrice; // Calculate total sales amount

    // Use a conditional (ternary) operator for inventory status
    inventoryStatus = (newInventory < 10) ? "Low Inventory" : "Sufficient Inventory";

    // Use type deduction to create helper variables
    auto totalSalesCopy = totalSalesAmount; // Helper variable using auto
    decltype(initialInventory) helperInventory = 100; // Helper variable using decltype

    // Implement flow control
    if (productCategory < 1 || productCategory > 5) {
        cout << "Invalid product category. Please enter a category between 1 and 5." << endl;
        return 1; // Exit the program
    }

    // Use a swich statement for product category
    switch (productCategory) {
        case 1:
            cout << "Category 1: Electronics" << endl;
            break;
        case 2:
            cout << "Category 2: Groceries" << endl;
            break;
        case 3:
            cout << "Category 3: Clothing" << endl;
            break;
        case 4:
            cout << "Category 4: Stationery" << endl;
            break;
        case 5:
            cout << "Category 5: Miscellaneous" << endl;
            break;
        default:
            cout << "Unkown category" << endl;
            break;
    }

    // Use a for loop to simulate receipt printing
    cout << endl << "Receipt:" << endl;
    for (int i = 1; i <= itemsSold; ++i) {
        cout << "Item " << i << ": $" << productPrice << endl;
    }

    // Output all info
    cout << endl << "Tax Rates:" << endl;
    cout << "Preprocessor constant tax rate: " << TAX_RATE_PREPROCESSOR * 100 << "%" << endl;
    cout << "Const keyword tax rate: " << TAX_RATE_CONST * 100 << "%" << endl;

    cout << endl << "Product Details:" << endl;
    cout << "Name: " << productName << endl;
    cout << "Category: " << productCategory << endl;
    cout << "Initial Inventory: " << initialInventory << endl;
    cout << "Price per Unit: $" << productPrice << endl;
    cout << "Items Sold: " << itemsSold << endl;

    cout << endl << "Computed Values:" << endl;
    cout << "New Inventory: " << newInventory << endl;
    cout << "Total Sales Amount: $" << totalSalesAmount << endl;
    cout << "Inventory Status: " << inventoryStatus << endl;

    cout << endl << "Helper Variables:" << endl;
    cout << "Total Sales Copy (auto): $" << totalSalesCopy << endl;
    cout << "Helper Inventory (decltype): " << helperInventory << endl;

    return 0;
}