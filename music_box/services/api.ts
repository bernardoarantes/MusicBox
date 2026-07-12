const URL = "http://localhost:8080";

async function apiRequest(endpoint: string, method: string, body?: unknown) {
  const response = await fetch(`${URL}${endpoint}`, {
    method,
    headers: { "Content-Type": "application/json" },
    body: body ? JSON.stringify(body) : undefined,
  });
  if (!response.ok) {
    throw new Error(`Response status: ${response.status}`);
  }
  return response.json();
}

export async function apiPostRequest(endpoint: string, method: string, body?: unknown) {
  return apiRequest(endpoint, method, body);
}

export async function apiGetRequest(endpoint: string, method: string = "GET") {
  return apiRequest(endpoint, method);
}