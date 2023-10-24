# test.sh
#!/bin/bash
# ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')");

# echo "Test is sort or no arg"
# ./push_swap " 1  2     3 "
# ./push_swap
# echo "Test normal"
# ./push_swap 6 " 2147483647 0 -2147483648" 5
# echo "Test normal 2\"   \"4 3 in this case argv is 24, 3"
# ./push_swap 2"   "4 3

# echo "Test push_swap with checker"
# ./push_swap $ARG | ./checker $ARG

##################################

NC="\033[0m"
BOLD="\033[1m"
ULINE="\033[4m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"

function TEST_ERR {
    printf "\n${RED} $1\n${NC}"
}

function TEST_OK {
    printf "\n${GREEN} $1\n${NC}"
}

echo "######################################"
echo "Test Error"
echo "######################################"
#must handle this error

TEST_ERR "./checker_Mac "+""
./checker_Mac "+"
echo $?
./checker "+"
echo $?

TEST_ERR "./checker_Mac "-""
./checker_Mac "-"
echo $?
./checker "-"
echo $?


TEST_ERR "./checker_Mac \"\""
./checker_Mac ""
echo $?
./checker ""
echo $?

TEST_ERR "./checker_Mac \"      \""
./checker_Mac "      "
echo $?
./checker "      "
echo $?

TEST_ERR "./checker_Mac 2 \"\" 4 3"
./checker_Mac 2 "" 4 3
echo $?
./checker 2 "      " 4 3
echo $?

TEST_ERR "./checker_Mac 2 \"      \" 4 3"
./checker_Mac 2 "      " 4 3
echo $?
./checker 2 "      " 4 3
echo $?

TEST_ERR "./checker_Mac 2 4 3a"
./checker_Mac 2 4 3a
echo $?
./checker 2 4 3a
echo $?

TEST_ERR "./checker_Mac 4+2 5 1"
./checker_Mac 4+2 5 1
echo $?
./checker 4+2 5 1
echo $?

TEST_ERR "./checker_Mac 4,2 5 1"
./checker_Mac 4,2 5 1
echo $?
./checker 4,2 5 1
echo $?

TEST_ERR "./checker_Mac 2 4 ++3"
./checker_Mac 2 4 ++3
echo $?
./checker 2 4 ++3
echo $?

TEST_ERR "./checker_Mac 2 4 +-3"
./checker_Mac 2 4 +-3
echo $?
./checker 2 4 +-0
echo $?

TEST_ERR "./checker_Mac 2147483648 12 1 5"
./checker_Mac 2147483648 12 1 5
echo $?
./checker 2147483648 12 1 5
echo $?

TEST_ERR "./checker_Mac -2147483649 12 1 5"
./checker_Mac -2147483649 12 1 5
echo $?
./checker -2147483649 12 1 5
echo $?

TEST_ERR "./checker_Mac 42 000042 5 1"
./checker_Mac 42 000042 5 1 
echo $?
./checker 42 000042 5 1
echo $?

TEST_ERR "./checker_Mac -5 2 -00005 7 "
./checker_Mac -5 2 -00005 7 
echo $?
./checker -5 2 -00005 7
echo $?

TEST_ERR "./checker_Mac \" 5 one 2 \""
./checker_Mac " 5 one 2 "
echo $?
./checker " 5 one 2 "
echo $?

TEST_ERR "./checker_Mac \" 2147483648 0 -2147483648\""
./checker_Mac " 2147483648 0 -2147483648"
echo $?
./checker " 2147483648 0 -2147483648"
echo $?

TEST_ERR "./checker_Mac \" 2147483647 0 -2147483649\""
./checker_Mac " 2147483647 0 -2147483649"
echo $?
./checker " 2147483647 0 -2147483649"
echo $?


echo
echo "######################################"
echo "Test OK"
echo "######################################"

TEST_OK "./checker_Mac 4 +2 5 1"
./push_swap 4 +2 5 1 | ./checker_Mac 4 +2 5 1
./push_swap 4 +2 5 1 | ./checker 4 +2 5 1

TEST_OK "./checker_Mac \"4\" +2 5 \"1\""
./push_swap "4" +2 5 "1" | ./checker_Mac "4" +2 5 "1"
./push_swap "4" +2 5 "1" | ./checker "4" +2 5 "1"

TEST_OK "./checker_Mac \"  4  \" \" +2 \" \"5    1\""
./push_swap "  4  " " +2 " "5    1" | ./checker_Mac "  4  " " +2 " "5    1"
./push_swap "  4  " " +2 " "5    1" | ./checker "  4  " " +2 " "5    1"

TEST_OK "./checker_Mac \"1 7\" 9 \"  25   10 \""
./push_swap "1 7" 9 "  25   10 " | ./checker_Mac "1 7" 9 "  25   10 "
./push_swap "1 7" 9 "  25   10 " | ./checker "1 7" 9 "  25   10 "

TEST_OK "./checker_Mac 00000 +0002 -2222 \"+0000009     -000009\""
./push_swap 00000 +0002 -2222 "+0000009     -000009" | ./checker_Mac 00000 +0002 -2222 "+0000009     -000009"
./push_swap 00000 +0002 -2222 "+0000009     -000009" | ./checker 00000 +0002 -2222 "+0000009     -000009"

TEST_OK "./checker_Mac 2147483647 \"-2147483648 00000000000000000000000001 +002 -002\""
./push_swap 2147483647 "-2147483648 00000000000000000000000001 +002 -002" | ./checker_Mac 2147483647 "-2147483648 00000000000000000000000001 +002 -002"
./push_swap 2147483647 "-2147483648 00000000000000000000000001 +002 -002" | ./checker 2147483647 "-2147483648 00000000000000000000000001 +002 -002"

# ./checker_Mac 2 4 3a
# echo $?
# ./checker 2 4 3a
# echo $?

# ./checker_Mac 4+2 5 1
# echo $?
# ./checker 4+2 5 1
# echo $?

# ./checker_Mac 2 4 ++3
# echo $?
# ./checker 2 4 ++3
# echo $?

# ./checker_Mac one two three
# echo $?
# ./checker one two three
# echo $?

# ./checker_Mac 5 9 "  8 7  " "" 6
# echo $?
# ./checker 5 9 "" 6
# echo $?

###############################
# echo "Test is duplicate"

# ./checker_Mac " 5 2 2 "
# echo $?
# ./checker " 5 2 2 "
# echo $?

###############################
# echo "Test is sort or no arg"

# ./checker_Mac " 1  2     3 " < /dev/null
# echo $?
# ./checker " 1  2     3 " < /dev/null
# echo $?

# ./checker_Mac
# echo $?
# ./checker
# echo $?

# INPUT="sa\nrra\n"
# echo -en $INPUT > mytest
# ./checker " 1 0" -01 < mytest
# rm -f mytest

# INPUT="sa\nrra\n"
# echo -en $INPUT > mytest
# ./checker_Mac " 1 0" -01 < mytest
# rm -f mytest

# ./push_swap
# echo "Test normal"
# ./push_swap 6 " 2147483647 0 -2147483648" 5
# echo "Test normal 2\"   \"4 3 in this case argv is 24, 3"
# ./push_swap 2"   "4 3