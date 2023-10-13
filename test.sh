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
echo "Test Error"

#must handle this error
# ./checker_Mac "+"
# echo $?
# ./checker "+"
# echo $?
echo "##########################"
./checker_Mac "-"
echo $?
./checker "-"
echo $?
echo "##########################"

./checker_Mac " 5 one 2 "
echo $?
./checker " 5 one 2 "
echo $?

./checker_Mac " 2147483648 0 -2147483648"
echo $?
./checker " 2147483648 0 -2147483648"
echo $?

./checker_Mac " 2147483647 0 -2147483649"
echo $?
./checker " 2147483647 0 -2147483649"
echo $?

./checker_Mac ""
echo $?
./checker ""
echo $?

./checker_Mac "      "
echo $?
./checker "      "
echo $?

./checker_Mac 2 4 3a
echo $?
./checker 2 4 3a
echo $?

./checker_Mac 4+2 5 1
echo $?
./checker 4+2 5 1
echo $?

./checker_Mac 2 4 ++3
echo $?
./checker 2 4 ++3
echo $?

./checker_Mac one two three
echo $?
./checker one two three
echo $?
###############################
echo "Test is duplicate"

./checker_Mac " 5 2 2 "
echo $?
./checker " 5 2 2 "
echo $?

###############################
echo "Test is sort or no arg"

./checker_Mac " 1  2     3 " < /dev/null
echo $?
./checker " 1  2     3 " < /dev/null
echo $?

./checker_Mac
echo $?
./checker
echo $?

INPUT="sa\nrra\n"
echo -en $INPUT > mytest
./checker " 1 0" -01 < mytest
rm -f mytest

INPUT="sa\nrra\n"
echo -en $INPUT > mytest
./checker_Mac " 1 0" -01 < mytest
rm -f mytest

# ./push_swap
# echo "Test normal"
# ./push_swap 6 " 2147483647 0 -2147483648" 5
# echo "Test normal 2\"   \"4 3 in this case argv is 24, 3"
# ./push_swap 2"   "4 3