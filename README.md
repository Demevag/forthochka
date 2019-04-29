```
 ______         _   _                _     _         
|  ____|       | | | |              | |   | |        
| |__ ___  _ __| |_| |__   ___   ___| |__ | | ____ _ 
|  __/ _ \| '__| __| '_ \ / _ \ / __| '_ \| |/ / _` |
| | | (_) | |  | |_| | | | (_) | (__| | | |   < (_| |
|_|  \___/|_|   \__|_| |_|\___/ \___|_| |_|_|\_\__,_|
                                                     
                                                     
```

```
 +-------------------------------+  
 +-------------------------------+  
 | |            | +------------+ |
 | |            | |            | |
 | |            | |            | |
 | |            | +------------+ |            +-----------------------------------------+
 | |            | |            | |            |The course work at ITMO University.      |
 | |            | |            | |            |What is it? It's a tiny forth interpreter|
 | |            | |            | |            +-----------------------------------------+
 | |            | |            | |
 | |            | |            | |
 +-+------------+-+------------+-+
 |                               |
 +-------------------------------+
 ```

# Description
Forthochka is a tiny Forth interpreter based on course by @sayon and his [forthress](https://github.com/sayon/forthress).
It consists of a kernel written on NASM as native Forth words and other words, written on Forth itself.
# Words
## Stack commands
`drop` -- (a -- )

`swap` -- (a b -- b a)

`dup` -- (a -- a a)

## Arithmetic operators
`+`-- (a b -- \[a+b\])

`*` -- (a b -- \[a\*b\])

`/` -- (a b -- \[a/b\])

`%` -- (a b -- \[a mod b\])

`-` -- (a b -- \[a - b\])

`=` -- (a b -- c) c = 1 if a == b else c = 0

`<` -- (a b -- \[a < b\])

`>` -- (a b -- \[a > b\])

## Logic operators
`not` -- (a -- a') a' = 1 if a == 0 else a' = 1

`land` -- (a b -- \[a && b\])

`lor` -- (a b -- \[ a || b\])

## Bitwise operators
`and` -- (a b -- \[a & b\])

`or` -- (a b -- \[a | b\])

## Return stack commands
`>r` -- push to return stack

`r>` -- pop from return stack

`r@` -- fetch from return stack

## Memory commands
`@` -- fetch by address (addr -- val)

`!` -- store value by address (val addr -- )

`c!` -- store char by addres (char addr -- )

`c@` -- fetch char by address (addr -- char)

`execute` -- execute word with this execution token (token -- )

`forth-dp` -- put the address of the first free segment of user's memory ( -- dp)

## Execution management commands
`docol` -- implementation of any colon word

`branch` -- jump to address

`0branch` -- jump to address if top of the stack  = 0

`exit` -- exit from colon word

## Service commands
`lit` -- push value to stack

`forth-sp` -- push rsp

`forth-stack-base` -- push stack base
