# 🚀 Drogon Hello Server

A simple web server built using the [Drogon](https://github.com/drogonframework/drogon) framework. This server provides two endpoints:

- `/`: Returns a basic "Hello from Drogon!" message.
- `/api/cityinfo/{city}`: Provides information about a city (e.g., New York, London, Tokyo).

## 📦 Features

- Built with Drogon, a high-performance C++17/20 web framework and ORM.
- Unit tests written with Google Test.
- Dockerized for easy deployment.
- Kubernetes deployment configuration for scalability.
- Git hooks and CI/CD integration via GitHub Actions.

---

## 🛠️ Prerequisites

Before running the project, ensure you have the following installed:

- **CMake** (`3.5+`)
- **C++17 compiler**
- **Git**
- **Docker** (optional but recommended)
- **Kubernetes cluster** (for deployment)

---

## 🧪 Building and Running the Project

### 1. Clone the Repository

```bash
git clone <repository-url>
cd task6
```

### 2. Set Up Dependencies via vcpkg

If not already set up:

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install drogon
```

Set the environment variable:

```bash
export VCPKG_ROOT=/path/to/vcpkg
```

### 3. Build the Project

```bash
mkdir build && cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake ..
make
```

### 4. Run the Server

```bash
./hello-server
```

The server will start and listen on port `8848`.

---

## 🧪 Running Tests

To run unit tests:

```bash
make main_test
./main_test
```

Ensure all tests pass before deploying or pushing changes to the repository.

---

## 🐳 Docker Setup

### Build the Docker Image

```bash
docker build -t drogon-hello-server .
```

### Run the Docker Container

```bash
docker run -p 8848:8848 drogon-hello-server
```

---

## 🚀 Kubernetes Deployment

This project includes a `deployment.yaml` file that defines a Kubernetes Deployment, Service, and HorizontalPodAutoscaler. To deploy it in a Kubernetes cluster:

1. Apply the configuration:

```bash
kubectl apply -f deployment.yaml
```

2. Verify the deployment:

```bash
kubectl get deployments,pods,services
```

3. Access the service via LoadBalancer or expose it as needed.

---

## 📂 Project Structure

```
task6/
├── .clang-tidy             # Clang-Tidy configuration for code quality checks
├── .dockerignore           # Files to ignore when building Docker image
├── .git/                   # Git repository files (commits, branches, etc.)
│   ├── COMMIT_EDITMSG      # Last commit message
│   ├── FETCH_HEAD          # Latest fetched commits
│   ├── HEAD                # Current branch pointer
│   ├── config              # Git configuration
│   └── logs/               # Commit history logs
├── .github/                # GitHub Actions CI/CD workflows
│   └── workflows/
│       └── github-actions.yml  # GitHub Actions workflow file
├── .gitignore              # Files to ignore in version control
├── CMakeLists.txt          # CMake build configuration
├── Dockerfile              # Docker image setup
├── README.md               # This file
├── config.json             # Server configuration (port, threads, etc.)
├── deployment.yaml         # Kubernetes deployment configuration
├── main.cpp                # Entry point of the application
├── src/                    # Source code directory
│   ├── CityInfoController.cpp/h
│   └── HelloController.cpp/h
├── test/                   # Unit tests
│   ├── test_cityinfo/
│   │   └── getcity_test.cpp
│   └── test_hello/
│       └── hello_test.cpp
├── uploads/                # Upload directories (not used in this example)
└── vcpkg.json              # vcpkg dependency configuration
```

---

## ✅ Example Endpoints

| Endpoint                   | Method | Description                           |
| -------------------------- | ------ | ------------------------------------- |
| `GET /`                    | GET    | Returns "Hello from Drogon!"          |
| `GET /api/cityinfo/{city}` | GET    | Returns info about the specified city |

---

## 🔁 CI/CD with GitHub Actions

The project includes a GitHub Actions workflow defined in `.github/workflows/github-actions.yml`. This workflow performs the following tasks:

1. **Build and Test**: Compiles the project and runs unit tests on every push to the repository.
2. **Deploy to GitHub Container Registry (GHCR)**: If the build is successful, the Docker image is pushed to GHCR.

### Workflow Details

- **Trigger**: The workflow is triggered by any `push` event to the repository.
- **Jobs**:
  - **Explore-GitHub-Actions**: Prints information about the current Git event, runner OS, and repository.
  - **Build-and-Test**: Builds the project and runs unit tests.
  - **Deploy-To-Github-Registry**: Builds the Docker image and pushes it to GHCR.

### Workflow Configuration

Here's a simplified view of the workflow file:

```yaml
name: CI/CD for cpp-endpoint
on: [push]

jobs:
  Explore-GitHub-Actions:
    runs-on: ubuntu-latest
    steps:
      - run: echo "🎉 The job was automatically triggered by a ${{ github.event_name }} event."
      - run: echo "🐧 This job is now running on a ${{ runner.os }} server hosted by GitHub!"
      - run: echo "🔎 The name of your branch is ${{ github.ref }} and your repository is ${{ github.repository }}."

  Build-and-Test:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - name: Build and run tests
        run: |
          mkdir build && cd build
          cmake ..
          make
          ./main_test

  Deploy-To-Github-Registry:
    runs-on: ubuntu-latest
    needs: Build-and-Test
    steps:
      - uses: actions/checkout@v4
      - name: Build and push the image
        run: |
          docker login --username <your login> --password ${{ secrets.GH }} ghcr.io
          docker build . --tag ghcr.io/z0tedd/cpp-endpoint-example:latest
          docker push ghcr.io/z0tedd/cpp-endpoint-example:latest
```

---

## 📝 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE.md) file for details.

---

## 📩 Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a feature branch.
3. Make your changes and write tests if applicable.
4. Submit a pull request.

---

## 📞 Contact

For questions or suggestions, feel free to reach out via email or open an issue in the GitHub repository.

## FIX LINT

```sh
mkdir build && cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake ..
ln -s ../build/compile_commands.json ..
```
