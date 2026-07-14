# MusicBox API Documentation

This document describes the HTTP API endpoints provided by the MusicBox backend.

## General Information
- **Base URL**: `http://localhost:8080` (or `http://0.0.0.0:8080`)
- **Content-Type**: Requests with bodies should generally be sent with `Content-Type: application/json` or as raw JSON text. Response bodies are returned with `Content-Type: text/plain` containing either plain text error messages or JSON serialized data.
- **CORS Support**: The backend allows all origins (`*`) and supports `POST, GET, OPTIONS, PUT, DELETE` methods.

---

## Common Response Headers
- `Access-Control-Allow-Origin: *`
- `Access-Control-Allow-Methods: POST, GET, OPTIONS, PUT, DELETE`
- `Access-Control-Allow-Headers: Content-Type, Authorization`

---

## Endpoint Reference

### 1. Create User
Creates a new user account in the system.

- **URL**: `/create-user`
- **Method**: `POST`
- **Request Body (JSON)**:
  | Field | Type | Required | Description |
  | :--- | :--- | :--- | :--- |
  | `name` | String | Yes | Username for the account. |
  | `email` | String | Yes | Unique email address. |
  | `password` | String | Yes | Password for the account. |

- **Validation Rules**:
  - `name`: Must not be empty. Must match pattern `^[A-Z0-9._%+-]+` (case-insensitive). Throws `ValidationException` otherwise.
  - `email`: Must not be empty. Must not contain spaces. Must match standard email pattern `^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,6}$` (case-insensitive). Throws `ValidationException` otherwise.
  - Email uniqueness: Cannot create a user if the email is already registered. Throws `ValidationException` otherwise.

- **Response**:
  - **Success (200 OK)**:
    - Body: `""` (Empty JSON string)
  - **Failure (400 Bad Request)**:
    - Body: Plain text validation or format error message (e.g. `email cannot contain blanks`, `invalid email ...`, `user with email ... already exists`, etc.)

---

### 2. Login
Authenticates a user and retrieves their User ID.

- **URL**: `/login`
- **Method**: `POST`
- **Request Body (JSON)**:
  | Field | Type | Required | Description |
  | :--- | :--- | :--- | :--- |
  | `email` | String | Yes | User's email address. |
  | `password` | String | Yes | User's password. |

- **Response**:
  - **Success (200 OK)**:
    - Body: `{"user_id": <id>}`
      - Example: `{"user_id":0}`
  - **Failure (400 Bad Request)**:
    - Body: `wrong credentials` (if the password is incorrect or format is invalid)
  - **Failure (500 Internal Server Error / Uncaught Exception)**:
    - Body: `no user with email <email>` (occurs when email is not found in the database; due to an uncaught `EntityNotFoundException` propagating from the backend)

---

### 3. Create Review Entry
Creates a new review/activity entry for a music track, album, or artist.

- **URL**: `/create-entry`
- **Method**: `POST`
- **Request Body (JSON)**:
  | Field | Type | Required | Description |
  | :--- | :--- | :--- | :--- |
  | `user_id` | String | Yes | ID of the user creating the entry. |
  | `type` | String | Yes | Type of entry (e.g., `"music"`, `"album"`, `"artist"`). |
  | `target_id` | String | Yes | Spotify ID or target ID of the item being reviewed. |
  | `comment` | String | Yes | User's comments or review. |
  | `rating` | Unsigned Int | Yes | Rating value (e.g., `0` to `5` or higher). |

- **Response**:
  - **Success (200 OK)**:
    - Body: `""` (Empty JSON string)
  - **Failure (400 Bad Request)**:
    - Body: Plain text format error message (e.g. `user_id not found`, `type not found`, etc.)

---

### 4. List User Entries
Retrieves all review entries created by a specific user.

- **URL**: `/list-entry`
- **Method**: `GET`
- **Query Parameters**:
  | Parameter | Type | Required | Description |
  | :--- | :--- | :--- | :--- |
  | `user_id` | String | Yes | ID of the owner user whose entries should be listed. |

- **Response**:
  - **Success (200 OK)**:
    - Body: JSON array of entry objects.
    - Example:
      ```json
      [
        {
          "id": "0",
          "owner_id": "0",
          "type": "music",
          "target_id": "AAHUIAI",
          "comment": "Horrível",
          "rating": "0"
        }
      ]
      ```
      *(Note: rating is serialized as a string value in the response).*
  - **Failure (400 Bad Request)**:
    - Body: `missing q param` (returned when the `user_id` query parameter is missing)

---

### 5. Search Spotify API
Searches tracks, albums, or artists on Spotify.

- **URL**: `/search`
- **Method**: `GET`
- **Query Parameters**:
  | Parameter | Type | Required | Description |
  | :--- | :--- | :--- | :--- |
  | `q` | String | Yes | The search keyword or phrase. |
  | `page` | Integer | Yes | The page index (offset is calculated as `10 * page`). |
  | `type` | String | Yes | The item type to search for (`track`, `album`, or `artist`). |

- **Response**:
  - **Success (200 OK)**:
    - Body: JSON object containing an `items` array with matching details.
    - Example (Track):
      ```json
      {
        "items": [
          {
            "id": "track_id",
            "title": "Track Name",
            "album": "album_id",
            "cover": "https://spotify.com/image.jpg",
            "duration": 240000,
            "artists": ["artist_id_1", "artist_id_2"]
          }
        ]
      }
      ```
    - Example (Album):
      ```json
      {
        "items": [
          {
            "id": "album_id",
            "title": "Album Name",
            "type": "album",
            "release_date": "2026-01-01",
            "cover": "https://spotify.com/image.jpg",
            "artists": ["artist_id_1"]
          }
        ]
      }
      ```
    - Example (Artist):
      ```json
      {
        "items": [
          {
            "id": "artist_id",
            "name": "Artist Name"
          }
        ]
      }
      ```
  - **Failure (400 Bad Request)**:
    - Body: `missing 'q' param`, `missing 'page' param`, or `type not found`

---

## Known Backend Bugs & Implementation Notes

During the API review, a few significant bugs and implementation quirks were identified:

1. **Broken `/search` Endpoint**:
   - In [QueryHandler.cpp](file:///tmp/MusicBox/backend/src/service/handler/QueryHandler.cpp#L25-L43), the query parameters `q` and `page` are parsed, but the `type` parameter is never extracted in `getData()`.
   - In `QueryHandler::handle()`, the code attempts to extract `type` from the parsed JSON, which throws a `FormatException("type not found")`. This causes the `/search` endpoint to always return `400 Bad Request` with `type not found`.
   - Additionally, `page` is read as a string from `req.get_param_value("page")` but cast directly to `unsigned` in `extract()`, which will throw a JSON type error at runtime.

2. **Uncaught EntityNotFoundException in `/login`**:
   - In [Workspace.cpp](file:///tmp/MusicBox/backend/src/service/Workspace.cpp#L85-L91), if the email is not found, it throws `EntityNotFoundException`.
   - Since [DefaultHandler.cpp](file:///tmp/MusicBox/backend/src/service/handler/DefaultHandler.cpp#L35-L48) only catches `FormatException` and `ValidationException`, this exception propagates to the server framework, resulting in an unhandled 500 error instead of a clean 400 validation error.

3. **Swapped ID Generation in RegistryService**:
   - In [RegistryService.cpp](file:///tmp/MusicBox/backend/src/service/RegistryService.cpp#L19-L25), `generateUserId()` returns `to_string(entry_count)` while `generateEntryId()` returns `to_string(user_count)`. The counters are swapped, leading to mismatched ID assignment formats.
