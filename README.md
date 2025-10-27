# Mini Search Engine Web Interface

This is a simple web interface for the Mini Search Engine C++ project. It allows users to search through a database of problems and solutions via a friendly web interface.

## Project Structure

```
minisearchengine/
├── search_engine          # The compiled C++ executable
├── Mini_Search_Engine_CLI.cpp   # Modified C++ code for CLI usage
└── web-interface/
    ├── public/
    │   ├── index.html     # Web interface HTML
    │   ├── styles.css     # CSS styles
    │   └── script.js      # Frontend JavaScript
    ├── package.json       # Node.js dependencies
    ├── server.js          # Node.js server code
    └── node_modules/      # Node dependencies (generated)
```

## How It Works

1. The C++ code has been modified to accept command-line arguments and output results in a format that can be parsed by the Node.js server.
2. The Node.js server receives search queries from the web interface, executes the C++ program, and returns the results.
3. The web interface allows users to enter search queries and displays the results in a user-friendly manner.

## How to Run

1. Compile the C++ code (if not already done):
   ```
   g++ -std=c++11 Mini_Search_Engine_CLI.cpp -o search_engine
   ```

2. Install Node.js dependencies:
   ```
   cd web-interface
   npm install
   ```

3. Start the Node.js server:
   ```
   cd web-interface
   node server.js
   ```

4. Open your browser and navigate to:
   ```
   http://localhost:3000
   ```

## Requirements

- C++ compiler with C++11 support
- Node.js
- npm (Node Package Manager)

## Notes

- The search engine looks for matches in the `Generic_Problem.txt` file and returns corresponding URLs from the `Generic_Solution.txt` file.
- If no match is found, the query is added to the problems file for future reference.
