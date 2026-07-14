import { apiGetRequest } from "./api";

export interface ListEntryUser {
  user_id: string;
}

export interface ListEntryMusic {
  music_id: string,
}

export interface ListEntryAlbum {
  album_id: string,
}

export interface ListArtistsAlbum{
  artists_id : string,
}

// returns a json list with id, title, artist, duration, album, cover_img
export async function listUserEntries(data: ListEntryUser) {
  return apiGetRequest(`/list-user-entries?user_id=${data.user_id}`);
}

// returns a json list with all the entries of a music id
export async function listMusicEntries(data: ListEntryMusic) {
  return apiGetRequest(`/list-music-entries?music_id=${data.music_id}`);
}

export async function getUsername(data: ListEntryUser){
  return apiGetRequest(`/get-user?user_id=${data.user_id}`);
}

<<<<<<< Updated upstream
export async function getAlbum(data: ListEntryAlbum){
  return apiGetRequest(`/fetch?type=albums&query=${data.album_id}`)
}

export async function getArtists(data: ListArtistsAlbum){
  return apiGetRequest(`/fetch?type=artists&query=${data.artists_id}`)
=======
export async function getMusic(data: ListEntryMusic){
  return apiGetRequest(`/fetch?type=tracks&query=${data.music_id}`)
>>>>>>> Stashed changes
}