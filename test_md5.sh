# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_md5.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 13:32:21 by rbourgea          #+#    #+#              #
#    Updated: 2023/12/19 15:57:54 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

MAGENTA='\033[035m'
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
    echo -e "${MAGENTA}${BOLD}==================================="
}

rm file
clear

display_separator
echo -e "> Test 1 - simple md5 ============="
display_separator
result_openssl=$(echo "42 is nice" | openssl md5)
result_ft_ssl=$(echo "42 is nice" | ./ft_ssl md5)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 2 - md5 -p ================="
display_separator
result_subject="(\"42 is nice\")= 35f1d6de0302e2086a4e472266efb3a9"
result_ft_ssl=$(echo "42 is nice" | ./ft_ssl md5 -p)
compare_output "$result_subject" "$result_ft_ssl"

display_separator
echo -e "> Test 3 - md5 -q -r =============="
display_separator
result_subject="e20c3b973f63482a778f3fd1869b7f25"
result_ft_ssl=$(echo "Pity the living." | ./ft_ssl md5 -q -r)
compare_output "$result_subject" "$result_ft_ssl"

display_separator
echo -e "> Test 4 - md5 file ==============="
display_separator
echo "And above all," > file
result_openssl=$(openssl md5 file)
result_ft_ssl=$(./ft_ssl md5 file)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 5 - md5 -r file ============"
display_separator
echo "And above all," > file
result_openssl=$(openssl md5 -r file)
result_ft_ssl=$(./ft_ssl md5 -r file)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 6 - md5 -s ================="
display_separator
result_subject="MD5(\"pity those that aren't following baerista on spotify.\")= a3c990a1964705d9bf0e602f44572f5f"
result_ft_ssl=$(./ft_ssl md5 -s "pity those that aren't following baerista on spotify.")
compare_output "$result_subject" "$result_ft_ssl"

display_separator
echo -e "> Test 7 - echo | md5 -p file ====="
display_separator
result_subject="(\"be sure to handle edge cases carefully\")= 3553dc7dc5963b583c056d1b9fa3349c
MD5(file)= 53d53ea94217b259c11a5a2d104ec58a"
result_ft_ssl=$(echo "be sure to handle edge cases carefully" | ./ft_ssl md5 -p file)
compare_output "$result_subject" "$result_ft_ssl"

display_separator
echo -e "> Test 8 - echo | md5 file ========"
display_separator
result_openssl=$(echo "some of this will not make sense at first" | openssl md5 file)
result_ft_ssl=$(echo "some of this will not make sense at first" | ./ft_ssl md5 file)
compare_output "$result_openssl" "$result_ft_ssl"

display_separator
echo -e "> Test 9 - echo | md5 -p -r file =="
display_separator
result_subject="(\"but eventually you will understand\")= dcdd84e0f635694d2a943fa8d3905281
53d53ea94217b259c11a5a2d104ec58a *file"
result_ft_ssl=$(echo "but eventually you will understand" | ./ft_ssl md5 -p -r file)
compare_output "$result_subject" "$result_ft_ssl"

display_separator
echo -e "> Test 10 - echo | md5 -p -s \"foo\" file"
display_separator
result_subject="(\"GL HF let's go\")= d1e3cc342b6da09480b27ec57ff243e2
MD5(\"foo\")= acbd18db4cc2f85cedef654fccc4a4d8
MD5(file)= 53d53ea94217b259c11a5a2d104ec58a"
result_ft_ssl=$(echo "GL HF let's go" | ./ft_ssl md5 -p -s "foo" file)
compare_output "$result_subject" "$result_ft_ssl"

display_separator
echo -e "> Test 11 - echo | md5 -r -p -s \"foo\" file -s \"bar\""
display_separator
result_subject="(\"one more thing\")= a0bd1876c6f011dd50fae52827f445f5
acbd18db4cc2f85cedef654fccc4a4d8 \"foo\"
53d53ea94217b259c11a5a2d104ec58a *file
ft_ssl: md5: -s: No such file or directory
ft_ssl: md5: bar: No such file or directory"
result_ft_ssl=$(echo "one more thing" | ./ft_ssl md5 -r -p -s "foo" file -s "bar")
compare_output "$result_subject" "$result_ft_ssl"

display_separator
echo -e "> Test 12 - echo | md5 -r -q -p -s \"foo\" file"
display_separator
result_subject="just to be extra clear
3ba35f1ea0d170cb3b9a752e3360286c
acbd18db4cc2f85cedef654fccc4a4d8
53d53ea94217b259c11a5a2d104ec58a"
result_ft_ssl=$(echo "just to be extra clear" | ./ft_ssl md5 -r -q -p -s "foo" file)
compare_output "$result_subject" "$result_ft_ssl"

display_separator
echo -e "> Passed tests: $succes/$max ============="
display_separator
