# GridSearch

Grid search implementation in C++ for hyperparameter optimization. Brings all combination of given parameters one by one with every next call.

## Installation   

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

There is an example in test/gridsearch which is app.cpp. 
```bash
cd build/bin
./gridsearch.app ../../test/gridsearch/config/gridSearchConfig.json
```

## License

[MIT](https://choosealicense.com/licenses/mit/)