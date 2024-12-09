# File Monitoring and Ranking Application

This application monitors the 'fileset' directory for file changes, processes the files, and maintains a ranking based on the occurrences of a specific word in the files. The application uses multiple threads to handle different tasks such as dispatching file events, processing files, and updating the ranking.

## Features

- Monitors a directory for file creation, deletion, modification, and movement.
- Processes files to count occurrences of a specific word.
- Maintains a ranking of files based on the word count.
- Gracefully handles termination with `Ctrl+C`.

## Requirements

- Linux operating system
- Cmake build system (version 3.10 or higher)
- Makefile build automation tool
- GCC compiler
- `pthread` library

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/Giovanni-LOS/paralegrep 
    cd paralegrep
    cd build 
    ```

2. Compile the application:
    ```bash
    cmake ..
    make
    ```

## Usage

1. Run the application with the word to search for:
    ```bash
    ./paralegrep <word_to_find>
    ```

2. The application will start monitoring the `../fileset` directory for file changes and update the ranking based on the occurrences of the specified word.

3. Press `Ctrl+C` to gracefully terminate the application.

## Code Structure

- `src/main.c`: Initializes the application, sets up signal handling, and starts the threads.
- `src/thread_dispatcher.c`: Monitors the directory for file changes and dispatches events to the worker threads.
- `src/thread_worker.c`: Processes the files to count occurrences of the specified word and updates the ranking buffer.
- `src/thread_ranking.c`: Maintains and displays the ranking of files based on the word count.
- `include/utils.h` and `src/utils.c`: Contains utility functions and shared data structures.

