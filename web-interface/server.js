const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');
const { exec } = require('child_process');
const path = require('path');
const fs = require('fs');

const app = express();
const PORT = process.env.PORT || 3000;

// Middleware
app.use(cors());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, 'public')));

// Health check endpoint for deployment platforms
app.get('/health', (req, res) => {
    res.json({ status: 'OK', message: 'Mini Search Engine is running!' });
});

    // API endpoint to search
app.post('/api/search', (req, res) => {
    const query = req.body.query;
    
    if (!query || query.trim() === '') {
        return res.status(400).json({ error: 'Query cannot be empty' });
    }
    
    // Escape quotes in the query to avoid command injection
    const sanitizedQuery = query.replace(/"/g, '\\"');
    
    // Path to the C++ executable
    const executablePath = path.join(__dirname, '..', 'search_engine');
    const workingDirectory = path.join(__dirname, '..');
    
    console.log(`Executing: "${executablePath}" "${sanitizedQuery}"`);
    // Execute the C++ program with correct working directory
    const searchProcess = exec(`"${executablePath}" "${sanitizedQuery}"`, {
        maxBuffer: 1024 * 1024,
        cwd: workingDirectory  // Set working directory to project root
    }, (error, stdout, stderr) => {
        // Log more detailed information about the execution
        console.log("======== SEARCH ENGINE EXECUTION ========");
        console.log(`Command: "${executablePath}" "${sanitizedQuery}"`);
        console.log(`Exit Code: ${error ? error.code : 0}`);
        console.log(`stdout length: ${stdout ? stdout.length : 0}`);
        
        if (error && error.code !== 0) {
            console.error(`exec error: ${error}`);
            console.error(`stderr: ${stderr}`);
            return res.status(500).json({ error: 'Error executing search engine' });
        }
        
        console.log(`stdout: ${stdout}`);
        if (stderr) {
            console.log(`stderr (debug info): ${stderr}`);
        }
        
        if (!stdout || stdout.trim() === '') {
            console.log("WARNING: Empty response from search engine");
            return res.status(500).json({ error: 'Empty response from search engine' });
        }
        
        // Parse the stdout which should be in format "result|flag"
        const parts = stdout.split('|');
        const resultText = parts[0] || '';
        const resultFlag = parts[1] || '';
        
        console.log("======== PARSING RESULTS ========");
        console.log(`Result parts: ${parts.length}`);
        console.log(`Result text length: ${resultText.length}`);
        console.log(`Result flag: "${resultFlag}"`);
        
        // Check if we have multiple results
        if (resultFlag === 'MULTIPLE_RESULTS') {
            res.json({
                resultText: resultText,
                multipleResults: true
            });
        } else {
            res.json({
                resultText: resultText,
                resultURL: resultFlag || '',
                multipleResults: false
            });
        }
    });
});

// Serve the main HTML page
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

// Handle all other routes (for SPA - Single Page Application)
// This fixes the "Not Found" issue on refresh
app.get('*', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

// Start the server
app.listen(PORT, '0.0.0.0', () => {
    console.log(`🚀 Mini Search Engine running on port ${PORT}`);
    console.log(`📍 Environment: ${process.env.NODE_ENV || 'development'}`);
    console.log(`🔍 Ready to search 455+ DSA problems!`);
});
