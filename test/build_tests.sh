#!/bin/bash

set -e
g++ -std=c++17 -Iinclude -o test_runner unit_test.cpp test_framework.cpp test_string.cpp test_pair.cpp test_priority_queue.cpp test_vector.cpp test_unordered_map.cpp
