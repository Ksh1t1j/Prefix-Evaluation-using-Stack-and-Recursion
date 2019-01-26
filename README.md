# Prefix-Evaluation-using-Stack-and-Recursion

Given an expression in Pre-fix notation, containing space separated digits and operators, use the Stack implementation with recursive algorithm which uses a Stack of NumOp records.

Input Format

The only line of input contains a string  of space separated characters. Each character can be one of the digits {0,1,....,9} or one of the four operator {+,-,*,/} . Look at the sample input for more details.

Constraints
1<=s<=500

Output Format

Output the final answer of the expression. Note that you have to take care of floating points. Answers correct within 2 places after decimal will be considered correct (An example, expression / 5 2, any answer will be marked correct).

Sample Input 0

+ 3 2
Sample Output 0

5
Sample Input 1

* / 5 6 4
Sample Output 1

3.333
Sample Input 2

+ + / * 5 - 3 2 4 * 5 5 6
Sample Output 2

32.25
