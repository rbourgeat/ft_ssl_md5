# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_sha384.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 13:32:21 by rbourgea          #+#    #+#              #
#    Updated: 2023/12/19 16:18:50 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

CYAN='\033[036m'
RED='\033[0;31m'
GREEN='\033[0;32m'
BOLD='\033[1m'
NC='\033[0m'

succes=0
max=0

compare_output() {
    expected="$1"
    actual="$2"
    ((max++))
    if [ "$expected" == "$actual" ]; then
        echo -e "${GREEN}${BOLD}openssl: [$expected]"
        echo -e "ft_ssl:  [$actual]"
        echo -e "Result:  [OK]${NC}"
        ((succes++))
    else
        echo -e "${RED}${BOLD}openssl: [$expected]"
        echo -e "ft_ssl:  [$actual]"
        echo -e "Result:  [KO]${NC}"
    fi
}

display_separator() {
    echo -e "${CYAN}${BOLD}==================================="
}

rm website
clear

display_separator
echo -e "> Test 1 - simple sha384 =========="
display_separator
result_openssl=$(echo "42 is nice" | openssl sha384)
result_ft_ssl=$(echo "42 is nice" | ./ft_ssl sha384)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 2 - sha384 file ============"
display_separator
echo "https://www.42.fr/" > website
result_openssl=$(openssl sha384 website)
result_ft_ssl=$(./ft_ssl sha384 website)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 3 - sha384 -r file ========="
display_separator
result_openssl=$(openssl sha384 -r file)
result_ft_ssl=$(./ft_ssl sha384 -r file)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 4 - echo | sha384 file ====="
display_separator
result_openssl=$(echo "some of this will not make sense at first" | openssl sha384 file)
result_ft_ssl=$(echo "some of this will not make sense at first" | ./ft_ssl sha384 file)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 5 - sha384 big ============="
display_separator
result_openssl=$(echo "4242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242" | openssl sha384)
result_ft_ssl=$(echo "4242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242" | ./ft_ssl sha384)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 6 - sha384 empty ==========="
display_separator
result_openssl=$(echo "" | openssl sha384)
result_ft_ssl=$(echo "" | ./ft_ssl sha384)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Passed tests: $succes/$max ==============="
display_separator
