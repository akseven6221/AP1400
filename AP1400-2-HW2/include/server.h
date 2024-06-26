#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <map>
#include <memory>
#include "client.h"

// class Client;

class Server
{
public:
	Server();
	std::shared_ptr<Client> add_client(std::string id);
	std::shared_ptr<Client> get_client(std::string id) const;
	double get_wallet(std::string id) const;
	static bool parse_trx(std::string trx, std::string &sender, std::string &receiver, double &value);
	bool add_pending_trx(std::string trx, std::string signature);
	size_t mine();
private:
	std::map<std::shared_ptr<Client>, double> clients;
    // 声明 show_wallets 为友元函数
	friend void show_wallets(const Server& server);
};



#endif //SERVER_H