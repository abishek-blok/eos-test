#include "../include/hello.hpp"

ACTION hello::sayhello(name user, name user1)
{
    print("you cannot say hello ", user, "say hello in person ", user1);
}

ACTION hello::addgame(uint64_t gameid, name user, bool isenable, std::string gamename)
{
    auto getgame = _games.find(user.value);
    if (getgame == _games.end())
    {
        getgame = _games.emplace(user, [&](auto &new_game)
                                 {
                                     new_game.gameid = gameid;
                                     new_game.username = user;
                                     new_game.isenabled = isenable;
                                     new_game.gamename = gamename;
                                 });
    }
    else
    {
        print("update code");
    }
}