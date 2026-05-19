# 🏦 Bank Management System
A console-based banking application built in C++ demonstrating core Object-Oriented Programming principles — inheritance, encapsulation, abstraction, polymorphism, interfaces, and design patterns — with authentication, role-based permissions, encrypted passwords, transfer logging, and full audit trails.

---

## 📋 Project Overview
This project simulates a real-world bank management system where authenticated users manage clients, perform transactions, manage system users, and operate under role-based permissions — all backed by file-based persistence with encrypted passwords and full audit logging.

---

## 🧠 OOP Concepts Covered
- **Encapsulation** — Private data members with controlled access via getters/setters and mode pattern
- **Inheritance** — `clsPerson → clsBankClient`, `clsPerson → clsUser`, `clsScreen → all screen classes`
- **Abstraction** — Screens interact with the model through clean public interfaces without knowing implementation details
- **Polymorphism** — Virtual functions and method overriding
- **Abstract Classes & Interfaces** — `clsInterfaceCommunication` defines a pure virtual contract implemented by `clsPerson`
- **Static vs Instance Methods** — Static factory methods, finders, and utility functions alongside instance methods
- **Object State Management** — `enMode` pattern (EmptyMode, UpdateMode, AddNewMode, DeleteMode)
- **Const Correctness** — All read-only methods and parameters marked `const`
- **Defensive Programming** — Two-layer validation at both screen and model level
- **Bitwise Operations** — Permission system using OR to combine, AND to check

---

## 🏗️ Architecture

```
clsInterfaceCommunication        (pure virtual interface)
    └── clsPerson                (base person data — implements interface)
            ├── clsBankClient    (client data + business logic + file I/O)
            └── clsUser          (system user + permissions + authentication)

clsScreen                        (base screen utilities + permission checker)
    ├── clsLoginScreen
    ├── clsMainScreen
    ├── clsListClientsScreen
    ├── clsAddNewClientScreen
    ├── clsDeleteClientScreen
    ├── clsUpdateClientScreen
    ├── clsFindClientScreen
    ├── clsTransactionsScreen
    │       ├── clsDepositScreen
    │       ├── clsWithDrawScreen
    │       ├── clsTotalBalancesScreen
    │       ├── clsTransferScreen
    │       └── clsTransferLogScreen
    ├── clsManageUsersScreen
    │       ├── clsListUsersScreen
    │       ├── clsAddNewUserScreen
    │       ├── clsDeleteUserScreen
    │       ├── clsUpdateUserScreen
    │       └── clsFindUserScreen
    └── clsLoginRegisterScreen

clsInputValidate                 (input validation utilities)
clsString                        (string utilities + encryption)
clsDate                          (date/time utilities)
clsUtil                          (number to string utilities)
Global.h                         (global state: CurrentUser)
```

---

## ✨ Features

### 🔐 Authentication
- Login screen with credential validation
- Lock system after 3 failed login attempts
- Logout with automatic return to login screen
- Login attempts tracked as local variable — resets each session

### 👥 Client Management (CRUD)
- List all clients in a formatted table with total count
- Add new client with duplicate account number protection (two-layer check)
- Delete client with confirmation prompt
- Update client information with confirmation prompt
- Find client by account number

### 💰 Transactions
- **Deposit** — Add funds with negative amount validation at both screen and model level
- **Withdraw** — Remove funds with insufficient balance protection at both layers
- **Transfer** — Transfer funds between accounts with automatic transfer log registration
- **Total Balances** — Display all account balances with grand total and number in words

### 👤 User Management (CRUD)
- Full CRUD operations for system users
- Username-based identification
- Permission assignment per user using bitwise operations

### 🔑 Role-Based Permissions
- Bitwise permission system — each permission is a power of 2
- Permissions stored as a single integer — OR to combine, AND to check
- Admin flag (`pAll = -1`) grants all permissions automatically
- Permissions: List Clients, Add Client, Delete Client, Update Client, Find Client, Transactions, Manage Users, Login Register

### 📝 Logging & Audit
- **Login Register** — logs every successful login with date, username, encrypted password, permission level
- **Transfer Log** — records every transfer with date, source account, destination account, amount, balances after transfer, and performing user
- Dedicated screen to view login register
- Dedicated screen to view transfer log

### 🔒 Security
- Passwords encrypted using Caesar cipher before storing in `Users.txt`
- Passwords encrypted in login register log
- Permission to view login register controlled per user (`pLoginRegister = 128`)
- System lockout after 3 failed login attempts

### 📡 Interface (Extension 10)
- `clsInterfaceCommunication` — pure virtual interface defining communication contract
- Methods: `SendEmail()`, `SendFax()`, `SendSMS()`
- `clsPerson` implements the interface — any person in the system can communicate
- Demonstrates how interfaces enforce contracts across the inheritance hierarchy

---

## 🔧 Extensions

| # | Feature | Status |
|---|---|---|
| 01 | Add date and logged-in user to all screens | ✅ |
| 02 | Lock system after 3 failed login attempts | ✅ |
| 03 | Register logins in a log file | ✅ |
| 04 | Show login register screen | ✅ |
| 05 | Permission to view login register screen | ✅ |
| 06 | Transfer funds between accounts | ✅ |
| 07 | Create transfer log | ✅ |
| 08 | Show transfers log screen | ✅ |
| 09 | Encrypt passwords in file | ✅ |
| 10 | Abstract class / interface practical example | ✅ |

---

## 🎯 Design Patterns Used

### Mode Pattern (Active Record)
Objects carry their own state via `enMode` enum:
```cpp
enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
```
`Save()` routes behavior based on current mode — object transitions from `AddNewMode` to `UpdateMode` after first save.

### Screen Architecture
Every screen is a class inheriting from `clsScreen` with a single public entry point:
```cpp
class clsAddNewClientScreen : protected clsScreen
{
    static void _ReadClientData(clsBankClient& Client);
    static void _PrintClient(const clsBankClient& Client);
public:
    static void Show();
};
```

### Factory Methods
```cpp
clsBankClient::GetAddNewClientObject(AccNumber);
clsBankClient::Find(AccNumber);
clsUser::Find(UserName, Password);
```

### Bitwise Permission System
```cpp
// OR to build permissions
Permission = (pListClients | Permission);
Permission = (pDeleteClient | Permission);

// AND to check
(FeatureNumber & Permission) == FeatureNumber

// Admin
pAll = -1  // 11111111 — passes every check
```

### Defensive Programming (Two Layers)
```cpp
// Screen — UX layer
while (Amount < 0) { cout << "Invalid..."; }

// Model — safety layer
bool Deposit(const float &Amount) {
    if (Amount < 0) return false;
}
```

### Interface Contract
```cpp
class clsInterfaceCommunication
{
public:
    virtual void SendEmail(const string& Title, const string& Body) = 0;
    virtual void SendFax(const string& Title, const string& Body) = 0;
    virtual void SendSMS(const string& Title, const string& Body) = 0;
};
```

---

## 📁 File Structure
```
Clients.txt              — client records
Users.txt                — system user records with encrypted passwords
LoginRegister.txt        — login audit trail (passwords encrypted)
TransferLogRegister.txt  — transfer records
```

### Record Formats
```
Clients.txt:
FirstName#//#LastName#//#PhoneNumber#//#Email#//#AccNumber#//#PinCode#//#Balance

Users.txt:
FirstName#//#LastName#//#PhoneNumber#//#Email#//#UserName#//#EncryptedPassword#//#Permissions

LoginRegister.txt:
DateTime#//#UserName#//#EncryptedPassword#//#Permission

TransferLogRegister.txt:
DateTime#//#SenderAccNum#//#ReceiverAccNum#//#Amount#//#SenderBalanceAfter#//#ReceiverBalanceAfter#//#UserName
```

---

## 🔑 Key Classes

| Class | Responsibility |
|---|---|
| `clsInterfaceCommunication` | Pure virtual interface — communication contract |
| `clsPerson` | Base person data — implements communication interface |
| `clsBankClient` | Client data, banking operations, file persistence |
| `clsUser` | System user, permissions, authentication, login logging |
| `clsScreen` | Base screen utilities, permission checking |
| `clsInputValidate` | All input validation |
| `clsString` | String utilities, encrypt/decrypt |
| `clsDate` | Date/time utilities |

---

## 🌍 Global State
```cpp
// Global.h — only one global variable in the entire project
clsUser CurrentUser = clsUser::Find("", "");  // tracks logged-in user
```

---

## 🚀 How to Run
1. Clone or download the project
2. Open in Visual Studio (Windows)
3. Build and run
4. Login with credentials from `Users.txt`
5. Admin account has full permissions (`Permission = -1`)

> ⚠️ Uses MSVC-specific features (`__declspec(property)`). Compile with Visual Studio on Windows.

---

## 📚 What I Learned
- Designing class hierarchies that scale cleanly
- Separating UI logic from business logic from data persistence
- Object state management with the mode pattern
- Defensive programming at multiple layers
- Bitwise operations for compact permission storage
- Authentication and basic security concepts
- File-based audit logging
- Password encryption (Caesar cipher)
- Role-based access control
- Abstract classes and interfaces in C++
- The difference between interface and abstract class
- Circular reference and how to avoid it
- Const correctness and why it matters
- Global vs local variable scope decisions
- When to apply design patterns and when to keep it simple
- Active Record pattern vs layered architecture tradeoffs
- The `override` keyword and why it matters

---

## 🎓 Course
Based on: **OOP As It Should Be — Applications** by Programming Advices
