"""
timer(spam, 1, 2, a=3, b=4, _reps=1000) calls and times
spam(1, 2, a=3) _ reps times, and returns total time for
all runs, with final result;

best(spam, 1, 2, a=3, b=4, _reps=1000) runs best-of-N
timer to filter our any system load variation, and
returns best time among _reps tests
"""

import time, sys
if sys.platform[:3] == 'win':
    timefunc = time.clock
else:
    timefunc = time.time

def trace(*args): pass

def timer(func, *pargs, **kargs):
    _reps = kargs.pop('_reps', 1000)
    trace(func, pargs, kargs, _reps)
    repslist = range(_reps)
    start = timefunc()
    for i in repslist:
        ret = func(*pargs, **kargs)
    elapsed = timefunc() - start
    return (elapsed, ret)

def best(func, *pargs, **kargs):
    _reps = kargs.pop('_reps', 50)
    best = 2 ** 32
    for i in range(_reps):
        (time, ret) = timer(func, *pargs, _reps=1, **kargs)
        if time < best: best = time
    return (best, ret)
