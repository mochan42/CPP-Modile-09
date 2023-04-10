echo "=== COMPILING ==================================="
make -s re
echo -e
echo "=== TESTS ======================================="
echo "1st test : ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\""
echo "Expected result is : 42. "
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo -e
echo "2nd test : ./RPN \"7 7 * 7 -\""
echo "Expected result is : 42. "
./RPN "7 7 * 7 -"
echo -e
echo "3rd test : ./RPN \"1 2 * 2 / 2 * 2 4 - +\""
echo "Expected result is : 0. "
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo -e
echo "4th test : ./RPN \"(1 + 1)\""
echo "Expected result is : Error (parenthesis are forbidden characters). "
./RPN "(1 + 1)"
echo -e