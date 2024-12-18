# Password Manager

A simple command-line password manager written in C that allows users to securely store and manage their credentials for different platforms.

## Features

- 🔐 User Authentication System
- 👤 User Registration
- 📝 Store credentials for multiple platforms:
  - GitHub
  - Email
  - Discord
  - Facebook
- 👀 View stored credentials
- 📊 View all data in organized format
- 🔄 Support for multiple users

## Prerequisites

To compile and run this program, you need:

- GCC (GNU Compiler Collection)
- Make (optional, for easier compilation)
- Unix-like environment (Linux/macOS) or Windows

## Installation

1. Clone the repository:
    ```bash
    > git clone https://github.com/yourusername/password-manager.git
    ```
2. Navigate to the project

    ```bash
    > cd password-manager
    ```
3. Compile the program:

- For Unix-like systems (Linux/macOS):

    ```bash
    > gcc main.c -o password_manager
    ```
- For Windows:
    ```bash
    gcc main.c -o password_manager.exe
    ```


#### NOTE : Before compiling on Windows, modify the `clean()` function in `main.c`:
- Find: `system("clear")`
- Replace with: `system("cls")`

## Usage

### 1. Run the compiled program:

```bash
> ./password_manager or password_manager.exe
```

### 2. Main Menu Options:
   - `1` - Login
   - `2` - Register
   - `3` - Exit

### 3. After logging in, you can:
   - Add new credentials
   - View specific platform credentials
   - View all stored credentials
   - Exit to main menu

### 4. Registration
1. Select option `2` from main menu
2. Enter your desired username
3. Enter your email
4. Create a password

### 5. Login
1. Select option `1` from main menu
2. Enter your username or email
3. Enter your password

### 6. Managing Credentials
After successful login, you can:
1. Add Data (Option `1`)
   - Choose platform (GitHub/Email/Discord/Facebook)
   - Enter email and password for the selected platform
   
2. View Data (Option `2`)
   - Select specific platform to view its credentials

3. View All Data (Option `3`)
   - Displays all stored credentials for your account

## Default Accounts

The program comes with these pre-configured accounts for testing:
1.  - Username: Johnny
    - Email: john@gmail.com
    - Password: pass111

2.  - Username: David
    - Email: david@gmail.com
    - Password: 111

3.  - Username: William
    - Email: william@gmail.com
    - Password: Apple112
4.  - Username: Admin
    - Email: admin@gmail.com
    - Password: Admin!!@111


## Security Notes

- Passwords are stored in plain text (not recommended for production use)
- Limited to 10 users and 4 platforms per user
- Data is not persistent (resets when program closes)

## Limitations

- Maximum 10 users
- Fixed number of platforms (4)
- No data encryption
- Data is stored in memory (not persistent)
- One-time credential addition per platform

## Contributing

Feel free to fork this repository and submit pull requests for any improvements.

## License

This project is open source and available under the [MIT License](LICENSE).

## Author

Originally developed by AKT (4.9.22)

---

⚠️ **Disclaimer**: This is a educational project and should not be used for storing actual sensitive information as it doesn't implement proper security measures.
