#include "server.h"
#include "client.h"

Server::Server() {}

std::shared_ptr<Client> Server::add_client(std::string id) {
    for (auto &user : clients) {
        if (user.first->get_id() == id) {
            id += std::rand() % 9000 + 1000;
        }
    }

    std::shared_ptr<Client> client = std::make_shared<Client>(id, *this);
    clients.insert({client, 5});
    return client;
}

std::shared_ptr<Client> Server::get_client(std::string id) const {
    for (auto &user : clients) {
        if (user.first->get_id() == id) {
            return user.first;
        }
    }
    std::cout << "no the expected id client" << std::endl;
    return std::shared_ptr<Client>(); 
}

double Server::get_wallet(std::string id) const {
    for (auto &client : clients) {
        if (client.first->get_id() == id) {
            return client.second;
        }
    }
    return 0;
    std::cout << "no the expected id client" << std::endl;
}

bool Server::parse_trx(std::string trx, std::string &sender, std::string &receiver, double &value) {
    size_t pos = 0;
    std::string delimiter = "-";

    // find the first - postion
    pos = trx.find(delimiter);
    if (pos != -1) {
        sender = trx.substr(0, pos);
    } else {
        throw std::runtime_error("find the first - failed");
    }

    //find the second - postion
    size_t next_pos = pos + delimiter.length();
    pos = trx.find(delimiter, next_pos);
    if (pos != -1) {
        receiver = trx.substr(next_pos, pos - next_pos);
    } else {
        throw std::runtime_error("find the first - failed");
    }

    next_pos = pos + delimiter.length();
    std::string val = trx.substr(next_pos);
    value = std::stod(val);
    std::cout << sender << " " << receiver << " " << value << std::endl;
    return true;
}

void show_wallets(const  Server& server) {
	std::cout << std::string(20, '*') << std::endl;
	for(const auto& client: server.clients)
		std::cout << client.first->get_id() <<  " : "  << client.second << std::endl;
	std::cout << std::string(20, '*') << std::endl;
}

