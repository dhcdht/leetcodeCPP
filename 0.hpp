// https://leetcode.com/problems/encode-and-decode-tinyurl/#/description
// 535. Encode and Decode TinyURL
#import <iostream>
#import <string>
#import <unordered_map>

using namespace std;

class Solution0 {
private:
    unordered_map<string, string> urls;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto count = this->urls.size();
        auto shortURL = "http://tinyurl.com/" + to_string(count);
        this->urls[shortURL] = longUrl;

        return shortURL;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return this->urls[shortUrl];
    }

    void test() {
        auto result = this->encode("https://leetcode.com/problems/design-tinyurl");
        cout << result << endl;
        cout << this->decode(result) << endl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));