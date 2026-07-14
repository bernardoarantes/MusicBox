#!/bin/zsh
curl -X POST "https://accounts.spotify.com/api/token" \
     -H "Content-Type: application/x-www-form-urlencoded" \
     -d "grant_type=client_credentials&client_id=e1cce31b72b9442d8dc7b1f9f22c1016&client_secret=3eee002adee44c85a847c3e88e115043"
