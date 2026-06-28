#include <bits/stdc++.h>

class FileManagerAndParser {
public:
    int read(char* s, std::streamsize n) {
        return 0;
    }
    void write(const char* s, std::streamsize n) {}
    std::vector<int> parse(const std::string &s);
};

class FileManager {
public:
    int read(char* s, std::streamsize n) { 
        return 0; 
    }
    void write(const char* s, std::streamsize n) {}
};

class Parser {
    std::vector<int> parse(const std::string &s);
};