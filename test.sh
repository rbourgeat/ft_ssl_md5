#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BOLD='\033[1m'
NC='\033[0m'

compare_output() {
    expected="$1"
    echo -e "openssl: [$expected]"
    actual="$2"
    echo -e "ft_ssl:  [$actual]"
    if [ "$expected" == "$actual" ]; then
        echo -e "${GREEN}${BOLD}Result:  [OK]${NC}"
    else
        echo -e "${RED}${BOLD}Result:  [KO]${NC}"
    fi
    echo "========================================="
}

# Test 1
result_openssl=$(echo "42 is nice" | openssl md5)
result_ft_ssl=$(echo "42 is nice" | ./ft_ssl md5)
compare_output "$result_openssl" "$result_ft_ssl"

# Test 2
echo "And above all," > file
result_openssl=$(openssl md5 file)
result_ft_ssl=$(./ft_ssl md5 file)
compare_output "$result_openssl" "$result_ft_ssl"
