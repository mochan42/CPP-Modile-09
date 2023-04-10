echo "=== COMPILING ==================================="
#make -s re
echo -e
echo "=== TESTS ======================================="
echo "1st test : ./PmergeMe 3 5 9 7 4"
./PmergeMe 3 5 9 7 4
echo -e
echo "2nd test : ./PmergeMe \"-1\" \"2\" "
./PmergeMe -1 2

echo -e
echo "3rd test : ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`"
#./PmergeMe `jot -r 3000 1 2147483647 | tr '\n' ' '` > output

echo -e
echo "=== TESTS COMPLETED ============================="
echo -e