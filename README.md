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

## Running Locally

```bash
# Quick start
npm install
npm start

# Or manually:
g++ -o search_engine Mini_Search_Engine_CLI.cpp -std=c++11
cd web-interface && npm install && node server.js

# Visit http://localhost:3000
```

## Deployment (Render)

1. Fork/clone this repo
2. Connect to [Render.com](https://render.com)
3. Build Command: `npm run build`
4. Start Command: `npm start`
5. Auto-deploys on push!

## Architecture

```
Query → Node.js API → C++ Search Engine → Ranked Results → JSON Response
```

The C++ engine handles file parsing, regex matching, and ranking. Node.js provides the web interface and API.

## Project Structure

```
minisearchengine/
├── Mini_Search_Engine_CLI.cpp   # C++ search engine
├── Generic_Problem.txt           # Problem database
├── Generic_Solution.txt          # Solution URLs
├── package.json                  # Build scripts
└── web-interface/
    ├── server.js                 # Express API
    └── public/                   # Frontend
```

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
- Deployment and DevOps basics

## Key Features

**Multi-word Search:** Query is tokenized and each word is searched independently  
**Relevance Ranking:** Results ranked by how many search terms match  
**Case Insensitive:** Matches "Array", "array", and "ARRAY"  
**Smart Pattern Matching:** Word boundaries prevent partial matches  
**Real-time Results:** Instant search through 455+ problems

## Development Journey

Built over 7 days during interview prep. Main challenges:
- Regex pattern matching (word boundaries)
- Vector bounds checking for multi-word queries
- File path handling for deployment
- Result ranking algorithm design

## Future Improvements

- Auto-complete using Trie data structure
- Fuzzy search for typos (Levenshtein distance)
- Query caching with LRU eviction
- Problem difficulty filtering
- Mobile app version

---

**Repository:** [github.com/prithamnandavaram/minisearchengine](https://github.com/prithamnandavaram/minisearchengine)  
**Tech:** C++11, STL, Node.js, Express, Regex  
**Database:** Striver's A2Z DSA Sheet (455 problems)
