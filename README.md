Python and R: Together At Last
==============================
> Writing Cross-Language Tools

This repo contains slides and code examples for a SciPy 2016 talk in which
we implement a function that computes the sum of an array (`tally`).

## The Python Package
### Build
```bash
cd tally_py && python setup.py develop
```
### Run
```Python
import numpy as np
from tally_py import tally

a = np.array([1., 2., 3.])
tally(a)
# 6
```

## The R Package
### Build
Using [devtools](https://github.com/hadley/devtools):
```bash
cd tally_r && Rscript -e "devtools::install()"
```
### Run
```R
library(tallyR)

tally(c(1, 2, 3))
# [1] 6
```
