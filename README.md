# CPP-Module-09

This module is about leraning how to use C++ containers.<br>

# ex 00
This aim of this exercise it to create a program that :<br>
- takes as an input a file `input.txt` in which each line contains a date and and a number of bitcoins:<br>
![Capture d’écran 2023-04-29 à 14 11 27](https://user-images.githubusercontent.com/107719618/235301919-4fa78c37-8604-4d58-be60-f9bc5697b372.png)<br>
- ouputs to the terminal the value of these bitcoins by multipliying the BTC exchange rate at that date with the quantity of Bitcoins :<br>
![Capture d’écran 2023-04-29 à 14 13 34](https://user-images.githubusercontent.com/107719618/235301965-44f9676a-8593-491f-881e-c6091d889ddd.png)
<br>
I extract the exchange rates from a csv file `data.csv` :

![Capture d’écran 2023-04-29 à 14 10 54](https://user-images.githubusercontent.com/107719618/235302081-3918560a-57fc-4bac-9942-713d0cd10c6c.png)
<br>The exchange rates are then stored into a `std::map` container.<br>
The reason is that the exchange rate can be access from the date which is the key of the map container.


# ex 01
The aim of this exercise is to calculate the result of a mathematical expression that uses Polish Notation.<br>
Polish notation : https://en.wikipedia.org/wiki/Polish_notation<br>
Basically, it means that the operator follows the operands where as we usually find the operator betweens the operands.<br>

"Usual" notation (operator between operands) : `4 x 3`<br>
Polish notation (operator follows operands) : `4 3 x`<br>

The container chosen here is `std::stack` : <br>
- we use one stack to store the operands,
- and another stack to store the operators.

# ex 02
The aim of this exercise is to code a merge-insert sorting algorithm and apply it to 2 different containers (`std::vector` and `std::queue`).


