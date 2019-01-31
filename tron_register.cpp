#include "tron_register.h"

void tron_register::put(name eos_account, string tron_address) {
    require_auth(eos_account);
    mapping_index table(_code, _code.value);
    auto found_user = table.find(eos_account.value);
    eosio_assert(found_user == table.end(), "eos account is already registered");
    validate_tron_address(tron_address);
    table.emplace(eos_account, [&](auto &row) {
        row.eos_account = eos_account;
        row.tron_address = tron_address;
    });
}

void tron_register::validate_tron_address(string tron_address) {
    eosio_assert(tron_address.length() == 42, "invalid address length");
    if (tron_address[0] != '4' || tron_address[1] != '1') {
        eosio_assert(false, "address should start with 41");
    }
    for (int i = 2; i < 42; i++) {
        eosio_assert(is_hex_char(tron_address[i]), "the passed hex char is not a valid hex string");
    }
}

bool tron_register::is_hex_char(char c) {
    return ((c >= 'A' && c <= 'F') ||
            (c >= 'a' && c <= 'f') ||
            (c >= '0' && c <= '9'));
}

EOSIO_DISPATCH(tron_register, (put))
