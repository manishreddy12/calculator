# Stage 1: Build the C++ application
FROM gcc:latest AS builder

# Set the working directory inside the container
WORKDIR /app

# Copy the source code
COPY src/calculator.cpp .

# Compile the application. -o calculator names the executable file.
# The 'build' step in the pipeline is effectively handled here.
RUN g++ calculator.cpp -o calculator -lm

# Stage 2: Create a minimal runtime image
# We use a base image with the necessary C++ libraries
FROM debian:stable-slim

# Copy only the compiled executable from the builder stage
COPY --from=builder /app/calculator /usr/local/bin/calculator

# Command to run the application when the container starts
CMD ["calculator"]