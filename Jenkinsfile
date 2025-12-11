pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                // Jenkins автоматично витягне код з репозиторію, який ми вкажемо в налаштуваннях Job
                checkout scm
            }
        }

        stage('Build') {
            steps {
                echo 'Building the project...'
                // Команда для збірки рішення (.sln). 
                // Використовуємо bat для Windows команд.
                // /t:Rebuild - повна перезбірка
                // /p:Configuration=Debug - конфігурація
                // /p:Platform=x64 - платформа (важливо для Google Test)
                bat "\"${tool 'MSBuild'}\" test_repos.sln /t:Rebuild /p:Configuration=Debug /p:Platform=x64"
            }
        }

        stage('Test') {
            steps {
                echo 'Running Google Tests...'
                // Запуск .exe файлу з тестами
                // --gtest_output="xml:test_report.xml" створює звіт для xUnit
                script {
                    bat 'x64\\Debug\\test_repos.exe --gtest_output="xml:test_report.xml"'
                }
            }
        }
    }

    post {
        always {
            echo 'Publishing Test Results...'
            // Публікація звіту через плагін xUnit
            // Переконайтеся, що плагін xUnit встановлено в Jenkins!
            junit 'test_report.xml'
        }
    }
}
