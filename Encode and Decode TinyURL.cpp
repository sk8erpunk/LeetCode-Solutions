/*
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work.
You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

class Solution {
  
    unordered_map<string,string> codeToUrl;
    unordered_map<string,string> urlToCode;
    string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFJHIJKLMNOPQRSTUVWXYZ";
    int codeSize = 6;
    int codeStart = 19;

	public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while(urlToCode.count(longUrl) == 0){
            string code = "";                       // genereate code of size 6 for tinyURL
            for(int i = 0; i < codeSize; i++){
                int idx = rand() % chars.size();
                code += chars[idx];
            }
            if(codeToUrl.count(code) == 0){
                codeToUrl[code] = longUrl; 
                urlToCode[longUrl] = code; 
            }
        }
        return "http://tinyurl.com/" + urlToCode[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(codeStart,codeSize);      // extract code
        return codeToUrl[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));