document.addEventListener('DOMContentLoaded', () => {
    const searchForm = document.getElementById('search-form');
    const searchInput = document.getElementById('search-input');
    const resultsSection = document.getElementById('results');
    const resultText = document.getElementById('result-text');
    const resultURL = document.getElementById('result-url');
    const resultURLContainer = document.getElementById('result-url-container');
    const noResultsSection = document.getElementById('no-results');
    const errorSection = document.getElementById('error');
    const loadingSection = document.getElementById('loading');
    
    // Function to format multiple results
    function formatMultipleResults(content) {
        // Replace newlines with HTML line breaks
        return content.split('\n').map(line => {
            // Special formatting for solution URLs
            if (line.startsWith('Solution:')) {
                const url = line.substring(line.indexOf('http'));
                return `Solution: <a href="${url}" target="_blank">${url}</a>`;
            }
            // Make match scores bold
            else if (line.startsWith('Match score:')) {
                return `<strong>${line}</strong>`;
            }
            // Make line numbers italic
            else if (line.match(/^Line \d+:/)) {
                return `<em>${line}</em>`;
            }
            return line;
        }).join('<br>');
    }
    
    searchForm.addEventListener('submit', async (e) => {
        e.preventDefault();
        
        const query = searchInput.value.trim();
        
        if (!query) {
            return;
        }
        
        // Reset UI
        resultsSection.classList.add('hidden');
        noResultsSection.classList.add('hidden');
        errorSection.classList.add('hidden');
        loadingSection.classList.remove('hidden');
        
        try {
            const response = await fetch('/api/search', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({ query })
            });
            
            loadingSection.classList.add('hidden');
            
            if (!response.ok) {
                throw new Error('Error in API response');
            }
            
            const data = await response.json();
            
            if (data.resultText.startsWith('No matches found')) {
                noResultsSection.classList.remove('hidden');
                return;
            }
            
            // Display results
            resultsSection.classList.remove('hidden');
            
            if (data.multipleResults) {
                // Format multiple results with HTML
                resultText.innerHTML = formatMultipleResults(data.resultText);
                resultURLContainer.classList.add('hidden');
            } else {
                // Single result display
                resultText.textContent = data.resultText;
                
                if (data.resultURL && data.resultURL.trim() !== '') {
                    resultURLContainer.classList.remove('hidden');
                    resultURL.textContent = data.resultURL;
                    resultURL.href = data.resultURL;
                } else {
                    resultURLContainer.classList.add('hidden');
                }
            }
            
        } catch (error) {
            console.error('Error:', error);
            loadingSection.classList.add('hidden');
            errorSection.classList.remove('hidden');
        }
    });
});
