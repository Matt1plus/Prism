-- Create database if not exists
CREATE DATABASE IF NOT EXISTS music_player_db;

-- Use the database
USE music_player_db;

-- Create table for user accounts
CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL
);

-- Create table for music files
CREATE TABLE IF NOT EXISTS music_files (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    image_path VARCHAR(255) NOT NULL,
    file_path VARCHAR(255) NOT NULL,
    uploaded_by INT,
    FOREIGN KEY (uploaded_by) REFERENCES users(id)
);
