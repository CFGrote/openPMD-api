.. _install-changelog:

Changelog
=========

0.7.0-alpha
-----------
**Date:** TBA

[Title]

[Summary]

Changes to "0.6.2-alpha"
^^^^^^^^^^^^^^^^^^^^^^^^

Features
""""""""

- C++:

  - ``storeChunk`` argument order changed, defaults added #386
- Python:

  - ``import openPMD`` renamed to ``import openpmd_api`` #380 #392
  - ``store_chunk`` argument order changed, defaults added #386
  - works with Python 3.7 #376
  - setup.py for sdist #240
- Backends: JSON support added #384 #393 #338

Bug Fixes
"""""""""

- support reading series with varying or no iteration padding in filename #388

Other
"""""

- Docs: upgrade guide added #385
- CI: GCC 8.1.0 & Python 3.7.0 #376
- CMake: treat third party libraries properly as ``IMPORTED`` #389


0.6.2-alpha
-----------
**Date:** 2018-09-25

Python Stride: Regression

A regression in the last fix for python strides made the relaxation not efficient for 2-D and higher.

Changes to "0.6.1-alpha"
^^^^^^^^^^^^^^^^^^^^^^^^

Bug Fixes
"""""""""

- Python: relax strides further


0.6.1-alpha
-----------
**Date:** 2018-09-24

Relaxed Python Stride Checks

Python stride checks have been relaxed and one-element n-d arrays are allowed for scalars.

Changes to "0.6.0-alpha"
^^^^^^^^^^^^^^^^^^^^^^^^

Bug Fixes
"""""""""

- Python:

  - stride check too strict #369
  - allow one-element n-d arrays for scalars in ``store``, ``make_constant`` #314

Other
"""""

- dependency change: Catch2 2.3.0+
- Python: add extended write example #314


0.6.0-alpha
-----------
**Date:** 2018-09-20

Particle Patches Improved, Constant Scalars and Python Containers Fixed

Scalar records properly support const-ness.
The Particle Patch load interface was changed, loading now all patches at once, and Python bindings are available.
Numpy ``dtype`` is now a first-class citizen for Python ``Datatype`` control, being accepted and returned instead of enums.
Python lifetime in garbage collection for containers such as ``meshes``, ``particles`` and ``iterations`` is now properly implemented.

Changes to "0.5.0-alpha"
^^^^^^^^^^^^^^^^^^^^^^^^

Features
""""""""

- Python:

  - accept & return ``numpy.dtype`` for ``Datatype`` #351
  - better check for (unsupported) numpy array strides #353
  - implement ``Record_Component.make_constant`` #354
  - implement ``Particle_Patches`` #362
- comply with runtime constraints w.r.t. ``written`` status #352
- load at once ``ParticlePatches.load()`` #364

Bug Fixes
"""""""""

- dataOrder: mesh attribute is a string #355
- constant scalar Mesh Records: reading corrected #358
- particle patches: stricter ``load( idx )`` range check #363, then removed in #364
- Python: lifetime of ``Iteration.meshes/particles`` and ``Series.iterations`` members #354

Other
"""""

- test cases for mixed constant/non-constant Records #358
- examples: close handles explicitly #359 #360

0.5.0-alpha
-----------
**Date:** 2018-09-17

Refactored Type System

The type system for ``Datatype::``s was refactored.
Integer types are now represented by ``SHORT``, ``INT``, ``LONG`` and ``LONGLONG`` as fundamental C/C++ types.
Python support enters "alpha" stage with fixed floating point storage and ``Attribute`` handling.

Changes to "0.4.0-alpha"
^^^^^^^^^^^^^^^^^^^^^^^^

Features
""""""""

- Removed ``Datatype::INT32`` types with ``::SHORT``, ``::INT`` equivalents #337
- ``Attribute::get<...>()`` performs a ``static_cast`` now #345

Bug Fixes
"""""""""

- Refactor type system and ``Attribute`` set/get

  - integers #337
  - support ``long double`` reads on MSVC #184
- ``setAttribute``: explicit C-string handling #341
- ``Dataset``: ``setCompression`` warning and error logic #326
- avoid impact on unrelated classes in invasive tests #324
- Python

  - single precision support: ``numpy.float`` is an alias for ``builtins.float`` #318 #320
  - ``Dataset`` method namings to underscores #319
  - container namespace ambiguity #343
  - ``set_attribute``: broken numpy, list and string support #330

Other
"""""

- CMake: invasive tests not enabled by default #323
- ``store_chunk``: more detailed type mismatch error #322
- ``no_such_file_error`` & ``no_such_attribute_error``: remove c-string constructor #325 #327
- add virtual destructor to ``Attributable`` #332
- Python: Numpy 1.15+ required #330


0.4.0-alpha
-----------
**Date:** 2018-08-27

Improved output handling

Refactored and hardened for ``fileBased`` output.
Records are not flushed before the ambiguity between scalar and vector records are resolved.
Trying to write globally zero-extent records will throw gracefully instead of leading to undefined behavior in backends.

Changes to "0.3.1-alpha"
^^^^^^^^^^^^^^^^^^^^^^^^

Features
""""""""

- do not assume record structure prematurely #297
- throw in (global) zero-extent dataset creation and write #309

Bug Fixes
"""""""""

- ADIOS1 ``fileBased`` IO #297
- ADIOS2 stub header #302
- name sanitization in ADIOS1 and HDF5 backends #310

Other
"""""

- CI updates: #291

  - measure C++ unit test coverage with coveralls
  - clang-format support
  - clang-tidy support
  - include-what-you-use support #291 export headers #300
  - OSX High Sierra support #301
  - individual cache per build # 303
  - readable build names #308
- remove superfluous whitespaces #292
- readme: openPMD is for scientific data #294
- ``override`` implies ``virtual`` #293
- spack load: ``-r`` #298
- default constructors and destructors #304
- string pass-by-value #305
- test cases with 0-sized reads & writes #135


0.3.1-alpha
-----------
**Date:** 2018-07-07

Refined fileBased Series & Python Data Load

A specification for iteration padding in filenames for ``fileBased`` series is introduced.
Padding present in read iterations is detected and conserved in processing.
Python builds have been simplified and python data loads now work for both meshes and particles.

Changes to "0.3.0-alpha"
^^^^^^^^^^^^^^^^^^^^^^^^

Features
""""""""

- CMake:

  - add ``openPMD::openPMD`` alias for full-source inclusion #277
  - include internally shipped pybind11 v2.2.3 #281
  - ADIOS1: enable serial API usage even if MPI is present #252 #254
- introduce detection and specification ``%0\d+T`` of iteration padding #270
- Python:

  - add unit tests #249
  - expose record components for particles #284

Bug Fixes
"""""""""

- improved handling of ``fileBased`` Series and ``READ_WRITE`` access
- expose ``Container`` constructor as ``protected`` rather than ``public`` #282
- Python:

  - return actual data in ``load_chunk`` #286

Other
"""""

- docs:

  - improve "Install from source" section #274 #285
  - Spack python 3 install command #278


0.3.0-alpha
-----------
**Date:** 2018-06-18

Python Attributes, Better FS Handling and Runtime Checks

This release exposes openPMD attributes to Python.
A new independent mechanism for verifying internal conditions is now in place.
Filesystem support is now more robust on varying directory separators.

Changes to "0.2.0-alpha"
^^^^^^^^^^^^^^^^^^^^^^^^

Features
""""""""

- CMake: add new ``openPMD_USE_VERIFY`` option #229
- introduce ``VERIFY`` macro for pre-/post-conditions that replaces ``ASSERT`` #229 #260
- serial Singularity container #236
- Python:

  - expose attributes #256 #266
  - use lists for offsets & extents #266
- C++:

  - ``setAttribute`` signature changed to const ref #268

Bug Fixes
"""""""""

- handle directory separators platform-dependent #229
- recursive directory creation with existing base #261
- ``FindADIOS.cmake``: reset on multiple calls #263
- ``SerialIOTest``: remove variable shadowing #262
- ADIOS1: memory violation in string attribute writes #269

Other
"""""

- enforce platform-specific directory separators on user input #229
- docs:

  - link updates to https #259
  - minimum MPI version #251
  - title updated #235
- remove MPI from serial ADIOS interface #258
- better name for scalar record in examples #257
- check validity of internally used pointers #247
- various CI updates #246 #250 #261


0.2.0-alpha
-----------
**Date:** 2018-06-11

Initial Numpy Bindings

Adds first bindings for record component reading and writing.
Fixes some minor CMake issues.

Changes to "0.1.1-alpha"
^^^^^^^^^^^^^^^^^^^^^^^^

Features
""""""""

- Python: first NumPy bindings for record component chunk store/load #219
- CMake: add new ``BUILD_EXAMPLES`` option #238
- CMake: build directories controllable #241

Bug Fixes
"""""""""

- forgot to bump ``version.hpp``/``__version__`` in last release
- CMake: Overwritable Install Paths #237


0.1.1-alpha
-----------
**Date:** 2018-06-07

ADIOS1 Build Fixes & Less Flushes

We fixed build issues with the ADIOS1 backend.
The number of performed flushes in backends was generally minimized.

Changes to "0.1.0-alpha"
^^^^^^^^^^^^^^^^^^^^^^^^

Bug Fixes
"""""""""

- SerialIOTest: ``loadChunk`` template missing for ADIOS1 #227
- prepare running serial applications linked against parallel ADIOS1 library #228

Other
"""""

- minimize number of flushes in backend #212


0.1.0-alpha
-----------
**Date:** 2018-06-06

This is the first developer release of openPMD-api.

Both HDF5 and ADIOS1 are implemented as backends with serial and parallel I/O support.
The C++11 API is considered alpha state with few changes expected to come.
We also ship an unstable preview of the Python3 API.
