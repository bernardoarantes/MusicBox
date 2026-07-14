# MusicBoxd 🎵

A social network for reviewing music, albums, and artists with your friends! Built with a Next.js 14 frontend and a robust, cached C++17 backend integrated with the Spotify API.

---

## 🚀 Running the Project

### Option A: Running with Docker Compose (Recommended)

Make sure you have Docker and Docker Compose installed.

1. **Obtain a Spotify Web API Token**:
   Run the helper script to generate a temporary Spotify token:
   ```shell
   bash get_api_key.sh
   ```
   *(Note: This returns a JSON response containing an `"access_token"`)*

2. **Start the services**:
   Export the key to your environment and start the containers. Docker Compose will automatically build the backend C++ application and set up the Next.js frontend:
   ```shell
   export SPOTIFY_API_KEY="your_copied_access_token"
   docker compose up --build
   ```

* Frontend will be accessible at: `http://localhost:3000`
* Backend will be accessible at: `http://localhost:8080`
* Your reviews will persist locally under the `./backend/data` directory mapped as a volume.

---

### Option B: Running Locally

#### 1. Backend (C++17)
**Prerequisites**: A C++17 compiler (`g++` 9+), OpenSSL library development headers (`libssl-dev` and `libcrypto-dev`).

```shell
cd backend
# Compile the C++ backend
g++ -std=c++17 src/main.cpp -I./src/ -I./dependencies/ -lssl -lcrypto -lpthread -o musicbox

# Export the Spotify API key
export SPOTIFY_API_KEY="your_spotify_token"

# Run the server
./musicbox
```

#### 2. Frontend (Next.js)
**Prerequisites**: Node.js (version 18 or higher) and npm.

```shell
cd music_box
# Install npm dependencies
npm install

# Start the dev server
npm run dev
```

---

## 📡 Back-end Endpoints

Base URL: `http://localhost:8080`

### 🔑 Authentication & Users
* `POST /create-user` - Registers a new user. Expects: `{"name": "...", "email": "...", "password": "..."}`
* `POST /login` - User login. Expects: `{"email": "...", "password": "..."}`
* `GET /get-user?user_id=${id}` - Retrieves a user's display name.

### 📝 Entries & Reviews
* `POST /create-entry` - Adds a review entry. Expects: `{"user_id": "...", "target_id": "...", "comment": "...", "rating": 10, "type": "music"}`
* `GET /list-user-entries?user_id=${id}` - Lists all reviews created by a user.
* `GET /list-music-entries?music_id=${id}` - Lists all reviews created for a specific track/album.
* `GET /check-for-entry?user_id=${user_id}&music_id=${music_id}` - Checks if a user has reviewed a track.

### 🎵 Spotify Catalog Integration (Query & Details)
* `GET /search?type=${type}&query=${query}&page=${page}` - Searches Spotify. `type` can be `track`, `album`, or `artist`.
* `GET /fetch?type=${type}&query=${id}` - Fetches detailed info for a Spotify item. `type` must be `tracks`, `albums`, or `artists`.
* `GET /list-random-musics` - Returns random tracks from Spotify.
