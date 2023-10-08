# test.sh
#!/bin/bash
# ARG="1 2 3 6 9 -9 8 0 10 14 15 12 19 39 26 20";
# ARG="-80 6 -59 92 -56 3 61 -31 -60 -39";
# ARG="77 -38 42 94 97 26 48 16 -57 -96 91 -19 -34 55 -98 -44 -73 -81 73 60 -10 37 -15 -51 -89 -87 57 -30 12 -2 -86 58 -21 40 -83 -64 -52 62 -28 96 14 -36 92 -47 20 -50 47 -29 7 74 -7 -78 30 95 -90 -94 72 56 44 -79 -65 -20 65 68 -13 83 49 89 70 -76 -63 98 -55 2 -69 59 -32 33 27 -71 13 85 -26 5 84 -43 0 -1 -45 17 -27 28 66 -8 39 15 -18 -72 -4 45"
# ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')");

# ./push_swap $ARG | ./checker_Mac $ARG
# valgrind ./push_swap $ARG

# ./push_swap $ARG | wc -l
# ./push_swap "1 2 3 6 9 -9 8 0" 10 100
# leaks --atExit -- ./push_swap "1 2 3 four 6 9 -9 8 0" 10 100 " 11 18 20  to "

# ARG="6 "4" 5"
# echo $ARG
# ./push_swap $ARG

# ARG="6 \"4 6\" 5";
# echo $ARG
# echo $(./push_swap $ARG);
# ./push_swap $ARG;
./push_swap 6 "4 6" 5