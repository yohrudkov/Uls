<h1 align="center"> Uls </h1> <br>

<p align="center"> System utility implementation. </p>

<p align="center">
    <a href="https://github.com/yohrudkov">
        <img alt="yohrudkov GitHub main page"
        title="Main page"
        src="https://github.githubassets.com/images/modules/logos_page/GitHub-Logo.png"
        width="140">
    </a>
</p>

## Table of Contents

- [Introduction](#Introduction)
- [Build Process](#Build-Process)
    - [Description](#Description)
    - [Compilation](#Compilation)
    - [Initiation](#Initiation)
- [Authors](#Authors)
- [License](#License)
- [Acknowledgments](#Acknowledgments)

## Introduction

System utility *`ls`* implementation. \
The program that outputs the contents of a file system directory and file information to standard output. \
All information regarding file access rights is stored as attributes of the file, ie is integral with it, and can be viewed by calling *`uls`* with the extended output key *`-l`*.

## Build Process

### Description

The program implement:
* the usage: *`usage: uls [-l] [file ...]`*;
* basic functionality of this command - list of directory contents without flags;
* processing of *`file`* operands for files and directories;
* the *`-l`*  flag, which is one of the most useful flags.

Implemented flags:
* *`-l`* - display a detailed list, which will display the owner, group, creation date, size and other parameters;
* *`-a`* - show all files, including hidden ones, these are those preceded by a period;
* *`-R`* - recursively display the contents of directories.

Program's output example:
<p align="center">
    <img alt="Uls"
    title="Uls"
    src="https://github.com/yohrudkov/Uls/blob/main/resources/output.jpg?raw=true"
    width="300">
</p>

### Compilation

Compile C-files with clang compiler and use these flags:\
*`clang -std=c11 -Wall -Wextra -Werror -Wpedantic`*.

### Initiation

To begin to use Uls project, run the following *`./uls [flags] [file ...]`* exe file.

## Authors

- Yaroslav Ohrudkov - *Program development* - [yohrudkov](https://github.com/yohrudkov)

## License

Collision is an open-sourced software licensed under the [MIT license](https://en.wikipedia.org/wiki/MIT_License). \
[Copyright (c) 2020 yohrudkov](https://github.com/yohrudkov/Uls/blob/main/LICENSE).

## Acknowledgments

Thanks [Ucode IT academy](https://ucode.world/ru/) for the training program provided.