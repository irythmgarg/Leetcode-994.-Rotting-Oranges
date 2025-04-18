# Leetcode-994.-Rotting-Oranges
# 🍊 Rotting Oranges - BFS Grid Simulation

This project solves the **Rotting Oranges** problem using **Breadth-First Search (BFS)**. The grid simulates the spread of rot from initially rotten oranges to fresh ones over time.

---

## 🧩 Problem Statement

You are given a `m x n` grid where:
- `0` represents an empty cell,
- `1` represents a fresh orange,
- `2` represents a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten one becomes rotten.  
Return the **minimum number of minutes** that must elapse until **no cell has a fresh orange**. If it's impossible, return `-1`.

---

## 🧠 Approach

- Use **Multi-source BFS** by pushing all rotten oranges into a queue.
- Spread the rot to neighboring fresh oranges, tracking time taken.
- After the spread, verify if any fresh oranges remain.

---

## 🔁 Algorithm Steps

1. Add all rotten oranges (value `2`) to the BFS queue with time `0`.
2. Use BFS to process each orange and rot adjacent fresh ones.
3. Track the time taken for each new rot.
4. After BFS, check if any fresh orange is left.
5. Return the total time or `-1` if not all could be rotted.

---

## 🧪 Example

### Input
```cpp
grid = {
  {2,1,1},
  {1,1,0},
  {0,1,1}
};

Output : 4
All oranges can be rotted in 4 minutes.

