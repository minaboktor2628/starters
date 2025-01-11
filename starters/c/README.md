# C/C++ Starter code

By Mina Boktor

## Table Of Contents

- [Features](#features)
- [Compiling](#compiling)
- [Usage](#usage)

## Features

- Uses makefile to compile all C/C++ code for you

## Compiling

There is an included makefile with this project.

Run:

```sh
make
```

to compile the program.

To clean artifacts and executable, run:

```sh
make clean
```

To clean just the artifacts, but keep executable, run:

```sh
make clean-obj
```

You can also specify the name of the executable target when running `make` by running:

```sh
make TARGET=my_executable
```

You can can also dynamically make a debugging version of your executable when running `make` by running:

```sh
make DEBUG
```

or

```sh
make DEBUG=1
```

for short.

## Usage

```sh
./executable <arg>
```

where

- `<arg>` is a command line argument

### Example

```bash
./executable cool_file.txt
```
