# Introduction to Python Concepts

Before diving into the exercises, it's essential to understand some fundamental Python concepts that will be helpful in solving the problems. This section provides a brief overview of key topics you'll encounter while working on the exercises.

## 1. Data Types

### Lists

- **Definition**: A list is an ordered collection of items (which can be of different types) that can be modified. Lists are defined using square brackets.
- **Example**:
  ```python
  my_list = [1, 2, 3, "hello", 5.5]
  ```
- **Key Operations**:
  - Accessing elements: `my_list[0]` retrieves the first element.
  - Adding items: `my_list.append(6)` adds `6` to the end of the list.
  - Slicing: `my_list[1:3]` returns elements from index `1` to `2`.

### Sets

- **Definition**: A set is an unordered collection of unique items. Sets are defined using curly braces.
- **Example**:
  ```python
  my_set = {1, 2, 3, 4}
  ```
- **Key Operations**:
  - Adding items: `my_set.add(5)` adds `5` to the set.
  - Checking membership: `3 in my_set` returns `True` if `3` is in the set.
  - Intersection: `set_a & set_b` returns common elements between two sets.

### Tuples

- **Definition**: A tuple is an ordered, immutable collection of items. Tuples are defined using parentheses.
- **Example**:
  ```python
  my_tuple = (1, 2, 3)
  ```
- **Key Operations**:
  - Accessing elements: `my_tuple[1]` retrieves the second element.
  - Slicing: `my_tuple[0:2]` returns elements from index `0` to `1`.

### Dictionaries

- **Definition**: A dictionary is an unordered collection of key-value pairs. Dictionaries are defined using curly braces with a colon separating keys and values.
- **Example**:
  ```python
  my_dict = {"name": "Alice", "age": 25}
  ```
- **Key Operations**:
  - Accessing values: `my_dict["name"]` retrieves the value associated with the key `"name"`.
  - Adding items: `my_dict["height"] = 170` adds a new key-value pair.

## 2. Control Flows

### If Statements

- Used to execute a block of code conditionally.
- **Example**:
  ```python
  if n > 0:
      print("Positive")
  elif n == 0:
      print("Zero")
  else:
      print("Negative")
  ```

### Loops

- **For Loop**: Iterates over a sequence (like a list or string).

  ```python
  for i in range(5):
      print(i)  # Prints numbers from 0 to 4
  ```

- **While Loop**: Continues to execute as long as a condition is `True`.
  ```python
  count = 0
  while count < 5:
      print(count)
      count += 1  # Increments count by 1
  ```

## 3. Functions

- **Definition**: A function is a block of reusable code that performs a specific task. Functions are defined using the `def` keyword.
- **Example**:
  ```python
  def greet(name):
      return f"Hello, {name}!"
  ```
- **Calling a function**: `greet("Alice")` returns `"Hello, Alice!"`.

## Summary

Familiarizing yourself with these concepts will help you successfully complete the exercises. As you work through each task, remember to leverage these Python features to build efficient and effective solutions.

Good luck, and happy coding!
