#include "client.h"
#include "server.h"


Client::Client(std::string id, const Server& server) : id(id), server(&server){
    crypto::generate_key(public_key, private_key);
}

std::string Client::get_id() {
    return id;
}

double Client::get_wallet() {
    return server->get_wallet(id);
}

std::string Client::get_publickey() const {
    return public_key;
}

std::string Client::sign(std::string txt) const {
    return crypto::signMessage(private_key, txt);
}
// std::string Client::sign(std::string txt) {
//     return crypto::signMessage(private_key, txt);
// }
