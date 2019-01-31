#ifndef TRON_REGISTER_H
#define TRON_REGISTER_H

#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <string>

using namespace std;
using namespace eosio;

class [[eosio::contract]] tron_register : public contract {
public:
    using contract::contract;

//    tron_register(name receiver, name code,  datastream<const char*> ds): contract(receiver, code, ds) {}

    [[eosio::action]]
    void put(name eos_account, string tron_address);

private:
    struct [[eosio::table]] mapping {
        name eos_account;
        string tron_address;

        uint64_t primary_key() const { return eos_account.value; }
    };

    void validate_tron_address(string tron_address);

    char hex_char_to_byte(char c);

    bool is_hex_char(char c);

    typedef multi_index<"mappings"_n, mapping> mapping_index;
};

#endif //TRON_REGISTER_H
