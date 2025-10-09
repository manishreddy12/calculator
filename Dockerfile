# =========================
# Stage 1: Build the C++ application
# =========================
FROM gcc:latest AS builder

# Set working directory
WORKDIR /app

# Copy all source files (header + cpp files)
COPY src/ ./src/

# Compile the application (main + calculator)
RUN g++ -std=c++17 src/main.cpp src/calculator.cpp -o calculator -lm

# =========================
# Stage 2: Runtime image
# =========================
FROM debian:stable-slim

# Install required shared libraries for C++ apps
RUN apt-get update && apt-get install -y libstdc++6 && rm -rf /var/lib/apt/lists/*

# Copy only the built executable
COPY --from=builder /app/calculator /usr/local/bin/calculator

# Default command
CMD ["calculator"]
