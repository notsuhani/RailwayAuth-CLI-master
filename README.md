<h2>🚆 RailwayAuth-CLI-master – Admin & User Validation System (C++ CLI)</h2>
RailwayAuth-CLI-master is a C++-based command-line application that simulates a secure user validation and registration system for a railway portal.
It includes admin login, credential updates, input validation, and file-based data persistence — all implemented using standard C++ libraries. <br>

<h2>🧠 Problem Statement </h2>
Railway systems require secure and structured user data entry.
This project simulates an admin-managed registration system where:

Admin credentials are validated and can be updated

User inputs are strictly validated (name, email, DOB, etc.)

Validated data is saved persistently in a local file (users.txt) <br>

<h2>💻 Features</h2>
✅ Admin login using a file-based .properties-like config<br>
✅ Create new admin users from CLI<br>
✅ User registration form with full input validation<br>
✅ Retry mechanism on invalid input<br>
✅ Stores user data in users.txt using file streams<br>
✅ Menu-driven CLI navigation<br>
✅ Modular, structured C++ code using classes and functions <br>

<h2>🛠️ Tech Stack</h2>
Technology	Usage <br>
C++ (Core):	Business logic, validation, menu handling<br>
File I/O:	fstream, ifstream, ofstream<br>
Regex:	std::regex for email, phone, and input validation<br>
Input Handling:	cin, getline()<br>

<h2>📁 Folder Structure </h2>
<pre>
RailwayAuth-CLI-master/
├── src/
│   └── AssignmentProgram.cpp
├── resources/
│   ├── userLogin.properties
│   └── users.txt
├── .gitignore
├── README.md
└── LICENSE
</pre>

🚀 How to Run
Clone this repo:

bash
Copy
Edit
git clone https://github.com/notsuhani/RailwayAuth-CLI-master.git
cd RailwayAuth-CLI-master
Compile & Run the program:

bash
Copy
Edit
cd src
g++ AssignmentProgram.cpp -o railwayauth
./railwayauth   # or railwayauth.exe on Windows
Make sure resources/userLogin.properties exists with default credentials.

<h2>🔐 Admin Credentials</h2>
Stored in: resources/userLogin.properties<br>

properties<br>
Copy<br>
Edit<br>
adminUserId=suhani<br>
adminPassword=1234<br>
You can update these credentials using the "Create New Admin" CLI option.<br>

<h2>📌 Future Enhancements</h2>
Switch from file-based storage to SQLite or PostgreSQL using C++ DB libraries<br>

Implement DAO pattern<br>

Add ticket booking and train search modules<br>

Add GUI using Qt or SFML<br>

Use hashing/encryption for password storage (e.g., SHA256)<br>

<h2>🧑‍💻 Author</h2>
Suhani Mishra

