class Solution {
public:
    
    unordered_map<int,string> map;
    int key=1;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        map[key]=longUrl;
        key++;
        
        return to_string(key-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));