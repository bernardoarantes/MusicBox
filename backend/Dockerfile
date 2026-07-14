# Stage 1: Build stage
FROM ubuntu:22.04 AS builder

# Prevent interactive prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

# Install compiler, SSL development headers, and CA certificates
RUN apt-get update && apt-get install -y \
    build-essential \
    libssl-dev \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy dependencies and sources
COPY dependencies ./dependencies
COPY src ./src

# Compile the backend using user's compiler flags
RUN g++ src/main.cpp -I./src/ -I./dependencies/ -O3 -g -lssl -lcrypto -lpthread -o musicbox

# Stage 2: Runtime stage
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install runtime SSL shared libraries and CA certificates (needed for Spotify HTTPS API requests)
RUN apt-get update && apt-get install -y \
    libssl3 \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy the compiled binary from builder
COPY --from=builder /app/musicbox .

# Copy initial data directory containing .jsonl storage files
COPY data ./data

# Expose backend port
EXPOSE 8080

# Execute server
CMD ["./musicbox"]
