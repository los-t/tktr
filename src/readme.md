# What is where?

The code is organized in the following manner:


## The src root directory
Contains only this readme, subdirectories and top-level build-script.

## ./lib
- Contains common code that is shared by final binaries (linkage not implied).
- top-level namespace is `tktr::`
- every public api resides in sub-namespace of `tktr::`

## ./client
- code for client applications.
- no top-level namespace: it is not supposed to be used from outside

## ./server
- code for server-side daemons.
- no top-level namespace: it is not supposed to be used from outside
