// Fetch music library data from backend and display it in the frontend
fetch('http://localhost:9080/music-library')
    .then(response => response.json())
    .then(data => {
        const musicLibraryElement = document.getElementById('music-library');
        for (const key in data) {
            if (data.hasOwnProperty(key)) {
                const musicItem = document.createElement('div');
                musicItem.textContent = `${key}: ${data[key]}`;
                musicLibraryElement.appendChild(musicItem);
            }
        }
    })
    .catch(error => console.error('Error fetching music library:', error));

// Handle file upload
const fileInput = document.getElementById('file-input');
const titleInput = document.getElementById('title-input');
const imageInput = document.getElementById('image-input');
const uploadButton = document.getElementById('upload-button');

uploadButton.addEventListener('click', () => {
    const file = fileInput.files[0];
    const title = titleInput.value;
    const imagePath = imageInput.value;
    if (file && title && imagePath) {
        const formData = new FormData();
        formData.append('file', file);
        formData.append('title', title);
        formData.append('imagePath', imagePath);

        fetch('http://localhost:9080/upload', {
            method: 'POST',
            body: formData
        })
        .then(response => {
            if (response.ok) {
                console.log('File uploaded successfully');
            } else {
                console.error('Error uploading file:', response.statusText);
            }
        })
        .catch(error => console.error('Error uploading file:', error));
    } else {
        console.error('Please fill in all fields');
    }
});

// Handle user login
const usernameInput = document.getElementById('username-input');
const passwordInput = document.getElementById('password-input');
const loginButton = document.getElementById('login-button');

loginButton.addEventListener('click', () => {
    const username = usernameInput.value;
    const password = passwordInput.value;
    if (username && password) {
        // Implement user login request
    } else {
        console.error('Please enter username and password');
    }
});

// Handle user signup
const signupButton = document.getElementById('signup-button');

signupButton.addEventListener('click', () => {
    const username = usernameInput.value;
    const password = passwordInput.value;
    if (username && password) {
        // Implement user signup request
    } else {
        console.error('Please enter username and password');
    }
});
