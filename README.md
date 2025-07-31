# Overview
It took me 10 days to finish this exhausting project. I tried to tackle the question using radix sort but unfortunately it was not the best answer.

# Timeline

_0616-0619 Researching different algorisms and settled down with radix sort_

_0620  Started parsing and validating part_

_0621-0622 Finished rules part_

_0623-0624 Finished radix sort part(50 numbers: 4700, 100 numbers: 24000)_

_0625-0626 Continued to optimize: improve index mapping(50 numbers: 1100, 100 numbers: 6800), add small_number sort(no improvement)_

_0627 Optimized stack b operation(50 numbers: 1026, 100 numbers: 6758) and evaluated by peers, passed with 84_

# My understanding of radix sort

### Disadvantages
1. It was very hard to optimize: I tried optimizing part of the operations, but it turned out be in vain.

2. It was very hard to combine with other algorism: I tried to combine chunk sort and radix sort to make it more effective. But it could not sort into correct order at the end so that i had to quit.

### Advantages
1. Very much stable: no matter what numbers were given, the number of steps are always same

2. Good chance to learn bit manipulation: << >> & ^ |
