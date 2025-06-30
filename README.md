<h1>🚆 RailwayAuth-CLI-master – Admin & User Validation System (C++ CLI)</h1>
RailwayAuth-CLI-master is a C++-based command-line application that simulates a secure user validation and registration system for a railway portal.
It includes admin login, credential updates, input validation, and file-based data persistence — all implemented using standard C++ libraries. <br>

<h1>🧠 Problem Statement </h1>
Railway systems require secure and structured user data entry.
This project simulates an admin-managed registration system where:

Admin credentials are validated and can be updated

User inputs are strictly validated (name, email, DOB, etc.)

Validated data is saved persistently in a local file (users.txt) <br>

<h1>💻 Features</h1>
✅ Admin login using a file-based .properties-like config
✅ Create new admin users from CLI
✅ User registration form with full input validation
✅ Retry mechanism on invalid input
✅ Stores user data in users.txt using file streams
✅ Menu-driven CLI navigation
✅ Modular, structured C++ code using classes and functions

🛠️ Tech Stack
Technology	Usage
C++ (Core)	Business logic, validation, menu handling
File I/O	fstream, ifstream, ofstream
Regex	std::regex for email, phone, and input validation
Input Handling	cin, getline()

📁 Folder Structure
objectivec
Copy
Edit
RailwayAuth-CLI-master/
├── src/
│   └── AssignmentProgram.cpp
├── resources/
│   ├── userLogin.properties   // Simple key-value config
│   └── users.txt              // Stores user data
├── .gitignore
├── README.md
└── LICENSE
🚀 How to Run
Clone this repo:

bash
Copy
Edit
git clone https://github.com/adityamishra1105/RailwayAuth-CLI-master.git
cd RailwayAuth-CLI-master
Compile & Run the program:

bash
Copy
Edit
cd src
g++ AssignmentProgram.cpp -o railwayauth
./railwayauth   # or railwayauth.exe on Windows
Make sure resources/userLogin.properties exists with default credentials.

🔐 Admin Credentials
Stored in: resources/userLogin.properties

properties
Copy
Edit
adminUserId=admin
adminPassword=admin123
You can update these credentials using the "Create New Admin" CLI option.

📌 Future Enhancements
Switch from file-based storage to SQLite or PostgreSQL using C++ DB libraries

Implement DAO pattern

Add ticket booking and train search modules

Add GUI using Qt or SFML

Use hashing/encryption for password storage (e.g., SHA256)

🧑‍💻 Author
Suhani Mishra

