# Bank Management System
A console-based banking application built in C++ demonstrating core Object-Oriented Programming principles including inheritance, encapsulation, abstraction, and design patterns — with authentication, role-based permissions, encrypted passwords, transfer logging, and more.

---

## Project Overview
This project simulates a real-world bank management system where authenticated users manage clients, perform transactions, manage system users, and operate under role-based permissions — all backed by file-based persistence with encrypted passwords and full audit logging.

---

## OOP Concepts Covered
- **Encapsulation** — Private data members with controlled access via getters/setters and mode pattern
- **Inheritance** — `clsPerson → clsBankClient`, `clsPerson → clsUser`, `clsScreen → all screen classes`
- **Abstraction** — Screens interact with the model through clean public interfaces without knowing implementation details
- **Polymorphism** — Virtual functions and abstract classes (Extension 10)
- **Static vs Instance Methods** — Static factory methods, finders, and utility functions alongside instance methods
- **Object State Management** — `enMode` pattern (EmptyMode, UpdateMode, AddNewMode, DeleteMode)

---

## Architecture

```
clsPerson                        (base person data)
    ├── clsBankClient            (client data + business logic + file I/O)
    └── clsUser                  (system user + permissions + authentication)

clsScreen                        (base screen utilities)
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
clsString                        (string utilities)
```

---

## Features

### Authentication
- Login screen with credential validation
- Lock system after 3 failed login attempts
- Logout with automatic return to login screen
- Logged-in user and current date displayed on all screens

### Client Management (CRUD)
- List all clients in a formatted table with total count
- Add new client with duplicate account number protection
- Delete client with confirmation prompt
- Update client information
- Find client by account number

### Transactions
- **Deposit** — Add funds with negative amount validation
- **Withdraw** — Remove funds with insufficient balance protection
- **Transfer** — Transfer funds between two accounts with transfer log
- **Total Balances** — Display sum of all account balances

### User Management (CRUD)
- Full CRUD operations for system users
- Role-based permissions per user
- Restrict access to specific menu options based on user permissions

### Logging & Audit
- Login register — logs every login attempt with timestamp and username
- Transfer log — records every transfer with source, destination, amount and date
- View login register screen
- View transfers log screen

### Security
- Passwords encrypted in file storage
- Permission to view login register controlled per user
- System lockout after failed login attempts

---

## Extensions

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

## Design Patterns Used

### Mode Pattern
Objects carry their own state via `enMode` enum:
```cpp
enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };
```
`Save()` routes behavior based on current mode — no need for separate add/update/delete methods at the caller level.

### Screen Architecture
Every screen is a class inheriting from `clsScreen`:
```cpp
class clsAddNewClientScreen : protected clsScreen
{
    // private helpers
    static void _ReadClientData(clsBankClient& Client);
    static void _PrintClient(const clsBankClient& Client);
public:
    static void Show();  // single public entry point
};
```

### Factory Methods
Objects are created through static factory methods rather than direct construction:
```cpp
clsBankClient::GetAddNewClientObject(AccNumber);
clsBankClient::Find(AccNumber);
clsUser::Find(Username, Password);
```

### Defensive Programming (Two-Layer Validation)
- **Screen layer** — blocks invalid input before reaching the model (UX)
- **Model layer** — protects data integrity regardless of caller (safety)

---

## File Structure
```
Clients.txt           — client records (delimited by #//#)
Users.txt             — system user records with encrypted passwords
LoginLog.txt          — login audit trail
TransferLog.txt       — transfer records
```

### Record Format (Clients.txt)
```
FirstName#//#LastName#//#PhoneNumber#//#Email#//#AccNumber#//#PinCode#//#Balance
```

### Record Format (Users.txt)
```
FirstName#//#LastName#//#PhoneNumber#//#Email#//#Username#//#EncryptedPassword#//#Permissions
```

### Record Format (LoginLog.txt)
```
DateTime#//#Username#//#Password#//#Status
```

### Record Format (TransferLog.txt)
```
DateTime#//#SourceAccount#//#DestinationAccount#//#Amount#//#BalanceAfter
```

---

## Key Classes

### `clsBankClient`
- Inherits from `clsPerson`
- Manages all client data and file persistence
- Key methods: `Find()`, `Save()`, `Delete()`, `Deposit()`, `WithDraw()`, `Transfer()`, `GetClientsList()`, `GetTotalBalances()`

### `clsUser`
- Inherits from `clsPerson`
- Manages system users and permissions
- Handles authentication via `Find(Username, Password)`
- Tracks failed login attempts

### `clsScreen`
- Base class for all screens
- Provides shared UI utilities: `_ShowScreenHeader(Title, SubTitle)`
- Displays logged-in user and current date on all screens

### `clsInputValidate`
- Static utility class for all input validation
- Methods: `ReadString()`, `ReadFloatNumber()`, `ReadDblNumber()`, `ReadShortNumberBetween()`, etc.

### `clsString`
- Static string utility class
- Methods: `Split()`, `Encrypt()`, `Decrypt()`, etc.

---

## How to Run
1. Clone or download the project
2. Open in Visual Studio (Windows)
3. Build and run
4. Login with default credentials from `Users.txt`

> **Note:** Project uses `__declspec(property)` which is MSVC-specific. Compile with Visual Studio on Windows.

---

## What I Learned
- Designing class hierarchies that scale
- Separating UI logic from business logic from data persistence
- The importance of object state management
- Defensive programming at multiple layers
- Authentication and basic security concepts
- File-based audit logging
- Password encryption
- Role-based access control
- Abstract classes and interfaces in C++
- When to apply design patterns and when to keep it simple
- `const` correctness and why it matters
- The difference between a working design and a scalable one

---
