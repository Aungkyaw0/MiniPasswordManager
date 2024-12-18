
## Technical Details

### Program Structure
- Written in C programming language
- Uses array-based storage system
- Implements custom string manipulation functions
- Command-line interface (CLI) based interaction

### Key Components
1. **Data Storage**
   - Uses 3D arrays for user credentials storage
   - Separate arrays for different types of data:

     - `PM[10][3][100]`: Main user credentials

     - `UserDescription[10][100]`: Platform descriptions
     - `UserEmail[10][10][100]`: Email storage
     - `UserPass[10][10][100]`: Password storage

2. **Core Functions**

   - `CheckCredential()`: Handles user authentication

   - `Register()`: Manages new user registration
   - `ViewAllData()`: Displays all stored credentials
   - `AddData()`: Adds new platform credentials
   - `ViewData()`: Shows platform-specific credentials

3. **Helper Functions**

   - `clean()`: Clears console screen

   - `scan()`: Custom string input handler
   - `StrLen()`: Custom string length calculator
   - `cmp()`: Custom string comparison
   - `StrAdd()`: Custom string concatenation
   - `ScanfIntHandling()`: Input validation for integers

### Memory Management
- Fixed-size arrays with following limitations:

  - Maximum 10 users (`PM[10][][]`)

  - Maximum 100 characters per string (`[100]`)
  - Maximum 10 entries per user (`UserEmail[10][10][]`)

## Development

### Build Requirements
- C compiler (GCC recommended)
- Standard C libraries:

  - `stdio.h`

  - `stdlib.h`

### Project Structure
```
password-manager/
├── main.c          # Main source code
├── README.md       # Documentation
└── LICENSE         # License file
```

### Compilation Flags
```bash
# Basic compilation
gcc main.c -o password_manager

# With warnings enabled (recommended for development)
gcc -Wall -Wextra main.c -o password_manager
```


