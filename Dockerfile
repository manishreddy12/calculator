FROM gcc:latest as builder
WORKDIR /app
COPY src/ .
RUN g++ -std=c++17 main.cpp calculator.cpp -o calculator -lm
FROM python:3.9-slim
WORKDIR /app
RUN pip install Flask
COPY --from=builder /app/calculator .
COPY server.py .
COPY index.html .
EXPOSE 5000
CMD ["python", "server.py"]