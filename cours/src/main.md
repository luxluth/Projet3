# Notices

## free()

```c
ptr = malloc(...)
free(ptr)
ptr = NULL
```
Ensure that a free `ptr` have the `NULL` value. On call, the app crash
