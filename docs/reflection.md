# Pointer Project Reflection

## 1) Differences Between Pointer Types

### Pointer to stack memory (Part A)
In Part A, `Task t1(...)` and `Task t2(...)` are created on the stack.  
Pointers like `Task* p1 = &t1;` simply store the address of those stack objects.
The key point is: **the program does not “own” stack memory through the pointer**.
When `main()` ends (or the scope ends), the objects are destroyed automatically.
No `delete` is allowed or needed because the memory was never allocated with `new`.

### Pointer to heap memory (Part B)
In Part B, `Task* tasks = new Task[capacity];` allocates an array on the heap.
This memory exists until we manually free it using `delete[] tasks;`.
Here, **we own the heap memory**, meaning we are responsible for releasing it.
If we forget `delete[]`, we create a **memory leak**.

### Smart pointer (unique_ptr) (Part C)
In Part C, `TaskManager` owns its array using:
`tasks = std::make_unique<Task[]>(initialCapacity);`
This is RAII: the memory is automatically freed when `TaskManager` is destroyed.
Ownership is explicit: only `TaskManager` owns the array, and cleanup happens automatically.
No manual `delete` is written, and the design prevents common memory errors.

## 2) Where and why delete was used
`delete[] tasks;` is used in Part B at the end of `runPartB()` because the array was allocated using `new Task[capacity]`.
Heap allocations must be paired correctly:
- `new[]` must be paired with `delete[]` (not plain `delete`).

## 3) Ownership in each design
- Part A: `main()` owns the stack objects. Pointers are just “references” to them.
- Part B: `main()` owns the heap array and must free it manually.
- Part C: `TaskManager` owns the heap array through `unique_ptr`, which enforces single ownership.

## 4) Safest method and why
`std::unique_ptr` is the safest method because it prevents memory leaks and double-free errors by tying the lifetime of the heap memory to the lifetime of the owning object.
It also makes ownership clear in the code and eliminates the need for manual cleanup.
