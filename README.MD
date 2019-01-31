# Contract for binding EOS account with TRON address

compile: ` eosio-cpp -o tron_register.wasm tron_register.cpp`

compile & generate abi: ` eosio-cpp -o tron_register.wasm tron_register.cpp --genabi`
