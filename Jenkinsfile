pipeline {
    agent any

    environment {
        GITHUB_USER = 'manishreddy12'
        DOCKERHUB_USER = 'manishr09'
        DOCKER_IMAGE = "${DOCKERHUB_USER}/calculator:${env.BUILD_NUMBER}"

        // C++ sources
        APP_SRC = 'src/calculator.cpp'
        MAIN_SRC = 'src/main.cpp'
        TEST_SRC = 'tests/test_calculator.cpp'

        TEST_EXEC = 'calculator_tests'
    }

    stages {
        stage('Checkout Code') {
            steps {
                git branch: 'main', url: "https://github.com/${GITHUB_USER}/calculator.git"
            }
        }

        stage('Build & Test') {
            steps {
                sh """
                echo "🔧 Compiling GoogleTest executable..."
                g++ -std=c++17 ${APP_SRC} ${TEST_SRC} -o ${TEST_EXEC} -lgtest -lgtest_main -lpthread -lm

                echo "🧪 Running unit tests..."
                ./${TEST_EXEC}
                """
            }
        }

        stage('Build Docker Image') {
            steps {
                script {
                    echo "🐳 Building Docker image: ${DOCKER_IMAGE}"
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

    post {
        always {
            emailext(
                to: 'ambatireddy13@gmail.com',
                subject: "Build ${env.JOB_NAME} #${env.BUILD_NUMBER} - ${currentBuild.currentResult}",
                body: """<p>Build URL: <a href="${env.BUILD_URL}">${env.BUILD_URL}</a></p>
                        <p>Build result: ${currentBuild.currentResult}</p>""",
                recipientProviders: [[$class: 'DevelopersRecipientProvider']]
            )
        }
    }


}
