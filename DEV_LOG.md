# Development Log

## Day 1 - Initial Idea (Sept 15)
- Frustrated with scrolling through 200+ solved problems in my text file
- Decided to build a search engine instead of switching to Excel
- Started with basic C++ file reading and regex matching

## Day 2-3 - Core Engine (Sept 16-17)
- Implemented map-based storage for problems and URLs
- Added multi-word search capability
- Struggled with regex patterns at first (kept getting partial matches)
- Fixed with word boundaries (\b...\b)

## Day 4 - Ranking System (Sept 18)
- Realized single-word search wasn't enough
- Added relevance scoring based on match count
- Created SearchResult struct for better organization
- Spent hours debugging vector out-of-bounds errors

## Day 5-6 - Web Interface (Sept 19-20)
- Built Node.js API wrapper around C++ engine
- Created simple HTML/CSS frontend
- Added error handling for edge cases
- Tested with various query combinations

## Day 7 - Polish & Deploy (Sept 21)
- Fixed file path issues for deployment
- Added environment variable support
- Created build scripts and documentation
- Ready for production!

## Challenges Faced
1. **Regex Complexity**: Initially matched partial words, fixed with word boundaries
2. **Memory Management**: Vector out-of-bounds when combining search results
3. **File Paths**: Absolute paths broke deployment, switched to relative
4. **Multi-word Logic**: Had to redesign ranking algorithm for better relevance

## What I Learned
- STL containers are incredibly powerful
- Regex can be tricky but very flexible
- System design matters even for small projects
- Building APIs around existing CLI tools is a great pattern

## Future Plans
- Add auto-complete with Trie
- Implement fuzzy search for typos
- Add caching for frequent queries
- Maybe convert to a mobile app

---
*Total development time: ~20 hours over 1 week*