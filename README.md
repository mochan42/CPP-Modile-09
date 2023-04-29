# CPP-Module-09

This module is about leraning how to use C++ containers.<br>

# ex 00
This aim of this exercise it to create a program that :<br>
- takes as an input a file `input.txt` in which each line contains a date and and a number of bitcoins,<br>
- ouputs the value of these bitcoins by multipliying the BTC exchange rate at that date with the quantity of Bitcoins.

In this exercise, I extract the exchange rates from a csv file `data.csv` :<br>
![Capture d’écran 2023-04-29 à 14 10 54](https://user-images.githubusercontent.com/107719618/235301870-40366a9d-c4ad-4e88-a6aa-7fccb4a6e4a8.png)
<br>
The exchange rates are then stored into a `std::map` container.
The reason is that the exchange rate can be access from the date which is the key of the map container.


# ex 01
The aim of this exercise is to calculate the result of a mathematical expression that uses Polish Notation.<br>
Polish notation : https://en.wikipedia.org/wiki/Polish_notation<br>
Basically, it means that the operator follows the operands where as we usually find the operator betweens the operands.<br>

"Usual" notation (operator between operands) : `4 x 3`<br>
Polish notation (operator follows operands) : `4 3 x`<br>

The container chosen here is `std::stack` : we use one stack to store the operands and one stock to store the operators.

# ex 02
The aim of this exercise is to code a merge-insert sorting algorithm and apply it to 2 different containers (`std::vector` and `std::queue`)

