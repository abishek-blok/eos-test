#include <eosio/eosio.hpp>
using namespace eosio;
CONTRACT hello : public contract
{
    using contract::contract;

public:
    hello(name receiver, name code, datastream<const char *> ds) : contract(receiver, code, ds), _games(receiver, receiver.value) {}

public:
    ACTION sayhello(name user, name user1);

public:
    ACTION addgame(uint64_t gameid, name user, bool isenable, std::string gamename);

private:
    TABLE games_struct
    {
        uint64_t gameid;
        name username;
        bool isenabled;
        std::string gamename;

        auto primary_key() const { return username.value; }
    };

    typedef multi_index<name("games"), games_struct> game_table;

    game_table _games;
};