# MusicBoxd

Review musics, albuns and artists with your friends!

# Run Server

Install needed package before running the server
```Shell
npm i lucide-react
```

Running the frontend locally with dev mode on root:

```Shell
npm run dev
```
# Back-end Endpoints
Base url:
`https://localhost:8080`

```http
/fetch/tracks/${data.music_id}
/fetch/artists/${data.artists_id}
/fetch/albums/${data.album_id}

/get-user?user_id=${data.user_id}

/list-user-entries?user_id=${data.user_id}
/list-music-entries?music_id=${data.music_id}
```
# Pages URL

Base url:
`https://localhost:3000`

```http
/auth/login
/auth/register
/auth/forgot_password

/main

/main/search
/main/search/[music_Id]

/main/profile
```
