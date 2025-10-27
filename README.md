# Mini Search Engine for DSA Problems

## Why I Built This

During my DSA preparation, I was solving problems daily and logging them in a text file (problem name + URL). After 100+ problems, finding specific ones became painful - I'd either scroll through hundreds of lines or use basic Ctrl+F.

Instead of switching to Excel like my friends, I thought: "Why not build my own search engine?" This way I could:
- Keep my simple text file workflow
- Learn C++ STL containers practically  
- Build something actually useful for my prep
- Have a cool project for interviews

## What It Does

Smart search through my DSA problem collection:
- Multi-word queries (e.g., "binary search tree")
- Relevance ranking (matches more words = higher rank)
- Case-insensitive search
- Web interface for easy access
- Instant results from 455+ problems

## Tech Stack

**Backend:** C++ with STL (maps, vectors, regex)  
**API:** Node.js + Express  
**Frontend:** Vanilla HTML/CSS/JS  
**Data:** Text files (problems + solution URLs)

## How It Works

1. **Data Storage:** Problems stored in `Generic_Problem.txt`, URLs in `Generic_Solution.txt`
2. **Search Logic:** C++ engine tokenizes query, uses regex to find matches
3. **Ranking:** Counts how many query words match each problem
4. **Results:** Returns ranked results with solution links

## Running Locally

```bash
# Compile the C++ engine
g++ -o search_engine Mini_Search_Engine_CLI.cpp -std=c++11

# Start the web server
cd web-interface
npm install
node server.js

# Visit http://localhost:3000
```

## Architecture

```
Query → Node.js API → C++ Search Engine → Ranked Results → JSON Response
```

The C++ engine handles the heavy lifting (file parsing, regex matching, ranking) while Node.js provides the web interface.

## Sample Searches

- "array" → Returns 24 array-related problems
- "binary tree" → Tree problems ranked by relevance  
- "dynamic programming" → DP problems with solution links

## What I Learned

- STL containers performance trade-offs (map vs unordered_map)
- Regex pattern matching and optimization
- File I/O and memory management in C++
- Building REST APIs with Node.js
- System design for search applications

## Future Improvements

- Add auto-complete using Trie data structure
- Implement fuzzy search for typos
- Cache frequent queries
- Add problem difficulty filtering
- Mobile app version

---

**Note:** This is my personal problem tracker turned into a search engine. The database contains Striver's A2Z DSA sheet problems that I've been solving during my preparation.

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
