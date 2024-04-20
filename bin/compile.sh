#!/bin/bash

# Create build directory if it doesn't exist
if [ ! -d "./build" ]; then
  echo "Creating build directory..."
  mkdir ./build
fi

# Change directory to build directory
echo "Changing directory to build directory..."
cd ./build

# Run cmake
echo "Running cmake..."
cmake ..

# Run make
echo "Running make..."
make

echo "Compilation completed successfully!"