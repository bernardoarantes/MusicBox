import { apiGetRequest } from "./api";

export interface ListEntryUser {
  user_id: string;
}

export interface ListEntryMusic {
  music_id: string,
}

// returns a json list with id, title, artist, duration, album, cover_img
export async function listUserEntries(data: ListEntryUser) {
  return apiGetRequest(`/list-user-entries?user_id=${data.user_id}`);
}

// returns a json list with all the entries of a music id
export async function listMusicEntries(data: ListEntryMusic) {
  return apiGetRequest(`/list-music-entries?music_id=${data.music_id}`);
}