# Cinema Reservation System

A command-line cinema scheduling and seat reservation system developed individually in C++ as a university Advanced Programming project.

## Overview

This project provides a simple cinema management system for scheduling movie shows, reserving seats, displaying available seats, and generating reservation reports.

The system prevents conflicting movie schedules and duplicate seat reservations.

## Features

- Adding a movie show to a cinema hall
- Managing different hall capacities
- Preventing multiple shows from being scheduled in the same hall at the same time
- Reserving seats for customers
- Preventing duplicate seat reservations
- Checking whether a show exists before accepting a reservation
- Listing scheduled movies in chronological order
- Displaying the number of available seats for each show
- Reporting reserved seats in ascending seat-number order
- Input validation and exact output formatting

## Cinema Halls

The system contains three cinema halls:

| Hall Number | Seat Capacity |
|-------------|---------------|
| 1           | 10 seats      |
| 2           | 20 seats      |
| 3           | 30 seats      |

## Commands

### Add a movie show

```text
add_show <movie_name> <time> <hall_number>
```

Example:

```text
add_show SpongeBob 10 3
```

### Reserve a seat

```text
reserve <hall_number> <time> <seat_number> <customer_name>
```

Example:

```text
reserve 3 10 21 Parisa
```

### List scheduled movies

```text
list_movies <hall_number>
```

Example:

```text
list_movies 3
```

### Report reserved seats

```text
report_seats <hall_number> <time>
```

Example:

```text
report_seats 2 24
```

## Error Handling

The program handles situations such as:

- Scheduling two movies in the same hall at the same time
- Reserving a seat for a show that does not exist
- Reserving a seat that has already been reserved
- Requesting reports when no movie or reservation exists

## Programming Concepts

- C++ programming
- Containers
- Structures
- Functions
- Modular programming
- Sorting
- State management
- Command-line input processing
- Input validation
- Clean code and separation of responsibilities

## Technologies

- C++
- Visual Studio Code
- Command-line interface

## Author

**Tara Jahanshahi**

Computer Engineering Student  
University of Tehran
