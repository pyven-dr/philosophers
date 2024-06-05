# Philosophers

## I never thought philosophy would be so deadly

### In this project, you will learn the basics of threading a process.You will see how to create threads and you will discover mutexes.

![image](https://github.com/pyven-dr/philosophers/assets/150053673/122352a5-927d-417b-860d-1d06a0b2e078)

## Explanation
In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.
It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present form.

A number of philosophers dine together at the same table. Each philosopher has his own plate at the table. There is a fork between each plate. The dish served is a kind of spaghetti which has to be eaten with two forks. Each philosopher can only alternately think, eat and sleep. Moreover, a philosopher can only eat his spaghetti when he has both a left and right fork. Thus two forks will only be available when his two nearest neighbors are sleeping, not eating. After an individual philosopher finishes eating, he will put down both forks.

## How to use

Clone the project
```bash
git clone https://github.com/pyven-dr/philosophers.git
```

Compile
```bash
cd philosophers/philo && make
```

### Arguments

`./philo_one number_philosopher time_to_die time_to_eat time_to_sleep [number_of_time_each_philosophers_must_eat]` arguments in square brackets are not required

example : `./philo 4 410 200 200` /
`./philo 4 410 200 200 5`
