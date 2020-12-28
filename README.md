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
All information regarding file access rights is stored as attributes of the file, ie is integral with it, and can be viewed by calling *`uls`* with the extended output key *`-l`*. \

## Build Process

### Description

Input file description:
* the remaining lines describe the distance between the two islands, one per line. Each line consists of two islands, the length of the bridge between them and a newline ina format: \
*`[Name(from)]-[Name(to)]=[Value]`*:
    * the names of the islands contain only alphabetic characters and cannot be empty or identical;
    * the length of the bridge contains only numbers, cannot be empty and has a positive value;
    * the sum of the lengths of all bridges in the file does not exceed *`INT_MAX`*.

The output consists of information blocks about a specific shortest path. Each block contains:
* *`<<====================>>`* the boundary;
* Path: *`<island1> -> <island2>`* that shows the initial point and the final destination;
* Route: *`<island1> -> <all_islands_between> -> <island2>`* that shows the full route between the two islands;
* Distance: *`<length1> + <length2> = <sum>`* that shows the distance between every island in the route, as well as their sum that indicates the distance to the final destination.

Error handling. The program prints errors to the standard error stream *`stderr`* in the following order of priority:
* *`usage: ./pathfinder [filename]`* if there is an invalid number of command-line arguments;
* *`error: invalid filename`* if the file does not exist;
* *`error: file empty`* is empty if the file is empty;
* *`error: line [line_number] isn't valid`* is not valid if one of the remaining lines does not match the format above;
* *`error: line [line_number] already exist with the different value`* if there is more than one bridge between the islands.

Map example:
<p align="center">
    <img alt="Example"
    title="Example"
    src="https://github.com/yohrudkov/Pathfinder/blob/main/resources/map.jpg?raw=true"
    width="300">
</p>

Program's output example:
<p align="center">
    <img alt="Pathfinder"
    title="Pathfinder"
    src="https://github.com/yohrudkov/Pathfinder/blob/main/resources/output.jpg?raw=true"
    width="300">
</p>

### Compilation

Compile C-files with clang compiler and use these flags:\
*`clang -std=c11 -Wall -Wextra -Werror -Wpedantic`*.

### Initiation

To begin to use Pathfinder project, run the following *`./pathfinder [filename]`* exe file.

## Authors

- Yaroslav Ohrudkov - *Application development* - [yohrudkov](https://github.com/yohrudkov)

## License

Collision is an open-sourced software licensed under the [MIT license](https://en.wikipedia.org/wiki/MIT_License). \
[Copyright (c) 2020 yohrudkov](https://github.com/yohrudkov/Pathfinder/blob/main/LICENSE).

## Acknowledgments

Thanks [Ucode IT academy](https://ucode.world/ru/) for the training program provided.