# Compilation and Execution

To compile and run the `main.cpp` file and execute a specific exercise (EXO = X), use the following command:

```sh
g++ main.cpp -o main -DEXO=X && ./main
```

Where `X` is the exercise number you want to run.

If `EXO` is not defined, the program will default to executing exercise **1**.

### Notes:
- This command is for **Linux** systems, **Windows** might require different approach.
- The default exercise is **1** if `EXO` is not specified.
