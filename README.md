# Algorithmic Challenges (Design & Analysis of Algorithms)

C++ solutions to two dynamic-programming problems, with a written report that covers the pseudocode, the recurrences and the time/space complexity analysis. This was a course project at FAST-NUCES for Design and Analysis of Algorithms.

## 🧩 Problems Solved

| File | Problem (from the code) | Approach | Complexity |
|------|-------------------------|----------|------------|
| `Q1(a).cpp` | Reads an integer `n` (0–200) and counts the valid ways to split it with the recursive function `combi(v, c)` | Top-down DP. The recursion is memoized in an `(n+1) × (n+1)` table that starts filled with `-1`. | Space O(n²). The table has O(n²) states and each one loops up to `v` times. |
| `Q1(b).cpp` | Reads an array of `n` values and a number of `attacks`. It cuts the array into segments to minimize the total cost, where a segment's cost is the sum of pairwise products of its elements. Repeats until it reads `0 0`. | Bottom-up DP: `dp[i][j] = min over k (val(k, i) + dp[k][j-1])`, with the base case `dp[i][0] = val(0, i)` | Time O(n⁴ · attacks), space O(n · attacks) (from the report) |

`report.pdf` gives the pseudocode, the recurrence, the order in which subproblems are solved, and the complexity derivations.

## 🛠 Tech Stack
- C++ (standard library only: `<iostream>`, `<climits>`)
- A DP table on the heap (manual `new`)

## 📁 Project Structure
```
Algorithmic-Challenges-Project/
├── Q1(a).cpp    # Memoized recursive counting (combi)
├── Q1(b).cpp    # Segmenting the array with minimum pairwise-product cost
└── report.pdf   # Project report: pseudocode and complexity analysis
```

## ▶️ How to Run
```bash
g++ "Q1(a).cpp" -o q1a
./q1a            # input: n (0-200)

g++ "Q1(b).cpp" -o q1b
./q1b            # input: n attacks, then n values; enter "0 0" to stop
```

## 👤 Author
Raja Saif Ali — [GitHub](https://github.com/raja-saif) · [LinkedIn](https://www.linkedin.com/in/raja-saif-01702329a/)
