# 🏦 Bank System — C++

A console-based bank management system built in C++.

This is a rebuild of the same project I previously implemented using **procedural programming**. The reason for rebuilding it with **OOP** is to apply proper software design — encapsulating data, controlling access, and making the system more secure and maintainable as it grows.

---

## ✨ Features

### 👤 Client Management
- Find, add, update, and delete clients
- List all clients
- View total balances

### 👥 User Management
- Find, add, update, and delete users
- List all users
- Role-based permissions per screen

### 💸 Transactions
- Deposit and withdraw
- Transfer between accounts
- View transfer log

### 🔒 Security
- Login / Logout
- Lock system after 3 failed login attempts
- Encrypted passwords stored in file
- Login activity log

### 🗄️ Storage
- Clients and users are stored in flat text files (`Clients.txt`, `Users.txt`)

---

## 🔄 What Changed from the Procedural Version

The procedural version used open structs, free functions, and no access control — any part of the code could read or modify any data directly.

The OOP version improves on this in the following ways:

- 🔐 **Encapsulation** — all data is private, accessible only through getters and setters
- 🧬 **Inheritance** — `clsPerson` holds shared personal data, `clsBankClient` and `clsUser` extend it without duplicating fields
- 🚦 **Access control via `enMode`** — objects know whether they are valid or empty, preventing operations on invalid data
- 🏭 **Static factory methods** — objects are created in a controlled way instead of being assembled freely anywhere in the code
- 🛡️ **Password encryption** — passwords are encrypted before being written to file, unlike the procedural version which stored them as plain text
- 🧹 **Cleaner separation of concerns** — each class is responsible for its own data and operations