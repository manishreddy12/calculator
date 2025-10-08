pipeline {
    agent any
    
    environment {
        GITHUB_USER = 'manishreddy12'
        DOCKERHUB_USER = 'manishr09'
        DOCKER_IMAGE = "${DOCKERHUB_USER}/scientific-calculator:${env.BUILD_NUMBER}"
        
        // Define the name of the test executable
        TEST_EXEC = 'calculator_tests'
        
        // C++ source files
        APP_SRC = 'src/calculator.cpp'
        TEST_SRC = 'tests/test_calculator.cpp'
    }

    stages {
        stage('Checkout Code') {
            steps {
                git branch: 'main', url: "https://github.com/${GITHUB_USER}/scientific-calculator-devops.git" 
            }
        }
        
        stage('Build and Test') {
            steps {
                // 1. Compile the main application and link the test suite 
                //    (Assuming gtest is installed on the Jenkins agent)
                sh """
                echo "Compiling C++ application and tests..."
                g++ -std=c++11 ${APP_SRC} ${TEST_SRC} -o ${TEST_EXEC} -lgtest -lgtest_main -lpthread -lm
                """
                
                // 2. Run the compiled test executable
                sh "./${TEST_EXEC}"
            }
        }
        
        stage('Build Docker Image') {
            steps {
                script {
                    // This command uses the Dockerfile (which compiles the main app again)
                    sh "docker build -t ${DOCKER_IMAGE} ."
                }
            }
        }
        
        stage('Push to Docker Hub') {
            steps {
                script {
                    withCredentials([usernamePassword(credentialsId: 'docker-hub-creds', 
                                                     usernameVariable: 'DOCKER_USER', 
                                                     passwordVariable: 'DOCKER_PASS')]) {
                        sh "echo ${DOCKER_PASS} | docker login -u ${DOCKER_USER} --password-stdin"
                        sh "docker push ${DOCKER_IMAGE}"
                    }
                }
            }
        }
        
        stage('Deploy with Ansible') {
            steps {
                sh "ansible-playbook -i ansible/hosts.ini ansible/deploy_calculator.yml -e DOCKER_IMAGE=${DOCKER_IMAGE}"
            }
        }
    }
}