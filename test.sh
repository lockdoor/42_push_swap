# test.sh
#!/bin/bash
ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')");

echo "Test Error"
./push_swap " 5 one 2 "
./push_swap " 5 2 2 "
./push_swap " 2147483648 0 -2147483648"
./push_swap " 2147483647 0 -2147483649"
./push_swap ""
./push_swap "      "
./push_swap 2 4 3a
./push_swap 4+2 5 1
./push_swap 2 4 ++3
./push_swap one two three
echo "Test is sort or no arg"
./push_swap " 1  2     3 "
./push_swap
echo "Test normal"
./push_swap 6 " 2147483647 0 -2147483648" 5
echo "Test normal 2\"   \"4 3 in this case argv is 24, 3"
./push_swap 2"   "4 3

echo "Check test"
echo "Test Error"
./checker " 5 one 2 "
./checker " 5 2 2 "
./checker " 2147483648 0 -2147483648"
./checker " 2147483647 0 -2147483649"
./checker ""
./checker "      "
./checker 2 4 3a
./checker 4+2 5 1
./checker 2 4 ++3
./checker one two three

echo "Test push_swap with checker"
./push_swap $ARG | ./checker $ARG