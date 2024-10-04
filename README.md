# Starter code

By Mina Boktor

Started code script from the command line!

## Table Of Contents

- [Features](#features)
- [Setup](#setup)
- [Usage](#usage)

## Features

- Generate boiler plate code for multiple project types
  - Java
  - T3 Stack (Next.js)
  - C/C++

## Setup

First, download this project. I recommend you made a `bin` directory in your home directory for all your global scripts.

If you don't already have a `bin` directory, run the following command:

```sh
cd 
mkdir -p bin
cd bin
```

Then, you can clone this project into here.

```sh
git clone https://github.com/minaboktor2628/starters.git
chmod +x generate
```

You must add this script to your `PATH` variable in order to use it anywhere.

For bash, run:

```sh
echo "export PATH="$PATH:$HOME/bin/starters"" >> ~/.bashrc
source ~/.bashrc
```

For zsh, run:

```sh
echo "export PATH="$PATH:$HOME/bin/starters"" >> ~/.zshrc
source ~/.zshrc
```

### NOTES:

- For `T3` projects, ensure you have `pnpm` installed

You can install pnpm with the following command:

```sh
curl -fsSL https://get.pnpm.io/install.sh | sh -
```

- For `Java` projects, ensure you have `gradle` intalled

You will need to download the JDK and SKDMAN! to manage gradle version.

To download the JDK, run the following command:

```sh
sudo apt update
sudo apt install openjdk-21-jdk
```

To download SDKMAN!, run the following command:

```sh
curl -s "https://get.sdkman.io" | bash
```

You can then use it to install gradle by running:

```sh
sdk install gradle 8.2.1
sdk use gradle 8.2.1
```

- For C/C++
  - Ensure you have `gcc` and/or `g++` installed. You can change this to the compiler of your choice after installing in the `Makefile`
  - Ensure you Have `make` installed

## Usage

### Java

This will generate a `gradle` project, and walk through the setup.

```sh
generate java [project name]
```

Where:

- `project name` option name for project. If not specified, you will be prompted for it.

You can then run:

- `gradle build` to build the project
- `gradle run` to execute project
- `gradle clean` to clean project

### C/C++

This will generate a `C` or `C++` project that is managed by a `Makefile`.

```sh
generate <c|cpp|c++> [project name]
```

Where:

- `project name` option name for project. If not specified, you will be prompted for it.
- `<c|cpp|c++>` is the type of project you are making.

You can then run:

- `make` to build the project
- `./<project name>` to execute project
- `make clean` to clean project
- `make clean-obj` to clean object files, but not the executable
- `make DEBUG` to compile your program in debug more. This adds the `-g` flag to your compilation step

You can find more information in the the generated file's README.md

### T3

This will generate a `T3` project w/ shad-cn components.

```sh
generate t3 [project name]
```

Where:

- `project name` option name for project. If not specified, you will be prompted for it.

You can then run:

- `pnpm run build` to build the project
- `pnpm run dev` to run the project in dev mode

You can find more information in the the generated file's README.md
