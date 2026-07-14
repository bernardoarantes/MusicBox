import { apiGetRequest } from "./api";

export interface ListEntryPayload {
  id: string; // user_id or music_id
}

// returns a json list with id, title, artist, duration, album, cover_img
export async function listUserEntries(data: ListEntryPayload) {
  return apiGetRequest(`/list-user-entries?user_id=${data.id}`);
}

// returns a json list with all the entries of a music id
export async function listMusicEntries(data: ListEntryPayload) {
  return apiGetRequest(`/list-music-entries?music_id=${data.id}`);
}