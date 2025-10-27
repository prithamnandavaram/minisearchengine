# Search Engine

## Overview

A text-based search engine built in C++ with a web interface. I created this to solve my own problem of quickly searching through a large collection of text entries instead of manually scrolling through files.

## Features

- Multi-word search queries
- Relevance ranking (more matching words = higher rank)
- Case-insensitive pattern matching
- Real-time search results
- Web-based interface
- Handles 455+ entries efficiently

## Tech Stack

**Backend:** C++ with STL (maps, vectors, regex)  
**API:** Node.js + Express  
**Frontend:** HTML/CSS/JavaScript  
**Data Storage:** Text files

## Quick Start

```bash
# Install and run
npm install
npm start

# Visit http://localhost:3000
```

## How It Works

1. Data is stored in two text files: entries and their metadata
2. C++ engine tokenizes queries and uses regex for pattern matching
3. Results are ranked by relevance (number of matching terms)
4. Node.js API serves the web interface and executes the C++ engine

## Architecture

```
User Query → Express API → C++ Engine → Ranked Results → JSON Response
```

## Deployment

**Live Demo:** https://minisearchengine.onrender.com

Deploy on Render:
1. Connect GitHub repository
2. Build Command: `npm run build`
3. Start Command: `npm start`
4. Deploy!

## Key Technical Features

- **Efficient Search:** O(N*M*W) complexity where N=entries, M=avg length, W=query words
- **Smart Ranking:** Uses match count for relevance scoring
- **Regex Pattern Matching:** Word boundaries prevent partial matches
- **STL Containers:** Maps for O(log n) access, vectors for dynamic storage

## Sample Searches

Try searching for:
- Single words: "array", "tree", "stack"
- Multiple words: "binary search", "dynamic programming"
- Specific topics: "graph traversal", "sorting algorithms"

## What I Learned

- Practical application of C++ STL containers
- Regex optimization and pattern matching
- Building REST APIs with Node.js
- Integrating compiled binaries with web services
- System design for search functionality

---

**Repository:** [github.com/prithamnandavaram/minisearchengine](https://github.com/prithamnandavaram/minisearchengine)  
**Tech:** C++11, STL, Node.js, Express, Regex
