#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <vector>
#include <sstream>
#include <map>
#include <regex>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Map: line number -> problem text
map<int,string> problemLineMap;
// Map: line number -> solution URL or metadata
map<int,string> solutionUrlMap;

// Structure to hold search results with their relevance score
struct SearchResult {
    int lineNumber;
    string problemText;
    string solutionURL;
    int matchCount;
    
    // Constructor
    SearchResult(int ln, string text, string url, int count) : 
        lineNumber(ln), problemText(text), solutionURL(url), matchCount(count) {}
    
    // For sorting in descending order of match count
    bool operator < (const SearchResult& other) const {
        return matchCount > other.matchCount; // Note: ">" for descending order
    }
};

class Problems{
public:
    std::pair<int,string> SearchProblemExist(int,string,int);
}getProblem;

class Solutions: public Problems{
public:
    // For each query word index (0..9), store the list of line numbers that matched that word
    vector<int> wordMatchedLines[10];
    long Life_solution(string,int);
    string subSearch(int,int,string);
    void printQuestions(int fetchQuestion){
        cout<<"Question less Proabable"<<fetchQuestion<<endl;
    }
}solution;

long Solutions::Life_solution(string word, int wordIndex){
    
    int y=0;
    long sub_search_count = 0;
    string line;
    std::smatch m;
    
    cerr << "Searching for word '" << word << "' at position " << wordIndex+1 << endl;
    
    // moving the file into map container
    string problemFilePath = "Generic_Problem.txt";
    cerr << "Opening problem file: " << problemFilePath << endl;
    ifstream getFile(problemFilePath);
    
    if (getFile.is_open())
    {
        cerr << "Problem file opened successfully" << endl;
        // Only load the file into map if it's empty (first word)
        if(problemLineMap.empty()) {
            while (getline(getFile,line))
            {
                problemLineMap.insert(std::pair<int,string>(++y,line)); // Assigning Number to a Line or Question !
            }
            cerr << "Loaded " << y << " lines from problem file" << endl;
        }
        // Moved the file to MAP CONTAINER
        
        for(map<int,string>::iterator itr = problemLineMap.begin(); itr!=problemLineMap.end(); ++itr){
            try{
                // Use case-insensitive regex search to find matches
                std::regex e ("\\b" + word +"\\b", std::regex_constants::icase);
                if(std::regex_search(itr->second,m,e))
                {
                    wordMatchedLines[wordIndex].push_back(itr->first); // Array Vector (wordMatchedLines) holds the occurrence of each word with its key value
                    cerr << "Match found for '" << word << "' in line " << itr->first << endl;
                }
            }catch(const std::regex_error& oor) {
                std::cerr << "Regex error: " << oor.code() << '\n';
                break;
            }
        }
        
        if(wordMatchedLines[wordIndex].empty()){
            cerr << "No matches found for word '" << word << "' at wordIndex " << wordIndex << endl;
        }
        else{
            try {
                sub_search_count = wordMatchedLines[wordIndex].size();
                cerr << "Word '" << word << "' found in " << sub_search_count << " lines" << endl;
            }
            catch (const std::out_of_range& oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
            }
        }
        getFile.close();
    }
    return sub_search_count;
}

string Solutions::subSearch(int matchedWordsCount, int totalWords, string queryString){
    
    cerr << "Starting search with " << matchedWordsCount << " matches found out of " << totalWords << " words" << endl;
    std::ofstream out;
    string line;
    int x=0;
    string resultOutput = "";
    
    if(matchedWordsCount > 0 && totalWords > 0){
        try{
            cerr << "Processing search results..." << endl;
            
            // Check if wordMatchedLines has any non-empty vectors
            bool hasResults = false;
            for(int i=0; i<10; i++){
                if(!wordMatchedLines[i].empty()){
                    hasResults = true;
                    break;
                }
            }
            
            if(!hasResults) {
                cerr << "No results found in any filter array" << endl;
                goto no_matches_found;
            }
            
            // Step 3: Combine matches - Count how many query words matched per line
            map<int, int> lineMatchCountMap;
            
            // For each word's filter array, count how many times each line appears
            for(int i=0; i<10 && i<totalWords; i++){
                if(!wordMatchedLines[i].empty()){
                    for(int lineNum : wordMatchedLines[i]){
                        // Increment the count for this line
                        lineMatchCountMap[lineNum]++;
                    }
                }
            }
            
            if(lineMatchCountMap.empty()) {
                cerr << "No line matched any words" << endl;
                goto no_matches_found;
            }
            
            // Load solution URLs if not already loaded
            string solutionFilePath = "Generic_Solution.txt";
            cerr << "Opening solution file: " << solutionFilePath << endl;
            ifstream soln(solutionFilePath);
            if (soln.is_open()) {
                cerr << "Solution file opened successfully" << endl;
                if(solutionUrlMap.empty()) {
                    while (getline(soln, line)) {
                        solutionUrlMap.insert(std::pair<int,string>(++x, line));
                    }
                }
                soln.close();
            } else {
                cerr << "Failed to open solution file" << endl;
            }
            
            // Create a vector of SearchResult objects for sorting
            vector<SearchResult> searchResults;
            
            // Build the search results vector
            for(const auto& lineMatchPair : lineMatchCountMap) {
                int lineNum = lineMatchPair.first;
                int matchCount = lineMatchPair.second;
                
                // Only include if line exists in both maps
                if(problemLineMap.find(lineNum) != problemLineMap.end()){
                    string problemText = problemLineMap[lineNum];
                    string solutionURL = "";
                    
                    if(solutionUrlMap.find(lineNum) != solutionUrlMap.end()) {
                        solutionURL = solutionUrlMap[lineNum];
                    }
                    
                    // Add to our results
                    searchResults.push_back(SearchResult(lineNum, problemText, solutionURL, matchCount));
                    cerr << "Line " << lineNum << " has " << matchCount << " word matches" << endl;
                }
            }
            
            // Sort the results by match count (descending)
            sort(searchResults.begin(), searchResults.end());
            
            // Build the output string with all matched lines and their match counts
            stringstream output;
            
            // Header for the results
            output << "Search results for: \"" << queryString << "\"\n";
            output << "Found " << searchResults.size() << " results\n\n";
            
            // Add each result to the output
            for(const auto& result : searchResults) {
                output << "Match score: " << result.matchCount << "/" << totalWords << " words\n";
                output << "Line " << result.lineNumber << ": " << result.problemText << "\n";
                if(!result.solutionURL.empty()) {
                    output << "Solution: " << result.solutionURL << "\n";
                }
                output << "\n";
            }
            
            return output.str() + "|MULTIPLE_RESULTS";
        }
        catch(const std::out_of_range& oor) {
            std::cerr << "Out of Range error: " << oor.what() << '\n';
            return "Error: Out of range error occurred.|";
        }
        catch(const std::exception& ex) {
            std::cerr << "Exception: " << ex.what() << '\n';
            return "Error: An exception occurred while processing search.|";
        }
        catch(...) {
            std::cerr << "Unknown error occurred\n";
            return "Error: An unknown error occurred while processing search.|";
        }
    }
    
no_matches_found:
    // No matches found, add the search query to the problems file
    string problemFilePath = "Generic_Problem.txt";
    out.open(problemFilePath, std::ios::app);
    std::string str = queryString;
    out << endl;
    out << problemLineMap.size()+2 << "." << str;
    out.close();
    return "No matches found. Your query has been added to our database.|";
}

int main(int argc, char* argv[]){
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " \"your search query\"" << endl;
        return 1;
        
    }
    
    string queryString = argv[1];
    string arr[20];
    int i = 0;
    int q = 0;
    int wordPresent = 0;
    map<int,string> queryWordMap;
    
    // Forming array format of string
    stringstream ssin(queryString);
    while (ssin.good() && i < 20){
        ssin >> arr[i];
        ++i;
    }
    
    // check entered string is empty or not and then inserting & mapping the string with key and value in queryWordMap Map
    int noOfwords = i;
    cerr << "Query contains " << noOfwords << " words" << endl;
    
    for(int x=0; x<20; x++){
        if(arr[x]==""){
            break;
        }
        else {
            queryWordMap.insert(std::pair<int,string>(x+1,arr[x]));
        }
    }
    
    // Clear any previous search data from the wordMatchedLines vectors
    for(int j=0; j<10; j++){
        solution.wordMatchedLines[j].clear();
    }
    
    // Search for each word independently
    for(map<int,string>::iterator it = queryWordMap.begin(); it!=queryWordMap.end(); ++it)
    {
        q +=1;
        if(q > noOfwords || q > 20) break; // Safety check
        
        cerr << "Searching for word '" << queryWordMap.at(q) << "' at position " << q << endl;
        long wordFound = solution.Life_solution(queryWordMap.at(q), q-1);
        if(wordFound>0){
            ++wordPresent;
            cerr << "Word '" << queryWordMap.at(q) << "' found, wordPresent incremented to " << wordPresent << endl;
        }
    }
    
    cerr << "Starting subSearch with wordPresent: " << wordPresent << ", noOfwords: " << noOfwords << endl;
    string result = solution.subSearch(wordPresent, noOfwords, queryString);
    cout << result;
    return 0;
}
