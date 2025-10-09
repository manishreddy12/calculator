import subprocess
from flask import Flask, request, send_from_directory

app = Flask(__name__)

# Route to serve the HTML file
@app.route('/')
def index():
    return send_from_directory('.', 'index.html')

# Route to handle calculations
@app.route('/calculate', methods=['POST'])
def calculate():
    # Get the expression from the incoming request
    data = request.get_json()
    expression = data['expression']

    # Run the compiled C++ calculator as a command-line program
    # The result from the C++ program's stdout is captured
    process = subprocess.run(
        ['./calculator', expression], 
        capture_output=True, 
        text=True
    )

    # Return the captured output
    if process.returncode == 0:
        return process.stdout
    else:
        return f"Error: {process.stderr}", 500

if __name__ == '__main__':
    # Run the server on port 5000, accessible from anywhere
    app.run(host='0.0.0.0', port=5000)