#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <ctime>
#include <map>
#include <iomanip>
using namespace std;

const string PROPERTIES_FILE = "userLogin.properties";
const string USERS_FILE = "users.txt";

// Helper function to trim whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Load properties from file into a map
map<string, string> loadProperties(const string& filename) {
    map<string, string> properties;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t delimiterPos = line.find('=');
        if (delimiterPos != string::npos) {
            string key = trim(line.substr(0, delimiterPos));
            string value = trim(line.substr(delimiterPos + 1));
            properties[key] = value;
        }
    }
    return properties;
}

// Save properties from map to file
void saveProperties(const string& filename, const map<string, string>& properties) {
    ofstream file(filename);
    for (const auto& pair : properties) {
        file << pair.first << "=" << pair.second << endl;
    }
}

// Menu display
void displayInitialMenu() {
    cout << "\n--- Welcome to ValidRail – Admin & User Validation System ---\n";
    cout << "1. Admin User Login\n";
    cout << "2. View User Login (Coming Soon)\n";
    cout << "3. Create New Admin\n";
    cout << "100. Exit\n";
    cout << "Enter your choice [1,2,3,100]: ";
}

// Validations
bool isValidName(const string& name) {
    return regex_match(name, regex("^[A-Za-z ]+$"));
}

bool isValidDOB(const string& dob) {
    tm tm{};
    istringstream ss(dob);
    ss >> get_time(&tm, "%d/%m/%Y");
    if (ss.fail()) return false;

    time_t now = time(0);
    tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0;
    time_t dob_time = mktime(&tm);

    return difftime(now, dob_time) > 0;
}

bool isValidGender(const string& gender) {
    string g = gender;
    for (auto& ch : g) ch = tolower(ch);
    return g == "m" || g == "f" || g == "male" || g == "female";
}

bool isValidMobile(const string& mobile) {
    return regex_match(mobile, regex("^\\+?[0-9]{10,13}$"));
}

bool isValidEmail(const string& email) {
    return regex_match(email, regex("^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,6}$")) &&
           email.find("..") == string::npos;
}

bool isValidPinCode(const string& pin) {
    return regex_match(pin, regex("^\\d{6}$"));
}

bool isValidAddressField(const string& field) {
    return !field.empty();
}

// Admin login
bool adminLogin() {
    auto props = loadProperties(PROPERTIES_FILE);
    cout << "[DEBUG] Stored adminUserId: '" << props["adminUserId"] << "'\n";
    cout << "[DEBUG] Stored adminPassword: '" << props["adminPassword"] << "'\n";

    string userId, password;

    cout << "Enter Admin User Id: ";
    getline(cin, userId);
    cout << "Enter Admin Password: ";
    getline(cin, password);

    if (props["adminUserId"] == userId && props["adminPassword"] == password) {
        cout << "Login successful. Update admin credentials.\n";
        cout << "New Admin User Id: ";
        getline(cin, props["adminUserId"]);
        cout << "New Admin Password: ";
        getline(cin, props["adminPassword"]);
        saveProperties(PROPERTIES_FILE, props);
        return true;
    } else {
        cout << "Credential not matched.\n";
        return false;
    }
}

// Create new admin
void createNewAdmin() {
    map<string, string> props;
    cout << "Enter new Admin User Id: ";
    getline(cin, props["adminUserId"]);
    cout << "Enter new Admin Password: ";
    getline(cin, props["adminPassword"]);
    saveProperties(PROPERTIES_FILE, props);
    cout << "✅ New admin created successfully.\n";
}

// User registration
void userRegistration() {
    string name, dob, gender, mobile, email;
    string houseNo, street, postOffice, pin, state, country;

    cout << "Name: "; getline(cin, name);
    cout << "Date Of Birth [dd/mm/yyyy]: "; getline(cin, dob);
    cout << "Gender [Male(M)/Female(F)]: "; getline(cin, gender);
    cout << "Mobile no with ISD: "; getline(cin, mobile);
    cout << "Email Id: "; getline(cin, email);
    cout << "Address HouseNo: "; getline(cin, houseNo);
    cout << "Street: "; getline(cin, street);
    cout << "Post Office: "; getline(cin, postOffice);
    cout << "PinCode: "; getline(cin, pin);
    cout << "State: "; getline(cin, state);
    cout << "Country Name: "; getline(cin, country);

    stringstream errors;

    if (!isValidName(name)) errors << "Invalid name.\n";
    if (!isValidDOB(dob)) errors << "Invalid date of birth.\n";
    if (!isValidGender(gender)) errors << "Invalid gender.\n";
    if (!isValidMobile(mobile)) errors << "Invalid mobile number.\n";
    if (!isValidEmail(email)) errors << "Invalid email.\n";
    if (!isValidAddressField(houseNo)) errors << "Invalid house number.\n";
    if (!isValidAddressField(street)) errors << "Invalid street.\n";
    if (!isValidAddressField(postOffice)) errors << "Invalid post office.\n";
    if (!isValidPinCode(pin)) errors << "Invalid pin code.\n";
    if (!isValidAddressField(state)) errors << "Invalid state.\n";
    if (!isValidAddressField(country)) errors << "Invalid country.\n";

    string errorStr = errors.str();
    if (!errorStr.empty()) {
        cout << "\nErrors:\n" << errorStr;
        cout << "Enter 1 to retry or 100 to return: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1) userRegistration();
        return;
    }

    ofstream outFile(USERS_FILE, ios::app);
    outFile << name << "$" << dob << "$" << gender << "$" << mobile << "$" << email << "$"
            << houseNo << "$" << street << "$" << postOffice << "$" << pin << "$"
            << state << "$" << country << "\n";
    outFile.close();
    cout << "✅ User registration successful.\n";
}

// Admin main menu
void displayAdminMenu() {
    while (true) {
        cout << "\n--- Admin Main Menu ---\n";
        cout << "1. User Registration Fields Validation\n";
        cout << "10. Exit\n";
        cout << "Enter your choice [1-10]: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 10) break;
        switch (choice) {
            case 1:
                userRegistration();
                break;
            default:
                cout << "Option under development. Try another.\n";
        }
    }
}

// Main Program
int main() {
    while (true) {
        displayInitialMenu();
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                if (adminLogin()) displayAdminMenu();
                break;
            case 2:
                cout << "View User Login: Coming Soon!\n";
                break;
            case 3:
                createNewAdmin();
                break;
            case 100:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}