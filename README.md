# Custom Malloc Implementation

This is a small personal project. As implied by the title, the purpose is to make a custom memory allocator in C. My goal is to learn about concepts including but not limited to low-level programming, memory management, and WSL. I will update this page as I write more code!

## Scope

The custom malloc must:
- Keep a list of memory locations inside the heap with free memory
- Keep a list of all allocations made
- Return a new free memory area of a given size on demand, or request the OS to grow the heap
- Free a chosen block of memory
- Be thread-safe

