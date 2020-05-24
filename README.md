# bamboo-c

> bamboo in c

Completely useless at the moment. Proof of concept that this builds bindings to bamboo from c.

## Build

```sh
$ make
```

## Run

```sh
$ ./main
```

Outputs the result status (0 is success), the hex string of the encoded message, some (not all of the available stuff) from decoding and the result of verifying the entry:

```
Publishing entry...
result 0
1020dd997dbd5c3fc0921d9ab2d06c2f3a4a958c738175a6dfa9ab485e20be9a43bd0150406b4c45fb9547e19c90851692764f39fe927a8ce7295dd15c8e15bfd78dd753c4bcc57aa929d4394e6218ae8fd0b1c8bf5f9910b9bdd27c62e06c301321a023402b49a3f84e81efdd24fa6eb452bb239ebd69d27e9861b8981769f2571f73bc37dd596d50ba2a92cbd5353d0c3579b36ca32a5ed6b245bc67a3f67645d218e1

Decoding entry...
entry decoded ok!!
log_id: 0
seq_num: 1
is_end_of_feed: 1
payload_length: 5


Verifying entry...
entry is valid!!
```
