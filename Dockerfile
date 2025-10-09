# Stage 1: Build the C++ executable
FROM gcc:latest as builder
WORKDIR /app
# Copy the entire C++ source directory
COPY src/ .
# Compile the C++ files from the copied src directory
RUN g++ -std=c++17 main.cpp calculator.cpp -o calculator -lm

# Stage 2: Create the final Python runtime image
FROM python:3.9-slim
WORKDIR /app

# Install Flask
RUN pip install Flask

# Copy the compiled C++ program from the 'builder' stage
COPY --from=builder /app/calculator .

# Copy the web server and HTML file from the project root
COPY server.py .
COPY index.html .

# Expose the port the server will run on
EXPOSE 5000

# Command to run the Python web server
CMD ["python", "server.py"]