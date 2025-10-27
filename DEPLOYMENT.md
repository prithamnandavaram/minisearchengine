# 🚀 Deploying My DSA Search Engine

## Quick Start

This is my personal DSA problem search engine. I built it during interview prep when I got tired of manually searching through 455+ problems in text files.

### Local Testing
```bash
# Build the C++ engine
npm run build

# Start the server  
npm start

# Visit http://localhost:3000
```

### Deploy to Railway (My Recommendation)
1. Push this repo to your GitHub
2. Go to [Railway.app](https://railway.app) 
3. Connect your GitHub account
4. Import this repository
5. Railway automatically detects and builds!

**Build Command:** `npm run build`  
**Start Command:** `npm start`

### Alternative: Render
1. Fork this repo on GitHub
2. Connect to [Render.com](https://render.com)
3. Set build command: `npm run build`
4. Set start command: `npm start`

## How It Works

The deployment process:
1. Compiles the C++ search engine binary
2. Installs Node.js dependencies  
3. Starts the Express server
4. Serves the web interface on the assigned PORT

## Environment Setup

- `PORT` - Server port (auto-set by platforms)
- `NODE_ENV` - Environment mode

## Project Architecture

```
My Text Files → C++ Engine → Node.js API → Web Interface
     ↓              ↓            ↓           ↓
Problem List → Search Logic → REST API → User Interface
```

## API Endpoints

- `GET /` - Web interface
- `POST /api/search` - Search my problems
- `GET /health` - Health check

## Personal Notes

This started as a simple text file where I logged solved problems. Instead of switching to Excel, I built my own search engine. Now I can instantly find any problem from my 455+ collection with smart multi-word search and relevance ranking.

Perfect example of solving a real problem while learning new tech! 🎯

---
**Live demo coming soon!** 🚀