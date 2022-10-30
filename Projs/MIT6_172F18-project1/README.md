## The algorithm

I just followed the instructions provided by the pdf (Page 7). i.e. $$(a^{-1}b^{-1})^{-1}=ba$$

## The result

```sh
./every -s
# Tier 32 (≈1MB) exceeded 0.01s cutoff with time 0.012932s

./every -m
# Tier 37 (≈19MB) exceeded 0.10s cutoff with time 0.144798s

./every -l
# Tier 42 (≈218MB) exceeded 1.00s cutoff with time 1.629777s
```

> Note: I didn't write more tests to make sure it's correct. Also, I knew litter of C language, so I didn't encapsulate the *reverse* operation as a function.

> Note: I chagned the `test.py` file to support python3