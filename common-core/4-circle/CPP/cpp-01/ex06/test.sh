#!/bin/bash

echo "=== Test 1: WARNING level ==="
./harlFilter "WARNING"

echo -e "\n=== Test 2: DEBUG level ==="
./harlFilter "DEBUG"

echo -e "\n=== Test 3: ERROR level ==="
./harlFilter "ERROR"

echo -e "\n=== Test 4: INFO level ==="
./harlFilter "INFO"

echo -e "\n=== Test 5: Invalid level ==="
./harlFilter "I am not sure how tired I am today..."

echo -e "\n=== Test 6: No parameter ==="
./harlFilter
