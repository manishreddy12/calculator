# Stage 1: Build the C++ executable
FROM gcc:latest as builder
WORKDIR /app
COPY src/ ./src/
RUN g++ -std=c++17 src/main.cpp src/calculator.cpp -o calculator -lm

# Stage 2: Create the final Python runtime image
FROM python:3.9-slim
WORKDIR /app

# Install Flask
RUN pip install Flask

# Copy the compiled C++ program from the 'builder' stage
COPY --from=builder /app/calculator .

# Copy the web server and HTML file
COPY server.py .
COPY index.html .

# Expose the port the server will run on
EXPOSE 5000

# Command to run the Python web server
CMD ["python", "server.py"]
