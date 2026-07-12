import { apiPostRequest } from "./api";

export interface ListEntryPayload {
  user_id: string;
}

// returns a json list with id, title, artist, duration, album, cover_img
export async function listEntries(data: ListEntryPayload) {
  return apiPostRequest("/list-entry", "GET", data);
}