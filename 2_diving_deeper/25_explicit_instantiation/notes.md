**Explicit template instantiation - notes**

```
$ nm a.out | grep max
0000000000001130 W _Z3maxIdET_S0_S0_
```

 Only one instance of max was instantiated (*double*):
```
$ c++filt _Z3maxIdET_S0_S0_
double max<double>(double, double)
```

All calls for Stack<int> were generated:

```
$ nm a.out | grep Stack
0000000000001526 W _ZN5StackIdE3topEv
0000000000001426 W _ZN5StackIiE3popEv
0000000000001320 W _ZN5StackIiE3topEv
00000000000011f6 W _ZN5StackIiE4pushERKi
0000000000001170 W _ZN5StackIiEC1Em
0000000000001170 W _ZN5StackIiEC2Em
00000000000011cc W _ZN5StackIiED1Ev
00000000000011cc W _ZN5StackIiED2Ev
```

for example:
```
$ c++filt _ZN5StackIiEC1Em
Stack<int>::Stack(unsigned long)
```
  
Single member *Stack<double>::top()* was instantiated:
```
$ nm a.out | grep top
0000000000001526 W _ZN5StackIdE3topEv
0000000000001320 W _ZN5StackIiE3topEv
```
  
  
```
$ c++filt _ZN5StackIdE3topEv _ZN5StackIiE3topEv
Stack<double>::top()
Stack<int>::top()
```
