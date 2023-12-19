# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_sha2.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 13:32:21 by rbourgea          #+#    #+#              #
#    Updated: 2023/12/19 16:07:13 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

BLUE='\033[034m'
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
    echo -e "${BLUE}${BOLD}==================================="
}

rm website
clear

display_separator
echo -e "> Test 1 - simple sha256 =========="
display_separator
result_openssl=$(echo "42 is nice" | openssl sha256)
result_ft_ssl=$(echo "42 is nice" | ./ft_ssl sha256)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 2 - sha256 file ============"
display_separator
echo "https://www.42.fr/" > website
result_openssl=$(openssl sha256 website)
result_ft_ssl=$(./ft_ssl sha256 website)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 3 - sha256 -q file ========="
display_separator
result_subject="1ceb55d2845d9dd98557b50488db12bbf51aaca5aa9c1199eb795607a2457daf"
result_ft_ssl=$(./ft_ssl sha256 -q website)
compare_output "$result_subject" "$result_ft_ssl"

display_separator
echo -e "> Test 4 - sha256 -s =============="
display_separator
result_subject="SHA256(\"42 is nice\")= b7e44c7a40c5f80139f0a50f3650fb2bd8d00b0d24667c4c2ca32c88e13b758f"
result_ft_ssl=$(./ft_ssl sha256 -s "42 is nice")
compare_output "$result_subject" "$result_ft_ssl"

display_separator
echo -e "> Test 5 - sha256 -r file ========="
display_separator
result_openssl=$(openssl sha256 -r file)
result_ft_ssl=$(./ft_ssl sha256 -r file)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 6 - echo | sha256 file ====="
display_separator
result_openssl=$(echo "some of this will not make sense at first" | openssl sha256 file)
result_ft_ssl=$(echo "some of this will not make sense at first" | ./ft_ssl sha256 file)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 7 - sha256 big ============="
display_separator
result_openssl=$(echo "4242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242" | openssl sha256)
result_ft_ssl=$(echo "4242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242424242" | ./ft_ssl sha256)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 8 - sha256 empty ==========="
display_separator
result_openssl=$(echo "" | openssl sha256)
result_ft_ssl=$(echo "" | ./ft_ssl sha256)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Passed tests: $succes/$max ==============="
display_separator
