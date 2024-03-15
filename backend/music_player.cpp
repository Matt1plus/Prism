#include "music_player.h"

using namespace web;
using namespace http;
using namespace http::experimental::listener;

void MusicPlayer::handleGetMusicLibrary(http_request request) {
    json::value jsonResponse;
    for (const auto& entry : musicLibrary) {
        jsonResponse[utility::conversions::to_string_t(entry.first)] = json::value::string(utility::conversions::to_string_t(entry.second.title));
    }
    request.reply(status_codes::OK, jsonResponse);
}

void MusicPlayer::handleFileUpload(http_request request) {
    // Implement file upload logic here
    // Extract file from request and save it to the server
    // Extract title and image path from request
    // Add entry to musicLibrary
    // Respond with success or failure message
}

void MusicPlayer::handleLogin(http_request request) {
    // Implement user login logic here
    // Extract username and password from request
    // Check if user exists in users vector
    // Respond with success or failure message
}

void MusicPlayer::handleSignup(http_request request) {
    // Implement user signup logic here
    // Extract username and password from request
    // Add user to users vector
    // Respond with success or failure message
}
