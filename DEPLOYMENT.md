# 🚀 Mini Search Engine - Deployment Guide

## Quick Deploy Options

### 1. **Railway (Recommended - Free)**
1. Fork/clone this repo to GitHub
2. Go to [Railway.app](https://railway.app)
3. Connect GitHub account
4. Select this repository
5. Railway auto-detects and deploys!

**Build Command:** `npm run build`  
**Start Command:** `npm start`

### 2. **Render (Free tier)**
1. Go to [Render.com](https://render.com)
2. Connect GitHub repo
3. Set:
   - **Build Command:** `npm run build`
   - **Start Command:** `npm start`
   - **Environment:** Node.js

### 3. **Local Development**
```bash
# Clone and setup
git clone <your-repo>
cd mini-search-engine

# Build C++ engine
g++ -o search_engine Mini_Search_Engine_CLI.cpp -std=c++11

# Install dependencies and start
npm install
npm start

# Access at http://localhost:3000
```

## 📁 Project Structure
```
mini-search-engine/
├── package.json          # Root package with build scripts
├── Procfile              # Deployment process file
├── build.sh              # Build script for C++ compilation
├── Mini_Search_Engine_CLI.cpp  # Core search engine
├── Generic_Problem.txt   # DSA problems database
├── Generic_Solution.txt  # Solution URLs
└── web-interface/
    ├── server.js         # Express API server
    ├── package.json      # Web interface dependencies
    └── public/           # Frontend files
```

## 🔧 Environment Variables
- `PORT` - Server port (auto-set by deployment platforms)
- `NODE_ENV` - Environment (production/development)

## 🛠️ Build Process
1. **C++ Compilation:** `g++ -o search_engine Mini_Search_Engine_CLI.cpp -std=c++11`
2. **Dependencies:** Install Node.js packages
3. **Start:** Launch Express server on PORT

## ✅ Health Check
- Endpoint: `/health`
- Returns: `{"status": "OK", "message": "Mini Search Engine is running!"}`

## 🔍 API Endpoints
- `POST /api/search` - Search DSA problems
- `GET /` - Web interface
- `GET /health` - Health check

## 📱 Features
- 455+ DSA problems searchable
- Multi-word query support
- Relevance ranking
- Real-time search results
- Mobile-responsive interface

---
**Ready to deploy? Just push to GitHub and connect to Railway/Render!** 🚀