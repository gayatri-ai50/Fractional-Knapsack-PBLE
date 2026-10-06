# Fractional Knapsack – AOA PBLE

## Project Description
Smart Delivery Planning – Fractional Knapsack is a menu-driven C program that implements the Fractional Knapsack Greedy Algorithm. The program calculates the Value/Weight ratio of each package, sorts the packages in decreasing order of ratio, and selects complete packages or suitable fractions to maximize the total value within the given vehicle capacity.

## Objectives
- Understand and implement the Greedy Method.
- Calculate the Value/Weight ratio of packages.
- Sort packages based on their ratio.
- Select complete packages or fractions when required.
- Calculate the maximum achievable value.

## Features
- Enter package details
- Display package details
- Calculate Value/Weight ratio
- Sort packages by ratio
- Find maximum value
- Display selected packages and fractions

## Algorithm
1. Calculate the Value/Weight ratio for each package.
2. Sort packages in decreasing order of ratio.
3. Select the package completely if it fits.
4. If the complete package does not fit, select the required fraction.
5. Continue until the vehicle capacity is full.
6. Display the maximum value and total weight used.

## Sample Input

| Package | Value | Weight |
|--------:|------:|-------:|
| 1 | 100 | 20 |
| 2 | 60 | 10 |
| 3 | 120 | 30 |
| 4 | 80 | 40 |

**Capacity:** 50

## Sample Output

```text
Maximum Value = 240.00
Total Weight Used = 50.00
```
## Complexity Analysis
- Time Complexity: O(n²)
- Space Complexity: O(n)
The time complexity is O(n²) because Bubble Sort is used to arrange the packages in decreasing order of Value/Weight ratio.
## Technologies Used
- C
- Greedy Algorithm
- Bubble Sort
