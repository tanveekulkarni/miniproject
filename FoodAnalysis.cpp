#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Diet {
    public:
        string name;
        int calories;
        int protein;
        int fat;
        int carbs;
        void display() {
            cout << "Name: " << name << endl;
            cout << "Calories: " << calories << endl;
            cout << "Protein: " << protein << endl;
            cout << "Fat: " << fat << endl;
            cout << "Carbs: " << carbs << endl;
        }
};

class DietAnalyzer : public Diet {
public:
    void analyze() {
        cout << "Analysis Results:" << endl;
        if (calories > 1000) {
            cout << "This food is high in calories, it is not healthy for consumption." << endl;
        } else {
            cout << "This food is low in calories, it is healthy for you." << endl;
        }

        if (protein < 10) {
            cout << "Low protein content. Consider adding protein-rich foods to your diet." << endl;
        } else if (protein > 30) {
            cout << "High protein content. Good for muscle building." << endl;
        } else {
            cout << "Moderate protein content." << endl;
        }

        if (fat < 5) {
            cout << "Low fat content. Good for a low-fat diet." << endl;
        } else if (fat > 15) {
            cout << "High fat content. Be cautious, too much fat may not be healthy." << endl;
        } else {
            cout << "Moderate fat content." << endl;
        }

        if (carbs < 20) {
            cout << "Low carbohydrate content. Consider adding more carbs for energy." << endl;
        } else if (carbs > 50) {
            cout << "High carbohydrate content. Good for energy, but watch for excessive sugar." << endl;
        } else {
            cout << "Moderate carbohydrate content." << endl;
        }
    }
};


class DietManager : public Diet {
    public:
        void add() {
            ofstream file("diet.txt", ios::app);
            file << name << " " << calories << " " << protein << " " << fat << " " << carbs << endl;
            file.close();
            cout << "Diet added successfully." << endl;
        }
        void view() {
            std::ifstream inputFile("diet.txt");



    std::string word;
    while (inputFile >> word) {
        std::cout << word << " "<<endl;
    }

    // Close the file
    inputFile.close();
        }
};

int main() {
    int choice;
    DietAnalyzer da;
    DietManager dm;
    while (true) {
        cout << "Enter your choice:" << endl;
        cout << "1. Add a food item" << endl;
        cout << "2. View all food items" << endl;
        cout << "3. Analyze a food item" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the name of the food item: ";
                cin >> dm.name;
                cout << "Enter the number of calories: ";
                cin >> dm.calories;
                cout << "Enter the amount of protein: ";
                cin >> dm.protein;
                cout << "Enter the amount of fat: ";
                cin >> dm.fat;
                cout << "Enter the amount of carbs: ";
                cin >> dm.carbs;
                dm.add();
                break;
            case 2:
                dm.view();
                break;
            case 3:
                cout << "Enter the name of the food item: ";
                cin >> da.name;
                cout << "Enter the number of calories: ";
                cin >> da.calories;
                cout << "Enter the amount of protein: ";
                cin >> da.protein;
                cout << "Enter the amount of fat: ";
                cin >> da.fat;
                cout << "Enter the amount of carbs: ";
                cin >> da.carbs;
                da.analyze();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
