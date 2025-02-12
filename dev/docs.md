# 技術文件

## 1. 本專案檔案配置結構

MORTIS/</br>
├── README.md             # Project description and overview</br>
├── .gitignore            # Files and directories to ignore in Git</br>
├── dev/                  # Development documentation</br>
│   ├── dev_log.md        # Log of the development process</br>
│   ├── issue.md          # List of issues and problems to be solved</br>
│   └── docs.md           # Current file structure and technical documentation</br>
├── docs/                 # Usage documentation for each data structure</br>
│   ├── GeneralArray.md</br>
│   ├── Polynomial.md</br>
│   ├── SparseMatrix.md</br>
│   └── String.md</br>
└── src/                  # Source code for the data structures</br>
    ├── array/            # Array-type data structures</br>
    │   ├── GeneralArray/</br>
    │   │   ├── GeneralArray.hpp</br>
    │   │   ├── GeneralArray.cpp</br>
    │   │   └── GeneralArray-test.cpp # test program </br>
    │   ├── Polynomial/</br>
    │   │   ├── Polynomial.hpp</br>
    │   │   ├── Polynomial.cpp</br>
    │   │   └── Polynomial-test.cpp # test program </br>
    │   ├── SparseMatrix/</br>
    │   │   ├── SparseMatrix.hpp</br>
    │   │   ├── SparseMatrix.cpp</br>
    │   │   └── SparseMatrix-test.cpp # test program </br>
    │   └── String/</br>
    │       ├── String.hpp</br>
    │       ├── String.cpp</br>
    │       └── String-test.cpp</br>
    ├── container/        # Container data structures</br>
    │   ├── Bag/</br>
    │   │   ├── Bag.hpp</br>
    │   │   ├── Bag.cpp</br>
    │   │   └── Bag-test.cpp</br>
    │   ├── CirQue/</br>
    │   │   ├── CirQue.hpp</br>
    │   │   ├── CirQue.cpp</br>
    │   │   └── CirQue-test.cpp</br>
    │   ├── DeQue/</br>
    │   │   ├── DeQue.hpp</br>
    │   │   ├── DeQue.cpp</br>
    │   │   └── DeQue-test.cpp</br>
    │   ├── Queue/</br>
    │   │   ├── Queue.hpp</br>
    │   │   ├── Queue.cpp</br>
    │   │   └── Queue-test.cpp</br>
    │   └── Stack/</br>
    │       ├── Stack.hpp</br>
    │       ├── Stack.cpp</br>
    │       └── Stack-test.cpp</br>
    ├── chain/            # Chain structures</br>
    ├── tree/             # Tree-based data structures</br>
    ├── graph/            # Graph data structures</br>
    └── MORTIS.hpp        # Header file</br>