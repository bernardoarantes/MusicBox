import { apiGetRequest } from "./api";

export interface ListEntryPayload {
  user_id: string;
}

// returns a json list with id, title, artist, duration, album, cover_img
export async function listEntries(data: ListEntryPayload) {
  return apiGetRequest(`/list-entry?user_id=${data.user_id}`);
}