#include "music_player.h"
#include <iostream>

using namespace web;
using namespace http;
using namespace http::experimental::listener;

int main() {
    // Create a URI builder for the desired address
    uri_builder uriBuilder(U("http://localhost:9080"));
    auto addr = uriBuilder.to_uri().to_string();

    // Create a listener configuration
    http_listener_config config;

    // Create the http_listener object using the constructed URI and config
    http_listener listener(addr, config);

    MusicPlayer musicPlayer;

    // Register handler functions for different HTTP methods
    listener.support(methods::GET, std::bind(&MusicPlayer::handleGetMusicLibrary, &musicPlayer, std::placeholders::_1));
    listener.support(methods::POST, std::bind(&MusicPlayer::handleFileUpload, &musicPlayer, std::placeholders::_1));
    listener.support(methods::POST, std::bind(&MusicPlayer::handleLogin, &musicPlayer, std::placeholders::_1));
    listener.support(methods::POST, std::bind(&MusicPlayer::handleSignup, &musicPlayer, std::placeholders::_1));

    try {
        // Start listening for requests
        listener
            .open()
          .then([&listener, addr]() {
            // Use std::wcout to output the listening address
             std::wcout << L"Listening for requests at: " << addr << std::endl;
        })
            .wait();

        // Wait for user input to exit
        std::cout << "Press Enter to exit." << std::endl;
        std::string line;
        std::getline(std::cin, line);
    } catch (const std::exception &e) {
        // Catch and print any exceptions that occur during execution
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
