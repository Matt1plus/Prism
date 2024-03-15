#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <map>
#include <string>
#include <vector>
#include <sqlite3.h> // Include SQLite3 header

struct MusicFileInfo {
    std::string title;
    std::string imagePath;
    std::string filePath;
};

class MusicPlayer {
public:
    void handleGetMusicLibrary(web::http::http_request request);
    void handleFileUpload(web::http::http_request request);
    void handleLogin(web::http::http_request request);
    void handleSignup(web::http::http_request request);

    MusicPlayer(); // Constructor
    ~MusicPlayer(); // Destructor

private:
    std::map<std::string, MusicFileInfo> musicLibrary;
    std::vector<std::pair<std::string, std::string>> users; // username, password

    // Database
    sqlite3* db; // SQLite3 database connection
    void initializeDatabase();
    void saveUser(const std::string& username, const std::string& password);
    bool checkUser(const std::string& username, const std::string& password);
    void saveMusicFile(const MusicFileInfo& fileInfo);
    void loadMusicLibrary();
};

#endif // MUSIC_PLAYER_H
