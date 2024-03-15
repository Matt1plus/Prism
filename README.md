Prism Music Player
Prism Music Player is a simple web-based music player application that allows users to upload, manage, and play their music files. It provides a clean and intuitive user interface for accessing music files and controlling playback.

Features
Music Library: View a list of uploaded music files in the library.
File Upload: Upload music files with associated metadata such as title and cover image.
User Authentication: Secure login and signup functionality for user accounts.
Responsive Design: User interface adapts to different screen sizes for optimal viewing experience.
Cross-Platform Compatibility: Works on major web browsers and operating systems.

frontend: This directory contains files related to the frontend of the application, including the HTML, CSS, and JavaScript 
files responsible for rendering the user interface and handling user interactions.

backend: Here, you'll find the backend implementation files, including music_player.h and music_player.cpp, which define
and implement the MusicPlayer class responsible for handling backend logic such as managing music files, user authentication,
and serving API endpoints. main.cpp sets up the backend server and defines the main entry point of the application.

resources: This directory holds any additional resources required by the application, such as images or audio files. 
In this case, it includes the Prism logo image.

CMakeLists.txt: The CMake configuration file specifies how the project should be built, including dependencies and compiler options.

Usage
Upload Music: Click on the "Upload File" button to select a music file from your device. Fill in the title and cover image fields, then click "Upload" to add the music to your library.
Login/Signup: Enter your username and password to log in to your account or sign up for a new account if you don't have one.
Play Music: Once logged in, you can click on a music file in the library to start playback.
